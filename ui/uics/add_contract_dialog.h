/********************************************************************************
** Form generated from reading UI file 'add_contract.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_CONTRACT_DIALOG_H
#define ADD_CONTRACT_DIALOG_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddContractDialog
{
public:
    QVBoxLayout *mainVerticalLayout;
    QLabel *titleLabel;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *scrollLayout;
    QGroupBox *contractInfoGroup;
    QFormLayout *contractInfoLayout;
    QLabel *roomIdLabel;
    QComboBox *roomIdComboBox;
    QLabel *startDateLabel;
    QDateEdit *startDateEdit;
    QLabel *endDateLabel;
    QDateEdit *endDateEdit;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addTenant;
    QPushButton *removeTenant;
    QListWidget *tenantList;
    QGroupBox *financialInfoGroup;
    QFormLayout *financialInfoLayout;
    QLabel *monthlyRentLabel;
    QDoubleSpinBox *monthlyRentSpinBox;
    QLabel *depositLabel;
    QDoubleSpinBox *depositSpinBox;
    QGroupBox *statusNotesGroup;
    QFormLayout *statusNotesLayout;
    QLabel *notesLabel;
    QTextEdit *description;
    QSpacerItem *verticalSpacer;
    QFrame *buttonFrame;
    QHBoxLayout *buttonLayout;
    QSpacerItem *buttonSpacer;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *AddContractDialog)
    {
        if (AddContractDialog->objectName().isEmpty())
            AddContractDialog->setObjectName(QString::fromUtf8("AddContractDialog"));
        AddContractDialog->resize(700, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/contract.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddContractDialog->setWindowIcon(icon);
        AddContractDialog->setStyleSheet(QString::fromUtf8("/* Add Contract Dialog Styling */\n"
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
"QDateEdit:focus, QComboBox:focus, QDo"
                        "ubleSpinBox:focus, QLineEdit:focus, QSpinBox:focus, QTextEdit:focus, QPlainTextEdit:focus {\n"
"    border-color: #007bff;\n"
"    background-color: #f0f8ff;\n"
"}\n"
"\n"
"QDateEdit:hover, QComboBox:hover, QDoubleSpinBox:hover, QLineEdit:hover, QSpinBox:hover, QTextEdit:hover, QPlainTextEdit:hover {\n"
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
"QPu"
                        "shButton {\n"
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
"#saveButton {\n"
"    background-color: #28a745;\n"
"}\n"
"\n"
"#saveButton:hover {\n"
"    background-color: #1e7e34;\n"
"}\n"
"\n"
"#cancelButton {\n"
"    background-color: #6c757d;\n"
"}\n"
"\n"
"#cancelButton:hover {\n"
"    background-color: #545b62;\n"
"}\n"
"\n"
"#clearButton {\n"
"    background-color: #ffc107;\n"
"    color: #212529;\n"
"}\n"
"\n"
"#clearButton:hover {\n"
"    background-color: #e0a800;\n"
"}\n"
"\n"
"/* SpinBox Styling */\n"
"QSpinBox, QDoubleSpinBox {\n"
"    padding-right: 30px;\n"
"}\n"
"\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: to"
                        "p right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #ced4da;\n"
"    border-bottom: 1px solid #ced4da;\n"
"    border-top-right-radius: 8px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: bottom right;\n"
"    width: 20px;\n"
"    border-left: 1px solid #ced4da;\n"
"    border-bottom-right-radius: 8px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
"\n"
"QSpinBox::up-arrow, QDoubleSpinBox::up-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    background-color: #6c757d;\n"
"}\n"
"\n"
"QSpinBox::down-arrow, QDoubleSpinBox::down-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    background-color: #6c757d;\n"
"}\n"
"\n"
"/* Date Edit Calendar Button */\n"
"QDateEdit::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #ced4da;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-ri"
                        "ght-radius: 8px;\n"
