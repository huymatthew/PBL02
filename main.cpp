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

int main(int argc, char *argv[]) {
    //QLoggingCategory::setFilterRules("*.debug=true\n*.info=true\nqt.*=true");
    QApplication app(argc, argv);
    QMainWindow nw;
    
    QuanLy quanLy(&nw);
    nw.showMaximized();
    nw.setFocus();
    return app.exec();
}