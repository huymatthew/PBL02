# Trình biên dịch
CXX = g++
CXXFLAGS = -Wall -std=c++17 -fPIC

# Qt configuration
QT_CFLAGS = $(shell pkg-config --cflags Qt5Core Qt5Widgets Qt5Gui Qt5Charts)
QT_LIBS = $(shell pkg-config --libs Qt5Core Qt5Widgets Qt5Gui Qt5Charts)

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

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)