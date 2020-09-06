#ifndef BASESCREEN_H
#define BASESCREEN_H

//  Basescreen provides a widget with main window application
//

#include "main.h"
#include "daywin.h"
#include "monthoryearchange.h"

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
    QDate* tmp_date = new QDate;

    QHBoxLayout* buttons_layout = new QHBoxLayout;
    QGridLayout* calendar_layout = new QGridLayout;
    QVBoxLayout* main_layout = new QVBoxLayout;

    QVector<QLabel*> day_tmp_vec;
    QVector<DayWin*> calendar_days;

    void screenRefresh(QDate*);

public slots:
    void monthChange();
    void yearChange();
    void changeCurrentYear(int16_t);
    void changeCurrentMonth(QString);

};

#endif // BASESCREEN_H
