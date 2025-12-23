#ifndef EXTRA_FORMAT_H
#define EXTRA_FORMAT_H
#include <string>
#include <sstream>
#include <QString>
#include <QDate>
using namespace std;

QString moneyFormat(double amount);
QString dateFormat(const string& date);
QString monthFormat(const string& monthyear);

string formatDate(const QString& date);
string formatDate(const string& date);

string datetostring(const QDate& date);
string monthtostring(string monthyear);
string formatName(const string& name);
string formatSpace(const string& str);

QString idnumber(const int& id, int length);
#endif // EXTRA_FORMAT_H