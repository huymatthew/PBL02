/********************************************************************************
** Form generated from reading UI file 'admin_main.ui'
**
** Created by: Qt User Interface Compiler version 5.15.19
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ADMIN_MAIN_H
#define ADMIN_MAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMainWindow
{
public:
    QAction *actionNewProject;
    QAction *actionOpenProject;
    QAction *actionSaveProject;
    QAction *actionBackupData;
    QAction *actionRestoreData;
    QAction *actionExit;
    QAction *actionRoomManagement;
    QAction *actionTenantManagement;
    QAction *actionContractManagement;
    QAction *actionPaymentManagement;
    QAction *actionSettings;
    QAction *actionFinancialReport;
    QAction *actionOccupancyReport;
    QAction *actionPaymentReport;
    QAction *actionExportData;
    QAction *actionUserManual;
    QAction *actionContactSupport;
    QAction *actionAbout;
    QAction *actionQuickAddRoom;
    QAction *actionQuickAddTenant;
    QAction *actionQuickAddContract;
    QAction *actionQuickSearch;
    QAction *actionRefresh;
    QAction *actionBackup;
    QWidget *centralwidget;
    QVBoxLayout *mainVerticalLayout;
    QTabWidget *mainTabWidget;
    QWidget *roomsTab;
    QHBoxLayout *roomsLayout;
    QTableView *roomsTableView;
    QVBoxLayout *roomControlsLayout;
    QGroupBox *roomInfoGroup;
    QFormLayout *roomFormLayout;
    QLabel *roomNumberLabel;
    QLineEdit *roomNumberEdit;
    QLabel *roomTypeLabel;
    QComboBox *roomTypeComboBox;
    QLabel *roomPriceLabel;
    QDoubleSpinBox *roomPriceSpinBox;
    QLabel *roomStatusLabel;
    QComboBox *roomStatusComboBox;
    QLabel *roomDescLabel;
    QLineEdit *roomDescEdit;
    QSpacerItem *roomVerticalSpacer;
    QVBoxLayout *roomButtonsLayout;
    QPushButton *addRoomButton;
    QPushButton *editRoomButton;
    QPushButton *deleteRoomButton;
    QWidget *tenantsTab;
    QHBoxLayout *tenantsLayout;
    QTableView *tenantsTableView;
    QVBoxLayout *tenantControlsLayout;
    QGroupBox *tenantInfoGroup;
    QFormLayout *tenantFormLayout;
    QLabel *tenantNameLabel;
    QLineEdit *tenantNameEdit;
    QLineEdit *tenantPhoneEdit;
    QLabel *tenantRoomLabel;
    QComboBox *tenantRoomComboBox;
    QLabel *tenantPhoneLabel;
    QLineEdit *tenantIdEdit;
    QLabel *tenantIdLabel;
    QDateEdit *dateOfBirth;
    QLabel *label;
    QSpacerItem *tenantVerticalSpacer;
    QVBoxLayout *tenantButtonsLayout;
    QPushButton *addTenantButton;
    QPushButton *editTenantButton;
    QPushButton *deleteTenantButton;
    QWidget *contractsTab;
    QHBoxLayout *contractsLayout;
    QTableView *contractsTableView;
    QVBoxLayout *contractControlsLayout;
    QGroupBox *contractInfoGroup;
    QFormLayout *contractFormLayout;
    QLabel *contractTenantLabel;
    QComboBox *contractTenantComboBox;
    QLabel *contractRoomLabel;
    QComboBox *contractRoomComboBox;
    QLabel *contractStartDateLabel;
    QDateEdit *contractStartDateEdit;
    QLabel *contractEndDateLabel;
    QDateEdit *contractEndDateEdit;
    QLabel *contractDepositLabel;
    QDoubleSpinBox *contractDepositSpinBox;
    QLabel *contractStatusLabel;
    QComboBox *contractStatusComboBox;
    QSpacerItem *contractVerticalSpacer;
    QVBoxLayout *contractButtonsLayout;
    QPushButton *addContractButton;
    QPushButton *editContractButton;
    QPushButton *terminateContractButton;
    QWidget *paymentsTab;
    QHBoxLayout *paymentsLayout;
    QTableView *paymentsTableView;
    QVBoxLayout *paymentControlsLayout;
    QGroupBox *paymentInfoGroup;
    QFormLayout *paymentFormLayout;
    QLabel *paymentRoomLabel;
    QComboBox *paymentRoomComboBox;
    QLabel *paymentMonthLabel;
    QDateEdit *paymentMonthEdit;
    QLabel *rentAmountLabel;
    QDoubleSpinBox *rentAmountSpinBox;
    QLabel *electricBillLabel;
    QDoubleSpinBox *electricBillSpinBox;
    QLabel *waterBillLabel;
    QDoubleSpinBox *waterBillSpinBox;
    QLabel *internetBillLabel;
    QDoubleSpinBox *internetBillSpinBox;
    QLabel *paymentStatusLabel;
    QComboBox *paymentStatusComboBox;
    QSpacerItem *paymentVerticalSpacer;
    QVBoxLayout *paymentButtonsLayout;
    QPushButton *addPaymentButton;
    QPushButton *editPaymentButton;
    QPushButton *printInvoiceButton;
    QWidget *reportsTab;
    QVBoxLayout *reportsMainLayout;
    QHBoxLayout *reportsFilterLayout;
    QGroupBox *filterGroup;
    QHBoxLayout *filterLayout;
    QLabel *fromDateLabel;
    QDateEdit *fromDateEdit;
    QLabel *toDateLabel;
    QDateEdit *toDateEdit;
    QPushButton *generateReportButton;
    QSpacerItem *filterHorizontalSpacer;
    QHBoxLayout *reportsContentLayout;
    QGroupBox *summaryGroup;
    QFormLayout *summaryLayout;
    QLabel *totalRoomsLabel;
    QLabel *totalRoomsValue;
    QLabel *occupiedRoomsLabel;
    QLabel *occupiedRoomsValue;
    QLabel *emptyRoomsLabel;
    QLabel *emptyRoomsValue;
    QLabel *totalRevenueLabel;
    QLabel *totalRevenueValue;
    QLabel *unpaidBillsLabel;
    QLabel *unpaidBillsValue;
    QTableView *reportsTableView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuManagement;
    QMenu *menuReports;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QLabel *statusInfoLabel;
    QLabel *dateTimeLabel;
    QToolBar *toolBar;

    void setupUi(QMainWindow *AdminMainWindow)
    {
        if (AdminMainWindow->objectName().isEmpty())
            AdminMainWindow->setObjectName(QString::fromUtf8("AdminMainWindow"));
        AdminMainWindow->resize(1200, 862);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        AdminMainWindow->setWindowIcon(icon);
        AdminMainWindow->setStyleSheet(QString::fromUtf8("/* Admin Window Styling */\n"
"QMainWindow {\n"
"    background-color: #f8f9fa;\n"
"    color: #212529;\n"
"}\n"
"\n"
"/* Menu Bar Styling */\n"
"QMenuBar {\n"
"    background-color: #343a40;\n"
"    color: white;\n"
"    border-bottom: 3px solid #495057;\n"
"    padding: 6px;\n"
"    font-size: 13px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background-color: transparent;\n"
"    padding: 10px 15px;\n"
"    border-radius: 5px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #007bff;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    background-color: #0056b3;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: white;\n"
"    border: 2px solid #dee2e6;\n"
"    border-radius: 8px;\n"
"    padding: 6px;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 10px 30px;\n"
"    margin: 2px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"}\n"
"\n"
"QMenu::separat"
                        "or {\n"
"    height: 2px;\n"
"    background-color: #dee2e6;\n"
"    margin: 6px 20px;\n"
"}\n"
"\n"
"/* Tool Bar Styling */\n"
"QToolBar {\n"
"    background-color: #e9ecef;\n"
"    border: none;\n"
"    border-bottom: 2px solid #dee2e6;\n"
"    spacing: 10px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 10px;\n"
"    padding: 12px 16px;\n"
"    min-width: 100px;\n"
"    font-weight: bold;\n"
"    font-size: 11px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"    border-color: #0056b3;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background-color: #0056b3;\n"
"}\n"
"\n"
"/* Tab Widget Styling */\n"
"QTabWidget::pane {\n"
"    border: 2px solid #dee2e6;\n"
"    border-radius: 10px;\n"
"    background-color: white;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #f8f9fa;\n"
"    border: 2px solid #dee2e6;\n"
"    border-bottom: none;\n"
""
                        "    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    padding: 12px 20px;\n"
