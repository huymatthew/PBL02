#ifndef ADD_BILL_DIAG_H
#define ADD_BILL_DIAG_H

#include <QDialog>
#include <QComboBox>
#include <Data/Tenant.h>

#include <Manager/DataManager.h>

#include <Core/ExtraFormat.h>
#include <add_bill_dialog.h>

class AddBillDialog : public QDialog, public Ui_AddBillDialog
{
public:
    AddBillDialog(QWidget *parent, DataManager *dataManager);
    ~AddBillDialog();

    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_tenant_addButton_clicked();
    void on_tenant_removeButton_clicked();

    void setRoom(int roomId);

private:
    void signalConnections();
    DataManager *dataManager;
};


#endif // ADD_BILL_DIAG_H