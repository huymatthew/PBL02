#include <ServiceType.h>

// Dummy implementations for demonstration purposes
ServiceType::ServiceType()
    : service_type(0), name(""), price(0.0) {}

ServiceType::ServiceType(int type, const string& name, double price)
    : service_type(type), name(name), price(price) {}

int ServiceType::getServiceType() const { return service_type; }
void ServiceType::setServiceType(int type) { service_type = type; }
string ServiceType::getName() const { return name; }
void ServiceType::setName(const string& name) { this->name = name; }
double ServiceType::getPrice() const { return price; }
void ServiceType::setPrice(double price) { this->price = price; }

vector<ServiceType> ServiceType::loadFromDatabase() {
    vector<ServiceType> services;
    services.emplace_back(1, "Cleaning", 50.0);
    services.emplace_back(2, "Repair", 75.0);
    services.emplace_back(3, "Consultation", 100.0);
    return services;
}

bool ServiceType::saveToDatabase(const ServiceType& serviceType) {
    // In a real application, this would save to a database.
    // Here, we just return true to indicate success.
    return true;
}