#include "monthoryearchange.h"

MonthOrYearChange::MonthOrYearChange(int16_t curr)
{
    // set this attribute for delete this object when it's close
    setAttribute(Qt::WA_DeleteOnClose);

    // window properties
    int width = 200;
    int height = 300;
    setGeometry((QApplication::desktop()->screenGeometry().width() - width) / 2,
                (QApplication::desktop()->screenGeometry().height() - height) / 2,
                width,
                height
                );

    if(curr <= 12)
        chooseMonth();
    else
        chooseYear(curr);

    QObject::connect(cancel_btn, SIGNAL(clicked()), this, SLOT(close()));
    grd->addWidget(cancel_btn);

    // Layout settings
    setLayout(grd);
}

MonthOrYearChange::~MonthOrYearChange(){
    for(int i = 0; i < buttons.size(); i++) {
        delete buttons[i];
    }
    delete cancel_btn;
    delete grd;
}

void MonthOrYearChange::setNewValue() {
    QPushButton* psender = qobject_cast<QPushButton*>(sender());
    if(psender->text().toInt() < 13)
        emit changeMonthEvent(psender->text());
    else
        emit changeYearEvent(psender->text().toInt());
    close();
}

void MonthOrYearChange::chooseMonth() {
    setWindowTitle("Month Change");

    // Fiil the grid
    for(int i = 0; i < 12; i++) {
        QPushButton* month_tmp = new QPushButton(list_of_the_months[i]);
        buttons.push_back(month_tmp);
        grd->addWidget(month_tmp, i / 3, i % 3);
        // Linking
        QObject::connect(month_tmp, SIGNAL(clicked()), this, SLOT(setNewValue()));
    }
}

void MonthOrYearChange::chooseYear(int16_t curr) {
    setWindowTitle("Year Change");

    int8_t rows = 5, lines = 5;
    int16_t start_value = curr - rows * lines / 2;
    for(int i = 0; i < lines * rows; i++) {
        QPushButton* year_tmp = new QPushButton;
        year_tmp->setText(QString::number(start_value + i));
        buttons.push_back(year_tmp);
        grd->addWidget(year_tmp, i / rows, i % rows);
        // Linking
        QObject::connect(year_tmp, SIGNAL(clicked()), this, SLOT(setNewValue()));
    }

}
