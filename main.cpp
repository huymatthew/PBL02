#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <iostream>

#include <Data/Bill.h>
#include <Data/Contract.h>
#include <Data/Tenant.h>
#include <Data/Room.h>
#include <Core/PrimaryKey.h>
#include <QuanLy.h>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow nw;
    QuanLy quanLy;
    quanLy.setupUi(&nw);
    nw.show();
    return app.exec();
}