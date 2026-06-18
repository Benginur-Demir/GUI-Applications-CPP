#include "mainwindow.h"
#include <QRandomGenerator>
#include <algorithm>
#include <QDebug>
#include <QMessageBox>
#include <QFont>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ilkAcilanKart(nullptr)
    , ikinciAcilanKart(nullptr)
    , eslesenCiftSayisi(0)
    , hataliDenemeSayisi(0)
{
    setWindowTitle("Hafıza Oyunu");

    merkeziWidget = new QWidget(this);
    anaLayout = new QVBoxLayout(merkeziWidget);

    hataSayaciLabel = new QLabel(this);
    hataSayaciLabel->setText("Hatalı Deneme: 0");
    hataSayaciLabel->setAlignment(Qt::AlignCenter);

    QFont font = hataSayaciLabel->font();
    font.setPointSize(14);
    hataSayaciLabel->setFont(font);

    oyunAlaniLayout = new QGridLayout();

    merkeziWidget->setStyleSheet(
        "QWidget {"
        "    background-color: #BDE0FE;"
        "}"
        "QLabel {"
        "    color: #22333B;"
        "    background-color: transparent;"

        "    font-family: 'Segoe Print';"
        "    font-size: 25px;"
        "    font-weight: bold;"
        "     font-style: italic; "
        "}"
        "QPushButton {"
        "    background-color:white;"
        "    border: 2px solid #000080;"
        "    border-radius: 10px;"
        "}"
        );

    anaLayout->addWidget(hataSayaciLabel);
    anaLayout->addLayout(oyunAlaniLayout);

    setCentralWidget(merkeziWidget);

    resize(550, 300);


    zamanlayici = new QTimer(this);
    zamanlayici->setSingleShot(true);
    connect(zamanlayici, &QTimer::timeout, this, &MainWindow::kartlariKapat);

    oyunuKur();
}

MainWindow::~MainWindow()
{
}

void MainWindow::oyunuKur()
{
    arkaYuz = QPixmap(":/resimler/arka.png");
    for(int i = 1; i <= 5; ++i) {
        resimler.append(QPixmap(QString(":/resimler/resim%1.png").arg(i)));
    }

    kartIDleri.clear();
    for(int i = 0; i < 5; ++i) {
        kartIDleri.append(i);
        kartIDleri.append(i);
    }

    std::shuffle(kartIDleri.begin(), kartIDleri.end(), *QRandomGenerator::global());

    int Index = 0;
    for (int satir = 0; satir < 2; ++satir) {
        for (int sutun = 0; sutun < 5; ++sutun) {

            if(Index >= kartIDleri.size()) break;

            int id = kartIDleri[Index];

            Etiket *kart = new Etiket(this);
            kart->setKartID(id);
            kart->setArkaYuz(arkaYuz);
            kart->setOnYuz(resimler[id]);

            connect(kart, &Etiket::clicked, this, &MainWindow::kartTiklandi);

            oyunAlaniLayout->addWidget(kart, satir, sutun);
            kartlar.append(kart);

            Index++;
        }
    }
}

void MainWindow::kartTiklandi()
{
    if (zamanlayici->isActive()) {
        return;
    }

    Etiket *secilen_kartım = qobject_cast<Etiket*>(sender());

    if (!secilen_kartım || secilen_kartım->eslestiMi() || secilen_kartım == ilkAcilanKart) {
        return;
    }

    secilen_kartım->ac();

    if (ilkAcilanKart == nullptr) {
        ilkAcilanKart = secilen_kartım;
    } else {
        ikinciAcilanKart = secilen_kartım;
        kontrolEt();
    }
}

void MainWindow::kontrolEt()
{
    if (!ilkAcilanKart || !ikinciAcilanKart) return;

    if (ilkAcilanKart->getKartID() == ikinciAcilanKart->getKartID()) {
        ilkAcilanKart->setEslesti();
        ikinciAcilanKart->setEslesti();

        ilkAcilanKart = nullptr;
        ikinciAcilanKart = nullptr;

        eslesenCiftSayisi++;
    } else {
        hataliDenemeSayisi++;
        hataSayaciLabel->setText(QString("Hatalı Deneme: %1").arg(hataliDenemeSayisi));
        zamanlayici->start(500);
    }
}

void MainWindow::kartlariKapat()
{
    if (ilkAcilanKart) {
        ilkAcilanKart->kapat();
    }
    if (ikinciAcilanKart) {
        ikinciAcilanKart->kapat();
    }

    ilkAcilanKart = nullptr;
    ikinciAcilanKart = nullptr;
}
