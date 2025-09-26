#include <Dialogs/AddContractDiag.h>
#include <QMessageBox>

using namespace std;

AddContractDialog::AddContractDialog(QWidget *parent, ContractManager *contractManager, RoomManager *roomManager, TenantManager *tenantManager, RentManager *rentManager)
    : QDialog(parent), contractManager(contractManager), roomManager(roomManager), tenantManager(tenantManager), rentManager(rentManager) {
    setupUi(this);
    contractIdSpinBox->setValue(contractManager->getContractCount() + 1);
    for (const auto& room : roomManager->getAllRooms()) {
        roomIdComboBox->addItem(QString::fromStdString(room.getRoomName() + " - " + (room.getStatus() ? "Occupied" : "Available")), QVariant::fromValue(room.getRoomId()));
    }
    signalConnections();
}
AddContractDialog::~AddContractDialog() {}

void AddContractDialog::on_saveButton_clicked() {
    int contractId = contractIdSpinBox->value();
    int roomId = roomIdComboBox->currentData().toInt();
    QDate startDate = startDateEdit->date();
    QDate endDate = endDateEdit->date();
    double monthlyRent = monthlyRentSpinBox->value();
    double deposit = depositSpinBox->value();
    int status = statusComboBox->currentData().toInt();
    QString notes = description->toPlainText();

    // Input validation
    string errorlog = "";
    if (roomIdComboBox->currentIndex() == -1) {
        errorlog += "- Please select a valid Room ID.\n";
    }
    if (startDate > endDate) {
        errorlog += "- Start Date cannot be after End Date.\n";
    }
    if (monthlyRent <= 0) {
        errorlog += "- Monthly Rent must be greater than zero.\n";
    }
    if (deposit < 0) {
        errorlog += "- Deposit cannot be negative.\n";
    }
    if (tenantList->count() == 0) {
        errorlog += "- Please add at least one tenant.\n";
    }
    if (roomIdComboBox->currentText().contains("Occupied")) {
        errorlog += "- Selected room is already occupied. Please choose another room.\n";
    }

    if (!errorlog.empty()) {
        QMessageBox::warning(this, "Input Error", QString::fromStdString(errorlog));
        return;
    }

    bool checkOverlap[10000] = {false};
    for (int i = 0; i < tenantList->count(); ++i) {
        QListWidgetItem* item = tenantList->item(i);
        QComboBox* tenantComboBox = qobject_cast<QComboBox*>(tenantList->itemWidget(item));
        if (tenantComboBox) {
            int tenantId = tenantComboBox->currentData().toInt();
            if (checkOverlap[tenantId]) {
                QMessageBox::warning(this, "Input Error", "Duplicate tenant detected. Please ensure each tenant is added only once.");
                return;
            }
            checkOverlap[tenantId] = true;
            rentManager->addRent(contractId, tenantId, i == 0);
        }
    }
    roomManager->setRoomOccupied(roomId);
    
    Contract newContract(contractId, roomId, startDate.toString("yyyy-MM-dd").toStdString(),
                         endDate.toString("yyyy-MM-dd").toStdString(), monthlyRent, deposit,
                         status, notes.toStdString());
    if (!contractManager->addContract(newContract)) {
        QMessageBox::critical(this, "Error", "Failed to add contract. Please check the details and try again.");
        return;
    }
    accept();
}

void AddContractDialog::on_cancelButton_clicked() {
    this->reject();
}
void AddContractDialog::on_tenant_addButton_clicked() {
    if (!tenantList) {
        qWarning("tenantList is not initialized!");
        return;
    }
    QComboBox* tenantComboBox = new QComboBox(this);
    tenantComboBox->setFixedWidth(tenantList->width() - 50);
    tenantComboBox->setEditable(false);
    tenantComboBox->setStyleSheet("QComboBox::drop-down{subcontrol-origin:padding;subcontrol-position:top right;width:25px;border-left:1px solid #ced4da;border-top-right-radius:8px;border-bottom-right-radius:8px;background-color:#f8f9fa;color:#212529;}QComboBox::down-arrow{width:15px;height:15px;background-color:#6c757d;}QComboBox QAbstractItemView{background-color:white;border:2px solid #ced4da;border-radius:8px;selection-background-color:#007bff;selection-color:black;}");

    for (const auto& tenant : tenantManager->getAllTenants()) {
        tenantComboBox->addItem(QString::fromStdString(tenant.getFullName() + " - " + std::to_string(tenant.getTenantId())), QVariant::fromValue(tenant.getTenantId()));
    }
    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint(tenantComboBox->sizeHint());
    tenantList->addItem(item);
    tenantList->setItemWidget(item, tenantComboBox);
}
void AddContractDialog::on_tenant_removeButton_clicked() {
    QListWidgetItem* selectedItem = tenantList->currentItem();
    if (selectedItem) {
        delete tenantList->takeItem(tenantList->row(selectedItem));
    }
}

void AddContractDialog::signalConnections() {
    connect(saveButton, &QPushButton::clicked, this, &AddContractDialog::on_saveButton_clicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddContractDialog::on_cancelButton_clicked);
    connect(addTenant, &QPushButton::clicked, this, &AddContractDialog::on_tenant_addButton_clicked);
    connect(removeTenant, &QPushButton::clicked, this, &AddContractDialog::on_tenant_removeButton_clicked);
}