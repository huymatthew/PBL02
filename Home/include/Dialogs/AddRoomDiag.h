#ifndef ADD_ROOM_DIAG_H
#define ADD_ROOM_DIAG_H

#include <QDialog>
#include <QComboBox>

#include <add_room_dialog.h>
using namespace std;

class AddRoomDiag: public QDialog, public Ui_AddRoomDialog {
    Q_OBJECT
    public:
    AddRoomDiag(QWidget* parent = nullptr);
};

#endif // ADD_ROOM_DIAG_H
