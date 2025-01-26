#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect(QString ip);
public slots:
  void timerEvent(QTimerEvent *e);
  void getData();
  void connectIp();
  void disconnect();
  void updateList();
  void StartTimer();
  void StopTimer();
  void mudaTime(int val);
  void mudaIp(QString);
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int timerId;
  bool timerOn=false,connected=false,ipSelected=false;
  int time=1;
  QString currentIp;
signals:
  void dado(QString);
};

#endif // MAINWINDOW_H
