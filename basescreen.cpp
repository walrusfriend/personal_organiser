#include "basescreen.h"

BaseScreen::BaseScreen() {

    // Month label settings
    year->setFlat(true);
    month->setFlat(true);

    // Base screen rendering
    // Add days of the week to the grid layout
    for(int i = 0; i < 7; i++) {    // Magic number 7 is number of the days of the week
        QLabel* day_tmp = new QLabel(list_of_days_of_the_week[i]);
        calendar_layout->addWidget(day_tmp, 0, i);
        day_tmp_vec.push_back(day_tmp); // With vector we can free the memory later
    }

    // Rendering the screen
    screenRefresh(curr_date);

    // buttons settings
    buttons_layout->addWidget(set_curr_date);

    // Layout properties
    main_layout->addWidget(year);
    main_layout->addWidget(month);
    main_layout->addLayout(calendar_layout);
    main_layout->addLayout(buttons_layout);

    setLayout(main_layout);

    // Linking objects
        // set the custom month
    QObject::connect(year, SIGNAL(clicked()), this, SLOT(yearChange()));
        // set the custom year
    QObject::connect(month, SIGNAL(clicked()), this, SLOT(monthChange()));
        // set the current date
    QObject::connect(set_curr_date, SIGNAL(clicked()), this, SLOT(changeCurrentDate()));
}

BaseScreen::~BaseScreen(){
    for(int i = 0; i < 7; i++) {
        delete day_tmp_vec[i];
    }

    for(int i = 0; i < calendar_days.size(); i++) {
        delete calendar_days[i];
    }

    delete curr_date;
    delete tmp_date;
    delete year;
    delete month;
    delete set_curr_date;

    delete buttons_layout;
    delete calendar_layout;
    delete main_layout;
}

void BaseScreen::screenRefresh(QDate* date) {
    // Add year and month
    year->setText(QString::number(date->year()));
    month->setText(list_of_the_months[date->month() - 1]);

    // Define and check numbers of the month
    int8_t number_of_days_in_month = date->daysInMonth();
    if(number_of_days_in_month < 28 || number_of_days_in_month > 31) {
        QMessageBox error;
        error.critical(0,"Error","The month should be from 28 to 31 days!");
        error.setFixedSize(500,200);
        return;
    }

    // Turn off old widgets
    for(int i = 0; i < calendar_days.size(); i++) {
        calendar_layout->removeWidget(calendar_days[i]);
        delete calendar_days[i];
    }

    // Add dates to the grid
        // define what's day is first in month
    calendar_days.clear();
    int8_t first_day = date->dayOfWeek() - (date->day() % 7 - 1);
    for(int i = 0; i < number_of_days_in_month; i++) {
        DayWin* day = new DayWin(i + 1);
        calendar_layout->addWidget(day, (first_day + i - 1) / 7 + 3,
                                   (first_day + i - 1) % 7);
        calendar_days.push_back(day);
    }
}

void BaseScreen::monthChange(){
    MonthOrYearChange* win = new MonthOrYearChange(curr_date->month());
    QObject::connect(win, SIGNAL(changeMonthEvent(QString)), this, SLOT(changeCurrentDate(QString)));
    win->exec();
}

void BaseScreen::yearChange() {
    MonthOrYearChange* tmp = new MonthOrYearChange(curr_date->year());
    QObject::connect(tmp, SIGNAL(changeYearEvent(int16_t)), this, SLOT(changeCurrentDate(int16_t)));
    tmp->exec();
}

void BaseScreen::changeCurrentDate() {
    *tmp_date = *curr_date;
    screenRefresh(tmp_date);
}

void BaseScreen::changeCurrentDate(int16_t new_year) {
    tmp_date->setDate(new_year, tmp_date->month(), 1);
    screenRefresh(tmp_date);
}
void BaseScreen::changeCurrentDate(QString new_month) {
    int8_t month_num = 0;
    for(int i = 0; i < 12; i++)
        if(new_month == list_of_the_months[i]) {
            month_num = i + 1;
            break;
        }

    tmp_date->setDate(tmp_date->year(), month_num, 1);
    screenRefresh(tmp_date);
}
