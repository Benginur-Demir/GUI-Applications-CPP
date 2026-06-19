#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// Veritabanı işlemleri için gerekli kütüphaneler (Kaynak 7)
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
// Arayüz elemanları için kütüphaneler (Kaynak 9 - TableWidget içi)
#include <qcombobox.h>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // --- Kendi yazdığımız fonksiyonlar ---
    void musteriListele(QString prm); // Müşterileri isme göre filtreler
    void urunListele();               // Ürünleri TableWidget içine widget'larla doldurur
    void satisListele();              // Yapılan satışları listeler

private slots:
    // Arama kutusuna yazı yazıldıkça çalışır (Canlı Arama - Kaynak 8)
    void on_lineEdit_textChanged(const QString &arg1);

    // "Satış Yap" butonuna basılınca çalışır (Toplu Kayıt - Kaynak 9)
    void on_pushButton_clicked();

    // Sol tablodan müşteri seçilince ID'sini alır
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    // Veritabanı bağlantı nesnesi
    QSqlDatabase db;

    // Sorgu çalıştırmak için kullanılan işaretçiler (Pointers)
    QSqlQuery *musteriler, *Satislar, *Urunler , *SatislarEkleme;

    // Verileri tabloda göstermek için modeller (View için)
    QSqlQueryModel *musmodel, *satismodel, *urunmodel , *satiseklememodel;

    // Kod içinde dinamik oluşturacağımız nesneler
    QComboBox *cmbKdv;   // Her satıra KDV seçimi için
    QLineEdit *txtAdet;  // Her satıra Adet girişi için
    QCheckBox *chckBox;  // Satırı seçmek için kutucuk

    // Seçilen müşterinin numarasını hafızada tutmak için değişken
    QString musteriNo;

};
#endif // MAINWINDOW_H
