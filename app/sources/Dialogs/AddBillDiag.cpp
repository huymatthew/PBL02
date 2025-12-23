#include <Dialogs/AddBillDiag.h>
#include <Widgets/QServiceWidget.h>

#include <Manager/DataManager.h>
#include <Data/Bill.h>
#include <Data/Contract.h>
#include <Data/Room.h>
#include <Data/Tenant.h>
#include <Data/ServiceType.h>
#include <Data/Service.h>

#include <iostream>
#include <QMessageBox>
#include <QDialog>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
using namespace std;

AddBillDialog::AddBillDialog(QWidget *parent) : QDialog(parent){
    setupUi(this);
    signalConnections();
    setFixedSize(400, 300);
    statusComboBox->setCurrentIndex(1);
}

AddBillDialog::~AddBillDialog() {}

void AddBillDialog::on_saveButton_clicked() {
    DataManager& dataManager = DataManager::getInstance();

    int contractid = contractID->text().toInt();
    string monthYearStr = yearEdit->text().toStdString() + "-" + monthComboBox->currentText().toStdString();
    double roomRent = monthlyRentSpinBox->value();
    double totalAmount = sumSpinBox->value();
    int status = statusComboBox->currentIndex();

    if (dataManager.getBillManager().addBill(contractid, monthYearStr, roomRent, totalAmount, status) == false) {
        QMessageBox::warning(this, "Lỗi", "Thêm hóa đơn thất bại. Vui lòng thử lại.");
        return;
    }

    int billId = dataManager.getBillManager().getNextId() - 1;

    for (int i = 0; i < service->count(); ++i) {
        cout << "Adding service " << i << endl;
        QListWidgetItem* item = service->item(i);
        QServiceWidget* serviceWidget = static_cast<QServiceWidget*>(service->itemWidget(item));
        if (serviceWidget) {
            dataManager.getServiceManager().addService(serviceWidget->getType(),
                            billId,
                            serviceWidget->getQuantity(), 
                            serviceWidget->getPricePerUnit() * serviceWidget->getQuantity());

        }
    }
    QMessageBox::information(this, "Lưu hóa đơn", "Hóa đơn đã được lưu thành công. \n Mã hóa đơn: " + QString::number(billId));
    accept();
}

void AddBillDialog::on_cancelButton_clicked() {
    reject();
}

void AddBillDialog::on_service_addButton_clicked() {
    QServiceWidget* serviceWidget = new QServiceWidget(this);
    QListWidgetItem* item = new QListWidgetItem(service);
    item->setSizeHint(serviceWidget->sizeHint());
    service->addItem(item);
    service->setItemWidget(item, serviceWidget);
}

void AddBillDialog::setRoom(int roomId) {
    DataManager& dataManager = DataManager::getInstance();
    Contract* contract = dataManager.getContractManager().getActiveContractByRoom(roomId);
    if (contract) {
        contractID->setText(QString::number(contract->getId()));
        Room* room = dataManager.getRoomManager().get(roomId);
        if (room) {
            roomBox->setText(QString::fromStdString(room->getRoomName()));
        }
        Tenant* tenant = dataManager.getMainTenantFromContract(contract->getId());
        if (tenant) {
            resName->setText(QString::fromStdString(formatSpace(tenant->getFullName())));
        }
        monthlyRentSpinBox->setValue(contract->getMonthlyRent());
        monthComboBox->setCurrentIndex(QDate::currentDate().month() - 1);
        yearEdit->setText(QString::number(QDate::currentDate().year()));
    } else {
        QMessageBox::warning(this, "Không có hợp đồng", "Phòng đã chọn không có hợp đồng đang hoạt động.");
    }
}

void AddBillDialog::on_service_removeButton_clicked() {
    QListWidgetItem* item = service->currentItem();
    if (item) {
        delete service->takeItem(service->row(item));
    } else {
        QMessageBox::warning(this, "Xóa dịch vụ", "Vui lòng chọn dịch vụ để xóa.");
    }
}

void AddBillDialog::updateTotal() {
    double total = monthlyRentSpinBox->value();
    for (int i = 0; i < service->count(); ++i) {
        QListWidgetItem* item = service->item(i);
        QServiceWidget* serviceWidget = static_cast<QServiceWidget*>(service->itemWidget(item));
        if (serviceWidget) {
            total += serviceWidget->getPricePerUnit() * serviceWidget->getQuantity();
        }
    }
    sumSpinBox->setValue(total);
}

void AddBillDialog::signalConnections() {
    connect(addService, &QPushButton::clicked, this, &AddBillDialog::on_service_addButton_clicked);
    connect(removeService, &QPushButton::clicked, this, &AddBillDialog::on_service_removeButton_clicked);
    connect(saveButton, &QPushButton::clicked, this, &AddBillDialog::on_saveButton_clicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddBillDialog::on_cancelButton_clicked);
    connect(monthlyRentSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, [this](double value) {
        updateTotal();
    });
}
