#include <Dialogs/AddContractDiag.h>
#include <QMessageBox>
#include <algorithm>

using namespace std;

AddContractDialog::AddContractDialog(QWidget *parent) : QDialog(parent), Ui_AddContractDialog() {
    setupUi(this);
    for (const auto& room : DataManager::getInstance().getRoomManager().getAllAvailableRooms()) {
        roomIdComboBox->addItem(QString::fromStdString(room->getRoomName()), QVariant::fromValue(room->getId()));
    }
    on_room_change();
    signalConnections();
}
AddContractDialog::~AddContractDialog() {}

void AddContractDialog::on_saveButton_clicked() {
    int roomId = roomIdComboBox->currentData().toInt();
    QDate startDate = startDateEdit->date();
    QDate endDate = endDateEdit->date();
    double monthlyRent = monthlyRentSpinBox->value();
    double deposit = depositSpinBox->value();
    int status = 1;
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

    // check overlap tenants
    bool tenantOverlap = false;
    unordered_set<int> tenantIds;
    for (int i = 0; i < tenantList->count(); ++i) {
        QListWidgetItem* item = tenantList->item(i);
        QComboBox* tenantComboBox = qobject_cast<QComboBox*>(tenantList->itemWidget(item));
        if (tenantComboBox) {
            int tenantId = tenantComboBox->currentData().toInt();
            if (tenantIds.find(tenantId) != tenantIds.end()) {
                tenantOverlap = true;
                break;
            }
            tenantIds.insert(tenantId);
        }
    }
    if (tenantOverlap) {
        errorlog += "- Duplicate tenants detected. Please ensure each tenant is added only once.\n";
    }


    if (!errorlog.empty()) {
        QMessageBox::warning(this, "Lỗi nhập liệu", QString::fromStdString(errorlog));
        return;
    }

    DataManager::getInstance().getRoomManager().setRoomOccupied(roomId);
    ContractManager* contractManager = &DataManager::getInstance().getContractManager();
    
    string note = notes.toStdString();
    std::replace(note.begin(), note.end(),' ', '~');
    if (!contractManager->addContract(roomId, startDate.toString("yyyy-MM-dd").toStdString(),
    endDate.toString("yyyy-MM-dd").toStdString(), monthlyRent,
    deposit, status, note)) {
        QMessageBox::critical(this, "Lỗi", "Thêm hợp đồng thất bại. Vui lòng kiểm tra thông tin và thử lại.");
        return;
    }
    Contract newContract = *contractManager->getActiveContractByRoom(roomId);

    for (int i = 0; i < tenantList->count(); ++i) {
        QListWidgetItem* item = tenantList->item(i);
        QComboBox* tenantComboBox = qobject_cast<QComboBox*>(tenantList->itemWidget(item));
        if (tenantComboBox) {
            int tenantId = tenantComboBox->currentData().toInt();
            DataManager::getInstance().getRentManager().addRent(newContract.getId(), tenantId, i == 0);
        }
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

    for (const auto& tenant : DataManager::getInstance().getAllNoRoomTenants()) {
        tenantComboBox->addItem(QString::fromStdString(tenant.getFullName() + " - " + std::to_string(tenant.getId())), QVariant::fromValue(tenant.getId()));
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

void AddContractDialog::on_room_change(){
    Room* room = DataManager::getInstance().getRoomManager().get(roomIdComboBox->currentData().toInt());
    if (room) {
        monthlyRentSpinBox->setValue(room->getMonthlyRent());
    }
    else{
        QMessageBox::warning(this, "Không tìm thấy phòng", "Không thể tìm thấy phòng đã chọn.");
    }
}

void AddContractDialog::signalConnections() {
    connect(saveButton, &QPushButton::clicked, this, &AddContractDialog::on_saveButton_clicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddContractDialog::on_cancelButton_clicked);
    connect(addTenant, &QPushButton::clicked, this, &AddContractDialog::on_tenant_addButton_clicked);
    connect(removeTenant, &QPushButton::clicked, this, &AddContractDialog::on_tenant_removeButton_clicked);
    connect(roomIdComboBox, &QComboBox::currentTextChanged, this, &AddContractDialog::on_room_change);
}