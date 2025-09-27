#ifndef RENT_H
#define RENT_H

#include <string>
#include <vector>
#include <Core/PrimaryKey.h>
using namespace std;

class Rent {
    int room_id;
    int tenant_id;
    bool is_representative;
    public:
    Rent();
    Rent(const Rent& other);
    Rent(int roomId, int tenantId, bool isRepresentative);
    ~Rent();

    int getRoomId() const;
    void setRoomId(int roomId);

    int getTenantId() const;
    void setTenantId(int tenantId);

    bool getIsRepresentative() const;
    void setIsRepresentative(bool isRepresentative);
};

#endif
