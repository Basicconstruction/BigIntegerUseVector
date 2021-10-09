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
#include <iomanip>
#include <cstring>
#include <ctime>
#include <chrono>
#include <ctime>
#include <list>
#include <deque>
#include <sstream>
#include <iterator>

#include "Utils.h"
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using namespace std;
using namespace std::string_literals;
typedef unsigned char jbyte;
typedef unsigned long long ll;
class BigInteger{
public:
    vector<jbyte> value;
    bool signum;
    BigInteger();
    explicit BigInteger(long long int);
    explicit BigInteger(string);
    static void putInObject(vector<jbyte> &value, ll transferredValue);
    friend ostream& operator<<(ostream& os,const BigInteger & num);
    friend istream& operator>>(istream& is,BigInteger & num);
    void printSelf() const;
    static void printSelf(const BigInteger& bigInteger);
    string toString() const;
    static string toString(const BigInteger& bigInteger);
    static void putInObject(vector<jbyte> &value,string transferredValue);
    BigInteger(const BigInteger&);
    ~BigInteger();
    BigInteger& add(long long int);
    BigInteger& add(const string&);
    BigInteger& add(BigInteger&);
    int compareTo(const BigInteger&);
    int compareTo(const string&);
    int compareTo(long long int);
    static int compareTo(vector<jbyte> v1,vector<jbyte> v2);
    BigInteger operator+() const ;
    BigInteger operator-() const;
    BigInteger& operator = (const BigInteger&) = default;
    BigInteger& operator = (long long int);
    BigInteger& operator = (string);
    BigInteger& sub(const BigInteger&);
    BigInteger& sub(const string&);
    BigInteger& sub(long long int);
    BigInteger& operator+=(BigInteger b2);
    BigInteger& operator+=(const string& b2);
    BigInteger& operator+=(long long int b2);
    BigInteger& operator-=(BigInteger b2);
    BigInteger& operator-=(const string& b2);
    BigInteger& operator-=(long long int b2);
    //pre
    BigInteger& operator++();
    //post
    BigInteger operator++(int dummy);
    //pre
    BigInteger& operator--();
    //post
    BigInteger operator--(int dummy);
    bool equals(const BigInteger& b2);
    bool equals(const string& b2);
    bool equals(long long int b2);
    bool lessThan(const BigInteger& b);
    bool operator < (const BigInteger& b);
    bool operator < (const string& b);
    bool operator < (long long int b);
    bool greaterThan(const BigInteger& b);
    bool operator > (const BigInteger& b);
    bool operator > (const string& b);
    bool operator > (long long int b);
    bool lessOrEqualTo(const BigInteger& b);
    bool operator <= (const BigInteger& b);
    bool operator <= (const string& b);
    bool operator <= (long long int b);
    bool greaterOrEqualTo(const BigInteger& b);
    bool operator >= (const BigInteger& b);
    bool operator >= (const string& b);
    bool operator >= (long long int b);
    bool equalTo(const BigInteger& b);
    bool operator == (const BigInteger& b);
    bool operator == (const string& b);
    bool operator == (long long int b);
    bool notEqualTo(const BigInteger& b);
    bool operator != (const BigInteger& b);
    bool operator != (const string& b);
    bool operator != (long long int b);
    static BigInteger abs(const BigInteger&);
    static BigInteger abs(string);
    static BigInteger abs(long long int);
    BigInteger operator<<(long long y) const;
    BigInteger operator>>(long long y) const;
    BigInteger singleMul(short b) const;
    BigInteger mul(const BigInteger& b2);
    BigInteger mul(const string& b2);
    BigInteger mul(long long int b2);
    BigInteger operator*(const BigInteger& b2);
    BigInteger operator*(const string& b2);
    BigInteger operator*(long long int b2);
    BigInteger& operator*=(const BigInteger& b2);
    BigInteger& operator*=(const string& b2);
    BigInteger& operator*=(long long int b2);
    static void getSignaledData(vector<short> &clubs, vector<jbyte>& data);
    static BigInteger value_of(long long int);
    static BigInteger value_of(string);
    static BigInteger value_of(BigInteger&);
    BigInteger pow(int);
    static BigInteger pow(BigInteger&,int);
    static BigInteger pow(string,int);
    static BigInteger pow(long long int,int);
    static BigInteger factorial(int);
    static BigInteger factorial(BigInteger);
    static BigInteger factorial(string);
    static BigInteger fibo(long long int);
    ll longlongValue() const;
    static ll longlongValue(const BigInteger&);

};



#endif //BIGINTEGERUSEVECTOR_BIGINTEGER_H
