#ifndef MONTHCHANGE_H
#define MONTHCHANGE_H

// Pop-up screen for choosing a month or year

#include "main.h"
#include <QDialog>

class MonthOrYearChange : public QDialog
{
    Q_OBJECT
public:
    MonthOrYearChange(int16_t curr);
    ~MonthOrYearChange();

private:
    QVector<QPushButton*> buttons;
    QGridLayout* grd = new QGridLayout;
    QPushButton* cancel_btn = new QPushButton("&Cancel");

    void chooseMonth();
    void chooseYear(int16_t curr);

public slots:
    void setNewValue();

signals:
    void changeMonthEvent(QString month);
    void changeYearEvent(int16_t year);
};

#endif // MONTHCHANGE_H
