#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>
using namespace std;
class Contract {
private:
    int contract_id;
    int room_id; 
    string start_date;
    string end_date;
    double monthly_rent;
    double deposit;
    int status; // 0: inactive, 1: active
    string notes;
public:
    Contract();
    Contract(const Contract& other);
    Contract(int id, const int& roomId,
             const string& start, const string& end,
             double rent, double deposit, int status, const string& notes);

    int getContractId() const;
    void setContractId(int id);

    int getRoomId() const;
    void setRoomId(const int& roomId);

    string getStartDate() const;
    void setStartDate(const string& start);

    string getEndDate() const;
    void setEndDate(const string& end);

    double getMonthlyRent() const;
    void setMonthlyRent(double rent);

    double getDeposit() const;
    void setDeposit(double deposit);

    int getStatus() const;
    void setStatus(int status);

    string getNotes() const;
    void setNotes(const string& notes);
};

#endif // CONTRACT_H
