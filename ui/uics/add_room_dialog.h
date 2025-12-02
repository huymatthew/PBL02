/********************************************************************************
** Form generated from reading UI file 'add_room_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_ROOM_DIALOG_H
#define ADD_ROOM_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddRoomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxRoomInfo;
    QFormLayout *formLayout;
    QLabel *labelRoomNumber;
    QLineEdit *lineEditRoomNumber;
    QLabel *labelRoomType;
    QComboBox *comboBoxRoomType;
    QDoubleSpinBox *doubleSpinBoxRentPrice;
    QLabel *labelRentPrice;
    QGroupBox *groupBoxStatus;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_3;
    QLabel *labelStatus;
    QComboBox *comboBoxStatus;
    QLabel *labelDescription;
    QPlainTextEdit *plainTextEditDescription;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddRoomDialog)
    {
        if (AddRoomDialog->objectName().isEmpty())
            AddRoomDialog->setObjectName(QString::fromUtf8("AddRoomDialog"));
        AddRoomDialog->resize(500, 658);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/room-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddRoomDialog->setWindowIcon(icon);
        AddRoomDialog->setStyleSheet(QString::fromUtf8("/* Dialog Styling */\n"
"QDialog {\n"
"    background-color: #f8f9fa;\n"
"    color: #212529;\n"
"}\n"
"\n"
"/* Group Box Styling */\n"
"QGroupBox {\n"
"    font-weight: bold;\n"
"    font-size: 14px;\n"
"    color: #495057;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 10px;\n"
"    margin-top: 1.5ex;\n"
"    padding-top: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 15px;\n"
"    padding: 0 10px 0 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"/* Form Labels */\n"
"QLabel {\n"
"    color: #495057;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"/* Input Fields Styling */\n"
"QDateEdit, QComboBox, QDoubleSpinBox, QLineEdit, QSpinBox, QTextEdit, QPlainTextEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 8px;\n"
"    padding: 10px 15px;\n"
"    font-size: 12px;\n"
"    min-height: 18px;\n"
"}\n"
"\n"
"QDateEdit:focus, QComboBox:focus, QDoubleSpinBox:f"
                        "ocus, QLineEdit:focus, QSpinBox:focus, QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border-color: #007bff;\n"
"    background-color: #f0f8ff;\n"
"}\n"
"\n"
"QDateEdit:hover, QComboBox:hover, QDoubleSpinBox:hover, QLineEdit:hover, QSpinBox:hover, QTextEdit:hover, QPlainTextEdit:hover {\n"
"    border-color: #6c757d;\n"
"}\n"
"\n"
"/* SpinBox and DoubleSpinBox */\n"
"QSpinBox, QDoubleSpinBox {\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #ced4da;\n"
"    border-top-right-radius: 8px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #ced4da;\n"
"    border-bottom-right-radius: 8px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"QSpinBox::up-arrow, QDoubleSpin"
                        "Box::up-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"    background-color: #6c757d;\n"
"}\n"
"\n"
"QSpinBox::down-arrow, QDoubleSpinBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"    background-color: #6c757d;\n"
"}\n"
"\n"
"/* ComboBox Arrow */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #ced4da;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 15px;\n"
"    height: 15px;\n"
"    background-color: #6c757d;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 8px;\n"
"    selection-background-color: #007bff;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"/* Text Edit for Description */\n"
"QTextEdit, QPlainTextEdit {\n"
"    min-height: 80px;\n"
"}\n"
"\n"
"/* Button Styling "
                        "*/\n"
