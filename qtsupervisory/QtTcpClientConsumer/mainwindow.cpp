#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  connect(ui->pushButtonConnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(connectIp()));
  connect(ui->pushButtonDisconnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(disconnect()));
  connect(ui->pushButtonUpdate,
          SIGNAL(clicked(bool)),
          this,
          SLOT(updateList()));
  connect(ui->pushButtonStart,
          SIGNAL(clicked(bool)),
          this,
          SLOT(StartTimer()));
  connect(ui->pushButtonStop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(StopTimer()));
  connect(ui->horizontalSliderTime,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(mudaTime(int)));
  connect(ui->listWidgetIps,
          SIGNAL(currentTextChanged(QString)),
          this,
          SLOT(mudaIp(QString)));
  connect(this,
          SIGNAL(dado(QString)),
          ui->widgetPlotter,
          SLOT(mudaDado(QString)));
}

void MainWindow::tcpConnect(QString ip){
    if(!connected){
        socket->connectToHost(ip,1234);
        if(socket->waitForConnected(3000)){
            qDebug() << "Connected";
            connected=true;
        }
    }

}

void MainWindow::getData(){
  QString str,str_get;
  QStringList list;
  qint64 thetime;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      str_get="get "+ currentIp + " 2\r\n";
      qDebug() << socket->write(str_get.toStdString().c_str());
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          str = list.at(1);
          emit dado(str);
          qDebug() << thetime << ": " << str;
        }
      }
    }
  }
}


MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}


void MainWindow::connectIp(){
    tcpConnect(ui->lineEditIp->displayText());
}

void MainWindow::disconnect(){
    if(connected){
        socket->disconnectFromHost();
        if(!socket->waitForConnected(3000)){
            qDebug() << "Disconnected";
            connected=false;
            StopTimer();
        }
    }
}

void MainWindow::updateList(){
    QString str;
    QStringList list;
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            socket->write("list\r\n");
            ui->listWidgetIps->clear();
            socket->waitForBytesWritten(500);
            socket->waitForReadyRead(500);
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                qDebug()<<str;

                ui->listWidgetIps->addItems(list);
            }
        }
    }
}


void MainWindow::timerEvent(QTimerEvent *e){
    getData();
}
void MainWindow::StartTimer(){
    if(ipSelected && connected && !timerOn){
        timerId = startTimer(time*1000);
        timerOn=true;
    }

}

void MainWindow::StopTimer(){
        if(timerOn){
        killTimer(timerId);
        timerOn=false;
    }

}
void MainWindow::mudaTime(int val){
    time=val;
    if(timerOn){
        killTimer(timerId);
        timerId = startTimer(time*1000);
    }

}

void MainWindow::mudaIp(QString ip){
    currentIp=ip;
    ipSelected=true;
    qDebug()<<currentIp;
}
