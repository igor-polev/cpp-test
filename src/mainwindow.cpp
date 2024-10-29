#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    ui->UserInput->setPlaceholderText(QString::fromStdString(
        "Please, enter minimum " + std::to_string(MIN_PASS_LENGTH) + " symbols."
    ));

    connect(
        ui->UserInput,  SIGNAL(textChanged(QString)),
        &keyManager,    SLOT  (changeValue(QString))
    );
    connect(
        &keyManager,    SIGNAL(newPrivate(QString)),
        ui->PrivateKey, SLOT  (setText(QString))
    );
    connect(
        &keyManager,    SIGNAL(newWIFc(QString)),
        ui->WIFc,       SLOT  (setText(QString))
    );
    connect(
        &keyManager,    SIGNAL(newWIFu(QString)),
        ui->WIFu,       SLOT  (setText(QString))
    );
    connect(
        &keyManager,    SIGNAL(newP2PKHc(QString)),
        ui->P2PKHc,     SLOT  (setText(QString))
    );
    connect(
        &keyManager,    SIGNAL(newP2PKHu(QString)),
        ui->P2PKHu,     SLOT  (setText(QString))
    );
    connect(
        &keyManager,    SIGNAL(newP2SHc(QString)),
        ui->P2SHc,      SLOT  (setText(QString))
    );
    connect(
        &keyManager,    SIGNAL(newBECH32c(QString)),
        ui->BECH32c,    SLOT  (setText(QString))
    );

}

MainWindow::~MainWindow() { delete ui; }
