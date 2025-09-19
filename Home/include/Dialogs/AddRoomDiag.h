#ifndef ADD_ROOM_DIAG_H
#define ADD_ROOM_DIAG_H
#include <QDialog>
#include <QComboBox>
#include <Manager/RoomManager.h>  
#include <Core/ExtraFormat.h>   

#include <add_room_dialog.h>
using namespace std;
class AddRoomDiag: public QDialog, public Ui_AddRoomDialog {
    public:
    AddRoomDiag(QWidget* parent, RoomManager& roomManager);
    ~AddRoomDiag();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void signalConnect();

    private:
    RoomManager& roomManager;
};

#endif // ADD_ROOM_DIAG_H