"QPushButton {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 12px 25px;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"    min-width: 100px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #004085;\n"
"}\n"
"\n"
"#buttonSave {\n"
"    background-color: #28a745;\n"
"}\n"
"\n"
"#buttonSave:hover {\n"
"    background-color: #1e7e34;\n"
"}\n"
"\n"
"#buttonCancel {\n"
"    background-color: #dc3545;\n"
"}\n"
"\n"
"#buttonCancel:hover {\n"
"    background-color: #c82333;\n"
"}\n"
"\n"
"/* Required field indicators */\n"
"QLabel[required=\"true\"] {\n"
"    color: #dc3545;\n"
"}\n"
"\n"
"QLabel[required=\"true\"]:after {\n"
"    content: \" *\";\n"
"    color: #dc3545;\n"
"}\n"
""));
        AddRoomDialog->setModal(true);
        verticalLayout = new QVBoxLayout(AddRoomDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        groupBoxRoomInfo = new QGroupBox(AddRoomDialog);
        groupBoxRoomInfo->setObjectName(QString::fromUtf8("groupBoxRoomInfo"));
        formLayout = new QFormLayout(groupBoxRoomInfo);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(15, 15, 15, 15);
        labelRoomNumber = new QLabel(groupBoxRoomInfo);
        labelRoomNumber->setObjectName(QString::fromUtf8("labelRoomNumber"));
        labelRoomNumber->setProperty("required", QVariant(true));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelRoomNumber);

        lineEditRoomNumber = new QLineEdit(groupBoxRoomInfo);
        lineEditRoomNumber->setObjectName(QString::fromUtf8("lineEditRoomNumber"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditRoomNumber);

        labelRoomType = new QLabel(groupBoxRoomInfo);
        labelRoomType->setObjectName(QString::fromUtf8("labelRoomType"));
        labelRoomType->setProperty("required", QVariant(true));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelRoomType);

        comboBoxRoomType = new QComboBox(groupBoxRoomInfo);
        comboBoxRoomType->addItem(QString());
        comboBoxRoomType->addItem(QString());
        comboBoxRoomType->addItem(QString());
        comboBoxRoomType->setObjectName(QString::fromUtf8("comboBoxRoomType"));
        comboBoxRoomType->setEditable(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxRoomType);

        doubleSpinBoxRentPrice = new QDoubleSpinBox(groupBoxRoomInfo);
        doubleSpinBoxRentPrice->setObjectName(QString::fromUtf8("doubleSpinBoxRentPrice"));
        doubleSpinBoxRentPrice->setDecimals(0);
        doubleSpinBoxRentPrice->setMinimum(100000.000000000000000);
        doubleSpinBoxRentPrice->setMaximum(50000000.000000000000000);
        doubleSpinBoxRentPrice->setSingleStep(50000.000000000000000);
        doubleSpinBoxRentPrice->setValue(1000000.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBoxRentPrice);

        labelRentPrice = new QLabel(groupBoxRoomInfo);
        labelRentPrice->setObjectName(QString::fromUtf8("labelRentPrice"));
        labelRentPrice->setProperty("required", QVariant(true));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRentPrice);


        verticalLayout->addWidget(groupBoxRoomInfo);

        groupBoxStatus = new QGroupBox(AddRoomDialog);
        groupBoxStatus->setObjectName(QString::fromUtf8("groupBoxStatus"));
        verticalLayout_2 = new QVBoxLayout(groupBoxStatus);
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setHorizontalSpacing(15);
        formLayout_3->setVerticalSpacing(12);
        labelStatus = new QLabel(groupBoxStatus);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, labelStatus);

        comboBoxStatus = new QComboBox(groupBoxStatus);
        comboBoxStatus->addItem(QString());
        comboBoxStatus->setObjectName(QString::fromUtf8("comboBoxStatus"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, comboBoxStatus);


        verticalLayout_2->addLayout(formLayout_3);

        labelDescription = new QLabel(groupBoxStatus);
        labelDescription->setObjectName(QString::fromUtf8("labelDescription"));

        verticalLayout_2->addWidget(labelDescription);

        plainTextEditDescription = new QPlainTextEdit(groupBoxStatus);
        plainTextEditDescription->setObjectName(QString::fromUtf8("plainTextEditDescription"));

        verticalLayout_2->addWidget(plainTextEditDescription);


        verticalLayout->addWidget(groupBoxStatus);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AddRoomDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(lineEditRoomNumber, comboBoxRoomType);
        QWidget::setTabOrder(comboBoxRoomType, comboBoxStatus);
        QWidget::setTabOrder(comboBoxStatus, plainTextEditDescription);

        retranslateUi(AddRoomDialog);

        QMetaObject::connectSlotsByName(AddRoomDialog);
    } // setupUi

    void retranslateUi(QDialog *AddRoomDialog)
    {
        AddRoomDialog->setWindowTitle(QCoreApplication::translate("AddRoomDialog", "Th\303\252m Ph\303\262ng M\341\273\233i", nullptr));
        groupBoxRoomInfo->setTitle(QCoreApplication::translate("AddRoomDialog", "Th\303\264ng Tin C\306\241 B\341\272\243n", nullptr));
        labelRoomNumber->setText(QCoreApplication::translate("AddRoomDialog", "S\341\273\221 Ph\303\262ng:", nullptr));
        lineEditRoomNumber->setPlaceholderText(QCoreApplication::translate("AddRoomDialog", "V\303\255 d\341\273\245: P101, A201", nullptr));
        labelRoomType->setText(QCoreApplication::translate("AddRoomDialog", "Lo\341\272\241i Ph\303\262ng:", nullptr));
        comboBoxRoomType->setItemText(0, QCoreApplication::translate("AddRoomDialog", "Ph\303\262ng \304\221\306\241n", nullptr));
        comboBoxRoomType->setItemText(1, QCoreApplication::translate("AddRoomDialog", "Ph\303\262ng \304\221\303\264i", nullptr));
        comboBoxRoomType->setItemText(2, QCoreApplication::translate("AddRoomDialog", "Ph\303\262ng gia \304\221\303\254nh", nullptr));

        doubleSpinBoxRentPrice->setSuffix(QCoreApplication::translate("AddRoomDialog", " VN\304\220", nullptr));
        labelRentPrice->setText(QCoreApplication::translate("AddRoomDialog", "Gi\303\241 Thu\303\252:", nullptr));
        groupBoxStatus->setTitle(QCoreApplication::translate("AddRoomDialog", "Tr\341\272\241ng Th\303\241i - M\303\264 T\341\272\243", nullptr));
        labelStatus->setText(QCoreApplication::translate("AddRoomDialog", "Tr\341\272\241ng Th\303\241i:", nullptr));
        comboBoxStatus->setItemText(0, QCoreApplication::translate("AddRoomDialog", "Tr\341\273\221ng", nullptr));

        labelDescription->setText(QCoreApplication::translate("AddRoomDialog", "M\303\264 T\341\272\243:", nullptr));
        plainTextEditDescription->setPlaceholderText(QCoreApplication::translate("AddRoomDialog", "Nh\341\272\255p m\303\264 t\341\272\243 v\341\273\201 ph\303\262ng: n\341\273\231i th\341\272\245t, ti\341\273\207n nghi, ghi ch\303\272...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddRoomDialog: public Ui_AddRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_ROOM_DIALOG_H
