//
// Created by hay boy on 2021/9/30.
//

#ifndef BIGINTEGERUSEVECTOR_BIGINTEGER_H
#define BIGINTEGERUSEVECTOR_BIGINTEGER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <chrono>
#include "Utils.h"
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using namespace std;
using namespace std::string_literals;
class BigInteger {
public:
    size_t effectiveLength;
    bool over0;
    string value;
    string deploy;
    explicit BigInteger(long long int initNum);
    explicit BigInteger(const string& initWithString);
    BigInteger(const string& initWithDeploy, bool simplifyDeploy);
    BigInteger(const BigInteger& bi);
    ~BigInteger() = default;
    string getDeploy() const;
    static string getDeploy(string valueTemp, bool over0Temp) {
        //计算“10补数”
        if (over0Temp) {
            return "0" + valueTemp;
        }
        size_t length = valueTemp.length();
        string deployTemp;
        size_t p;
        size_t push = 0;
        size_t endBit = 10 - convertCharToInt(valueTemp[length - 1]);
        if (endBit == 10) {
            deployTemp = '0';
            push = 1;
        }
        else {
            deployTemp = convertIntToChar(endBit);
        }
        for (int iter = 2; iter <= length; ++iter) {
            p = length - iter;
            endBit = 9 - convertCharToInt(valueTemp[p]) + push;
            if (endBit == 10) {
                if (iter == length) {
                    //                    deploy =
                }
                deployTemp = '0' + deployTemp;
                push = 1;
            }
            else {
                deployTemp = convertIntToChar(endBit) + deployTemp;
                push = 0;
            }

        }
        return '9' + deployTemp;
    }
    static vector<string> getOrigin(string deployed) {
        //将计算结果转化为分开的包含符号位和数字位的组合
        vector<string> x(2);
        size_t getBack = 1;
        if (deployed[0] == '0') {
            x[0] = "1";
            const string t = string(deployed.begin() + 1, deployed.end());
            x[1] = simplifyBigIntegerValue(t);
        }
        else {
            assert(deployed[0] == '9');
            //            cout<<"&&&!!!"<<deployed<<" "<<deployed[0]<<endl;
            x[0] = "0";//false
            string originTemp = getDeploy(string(deployed.begin() + 1, deployed.end()), false);
            const string t = string(originTemp.begin() + 1, originTemp.end());
            x[1] = simplifyBigIntegerValue(t);
        }
        return x;
    }
    void toString();
    void getDetails();
    BigInteger add(const BigInteger& b2) const;
    BigInteger add(const string& b2) const;
    BigInteger add(long long int b2) const ;
    BigInteger operator+() const ;
    BigInteger operator-() const;
    BigInteger& operator = (const BigInteger& b2) = default;//simplify by clion
    BigInteger sub(const BigInteger& b2) const;
    BigInteger sub(const string& b2) const;
    BigInteger sub(long long int b2) const;
    BigInteger operator+(const BigInteger& b2) const;
    BigInteger operator+(const string& b2) const ;
    BigInteger operator+(long long int b2) const;
    //pre
    BigInteger& operator++();
    //post
    BigInteger operator++(int dummy);
    //pre
    BigInteger& operator--();
    //post
    BigInteger operator--(int dummy);
    BigInteger operator-(const BigInteger& b2) const ;
    BigInteger operator-(const string& b2) const;
    BigInteger operator-(long long int b2) const;
    char operator[](size_t index) const ;
    BigInteger& operator+=(const BigInteger& b2);
    BigInteger& operator+=(const string& b2);
    BigInteger& operator+=(long long int b2);
    BigInteger& operator-=(const BigInteger& b2);
    BigInteger& operator-=(const string& b2);
    BigInteger& operator-=(long long int b2);

    int compareTo(const BigInteger& b2);
    int compareTo(const string& b2);
    int compareTo(long long int b2);
    //-- ++ equals()
    bool equals(const BigInteger& b2);
    bool equals(const string& b2);
    bool equals(long long int b2);
    bool operator < (const BigInteger& b);
    bool operator > (const BigInteger& b);
    bool operator <= (const BigInteger& b);
    bool operator >= (const BigInteger& b);
    bool operator == (const BigInteger& b);
    bool operator != (const BigInteger& b);
    BigInteger& operator<<(long long int x);
    BigInteger operator<<(const string& y) const;
    BigInteger& operator>>(long long int x);
    BigInteger operator>>(const string& b);
    string getValue() const;
    BigInteger singleMul(unsigned int b) const;
    BigInteger mul(const BigInteger& b2);
    BigInteger mul(const string& b2);
    BigInteger mul(long long int b2);
    BigInteger operator*(const BigInteger& b2);
    BigInteger operator*(const string& b2);
    BigInteger operator*(long long int b2);
    BigInteger& operator*=(const BigInteger& b2);
    BigInteger& operator*=(const string& b2);
    BigInteger& operator*=(long long int b2);
    BigInteger& toAbs();
    static BigInteger abs(const BigInteger& b) {
        BigInteger x(b.value);
        return x;
    }
    static size_t divHelp(BigInteger& b1, BigInteger& b2) {
        for (size_t k = 2; k <= 9; ++k) {
            if (b1 == (b2 * k)) {
                return k;
            }
            else if (b1 < (b2 * k)) {
                return --k;
            }
            else {

            }
        }
        return 9;
    }
    BigInteger div(BigInteger b2);
    BigInteger operator %(BigInteger b2);
    BigInteger operator % (const string& b2);
    BigInteger operator % (const long long int b2);
    BigInteger& operator %=(const BigInteger& b2);
    BigInteger& operator %=(const string& b2);
    BigInteger& operator %=(const long long int b2);
    BigInteger div(const string& b2);
    BigInteger div(long long int b2);
    BigInteger operator / (const BigInteger& b2);
    BigInteger operator / (const string& b2);
    BigInteger operator / (long long int b2) ;
    BigInteger& operator /= (const BigInteger& b);
    BigInteger& operator /= (const string& b);
    BigInteger& operator /= (long long int b);
    BigInteger sqrt();
    BigInteger pow(unsigned int x);
    static BigInteger pow(int x,int y){
        BigInteger tmp(x);
        BigInteger res(1);
        for(int i = 1;i<=y;i++){
            res *= tmp;
        }
        return res;
    }
    static BigInteger pow(const string& x,int y){
        BigInteger tmp(x);
        BigInteger res(1);
        for(int i = 1;i<=y;i++){
            res *= tmp;
        }
        return res;
    }
    static BigInteger factorial(int i){
        if(i==1||i==0){
            return BigInteger(1);
        }else{
            BigInteger tmp(1);
            for(int j = 1;j<i;j++){
                tmp *= j;
            }
            return tmp;
        }

    }
    static string getFibo(long long int p){
        if (p == 0) {
            return "0";
        }
        else if (p == 1) {
            return "1";
        }
        else {
            BigInteger x(1);
            BigInteger y(0);
            BigInteger z(1);
            for (int h = 2; h <= p; h++) {
                x = y;
                y = z;
                z = x + y;
            }
            return z.value;
        }
    }


};



#endif //BIGINTEGERUSEVECTOR_BIGINTEGER_H
