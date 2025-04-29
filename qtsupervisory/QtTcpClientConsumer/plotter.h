#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <QPaintEvent>


class Plotter : public QWidget
{
    Q_OBJECT

private:
    QColor background;
    QString dado="0";
    QStringList lista;
    float h;
    int n=0;
public:
    explicit Plotter(QWidget *parent = nullptr);

public slots:
    void paintEvent(QPaintEvent *e);
    void mudaDado(QString str);
signals:
};

#endif // PLOTTER_H