"    margin-right: 2px;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"    color: #495057;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    color: #007bff;\n"
"    border-color: #007bff;\n"
"    border-bottom: 2px solid white;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #e9ecef;\n"
"}\n"
"\n"
"/* Table View Styling */\n"
"QTableView {\n"
"    background-color: white;\n"
"    alternate-background-color: #f8f9fa;\n"
"    gridline-color: #dee2e6;\n"
"    border: 2px solid #e9ecef;\n"
"    border-radius: 10px;\n"
"    selection-background-color: #007bff;\n"
"    selection-color: white;\n"
"    font-size: 11px;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #e9ecef;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    backgr"
                        "ound-color: #495057;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"    font-size: 12px;\n"
"}\n"
"\n"
"QHeaderView::section:hover {\n"
"    background-color: #343a40;\n"
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
"    font-size:"
                        " 12px;\n"
"    min-height: 18px;\n"
"}\n"
"\n"
"QDateEdit:focus, QComboBox:focus, QDoubleSpinBox:focus, QLineEdit:focus, QSpinBox:focus {\n"
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
""
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
"#addButton {\n"
"    background-color: #28a745;\n"
"}\n"
"\n"
"#addButton:hover {\n"
"    background-color: #1e7e34;\n"
"}\n"
"\n"
"#editButton {\n"
"    background-color: #ffc107;\n"
"    color: #212529;\n"
"}\n"
"\n"
"#editButton:hover {\n"
"    background-color: #e0a800;\n"
"}\n"
"\n"
"#deleteButton {\n"
"    background-color: #dc3545;\n"
"}\n"
"\n"
"#deleteButton:hover {\n"
"    background-color: #c82333;\n"
"}\n"
"\n"
"#searchButton {\n"
"    background-color: #17a2b8;\n"
"}\n"
"\n"
"#searchButton:hover {\n"
"    background-color: #138496;\n"
"}\n"
"\n"
"/* Status Bar Styling */\n"
"QStatusBar {\n"
"    background-color: #495057"
                        ";\n"
