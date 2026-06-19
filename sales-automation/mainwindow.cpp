#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // --- 1. Veritabanı Bağlantısı (Kaynak 7 Standart) ---
    db = QSqlDatabase::addDatabase("QSQLITE");

    // Veritabanı dosyasının yolu (Sınavda burayı kontrol et!)
    db.setDatabaseName("C:/Users/EXCALIBUR/OneDrive/Masaüstü/Yazılım Ders 3/Görsel Programlama/FİNAL-TaksitÖrnek/TaksitOrnek/final.db");

    // Bağlantı başarısızsa hata mesajı ver
    if (!db.open()) {
        QMessageBox::critical(this, "Baglanti hatasi", db.lastError().text());
    }

    // --- 2. Nesnelerin Oluşturulması (Heap Allocation) ---
    musteriler = new QSqlQuery(db);
    Satislar = new QSqlQuery(db);
    SatislarEkleme = new QSqlQuery(db);
    Urunler = new QSqlQuery(db);

    musmodel = new QSqlQueryModel();
    satismodel = new QSqlQueryModel();
    satiseklememodel = new QSqlQueryModel();
    urunmodel = new QSqlQueryModel();

    // --- 3. Başlangıç Fonksiyonlarının Çağrılması ---
    musteriListele(""); // Müşterileri listele (parametre yok, hepsi gelir)
    urunListele();      // Ürünleri widget'larla doldur
    satisListele();     // Eski satışları göster
}

MainWindow::~MainWindow()
{
    delete ui;
}

// --- Müşteri Listeleme (Kaynak 8 - Filtreli) ---
void MainWindow::musteriListele(QString prm)
{
    // Eğer parametre (prm) boşsa hepsini getir
    if (prm.isEmpty()) {
        musteriler->exec("select * from musteriler");
    } else {
        // Değilse isme göre filtrele (LIKE 'Ahmet%')
        musteriler->exec("select * from musteriler where adi like '" + prm + "%'");
    }
    // Sonucu modele yükle ve ekrana bas
    musmodel->setQuery(*musteriler);
    ui->tableView->setModel(musmodel);
}

// --- Ürünleri Widget ile Listeleme (Kaynak 9 - En Önemli Kısım) ---
void MainWindow::urunListele()
{
    // 1. Ürün verilerini veritabanından çek
    Urunler->prepare("SELECT UrunID, UrunKod, Adi, Fiyati from Urunler");
    Urunler->exec();

    // 2. Veriyi modele al (Okumak için kullanacağız)
    urunmodel->setQuery(*Urunler);

    // 3. TableWidget Ayarları (Manuel Tablo)
    ui->tableWidget->setColumnCount(7); // 7 Sütun olacak
    ui->tableWidget->setRowCount(urunmodel->rowCount()); // Veri kadar satır aç

    // Başlıkları ayarla
    QStringList baslik = {"Ürün id", "Urun Kod ", "Urun Ad", "Tutar" ,"KDV Oranı","Adet","Satıldı mı"};
    ui->tableWidget->setHorizontalHeaderLabels(baslik);

    // 4. DÖNGÜ: Her satırı tek tek doldur
    for (int i = 0; i < urunmodel->rowCount(); ++i) {

        // İlk 3 sütuna normal yazı (Label) koyuyoruz (Değiştirilemez)
        ui->tableWidget->setCellWidget(i, 0, new QLabel(urunmodel->index(i, 0).data().toString())); // ID
        ui->tableWidget->setCellWidget(i, 1, new QLabel(urunmodel->index(i, 1).data().toString())); // Kod
        ui->tableWidget->setCellWidget(i, 2, new QLabel(urunmodel->index(i, 2).data().toString())); // Ad

        // 4. Sütun (Fiyat): Değiştirilebilir olsun diye QLineEdit koyuyoruz
        ui->tableWidget->setCellWidget(i, 3, new QLineEdit(urunmodel->index(i, 3).data().toString()));

        // 5. Sütun (KDV): Seçim yapabilsin diye ComboBox koyuyoruz
        cmbKdv = new QComboBox();
        cmbKdv->addItem("%1", 1);   // Ekranda %1 görünür, değeri 1'dir
        cmbKdv->addItem("%10", 10);
        cmbKdv->addItem("%20", 20);
        cmbKdv->addItem("%30", 30);
        // cmbKdv->setCurrentIndex(2); // (Yorum satırı: Varsayılanı seçmek için)

        ui->tableWidget->setCellWidget(i,4,cmbKdv); // Tabloya yerleştir

        // 6. Sütun (Adet): Sayı girebilsin diye boş LineEdit
        txtAdet = new QLineEdit();
        ui->tableWidget->setCellWidget(i,5, txtAdet);

        // 7. Sütun (Seçim): Satılacak mı? CheckBox koyuyoruz
        chckBox = new QCheckBox();
        ui->tableWidget->setCellWidget(i,6,chckBox);
    }
}

