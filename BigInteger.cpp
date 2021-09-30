//
// Created by hay boy on 2021/9/30.
//

#include "BigInteger.h"
using namespace std;
using namespace std::string_literals;
string BigInteger::getDeploy() const {
    if (this->over0) {
        return "0" + this->value;
    }
    size_t length = this->effectiveLength;
    string deployTemp;
    size_t p;
    size_t push = 0;
    size_t endBit = 10 - convertCharToInt(string(this->value)[length - 1]);
    if (endBit == 10) {
        deployTemp = '0';
        push = 1;
    }
    else {
        deployTemp = convertIntToChar(endBit);
    }
    for (int iter = 2; iter <= length; ++iter) {
        p = length - iter;
        endBit = 9 - convertCharToInt(string(this->value)[p]) + push;
        if (endBit == 10) {
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
void BigInteger::toString() {
    //用于对齐
    if (this->over0) {
        printf("symbol:BigInteger\nover0: %s\nvalue:  %s \ndeploy: %s\neffectLength: %d\n", convertBoolToString(this->over0).c_str(), this->getValue().c_str(), this->deploy.c_str(), this->effectiveLength);
    }
    else {
        printf("symbol:BigInteger\nover0: %s\nvalue: %s \ndeploy: %s\neffectLength: %d\n", convertBoolToString(this->over0).c_str(), this->getValue().c_str(), this->deploy.c_str(), this->effectiveLength);
    }
}
void BigInteger::getDetails() {
    this->toString();
}
BigInteger BigInteger::add(const BigInteger& b2) const {
    const BigInteger b1(this->deploy, true);
    size_t l1 = b1.effectiveLength;
    size_t l2 = b2.effectiveLength;
    string effects1, effects2;
    effects1 = b1.deploy;
    effects2 = b2.deploy;
    effects1 = string(effects1.begin() + 1, effects1.end());
    effects2 = string(effects2.begin() + 1, effects2.end());
    if (l1 >= l2) {
        if (b2.over0) {
            effects2 = (string(b2.deploy))[0] + string(l1 - l2, '0') + effects2;
        }
        else {
            effects2 = (string(b2.deploy))[0] + string(l1 - l2, '9') + effects2;
        }
        effects1 = (string(b1.deploy))[0] + effects1;
    }
    else {
        if (b1.over0) {
            effects1 = (string(b1.deploy))[0] + string(l2 - l1, '0') + effects1;
        }
        else {
            effects1 = (string(b1.deploy))[0] + string(l2 - l1, '9') + effects1;
        }
        effects2 = (string(b2.deploy))[0] + effects2;
    }
    size_t push = 0;
    size_t temp;
    size_t n1;
    size_t n2;
    string deployed;
    size_t ll = effects1.length();
    assert(ll == effects1.length());
    for (size_t j = 0; j < ll; j++) {
        n1 = convertCharToInt(effects1[ll - j - 1]);
        n2 = convertCharToInt(effects2[ll - j - 1]);
        temp = n1 + n2 + push;
        push = 0;
        if (temp >= 10) {
            push = 1;
        }
        temp = temp % 10;
        deployed = convertIntToChar(temp) + deployed;
    }
    if (b1.over0 && b2.over0 && deployed[0] == '1') {
        deployed = '0' + deployed;
    }
    vector<string> x = getOrigin(deployed);
    return BigInteger(simplifyBigIntegerValue(convertStringToBool(string(x[0])) ? x[1] : '-' + x[1]));
}
BigInteger BigInteger::add(const string& b2) const {
    BigInteger b1 = BigInteger(this->deploy);
    BigInteger bx = BigInteger(b2, true);
    return b1.add(bx);
}
BigInteger BigInteger::add(const long long int b2) const {
    BigInteger b1 = BigInteger(this->deploy);
    BigInteger bx = BigInteger(b2);
    return b1.add(bx);
}
BigInteger BigInteger::operator+() const {
    return *this;
}
BigInteger BigInteger::operator-() const {
    return BigInteger(this->over0 ? '-' + this->value : this->value);
}
BigInteger BigInteger::sub(const BigInteger& b2) const {
    return this->add(-b2);
}
BigInteger BigInteger::sub(const string& b2) const {
    return this->add(-BigInteger(b2));
}
BigInteger BigInteger::sub(long long int b2) const {
    return this->add(-BigInteger(b2));
}
BigInteger BigInteger::operator+(const BigInteger& b2) const {
    return this->add(b2);
}
BigInteger BigInteger::operator+(const string& b2) const {
    return this->add(BigInteger(b2));
}
BigInteger BigInteger::operator+(const long long int b2) const {
    return this->add(BigInteger(b2));
}
//pre
BigInteger& BigInteger::operator++() {
    (*this) += 1;
    return *this;
}
//post
BigInteger BigInteger::operator++(int dummy) {
    const BigInteger x = BigInteger(*this);
    (*this) += 1;
    return x;
}
//pre
BigInteger& BigInteger::operator--() {
    (*this) -= 1;
    return *this;
}
//post
BigInteger BigInteger::operator--(int dummy) {
    BigInteger x = BigInteger(*this);
    (*this) -= 1;
    return x;
}
BigInteger BigInteger::operator-(const BigInteger& b2) const {
    return this->sub(b2);
}
BigInteger BigInteger::operator-(const string& b2) const {
    return this->sub(b2);
}
BigInteger BigInteger::operator-(const long long int b2) const {
    return this->sub(b2);
}
char BigInteger::operator[](size_t index) const {
    assert(index + 1 <= this->value.length());
    return this->value[index];
}
BigInteger& BigInteger::operator+=(const BigInteger& b2) {
    *this = this->add(b2);
    return *this;
}
BigInteger& BigInteger::operator+=(const string& b2) {
    *this = this->add(b2);
    return *this;
}
BigInteger& BigInteger::operator+=(const long long int b2) {
    *this = this->add(b2);
    return *this;
}
BigInteger& BigInteger::operator-=(const BigInteger& b2) {
    *this = this->sub(b2);
    return *this;
}
BigInteger& BigInteger::operator-=(const string& b2) {
    *this = this->sub(b2);
    return *this;
}
BigInteger& BigInteger::operator-=(const long long int b2) {
    *this = this->sub(b2);
    return *this;
}

int BigInteger::compareTo(const BigInteger& b2) {
    //注意要比较的是有效值长度
    int y = 2;
    if (this->over0 && (!b2.over0)) {
        return 1;
    }
    if ((!this->over0) && b2.over0) {
        return -1;
    }
    if (this->value.length() > b2.value.length()) {
        y = 3;
    }
    else if (this->value.length() < b2.value.length()) {
        y = 1;
    }
    else {
        for (unsigned int c = 0; c < this->value.length(); c++) {
            if (this->value[c] > b2.value[c]) {
                y = 3;
                break;
            }
            else if (this->value[c] < b2.value[c]) {
                y = 1;
                break;
            }
            else {
                continue;
            }
        }
    }
    if (y == 2) {
        return 0;
    }
    if (this->over0) {
        if (y == 3) {
            return 1;
        }
        else {
            return -1;
        }
    }
    else {
        if (y == 3) {
            return -1;
        }
        else {
            return 1;
        }
    }
}
int BigInteger::compareTo(const string& b2) {
    const BigInteger t(b2);
    return this->compareTo(t);
}
int BigInteger::compareTo(const long long int b2) {
    const BigInteger t(b2);
    return this->compareTo(t);
}
//-- ++ equals()
bool BigInteger::equals(const BigInteger& b2) {
    if (this->compareTo(b2) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool BigInteger::equals(const string& b2) {
    if (this->compareTo(b2) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool BigInteger::equals(const long long int b2) {
    if (this->compareTo(b2) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool BigInteger::operator < (const BigInteger& b) {
    return this->compareTo(b) < 0;
}
bool BigInteger::operator > (const BigInteger& b) {
    return this->compareTo(b) > 0;
}
bool BigInteger::operator <= (const BigInteger& b) {
    return this->compareTo(b) <= 0;
}
bool BigInteger::operator >= (const BigInteger& b) {
    return this->compareTo(b) >= 0;
}
bool BigInteger::operator == (const BigInteger& b) {
    return this->equals(b);
}
bool BigInteger::operator != (const BigInteger& b) {
    return !this->equals(b);
}
BigInteger& BigInteger::operator<<(const long long int x) {
    assert(x >= 0);
    BigInteger t(this->over0 ? this->value + string(x, '0') : '-' + this->value + string(x, '0'));
    this->value = t.value;
    this->deploy = t.deploy;
    this->effectiveLength = t.effectiveLength;
    return *this;
}
BigInteger BigInteger::operator<<(const string& y) const {
    //这个并非是为冗余重载设计，而是用于提供一个不改变原对象（返回新对象）的方法
    long long int x = convertStringToLong(y);
    assert(x >= 0);
    BigInteger t(this->over0 ? this->value + string(x, '0') : '-' + this->value + string(x, '0'));
    return t;
}
BigInteger& BigInteger::operator>>(const long long int x) {
    assert(x >= 0);
    if (x >= this->effectiveLength) {
        this->value = "0";
        this->deploy = "00";
        this->effectiveLength = 1;
        return *this;
    }
    else {
        BigInteger t(this->over0 ? string((this->value).begin(), (this->value).end() - x) : '-' + string((this->value).begin(), (this->value).end() - x));
        this->value = t.value;
        this->deploy = t.deploy;
        this->effectiveLength = t.effectiveLength;
        return *this;
    }
}
BigInteger BigInteger::operator>>(const string& b) {
    //这个并非是为冗余重载设计，而是用于提供一个不改变原对象（返回新对象）的方法
    long long int x = convertStringToLong(b);
    assert(x >= 0);
    if (x >= this->effectiveLength) {
        return BigInteger(0);
    }
    else {
        BigInteger t(this->over0 ? string((this->value).begin(), (this->value).end() - x) : '-' + string((this->value).begin(), (this->value).end() - x));
        return t;
    }
}
string BigInteger::getValue() const {
    return over0 ? this->value : '-' + this->value;
}
BigInteger BigInteger::singleMul(const unsigned int b) const {
    string c;
    string b1 = this->value;
    size_t le = b1.length();
    size_t push = 0;
    size_t multi;
    for (size_t h = 0; h < le; h++) {
        multi = convertCharToInt(b1[le - h - 1]) * b + push;
        c = convertIntToChar(multi % 10) + c;
        push = multi / 10 % 10;
    }
    c = convertIntToChar(push) + c;
    return BigInteger(c);
}
BigInteger BigInteger::mul(const BigInteger& b2) {
    BigInteger c(0);
    BigInteger c2(*this);
    const string b3 = b2.value;
    for (size_t h = 0; h < b2.value.length(); ++h) {
        c = c + (c2 << (convertNumToString(h))).singleMul(convertCharToInt(b3[b2.value.length() - h - 1]));
    }
    if ((this->over0 && b2.over0) || ((!this->over0) && (!b2.over0))) {
        c.over0 = true;
    }
    else {
        c.over0 = false;
    }
    c.deploy = c.getDeploy();
    return c;
}
BigInteger BigInteger::mul(const string& b2) {
    return this->mul(BigInteger(b2));
}
BigInteger BigInteger::mul(const long long int b2) {
    return this->mul(BigInteger(b2));
}
BigInteger BigInteger::operator*(const BigInteger& b2) {
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const string& b2) {
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const long long int b2) {
    return this->mul(b2);
}
BigInteger& BigInteger::operator*=(const BigInteger& b2) {
    BigInteger x = this->mul(b2);
    this->over0 = x.over0;
    this->value = x.value;
    this->deploy = x.deploy;
    this->effectiveLength = x.effectiveLength;
    return *this;
}
BigInteger& BigInteger::operator*=(const string& b2) {
    BigInteger x = this->mul(b2);
    this->over0 = x.over0;
    this->value = x.value;
    this->deploy = x.deploy;
    this->effectiveLength = x.effectiveLength;
    return *this;
}
BigInteger& BigInteger::operator*=(const long long int b2) {
    BigInteger x = this->mul(b2);
    this->over0 = x.over0;
    this->value = x.value;
    this->deploy = x.deploy;
    this->effectiveLength = x.effectiveLength;
    return *this;
}
BigInteger& BigInteger::toAbs(){
    this->over0 = true;
    this->deploy = this->getDeploy();
    return *this;
}
BigInteger BigInteger::div(BigInteger b2) {
    if (b2.value == "1") {
        return *this;
    }
    bool b2_over0 = b2.over0;
    b2.toAbs();
    if (BigInteger::abs(*this) < b2) {
        return BigInteger(0);
    }
    BigInteger dh = BigInteger::abs(*this);
    size_t l1 = this->value.length();
    //1000
    //div 35
    size_t p=0;
    string get;
    for (p; p < l1;) {
        if (BigInteger(string(dh.value.begin(), dh.value.begin() + 1 + p)) < b2) {
            p++;
        }
        else {
            break;
        }
    }
    auto* t = new BigInteger(string(dh.value.begin(), dh.value.begin() + 1 + p));
    size_t newp = p;
    size_t cal;
    while (true) {
        if (*t < b2) {
            get.append("0");
        }
        else {
            cal = divHelp(*t, b2);
            get.append(convertNumToString(cal));
        }
        dh -= ((b2 * cal) << (l1 - 1 - newp));
        if (get.length() == l1 - p) {
            break;
        }
        newp++;
        *t = ((*t - (b2 * cal)) << 1) + convertCharToInt((*this)[newp]);
        cal = 0;
    }
    assert(get.length() == l1 - p);//默认查错
    get = same(this->over0, b2_over0) ? get : '-' + get;
    return BigInteger(get);
}
BigInteger BigInteger::operator %(BigInteger b2) {
    //b2 > 0
    b2.toAbs();
    if (BigInteger::abs(*this) < b2) {
        return BigInteger(0);
    }
    BigInteger dh = BigInteger::abs(*this);
    size_t l1 = this->value.length();
    size_t l2 = b2.value.length();
    //1000
    //div 35
    size_t p=0;
    size_t get = 0;
    for (; p < l1;) {
        if (BigInteger(string(dh.value.begin(), dh.value.begin() + 1 + p)) < b2) {
            p++;
        }
        else {
            break;
        }
    }
    BigInteger* t = new BigInteger(string(dh.value.begin(), dh.value.begin() + 1 + p));
    size_t newp = p;
    size_t cal;
    while (true) {
        if (*t < b2) {
        }
        else {
            cal = divHelp(*t, b2);
        }
        dh -= ((b2 * cal) << (l1 - newp - 1));
        get += 1;
        if (get == l1 - p) {
            break;
        }
        newp++;
        *t = ((*t - (b2 * cal)) << 1) + convertCharToInt((*this)[newp]);
        cal = 0;
    }
    assert(get == l1 - p);//默认查错
    return (*this).over0 ? dh : -dh;
}
BigInteger BigInteger::operator % (const string& b2) {
    return *this % BigInteger(b2);
}
BigInteger BigInteger::operator % (const long long int b2) {
    return *this % BigInteger(b2);
}
BigInteger& BigInteger::operator %=(const BigInteger& b2) {
    *this = (*this) % b2;
    return (*this);
}
BigInteger& BigInteger::operator %=(const string& b2) {
    *this = (*this) % b2;
    return (*this);
}
BigInteger& BigInteger::operator %=(const long long int b2) {
    *this = (*this) % b2;
    return (*this);
}
BigInteger BigInteger::div(const string& b2) {
    BigInteger b(b2);
    return this->div(b);
}
BigInteger BigInteger::div(const long long int b2) {
    BigInteger b(b2);
    return this->div(b);
}
BigInteger BigInteger::operator / (const BigInteger& b2) {
    return this->div(b2);
}
BigInteger BigInteger::operator / (const string& b2) {
    BigInteger b(b2);
    return this->div(b);
}
BigInteger BigInteger::operator / (const long long int b2) {
    BigInteger b(b2);
    return this->div(b);
}
BigInteger& BigInteger::operator /= (const BigInteger& b) {
    *this = this->div(b);
    return *this;
}
BigInteger& BigInteger::operator /= (const string& b) {
    *this = this->div(b);
    return *this;
}
BigInteger& BigInteger::operator /= (const long long int b) {
    *this = this->div(b);
    return *this;
}
BigInteger BigInteger::sqrt() {
    BigInteger res(1);
    bool t = true;
    while (t) {
        res =(res + (*this) / res)/ 2;
        t = (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) || (res * res >= (*this) && (res - 1) * (res - 1) < (*this));
        t = !t;
    }
    return (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ? res : res - 1;
}
BigInteger BigInteger::pow(unsigned int x){
    assert(x>0);
    BigInteger tmp = BigInteger(*this);
    BigInteger res(1);
    for(int i = 1;i<x;i++){
        res *= tmp;
    }
    return res;
}

