/********************************************************************************
** Form generated from reading UI file 'add_tenant_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_TENANT_DIALOG_H
#define ADD_TENANT_DIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTenantDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxPersonalInfo;
    QFormLayout *formLayout;
    QLabel *labelFullName;
    QLineEdit *lineEditFullName;
    QLabel *labelPhone;
    QLineEdit *lineEditPhone;
    QLabel *labelCCCD;
    QLineEdit *lineEditCCCD;
    QLabel *labelBirthDate;
    QDateEdit *dateEditBirthDate;
    QLabel *labelGender;
    QComboBox *comboBoxGender;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayoutButtons;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddTenantDialog)
    {
        if (AddTenantDialog->objectName().isEmpty())
            AddTenantDialog->setObjectName(QString::fromUtf8("AddTenantDialog"));
        AddTenantDialog->resize(450, 609);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/person-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddTenantDialog->setWindowIcon(icon);
        AddTenantDialog->setStyleSheet(QString::fromUtf8("/* Dialog Styling */\n"
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
"QDateEdit, QComboBox, QDoubleSpinBox, QLineEdit, QSpinBox {\n"
"    background-color: white;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 8px;\n"
"    padding: 10px 15px;\n"
"    font-size: 12px;\n"
"    min-height: 18px;\n"
"}\n"
"\n"
"QDateEdit:focus, QComboBox:focus, QDoubleSpinBox:focus, QLineEdit:focus, QSpi"
                        "nBox:focus {\n"
