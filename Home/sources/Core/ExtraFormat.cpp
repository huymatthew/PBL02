#include <Core/ExtraFormat.h>

QString moneyFormat(double amount) {
    QString formatted = QString::number(amount, 'f', 0);
    int len = formatted.length();
    for (int i = len - 3; i > 0; i -= 3) {
        formatted.insert(i, ',');
    }
    return formatted + " VND";
}