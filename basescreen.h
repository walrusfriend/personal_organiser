#ifndef BASESCREEN_H
#define BASESCREEN_H

//  Basescreen provides a widget with main window application
//

#include "main.h"
#include "daywin.h"
#include "monthchange.h"

class BaseScreen : public QWidget
{
    Q_OBJECT

public:
    BaseScreen();
    ~BaseScreen();

private:
    QLabel* year = new QLabel;
    QPushButton* month = new QPushButton;
    QDate* curr_date = new QDate(QDate::currentDate());
    QDate* tmp_date = new QDate;

    QHBoxLayout* buttons_layout = new QHBoxLayout;
    QGridLayout* calendar_layout = new QGridLayout;
    QVBoxLayout* main_layout = new QVBoxLayout;

    QVector<QLabel*> day_tmp_vec;
    QVector<DayWin*> calendar_days;

    void screenRefresh(QDate*);

public slots:
    void monthChange();
    void changeCurrentMonth(QString);

};

#endif // BASESCREEN_H
