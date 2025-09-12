# PBL 02 - Dự án cơ sở lập trình

## Đề tài: Ứng dụng quản lý khu trọ

### 📋 Mô tả dự án

Ứng dụng **Quản lý khu trọ** là một phần mềm desktop được phát triển bằng **Qt5** với **C++**, giúp quản lý hiệu quả các hoạt động của khu trọ bao gồm: quản lý phòng, hợp đồng, người thuê, dịch vụ và hóa đơn.

### 🚀 Tính năng chính

- **Quản lý phòng trọ**: Thêm, sửa, xóa thông tin phòng, theo dõi trạng thái phòng
- **Quản lý hợp đồng**: Tạo, cập nhật hợp đồng thuê, theo dõi thời hạn
- **Quản lý người thuê**: Lưu trữ thông tin chi tiết của người thuê
- **Quản lý dịch vụ**: Quản lý các loại dịch vụ (điện, nước, internet...)
- **Quản lý hóa đơn**: Tạo và theo dõi hóa đơn thanh toán
- **Báo cáo**: Thống kê doanh thu, tình trạng phòng

### 🛠️ Công nghệ sử dụng

- **Framework**: Qt5 (QtCore, QtGui, QtWidgets)
- **Ngôn ngữ**: C++
- **Platform**: Windows
- **Build System**: qmake/make
- **UI Design**: Qt Designer (.ui files)

### 📁 Cấu trúc dự án

```text
FirstProject/
├── main.cpp                 # Entry point của ứng dụng
├── README.md               # Tài liệu dự án
├── run.bat                 # Script chạy ứng dụng
├── uic.bat                 # Script compile UI files
├── um.bat                  # Script utility
├── bin/                    # Thư mục chứa file thực thi
│   ├── main.exe           # File thực thi chính
│   ├── *.dll              # Các thư viện Qt cần thiết
│   └── platforms/         # Qt platform plugins
├── Home/                   # Thư mục source code chính
│   ├── database/          # Database files và structure
│   ├── include/           # Header files
│   │   ├── QuanLy.h      # Main application class
│   │   ├── Core/         # Core utilities
│   │   ├── Data/         # Data models
│   │   └── Manager/      # Business logic managers
│   └── sources/          # Implementation files
│       ├── QuanLy.cpp
│       ├── Core/
│       ├── Data/
│       └── Manager/
├── include/               # Qt headers
├── lib/                  # Qt libraries
├── platforms/            # Platform specific files
└── ui/                   # UI design files
    ├── design/           # .ui files từ Qt Designer
    └── uics/            # Generated UI headers
```

### 🗄️ Cấu trúc cơ sở dữ liệu

Ứng dụng sử dụng file-based database với các entities chính:

#### **Room (Phòng trọ)**

- Quản lý thông tin phòng: tên phòng, loại phòng, giá thuê
- Trạng thái: trống/đang thuê

#### **Contract (Hợp đồng)**

- Thông tin hợp đồng thuê: số hợp đồng, thời hạn, giá thuê
- Liên kết với phòng và người thuê

#### **Tenant (Người thuê)**

- Thông tin cá nhân: họ tên, SĐT, CMND, ngày sinh
- Phân biệt người thuê chính và người ở cùng

#### **Service (Dịch vụ)**

- Quản lý các dịch vụ sử dụng: điện, nước, internet
- Tính toán chi phí dựa trên số lượng sử dụng

#### **Bill (Hóa đơn)**

- Tạo hóa đơn hàng tháng cho từng hợp đồng
- Tính tổng tiền thuê + dịch vụ

### Dự án này được phát triển cho mục đích học tập trong khuôn khổ môn: Dự án cơ sở lập trình (PBL 02)

### 👥 Thành viên nhóm

- **Võ Phi Nhật Huy** &mdash; 102240139
- **Hồ Đức Việt** &mdash; 102240175
