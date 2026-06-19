#ifndef ETIKET_H
#define ETIKET_H

#include <QLabel>
#include <QTimer>
#include <QPushButton>

class etiket : public QLabel
{
    Q_OBJECT
public:
    explicit etiket(QWidget *parent = nullptr);

    void butonTanimla(QPushButton *ptrButon);

    void sinirlariKontrolEt();

private:
    QTimer *zamanlayici;

    QPushButton *buton;

    int xEkseniHizi;
    int yEkseniHizi;
    int puan;

private slots:
    void hareketlendir();
};

#endif // ETIKET_H
