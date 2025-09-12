g++ main.cpp -o bin/main.exe Home/sources/QuanLy.cpp Home/sources/Data/*.cpp Home/sources/Manager/*.cpp Home/sources/Core/*.cpp^
 -I include ^
 -I include\QtWidgets ^
 -I include\QtCore ^
 -I include\QtGui ^
 -I Home\include ^
 -I ui\uics ^
 -I ui ^
 -L lib ^
 -lQt5Core -lQt5Gui -lQt5Widgets

if %ERRORLEVEL%==0 (
	bin\main.exe
)