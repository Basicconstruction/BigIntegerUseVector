//
// Created by hay boy on 2021/9/30.
//
#include "Utils.h"

bool same(const bool a, const bool b) {
    if ((a && b)||((!a) && (!b))) {
        return true;
    }else {
        return false;
    }
}
size_t convertCharToInt(const char c) {
    assert(c >= 48 && c <= 57);
    return static_cast<size_t>(c) - 48;
}
char convertIntToChar(size_t c) {
    return static_cast<char>(c + 48);
}
long long int convertStringToLong(const string& s) {
    long long int x = 0;
    for (char i : s) {
        x *= 10;
        x += convertCharToInt(i);
    }
    return x;
}

bool convertStringToBool(const string& bo) {
    if (bo == "0") {
        return false;
    }
    else {
        return true;
    }
}
string convertBoolToString(bool bo) {
    if (bo) {
        return "true";
    }
    else {
        return "false";
    }
}

size_t nonZero(const string& getStr) {
    for (size_t i = 0; i < getStr.length(); ++i) {
        if (getStr[i] != '0') {
            return i;
        }
    }
    //获取整数字符串中第一个非零字符的位置，用于简化字符串存储
    //比如传入 0000123 那么该函数将会返回4，后续函数可以利用该数字来处理简化
    return getStr.length();
}
string simplifyBigIntegerValue(string BigIntegerValue) {
    string v = std::move(BigIntegerValue);
    //用于简化BigInteger.add(BigInteger&,BigInteger&)的输出
    //比如将-00001,简化为-1
    //将00001简化为1
    if (v[0] == '-' || v[0] == '+') {
        size_t bn0 = nonZero(string(v.begin() + 1, v.end()));
        if (bn0 + 1 == v.length()) {
            return "0";
        }
        return '-' + string(v.begin() + int(bn0) + 1, v.end());
    }
    else {
        size_t bn0 = nonZero(v);
        if (bn0 == v.length()) {
            return "0";
        }
        return string(v.begin() + bn0, v.end());
    }
}