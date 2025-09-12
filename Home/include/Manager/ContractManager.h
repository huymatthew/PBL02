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
    bool addContract(const string& roomId, const string& number,
                    const string& start, const string& end,
                    double rent, double deposit, int status,
                    const string& signedDate, const string& notes);
    bool removeContract(int contractId);
    bool updateContract(int contractId, const Contract& updatedContract);
    
    Contract* getContract(int contractId);
    Contract* getContractByRoom(const string& roomId);
    Contract* getContractByNumber(const string& contractNumber);
    vector<Contract> getContractsByStatus(int status);
    vector<Contract> getAllContracts() const;
    
    bool contractExists(int contractId) const;
    bool contractNumberExists(const string& contractNumber) const;
    bool roomHasActiveContract(const string& roomId) const;
    int getContractCount() const;
    
    bool activateContract(int contractId);
    bool deactivateContract(int contractId);
    bool extendContract(int contractId, const string& newEndDate);
    
    vector<Contract> getExpiringContracts(const string& date) const;
    vector<Contract> getActiveContracts() const;
    vector<Contract> getInactiveContracts() const;
    
    vector<Contract> searchContracts(const string& keyword);
    
    double getTotalMonthlyRent() const;
    double getTotalDeposits() const;
    
    QStandardItemModel* getContractsAsModel() const;
private:
    vector<Contract> contracts;
    PrimaryKey pk_manager;
    bool data_loaded;
    
    // Helper methods
    vector<Contract>::iterator findContractIterator(int contractId);
    bool isDateBefore(const string& date1, const string& date2) const;
    void sortContractsByDate();
};

#endif // CONTRACT_MANAGER_H