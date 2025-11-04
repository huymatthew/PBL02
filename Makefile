# Trình biên dịch
CXX = g++
CXXFLAGS = -Wall -std=c++17 -fPIC

# Qt configuration
QT_CFLAGS = $(shell pkg-config --cflags Qt5Core Qt5Widgets Qt5Gui)
QT_LIBS = $(shell pkg-config --libs Qt5Core Qt5Widgets Qt5Gui)

# Include paths
INCLUDES = -I app/include \
           -I ui/uics \
           $(QT_CFLAGS)

# Lib paths
LDFLAGS = $(QT_LIBS)

# Tên file xuất
TARGET = bin/main

# Lấy toàn bộ file .cpp
SRCS = main.cpp \
       app/sources/QuanLy.cpp \
       $(wildcard app/sources/Data/*.cpp) \
       $(wildcard app/sources/Manager/*.cpp) \
       $(wildcard app/sources/Core/*.cpp) \
       $(wildcard app/sources/Dialogs/*.cpp) \
       $(wildcard app/sources/Widgets/*.cpp) \
       $(wildcard app/sources/Secure/*.cpp) 


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
	./$(TARGET)