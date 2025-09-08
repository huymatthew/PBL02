#ifndef QUAN_LY_H
#define QUAN_LY_H

#include <iostream>
#include <Data/Bill.h>
#include <Data/Contract.h>
#include <Data/Room.h>
#include <Data/Service.h>
#include <Data/ServiceType.h>
#include <Data/Tenant.h>
#include <admin_main.h>

class QuanLy : public Ui_AdminMainWindow {
public:
    QuanLy();  // Declaration only
    ~QuanLy(); // Declaration only

    void addTenant();
private:
    vector<Bill> bills;
    vector<Contract> contracts;
    vector<Room> rooms;
    vector<Service> services;
    vector<ServiceType> serviceTypes;
    vector<Tenant> tenants;
};



#endif // QUAN_LY_H