#include <Widgets/QServiceWidget.h>
#include <Data/ServiceType.h>
#include <QHBoxLayout>
using namespace std;

QServiceWidget::QServiceWidget(AddBillDialog* parent) : QWidget(parent), p(parent) {
    setupUi();
}

void QServiceWidget::setupUi() {
    DataManager& dataManager = DataManager::getInstance();
    this->setLayout(new QHBoxLayout(this));
    serviceTypeComboBox = new QComboBox(this);
    layout()->addWidget(serviceTypeComboBox);
    quantitySpinBox = new QSpinBox(this);
    quantitySpinBox->setMaximum(10000);
    layout()->addWidget(quantitySpinBox);
    unitLabel = new QLabel("Unit", this);
    layout()->addWidget(unitLabel);
    priceLabel = new QLabel("Price: 0", this);
    layout()->addWidget(priceLabel);

    
    serviceTypeComboBox->addItems(dataManager.getServiceTypeManager().getServiceTypeNamesForComboBox());
    
    ServiceType* serviceType = DataManager::getInstance().getServiceTypeManager().getServiceTypeByName(serviceTypeComboBox->currentText().toStdString());
    if (serviceType) {
        setType(serviceType->getServiceType());
    }
    p->updateTotal();
    
    connect(quantitySpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, [this](int value) {
        priceLabel->setText(QString::number(pricePerUnit * quantitySpinBox->value() / 1000, 'f', 1) + "K VND");
        p->updateTotal();
    });
    connect(serviceTypeComboBox, &QComboBox::currentTextChanged, this, [this](const QString &text) {
        ServiceType* serviceType = DataManager::getInstance().getServiceTypeManager().getServiceTypeByName(text.toStdString());
        if (serviceType) {
            setType(serviceType->getServiceType());
        }
        p->updateTotal();
    });
}
QServiceWidget::~QServiceWidget() {}

void QServiceWidget::setType(int type) {
    ServiceType* serviceType = DataManager::getInstance().getServiceTypeManager().getServiceType(type);
    quantitySpinBox->setValue(1);
    if (serviceType) {
        pricePerUnit = serviceType->getPrice();
        unitLabel->setText(QString::number(serviceType->getPrice() / 1000, 'f', 1) + "K VND / " + QString::fromStdString(serviceType->getUnit()));
        priceLabel->setText(QString::number(pricePerUnit * quantitySpinBox->value() / 1000, 'f', 1) + "K VND");
    } else {
        pricePerUnit = 0.0;
        unitLabel->setText("Unit");
        priceLabel->setText("Price: 0");
    }
}
int QServiceWidget::getType() const {
    ServiceType* serviceType = DataManager::getInstance().getServiceTypeManager().getServiceTypeByName(serviceTypeComboBox->currentText().toStdString());
    return serviceType ? serviceType->getServiceType() : -1;
}
int QServiceWidget::getQuantity() const {
    return quantitySpinBox->value();
}
double QServiceWidget::getPricePerUnit() const {
    return pricePerUnit;
}
