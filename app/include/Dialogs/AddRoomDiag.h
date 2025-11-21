#ifndef ADD_ROOM_DIAG_H
#define ADD_ROOM_DIAG_H
#include <QDialog>
#include <QComboBox>
#include <Manager/RoomManager.h>  
#include <Manager/DataManager.h>
#include <Core/ExtraFormat.h>   

#include <add_room_dialog.h>
using namespace std;
class AddRoomDiag: public QDialog, public Ui_AddRoomDialog {
public:
    AddRoomDiag(QWidget* parent);
    AddRoomDiag(Room* room, QWidget* parent);
    ~AddRoomDiag();

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void signalConnect();
private:
    Room* editingRoom = nullptr;
};

#endif // ADD_ROOM_DIAG_H

