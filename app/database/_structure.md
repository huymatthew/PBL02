# Database Structure Documentation

> **Ứng dụng quản lý khu trọ - PBL02**  
> Cấu trúc cơ sở dữ liệu file-based sử dụng text files (.dat)

---

## 📋 **Entities Overview**

| Entity | Purpose | File Location |
|--------|---------|---------------|
| Room | Quản lý phòng trọ | `rooms.dat` |
| Tenant | Quản lý người thuê | `tenants.dat` |
| Contract | Quản lý hợp đồng thuê | `contracts.dat` |
| Bill | Quản lý hóa đơn thanh toán | `bills.dat` |
| Service | Quản lý dịch vụ sử dụng | `services.dat` |
| ServiceType | Quản lý loại dịch vụ | `service_types.dat` |
| Rent | Quan hệ Tenant-Contract | `rents.dat` |

---

## 🏠 **Room (Phòng trọ)**

| Field | Type | Description | Example |
|-------|------|-------------|---------|
| `room_id` | `int` | **Primary Key** - ID duy nhất của phòng | `101` |
| `room_name` | `string` | Tên/số phòng | `"P101"` |
| `room_type` | `int` | Loại phòng | `0` |
| `monthly_rent` | `double` | Giá thuê hàng tháng | `2500000.0` |
| `description` | `string` | Mô tả chi tiết phòng | `" Phòng có ban công"` |
| `status` | `int` | Trạng thái phòng | `0` |

### **Room Type Enum:**
- `0`: Phòng đơn
- `1`: Phòng đôi  
- `2`: Phòng gia đình

### **Room Status Enum:**
- `0`: Trống
- `1`: Đang thuê

**File format:** `room_id room_name room_type monthly_rent status description`

---

## 👥 **Tenant (Người thuê)**

| Field | Type | Description | Example |
|-------|------|-------------|---------|
| `tenant_id` | `int` | **Primary Key** - ID duy nhất | `1001` |
| `full_name` | `string` | Họ tên đầy đủ | `"Nguyen Van A"` |
| `phone` | `string` | Số điện thoại | `"0901234567"` |
| `identity_card` | `string` | Số CMND/CCCD | `"123456789"` |
| `date_of_birth` | `string` | Ngày sinh (ddmmyyyy) | `"01011990"` |
| `gender` | `int` | Giới tính | `1` |

### **Gender Enum:**
- `0`: Không xác định
- `1`: Nam
- `2`: Nữ

**File format:** `tenant_id full_name phone identity_card date_of_birth gender`

---

## 📜 **Contract (Hợp đồng)**

| Field | Type | Description | Example |
|-------|------|-------------|---------|
| `contract_id` | `int` | **Primary Key** - ID hợp đồng | `2001` |
| `room_id` | `int` | **Foreign Key** → Room | `101` |
| `start_date` | `string` | Ngày bắt đầu (yyyy-mm-dd) | `"2024-01-15"` |
| `end_date` | `string` | Ngày kết thúc (yyyy-mm-dd) | `"2024-12-15"` |
| `monthly_rent` | `double` | Tiền thuê tháng | `2500000.0` |
| `deposit` | `double` | Tiền đặt cọc | `5000000.0` |
| `status` | `int` | Trạng thái hợp đồng | `1` |
| `notes` | `string` | Ghi chú thêm | `"Hop dong 1 nam"` |

### **Contract Status Enum:**
- `0`: Không hoạt động/Đã kết thúc
- `1`: Đang hoạt động

**File format:** `contract_id room_id start_date end_date monthly_rent deposit status notes`

---

## 💰 **Bill (Hóa đơn)**

| Field | Type | Description | Example |
|-------|------|-------------|---------|
| `bill_id` | `int` | **Primary Key** - ID hóa đơn | `3001` |
| `contract_id` | `int` | **Foreign Key** → Contract | `2001` |
| `billing_month` | `string` | Tháng tính tiền (yyyy-mm) | `"2024-03"` |
| `room_rent` | `double` | Tiền thuê phòng | `2500000.0` |
| `total_amount` | `double` | Tổng tiền phải trả | `2850000.0` |
| `status` | `int` | Trạng thái thanh toán | `0` |

### **Bill Status Enum:**
- `0`: Chưa thanh toán
- `1`: Đã thanh toán
- `2`: Vô Hiệu Hóa

**File format:** `bill_id contract_id billing_month room_rent total_amount status`

---

## ⚡ **Service (Dịch vụ sử dụng)**

| Field | Type | Description | Example |
|-------|------|-------------|---------|
| `service_id` | `int` | **Primary Key** - ID dịch vụ | `4001` |
| `service_type` | `int` | **Foreign Key** → ServiceType | `0` |
| `bill_id` | `int` | **Foreign Key** → Bill | `3001` |
| `quantity` | `int` | Số lượng sử dụng | `150` |
| `price` | `double` | Giá tiền dịch vụ | `350000.0` |

**File format:** `service_id service_type bill_id quantity price`

