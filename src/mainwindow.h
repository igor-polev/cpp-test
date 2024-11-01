#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "btc_global.h"
#include "btc_key.hpp"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    btc_key keyManager;

};

#endif