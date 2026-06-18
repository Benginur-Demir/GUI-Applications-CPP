#ifndef ETIKET_H
#define ETIKET_H

#include <QPushButton>
#include <QPixmap>

class Etiket : public QPushButton
{
    Q_OBJECT
public:
    explicit Etiket(QWidget *parent = nullptr);

    void setKartID(int id);
    int getKartID() const;

    void setOnYuz(const QPixmap &resim);
    void setArkaYuz(const QPixmap &resim);

    void ac();
    void kapat();

    void setEslesti();
    bool eslestiMi() const;

private:
    int kartID;
    bool acikMi;
    bool eslesti;
    QPixmap onYuzResmi;
    QPixmap arkaYuzResmi;
};

#endif
