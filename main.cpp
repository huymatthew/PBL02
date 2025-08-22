#include <QApplication>
#include <QPushButton>
#include "ui/admin_main.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow nw;
    Ui_AdminMainWindow w;
    w.setupUi(&nw);
    nw.show();
    return app.exec();
}