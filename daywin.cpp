#include "daywin.h"

DayWin::DayWin(int8_t day) {
    info->setNum(day);
    info->setFrameStyle(QFrame::Box | QFrame::Plain);
    info->setAlignment(Qt::AlignCenter);

    // Layout
    pgrd->addWidget(info);

    setLayout(pgrd);
}

DayWin::~DayWin(){
    delete date;
    delete info;
    delete pgrd;
}
