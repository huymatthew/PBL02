/********************************************************************************
** Form generated from reading UI file 'search_filter_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SEARCH_FILTER_DIALOG_H
#define SEARCH_FILTER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchFilterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *searchTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *searchGroupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *searchLabel;
    QLineEdit *searchLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *searchFieldLabel;
    QComboBox *searchFieldComboBox;
    QSpacerItem *horizontalSpacer;
    QCheckBox *caseSensitiveCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *filterTab;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *roomFilterView;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *roomFilterBox;
    QFormLayout *formLayout;
    QLabel *filterRoomTypeLabel;
    QComboBox *filterRoomType;
    QLabel *filterRoomStatusLabel;
    QComboBox *filterRoomStatus;
    QLabel *filterRoomPriceLabel;
    QFrame *filterRoomPrice;
    QFormLayout *formLayout_2;
    QLabel *filterRoomPriceFromLabel;
    QSpinBox *filterRoomPriceFrom;
    QLabel *filterRoomPriceToLabel;
    QSpinBox *filterRoomPriceTo;
    QCheckBox *billInMonth;
    QSpacerItem *verticalSpacer_4;
    QWidget *tenantFilterView;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *tenantFilterBox;
    QGridLayout *gridLayout;
    QComboBox *tenantFilterRole;
    QLabel *tenantFilterStatusLabel;
    QSpacerItem *verticalSpacer_2;
    QLabel *tenantFilterRoleLabel;
    QComboBox *tenantFilterStatus;
    QLabel *tenantFilterGenderLabel;
    QComboBox *tenantFilterGender;
    QWidget *contracFilterView;
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *contractFilterBox;
    QFormLayout *formLayout_10;
    QLabel *contractFilterStatusLabel;
    QComboBox *contractFilterStatus;
    QLabel *contractFilterRoomRentLabel;
    QFrame *contractFilterRoomRentBox;
    QFormLayout *formLayout_3;
    QLabel *contractFilterRoomRentFromLabel;
    QSpinBox *contractFilterRoomRentFrom;
    QLabel *contractFilterRoomRentToLabel;
    QSpinBox *contractFilterRoomRentTo;
    QLabel *label_13;
    QFrame *contractFilterDepositBox;
    QFormLayout *formLayout_5;
    QLabel *contractFilterDepositFromLabel;
    QSpinBox *contractFilterDepositFrom;
    QLabel *contractFilterDepositToLabel;
    QSpinBox *contractFilterDepositTo;
    QLabel *label_12;
    QFrame *contractFilterStartDate;
    QFormLayout *formLayout_4;
    QLabel *contractFilterStartDateToLabel;
    QLabel *contractFilterStartDateFromLabel;
    QDateEdit *contractFilterStartDateFrom;
    QDateEdit *contractFilterStartDateTo;
    QSpacerItem *verticalSpacer_3;
    QFrame *contractFilterEndDate;
    QFormLayout *formLayout_6;
    QLabel *contractFilterEndDateToLabel;
    QLabel *contractFilterEndDateFromLabel;
    QDateEdit *contractFilterEndDateFrom;
    QDateEdit *contractFilterEndDateTo;
    QLabel *label;
    QWidget *billFilterView;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *billFilterBox;
    QFormLayout *formLayout_7;
    QLabel *billFilterStatusLabel;
    QComboBox *billFilterStatus;
    QLabel *label_19;
    QFrame *billFilterPriceBox;
    QFormLayout *formLayout_9;
    QLabel *billFilterPriceFromLabel;
    QSpinBox *billFilterPriceFrom;
    QLabel *billFilterPriceToLabel;
    QSpinBox *billFilterPriceTo;
    QLabel *label_16;
    QFrame *billFilterMonth;
    QFormLayout *formLayout_8;
    QLabel *billFilterMonthFromLabel;
    QDateEdit *billFilterMonthFrom;
    QDateEdit *billFilterMonthTo;
    QLabel *billFilterMonthToLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SearchFilterDialog)
    {
        if (SearchFilterDialog->objectName().isEmpty())
            SearchFilterDialog->setObjectName(QString::fromUtf8("SearchFilterDialog"));
        SearchFilterDialog->resize(600, 656);
        verticalLayout = new QVBoxLayout(SearchFilterDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(SearchFilterDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        searchTab = new QWidget();
        searchTab->setObjectName(QString::fromUtf8("searchTab"));
        verticalLayout_2 = new QVBoxLayout(searchTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        searchGroupBox = new QGroupBox(searchTab);
        searchGroupBox->setObjectName(QString::fromUtf8("searchGroupBox"));
        verticalLayout_3 = new QVBoxLayout(searchGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchLabel = new QLabel(searchGroupBox);
        searchLabel->setObjectName(QString::fromUtf8("searchLabel"));

        horizontalLayout->addWidget(searchLabel);

        searchLineEdit = new QLineEdit(searchGroupBox);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        searchFieldLabel = new QLabel(searchGroupBox);
        searchFieldLabel->setObjectName(QString::fromUtf8("searchFieldLabel"));

        horizontalLayout_2->addWidget(searchFieldLabel);

        searchFieldComboBox = new QComboBox(searchGroupBox);
        searchFieldComboBox->setObjectName(QString::fromUtf8("searchFieldComboBox"));

        horizontalLayout_2->addWidget(searchFieldComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        caseSensitiveCheckBox = new QCheckBox(searchGroupBox);
        caseSensitiveCheckBox->setObjectName(QString::fromUtf8("caseSensitiveCheckBox"));

        verticalLayout_3->addWidget(caseSensitiveCheckBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_2->addWidget(searchGroupBox);

        tabWidget->addTab(searchTab, QString());
        filterTab = new QWidget();
        filterTab->setObjectName(QString::fromUtf8("filterTab"));
        verticalLayout_4 = new QVBoxLayout(filterTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        stackedWidget = new QStackedWidget(filterTab);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        roomFilterView = new QWidget();
        roomFilterView->setObjectName(QString::fromUtf8("roomFilterView"));
        horizontalLayout_5 = new QHBoxLayout(roomFilterView);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        roomFilterBox = new QGroupBox(roomFilterView);
        roomFilterBox->setObjectName(QString::fromUtf8("roomFilterBox"));
        formLayout = new QFormLayout(roomFilterBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        filterRoomTypeLabel = new QLabel(roomFilterBox);
        filterRoomTypeLabel->setObjectName(QString::fromUtf8("filterRoomTypeLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, filterRoomTypeLabel);

        filterRoomType = new QComboBox(roomFilterBox);
        filterRoomType->addItem(QString());
        filterRoomType->addItem(QString());
        filterRoomType->addItem(QString());
        filterRoomType->addItem(QString());
        filterRoomType->setObjectName(QString::fromUtf8("filterRoomType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, filterRoomType);

        filterRoomStatusLabel = new QLabel(roomFilterBox);
        filterRoomStatusLabel->setObjectName(QString::fromUtf8("filterRoomStatusLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, filterRoomStatusLabel);

        filterRoomStatus = new QComboBox(roomFilterBox);
        filterRoomStatus->addItem(QString());
        filterRoomStatus->addItem(QString());
        filterRoomStatus->addItem(QString());
        filterRoomStatus->setObjectName(QString::fromUtf8("filterRoomStatus"));

        formLayout->setWidget(1, QFormLayout::FieldRole, filterRoomStatus);

        filterRoomPriceLabel = new QLabel(roomFilterBox);
        filterRoomPriceLabel->setObjectName(QString::fromUtf8("filterRoomPriceLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, filterRoomPriceLabel);

        filterRoomPrice = new QFrame(roomFilterBox);
        filterRoomPrice->setObjectName(QString::fromUtf8("filterRoomPrice"));
        filterRoomPrice->setFrameShape(QFrame::StyledPanel);
        filterRoomPrice->setFrameShadow(QFrame::Plain);
        formLayout_2 = new QFormLayout(filterRoomPrice);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        filterRoomPriceFromLabel = new QLabel(filterRoomPrice);
        filterRoomPriceFromLabel->setObjectName(QString::fromUtf8("filterRoomPriceFromLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, filterRoomPriceFromLabel);

        filterRoomPriceFrom = new QSpinBox(filterRoomPrice);
        filterRoomPriceFrom->setObjectName(QString::fromUtf8("filterRoomPriceFrom"));
        filterRoomPriceFrom->setMaximum(999999999);
        filterRoomPriceFrom->setSingleStep(100000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, filterRoomPriceFrom);

        filterRoomPriceToLabel = new QLabel(filterRoomPrice);
        filterRoomPriceToLabel->setObjectName(QString::fromUtf8("filterRoomPriceToLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, filterRoomPriceToLabel);

        filterRoomPriceTo = new QSpinBox(filterRoomPrice);
        filterRoomPriceTo->setObjectName(QString::fromUtf8("filterRoomPriceTo"));
        filterRoomPriceTo->setMaximum(999999999);
        filterRoomPriceTo->setSingleStep(100000);
        filterRoomPriceTo->setValue(10000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, filterRoomPriceTo);


        formLayout->setWidget(2, QFormLayout::FieldRole, filterRoomPrice);

        billInMonth = new QCheckBox(roomFilterBox);
        billInMonth->setObjectName(QString::fromUtf8("billInMonth"));

        formLayout->setWidget(3, QFormLayout::FieldRole, billInMonth);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(4, QFormLayout::FieldRole, verticalSpacer_4);


        horizontalLayout_5->addWidget(roomFilterBox);

        stackedWidget->addWidget(roomFilterView);
        tenantFilterView = new QWidget();
        tenantFilterView->setObjectName(QString::fromUtf8("tenantFilterView"));
        horizontalLayout_4 = new QHBoxLayout(tenantFilterView);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tenantFilterBox = new QGroupBox(tenantFilterView);
        tenantFilterBox->setObjectName(QString::fromUtf8("tenantFilterBox"));
        gridLayout = new QGridLayout(tenantFilterBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tenantFilterRole = new QComboBox(tenantFilterBox);
        tenantFilterRole->addItem(QString());
        tenantFilterRole->addItem(QString());
        tenantFilterRole->addItem(QString());
        tenantFilterRole->setObjectName(QString::fromUtf8("tenantFilterRole"));

        gridLayout->addWidget(tenantFilterRole, 1, 2, 1, 1);

        tenantFilterStatusLabel = new QLabel(tenantFilterBox);
        tenantFilterStatusLabel->setObjectName(QString::fromUtf8("tenantFilterStatusLabel"));

        gridLayout->addWidget(tenantFilterStatusLabel, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 2, 1, 1);

        tenantFilterRoleLabel = new QLabel(tenantFilterBox);
        tenantFilterRoleLabel->setObjectName(QString::fromUtf8("tenantFilterRoleLabel"));

        gridLayout->addWidget(tenantFilterRoleLabel, 1, 1, 1, 1);

        tenantFilterStatus = new QComboBox(tenantFilterBox);
        tenantFilterStatus->addItem(QString());
        tenantFilterStatus->addItem(QString());
        tenantFilterStatus->addItem(QString());
        tenantFilterStatus->setObjectName(QString::fromUtf8("tenantFilterStatus"));

        gridLayout->addWidget(tenantFilterStatus, 0, 2, 1, 1);

        tenantFilterGenderLabel = new QLabel(tenantFilterBox);
        tenantFilterGenderLabel->setObjectName(QString::fromUtf8("tenantFilterGenderLabel"));

        gridLayout->addWidget(tenantFilterGenderLabel, 2, 1, 1, 1);

        tenantFilterGender = new QComboBox(tenantFilterBox);
        tenantFilterGender->addItem(QString());
        tenantFilterGender->addItem(QString());
        tenantFilterGender->addItem(QString());
        tenantFilterGender->addItem(QString());
        tenantFilterGender->setObjectName(QString::fromUtf8("tenantFilterGender"));

        gridLayout->addWidget(tenantFilterGender, 2, 2, 1, 1);


        horizontalLayout_4->addWidget(tenantFilterBox);

        stackedWidget->addWidget(tenantFilterView);
        contracFilterView = new QWidget();
        contracFilterView->setObjectName(QString::fromUtf8("contracFilterView"));
        horizontalLayout_6 = new QHBoxLayout(contracFilterView);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        contractFilterBox = new QGroupBox(contracFilterView);
        contractFilterBox->setObjectName(QString::fromUtf8("contractFilterBox"));
        formLayout_10 = new QFormLayout(contractFilterBox);
        formLayout_10->setObjectName(QString::fromUtf8("formLayout_10"));
        contractFilterStatusLabel = new QLabel(contractFilterBox);
        contractFilterStatusLabel->setObjectName(QString::fromUtf8("contractFilterStatusLabel"));

        formLayout_10->setWidget(0, QFormLayout::LabelRole, contractFilterStatusLabel);

        contractFilterStatus = new QComboBox(contractFilterBox);
        contractFilterStatus->addItem(QString());
        contractFilterStatus->addItem(QString());
        contractFilterStatus->addItem(QString());
        contractFilterStatus->addItem(QString());
        contractFilterStatus->setObjectName(QString::fromUtf8("contractFilterStatus"));

        formLayout_10->setWidget(0, QFormLayout::FieldRole, contractFilterStatus);

        contractFilterRoomRentLabel = new QLabel(contractFilterBox);
        contractFilterRoomRentLabel->setObjectName(QString::fromUtf8("contractFilterRoomRentLabel"));

        formLayout_10->setWidget(2, QFormLayout::LabelRole, contractFilterRoomRentLabel);

        contractFilterRoomRentBox = new QFrame(contractFilterBox);
        contractFilterRoomRentBox->setObjectName(QString::fromUtf8("contractFilterRoomRentBox"));
        contractFilterRoomRentBox->setFrameShape(QFrame::StyledPanel);
        contractFilterRoomRentBox->setFrameShadow(QFrame::Plain);
        formLayout_3 = new QFormLayout(contractFilterRoomRentBox);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        contractFilterRoomRentFromLabel = new QLabel(contractFilterRoomRentBox);
        contractFilterRoomRentFromLabel->setObjectName(QString::fromUtf8("contractFilterRoomRentFromLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, contractFilterRoomRentFromLabel);

        contractFilterRoomRentFrom = new QSpinBox(contractFilterRoomRentBox);
        contractFilterRoomRentFrom->setObjectName(QString::fromUtf8("contractFilterRoomRentFrom"));
        contractFilterRoomRentFrom->setMaximum(999999999);
        contractFilterRoomRentFrom->setSingleStep(100000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, contractFilterRoomRentFrom);

        contractFilterRoomRentToLabel = new QLabel(contractFilterRoomRentBox);
        contractFilterRoomRentToLabel->setObjectName(QString::fromUtf8("contractFilterRoomRentToLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, contractFilterRoomRentToLabel);

        contractFilterRoomRentTo = new QSpinBox(contractFilterRoomRentBox);
        contractFilterRoomRentTo->setObjectName(QString::fromUtf8("contractFilterRoomRentTo"));
        contractFilterRoomRentTo->setMaximum(999999999);
        contractFilterRoomRentTo->setSingleStep(100000);
        contractFilterRoomRentTo->setValue(10000000);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, contractFilterRoomRentTo);


        formLayout_10->setWidget(2, QFormLayout::FieldRole, contractFilterRoomRentBox);

        label_13 = new QLabel(contractFilterBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_10->setWidget(4, QFormLayout::LabelRole, label_13);

        contractFilterDepositBox = new QFrame(contractFilterBox);
        contractFilterDepositBox->setObjectName(QString::fromUtf8("contractFilterDepositBox"));
        contractFilterDepositBox->setFrameShape(QFrame::StyledPanel);
        contractFilterDepositBox->setFrameShadow(QFrame::Plain);
        formLayout_5 = new QFormLayout(contractFilterDepositBox);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        contractFilterDepositFromLabel = new QLabel(contractFilterDepositBox);
        contractFilterDepositFromLabel->setObjectName(QString::fromUtf8("contractFilterDepositFromLabel"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, contractFilterDepositFromLabel);

        contractFilterDepositFrom = new QSpinBox(contractFilterDepositBox);
        contractFilterDepositFrom->setObjectName(QString::fromUtf8("contractFilterDepositFrom"));
        contractFilterDepositFrom->setMaximum(999999999);
        contractFilterDepositFrom->setSingleStep(100000);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, contractFilterDepositFrom);

        contractFilterDepositToLabel = new QLabel(contractFilterDepositBox);
        contractFilterDepositToLabel->setObjectName(QString::fromUtf8("contractFilterDepositToLabel"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, contractFilterDepositToLabel);

        contractFilterDepositTo = new QSpinBox(contractFilterDepositBox);
        contractFilterDepositTo->setObjectName(QString::fromUtf8("contractFilterDepositTo"));
        contractFilterDepositTo->setMaximum(999999999);
        contractFilterDepositTo->setSingleStep(100000);
        contractFilterDepositTo->setValue(10000000);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, contractFilterDepositTo);


        formLayout_10->setWidget(4, QFormLayout::FieldRole, contractFilterDepositBox);

        label_12 = new QLabel(contractFilterBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_10->setWidget(6, QFormLayout::LabelRole, label_12);

        contractFilterStartDate = new QFrame(contractFilterBox);
        contractFilterStartDate->setObjectName(QString::fromUtf8("contractFilterStartDate"));
        contractFilterStartDate->setFrameShape(QFrame::StyledPanel);
        contractFilterStartDate->setFrameShadow(QFrame::Plain);
        formLayout_4 = new QFormLayout(contractFilterStartDate);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        contractFilterStartDateToLabel = new QLabel(contractFilterStartDate);
        contractFilterStartDateToLabel->setObjectName(QString::fromUtf8("contractFilterStartDateToLabel"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, contractFilterStartDateToLabel);

        contractFilterStartDateFromLabel = new QLabel(contractFilterStartDate);
        contractFilterStartDateFromLabel->setObjectName(QString::fromUtf8("contractFilterStartDateFromLabel"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, contractFilterStartDateFromLabel);

        contractFilterStartDateFrom = new QDateEdit(contractFilterStartDate);
        contractFilterStartDateFrom->setObjectName(QString::fromUtf8("contractFilterStartDateFrom"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, contractFilterStartDateFrom);

        contractFilterStartDateTo = new QDateEdit(contractFilterStartDate);
        contractFilterStartDateTo->setObjectName(QString::fromUtf8("contractFilterStartDateTo"));
        contractFilterStartDateTo->setDateTime(QDateTime(QDate(2050, 1, 1), QTime(0, 0, 0)));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, contractFilterStartDateTo);


        formLayout_10->setWidget(6, QFormLayout::FieldRole, contractFilterStartDate);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_10->setItem(9, QFormLayout::FieldRole, verticalSpacer_3);

        contractFilterEndDate = new QFrame(contractFilterBox);
        contractFilterEndDate->setObjectName(QString::fromUtf8("contractFilterEndDate"));
        contractFilterEndDate->setFrameShape(QFrame::StyledPanel);
        contractFilterEndDate->setFrameShadow(QFrame::Plain);
        formLayout_6 = new QFormLayout(contractFilterEndDate);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        contractFilterEndDateToLabel = new QLabel(contractFilterEndDate);
        contractFilterEndDateToLabel->setObjectName(QString::fromUtf8("contractFilterEndDateToLabel"));

        formLayout_6->setWidget(1, QFormLayout::LabelRole, contractFilterEndDateToLabel);

        contractFilterEndDateFromLabel = new QLabel(contractFilterEndDate);
        contractFilterEndDateFromLabel->setObjectName(QString::fromUtf8("contractFilterEndDateFromLabel"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, contractFilterEndDateFromLabel);

        contractFilterEndDateFrom = new QDateEdit(contractFilterEndDate);
        contractFilterEndDateFrom->setObjectName(QString::fromUtf8("contractFilterEndDateFrom"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, contractFilterEndDateFrom);

        contractFilterEndDateTo = new QDateEdit(contractFilterEndDate);
        contractFilterEndDateTo->setObjectName(QString::fromUtf8("contractFilterEndDateTo"));
        contractFilterEndDateTo->setDateTime(QDateTime(QDate(2050, 1, 1), QTime(0, 0, 0)));

        formLayout_6->setWidget(1, QFormLayout::FieldRole, contractFilterEndDateTo);


        formLayout_10->setWidget(7, QFormLayout::FieldRole, contractFilterEndDate);

        label = new QLabel(contractFilterBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_10->setWidget(7, QFormLayout::LabelRole, label);


        horizontalLayout_6->addWidget(contractFilterBox);

        stackedWidget->addWidget(contracFilterView);
        billFilterView = new QWidget();
        billFilterView->setObjectName(QString::fromUtf8("billFilterView"));
        horizontalLayout_7 = new QHBoxLayout(billFilterView);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        billFilterBox = new QGroupBox(billFilterView);
        billFilterBox->setObjectName(QString::fromUtf8("billFilterBox"));
        formLayout_7 = new QFormLayout(billFilterBox);
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        billFilterStatusLabel = new QLabel(billFilterBox);
        billFilterStatusLabel->setObjectName(QString::fromUtf8("billFilterStatusLabel"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, billFilterStatusLabel);

        billFilterStatus = new QComboBox(billFilterBox);
        billFilterStatus->addItem(QString());
        billFilterStatus->addItem(QString());
        billFilterStatus->addItem(QString());
        billFilterStatus->addItem(QString());
        billFilterStatus->setObjectName(QString::fromUtf8("billFilterStatus"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, billFilterStatus);

        label_19 = new QLabel(billFilterBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, label_19);

        billFilterPriceBox = new QFrame(billFilterBox);
        billFilterPriceBox->setObjectName(QString::fromUtf8("billFilterPriceBox"));
        billFilterPriceBox->setFrameShape(QFrame::StyledPanel);
        billFilterPriceBox->setFrameShadow(QFrame::Plain);
        formLayout_9 = new QFormLayout(billFilterPriceBox);
        formLayout_9->setObjectName(QString::fromUtf8("formLayout_9"));
        billFilterPriceFromLabel = new QLabel(billFilterPriceBox);
        billFilterPriceFromLabel->setObjectName(QString::fromUtf8("billFilterPriceFromLabel"));

        formLayout_9->setWidget(0, QFormLayout::LabelRole, billFilterPriceFromLabel);

        billFilterPriceFrom = new QSpinBox(billFilterPriceBox);
        billFilterPriceFrom->setObjectName(QString::fromUtf8("billFilterPriceFrom"));
        billFilterPriceFrom->setMaximum(999999999);
        billFilterPriceFrom->setSingleStep(100000);

        formLayout_9->setWidget(0, QFormLayout::FieldRole, billFilterPriceFrom);

        billFilterPriceToLabel = new QLabel(billFilterPriceBox);
        billFilterPriceToLabel->setObjectName(QString::fromUtf8("billFilterPriceToLabel"));

        formLayout_9->setWidget(1, QFormLayout::LabelRole, billFilterPriceToLabel);

        billFilterPriceTo = new QSpinBox(billFilterPriceBox);
        billFilterPriceTo->setObjectName(QString::fromUtf8("billFilterPriceTo"));
        billFilterPriceTo->setMaximum(999999999);
        billFilterPriceTo->setSingleStep(100000);
        billFilterPriceTo->setValue(10000000);

        formLayout_9->setWidget(1, QFormLayout::FieldRole, billFilterPriceTo);


        formLayout_7->setWidget(1, QFormLayout::FieldRole, billFilterPriceBox);

        label_16 = new QLabel(billFilterBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, label_16);

        billFilterMonth = new QFrame(billFilterBox);
        billFilterMonth->setObjectName(QString::fromUtf8("billFilterMonth"));
        billFilterMonth->setFrameShape(QFrame::StyledPanel);
        billFilterMonth->setFrameShadow(QFrame::Plain);
        formLayout_8 = new QFormLayout(billFilterMonth);
        formLayout_8->setObjectName(QString::fromUtf8("formLayout_8"));
        billFilterMonthFromLabel = new QLabel(billFilterMonth);
        billFilterMonthFromLabel->setObjectName(QString::fromUtf8("billFilterMonthFromLabel"));

        formLayout_8->setWidget(1, QFormLayout::LabelRole, billFilterMonthFromLabel);

        billFilterMonthFrom = new QDateEdit(billFilterMonth);
        billFilterMonthFrom->setObjectName(QString::fromUtf8("billFilterMonthFrom"));
        billFilterMonthFrom->setCurrentSection(QDateTimeEdit::MonthSection);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, billFilterMonthFrom);

        billFilterMonthTo = new QDateEdit(billFilterMonth);
        billFilterMonthTo->setObjectName(QString::fromUtf8("billFilterMonthTo"));
        billFilterMonthTo->setDateTime(QDateTime(QDate(2050, 1, 1), QTime(0, 0, 0)));

        formLayout_8->setWidget(1, QFormLayout::FieldRole, billFilterMonthTo);

        billFilterMonthToLabel = new QLabel(billFilterMonth);
        billFilterMonthToLabel->setObjectName(QString::fromUtf8("billFilterMonthToLabel"));

        formLayout_8->setWidget(0, QFormLayout::LabelRole, billFilterMonthToLabel);


        formLayout_7->setWidget(2, QFormLayout::FieldRole, billFilterMonth);


        horizontalLayout_7->addWidget(billFilterBox);

        stackedWidget->addWidget(billFilterView);

        verticalLayout_4->addWidget(stackedWidget);

        tabWidget->addTab(filterTab, QString());

        verticalLayout->addWidget(tabWidget);

        buttonBox = new QDialogButtonBox(SearchFilterDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(SearchFilterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SearchFilterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SearchFilterDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(SearchFilterDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchFilterDialog)
    {
        SearchFilterDialog->setWindowTitle(QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m v\303\240 L\341\273\215c", nullptr));
        searchGroupBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m th\303\264ng tin", nullptr));
        searchLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253 kh\303\263a:", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("SearchFilterDialog", "Nh\341\272\255p t\341\273\253 kh\303\263a t\303\254m ki\341\272\277m...", nullptr));
        searchFieldLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\303\254m theo:", nullptr));
        caseSensitiveCheckBox->setText(QCoreApplication::translate("SearchFilterDialog", "Ph\303\242n bi\341\273\207t ch\341\273\257 hoa/th\306\260\341\273\235ng", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(searchTab), QCoreApplication::translate("SearchFilterDialog", "T\303\254m ki\341\272\277m", nullptr));
        roomFilterBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "Ph\303\262ng", nullptr));
        filterRoomTypeLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Lo\341\272\241i Ph\303\262ng", nullptr));
        filterRoomType->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "...", nullptr));
        filterRoomType->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "Ph\303\262ng \304\220\306\241n", nullptr));
        filterRoomType->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "Ph\303\262ng \304\220\303\264i", nullptr));
        filterRoomType->setItemText(3, QCoreApplication::translate("SearchFilterDialog", "Ph\303\262ng Gia \304\220\303\254nh", nullptr));

        filterRoomStatusLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Tr\341\272\241ng Th\303\241i", nullptr));
        filterRoomStatus->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "...", nullptr));
        filterRoomStatus->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "Tr\341\273\221ng", nullptr));
        filterRoomStatus->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "\304\220\303\243 Thu\303\252", nullptr));

        filterRoomPriceLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Gi\303\241 Thu\303\252", nullptr));
        filterRoomPriceFromLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253", nullptr));
        filterRoomPriceFrom->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        filterRoomPriceFrom->setPrefix(QString());
        filterRoomPriceToLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n", nullptr));
        filterRoomPriceTo->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        filterRoomPriceTo->setPrefix(QString());
        billInMonth->setText(QCoreApplication::translate("SearchFilterDialog", "H\303\263a \304\221\306\241n th\303\241ng n\303\240y", nullptr));
        tenantFilterBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "Kh\303\241ch H\303\240ng", nullptr));
        tenantFilterRole->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "...", nullptr));
        tenantFilterRole->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "Ch\341\273\247 H\341\273\243p \304\220\341\273\223ng", nullptr));
        tenantFilterRole->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "Kh\303\241ch Thu\303\252", nullptr));

        tenantFilterStatusLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Tr\341\272\241ng Th\303\241i", nullptr));
        tenantFilterRoleLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Vai tr\303\262", nullptr));
        tenantFilterStatus->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "...", nullptr));
        tenantFilterStatus->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "\304\220ang Thu\303\252", nullptr));
        tenantFilterStatus->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "Ch\306\260a c\303\263 ph\303\262ng", nullptr));

        tenantFilterGenderLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Gi\341\273\233i T\303\255nh", nullptr));
        tenantFilterGender->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "...", nullptr));
        tenantFilterGender->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "Nam", nullptr));
        tenantFilterGender->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "N\341\273\257", nullptr));
        tenantFilterGender->setItemText(3, QCoreApplication::translate("SearchFilterDialog", "Kh\303\241c", nullptr));

        contractFilterBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "H\341\273\243p \304\220\341\273\223ng", nullptr));
        contractFilterStatusLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Tr\341\272\241ng Th\303\241i", nullptr));
        contractFilterStatus->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "...", nullptr));
        contractFilterStatus->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "\304\220\303\243 K\341\272\277t Th\303\272c", nullptr));
        contractFilterStatus->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "\304\220ang Ho\341\272\241t \304\220\341\273\231ng", nullptr));
        contractFilterStatus->setItemText(3, QCoreApplication::translate("SearchFilterDialog", "V\303\264 Hi\341\273\207u", nullptr));

        contractFilterRoomRentLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Ti\341\273\201n Thu\303\252", nullptr));
        contractFilterRoomRentFromLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253", nullptr));
        contractFilterRoomRentFrom->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        contractFilterRoomRentFrom->setPrefix(QString());
        contractFilterRoomRentToLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n", nullptr));
        contractFilterRoomRentTo->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        contractFilterRoomRentTo->setPrefix(QString());
        label_13->setText(QCoreApplication::translate("SearchFilterDialog", "Ti\341\273\201n C\341\273\215c", nullptr));
        contractFilterDepositFromLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253", nullptr));
        contractFilterDepositFrom->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        contractFilterDepositFrom->setPrefix(QString());
        contractFilterDepositToLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n", nullptr));
        contractFilterDepositTo->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        contractFilterDepositTo->setPrefix(QString());
        label_12->setText(QCoreApplication::translate("SearchFilterDialog", "Ng\303\240y B\341\272\257t \304\220\341\272\247u", nullptr));
        contractFilterStartDateToLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n", nullptr));
        contractFilterStartDateFromLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253", nullptr));
        contractFilterStartDateFrom->setDisplayFormat(QCoreApplication::translate("SearchFilterDialog", "dd/MM/yyyy", nullptr));
        contractFilterStartDateTo->setDisplayFormat(QCoreApplication::translate("SearchFilterDialog", "dd/MM/yyyy", nullptr));
        contractFilterEndDateToLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n", nullptr));
        contractFilterEndDateFromLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253", nullptr));
        contractFilterEndDateFrom->setDisplayFormat(QCoreApplication::translate("SearchFilterDialog", "dd/MM/yyyy", nullptr));
        contractFilterEndDateTo->setDisplayFormat(QCoreApplication::translate("SearchFilterDialog", "dd/MM/yyyy", nullptr));
        label->setText(QCoreApplication::translate("SearchFilterDialog", "Ng\303\240y H\341\272\277t H\341\272\241n", nullptr));
        billFilterBox->setTitle(QCoreApplication::translate("SearchFilterDialog", "H\303\263a \304\220\306\241n", nullptr));
        billFilterStatusLabel->setText(QCoreApplication::translate("SearchFilterDialog", "Tr\341\272\241ng Th\303\241i", nullptr));
        billFilterStatus->setItemText(0, QCoreApplication::translate("SearchFilterDialog", "...", nullptr));
        billFilterStatus->setItemText(1, QCoreApplication::translate("SearchFilterDialog", "Ch\306\260a thanh to\303\241n", nullptr));
        billFilterStatus->setItemText(2, QCoreApplication::translate("SearchFilterDialog", "\304\220\303\243 thanh to\303\241n", nullptr));
        billFilterStatus->setItemText(3, QCoreApplication::translate("SearchFilterDialog", "V\303\264 hi\341\273\207u h\303\263a", nullptr));

        label_19->setText(QCoreApplication::translate("SearchFilterDialog", "S\341\273\221 Ti\341\273\201n", nullptr));
        billFilterPriceFromLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253", nullptr));
        billFilterPriceFrom->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        billFilterPriceFrom->setPrefix(QString());
        billFilterPriceToLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n", nullptr));
        billFilterPriceTo->setSuffix(QCoreApplication::translate("SearchFilterDialog", " VN\304\220", nullptr));
        billFilterPriceTo->setPrefix(QString());
        label_16->setText(QCoreApplication::translate("SearchFilterDialog", "Th\303\241ng Thanh To\303\241n", nullptr));
        billFilterMonthFromLabel->setText(QCoreApplication::translate("SearchFilterDialog", "\304\220\341\272\277n", nullptr));
        billFilterMonthFrom->setDisplayFormat(QCoreApplication::translate("SearchFilterDialog", "MM/yyyy", nullptr));
        billFilterMonthTo->setDisplayFormat(QCoreApplication::translate("SearchFilterDialog", "MM/yyyy", nullptr));
        billFilterMonthToLabel->setText(QCoreApplication::translate("SearchFilterDialog", "T\341\273\253", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(filterTab), QCoreApplication::translate("SearchFilterDialog", "L\341\273\215c", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchFilterDialog: public Ui_SearchFilterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SEARCH_FILTER_DIALOG_H
