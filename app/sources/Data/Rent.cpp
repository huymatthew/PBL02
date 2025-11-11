#include <Data/Rent.h>

Rent::Rent() : contract_id(0), tenant_id(0), is_representative(false) {}

Rent::Rent(const Rent& other)
    : contract_id(other.contract_id), tenant_id(other.tenant_id), is_representative(other.is_representative) {}

Rent::Rent(int contractId, int tenantId, bool isRepresentative)
    : contract_id(contractId), tenant_id(tenantId), is_representative(isRepresentative) {}
Rent::~Rent() {}

int Rent::getId() const {
    return contract_id;
}

void Rent::setId(int id) {
    contract_id = id;
}

int Rent::getTenantId() const {
    return tenant_id;
}

void Rent::setTenantId(int tenantId) {
    tenant_id = tenantId;
}

int Rent::getContractId() const {
    return contract_id;
}

void Rent::setContractId(int contractId) {
    contract_id = contractId;
}

bool Rent::getIsRepresentative() const {
    return is_representative;
}

void Rent::setIsRepresentative(bool isRepresentative) {
    is_representative = isRepresentative;
}