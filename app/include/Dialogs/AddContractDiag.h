#ifndef ADD_CONTRACT_DIAG_H
#define ADD_CONTRACT_DIAG_H

#include <QDialog>
#include <QComboBox>
#include <Data/Tenant.h>

#include <Manager/DataManager.h>
#include <Manager/ContractManager.h>
#include <Manager/RoomManager.h>
#include <Manager/TenantManager.h>
#include <Manager/RentManager.h>

#include <Core/ExtraFormat.h>
#include <add_contract_dialog.h>

class AddContractDialog : public QDialog, public Ui_AddContractDialog
{
public:
    AddContractDialog(QWidget *parent);
    ~AddContractDialog();

    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_tenant_addButton_clicked();
    void on_tenant_removeButton_clicked();

private:
    void signalConnections();
};

#endif // ADD_CONTRACT_DIAG_H