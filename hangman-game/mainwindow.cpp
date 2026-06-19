#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/EXCALIBUR/OneDrive/Masaüstü/Yazılım Ders 3/Görsel Prog.-QT/231229061_BenginurDemir_ödev3/kelimeler.db");
    if (!db.open()) {
        QMessageBox::critical(this, "Hata", "Veritabanı açma hatası: " + db.lastError().text());
    }

    sorgu = new QSqlQuery(db);
    model = new QSqlQueryModel();
    listele();



    uzuvlar[0] = ui->lblTaban;   uzuvlar[1] = ui->lblDirek;
    uzuvlar[2] = ui->lblUstKol;  uzuvlar[3] = ui->lblIp;
    uzuvlar[4] = ui->lblKafa;    uzuvlar[5] = ui->lblGovde;
    uzuvlar[6] = ui->lblSolKol;  uzuvlar[7] = ui->lblSagKol;
    uzuvlar[8] = ui->lblSolBacak;uzuvlar[9] = ui->lblSagBacak;

    for(int i = 0; i < 10; i++) {
        if(uzuvlar[i]) uzuvlar[i]->hide();
    }
}

MainWindow::~MainWindow() { delete ui; }


void MainWindow::listele() {
    sorgu->exec("SELECT * FROM kelime");
    model->setQuery(*sorgu);
    ui->tableView->setModel(model);
}


void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    seciliID = model->index(index.row(), 0).data().toString(); // kelimeNo
    ui->leKelime->setText(model->index(index.row(), 1).data().toString()); // isim
}


void MainWindow::on_btnEkle_clicked() {
    sorgu->prepare("INSERT INTO kelime (isim) VALUES (?)");
    sorgu->addBindValue(ui->leKelime->text());
    if(!sorgu->exec()) QMessageBox::warning(this, "Hata", sorgu->lastError().text());
    listele();
}

void MainWindow::on_btnSil_clicked() {
    sorgu->prepare("DELETE FROM kelime WHERE kelimeNo = ?");
    sorgu->addBindValue(seciliID);
    sorgu->exec();
    listele();
}

void MainWindow::on_btnGuncelle_clicked() {
    sorgu->prepare("UPDATE kelime SET isim = ? WHERE kelimeNo = ?");
    sorgu->addBindValue(ui->leKelime->text());
    sorgu->addBindValue(seciliID);
    sorgu->exec();
    listele();
}


void MainWindow::on_btnBasla_clicked() {
    hataSayisi = 0;
    ui->listTahminler->clear();
    for(int i = 0; i < 10; i++) if(uzuvlar[i]) uzuvlar[i]->hide();

    sorgu->exec("SELECT isim FROM kelime ORDER BY RANDOM() LIMIT 1");
    if(sorgu->next()) {
        secilenKelime = sorgu->value(0).toString().toUpper();
        gorunenKelime = "";
        for(int i = 0; i < secilenKelime.length(); i++) gorunenKelime += "_ ";
        ui->lblKelime->setText(gorunenKelime);
    }
}


void MainWindow::on_btnTahmin_clicked() {
    QString harf = ui->leTahmin->text();
    if(harf.isEmpty() || secilenKelime.isEmpty()) return;

    if(secilenKelime.contains(harf)) {
        for(int i = 0; i < secilenKelime.length(); i++) {
            if(secilenKelime[i] == harf[0]) {
                gorunenKelime[i*2] = harf[0];
            }
        }
        ui->lblKelime->setText(gorunenKelime);
        if(!gorunenKelime.contains("_")) QMessageBox::information(this, "Sonuç", "Tebrikler!");
    } else {
        if(hataSayisi < 10) {
            if(uzuvlar[hataSayisi]) uzuvlar[hataSayisi]->show();
            hataSayisi++;
            ui->listTahminler->addItem(harf);
        }
        if(hataSayisi == 10) QMessageBox::critical(this, "Sonuç", "Kaybettiniz! Kelime: " + secilenKelime);
    }
    ui->leTahmin->clear();
}
