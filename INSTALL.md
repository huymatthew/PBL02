# Hướng Dẫn Cài Đặt

Tài liệu này sẽ hướng dẫn bạn cài đặt các thư viện cần thiết để biên dịch và chạy ứng dụng quản lý phòng trọ sử dụng Qt.

## Các Thư Viện Yêu Cầu

Dự án này yêu cầu các thư viện Qt5 sau:
- **Qt5Core** - Chức năng cốt lõi của Qt
- **Qt5Widgets** - Các widget giao diện đồ họa
- **Qt5Gui** - Các lớp nền tảng GUI
- **Qt5Charts** - Thành phần biểu đồ

## Hướng Dẫn Cài Đặt

### Linux (Ubuntu/Debian)

1. **Cập nhật danh sách gói:**
   ```bash
   sudo apt update
   ```

2. **Cài đặt các gói phát triển Qt5:**
   ```bash
   sudo apt install -y qt5-default qtbase5-dev libqt5charts5-dev
   ```

3. **Cài đặt công cụ biên dịch (nếu chưa có):**
   ```bash
   sudo apt install -y build-essential pkg-config
   ```

4. **Kiểm tra cài đặt:**
   ```bash
   pkg-config --modversion Qt5Core Qt5Widgets Qt5Gui Qt5Charts
   ```
   Lệnh này sẽ hiển thị số phiên bản của các thư viện Qt đã cài đặt.

### Linux (Fedora/RHEL/CentOS)

1. **Cài đặt các gói phát triển Qt5:**
   ```bash
   sudo dnf install -y qt5-qtbase-devel qt5-qtcharts-devel
   ```

2. **Cài đặt công cụ biên dịch:**
   ```bash
   sudo dnf groupinstall "Development Tools"
   ```

### Linux (Arch/Manjaro)

1. **Cài đặt các gói Qt5:**
   ```bash
   sudo pacman -S qt5-base qt5-charts gcc make pkg-config
   ```

### macOS

1. **Cài đặt Homebrew (nếu chưa có):**
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. **Cài đặt Qt5:**
   ```bash
   brew install qt@5
   ```

3. **Thêm Qt5 vào PATH:**
   ```bash
   echo 'export PATH="/usr/local/opt/qt@5/bin:$PATH"' >> ~/.zshrc
   source ~/.zshrc
   ```

### Windows

1. **Tải Qt Online Installer:**
   - Truy cập: https://www.qt.io/download-qt-installer
   - Tải Qt Online Installer

2. **Chạy trình cài đặt:**
   - Tạo tài khoản Qt (miễn phí)
   - Chọn "Custom Installation"
   - Chọn Qt 5.15.x (hoặc phiên bản Qt5 mới nhất)
   - Chọn các thành phần sau:
     - Desktop gcc 64-bit (Linux)
     - MinGW 64-bit (Windows)
     - Qt Charts

3. **Cài đặt MinGW (chỉ Windows):**
   - Trình cài đặt Qt đã bao gồm MinGW
   - HOẶC tải từ: https://sourceforge.net/projects/mingw-w64/

4. **Thêm vào PATH:**
   - Thêm thư mục bin của Qt vào PATH hệ thống
   - Ví dụ: `C:\Qt\5.15.2\mingw81_64\bin`
   - Thêm thư mục bin của MinGW: `C:\Qt\Tools\mingw810_64\bin`

## Kiểm Tra Cài Đặt

### Kiểm Tra Qt

Chạy lệnh sau để xác minh các thư viện Qt đã được cài đặt đúng:

```bash
pkg-config --cflags --libs Qt5Core Qt5Widgets Qt5Gui Qt5Charts
```

Nếu thành công, lệnh sẽ hiển thị các cờ biên dịch và liên kết.

### Kiểm Tra Trình Biên Dịch C++

```bash
g++ --version
```

Lệnh này sẽ hiển thị phiên bản GCC của bạn (khuyến nghị: 7.0 trở lên để hỗ trợ C++17).

## Biên Dịch Dự Án

Sau khi cài đặt xong các thư viện cần thiết:

1. **Di chuyển đến thư mục dự án:**
   ```bash
   cd /đường/dẫn/đến/PBL02
   ```

2. **Biên dịch dự án:**
   ```bash
   make
   ```

3. **Chạy ứng dụng:**
   ```bash
   make run
   ```
   Hoặc chạy trực tiếp:
   ```bash
   ./bin/main
   ```

## Xử Lý Sự Cố

### Lỗi: "Package Qt5Charts was not found"

**Giải pháp:**
- Đảm bảo `libqt5charts5-dev` (Ubuntu/Debian) đã được cài đặt
- Hoặc `qt5-qtcharts-devel` (Fedora/RHEL)
- Hoặc `qt5-charts` (Arch)

### Lỗi: "g++: command not found"

**Giải pháp:**
```bash
# Ubuntu/Debian
sudo apt install build-essential

# Fedora/RHEL
sudo dnf groupinstall "Development Tools"

# Arch
sudo pacman -S base-devel
```

### Lỗi: "pkg-config: command not found"

**Giải pháp:**
```bash
# Ubuntu/Debian
sudo apt install pkg-config

# Fedora/RHEL
sudo dnf install pkgconfig

# Arch
sudo pacman -S pkg-config
```

### Lỗi: Biên dịch thất bại với lỗi C++17

**Giải pháp:**
- Đảm bảo phiên bản GCC của bạn là 7.0 trở lên
- Cập nhật GCC nếu cần:
  ```bash
  # Ubuntu/Debian
  sudo apt install g++-9
  
  # Cập nhật alternatives
  sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 90
  ```

## Lưu Ý Bổ Sung

- Dự án này sử dụng chuẩn **C++17** - đảm bảo trình biên dịch của bạn hỗ trợ
- Sử dụng **Qt5** (không phải Qt6) - đảm bảo cài đặt các gói Qt5
- Dự án sử dụng **pkg-config** để tự động tìm các thư viện Qt
- Trên một số hệ thống, bạn có thể cần đăng xuất và đăng nhập lại sau khi cài đặt để các thay đổi PATH có hiệu lực

## Nhận Trợ Giúp

Nếu gặp vấn đề không được đề cập ở đây:
1. Kiểm tra kỹ thông báo lỗi
2. Xác minh tất cả gói đã được cài đặt: `dpkg -l | grep qt5` (Ubuntu/Debian)
3. Kiểm tra phiên bản Qt: `qmake --version`
4. Đảm bảo pkg-config có thể tìm thấy Qt: `pkg-config --list-all | grep Qt5`

## Cấu Trúc Dự Án

Sau khi cài đặt và biên dịch thành công:
- **Mã nguồn**: `app/sources/` và `app/include/`
- **File UI**: `ui/design/`
- **File thực thi**: `bin/main`
- **Makefile**: Thư mục gốc

---

**Cập nhật lần cuối:** Tháng 12/2025  
**Phiên bản Qt yêu cầu:** Qt 5.x  
**Chuẩn C++:** C++17
