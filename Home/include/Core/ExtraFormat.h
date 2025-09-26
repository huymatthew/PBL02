#ifndef EXTRA_FORMAT_H
#define EXTRA_FORMAT_H
#include <string>
#include <sstream>
#include <QString>
#include <QDate>
using namespace std;

QString moneyFormat(double amount);
string formatDate(const QString& date);
string datetostring(const QDate& date);
string formatName(const string& name);
#endif // EXTRA_FORMAT_H