// --- Satış Listeleme (Basit Görüntüleme - Kaynak 7 Mantığı) ---
// Veritabanındaki kayıtları ekrandaki tabloya yansıtmak için kullanılır.
void MainWindow::satisListele()
{
    // 1. SQL Sorgusunu Çalıştır:
    // 'Satislar' tablosundaki TÜM verileri (sütun ve satırları) getir.
    Satislar->exec("select * from Satislar");

    // 2. Veriyi Modele Yükle:
    // Veritabanından dönen ham sonuçları (Query), Qt'nin anlayacağı formata (Model) çeviriyoruz.
    satismodel->setQuery(*Satislar);

    // 3. Modeli Görünüme (View) Bağla:
    // Arayüzdeki 'tableView_2' (Sağ Alt Tablo) nesnesine diyoruz ki:
    // "Senin göstereceğin veriler 'satismodel'in içindedir, oradan oku."
    ui->tableView_2->setModel(satismodel);
}

// --- Arama Kutusu Değişince (Canlı Arama) ---
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    musteriListele(arg1); // Filtreleme fonksiyonunu çağır
}

// --- SATIŞ YAP BUTONU (Hesaplama ve Kayıt) ---
void MainWindow::on_pushButton_clicked()
{
    // (Yorum satırı: Bu kısım alternatif bir yöntemdi, kullanılmamış)
    // int musRow = ui->tableView->currentIndex().row();
    // int musNo = musmodel->index(musRow, 0).data().toInt(); bu şekilde de kullanılabilir..

    // 1. DÖNGÜ: Tablodaki tüm satırları gez
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {

        // 2. O satırdaki CheckBox'ı bul ve CASTING yap (Widget -> CheckBox)"Tür Dönüşümü" (Casting) işlemidir.
        QCheckBox *chk = (QCheckBox*)ui->tableWidget->cellWidget(i, 6);

        // Eğer kutucuk işaretli DEĞİLSE, bu satırı geç (Satma)
        if (!chk->isChecked()){
            continue;
        }

        // 3. İşaretliyse, o satırdaki diğer verileri (Fiyat, Adet, KDV) okumak için widgetları al
        QLabel *lblUrun = (QLabel*)ui->tableWidget->cellWidget(i, 1);       // Ürün Kodu
        QLineEdit *txtFiyat = (QLineEdit*)ui->tableWidget->cellWidget(i, 3); // Fiyat
        QLineEdit *txtAdet = (QLineEdit*)ui->tableWidget->cellWidget(i, 5);  // Adet
        QComboBox *cmbKdv = (QComboBox*)ui->tableWidget->cellWidget(i, 4);   // KDV

        // 4. Widgetların içindeki verileri değişkenlere al
        QString urunNo= lblUrun->text();
        double fiyat = txtFiyat->text().toDouble(); // String -> Double
        int adet = txtAdet->text().toInt();         // String -> Int
        int kdv = cmbKdv->currentData().toInt();    // ComboBox'ın gizli verisini (1, 10, 20) al

        // 5. Matematiksel Hesaplama
        double tutar = fiyat * adet;        // Ham Tutar
        tutar = tutar + (tutar * kdv / 100); // KDV ekle

        // Alternatif hesaplama formülü (Yorum satırı)
        // double tutar = fiyat * adet * (1 + kdv / 100.0);

        // 6. Veritabanına Kaydet (Insert)
        SatislarEkleme->prepare("insert into Satislar (MusNo, UrunNo, Tutar) values (?,?,?)");
        SatislarEkleme->addBindValue(musteriNo); // Tıklanan müşterinin ID'si (Global değişkenden)
        SatislarEkleme->addBindValue(urunNo);    // O satırdaki ürün kodu
        SatislarEkleme->addBindValue(tutar);     // Hesaplanan son tutar
        SatislarEkleme->exec(); // Kaydet
    }
    // İşlem bitince listeyi yenile ki yeni satışı görelim
    satisListele();
}

// --- Sol Tabloya Tıklayınca (ID Alma) ---
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    // Tıklanan satırın 0. sütunundaki veriyi (Müşteri No) al ve global değişkene ata
    musteriNo = musmodel->index(index.row(), 0).data().toString();
}
