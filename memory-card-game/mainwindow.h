#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QTimer>
#include <QList>
#include "etiket.h"
#include <QLabel>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void kartTiklandi();
    void kartlariKapat();

private:

    void oyunuKur();
    void kontrolEt();

    QWidget *merkeziWidget;
    QGridLayout *oyunAlaniLayout;
    QVBoxLayout *anaLayout;
    QLabel *hataSayaciLabel;

    QList<Etiket*> kartlar;
    QList<int> kartIDleri;
    QList<QPixmap> resimler;
    QPixmap arkaYuz;

    int hataliDenemeSayisi;

    Etiket *ilkAcilanKart;
    Etiket *ikinciAcilanKart;

    QTimer *zamanlayici;
    int eslesenCiftSayisi;
};
#endif
