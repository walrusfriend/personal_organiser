#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

// A window appears when error accurs.
// Window contains error message and "ok" button

#include "main.h"

class ErrorWindow : public QWidget
{
    Q_OBJECT
public:
    ErrorWindow();

    QLabel* message = new QLabel;
    QPushButton* okey = new QPushButton;
};

#endif // ERRORWINDOW_H
