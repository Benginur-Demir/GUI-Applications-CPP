/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLineEdit *leKelime;
    QPushButton *btnEkle;
    QPushButton *btnSil;
    QPushButton *btnBasla;
    QLabel *lblKelime;
    QLineEdit *leTahmin;
    QPushButton *btnTahmin;
    QListWidget *listTahminler;
    QLabel *lblTaban;
    QLabel *lblDirek;
    QLabel *lblUstKol;
    QLabel *lblIp;
    QLabel *lblKafa;
    QLabel *lblGovde;
    QLabel *lblSolKol;
    QLabel *lblSagKol;
    QLabel *lblSolBacak;
    QLabel *lblSagBacak;
    QPushButton *btnGuncelle;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QFont font;
        font.setPointSize(11);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 60, 256, 481));
        leKelime = new QLineEdit(centralwidget);
        leKelime->setObjectName("leKelime");
        leKelime->setGeometry(QRect(30, 10, 251, 31));
        btnEkle = new QPushButton(centralwidget);
        btnEkle->setObjectName("btnEkle");
        btnEkle->setGeometry(QRect(310, 70, 91, 31));
        btnSil = new QPushButton(centralwidget);
        btnSil->setObjectName("btnSil");
        btnSil->setGeometry(QRect(310, 110, 91, 31));
        btnBasla = new QPushButton(centralwidget);
        btnBasla->setObjectName("btnBasla");
        btnBasla->setGeometry(QRect(310, 310, 91, 31));
        lblKelime = new QLabel(centralwidget);
        lblKelime->setObjectName("lblKelime");
        lblKelime->setGeometry(QRect(310, 500, 271, 31));
        leTahmin = new QLineEdit(centralwidget);
        leTahmin->setObjectName("leTahmin");
        leTahmin->setGeometry(QRect(300, 440, 113, 28));
        btnTahmin = new QPushButton(centralwidget);
        btnTahmin->setObjectName("btnTahmin");
        btnTahmin->setGeometry(QRect(310, 360, 90, 29));
        listTahminler = new QListWidget(centralwidget);
        listTahminler->setObjectName("listTahminler");
        listTahminler->setGeometry(QRect(725, 30, 41, 511));
        lblTaban = new QLabel(centralwidget);
        lblTaban->setObjectName("lblTaban");
        lblTaban->setGeometry(QRect(440, 440, 241, 31));
        lblTaban->setPixmap(QPixmap(QString::fromUtf8(":/images/yatayCizgi.png")));
        lblDirek = new QLabel(centralwidget);
        lblDirek->setObjectName("lblDirek");
        lblDirek->setGeometry(QRect(470, 60, 20, 401));
        lblDirek->setPixmap(QPixmap(QString::fromUtf8(":/images/dikCizgi.png")));
        lblUstKol = new QLabel(centralwidget);
        lblUstKol->setObjectName("lblUstKol");
        lblUstKol->setGeometry(QRect(470, 60, 121, 21));
        lblUstKol->setPixmap(QPixmap(QString::fromUtf8(":/images/yatayCizgi.png")));
        lblIp = new QLabel(centralwidget);
        lblIp->setObjectName("lblIp");
        lblIp->setGeometry(QRect(590, 70, 16, 41));
        lblIp->setPixmap(QPixmap(QString::fromUtf8(":/images/dikCizgi.png")));
        lblKafa = new QLabel(centralwidget);
        lblKafa->setObjectName("lblKafa");
        lblKafa->setGeometry(QRect(560, 110, 81, 71));
        lblKafa->setPixmap(QPixmap(QString::fromUtf8(":/images/cember.png")));
        lblKafa->setScaledContents(true);
        lblGovde = new QLabel(centralwidget);
        lblGovde->setObjectName("lblGovde");
        lblGovde->setGeometry(QRect(600, 180, 16, 151));
        lblGovde->setPixmap(QPixmap(QString::fromUtf8(":/images/dikCizgi.png")));
        lblSolKol = new QLabel(centralwidget);
        lblSolKol->setObjectName("lblSolKol");
        lblSolKol->setGeometry(QRect(562, 190, 41, 41));
        lblSolKol->setPixmap(QPixmap(QString::fromUtf8(":/images/sol.png")));
        lblSolKol->setScaledContents(true);
        lblSagKol = new QLabel(centralwidget);
        lblSagKol->setObjectName("lblSagKol");
        lblSagKol->setGeometry(QRect(600, 190, 51, 41));
        lblSagKol->setPixmap(QPixmap(QString::fromUtf8(":/images/sag.png")));
        lblSagKol->setScaledContents(true);
        lblSolBacak = new QLabel(centralwidget);
        lblSolBacak->setObjectName("lblSolBacak");
        lblSolBacak->setGeometry(QRect(560, 310, 41, 41));
        lblSolBacak->setPixmap(QPixmap(QString::fromUtf8(":/images/sol.png")));
        lblSolBacak->setScaledContents(true);
        lblSagBacak = new QLabel(centralwidget);
        lblSagBacak->setObjectName("lblSagBacak");
        lblSagBacak->setGeometry(QRect(610, 310, 51, 41));
        lblSagBacak->setPixmap(QPixmap(QString::fromUtf8(":/images/sag.png")));
        lblSagBacak->setScaledContents(true);
        btnGuncelle = new QPushButton(centralwidget);
        btnGuncelle->setObjectName("btnGuncelle");
        btnGuncelle->setGeometry(QRect(310, 150, 91, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(700, 0, 81, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnEkle->setText(QCoreApplication::translate("MainWindow", "EKLE", nullptr));
        btnSil->setText(QCoreApplication::translate("MainWindow", "S\304\260L", nullptr));
        btnBasla->setText(QCoreApplication::translate("MainWindow", "BASLA", nullptr));
        lblKelime->setText(QString());
        btnTahmin->setText(QCoreApplication::translate("MainWindow", "TAHM\304\260N", nullptr));
        lblTaban->setText(QString());
        lblDirek->setText(QString());
        lblUstKol->setText(QString());
        lblIp->setText(QString());
        lblKafa->setText(QString());
        lblGovde->setText(QString());
        lblSolKol->setText(QString());
        lblSagKol->setText(QString());
        lblSolBacak->setText(QString());
        lblSagBacak->setText(QString());
        btnGuncelle->setText(QCoreApplication::translate("MainWindow", "G\303\234NCELLE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", " HARFLER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
