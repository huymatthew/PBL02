/********************************************************************************
** Form generated from reading UI file 'add_bill.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADD_BILL_DIALOG_H
#define ADD_BILL_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBillDialog
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
    QLabel *contractLabel;
    QLabel *contractID;
    QLabel *resLabel;
    QLabel *resName;
    QLabel *startDateLabel;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *monthLabel;
    QComboBox *monthComboBox;
    QLabel *yearLabel;
    QLineEdit *yearEdit;
    QLabel *roomBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addService;
    QPushButton *removeService;
    QListWidget *service;
    QGroupBox *financialInfoGroup;
    QFormLayout *financialInfoLayout;
    QLabel *monthlyRentLabel;
    QLabel *sumLabel;
    QSpinBox *sumSpinBox;
    QDoubleSpinBox *monthlyRentSpinBox;
    QGroupBox *statusNotesGroup;
    QFormLayout *statusNotesLayout;
    QLabel *statusLabel;
    QComboBox *statusComboBox;
    QSpacerItem *verticalSpacer;
    QFrame *buttonFrame;
    QHBoxLayout *buttonLayout;
    QSpacerItem *buttonSpacer;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *AddBillDialog)
    {
        if (AddBillDialog->objectName().isEmpty())
            AddBillDialog->setObjectName(QString::fromUtf8("AddBillDialog"));
        AddBillDialog->resize(700, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/contract.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddBillDialog->setWindowIcon(icon);
        AddBillDialog->setStyleSheet(QString::fromUtf8("/* Add Contract Dialog Styling */\n"
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
        mainVerticalLayout = new QVBoxLayout(AddBillDialog);
        mainVerticalLayout->setSpacing(15);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainVerticalLayout->setContentsMargins(20, 20, 20, 20);
        titleLabel = new QLabel(AddBillDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setStyleSheet(QString::fromUtf8("color: #007bff; padding: 10px;"));
        titleLabel->setAlignment(Qt::AlignCenter);

        mainVerticalLayout->addWidget(titleLabel);

        scrollArea = new QScrollArea(AddBillDialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea { border: none; background-color: transparent; }"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 646, 893));
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

        contractLabel = new QLabel(contractInfoGroup);
        contractLabel->setObjectName(QString::fromUtf8("contractLabel"));

        contractInfoLayout->setWidget(1, QFormLayout::LabelRole, contractLabel);

        contractID = new QLabel(contractInfoGroup);
        contractID->setObjectName(QString::fromUtf8("contractID"));

        contractInfoLayout->setWidget(1, QFormLayout::FieldRole, contractID);

        resLabel = new QLabel(contractInfoGroup);
        resLabel->setObjectName(QString::fromUtf8("resLabel"));

        contractInfoLayout->setWidget(2, QFormLayout::LabelRole, resLabel);

        resName = new QLabel(contractInfoGroup);
        resName->setObjectName(QString::fromUtf8("resName"));

        contractInfoLayout->setWidget(2, QFormLayout::FieldRole, resName);

        startDateLabel = new QLabel(contractInfoGroup);
        startDateLabel->setObjectName(QString::fromUtf8("startDateLabel"));

        contractInfoLayout->setWidget(3, QFormLayout::LabelRole, startDateLabel);

        frame = new QFrame(contractInfoGroup);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        monthLabel = new QLabel(frame);
        monthLabel->setObjectName(QString::fromUtf8("monthLabel"));

        horizontalLayout_2->addWidget(monthLabel);

        monthComboBox = new QComboBox(frame);
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->addItem(QString());
        monthComboBox->setObjectName(QString::fromUtf8("monthComboBox"));

        horizontalLayout_2->addWidget(monthComboBox);

        yearLabel = new QLabel(frame);
        yearLabel->setObjectName(QString::fromUtf8("yearLabel"));

        horizontalLayout_2->addWidget(yearLabel);

        yearEdit = new QLineEdit(frame);
        yearEdit->setObjectName(QString::fromUtf8("yearEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(yearEdit->sizePolicy().hasHeightForWidth());
        yearEdit->setSizePolicy(sizePolicy);
        yearEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(yearEdit);


        contractInfoLayout->setWidget(3, QFormLayout::FieldRole, frame);

        roomBox = new QLabel(contractInfoGroup);
        roomBox->setObjectName(QString::fromUtf8("roomBox"));

        contractInfoLayout->setWidget(0, QFormLayout::FieldRole, roomBox);


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

        addService = new QPushButton(widget);
        addService->setObjectName(QString::fromUtf8("addService"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addService->sizePolicy().hasHeightForWidth());
        addService->setSizePolicy(sizePolicy1);
        addService->setMinimumSize(QSize(150, 32));
        addService->setIconSize(QSize(0, 0));
        addService->setCheckable(false);

        horizontalLayout->addWidget(addService);

        removeService = new QPushButton(widget);
        removeService->setObjectName(QString::fromUtf8("removeService"));
        removeService->setMinimumSize(QSize(150, 0));
        removeService->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: red;\n"
"}\n"
"QPushButton::hover{\n"
"background-color: rgb(192, 28, 40);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: rgb(165, 29, 45);\n"
"}"));

        horizontalLayout->addWidget(removeService);


        verticalLayout->addWidget(widget);

        service = new QListWidget(groupBox);
        service->setObjectName(QString::fromUtf8("service"));
        service->setMinimumSize(QSize(0, 200));
        service->setToolTipDuration(-3);
        service->setStyleSheet(QString::fromUtf8("QWidget{border: 1px solid black}"));

        verticalLayout->addWidget(service);


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

        sumLabel = new QLabel(financialInfoGroup);
        sumLabel->setObjectName(QString::fromUtf8("sumLabel"));

        financialInfoLayout->setWidget(1, QFormLayout::LabelRole, sumLabel);

        sumSpinBox = new QSpinBox(financialInfoGroup);
        sumSpinBox->setObjectName(QString::fromUtf8("sumSpinBox"));
        sumSpinBox->setEnabled(false);
        sumSpinBox->setStyleSheet(QString::fromUtf8("color: black"));
        sumSpinBox->setProperty("showGroupSeparator", QVariant(false));
        sumSpinBox->setMaximum(999999999);
        sumSpinBox->setSingleStep(10000);
        sumSpinBox->setDisplayIntegerBase(10);

        financialInfoLayout->setWidget(1, QFormLayout::FieldRole, sumSpinBox);

        monthlyRentSpinBox = new QDoubleSpinBox(financialInfoGroup);
        monthlyRentSpinBox->setObjectName(QString::fromUtf8("monthlyRentSpinBox"));
        monthlyRentSpinBox->setDecimals(0);
        monthlyRentSpinBox->setMinimum(0.000000000000000);
        monthlyRentSpinBox->setMaximum(999999999.000000000000000);
        monthlyRentSpinBox->setSingleStep(100000.000000000000000);
        monthlyRentSpinBox->setValue(0.000000000000000);

        financialInfoLayout->setWidget(0, QFormLayout::FieldRole, monthlyRentSpinBox);


        scrollLayout->addWidget(financialInfoGroup);

        statusNotesGroup = new QGroupBox(scrollAreaWidgetContents);
        statusNotesGroup->setObjectName(QString::fromUtf8("statusNotesGroup"));
        statusNotesLayout = new QFormLayout(statusNotesGroup);
        statusNotesLayout->setObjectName(QString::fromUtf8("statusNotesLayout"));
        statusNotesLayout->setHorizontalSpacing(15);
        statusNotesLayout->setVerticalSpacing(15);
        statusNotesLayout->setContentsMargins(20, 25, 20, 20);
        statusLabel = new QLabel(statusNotesGroup);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));

        statusNotesLayout->setWidget(0, QFormLayout::LabelRole, statusLabel);

        statusComboBox = new QComboBox(statusNotesGroup);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName(QString::fromUtf8("statusComboBox"));
        statusComboBox->setStyleSheet(QString::fromUtf8("QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left: 1px solid #ced4da;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"    background-color: #f8f9fa;\n"
"	color: #212529;\n"
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
"    selection-color: black;\n"
"}"));

        statusNotesLayout->setWidget(0, QFormLayout::FieldRole, statusComboBox);


        scrollLayout->addWidget(statusNotesGroup);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        scrollLayout->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        mainVerticalLayout->addWidget(scrollArea);

        buttonFrame = new QFrame(AddBillDialog);
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

        QWidget::setTabOrder(scrollArea, service);
        QWidget::setTabOrder(service, monthlyRentSpinBox);
        QWidget::setTabOrder(monthlyRentSpinBox, sumSpinBox);
        QWidget::setTabOrder(sumSpinBox, statusComboBox);
        QWidget::setTabOrder(statusComboBox, cancelButton);
        QWidget::setTabOrder(cancelButton, saveButton);

        retranslateUi(AddBillDialog);

        saveButton->setDefault(true);


        QMetaObject::connectSlotsByName(AddBillDialog);
    } // setupUi

    void retranslateUi(QDialog *AddBillDialog)
    {
        AddBillDialog->setWindowTitle(QCoreApplication::translate("AddBillDialog", "Th\303\252m H\303\263a \304\220\306\241n", nullptr));
        titleLabel->setText(QCoreApplication::translate("AddBillDialog", "TH\303\212M H\303\223A \304\220\306\240N", nullptr));
        contractInfoGroup->setTitle(QCoreApplication::translate("AddBillDialog", "Th\303\264ng Tin H\303\263a \304\220\306\241n", nullptr));
        roomIdLabel->setText(QCoreApplication::translate("AddBillDialog", "M\303\243 Ph\303\262ng:", nullptr));
        contractLabel->setText(QCoreApplication::translate("AddBillDialog", "M\303\243 H\341\273\243p \304\220\341\273\223ng", nullptr));
        contractID->setText(QCoreApplication::translate("AddBillDialog", ".", nullptr));
        resLabel->setText(QCoreApplication::translate("AddBillDialog", "T\303\252n \304\220\341\272\241i Di\341\273\207n", nullptr));
        resName->setText(QCoreApplication::translate("AddBillDialog", ".", nullptr));
        startDateLabel->setText(QCoreApplication::translate("AddBillDialog", "Th\303\241ng Thanh To\303\241n", nullptr));
        monthLabel->setText(QCoreApplication::translate("AddBillDialog", "Th\303\241ng", nullptr));
        monthComboBox->setItemText(0, QCoreApplication::translate("AddBillDialog", "1", nullptr));
        monthComboBox->setItemText(1, QCoreApplication::translate("AddBillDialog", "2", nullptr));
        monthComboBox->setItemText(2, QCoreApplication::translate("AddBillDialog", "3", nullptr));
        monthComboBox->setItemText(3, QCoreApplication::translate("AddBillDialog", "4", nullptr));
        monthComboBox->setItemText(4, QCoreApplication::translate("AddBillDialog", "5", nullptr));
        monthComboBox->setItemText(5, QCoreApplication::translate("AddBillDialog", "6", nullptr));
        monthComboBox->setItemText(6, QCoreApplication::translate("AddBillDialog", "7", nullptr));
        monthComboBox->setItemText(7, QCoreApplication::translate("AddBillDialog", "8", nullptr));
        monthComboBox->setItemText(8, QCoreApplication::translate("AddBillDialog", "9", nullptr));
        monthComboBox->setItemText(9, QCoreApplication::translate("AddBillDialog", "10", nullptr));
        monthComboBox->setItemText(10, QCoreApplication::translate("AddBillDialog", "11", nullptr));
        monthComboBox->setItemText(11, QCoreApplication::translate("AddBillDialog", "12", nullptr));

        yearLabel->setText(QCoreApplication::translate("AddBillDialog", "N\304\203m", nullptr));
        roomBox->setText(QCoreApplication::translate("AddBillDialog", ".", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddBillDialog", "Danh s\303\241ch d\341\273\213ch v\341\273\245", nullptr));
        addService->setText(QCoreApplication::translate("AddBillDialog", "+", nullptr));
        removeService->setText(QCoreApplication::translate("AddBillDialog", "-", nullptr));
        financialInfoGroup->setTitle(QCoreApplication::translate("AddBillDialog", "Th\303\264ng Tin T\303\240i Ch\303\255nh", nullptr));
        monthlyRentLabel->setText(QCoreApplication::translate("AddBillDialog", "Ti\341\273\201n Ph\303\262ng", nullptr));
        sumLabel->setText(QCoreApplication::translate("AddBillDialog", "T\341\273\225ng Ti\341\273\201n", nullptr));
        sumSpinBox->setSuffix(QCoreApplication::translate("AddBillDialog", " VND", nullptr));
        sumSpinBox->setPrefix(QString());
        monthlyRentSpinBox->setSuffix(QCoreApplication::translate("AddBillDialog", " VN\304\220", nullptr));
        statusNotesGroup->setTitle(QCoreApplication::translate("AddBillDialog", "Tr\341\272\241ng Th\303\241i v\303\240 Ghi Ch\303\272", nullptr));
        statusLabel->setText(QCoreApplication::translate("AddBillDialog", "Tr\341\272\241ng Th\303\241i:", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("AddBillDialog", "Ho\341\272\241t \304\220\341\273\231ng", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("AddBillDialog", "Ng\341\273\253ng Ho\341\272\241t \304\220\341\273\231ng", nullptr));

        cancelButton->setText(QCoreApplication::translate("AddBillDialog", "H\341\273\247y", nullptr));
        saveButton->setText(QCoreApplication::translate("AddBillDialog", "T\341\272\241o H\303\263a \304\220\306\241n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBillDialog: public Ui_AddBillDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADD_BILL_DIALOG_H
