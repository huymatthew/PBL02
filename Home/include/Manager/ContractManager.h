#ifndef CONTRACT_MANAGER_H
#define CONTRACT_MANAGER_H

#include <QStandardItem>
#include <QStandardItemModel>

#include <Data/Contract.h>
#include <Core/PrimaryKey.h>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class ContractManager {
public:
    ContractManager();
    ~ContractManager();

    bool loadFromDatabase();
    bool saveToDatabase();
    
    bool addContract(const Contract& contract);
    bool addContract(const int& roomId,
                    const string& start, const string& end,
                    double rent, double deposit, int status,
                    const string& notes);
    bool removeContract(int contractId);
    bool updateContract(int contractId, const Contract& updatedContract);
    
    Contract* getContract(int contractId);
    
    bool contractExists(int contractId) const;
    bool roomHasActiveContract(const int& roomId) const;
    int getContractCount() const;
    
    bool activateContract(int contractId);
    bool deactivateContract(int contractId);
    bool extendContract(int contractId, const string& newEndDate);

    double getTotalMonthlyRent() const;
    double getTotalDeposits() const;
    
    QStandardItemModel* getContractsAsModel() const;
private:
    vector<Contract> contracts;
    PrimaryKey pk_manager;
    bool data_loaded;
    
    vector<Contract>::iterator findContractIterator(int contractId);
};

#endif // CONTRACT_MANAGER_H