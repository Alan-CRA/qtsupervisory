#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

#include <QString>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
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
  connect(ui->horizontalSliderMax,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(mudaMax(int)));
  connect(ui->horizontalSliderMin,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(mudaMin(int)));
  connect(ui->horizontalSliderTime,
          SIGNAL(valueChanged(int)),
          this,
          SLOT(mudaTime(int)));
  connect(ui->pushButtonStart,
          SIGNAL(clicked(bool)),
          this,
          SLOT(StartTimer()));
  connect(ui->pushButtonStop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(StopTimer()));
  connect(this,
          SIGNAL(dado(QString)),
          ui->plainTextEditDado,
          SLOT(appendPlainText(QString)));

}

void MainWindow::tcpConnect(QString ip){
    QDateTime datetime;
    QString str;
    qint64 msecdate;
    if(!connected){
        socket->connectToHost(ip,1234);
        if(socket->waitForConnected(3000)){
            qDebug() << "Connected";
            connected=true;
        }
        if(socket->state()== QAbstractSocket::ConnectedState){
            msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
            str = "set "+QString::number(msecdate)+" 0";
            emit dado(str);
            qDebug() << str;
            qDebug() << socket->write(str.toStdString().c_str())<< " bytes written";
            if(socket->waitForBytesWritten(3000)){
                qDebug() << "wrote";
            }
        }
    }


}

void MainWindow::timerEvent(QTimerEvent *e){
    putData();
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

void MainWindow::mudaMax(int val){
    if(val>min){
        max=val;
    }

}

void MainWindow::mudaMin(int val){
    if(val<max){
        min=val;
    }

}

void MainWindow::mudaTime(int val){
    time=val;
    if(timerOn){
        killTimer(timerId);
        timerId = startTimer(time*1000);
    }

}

void MainWindow::StartTimer(){
    if(connected && !timerOn){
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

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  if(socket->state()== QAbstractSocket::ConnectedState){
    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+QString::number(msecdate)+" "+QString::number(min+rand()%(max-min+1));
    emit dado(str);
    qDebug() << str;
    qDebug() << socket->write(str.toStdString().c_str())<< " bytes written";
    if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
    }
    str = "set "+QString::number(msecdate)+" "+QString::number(min+rand()%(max-min+1));
    emit dado(str);
    qDebug() << str;
    qDebug() << socket->write(str.toStdString().c_str())<< " bytes written";
    if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
    }
  }
}

MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
