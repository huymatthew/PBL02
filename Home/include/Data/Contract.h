#ifndef CONTRACT_H
#define CONTRACT_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>
using namespace std;
class Contract {
private:
    int contract_id;
    string room_id; // FK -> Rooms
    string contract_number;
    string start_date;
    string end_date;
    double monthly_rent;
    double deposit;
    int status; // 0: inactive, 1: active
    string signed_date;
    string notes;
public:
    Contract();
    Contract(const Contract& other);
    Contract(int id, const string& roomId, const string& number,
             const string& start, const string& end,
             double rent, double deposit, int status,
             const string& signedDate, const string& notes);

    // Getter - Setter
    int getContractId() const;
    void setContractId(int id);

    string getRoomId() const;
    void setRoomId(const string& roomId);

    string getContractNumber() const;
    void setContractNumber(const string& number);

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

    string getSignedDate() const;
    void setSignedDate(const string& signedDate);

    string getNotes() const;
    void setNotes(const string& notes);
};

#endif
