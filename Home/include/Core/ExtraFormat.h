#ifndef EXTRA_FORMAT_H
#define EXTRA_FORMAT_H
#include <string>
#include <sstream>
#include <QString>
using namespace std;

QString moneyFormat(double amount);
string formatDate(const QString& date);
#endif // EXTRA_FORMAT_H