// Main GUI program

#include "btc_global.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    MainWindow main_wnd;
    main_wnd.show();

    return app.exec();

}
