#ifndef ADD_CONTRACT_DIAG_H
#define ADD_CONTRACT_DIAG_H

#include <QDialog>
#include <QComboBox>
#include <Data/Tenant.h>

#include <Manager/ContractManager.h>
#include <Manager/RoomManager.h>
#include <Manager/TenantManager.h>
#include <Manager/RentManager.h>

#include <Core/ExtraFormat.h>
#include <add_contract_dialog.h>

class AddContractDialog : public QDialog, public Ui_AddContractDialog
{
public:
    AddContractDialog(QWidget *parent, ContractManager *contractManager, RoomManager *roomManager, TenantManager *tenantManager, RentManager *rentManager);
    ~AddContractDialog();

    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_tenant_addButton_clicked();
    void on_tenant_removeButton_clicked();

private:
    void signalConnections();
    ContractManager *contractManager;
    RoomManager *roomManager;
    TenantManager *tenantManager;
    RentManager *rentManager;
};

#endif // ADD_CONTRACT_DIAG_H