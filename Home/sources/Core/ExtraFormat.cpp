#include <Core/ExtraFormat.h>

QString moneyFormat(double amount) {
    QString formatted = QString::number(amount, 'f', 0);
    int len = formatted.length();
    for (int i = len - 3; i > 0; i -= 3) {
        formatted.insert(i, ',');
    }
    return formatted + " VND";
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