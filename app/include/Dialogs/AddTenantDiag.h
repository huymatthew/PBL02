#ifndef ADD_TENANT_DIAG_H
#define ADD_TENANT_DIAG_H
#include <QDialog>
#include <QComboBox>
#include <Manager/DataManager.h>
#include <Manager/TenantManager.h>  
#include <Core/ExtraFormat.h>   

#include <add_tenant_dialog.h>
using namespace std;
class AddTenantDiag: public QDialog, public Ui_AddTenantDialog {
    public:
    AddTenantDiag(QWidget* parent);
    AddTenantDiag(Tenant* tenant, QWidget* parent);
    ~AddTenantDiag();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void signalConnect();

private:
    Tenant* editingTenant = nullptr;
};

#endif // ADD_TENANT_DIAG_H

