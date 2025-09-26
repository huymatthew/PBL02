#include <Data/Rent.h>

Rent::Rent() : room_id(0), tenant_id(0), is_representative(false) {}

Rent::Rent(const Rent& other)
    : room_id(other.room_id), tenant_id(other.tenant_id), is_representative(other.is_representative) {}

Rent::Rent(int roomId, int tenantId, bool isRepresentative)
    : room_id(roomId), tenant_id(tenantId), is_representative(isRepresentative) {}

int Rent::getRoomId() const {
    return room_id;
}

void Rent::setRoomId(int roomId) {
    room_id = roomId;
}

int Rent::getTenantId() const {
    return tenant_id;
}

void Rent::setTenantId(int tenantId) {
    tenant_id = tenantId;
}

bool Rent::getIsRepresentative() const {
    return is_representative;
}

void Rent::setIsRepresentative(bool isRepresentative) {
    is_representative = isRepresentative;
}