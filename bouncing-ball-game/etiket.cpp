#include "etiket.h"

etiket::etiket(QWidget *parent)
    : QLabel(parent)
{
    xEkseniHizi = 5;
    yEkseniHizi = 5;
    puan = 0;

    buton = nullptr;

    zamanlayici = new QTimer(this);
    connect(zamanlayici, SIGNAL(timeout()), this, SLOT(hareketlendir()));
    zamanlayici->start(20);
}


void etiket::butonTanimla(QPushButton *ptrButon)
{
    buton = ptrButon;
}

void etiket::sinirlariKontrolEt()
{
    if (!parentWidget()) return;
    if (this->x() > parentWidget()->width() - this->width()) {
        this->move(parentWidget()->width() - this->width(), this->y());
    }
    if (this->y() > parentWidget()->height() - this->height()) {
        this->move(this->x(), parentWidget()->height() - this->height());
    }
}

void etiket::hareketlendir()
{

    this->setGeometry(this->x() + xEkseniHizi, this->y() + yEkseniHizi, this->width(), this->height());

    if (this->x() < 0 || this->x() > (parentWidget()->width() - this->width())) {
        xEkseniHizi = -1 * xEkseniHizi;
    }
    if (this->y() < 0) {
        yEkseniHizi = -1 * yEkseniHizi;
    }

    if (buton != nullptr && this->y() > (buton->y() - this->height())) {

        int topSag = this->x() + this->width();
        int topSol = this->x();


        int butonSol = buton->x();
        int butonSag = buton->x() + buton->width();


        if (topSag > butonSol && topSol < butonSag) {


            this->setGeometry(this->x(), buton->y() - this->height(), this->width(), this->height());

            yEkseniHizi = -1 * yEkseniHizi;
            puan++;




            buton->setText(QString::number(puan));
        }
        else if (this->y() + this->height() >= parentWidget()->height()) {
            zamanlayici->stop();
            zamanlayici->disconnect();
            xEkseniHizi = 0;
            yEkseniHizi = 0;

            this->setGeometry(this->x(), parentWidget()->height() - this->height(), this->width(), this->height());
            this->setPixmap(QPixmap(":/new/prefix1/patlama.png"));
            this->setScaledContents(true);


            buton->setText("OYUN BITTI!");
        }
    }
}
