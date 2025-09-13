# Trình biên dịch
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Include paths
INCLUDES = -I include \
           -I include/QtWidgets \
           -I include/QtCore \
           -I include/QtGui \
           -I Home/include \
           -I ui/uics \
           -I ui

# Lib paths
LDFLAGS = -L lib -lQt5Core -lQt5Gui -lQt5Widgets

# Tên file xuất
TARGET = bin/main.exe

# Lấy toàn bộ file .cpp
SRCS = main.cpp \
       Home/sources/QuanLy.cpp \
       $(wildcard Home/sources/Data/*.cpp) \
       $(wildcard Home/sources/Manager/*.cpp) \
       $(wildcard Home/sources/Core/*.cpp) \
       $(wildcard Home/sources/Dialogs/*.cpp)

OBJS = $(SRCS:.cpp=.o)

# Luật build chính
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Luật build từng .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Dọn dẹp
clean:
	rm -f $(OBJS) $(TARGET)

# Chạy chương trình (sau khi build)
run: $(TARGET)
	bin\main.exe
