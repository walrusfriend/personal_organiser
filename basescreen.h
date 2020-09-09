#ifndef BASESCREEN_H
#define BASESCREEN_H

//  Basescreen provides a widget with main window application
//

#include "main.h"
#include "daywin.h"
#include "monthOrYearChange.h"

class BaseScreen : public QWidget
{
    Q_OBJECT

public:
    BaseScreen();
    ~BaseScreen();

private:
    QPushButton* year = new QPushButton;
    QPushButton* month = new QPushButton;
    QDate* curr_date = new QDate(QDate::currentDate());
    QDate* tmp_date = new QDate(*curr_date);
    QPushButton* set_curr_date = new QPushButton("Today");

    QHBoxLayout* buttons_layout = new QHBoxLayout;
    QGridLayout* calendar_layout = new QGridLayout;
    QVBoxLayout* main_layout = new QVBoxLayout;

    QVector<QLabel*> day_tmp_vec;
    QVector<DayWin*> calendar_days;

    void screenRefresh(QDate*);

public slots:
    void monthChange();
    void yearChange();
    void changeCurrentDate();
    void changeCurrentDate(int16_t year);
    void changeCurrentDate(QString month);

};

#endif // BASESCREEN_H