"    border-color: #007bff;\n"
"    background-color: #f0f8ff;\n"
"}\n"
"\n"
"QDateEdit:hover, QComboBox:hover, QDoubleSpinBox:hover, QLineEdit:hover, QSpinBox:hover {\n"
"    border-color: #6c757d;\n"
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
"/* Button Styling */\n"
"QPushButton {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
""
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
        AddTenantDialog->setModal(true);
        verticalLayout = new QVBoxLayout(AddTenantDialog);
        verticalLayout->setSpacing(15);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(20, 20, 20, 20);
        groupBoxPersonalInfo = new QGroupBox(AddTenantDialog);
        groupBoxPersonalInfo->setObjectName(QString::fromUtf8("groupBoxPersonalInfo"));
        formLayout = new QFormLayout(groupBoxPersonalInfo);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(15, 15, 15, 15);
        labelFullName = new QLabel(groupBoxPersonalInfo);
        labelFullName->setObjectName(QString::fromUtf8("labelFullName"));
        labelFullName->setProperty("required", QVariant(true));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelFullName);

        lineEditFullName = new QLineEdit(groupBoxPersonalInfo);
        lineEditFullName->setObjectName(QString::fromUtf8("lineEditFullName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditFullName);

        labelPhone = new QLabel(groupBoxPersonalInfo);
        labelPhone->setObjectName(QString::fromUtf8("labelPhone"));
        labelPhone->setProperty("required", QVariant(true));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPhone);

        lineEditPhone = new QLineEdit(groupBoxPersonalInfo);
        lineEditPhone->setObjectName(QString::fromUtf8("lineEditPhone"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPhone);

        labelCCCD = new QLabel(groupBoxPersonalInfo);
        labelCCCD->setObjectName(QString::fromUtf8("labelCCCD"));
        labelCCCD->setProperty("required", QVariant(true));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelCCCD);

        lineEditCCCD = new QLineEdit(groupBoxPersonalInfo);
        lineEditCCCD->setObjectName(QString::fromUtf8("lineEditCCCD"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditCCCD);

        labelBirthDate = new QLabel(groupBoxPersonalInfo);
        labelBirthDate->setObjectName(QString::fromUtf8("labelBirthDate"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelBirthDate);

        dateEditBirthDate = new QDateEdit(groupBoxPersonalInfo);
        dateEditBirthDate->setObjectName(QString::fromUtf8("dateEditBirthDate"));
        dateEditBirthDate->setMaximumDate(QDate(2010, 12, 31));
        dateEditBirthDate->setMinimumDate(QDate(1950, 1, 1));
        dateEditBirthDate->setCalendarPopup(true);
        dateEditBirthDate->setDate(QDate(1990, 1, 1));

        formLayout->setWidget(3, QFormLayout::FieldRole, dateEditBirthDate);

        labelGender = new QLabel(groupBoxPersonalInfo);
        labelGender->setObjectName(QString::fromUtf8("labelGender"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelGender);

        comboBoxGender = new QComboBox(groupBoxPersonalInfo);
        comboBoxGender->addItem(QString());
        comboBoxGender->addItem(QString());
        comboBoxGender->addItem(QString());
        comboBoxGender->setObjectName(QString::fromUtf8("comboBoxGender"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxGender);


        verticalLayout->addWidget(groupBoxPersonalInfo);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setSpacing(15);
        horizontalLayoutButtons->setObjectName(QString::fromUtf8("horizontalLayoutButtons"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutButtons->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(AddTenantDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        horizontalLayoutButtons->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayoutButtons);

        QWidget::setTabOrder(lineEditFullName, lineEditPhone);
        QWidget::setTabOrder(lineEditPhone, lineEditCCCD);
        QWidget::setTabOrder(lineEditCCCD, dateEditBirthDate);
        QWidget::setTabOrder(dateEditBirthDate, comboBoxGender);

        retranslateUi(AddTenantDialog);

        QMetaObject::connectSlotsByName(AddTenantDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTenantDialog)
    {
        AddTenantDialog->setWindowTitle(QCoreApplication::translate("AddTenantDialog", "Th\303\252m Kh\303\241ch Thu\303\252 M\341\273\233i", nullptr));
        groupBoxPersonalInfo->setTitle(QCoreApplication::translate("AddTenantDialog", "Th\303\264ng Tin C\303\241 Nh\303\242n", nullptr));
        labelFullName->setText(QCoreApplication::translate("AddTenantDialog", "H\341\273\215 v\303\240 T\303\252n:", nullptr));
        lineEditFullName->setPlaceholderText(QCoreApplication::translate("AddTenantDialog", "Nh\341\272\255p h\341\273\215 v\303\240 t\303\252n \304\221\341\272\247y \304\221\341\273\247", nullptr));
        labelPhone->setText(QCoreApplication::translate("AddTenantDialog", "S\341\273\221 \304\220i\341\273\207n Tho\341\272\241i:", nullptr));
        lineEditPhone->setInputMask(QCoreApplication::translate("AddTenantDialog", "0000000000;_", nullptr));
        lineEditPhone->setPlaceholderText(QCoreApplication::translate("AddTenantDialog", "V\303\255 d\341\273\245: 0123456789", nullptr));
        labelCCCD->setText(QCoreApplication::translate("AddTenantDialog", "CCCD/CMND:", nullptr));
        lineEditCCCD->setInputMask(QCoreApplication::translate("AddTenantDialog", "000000000000;_", nullptr));
        lineEditCCCD->setPlaceholderText(QCoreApplication::translate("AddTenantDialog", "Nh\341\272\255p s\341\273\221 CCCD/CMND", nullptr));
        labelBirthDate->setText(QCoreApplication::translate("AddTenantDialog", "Ng\303\240y Sinh:", nullptr));
        dateEditBirthDate->setDisplayFormat(QCoreApplication::translate("AddTenantDialog", "dd/MM/yyyy", nullptr));
        labelGender->setText(QCoreApplication::translate("AddTenantDialog", "Gi\341\273\233i T\303\255nh:", nullptr));
        comboBoxGender->setItemText(0, QCoreApplication::translate("AddTenantDialog", "Nam", nullptr));
        comboBoxGender->setItemText(1, QCoreApplication::translate("AddTenantDialog", "N\341\273\257", nullptr));
        comboBoxGender->setItemText(2, QCoreApplication::translate("AddTenantDialog", "Kh\303\241c", nullptr));

    } // retranslateUi

};

namespace Ui {
    class AddTenantDialog: public Ui_AddTenantDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_TENANT_DIALOG_H
