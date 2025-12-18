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
#include <Secure/Authentication.h>

using namespace std;

int runApp(int argc, char *argv[]);


int main(int argc, char *argv[]) {
    Authentication oauth;
    if (oauth.Auth()){
        return runApp(argc, argv);
    }
    else{
        cout << "Exiting application..." << endl;
        return 0;
    }
}

int runApp(int argc, char *argv[]){
    qputenv("QT_LOGGING_RULES", "qt.qpa.*=false");
    QLocale locale(QLocale::Vietnamese, QLocale::Vietnam);
    QLocale::setDefault(locale);
    
    QApplication app(argc, argv);
    QMainWindow nw;
    
    QuanLy quanLy(&nw);
    nw.showMaximized();
    nw.setFocus();
    return app.exec();
}
