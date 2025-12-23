#include <Core/ExtraFormat.h>

QString moneyFormat(double amount) {
    QString formatted = QString::number(amount, 'f', 0);
    int len = formatted.length();
    for (int i = len - 3; i > 0; i -= 3) {
        formatted.insert(i, ',');
    }
    return formatted + " VND";
}

QString dateFormat(const string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return "";
    }
    QString year = QString::fromStdString(date.substr(0, 4));
    QString month = QString::fromStdString(date.substr(5, 2));
    QString day = QString::fromStdString(date.substr(8, 2));
    return day + "/" + month + "/" + year;
}

QString monthFormat(const string& monthYear) {
    if (monthYear.length() != 7 || monthYear[4] != '-') {
        return "";
    }
    QString year = QString::fromStdString(monthYear.substr(0, 4));
    QString month = QString::fromStdString(monthYear.substr(5, 2));
    return month + "/" + year;
}

// from "dd/mm/yyyy" to "yyyy-mm-dd"
string formatDate(const QString& date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') {
        return "";
    }
    string day = date.mid(0, 2).toStdString();
    string month = date.mid(3, 2).toStdString();
    string year = date.mid(6, 4).toStdString();
    return year + "-" + month + "-" + day;
}


string datetostring(const QDate& date) {
    return date.toString("yyyy-MM-dd").toStdString();
}

// from "yyyy-MM" to "MM/yyyy" 
string monthtostring(string monthYear) {
    if (monthYear.length() != 7 || monthYear[4] != '-') {
        return "";
    }
    string year = monthYear.substr(0, 4);
    string month = monthYear.substr(5, 2);
    return month + "/" + year;
}

string formatName(const string& name) {
    ostringstream oss;
    for (char c : name) {
        if (c == ' ')
            oss << '~';
        else
            oss << c;
    }
    return oss.str();
}

string formatSpace(const string& str) {
    ostringstream oss;
    for (char c : str) {
        if (c == '~')
            oss << ' ';
        else
            oss << c;
    }
    return oss.str();
}

QString idnumber(const int& id, int length){
    QString s = QString::number(id);
    QString result = "";
    int zeroCount = length - s.size();
    for (int i = 0; i < length;i++){
        if (i < zeroCount){
            result += '0';
        }
    }
    result += s;
    return result;
}