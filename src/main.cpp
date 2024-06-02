#include <QApplication>
#include "ui/MainWindow.h"
#include "instrument/dither/OrderedDither.h"
#include <QThreadPool>
#include <iostream>

#include <cstdlib>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

     MainWindow window;
     window.show();

    return QApplication::exec();
}
