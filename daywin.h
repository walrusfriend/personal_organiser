#ifndef DAYWIN_H
#define DAYWIN_H

// This class contains all info about each day

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QDate>

class DayWin : public QWidget
{
    Q_OBJECT

public:

    DayWin(int8_t);
    ~DayWin();
    QDate* date = new QDate;
    QLabel* info = new QLabel;

private:

    QGridLayout* pgrd = new QGridLayout;    // main layout for the class
};

#endif // DAYWIN_H
