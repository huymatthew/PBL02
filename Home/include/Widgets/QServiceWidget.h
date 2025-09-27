#ifndef Q_SERVICE_WIDGET_H
#define Q_SERVICE_WIDGET_H

#include <Dialogs/AddBillDiag.h>
#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>

class QServiceWidget : public QWidget {
public:
    QServiceWidget(AddBillDialog* parent = nullptr);
    ~QServiceWidget();

    void setupUi();
    void setType(int type);

    int getType() const;
    int getQuantity() const;
    double getPricePerUnit() const;
private:
    AddBillDialog* p;
    QComboBox* serviceTypeComboBox;
    QSpinBox* quantitySpinBox;
    QLabel* priceLabel;
    QLabel* unitLabel;

    double pricePerUnit;
};

#endif // Q_SERVICE_WIDGET_H