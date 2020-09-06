#include "daywin.h"

DayWin::DayWin(int8_t day) {
    info->setNum(day);
    info->setFrameStyle(QFrame::Box | QFrame::Plain);

    // Layout
    pgrd->addWidget(info);

    setLayout(pgrd);
}

DayWin::~DayWin(){
    delete date;
    delete info;
    delete pgrd;
}
