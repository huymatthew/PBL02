#ifndef CONTRACT_MANAGER_H
#define CONTRACT_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>
#include <Core/Manager.h>

#include <Data/Contract.h>
#include <Core/PrimaryKey.h>
#include <Core/cVector.h>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class DataManager;
class QChartPie;

class ContractManager : public Manager<Contract> {
public:
    ContractManager();
    ~ContractManager();

    bool loadFromDatabase(bool showLog = false) override;
    bool saveToDatabase(bool showLog = false) override;

    bool addContract(const int& roomId,
                    const string& start, const string& end,
                    double rent, double deposit, int status,
                    const string& notes);

    Contract* getSelected() const;
    void setSelected(Contract* contract);

    void setStatusWhenDue();

    Contract* getActiveContractByRoom(const int& roomId);
    bool roomHasActiveContract(const int& roomId) const;
    double getTotalMonthlyRent() const;
    double getTotalDeposits() const;

    bool roomUsed(int roomId) const;
    void deactivateContract(int contractId);
    void terminateContract(int contractId);
    
    QStandardItemModel* getContractsAsModel() const;
    friend class DataManager;
    friend class QChartPie;
private:
    Contract* selectedContract;
};

#endif // CONTRACT_MANAGER_H