//
// Created by hay boy on 2021/9/30.
//

#ifndef BIGINTEGERUSEVECTOR_UTILS_H
#define BIGINTEGERUSEVECTOR_UTILS_H
#include <iostream>
#include <cassert>
using namespace std;
bool same(bool a, bool b);
size_t convertCharToInt(char c);
char convertIntToChar(size_t c);
long long int convertStringToLong(const string& s) ;
template <typename T>
string convertNumToString(T x) {
    // transfer int number to string
    if (x == 0) {
        return "0";
    }
    string s;
    x *= 10;
    while (x >= 10) {
        x /= 10;
        s = static_cast<char>(x % 10 + 48) + s;
    }
    return s;
}
bool convertStringToBool(const string& bo);
string convertBoolToString(bool bo);
size_t nonZero(const string& getStr);
string simplifyBigIntegerValue(string BigIntegerValue);
#endif //BIGINTEGERUSEVECTOR_UTILS_H
