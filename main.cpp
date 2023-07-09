#include "mainwindow.h"
#include "introWindow.h"

#include <QApplication>

MainWindow *w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IntroWindow introWindow;
    introWindow.show();

    // Connect the startGameSignal from IntroWindow to the constructor of MainWindow
    QObject::connect(&introWindow, &IntroWindow::startGameSignal, [&]() {
        // Call the constructor of MainWindow directly
        w= new MainWindow();
        w->show();
    });

    return a.exec();
}
