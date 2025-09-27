#include <Data/Contract.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Contract::Contract()
    : contract_id(0), monthly_rent(0.0), deposit(0.0), status(0) {}

Contract::Contract(const Contract& other)
    : contract_id(other.contract_id), room_id(other.room_id),
      start_date(other.start_date), end_date(other.end_date),
      monthly_rent(other.monthly_rent), deposit(other.deposit),
      status(other.status), notes(other.notes) {}

Contract::Contract(int id, const int& roomId,
                   const string& start, const string& end,
                   double rent, double deposit, int status,
                   const string& notes)
    : contract_id(id), room_id(roomId), start_date(start),
      end_date(end), monthly_rent(rent), deposit(deposit),
      status(status), notes(notes) {}
Contract::~Contract() {}

int Contract::getContractId() const { return contract_id; }
void Contract::setContractId(int id) { contract_id = id; }

int Contract::getRoomId() const { return room_id; }
void Contract::setRoomId(const int& roomId) { room_id = roomId; }

string Contract::getStartDate() const { return start_date; }
void Contract::setStartDate(const string& start) { start_date = start; }

string Contract::getEndDate() const { return end_date; }
void Contract::setEndDate(const string& end) { end_date = end; }

double Contract::getMonthlyRent() const { return monthly_rent; }
void Contract::setMonthlyRent(double rent) { monthly_rent = rent; }

double Contract::getDeposit() const { return deposit; }
void Contract::setDeposit(double deposit) { this->deposit = deposit; }

int Contract::getStatus() const { return status; }
void Contract::setStatus(int status) { this->status = status; }

string Contract::getNotes() const { return notes; }
void Contract::setNotes(const string& notes) { this->notes = notes; }
