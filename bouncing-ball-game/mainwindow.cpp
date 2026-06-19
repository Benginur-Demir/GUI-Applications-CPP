#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etiket.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->buton->setGeometry(
        (this->width() / 2) - (ui->buton->width() / 2),
        this->height() - ui->buton->height() - 25,
        ui->buton->width(),
        ui->buton->height()
        );

    int rastgeleX = QRandomGenerator::global()->bounded(this->width() - ui->sekenTop->width());
    int rastgeleY = QRandomGenerator::global()->bounded(this->height() / 2);

    ui->sekenTop->setGeometry(
        rastgeleX,
        rastgeleY,
        ui->sekenTop->width(),
        ui->sekenTop->height()
        );


    ui->sekenTop->butonTanimla(ui->buton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    int yeniY = this->height() - ui->buton->height() - 20;
    int yeniX = ui->buton->x();
    if (yeniX + ui->buton->width() > this->width()) {
        yeniX = this->width() - ui->buton->width();
    }
    ui->buton->setGeometry(yeniX, yeniY, ui->buton->width(), ui->buton->height());

    int topX = ui->sekenTop->x();
    int topY = ui->sekenTop->y();
    bool duzeltme = false;

    if (topX + ui->sekenTop->width() > this->width()) {
        topX = this->width() - ui->sekenTop->width();
        duzeltme = true;
    }
    if (topY + ui->sekenTop->height() > this->height()) {
        topY = this->height() - ui->sekenTop->height();
        duzeltme = true;
    }
    if (duzeltme) {
        ui->sekenTop->setGeometry(topX, topY, ui->sekenTop->width(), ui->sekenTop->height());
    }

    QMainWindow::resizeEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *fareOlayi)
{
    ui->buton->setGeometry(
        fareOlayi->x() - (ui->buton->width() / 2),
        this->height() - ui->buton->height() - 20,
        ui->buton->width(),
        ui->buton->height()
        );
}
