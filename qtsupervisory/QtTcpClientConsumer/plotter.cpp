#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QDebug>
Plotter::Plotter(QWidget *parent): QWidget{parent}{
    background = QColor(255,255,200);
    for(int i=0;i<=29;i++){
        lista.append("");
    }
}

void Plotter::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPen pen;
    QBrush brush;

    painter.setRenderHint(QPainter::Antialiasing);

    pen.setColor(QColor(0,0,255));
    pen.setWidth(2);
    painter.setPen(pen);

    brush.setColor(background);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    painter.drawRect(0,0,width(), height());


    pen.setWidth(1);
    pen.setColor(QColor(255,0,0));
    painter.setPen(pen);

    float x0, y0, x1, y1;
    x0 = 0;
    h=(float) width()/29.0;
    qDebug()<<h;
    bool ok;
    y0 = height()-(height()*lista[0].toFloat(&ok)/100);


    for(int i=1; i<lista.length();i++){
        x1=x0+h;
        y1=height()-(height()*lista[i].toFloat(&ok)/100);
        painter.drawLine(x0,y0,x1,y1);
        x0 = x1;
        y0 = y1;
    }
}

void Plotter::mudaDado(QString str){
    dado=str;
    lista.replace(n,str);
    n=n+1;
    if(n>=30){
        n=0;
    }
    qDebug()<<n;
    repaint();
}
