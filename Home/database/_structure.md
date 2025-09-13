# Database Structure

## Bill

|Bill_ID|Contract_ID|Billing_Month|Room_Rent|Total_Amount|Due_Date|Status|
|-------|-----------|-------------|---------|------------|--------|------|
|int    |int        |string       |double   |double      |string  |int   |

**Description:**

- Bill_ID: Primary Key
- Contract_ID: Foreign Key -> Contract
- Billing_Month: Tháng tính tiền (format: MMYYYY)
- Room_Rent: Tiền thuê phòng
- Total_Amount: Tổng tiền phải trả
- Due_Date: Hạn thanh toán
- Status: Trạng thái (0: chưa thanh toán, 1: đã thanh toán)

---

## Contract

|Contract_ID|Room_ID|Start_Date|End_Date|Monthly_Rent|Deposit|Status|Notes |
|-----------|-------|----------|--------|------------|-------|------|------|
|int        |string |string    |string  |double      |double |int   |string|

**Description:**

- Contract_ID: Primary Key
- Room_ID: Foreign Key -> Room
- Start_Date: Ngày bắt đầu hợp đồng
- End_Date: Ngày kết thúc hợp đồng
- Monthly_Rent: Tiền thuê hàng tháng
- Deposit: Tiền đặt cọc
- Status: Trạng thái (0: không hoạt động, 1: đang hoạt động)
- Notes: Ghi chú

---

## Room

|Room_ID|RoomName|Contract_ID|Room_Type|Monthly_Rent|Status|Description|
|-------|--------|-----------|---------|------------|------|-----------|
|int    |string  |int        |int      |double      |int   |string     |

**Description:**

- Room_ID: Primary Key
- RoomName: String
- Contract_ID: Foreign Key -> Contract
- Room_Type: Loại phòng
- Monthly_Rent: Tiền thuê hàng tháng
- Description: Mô tả phòng
- Status: Trạng thái (0: trống, 1: đang thuê)

---

## Tenant

|Tenant_ID|Full_Name|Phone |Identity_Card|Date_Of_Birth|Contract_ID|Is_Main_Tenant|
|---------|---------|------|-------------|-------------|-----------|--------------|
|int      |string   |string|string       |string       |int        |bool          |

**Description:**

- Tenant_ID: Primary Key
- Full_Name: Họ và tên
- Phone: Số điện thoại
- Identity_Card: Số CMND/CCCD
- Date_Of_Birth: Ngày sinh (ddmmyyyy)
- Contract_ID: Foreign Key -> Contract
- Is_Main_Tenant: Là người thuê chính (true/false)

---

## Service

|Service_ID|Service_Type|Bill_ID|Quantity|Price|
|----------|------------|-------|--------|-----|
|int       |int         |int    |int     |double|

**Description:**

- Service_ID: Primary Key
- Service_Type: Loại dịch vụ (0: Điện, 1: Nước, 2: Internet, ...)
- Bill_ID: Foreign Key -> Bill
- Quantity: Số lượng sử dụng
- Price: Giá tiền

---

## ServiceType

|Service_Type|Name|Price|
|------------|----|----- |
|int         |string|double|

**Description:**

- Service_Type: Primary Key
- Name: Tên dịch vụ
- Price: Giá dịch vụ

---

## Relationships

- **Contract** ↔ **Room**: 1-1 (Một hợp đồng có một phòng)
- **Contract** → **Bill**: 1-N (Một hợp đồng có nhiều hóa đơn)
- **Contract** → **Tenant**: 1-N (Một hợp đồng có nhiều người thuê)
- **Bill** → **Service**: 1-N (Một hóa đơn có nhiều dịch vụ)
- **ServiceType** → **Service**: 1-N (Một loại dịch vụ có nhiều dịch vụ cụ thể)
