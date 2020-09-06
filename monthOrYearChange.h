#ifndef MONTHCHANGE_H
#define MONTHCHANGE_H

// Pop-up screen for choosing a month or year

#include "main.h"
#include <QDialog>

class monthOrYearChange : public QDialog
{
    Q_OBJECT
public:
    monthOrYearChange(int curr_month);
    ~monthOrYearChange();

private:
    QString picked_month;

    QVector<QPushButton*> buttons;
    QGridLayout* grd = new QGridLayout;
    QPushButton* cancel_btn = new QPushButton("&Cancel");

public slots:
    void setMonth();

signals:
    void changeEvent(QString month);
};

#endif // MONTHCHANGE_H
