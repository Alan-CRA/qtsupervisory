/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEditIp;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QHBoxLayout *horizontalLayout;
    QSlider *horizontalSliderMin;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSliderMax;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *horizontalSliderTime;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonStop;
    QPlainTextEdit *plainTextEditDado;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(560, 378);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 531, 301));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName("verticalLayout_3");
        lineEditIp = new QLineEdit(groupBox);
        lineEditIp->setObjectName("lineEditIp");

        verticalLayout_3->addWidget(lineEditIp);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButtonConnect = new QPushButton(groupBox);
        pushButtonConnect->setObjectName("pushButtonConnect");

        horizontalLayout_3->addWidget(pushButtonConnect);

        pushButtonDisconnect = new QPushButton(groupBox);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");

        horizontalLayout_3->addWidget(pushButtonDisconnect);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSliderMin = new QSlider(groupBox);
        horizontalSliderMin->setObjectName("horizontalSliderMin");
        horizontalSliderMin->setMaximum(100);
        horizontalSliderMin->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout->addWidget(horizontalSliderMin);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName("lcdNumber");

        verticalLayout->addWidget(lcdNumber);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSliderMax = new QSlider(groupBox);
        horizontalSliderMax->setObjectName("horizontalSliderMax");
        horizontalSliderMax->setMinimum(0);
        horizontalSliderMax->setMaximum(100);
        horizontalSliderMax->setValue(0);
        horizontalSliderMax->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderMax);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        lcdNumber_2 = new QLCDNumber(groupBox);
        lcdNumber_2->setObjectName("lcdNumber_2");

        verticalLayout_2->addWidget(lcdNumber_2);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        horizontalSliderTime = new QSlider(groupBox);
        horizontalSliderTime->setObjectName("horizontalSliderTime");
        horizontalSliderTime->setMinimum(1);
        horizontalSliderTime->setMaximum(60);
        horizontalSliderTime->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(horizontalSliderTime);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButtonStart = new QPushButton(groupBox);
        pushButtonStart->setObjectName("pushButtonStart");

        horizontalLayout_5->addWidget(pushButtonStart);

        pushButtonStop = new QPushButton(groupBox);
        pushButtonStop->setObjectName("pushButtonStop");

        horizontalLayout_5->addWidget(pushButtonStop);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout_3);

        plainTextEditDado = new QPlainTextEdit(groupBox);
        plainTextEditDado->setObjectName("plainTextEditDado");

        horizontalLayout_6->addWidget(plainTextEditDado);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 560, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSliderMin, &QSlider::valueChanged, lcdNumber, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSliderMax, &QSlider::valueChanged, lcdNumber_2, qOverload<int>(&QLCDNumber::display));
        QObject::connect(horizontalSliderTime, &QSlider::valueChanged, label_4, qOverload<int>(&QLabel::setNum));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Timing(s)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
