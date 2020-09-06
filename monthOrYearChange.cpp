#include "monthchange.h"

MonthChange::MonthChange(int curr_month)
{
    // window properties
    int width = 200;
    int height = 300;
    setGeometry((QApplication::desktop()->screenGeometry().width() - width) / 2,
                (QApplication::desktop()->screenGeometry().height() - height) / 2,
                width,
                height
                );
    setWindowTitle("Month Change");

    // Fiil the grid
    buttons.resize(12);
    for(int i = 0; i < 12; i++) {
        QPushButton* month_tmp = new QPushButton(list_of_the_months[i]);
        buttons[i] = month_tmp;
        grd->addWidget(month_tmp, i / 3, i % 3);
        // Linking
        QObject::connect(month_tmp, SIGNAL(clicked()), this, SLOT(setMonth()));
    }
    QObject::connect(cancel_btn, SIGNAL(clicked()), this, SLOT(close()));
    grd->addWidget(cancel_btn, 4, 0, 1, 3);

    // Layout settings
    setLayout(grd);
}

MonthChange::~MonthChange(){
    for(int i = 0; i < buttons.size(); i++) {
        delete buttons[i];
    }
    delete grd;
}

void MonthChange::setMonth() {
    QPushButton* senderPointer = qobject_cast<QPushButton*>(sender());
    picked_month = senderPointer->text();
    emit monthChangeEvent(picked_month);
    close();
}
