#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void listele();

private slots:
    void on_btnEkle_clicked();
    void on_btnSil_clicked();
    void on_btnGuncelle_clicked();
    void on_btnBasla_clicked();
    void on_btnTahmin_clicked();
    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    QString secilenKelime, gorunenKelime, seciliID;
    int hataSayisi = 0;
    QLabel* uzuvlar[10];
};
#endif
