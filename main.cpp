#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include "ui/admin_main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow nw;
    Ui_AdminMainWindow uw;
    uw.setupUi(&nw);
    nw.show();
    return app.exec();
}