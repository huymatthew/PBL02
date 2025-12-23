#include <Dialogs/SearchFilterDiag.h>

SearchFilterDialog::SearchFilterDialog(QWidget* parent, QTableView* view, int filterIn) : QDialog(parent), Ui_SearchFilterDialog(), view(view) {
    setupUi(this);
    signalConnect();
    tabWidget->setCurrentIndex(0);
    stackedWidget->setCurrentIndex(filterIn);


    for (int i = 0; i < view->model()->columnCount(); ++i) {
        searchFieldComboBox->addItem(view->model()->headerData(i, Qt::Horizontal).toString(), QVariant::fromValue(i));
    }
}

SearchFilterDialog::~SearchFilterDialog() {

}

void SearchFilterDialog::on_buttonBox_accepted() {
    cout << "Accepted: Push Search/Filter Data" << endl;
    applySearchFilter();
    accept();
}

void SearchFilterDialog::on_buttonBox_rejected() {
    cout << "Rejected" << endl;
    reject();
}


void SearchFilterDialog::signalConnect() {
    connect(buttonBox, &QDialogButtonBox::accepted, this, &SearchFilterDialog::on_buttonBox_accepted);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &SearchFilterDialog::on_buttonBox_rejected);
}

void SearchFilterDialog::applySearchFilter() {
    cout << "Apply Search/Filter" << endl;
    // Search
    int searchFieldIndex = searchFieldComboBox->currentData().toInt();
    QString searchValue = searchLineEdit->text();
    bool caseSensitive = caseSensitiveCheckBox->isChecked();

    for (int row = 0; row < view->model()->rowCount(); ++row) {
        QModelIndex index = view->model()->index(row, searchFieldIndex);
        QString data = view->model()->data(index).toString().replace('~', " ");
        Qt::CaseSensitivity cs = caseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive;
        if (data.contains(searchValue, cs) && shouldShowIt(row)) {
            view->setRowHidden(row, false);
        }
        else {
            view->setRowHidden(row, true);
        }
    }
}

bool SearchFilterDialog::shouldShowIt(int rowIndex){ // Filter
    int filterIn = stackedWidget->currentIndex();
    switch (filterIn)
    {
    case 0:
        // Room Filter
        {
            int roomType = filterRoomType->currentIndex();
            int roomStatus = filterRoomStatus->currentIndex();
            int priceFrom = filterRoomPriceFrom->value();
            int priceTo = filterRoomPriceTo->value();

            cout << "Room Filter: Type=" << roomType << " Status=" << roomStatus << " PriceFrom=" << priceFrom << " PriceTo=" << priceTo << endl;

            QModelIndex typeIndex = view->model()->index(rowIndex, 2);
            QModelIndex statusIndex = view->model()->index(rowIndex, 4); 
            QModelIndex priceIndex = view->model()->index(rowIndex, 3);

            bool typeMatch = (roomType == 0) || (view->model()->data(typeIndex, Qt::UserRole).toInt() == roomType - 1);
            bool statusMatch = (roomStatus == 0) || (view->model()->data(statusIndex, Qt::UserRole).toInt() == roomStatus - 1);
            bool priceMatch = (view->model()->data(priceIndex, Qt::UserRole).toInt() >= priceFrom) && (view->model()->data(priceIndex, Qt::UserRole).toInt() <= priceTo);

            return typeMatch && statusMatch && priceMatch;
        }
        break;
    case 1:
        // Tenant Filter
        {
            int tenantRole = tenantFilterRole->currentIndex();
            int tenantStatus = tenantFilterStatus->currentIndex();

            int tenantID = view->model()->data(view->model()->index(rowIndex, 0)).toInt();
            int rentType = DataManager::getInstance().isTenantRenting(tenantID); 

            bool roleMatch = (tenantRole == 0) || (rentType == tenantRole);
            bool isCurrentlyRenting = (rentType > 0); 
            bool statusMatch = (tenantStatus == 0) || 
                            (tenantStatus == 1 && isCurrentlyRenting) || 
                            (tenantStatus == 2 && !isCurrentlyRenting);

            return roleMatch && statusMatch;
        }
        break;
    case 2:
        // Contract Filter
        {
            int contractStatus = contractFilterStatus->currentIndex();
            int contractRoomRentFrom = contractFilterRoomRentFrom->value();
            int contractRoomRentTo = contractFilterRoomRentTo->value();
            int contractDepositFrom = contractFilterDepositFrom->value();
            int contractDepositTo = contractFilterDepositTo->value();
            int contractStartDateFrom = contractFilterStartDateFrom->date().toJulianDay();
            int contractStartDateTo = contractFilterStartDateTo->date().toJulianDay();
            int contractEndDateFrom = contractFilterEndDateFrom->date().toJulianDay();
            int contractEndDateTo = contractFilterEndDateTo->date().toJulianDay();

            QModelIndex statusIndex = view->model()->index(rowIndex, 6);
            QModelIndex roomRentIndex = view->model()->index(rowIndex, 5);
            QModelIndex depositIndex = view->model()->index(rowIndex, 4);
            QModelIndex startDateIndex = view->model()->index(rowIndex, 2);
            QModelIndex endDateIndex = view->model()->index(rowIndex, 3);
            bool statusMatch = (contractStatus == 0) || (view->model()->data(statusIndex, Qt::UserRole).toInt() == contractStatus - 1);
            bool roomRentMatch = (view->model()->data(roomRentIndex, Qt::UserRole).toInt() >= contractRoomRentFrom) && (view->model()->data(roomRentIndex, Qt::UserRole).toInt() <= contractRoomRentTo);
            bool depositMatch = (view->model()->data(depositIndex, Qt::UserRole).toInt() >= contractDepositFrom) && (view->model()->data(depositIndex, Qt::UserRole).toInt() <= contractDepositTo);
            bool startDateMatch = (view->model()->data(startDateIndex, Qt::UserRole).toInt() >= contractStartDateFrom) && (view->model()->data(startDateIndex, Qt::UserRole).toInt() <= contractStartDateTo);
            bool endDateMatch = (view->model()->data(endDateIndex, Qt::UserRole).toInt() >= contractEndDateFrom) && (view->model()->data(endDateIndex, Qt::UserRole).toInt() <= contractEndDateTo);

            return statusMatch && roomRentMatch && depositMatch && startDateMatch && endDateMatch;
        }
        break;
    case 3:
        // Payment Filter
        {
            int billStatus = billFilterStatus->currentIndex();
            int billPriceFrom = billFilterPriceFrom->value();
            int billPriceTo = billFilterPriceTo->value();
            int billMonthFrom = billFilterMonthFrom->date().toJulianDay();
            int billMonthTo = billFilterMonthTo->date().toJulianDay();

            QModelIndex statusIndex = view->model()->index(rowIndex, 5);
            QModelIndex priceIndex = view->model()->index(rowIndex, 4);
            QModelIndex monthIndex = view->model()->index(rowIndex, 2);

            bool statusMatch = (billStatus == 0) || (view->model()->data(statusIndex, Qt::UserRole).toInt() == billStatus - 1);
            bool priceMatch = (view->model()->data(priceIndex, Qt::UserRole).toInt() >= billPriceFrom) && (view->model()->data(priceIndex, Qt::UserRole).toInt() <= billPriceTo);
            bool monthMatch = (view->model()->data(monthIndex, Qt::UserRole).toInt() >= billMonthFrom) && (view->model()->data(monthIndex, Qt::UserRole).toInt() <= billMonthTo);
            return statusMatch && priceMatch && monthMatch;

        }
        break;
    default:
        return true;
        break;
    }
    return true;
}