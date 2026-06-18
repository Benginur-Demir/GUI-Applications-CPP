#include "etiket.h"
#include <QIcon>

Etiket::Etiket(QWidget *parent)
    : QPushButton(parent), kartID(0), acikMi(false), eslesti(false)
{
    setFixedSize(100, 100);
    setIconSize(QSize(90, 90));
}

void Etiket::setKartID(int id) {
    kartID = id;
}

int Etiket::getKartID() const {
    return kartID;
}

void Etiket::setOnYuz(const QPixmap &resim) {
    onYuzResmi = resim;
}

void Etiket::setArkaYuz(const QPixmap &resim) {
    arkaYuzResmi = resim;
    kapat();
}

void Etiket::ac() {
    if (eslesti) return;
    setIcon(onYuzResmi);
    acikMi = true;
}

void Etiket::kapat() {
    if (eslesti) return;
    setIcon(arkaYuzResmi);
    acikMi = false;
}

void Etiket::setEslesti() {
    eslesti = true;
}

bool Etiket::eslestiMi() const {
    return eslesti;
}