"    background-color: #f8f9fa;\n"
"}\n"
""));
        mainVerticalLayout = new QVBoxLayout(AddContractDialog);
        mainVerticalLayout->setSpacing(15);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(20, 20, 20, 20);
        titleLabel = new QLabel(AddContractDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color: #007bff; padding: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        mainVerticalLayout->addWidget(titleLabel);

        scrollArea = new QScrollArea(AddContractDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea { border: none; background-color: transparent; }"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -258, 646, 892));
        scrollLayout = new QVBoxLayout(scrollAreaWidgetContents);
        scrollLayout->setSpacing(15);
        scrollLayout->setObjectName(QString::fromUtf8("scrollLayout"));
        contractInfoGroup = new QGroupBox(scrollAreaWidgetContents);
        contractInfoGroup->setObjectName(QString::fromUtf8("contractInfoGroup"));
        contractInfoLayout = new QFormLayout(contractInfoGroup);
        contractInfoLayout->setObjectName(QString::fromUtf8("contractInfoLayout"));
        contractInfoLayout->setHorizontalSpacing(15);
        contractInfoLayout->setVerticalSpacing(15);
        contractInfoLayout->setContentsMargins(20, 25, 20, 20);
        roomIdLabel = new QLabel(contractInfoGroup);
        roomIdLabel->setObjectName(QString::fromUtf8("roomIdLabel"));

        contractInfoLayout->setWidget(0, QFormLayout::LabelRole, roomIdLabel);

        roomIdComboBox = new QComboBox(contractInfoGroup);
        roomIdComboBox->setObjectName(QString::fromUtf8("roomIdComboBox"));
        roomIdComboBox->setEditable(true);

        contractInfoLayout->setWidget(0, QFormLayout::FieldRole, roomIdComboBox);

        startDateLabel = new QLabel(contractInfoGroup);
        startDateLabel->setObjectName(QString::fromUtf8("startDateLabel"));

        contractInfoLayout->setWidget(1, QFormLayout::LabelRole, startDateLabel);

        startDateEdit = new QDateEdit(contractInfoGroup);
        startDateEdit->setObjectName(QString::fromUtf8("startDateEdit"));
        startDateEdit->setCalendarPopup(true);
        startDateEdit->setDate(QDate(2025, 9, 13));

        contractInfoLayout->setWidget(1, QFormLayout::FieldRole, startDateEdit);

        endDateLabel = new QLabel(contractInfoGroup);
        endDateLabel->setObjectName(QString::fromUtf8("endDateLabel"));

        contractInfoLayout->setWidget(2, QFormLayout::LabelRole, endDateLabel);

        endDateEdit = new QDateEdit(contractInfoGroup);
        endDateEdit->setObjectName(QString::fromUtf8("endDateEdit"));
        endDateEdit->setCalendarPopup(true);
        endDateEdit->setDate(QDate(2026, 9, 13));

        contractInfoLayout->setWidget(2, QFormLayout::FieldRole, endDateEdit);


        scrollLayout->addWidget(contractInfoGroup);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget{border: none}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(486, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addTenant = new QPushButton(widget);
        addTenant->setObjectName(QString::fromUtf8("addTenant"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addTenant->sizePolicy().hasHeightForWidth());
        addTenant->setSizePolicy(sizePolicy);
        addTenant->setMinimumSize(QSize(150, 32));
        addTenant->setIconSize(QSize(0, 0));
        addTenant->setCheckable(false);

        horizontalLayout->addWidget(addTenant);

        removeTenant = new QPushButton(widget);
        removeTenant->setObjectName(QString::fromUtf8("removeTenant"));
        removeTenant->setMinimumSize(QSize(150, 0));
        removeTenant->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: red;\n"
"}\n"
"QPushButton::hover{\n"
"background-color: rgb(192, 28, 40);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: rgb(165, 29, 45);\n"
"}"));

        horizontalLayout->addWidget(removeTenant);


        verticalLayout->addWidget(widget);

        tenantList = new QListWidget(groupBox);
        tenantList->setObjectName(QString::fromUtf8("tenantList"));
        tenantList->setMinimumSize(QSize(0, 200));
        tenantList->setToolTipDuration(-3);
        tenantList->setStyleSheet(QString::fromUtf8("QWidget{border: 1px solid black}"));

        verticalLayout->addWidget(tenantList);


        scrollLayout->addWidget(groupBox);

        financialInfoGroup = new QGroupBox(scrollAreaWidgetContents);
        financialInfoGroup->setObjectName(QString::fromUtf8("financialInfoGroup"));
        financialInfoLayout = new QFormLayout(financialInfoGroup);
        financialInfoLayout->setObjectName(QString::fromUtf8("financialInfoLayout"));
        financialInfoLayout->setHorizontalSpacing(15);
        financialInfoLayout->setVerticalSpacing(15);
        financialInfoLayout->setContentsMargins(20, 25, 20, 20);
        monthlyRentLabel = new QLabel(financialInfoGroup);
        monthlyRentLabel->setObjectName(QString::fromUtf8("monthlyRentLabel"));

        financialInfoLayout->setWidget(0, QFormLayout::LabelRole, monthlyRentLabel);

        monthlyRentSpinBox = new QDoubleSpinBox(financialInfoGroup);
        monthlyRentSpinBox->setObjectName(QString::fromUtf8("monthlyRentSpinBox"));
        monthlyRentSpinBox->setDecimals(0);
        monthlyRentSpinBox->setMinimum(0.000000000000000);
        monthlyRentSpinBox->setMaximum(999999999.000000000000000);
        monthlyRentSpinBox->setSingleStep(100000.000000000000000);
        monthlyRentSpinBox->setValue(0.000000000000000);

        financialInfoLayout->setWidget(0, QFormLayout::FieldRole, monthlyRentSpinBox);

        depositLabel = new QLabel(financialInfoGroup);
        depositLabel->setObjectName(QString::fromUtf8("depositLabel"));

        financialInfoLayout->setWidget(1, QFormLayout::LabelRole, depositLabel);

        depositSpinBox = new QDoubleSpinBox(financialInfoGroup);
        depositSpinBox->setObjectName(QString::fromUtf8("depositSpinBox"));
        depositSpinBox->setDecimals(0);
        depositSpinBox->setMinimum(0.000000000000000);
        depositSpinBox->setMaximum(999999999.000000000000000);
        depositSpinBox->setSingleStep(100000.000000000000000);
        depositSpinBox->setValue(0.000000000000000);

        financialInfoLayout->setWidget(1, QFormLayout::FieldRole, depositSpinBox);


        scrollLayout->addWidget(financialInfoGroup);

        statusNotesGroup = new QGroupBox(scrollAreaWidgetContents);
        statusNotesGroup->setObjectName(QString::fromUtf8("statusNotesGroup"));
        statusNotesLayout = new QFormLayout(statusNotesGroup);
        statusNotesLayout->setObjectName(QString::fromUtf8("statusNotesLayout"));
        statusNotesLayout->setHorizontalSpacing(15);
        statusNotesLayout->setVerticalSpacing(15);
        statusNotesLayout->setContentsMargins(20, 25, 20, 20);
        notesLabel = new QLabel(statusNotesGroup);
        notesLabel->setObjectName(QString::fromUtf8("notesLabel"));

        statusNotesLayout->setWidget(0, QFormLayout::LabelRole, notesLabel);

        description = new QTextEdit(statusNotesGroup);
        description->setObjectName(QString::fromUtf8("description"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(description->sizePolicy().hasHeightForWidth());
        description->setSizePolicy(sizePolicy1);
        description->setMinimumSize(QSize(0, 42));

        statusNotesLayout->setWidget(0, QFormLayout::FieldRole, description);


        scrollLayout->addWidget(statusNotesGroup);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        scrollLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        mainVerticalLayout->addWidget(scrollArea);

        buttonFrame = new QFrame(AddContractDialog);
        buttonFrame->setObjectName(QString::fromUtf8("buttonFrame"));
        buttonFrame->setFrameShape(QFrame::NoFrame);
        buttonFrame->setFrameShadow(QFrame::Raised);
        buttonLayout = new QHBoxLayout(buttonFrame);
        buttonLayout->setSpacing(15);
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        buttonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        buttonLayout->addItem(buttonSpacer);

        cancelButton = new QPushButton(buttonFrame);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon1);

        buttonLayout->addWidget(cancelButton);

        saveButton = new QPushButton(buttonFrame);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon2);

        buttonLayout->addWidget(saveButton);


        mainVerticalLayout->addWidget(buttonFrame);

        QWidget::setTabOrder(scrollArea, roomIdComboBox);
        QWidget::setTabOrder(roomIdComboBox, startDateEdit);
        QWidget::setTabOrder(startDateEdit, endDateEdit);
        QWidget::setTabOrder(endDateEdit, tenantList);
        QWidget::setTabOrder(tenantList, monthlyRentSpinBox);
        QWidget::setTabOrder(monthlyRentSpinBox, depositSpinBox);
        QWidget::setTabOrder(depositSpinBox, cancelButton);
        QWidget::setTabOrder(cancelButton, saveButton);

        retranslateUi(AddContractDialog);

        saveButton->setDefault(true);


        QMetaObject::connectSlotsByName(AddContractDialog);
    } // setupUi

    void retranslateUi(QDialog *AddContractDialog)
    {
        AddContractDialog->setWindowTitle(QCoreApplication::translate("AddContractDialog", "Th\303\252m H\341\273\243p \304\220\341\273\223ng M\341\273\233i", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddContractDialog", "TH\303\212M H\341\273\242P \304\220\341\273\222NG M\341\273\232I", nullptr));
        contractInfoGroup->setTitle(QCoreApplication::translate("AddContractDialog", "Th\303\264ng Tin H\341\273\243p \304\220\341\273\223ng", nullptr));
        roomIdLabel->setText(QCoreApplication::translate("AddContractDialog", "M\303\243 Ph\303\262ng:", nullptr));
        startDateLabel->setText(QCoreApplication::translate("AddContractDialog", "Ng\303\240y B\341\272\257t \304\220\341\272\247u:", nullptr));
        endDateLabel->setText(QCoreApplication::translate("AddContractDialog", "Ng\303\240y K\341\272\277t Th\303\272c:", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddContractDialog", "Danh s\303\241ch ng\306\260\341\273\235i \341\273\237", nullptr));
        addTenant->setText(QCoreApplication::translate("AddContractDialog", "+", nullptr));
        removeTenant->setText(QCoreApplication::translate("AddContractDialog", "-", nullptr));
        financialInfoGroup->setTitle(QCoreApplication::translate("AddContractDialog", "Th\303\264ng Tin T\303\240i Ch\303\255nh", nullptr));
        monthlyRentLabel->setText(QCoreApplication::translate("AddContractDialog", "Ti\341\273\201n Thu\303\252 H\303\240ng Th\303\241ng (VN\304\220):", nullptr));
        monthlyRentSpinBox->setSuffix(QCoreApplication::translate("AddContractDialog", " VN\304\220", nullptr));
        depositLabel->setText(QCoreApplication::translate("AddContractDialog", "Ti\341\273\201n \304\220\341\272\267t C\341\273\215c (VN\304\220):", nullptr));
        depositSpinBox->setSuffix(QCoreApplication::translate("AddContractDialog", " VN\304\220", nullptr));
        statusNotesGroup->setTitle(QCoreApplication::translate("AddContractDialog", "Th\303\252m", nullptr));
        notesLabel->setText(QCoreApplication::translate("AddContractDialog", "Ghi Ch\303\272:", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddContractDialog", "H\341\273\247y", nullptr));
        saveButton->setText(QCoreApplication::translate("AddContractDialog", "L\306\260u H\341\273\243p \304\220\341\273\223ng", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddContractDialog: public Ui_AddContractDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_CONTRACT_DIALOG_H
