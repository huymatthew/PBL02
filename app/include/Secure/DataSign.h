#ifndef DATASIGN_H
#define DATASIGN_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class DataSign {
public:
    static bool saveDataSign();
    static bool checkModified();
    static long long hashDataSign();
private:
    static long long hashFile(const string& filePath);
    static long long hashString(const string& str);
};

#endif // DATASIGN_H