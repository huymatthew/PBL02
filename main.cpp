#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QLoggingCategory>
#include <iostream>

#include <Data/Bill.h>
#include <Data/Contract.h>
#include <Data/Tenant.h>
#include <Data/Room.h>
#include <Core/PrimaryKey.h>
#include <QuanLy.h>

using namespace std;
// Chuyển qua dùng Makefile để build
// Xử lý (space) trong database

int main(int argc, char *argv[]) {
    //QLoggingCategory::setFilterRules("*.debug=true\n*.info=true\nqt.*=true");
    QApplication app(argc, argv);
    QMainWindow nw;
    QuanLy quanLy(&nw);
    nw.show();
    return app.exec();
}