"    color: white;\n"
"    border-top: 3px solid #343a40;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QStatusBar QLabel {\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    font-size: 13px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"/* Search Box */\n"
"#searchBox {\n"
"    background-color: white;\n"
"    border: 2px solid #ced4da;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    min-width: 200px;\n"
"}\n"
""));
        actionNewProject = new QAction(AdminMainWindow);
        actionNewProject->setObjectName(QString::fromUtf8("actionNewProject"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewProject->setIcon(icon1);
        actionOpenProject = new QAction(AdminMainWindow);
        actionOpenProject->setObjectName(QString::fromUtf8("actionOpenProject"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenProject->setIcon(icon2);
        actionSaveProject = new QAction(AdminMainWindow);
        actionSaveProject->setObjectName(QString::fromUtf8("actionSaveProject"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveProject->setIcon(icon3);
        actionBackupData = new QAction(AdminMainWindow);
        actionBackupData->setObjectName(QString::fromUtf8("actionBackupData"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/backup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackupData->setIcon(icon4);
        actionRestoreData = new QAction(AdminMainWindow);
        actionRestoreData->setObjectName(QString::fromUtf8("actionRestoreData"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/restore.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestoreData->setIcon(icon5);
        actionExit = new QAction(AdminMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon6);
        actionRoomManagement = new QAction(AdminMainWindow);
        actionRoomManagement->setObjectName(QString::fromUtf8("actionRoomManagement"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/rooms.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRoomManagement->setIcon(icon7);
        actionTenantManagement = new QAction(AdminMainWindow);
        actionTenantManagement->setObjectName(QString::fromUtf8("actionTenantManagement"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/tenants.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTenantManagement->setIcon(icon8);
        actionContractManagement = new QAction(AdminMainWindow);
        actionContractManagement->setObjectName(QString::fromUtf8("actionContractManagement"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/contracts.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContractManagement->setIcon(icon9);
        actionPaymentManagement = new QAction(AdminMainWindow);
        actionPaymentManagement->setObjectName(QString::fromUtf8("actionPaymentManagement"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/payments.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaymentManagement->setIcon(icon10);
        actionSettings = new QAction(AdminMainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon11);
        actionFinancialReport = new QAction(AdminMainWindow);
        actionFinancialReport->setObjectName(QString::fromUtf8("actionFinancialReport"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/financial.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFinancialReport->setIcon(icon12);
        actionOccupancyReport = new QAction(AdminMainWindow);
        actionOccupancyReport->setObjectName(QString::fromUtf8("actionOccupancyReport"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/occupancy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOccupancyReport->setIcon(icon13);
        actionPaymentReport = new QAction(AdminMainWindow);
        actionPaymentReport->setObjectName(QString::fromUtf8("actionPaymentReport"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/payment-report.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaymentReport->setIcon(icon14);
        actionExportData = new QAction(AdminMainWindow);
        actionExportData->setObjectName(QString::fromUtf8("actionExportData"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/icons/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExportData->setIcon(icon15);
        actionUserManual = new QAction(AdminMainWindow);
        actionUserManual->setObjectName(QString::fromUtf8("actionUserManual"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/icons/manual.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUserManual->setIcon(icon16);
        actionContactSupport = new QAction(AdminMainWindow);
        actionContactSupport->setObjectName(QString::fromUtf8("actionContactSupport"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/icons/support.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionContactSupport->setIcon(icon17);
        actionAbout = new QAction(AdminMainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/icons/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon18);
        actionQuickAddRoom = new QAction(AdminMainWindow);
        actionQuickAddRoom->setObjectName(QString::fromUtf8("actionQuickAddRoom"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/icons/add-room.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuickAddRoom->setIcon(icon19);
        actionQuickAddTenant = new QAction(AdminMainWindow);
        actionQuickAddTenant->setObjectName(QString::fromUtf8("actionQuickAddTenant"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/icons/add-tenant.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuickAddTenant->setIcon(icon20);
        actionQuickAddContract = new QAction(AdminMainWindow);
        actionQuickAddContract->setObjectName(QString::fromUtf8("actionQuickAddContract"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/icons/add-contract.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuickAddContract->setIcon(icon21);
        actionQuickSearch = new QAction(AdminMainWindow);
        actionQuickSearch->setObjectName(QString::fromUtf8("actionQuickSearch"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/icons/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuickSearch->setIcon(icon22);
        actionRefresh = new QAction(AdminMainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/icons/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon23);
        actionBackup = new QAction(AdminMainWindow);
        actionBackup->setObjectName(QString::fromUtf8("actionBackup"));
        actionBackup->setIcon(icon4);
        centralwidget = new QWidget(AdminMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainVerticalLayout = new QVBoxLayout(centralwidget);
        mainVerticalLayout->setObjectName(QString::fromUtf8("mainVerticalLayout"));
        mainTabWidget = new QTabWidget(centralwidget);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        mainTabWidget->setMinimumSize(QSize(0, 0));
        mainTabWidget->setMaximumSize(QSize(16777215, 16777213));
        mainTabWidget->setLayoutDirection(Qt::LeftToRight);
        mainTabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab { min-width: 150px; }"));
        mainTabWidget->setTabPosition(QTabWidget::North);
        mainTabWidget->setTabShape(QTabWidget::Rounded);
        mainTabWidget->setIconSize(QSize(20, 20));
        mainTabWidget->setElideMode(Qt::ElideNone);
        mainTabWidget->setMovable(false);
        roomsTab = new QWidget();
        roomsTab->setObjectName(QString::fromUtf8("roomsTab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(roomsTab->sizePolicy().hasHeightForWidth());
        roomsTab->setSizePolicy(sizePolicy);
        roomsTab->setAcceptDrops(false);
        roomsLayout = new QHBoxLayout(roomsTab);
        roomsLayout->setObjectName(QString::fromUtf8("roomsLayout"));
        roomsLayout->setContentsMargins(-1, -1, 11, -1);
        roomsTableView = new QTableView(roomsTab);
        roomsTableView->setObjectName(QString::fromUtf8("roomsTableView"));
        roomsTableView->setMinimumSize(QSize(600, 0));
        roomsTableView->setAlternatingRowColors(true);
        roomsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        roomsTableView->setSortingEnabled(true);

        roomsLayout->addWidget(roomsTableView);

        roomControlsLayout = new QVBoxLayout();
        roomControlsLayout->setObjectName(QString::fromUtf8("roomControlsLayout"));
        roomInfoGroup = new QGroupBox(roomsTab);
        roomInfoGroup->setObjectName(QString::fromUtf8("roomInfoGroup"));
        roomFormLayout = new QFormLayout(roomInfoGroup);
        roomFormLayout->setObjectName(QString::fromUtf8("roomFormLayout"));
        roomNumberLabel = new QLabel(roomInfoGroup);
        roomNumberLabel->setObjectName(QString::fromUtf8("roomNumberLabel"));

        roomFormLayout->setWidget(0, QFormLayout::LabelRole, roomNumberLabel);

        roomNumberEdit = new QLineEdit(roomInfoGroup);
        roomNumberEdit->setObjectName(QString::fromUtf8("roomNumberEdit"));

        roomFormLayout->setWidget(0, QFormLayout::FieldRole, roomNumberEdit);

        roomTypeLabel = new QLabel(roomInfoGroup);
        roomTypeLabel->setObjectName(QString::fromUtf8("roomTypeLabel"));

        roomFormLayout->setWidget(1, QFormLayout::LabelRole, roomTypeLabel);

        roomTypeComboBox = new QComboBox(roomInfoGroup);
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->addItem(QString());
        roomTypeComboBox->setObjectName(QString::fromUtf8("roomTypeComboBox"));

        roomFormLayout->setWidget(1, QFormLayout::FieldRole, roomTypeComboBox);

        roomPriceLabel = new QLabel(roomInfoGroup);
        roomPriceLabel->setObjectName(QString::fromUtf8("roomPriceLabel"));

        roomFormLayout->setWidget(2, QFormLayout::LabelRole, roomPriceLabel);

        roomPriceSpinBox = new QDoubleSpinBox(roomInfoGroup);
        roomPriceSpinBox->setObjectName(QString::fromUtf8("roomPriceSpinBox"));
        roomPriceSpinBox->setDecimals(0);
        roomPriceSpinBox->setMinimum(0.000000000000000);
        roomPriceSpinBox->setMaximum(99999999.000000000000000);
        roomPriceSpinBox->setSingleStep(100000.000000000000000);

        roomFormLayout->setWidget(2, QFormLayout::FieldRole, roomPriceSpinBox);

        roomStatusLabel = new QLabel(roomInfoGroup);
        roomStatusLabel->setObjectName(QString::fromUtf8("roomStatusLabel"));

        roomFormLayout->setWidget(3, QFormLayout::LabelRole, roomStatusLabel);

        roomStatusComboBox = new QComboBox(roomInfoGroup);
        roomStatusComboBox->addItem(QString());
        roomStatusComboBox->addItem(QString());
        roomStatusComboBox->addItem(QString());
        roomStatusComboBox->setObjectName(QString::fromUtf8("roomStatusComboBox"));

        roomFormLayout->setWidget(3, QFormLayout::FieldRole, roomStatusComboBox);

        roomDescLabel = new QLabel(roomInfoGroup);
        roomDescLabel->setObjectName(QString::fromUtf8("roomDescLabel"));

        roomFormLayout->setWidget(4, QFormLayout::LabelRole, roomDescLabel);

        roomDescEdit = new QLineEdit(roomInfoGroup);
        roomDescEdit->setObjectName(QString::fromUtf8("roomDescEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(roomDescEdit->sizePolicy().hasHeightForWidth());
        roomDescEdit->setSizePolicy(sizePolicy1);
        roomDescEdit->setMinimumSize(QSize(0, 42));

        roomFormLayout->setWidget(4, QFormLayout::FieldRole, roomDescEdit);


        roomControlsLayout->addWidget(roomInfoGroup);

        roomVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        roomControlsLayout->addItem(roomVerticalSpacer);

        roomButtonsLayout = new QVBoxLayout();
        roomButtonsLayout->setObjectName(QString::fromUtf8("roomButtonsLayout"));
        addRoomButton = new QPushButton(roomsTab);
        addRoomButton->setObjectName(QString::fromUtf8("addRoomButton"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addRoomButton->setIcon(icon24);

        roomButtonsLayout->addWidget(addRoomButton);

        editRoomButton = new QPushButton(roomsTab);
        editRoomButton->setObjectName(QString::fromUtf8("editRoomButton"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/icons/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        editRoomButton->setIcon(icon25);

        roomButtonsLayout->addWidget(editRoomButton);

        deleteRoomButton = new QPushButton(roomsTab);
        deleteRoomButton->setObjectName(QString::fromUtf8("deleteRoomButton"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteRoomButton->setIcon(icon26);

        roomButtonsLayout->addWidget(deleteRoomButton);


        roomControlsLayout->addLayout(roomButtonsLayout);


        roomsLayout->addLayout(roomControlsLayout);

        mainTabWidget->addTab(roomsTab, QString());
        tenantsTab = new QWidget();
        tenantsTab->setObjectName(QString::fromUtf8("tenantsTab"));
        tenantsLayout = new QHBoxLayout(tenantsTab);
        tenantsLayout->setObjectName(QString::fromUtf8("tenantsLayout"));
        tenantsTableView = new QTableView(tenantsTab);
        tenantsTableView->setObjectName(QString::fromUtf8("tenantsTableView"));
        tenantsTableView->setMinimumSize(QSize(600, 0));
        tenantsTableView->setAlternatingRowColors(true);
        tenantsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tenantsTableView->setSortingEnabled(true);

        tenantsLayout->addWidget(tenantsTableView);

        tenantControlsLayout = new QVBoxLayout();
        tenantControlsLayout->setObjectName(QString::fromUtf8("tenantControlsLayout"));
        tenantInfoGroup = new QGroupBox(tenantsTab);
        tenantInfoGroup->setObjectName(QString::fromUtf8("tenantInfoGroup"));
        tenantFormLayout = new QFormLayout(tenantInfoGroup);
        tenantFormLayout->setObjectName(QString::fromUtf8("tenantFormLayout"));
        tenantNameLabel = new QLabel(tenantInfoGroup);
        tenantNameLabel->setObjectName(QString::fromUtf8("tenantNameLabel"));

        tenantFormLayout->setWidget(1, QFormLayout::LabelRole, tenantNameLabel);

        tenantNameEdit = new QLineEdit(tenantInfoGroup);
        tenantNameEdit->setObjectName(QString::fromUtf8("tenantNameEdit"));

        tenantFormLayout->setWidget(1, QFormLayout::FieldRole, tenantNameEdit);

        tenantPhoneEdit = new QLineEdit(tenantInfoGroup);
        tenantPhoneEdit->setObjectName(QString::fromUtf8("tenantPhoneEdit"));

        tenantFormLayout->setWidget(4, QFormLayout::FieldRole, tenantPhoneEdit);

        tenantRoomLabel = new QLabel(tenantInfoGroup);
        tenantRoomLabel->setObjectName(QString::fromUtf8("tenantRoomLabel"));

        tenantFormLayout->setWidget(7, QFormLayout::LabelRole, tenantRoomLabel);

        tenantRoomComboBox = new QComboBox(tenantInfoGroup);
        tenantRoomComboBox->setObjectName(QString::fromUtf8("tenantRoomComboBox"));
        tenantRoomComboBox->setEditable(false);

        tenantFormLayout->setWidget(7, QFormLayout::FieldRole, tenantRoomComboBox);

        tenantPhoneLabel = new QLabel(tenantInfoGroup);
        tenantPhoneLabel->setObjectName(QString::fromUtf8("tenantPhoneLabel"));

        tenantFormLayout->setWidget(4, QFormLayout::LabelRole, tenantPhoneLabel);

        tenantIdEdit = new QLineEdit(tenantInfoGroup);
        tenantIdEdit->setObjectName(QString::fromUtf8("tenantIdEdit"));

        tenantFormLayout->setWidget(2, QFormLayout::FieldRole, tenantIdEdit);

        tenantIdLabel = new QLabel(tenantInfoGroup);
        tenantIdLabel->setObjectName(QString::fromUtf8("tenantIdLabel"));

        tenantFormLayout->setWidget(2, QFormLayout::LabelRole, tenantIdLabel);

        dateOfBirth = new QDateEdit(tenantInfoGroup);
        dateOfBirth->setObjectName(QString::fromUtf8("dateOfBirth"));

        tenantFormLayout->setWidget(8, QFormLayout::FieldRole, dateOfBirth);

        label = new QLabel(tenantInfoGroup);
        label->setObjectName(QString::fromUtf8("label"));

        tenantFormLayout->setWidget(8, QFormLayout::LabelRole, label);


        tenantControlsLayout->addWidget(tenantInfoGroup);

        tenantVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tenantControlsLayout->addItem(tenantVerticalSpacer);

        tenantButtonsLayout = new QVBoxLayout();
        tenantButtonsLayout->setObjectName(QString::fromUtf8("tenantButtonsLayout"));
        addTenantButton = new QPushButton(tenantsTab);
        addTenantButton->setObjectName(QString::fromUtf8("addTenantButton"));
        addTenantButton->setIcon(icon24);

        tenantButtonsLayout->addWidget(addTenantButton);

        editTenantButton = new QPushButton(tenantsTab);
        editTenantButton->setObjectName(QString::fromUtf8("editTenantButton"));
        editTenantButton->setIcon(icon25);

        tenantButtonsLayout->addWidget(editTenantButton);

        deleteTenantButton = new QPushButton(tenantsTab);
        deleteTenantButton->setObjectName(QString::fromUtf8("deleteTenantButton"));
        deleteTenantButton->setIcon(icon26);

        tenantButtonsLayout->addWidget(deleteTenantButton);


        tenantControlsLayout->addLayout(tenantButtonsLayout);


        tenantsLayout->addLayout(tenantControlsLayout);

        mainTabWidget->addTab(tenantsTab, QString());
        contractsTab = new QWidget();
        contractsTab->setObjectName(QString::fromUtf8("contractsTab"));
        contractsLayout = new QHBoxLayout(contractsTab);
        contractsLayout->setObjectName(QString::fromUtf8("contractsLayout"));
        contractsTableView = new QTableView(contractsTab);
        contractsTableView->setObjectName(QString::fromUtf8("contractsTableView"));
        contractsTableView->setMinimumSize(QSize(600, 0));
        contractsTableView->setAlternatingRowColors(true);
        contractsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        contractsTableView->setSortingEnabled(true);

        contractsLayout->addWidget(contractsTableView);

        contractControlsLayout = new QVBoxLayout();
        contractControlsLayout->setObjectName(QString::fromUtf8("contractControlsLayout"));
        contractInfoGroup = new QGroupBox(contractsTab);
        contractInfoGroup->setObjectName(QString::fromUtf8("contractInfoGroup"));
        contractFormLayout = new QFormLayout(contractInfoGroup);
        contractFormLayout->setObjectName(QString::fromUtf8("contractFormLayout"));
        contractTenantLabel = new QLabel(contractInfoGroup);
        contractTenantLabel->setObjectName(QString::fromUtf8("contractTenantLabel"));

        contractFormLayout->setWidget(0, QFormLayout::LabelRole, contractTenantLabel);

        contractTenantComboBox = new QComboBox(contractInfoGroup);
        contractTenantComboBox->setObjectName(QString::fromUtf8("contractTenantComboBox"));
        contractTenantComboBox->setEditable(false);

        contractFormLayout->setWidget(0, QFormLayout::FieldRole, contractTenantComboBox);

        contractRoomLabel = new QLabel(contractInfoGroup);
        contractRoomLabel->setObjectName(QString::fromUtf8("contractRoomLabel"));

        contractFormLayout->setWidget(1, QFormLayout::LabelRole, contractRoomLabel);

        contractRoomComboBox = new QComboBox(contractInfoGroup);
        contractRoomComboBox->setObjectName(QString::fromUtf8("contractRoomComboBox"));
        contractRoomComboBox->setEditable(false);

        contractFormLayout->setWidget(1, QFormLayout::FieldRole, contractRoomComboBox);

        contractStartDateLabel = new QLabel(contractInfoGroup);
        contractStartDateLabel->setObjectName(QString::fromUtf8("contractStartDateLabel"));

        contractFormLayout->setWidget(2, QFormLayout::LabelRole, contractStartDateLabel);

        contractStartDateEdit = new QDateEdit(contractInfoGroup);
        contractStartDateEdit->setObjectName(QString::fromUtf8("contractStartDateEdit"));
        contractStartDateEdit->setCalendarPopup(true);

        contractFormLayout->setWidget(2, QFormLayout::FieldRole, contractStartDateEdit);

        contractEndDateLabel = new QLabel(contractInfoGroup);
        contractEndDateLabel->setObjectName(QString::fromUtf8("contractEndDateLabel"));

        contractFormLayout->setWidget(3, QFormLayout::LabelRole, contractEndDateLabel);

        contractEndDateEdit = new QDateEdit(contractInfoGroup);
        contractEndDateEdit->setObjectName(QString::fromUtf8("contractEndDateEdit"));
        contractEndDateEdit->setCalendarPopup(true);

        contractFormLayout->setWidget(3, QFormLayout::FieldRole, contractEndDateEdit);

        contractDepositLabel = new QLabel(contractInfoGroup);
        contractDepositLabel->setObjectName(QString::fromUtf8("contractDepositLabel"));

        contractFormLayout->setWidget(4, QFormLayout::LabelRole, contractDepositLabel);

        contractDepositSpinBox = new QDoubleSpinBox(contractInfoGroup);
        contractDepositSpinBox->setObjectName(QString::fromUtf8("contractDepositSpinBox"));
        contractDepositSpinBox->setDecimals(0);
        contractDepositSpinBox->setMaximum(99999999.000000000000000);
        contractDepositSpinBox->setSingleStep(100000.000000000000000);

        contractFormLayout->setWidget(4, QFormLayout::FieldRole, contractDepositSpinBox);

        contractStatusLabel = new QLabel(contractInfoGroup);
        contractStatusLabel->setObjectName(QString::fromUtf8("contractStatusLabel"));

        contractFormLayout->setWidget(5, QFormLayout::LabelRole, contractStatusLabel);

        contractStatusComboBox = new QComboBox(contractInfoGroup);
        contractStatusComboBox->addItem(QString());
        contractStatusComboBox->addItem(QString());
        contractStatusComboBox->addItem(QString());
        contractStatusComboBox->addItem(QString());
        contractStatusComboBox->setObjectName(QString::fromUtf8("contractStatusComboBox"));

        contractFormLayout->setWidget(5, QFormLayout::FieldRole, contractStatusComboBox);


        contractControlsLayout->addWidget(contractInfoGroup);

        contractVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        contractControlsLayout->addItem(contractVerticalSpacer);

        contractButtonsLayout = new QVBoxLayout();
        contractButtonsLayout->setObjectName(QString::fromUtf8("contractButtonsLayout"));
        addContractButton = new QPushButton(contractsTab);
        addContractButton->setObjectName(QString::fromUtf8("addContractButton"));
        addContractButton->setIcon(icon24);

        contractButtonsLayout->addWidget(addContractButton);

        editContractButton = new QPushButton(contractsTab);
        editContractButton->setObjectName(QString::fromUtf8("editContractButton"));
        editContractButton->setIcon(icon25);

        contractButtonsLayout->addWidget(editContractButton);

        terminateContractButton = new QPushButton(contractsTab);
        terminateContractButton->setObjectName(QString::fromUtf8("terminateContractButton"));
        terminateContractButton->setIcon(icon26);

        contractButtonsLayout->addWidget(terminateContractButton);


        contractControlsLayout->addLayout(contractButtonsLayout);


        contractsLayout->addLayout(contractControlsLayout);

        mainTabWidget->addTab(contractsTab, QString());
        paymentsTab = new QWidget();
        paymentsTab->setObjectName(QString::fromUtf8("paymentsTab"));
        paymentsLayout = new QHBoxLayout(paymentsTab);
        paymentsLayout->setObjectName(QString::fromUtf8("paymentsLayout"));
        paymentsTableView = new QTableView(paymentsTab);
        paymentsTableView->setObjectName(QString::fromUtf8("paymentsTableView"));
        paymentsTableView->setMinimumSize(QSize(600, 0));
        paymentsTableView->setAlternatingRowColors(true);
        paymentsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        paymentsTableView->setSortingEnabled(true);

        paymentsLayout->addWidget(paymentsTableView);

        paymentControlsLayout = new QVBoxLayout();
        paymentControlsLayout->setObjectName(QString::fromUtf8("paymentControlsLayout"));
        paymentInfoGroup = new QGroupBox(paymentsTab);
        paymentInfoGroup->setObjectName(QString::fromUtf8("paymentInfoGroup"));
        paymentFormLayout = new QFormLayout(paymentInfoGroup);
        paymentFormLayout->setObjectName(QString::fromUtf8("paymentFormLayout"));
        paymentRoomLabel = new QLabel(paymentInfoGroup);
        paymentRoomLabel->setObjectName(QString::fromUtf8("paymentRoomLabel"));

        paymentFormLayout->setWidget(0, QFormLayout::LabelRole, paymentRoomLabel);

        paymentRoomComboBox = new QComboBox(paymentInfoGroup);
        paymentRoomComboBox->setObjectName(QString::fromUtf8("paymentRoomComboBox"));

        paymentFormLayout->setWidget(0, QFormLayout::FieldRole, paymentRoomComboBox);

        paymentMonthLabel = new QLabel(paymentInfoGroup);
        paymentMonthLabel->setObjectName(QString::fromUtf8("paymentMonthLabel"));

        paymentFormLayout->setWidget(1, QFormLayout::LabelRole, paymentMonthLabel);

        paymentMonthEdit = new QDateEdit(paymentInfoGroup);
        paymentMonthEdit->setObjectName(QString::fromUtf8("paymentMonthEdit"));
        paymentMonthEdit->setCalendarPopup(true);

        paymentFormLayout->setWidget(1, QFormLayout::FieldRole, paymentMonthEdit);

        rentAmountLabel = new QLabel(paymentInfoGroup);
        rentAmountLabel->setObjectName(QString::fromUtf8("rentAmountLabel"));

        paymentFormLayout->setWidget(2, QFormLayout::LabelRole, rentAmountLabel);

        rentAmountSpinBox = new QDoubleSpinBox(paymentInfoGroup);
        rentAmountSpinBox->setObjectName(QString::fromUtf8("rentAmountSpinBox"));
        rentAmountSpinBox->setDecimals(0);
        rentAmountSpinBox->setMaximum(99999999.000000000000000);
        rentAmountSpinBox->setSingleStep(100000.000000000000000);

        paymentFormLayout->setWidget(2, QFormLayout::FieldRole, rentAmountSpinBox);

        electricBillLabel = new QLabel(paymentInfoGroup);
        electricBillLabel->setObjectName(QString::fromUtf8("electricBillLabel"));

        paymentFormLayout->setWidget(3, QFormLayout::LabelRole, electricBillLabel);

        electricBillSpinBox = new QDoubleSpinBox(paymentInfoGroup);
        electricBillSpinBox->setObjectName(QString::fromUtf8("electricBillSpinBox"));
        electricBillSpinBox->setDecimals(0);
        electricBillSpinBox->setMaximum(99999999.000000000000000);
        electricBillSpinBox->setSingleStep(10000.000000000000000);

        paymentFormLayout->setWidget(3, QFormLayout::FieldRole, electricBillSpinBox);

        waterBillLabel = new QLabel(paymentInfoGroup);
        waterBillLabel->setObjectName(QString::fromUtf8("waterBillLabel"));

        paymentFormLayout->setWidget(4, QFormLayout::LabelRole, waterBillLabel);

        waterBillSpinBox = new QDoubleSpinBox(paymentInfoGroup);
        waterBillSpinBox->setObjectName(QString::fromUtf8("waterBillSpinBox"));
        waterBillSpinBox->setDecimals(0);
        waterBillSpinBox->setMaximum(99999999.000000000000000);
        waterBillSpinBox->setSingleStep(10000.000000000000000);

        paymentFormLayout->setWidget(4, QFormLayout::FieldRole, waterBillSpinBox);

        internetBillLabel = new QLabel(paymentInfoGroup);
        internetBillLabel->setObjectName(QString::fromUtf8("internetBillLabel"));

        paymentFormLayout->setWidget(5, QFormLayout::LabelRole, internetBillLabel);

        internetBillSpinBox = new QDoubleSpinBox(paymentInfoGroup);
        internetBillSpinBox->setObjectName(QString::fromUtf8("internetBillSpinBox"));
        internetBillSpinBox->setDecimals(0);
        internetBillSpinBox->setMaximum(99999999.000000000000000);
        internetBillSpinBox->setSingleStep(10000.000000000000000);

        paymentFormLayout->setWidget(5, QFormLayout::FieldRole, internetBillSpinBox);

        paymentStatusLabel = new QLabel(paymentInfoGroup);
        paymentStatusLabel->setObjectName(QString::fromUtf8("paymentStatusLabel"));

        paymentFormLayout->setWidget(6, QFormLayout::LabelRole, paymentStatusLabel);

        paymentStatusComboBox = new QComboBox(paymentInfoGroup);
        paymentStatusComboBox->addItem(QString());
        paymentStatusComboBox->addItem(QString());
        paymentStatusComboBox->addItem(QString());
        paymentStatusComboBox->addItem(QString());
        paymentStatusComboBox->setObjectName(QString::fromUtf8("paymentStatusComboBox"));

        paymentFormLayout->setWidget(6, QFormLayout::FieldRole, paymentStatusComboBox);


        paymentControlsLayout->addWidget(paymentInfoGroup);

        paymentVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        paymentControlsLayout->addItem(paymentVerticalSpacer);

        paymentButtonsLayout = new QVBoxLayout();
        paymentButtonsLayout->setObjectName(QString::fromUtf8("paymentButtonsLayout"));
        addPaymentButton = new QPushButton(paymentsTab);
        addPaymentButton->setObjectName(QString::fromUtf8("addPaymentButton"));
        addPaymentButton->setIcon(icon24);

        paymentButtonsLayout->addWidget(addPaymentButton);

        editPaymentButton = new QPushButton(paymentsTab);
        editPaymentButton->setObjectName(QString::fromUtf8("editPaymentButton"));
        editPaymentButton->setIcon(icon25);

        paymentButtonsLayout->addWidget(editPaymentButton);

        printInvoiceButton = new QPushButton(paymentsTab);
        printInvoiceButton->setObjectName(QString::fromUtf8("printInvoiceButton"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/icons/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printInvoiceButton->setIcon(icon27);

        paymentButtonsLayout->addWidget(printInvoiceButton);


        paymentControlsLayout->addLayout(paymentButtonsLayout);


        paymentsLayout->addLayout(paymentControlsLayout);

        mainTabWidget->addTab(paymentsTab, QString());
        reportsTab = new QWidget();
        reportsTab->setObjectName(QString::fromUtf8("reportsTab"));
        reportsMainLayout = new QVBoxLayout(reportsTab);
        reportsMainLayout->setObjectName(QString::fromUtf8("reportsMainLayout"));
        reportsFilterLayout = new QHBoxLayout();
        reportsFilterLayout->setObjectName(QString::fromUtf8("reportsFilterLayout"));
        filterGroup = new QGroupBox(reportsTab);
        filterGroup->setObjectName(QString::fromUtf8("filterGroup"));
        filterLayout = new QHBoxLayout(filterGroup);
        filterLayout->setObjectName(QString::fromUtf8("filterLayout"));
        fromDateLabel = new QLabel(filterGroup);
        fromDateLabel->setObjectName(QString::fromUtf8("fromDateLabel"));

        filterLayout->addWidget(fromDateLabel);

        fromDateEdit = new QDateEdit(filterGroup);
        fromDateEdit->setObjectName(QString::fromUtf8("fromDateEdit"));
        fromDateEdit->setCalendarPopup(true);

        filterLayout->addWidget(fromDateEdit);

        toDateLabel = new QLabel(filterGroup);
        toDateLabel->setObjectName(QString::fromUtf8("toDateLabel"));

        filterLayout->addWidget(toDateLabel);

        toDateEdit = new QDateEdit(filterGroup);
        toDateEdit->setObjectName(QString::fromUtf8("toDateEdit"));
        toDateEdit->setCalendarPopup(true);

        filterLayout->addWidget(toDateEdit);

        generateReportButton = new QPushButton(filterGroup);
        generateReportButton->setObjectName(QString::fromUtf8("generateReportButton"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/icons/report.png"), QSize(), QIcon::Normal, QIcon::Off);
        generateReportButton->setIcon(icon28);

        filterLayout->addWidget(generateReportButton);

        filterHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        filterLayout->addItem(filterHorizontalSpacer);


        reportsFilterLayout->addWidget(filterGroup);


        reportsMainLayout->addLayout(reportsFilterLayout);

        reportsContentLayout = new QHBoxLayout();
        reportsContentLayout->setObjectName(QString::fromUtf8("reportsContentLayout"));
        summaryGroup = new QGroupBox(reportsTab);
        summaryGroup->setObjectName(QString::fromUtf8("summaryGroup"));
        summaryLayout = new QFormLayout(summaryGroup);
        summaryLayout->setObjectName(QString::fromUtf8("summaryLayout"));
        totalRoomsLabel = new QLabel(summaryGroup);
        totalRoomsLabel->setObjectName(QString::fromUtf8("totalRoomsLabel"));

        summaryLayout->setWidget(0, QFormLayout::LabelRole, totalRoomsLabel);

        totalRoomsValue = new QLabel(summaryGroup);
        totalRoomsValue->setObjectName(QString::fromUtf8("totalRoomsValue"));
        totalRoomsValue->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #007bff;"));

        summaryLayout->setWidget(0, QFormLayout::FieldRole, totalRoomsValue);

        occupiedRoomsLabel = new QLabel(summaryGroup);
        occupiedRoomsLabel->setObjectName(QString::fromUtf8("occupiedRoomsLabel"));

        summaryLayout->setWidget(1, QFormLayout::LabelRole, occupiedRoomsLabel);

        occupiedRoomsValue = new QLabel(summaryGroup);
        occupiedRoomsValue->setObjectName(QString::fromUtf8("occupiedRoomsValue"));
        occupiedRoomsValue->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #28a745;"));

        summaryLayout->setWidget(1, QFormLayout::FieldRole, occupiedRoomsValue);

        emptyRoomsLabel = new QLabel(summaryGroup);
        emptyRoomsLabel->setObjectName(QString::fromUtf8("emptyRoomsLabel"));

        summaryLayout->setWidget(2, QFormLayout::LabelRole, emptyRoomsLabel);

        emptyRoomsValue = new QLabel(summaryGroup);
        emptyRoomsValue->setObjectName(QString::fromUtf8("emptyRoomsValue"));
        emptyRoomsValue->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #ffc107;"));

        summaryLayout->setWidget(2, QFormLayout::FieldRole, emptyRoomsValue);

        totalRevenueLabel = new QLabel(summaryGroup);
        totalRevenueLabel->setObjectName(QString::fromUtf8("totalRevenueLabel"));

        summaryLayout->setWidget(3, QFormLayout::LabelRole, totalRevenueLabel);

        totalRevenueValue = new QLabel(summaryGroup);
        totalRevenueValue->setObjectName(QString::fromUtf8("totalRevenueValue"));
        totalRevenueValue->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #007bff; font-size: 14px;"));

        summaryLayout->setWidget(3, QFormLayout::FieldRole, totalRevenueValue);

        unpaidBillsLabel = new QLabel(summaryGroup);
        unpaidBillsLabel->setObjectName(QString::fromUtf8("unpaidBillsLabel"));

        summaryLayout->setWidget(4, QFormLayout::LabelRole, unpaidBillsLabel);

        unpaidBillsValue = new QLabel(summaryGroup);
        unpaidBillsValue->setObjectName(QString::fromUtf8("unpaidBillsValue"));
        unpaidBillsValue->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #dc3545;"));

        summaryLayout->setWidget(4, QFormLayout::FieldRole, unpaidBillsValue);


        reportsContentLayout->addWidget(summaryGroup);

        reportsTableView = new QTableView(reportsTab);
        reportsTableView->setObjectName(QString::fromUtf8("reportsTableView"));
        reportsTableView->setAlternatingRowColors(true);
        reportsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        reportsTableView->setSortingEnabled(true);

        reportsContentLayout->addWidget(reportsTableView);


        reportsMainLayout->addLayout(reportsContentLayout);

        mainTabWidget->addTab(reportsTab, QString());

        mainVerticalLayout->addWidget(mainTabWidget);

        AdminMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 54));
        menubar->setLayoutDirection(Qt::LeftToRight);
        menubar->setAutoFillBackground(false);
        menubar->setDefaultUp(false);
        menubar->setNativeMenuBar(true);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuManagement = new QMenu(menubar);
        menuManagement->setObjectName(QString::fromUtf8("menuManagement"));
        menuReports = new QMenu(menubar);
        menuReports->setObjectName(QString::fromUtf8("menuReports"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        AdminMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusInfoLabel = new QLabel(statusbar);
        statusInfoLabel->setObjectName(QString::fromUtf8("statusInfoLabel"));
        statusInfoLabel->setGeometry(QRect(0, 0, 200, 30));
        dateTimeLabel = new QLabel(statusbar);
        dateTimeLabel->setObjectName(QString::fromUtf8("dateTimeLabel"));
        dateTimeLabel->setGeometry(QRect(900, 0, 200, 30));
        dateTimeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        AdminMainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(AdminMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMaximumSize(QSize(16777215, 80));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextOnly);
        AdminMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuManagement->menuAction());
        menubar->addAction(menuReports->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewProject);
        menuFile->addAction(actionOpenProject);
        menuFile->addAction(actionSaveProject);
        menuFile->addSeparator();
        menuFile->addAction(actionBackupData);
        menuFile->addAction(actionRestoreData);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuManagement->addAction(actionRoomManagement);
        menuManagement->addAction(actionTenantManagement);
        menuManagement->addAction(actionContractManagement);
        menuManagement->addAction(actionPaymentManagement);
        menuManagement->addSeparator();
        menuManagement->addAction(actionSettings);
        menuReports->addAction(actionFinancialReport);
        menuReports->addAction(actionOccupancyReport);
        menuReports->addAction(actionPaymentReport);
        menuReports->addSeparator();
        menuReports->addAction(actionExportData);
        menuHelp->addAction(actionUserManual);
        menuHelp->addAction(actionContactSupport);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionQuickAddRoom);
        toolBar->addAction(actionQuickAddTenant);
        toolBar->addAction(actionQuickAddContract);
        toolBar->addAction(actionQuickSearch);
        toolBar->addSeparator();
        toolBar->addAction(actionRefresh);
        toolBar->addAction(actionBackup);

        retranslateUi(AdminMainWindow);

        mainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AdminMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMainWindow)
    {
        AdminMainWindow->setWindowTitle(QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n L\303\275 Ph\303\262ng Tr\341\273\215 - Admin", nullptr));
        actionNewProject->setText(QCoreApplication::translate("AdminMainWindow", "&D\341\273\261 \303\241n m\341\273\233i", nullptr));
#if QT_CONFIG(statustip)
        actionNewProject->setStatusTip(QCoreApplication::translate("AdminMainWindow", "T\341\272\241o d\341\273\261 \303\241n qu\341\272\243n l\303\275 m\341\273\233i", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionNewProject->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpenProject->setText(QCoreApplication::translate("AdminMainWindow", "&M\341\273\237 d\341\273\261 \303\241n", nullptr));
#if QT_CONFIG(statustip)
        actionOpenProject->setStatusTip(QCoreApplication::translate("AdminMainWindow", "M\341\273\237 d\341\273\261 \303\241n qu\341\272\243n l\303\275 c\303\263 s\341\272\265n", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionOpenProject->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveProject->setText(QCoreApplication::translate("AdminMainWindow", "&L\306\260u d\341\273\261 \303\241n", nullptr));
#if QT_CONFIG(statustip)
        actionSaveProject->setStatusTip(QCoreApplication::translate("AdminMainWindow", "L\306\260u d\341\273\261 \303\241n hi\341\273\207n t\341\272\241i", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionSaveProject->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBackupData->setText(QCoreApplication::translate("AdminMainWindow", "Sao l\306\260u d\341\273\257 li\341\273\207u", nullptr));
#if QT_CONFIG(statustip)
        actionBackupData->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Sao l\306\260u to\303\240n b\341\273\231 d\341\273\257 li\341\273\207u", nullptr));
#endif // QT_CONFIG(statustip)
        actionRestoreData->setText(QCoreApplication::translate("AdminMainWindow", "Kh\303\264i ph\341\273\245c d\341\273\257 li\341\273\207u", nullptr));
#if QT_CONFIG(statustip)
        actionRestoreData->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Kh\303\264i ph\341\273\245c d\341\273\257 li\341\273\207u t\341\273\253 b\341\272\243n sao l\306\260u", nullptr));
#endif // QT_CONFIG(statustip)
        actionExit->setText(QCoreApplication::translate("AdminMainWindow", "T&ho\303\241t", nullptr));
#if QT_CONFIG(statustip)
        actionExit->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Tho\303\241t \341\273\251ng d\341\273\245ng", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("AdminMainWindow", "Alt+F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRoomManagement->setText(QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n l\303\275 &Ph\303\262ng", nullptr));
#if QT_CONFIG(statustip)
        actionRoomManagement->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Chuy\341\273\203n \304\221\341\272\277n tab qu\341\272\243n l\303\275 ph\303\262ng", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionRoomManagement->setShortcut(QCoreApplication::translate("AdminMainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTenantManagement->setText(QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n l\303\275 &Kh\303\241ch thu\303\252", nullptr));
#if QT_CONFIG(statustip)
        actionTenantManagement->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Chuy\341\273\203n \304\221\341\272\277n tab qu\341\272\243n l\303\275 kh\303\241ch thu\303\252", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionTenantManagement->setShortcut(QCoreApplication::translate("AdminMainWindow", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionContractManagement->setText(QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n l\303\275 &H\341\273\243p \304\221\341\273\223ng", nullptr));
#if QT_CONFIG(statustip)
        actionContractManagement->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Chuy\341\273\203n \304\221\341\272\277n tab qu\341\272\243n l\303\275 h\341\273\243p \304\221\341\273\223ng thu\303\252", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionContractManagement->setShortcut(QCoreApplication::translate("AdminMainWindow", "F3", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaymentManagement->setText(QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n l\303\275 &Thanh to\303\241n", nullptr));
#if QT_CONFIG(statustip)
        actionPaymentManagement->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Chuy\341\273\203n \304\221\341\272\277n tab qu\341\272\243n l\303\275 thanh to\303\241n", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionPaymentManagement->setShortcut(QCoreApplication::translate("AdminMainWindow", "F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSettings->setText(QCoreApplication::translate("AdminMainWindow", "&C\303\240i \304\221\341\272\267t", nullptr));
#if QT_CONFIG(statustip)
        actionSettings->setStatusTip(QCoreApplication::translate("AdminMainWindow", "M\341\273\237 c\303\240i \304\221\341\272\267t \341\273\251ng d\341\273\245ng", nullptr));
#endif // QT_CONFIG(statustip)
        actionFinancialReport->setText(QCoreApplication::translate("AdminMainWindow", "B\303\241o c\303\241o &T\303\240i ch\303\255nh", nullptr));
#if QT_CONFIG(statustip)
        actionFinancialReport->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Xem b\303\241o c\303\241o t\303\240i ch\303\255nh", nullptr));
#endif // QT_CONFIG(statustip)
        actionOccupancyReport->setText(QCoreApplication::translate("AdminMainWindow", "B\303\241o c\303\241o &L\306\260u tr\303\272", nullptr));
#if QT_CONFIG(statustip)
        actionOccupancyReport->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Xem b\303\241o c\303\241o t\303\254nh h\303\254nh l\306\260u tr\303\272", nullptr));
#endif // QT_CONFIG(statustip)
        actionPaymentReport->setText(QCoreApplication::translate("AdminMainWindow", "B\303\241o c\303\241o Thanh &to\303\241n", nullptr));
#if QT_CONFIG(statustip)
        actionPaymentReport->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Xem b\303\241o c\303\241o thanh to\303\241n", nullptr));
#endif // QT_CONFIG(statustip)
        actionExportData->setText(QCoreApplication::translate("AdminMainWindow", "&Xu\341\272\245t d\341\273\257 li\341\273\207u", nullptr));
#if QT_CONFIG(statustip)
        actionExportData->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Xu\341\272\245t d\341\273\257 li\341\273\207u ra file Excel", nullptr));
#endif // QT_CONFIG(statustip)
        actionUserManual->setText(QCoreApplication::translate("AdminMainWindow", "&H\306\260\341\273\233ng d\341\272\253n s\341\273\255 d\341\273\245ng", nullptr));
#if QT_CONFIG(statustip)
        actionUserManual->setStatusTip(QCoreApplication::translate("AdminMainWindow", "M\341\273\237 h\306\260\341\273\233ng d\341\272\253n s\341\273\255 d\341\273\245ng", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionUserManual->setShortcut(QCoreApplication::translate("AdminMainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionContactSupport->setText(QCoreApplication::translate("AdminMainWindow", "&Li\303\252n h\341\273\207 h\341\273\227 tr\341\273\243", nullptr));
#if QT_CONFIG(statustip)
        actionContactSupport->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Li\303\252n h\341\273\207 b\341\273\231 ph\341\272\255n h\341\273\227 tr\341\273\243", nullptr));
#endif // QT_CONFIG(statustip)
        actionAbout->setText(QCoreApplication::translate("AdminMainWindow", "&Gi\341\273\233i thi\341\273\207u", nullptr));
#if QT_CONFIG(statustip)
        actionAbout->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Th\303\264ng tin v\341\273\201 \341\273\251ng d\341\273\245ng", nullptr));
#endif // QT_CONFIG(statustip)
        actionQuickAddRoom->setText(QCoreApplication::translate("AdminMainWindow", "Th\303\252m Ph\303\262ng", nullptr));
#if QT_CONFIG(statustip)
        actionQuickAddRoom->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Th\303\252m ph\303\262ng m\341\273\233i nhanh", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionQuickAddRoom->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuickAddTenant->setText(QCoreApplication::translate("AdminMainWindow", "Th\303\252m Kh\303\241ch", nullptr));
#if QT_CONFIG(statustip)
        actionQuickAddTenant->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Th\303\252m kh\303\241ch thu\303\252 m\341\273\233i nhanh", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionQuickAddTenant->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuickAddContract->setText(QCoreApplication::translate("AdminMainWindow", "T\341\272\241o H\341\273\243p \304\220\341\273\223ng", nullptr));
#if QT_CONFIG(statustip)
        actionQuickAddContract->setStatusTip(QCoreApplication::translate("AdminMainWindow", "T\341\272\241o h\341\273\243p \304\221\341\273\223ng thu\303\252 m\341\273\233i nhanh", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionQuickAddContract->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuickSearch->setText(QCoreApplication::translate("AdminMainWindow", "T\303\254m Ki\341\272\277m", nullptr));
#if QT_CONFIG(statustip)
        actionQuickSearch->setStatusTip(QCoreApplication::translate("AdminMainWindow", "T\303\254m ki\341\272\277m nhanh", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionQuickSearch->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRefresh->setText(QCoreApplication::translate("AdminMainWindow", "L\303\240m M\341\273\233i", nullptr));
#if QT_CONFIG(statustip)
        actionRefresh->setStatusTip(QCoreApplication::translate("AdminMainWindow", "L\303\240m m\341\273\233i d\341\273\257 li\341\273\207u", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionRefresh->setShortcut(QCoreApplication::translate("AdminMainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBackup->setText(QCoreApplication::translate("AdminMainWindow", "Sao L\306\260u", nullptr));
#if QT_CONFIG(statustip)
        actionBackup->setStatusTip(QCoreApplication::translate("AdminMainWindow", "Sao l\306\260u d\341\273\257 li\341\273\207u nhanh", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        actionBackup->setShortcut(QCoreApplication::translate("AdminMainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        roomInfoGroup->setTitle(QCoreApplication::translate("AdminMainWindow", "Th\303\264ng Tin Ph\303\262ng", nullptr));
        roomNumberLabel->setText(QCoreApplication::translate("AdminMainWindow", "S\341\273\221 Ph\303\262ng:", nullptr));
        roomNumberEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "Nh\341\272\255p s\341\273\221 ph\303\262ng...", nullptr));
        roomTypeLabel->setText(QCoreApplication::translate("AdminMainWindow", "Lo\341\272\241i Ph\303\262ng:", nullptr));
        roomTypeComboBox->setItemText(0, QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng \304\221\306\241n", nullptr));
        roomTypeComboBox->setItemText(1, QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng \304\221\303\264i", nullptr));
        roomTypeComboBox->setItemText(2, QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng gia \304\221\303\254nh", nullptr));
        roomTypeComboBox->setItemText(3, QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng VIP", nullptr));

        roomPriceLabel->setText(QCoreApplication::translate("AdminMainWindow", "Gi\303\241 Ph\303\262ng:", nullptr));
        roomPriceSpinBox->setSuffix(QCoreApplication::translate("AdminMainWindow", " VND", nullptr));
        roomStatusLabel->setText(QCoreApplication::translate("AdminMainWindow", "Tr\341\272\241ng Th\303\241i:", nullptr));
        roomStatusComboBox->setItemText(0, QCoreApplication::translate("AdminMainWindow", "Tr\341\273\221ng", nullptr));
        roomStatusComboBox->setItemText(1, QCoreApplication::translate("AdminMainWindow", "\304\220\303\243 thu\303\252", nullptr));
        roomStatusComboBox->setItemText(2, QCoreApplication::translate("AdminMainWindow", "B\341\272\243o tr\303\254", nullptr));

        roomDescLabel->setText(QCoreApplication::translate("AdminMainWindow", "M\303\264 T\341\272\243:", nullptr));
        roomDescEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "M\303\264 t\341\272\243 ph\303\262ng...", nullptr));
        addRoomButton->setText(QCoreApplication::translate("AdminMainWindow", "Th\303\252m Ph\303\262ng", nullptr));
        editRoomButton->setText(QCoreApplication::translate("AdminMainWindow", "S\341\273\255a Ph\303\262ng", nullptr));
        deleteRoomButton->setText(QCoreApplication::translate("AdminMainWindow", "X\303\263a Ph\303\262ng", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(roomsTab), QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n L\303\275 Ph\303\262ng", nullptr));
        tenantInfoGroup->setTitle(QCoreApplication::translate("AdminMainWindow", "Th\303\264ng Tin Kh\303\241ch Thu\303\252", nullptr));
        tenantNameLabel->setText(QCoreApplication::translate("AdminMainWindow", "H\341\273\215 T\303\252n:", nullptr));
        tenantNameEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "Nh\341\272\255p h\341\273\215 t\303\252n...", nullptr));
        tenantPhoneEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "Nh\341\272\255p s\341\273\221 \304\221i\341\273\207n tho\341\272\241i...", nullptr));
        tenantRoomLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng:", nullptr));
        tenantPhoneLabel->setText(QCoreApplication::translate("AdminMainWindow", "S\341\273\221 \304\220i\341\273\207n Tho\341\272\241i:", nullptr));
        tenantIdEdit->setPlaceholderText(QCoreApplication::translate("AdminMainWindow", "Nh\341\272\255p CCCD...", nullptr));
        tenantIdLabel->setText(QCoreApplication::translate("AdminMainWindow", "CMND/CCCD:", nullptr));
        label->setText(QCoreApplication::translate("AdminMainWindow", "Ng\303\240y Sinh", nullptr));
        addTenantButton->setText(QCoreApplication::translate("AdminMainWindow", "Th\303\252m Kh\303\241ch", nullptr));
        editTenantButton->setText(QCoreApplication::translate("AdminMainWindow", "S\341\273\255a Th\303\264ng Tin", nullptr));
        deleteTenantButton->setText(QCoreApplication::translate("AdminMainWindow", "X\303\263a Kh\303\241ch", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(tenantsTab), QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n L\303\275 Kh\303\241ch Thu\303\252", nullptr));
        contractInfoGroup->setTitle(QCoreApplication::translate("AdminMainWindow", "Th\303\264ng Tin H\341\273\243p \304\220\341\273\223ng", nullptr));
        contractTenantLabel->setText(QCoreApplication::translate("AdminMainWindow", "Kh\303\241ch Thu\303\252:", nullptr));
        contractRoomLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng:", nullptr));
        contractStartDateLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ng\303\240y B\341\272\257t \304\220\341\272\247u:", nullptr));
        contractEndDateLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ng\303\240y K\341\272\277t Th\303\272c:", nullptr));
        contractDepositLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ti\341\273\201n C\341\273\215c:", nullptr));
        contractDepositSpinBox->setSuffix(QCoreApplication::translate("AdminMainWindow", " VND", nullptr));
        contractStatusLabel->setText(QCoreApplication::translate("AdminMainWindow", "Tr\341\272\241ng Th\303\241i:", nullptr));
        contractStatusComboBox->setItemText(0, QCoreApplication::translate("AdminMainWindow", "\304\220ang hi\341\273\207u l\341\273\261c", nullptr));
        contractStatusComboBox->setItemText(1, QCoreApplication::translate("AdminMainWindow", "H\341\272\277t h\341\272\241n", nullptr));
        contractStatusComboBox->setItemText(2, QCoreApplication::translate("AdminMainWindow", "\304\220\303\243 h\341\273\247y", nullptr));
        contractStatusComboBox->setItemText(3, QCoreApplication::translate("AdminMainWindow", "T\341\272\241m ng\306\260ng", nullptr));

        addContractButton->setText(QCoreApplication::translate("AdminMainWindow", "T\341\272\241o H\341\273\243p \304\220\341\273\223ng", nullptr));
        editContractButton->setText(QCoreApplication::translate("AdminMainWindow", "S\341\273\255a H\341\273\243p \304\220\341\273\223ng", nullptr));
        terminateContractButton->setText(QCoreApplication::translate("AdminMainWindow", "Ch\341\272\245m D\341\273\251t H\304\220", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(contractsTab), QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n L\303\275 H\341\273\243p \304\220\341\273\223ng Thu\303\252", nullptr));
        paymentInfoGroup->setTitle(QCoreApplication::translate("AdminMainWindow", "Th\303\264ng Tin Thanh To\303\241n", nullptr));
        paymentRoomLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng:", nullptr));
        paymentMonthLabel->setText(QCoreApplication::translate("AdminMainWindow", "Th\303\241ng:", nullptr));
        paymentMonthEdit->setDisplayFormat(QCoreApplication::translate("AdminMainWindow", "MM/yyyy", nullptr));
        rentAmountLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ti\341\273\201n Ph\303\262ng:", nullptr));
        rentAmountSpinBox->setSuffix(QCoreApplication::translate("AdminMainWindow", " VND", nullptr));
        electricBillLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ti\341\273\201n \304\220i\341\273\207n:", nullptr));
        electricBillSpinBox->setSuffix(QCoreApplication::translate("AdminMainWindow", " VND", nullptr));
        waterBillLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ti\341\273\201n N\306\260\341\273\233c:", nullptr));
        waterBillSpinBox->setSuffix(QCoreApplication::translate("AdminMainWindow", " VND", nullptr));
        internetBillLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ti\341\273\201n Internet:", nullptr));
        internetBillSpinBox->setSuffix(QCoreApplication::translate("AdminMainWindow", " VND", nullptr));
        paymentStatusLabel->setText(QCoreApplication::translate("AdminMainWindow", "Tr\341\272\241ng Th\303\241i:", nullptr));
        paymentStatusComboBox->setItemText(0, QCoreApplication::translate("AdminMainWindow", "Ch\306\260a thanh to\303\241n", nullptr));
        paymentStatusComboBox->setItemText(1, QCoreApplication::translate("AdminMainWindow", "\304\220\303\243 thanh to\303\241n", nullptr));
        paymentStatusComboBox->setItemText(2, QCoreApplication::translate("AdminMainWindow", "Thanh to\303\241n m\341\273\231t ph\341\272\247n", nullptr));
        paymentStatusComboBox->setItemText(3, QCoreApplication::translate("AdminMainWindow", "Qu\303\241 h\341\272\241n", nullptr));

        addPaymentButton->setText(QCoreApplication::translate("AdminMainWindow", "Th\303\252m H\303\263a \304\220\306\241n", nullptr));
        editPaymentButton->setText(QCoreApplication::translate("AdminMainWindow", "S\341\273\255a H\303\263a \304\220\306\241n", nullptr));
        printInvoiceButton->setText(QCoreApplication::translate("AdminMainWindow", "In H\303\263a \304\220\306\241n", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(paymentsTab), QCoreApplication::translate("AdminMainWindow", "Qu\341\272\243n L\303\275 Thanh To\303\241n", nullptr));
        filterGroup->setTitle(QCoreApplication::translate("AdminMainWindow", "B\341\273\231 L\341\273\215c B\303\241o C\303\241o", nullptr));
        fromDateLabel->setText(QCoreApplication::translate("AdminMainWindow", "T\341\273\253 ng\303\240y:", nullptr));
        toDateLabel->setText(QCoreApplication::translate("AdminMainWindow", "\304\220\341\272\277n ng\303\240y:", nullptr));
        generateReportButton->setText(QCoreApplication::translate("AdminMainWindow", "T\341\272\241o B\303\241o C\303\241o", nullptr));
        summaryGroup->setTitle(QCoreApplication::translate("AdminMainWindow", "T\303\263m T\341\272\257t T\303\240i Ch\303\255nh", nullptr));
        totalRoomsLabel->setText(QCoreApplication::translate("AdminMainWindow", "T\341\273\225ng s\341\273\221 ph\303\262ng:", nullptr));
        totalRoomsValue->setText(QCoreApplication::translate("AdminMainWindow", "0", nullptr));
        occupiedRoomsLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng \304\221\303\243 thu\303\252:", nullptr));
        occupiedRoomsValue->setText(QCoreApplication::translate("AdminMainWindow", "0", nullptr));
        emptyRoomsLabel->setText(QCoreApplication::translate("AdminMainWindow", "Ph\303\262ng tr\341\273\221ng:", nullptr));
        emptyRoomsValue->setText(QCoreApplication::translate("AdminMainWindow", "0", nullptr));
        totalRevenueLabel->setText(QCoreApplication::translate("AdminMainWindow", "T\341\273\225ng doanh thu:", nullptr));
        totalRevenueValue->setText(QCoreApplication::translate("AdminMainWindow", "0 VND", nullptr));
        unpaidBillsLabel->setText(QCoreApplication::translate("AdminMainWindow", "H\303\263a \304\221\306\241n ch\306\260a thanh to\303\241n:", nullptr));
        unpaidBillsValue->setText(QCoreApplication::translate("AdminMainWindow", "0", nullptr));
        mainTabWidget->setTabText(mainTabWidget->indexOf(reportsTab), QCoreApplication::translate("AdminMainWindow", "B\303\241o C\303\241o - Th\341\273\221ng K\303\252", nullptr));
        menuFile->setTitle(QCoreApplication::translate("AdminMainWindow", "&T\341\273\207p", nullptr));
        menuManagement->setTitle(QCoreApplication::translate("AdminMainWindow", "&Qu\341\272\243n L\303\275", nullptr));
        menuReports->setTitle(QCoreApplication::translate("AdminMainWindow", "&B\303\241o C\303\241o", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("AdminMainWindow", "&Tr\341\273\243 Gi\303\272p", nullptr));
        statusInfoLabel->setText(QCoreApplication::translate("AdminMainWindow", "S\341\272\265n s\303\240ng", nullptr));
        dateTimeLabel->setText(QCoreApplication::translate("AdminMainWindow", "20/08/2025 - 10:30", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("AdminMainWindow", "Thanh C\303\264ng C\341\273\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMainWindow: public Ui_AdminMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ADMIN_MAIN_H
