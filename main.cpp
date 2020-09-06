#include "main.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    BaseScreen mainwindow;

    // window size properties
    int width = 500;
    int height = 500;
        // set window to the center of the screen
    mainwindow.setGeometry(
                (QApplication::desktop()->screenGeometry().width() - width) / 2,
                (QApplication::desktop()->screenGeometry().height() - height) / 2,
                width,
                height
                );
    mainwindow.setWindowTitle("Personal Organizer");


    mainwindow.show();

    return app.exec();
}