---

## 🔧 **ServiceType (Loại dịch vụ)**

| Field | Type | Description | Example |
|-------|------|-------------|---------|
| `service_type` | `int` | **Primary Key** - Mã loại dịch vụ | `0` |
| `name` | `string` | Tên dịch vụ | `"Dien"` |
| `price` | `double` | Đơn giá | `2500.0` |
| `unit` | `string` | Đơn vị tính | `"kWh"` |

### **Service Type Enum:**
- `0`: Điện
- `1`: Nước
- `2`: Internet
- `3`: Rác
- `4`: Khác

**File format:** `service_type name price unit`

---

## 🔗 **Rent (Quan hệ Tenant-Contract)**

| Field | Type | Description | Example |
|-------|------|-------------|---------|
| `contract_id` | `int` | **Foreign Key** → Contract | `2001` |
| `tenant_id` | `int` | **Foreign Key** → Tenant | `1001` |
| `is_representative` | `bool` | Là người đại diện hợp đồng | `true` |

**Purpose:** Liên kết nhiều tenant với một contract (nhiều người ở cùng phòng)

**File format:** `contract_id tenant_id is_representative`

---

## 🔄 **Entity Relationships**

### **1. Room ↔ Contract (1:1)**
```
Room.room_id ←→ Contract.room_id
```
- Một phòng có thể có một hợp đồng hoạt động
- Một hợp đồng thuộc về một phòng duy nhất

### **2. Contract → Bill (1:N)**
```
Contract.contract_id ←→ Bill.contract_id
```
- Một hợp đồng có nhiều hóa đơn (hàng tháng)
- Một hóa đơn thuộc về một hợp đồng

### **3. Contract ↔ Tenant (M:N via Rent)**
```
Contract.contract_id ←→ Rent.contract_id
Tenant.tenant_id ←→ Rent.tenant_id
```
- Một hợp đồng có thể có nhiều người thuê
- Một người thuê có thể có nhiều hợp đồng (theo thời gian)
- **Rent table** quản lý mối quan hệ này

### **4. Bill → Service (1:N)**
```
Bill.bill_id ←→ Service.bill_id
```
- Một hóa đơn chứa nhiều dịch vụ
- Một dịch vụ thuộc về một hóa đơn

### **5. ServiceType → Service (1:N)**
```
ServiceType.service_type ←→ Service.service_type
```
- Một loại dịch vụ có nhiều instance sử dụng
- Mỗi service sử dụng thuộc một loại dịch vụ

---

## 📊 **Business Logic Rules**

### **Room Management:**
1. Room chỉ có thể có 1 active contract tại một thời điểm
2. Khi tạo contract mới cho room → room.status = 1 (đang thuê)
3. Khi kết thúc contract → room.status = 0 (trống)

### **Contract Management:**
1. Contract phải có ít nhất 1 tenant làm representative
2. Start_date < End_date
3. Monthly_rent > 0 và Deposit >= 0

### **Bill Management:**
1. Bill được tạo hàng tháng cho active contracts
2. Total_amount = room_rent + sum(services)
3. Billing_month format: "yyyy-mm"

### **Tenant Management:**
1. Mỗi tenant có identity_card và phone duy nhất
2. Date_of_birth format: "ddmmyyyy"

### **Service Management:**
1. Service chỉ được thêm vào unpaid bills
2. Quantity > 0, Price >= 0

---

## 💾 **File Storage Format**

All data files use **space-separated values** with the following characteristics:

- **Encoding:** UTF-8
- **Separator:** Single space `" "`
- **Line ending:** Unix (`\n`)
- **String handling:** No quotes, spaces in descriptions handled specially
- **File extension:** `.dat`

### **Sample Data Files:**

**rooms.dat:**
```
101 P101 0 2500000 0  Phong co ban cong
102 P102 1 3000000 1  Phong doi rong rai
```

**contracts.dat:**
```
2001 101 2024-01-15 2024-12-15 2500000 5000000 1 Hop_dong_1_nam
```

**bills.dat:**
```
3001 2001 2024-03 2500000 2850000 0
```

---

## 🔧 **Implementation Notes**

### **Primary Key Management:**
- Sử dụng `PrimaryKey` class để quản lý auto-increment IDs
- Mỗi Manager class có riêng PrimaryKey instance

### **Data Validation:**
- Room: room_name không empty, monthly_rent > 0
- Tenant: phone và identity_card unique, date format valid
- Contract: start_date < end_date, room available
- Bill: contract exists và active

### **Error Handling:**
- File I/O errors được log ra console
- Duplicate key detection
- Invalid data format handling

---

## 📈 **Future Enhancements**

1. **Database Migration:** Chuyển sang SQLite với proper foreign keys
2. **Data Encryption:** Mã hóa sensitive data (identity_card, phone)
3. **Backup System:** Automatic periodic backups
4. **Index System:** Tạo index files cho faster lookups
5. **Transaction Support:** Atomic operations cho data consistency
