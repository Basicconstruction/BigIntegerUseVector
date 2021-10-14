//
// Created by hay boy on 2021/10/3.
//

#include "BigInteger.h"
using std::vector;
using std::list;
using std::deque;
BigInteger& BigInteger::operator = (const BigInteger& num)= default;
BigInteger& BigInteger::operator=(long long int num) {
    *this = BigInteger(num);
    return *this;
}
BigInteger &BigInteger::operator=(string num) {
    *this = BigInteger(num);
    return *this;
}
BigInteger BigInteger::operator+() const {
    return *this;
}

BigInteger BigInteger::operator-()const{
    BigInteger b2 = *this;
    b2.signum = !b2.signum;
    return b2;
}

BigInteger& BigInteger::operator+=(const BigInteger& num) {
    *this = this->add(num);
    return *this;
}
BigInteger& BigInteger::operator+=(const string&num) {
    *this = this->add(num);
    return *this;
}
BigInteger& BigInteger::operator+=(const long long int num) {
    *this = this->add(num);
    return *this;
}
BigInteger& BigInteger::operator-=(const BigInteger& num) {
    *this = this->sub(num);
    return *this;
}
BigInteger& BigInteger::operator-=(const string& num) {
    *this = this->sub(num);
    return *this;
}
BigInteger& BigInteger::operator-=(const long long int num) {
    *this = this->sub(num);
    return *this;
}
//pre
BigInteger& BigInteger::operator++() {
    (*this) += 1;
    return *this;
}
//post
BigInteger BigInteger::operator++(int dummy) {
    BigInteger x = *this;
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
bool BigInteger::operator < (const BigInteger& b) const {
    return this->compareTo(b) < 0;
}
bool BigInteger::operator > (const BigInteger& b) const {
    return this->compareTo(b) > 0;
}
bool BigInteger::operator <= (const BigInteger& b) const {
    return this->compareTo(b) <= 0;
}
bool BigInteger::operator >= (const BigInteger& b) const {
    return this->compareTo(b) >= 0;
}
bool BigInteger::operator == (const BigInteger& b) {
    return this->equals(b);
}
bool BigInteger::operator != (const BigInteger& b) {
    return !this->equals(b);
}

BigInteger BigInteger::operator<<(long long int y) const {
    //bigger
    assert(y>=0);
    BigInteger b2 = *this;
    if(y%2==0){
        vector<jbyte> vi = b2.value;
        deque<jbyte> di(vi.begin(),vi.end());
        for(long long i = 0;i<y/2;i++){
            di.push_front(0);
        }
        b2.value = vector<jbyte>(di.begin(),di.end());
    }else{
        vector<jbyte> vi = b2.value;
        ostringstream os;
        std::vector<jbyte>::const_reverse_iterator it = vi.rbegin();
        os<<short(*it);
        ++it;
        for(;it!=vi.rend();it++){
            jbyte r = *it;
            if(int(r)>=10){
                os<<(short)r;
            }else{
                os<<0<<short(r);
            }
        }
        string s = os.str()+'0';
        vi.resize(s.length()%2==0?s.length()/2:s.length()/2+1);
        BigInteger::putInObject(vi,s);
        deque<jbyte> di(vi.begin(),vi.end());
        y = y - 1;
        for(long long i = 0;i<y/2;i++){
            di.push_front(0);
        }
        b2.value = vector<jbyte>(di.begin(),di.end());
    }
    return b2;
}

BigInteger BigInteger::operator>>(long long int y) const {
    //smaller
    assert(y>=0);
    BigInteger b2 = *this;
    vector<jbyte> vi = b2.value;
    ostringstream os;
    std::vector<jbyte>::const_reverse_iterator it = vi.rbegin();
    os<<short(*it);
    ++it;
    for(;it!=vi.rend();it++){
        jbyte r = *it;
        if(int(r)>=10){
            os<<(short)r;
        }else{
            os<<0<<short(r);
        }
    }
    string s = os.str();
    if(y>=s.length()){
        return BigInteger(0);
    }
    size_t len_new = s.length() - y;
    vi.resize(len_new%2==0?len_new/2:len_new/2+1);
    BigInteger::putInObject(vi,string(s.begin(),s.begin()+int(len_new)));
    b2.value = vi;
    return b2;
}
BigInteger BigInteger::operator*(const BigInteger& b2)const{
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const string& b2)const{
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const long long int b2)const{
    return this->mul(b2);
}

BigInteger &BigInteger::operator*=(const BigInteger &b2) {
    (*this).value = this->mul(b2).value;
    return *this;
}

BigInteger &BigInteger::operator*=(const string &b2) {
    (*this).value = this->mul(b2).value;
    return *this;
}

BigInteger &BigInteger::operator*=(long long int b2) {
    (*this).value = this->mul(b2).value;
    return *this;
}

bool BigInteger::operator<(const string &b) const {
    BigInteger tmp(b);
    return this->lessThan(tmp);
}

bool BigInteger::operator<(long long int b) const {
    BigInteger tmp(b);
    return this->lessThan(tmp);
}

bool BigInteger::operator>(const string &b) const {
    BigInteger tmp(b);
    return this->greaterThan(tmp);
}

bool BigInteger::operator>(long long int b) const {
    BigInteger tmp(b);
    return this->greaterThan(tmp);
}

bool BigInteger::operator<=(const string &b) const {
    BigInteger tmp(b);
    return this->lessOrEqualTo(tmp);
}

bool BigInteger::operator<=(long long int b) const {
    BigInteger tmp(b);
    return this->lessOrEqualTo(tmp);
}

bool BigInteger::operator>=(const string &b) const {
    BigInteger tmp(b);
    return this->greaterOrEqualTo(tmp);
}

bool BigInteger::operator>=(long long int b) const {
    BigInteger tmp(b);
    return this->greaterOrEqualTo(tmp);
}

bool BigInteger::operator==(const string &b) const {
    BigInteger tmp(b);
    return this->equalTo(tmp);
}

bool BigInteger::operator==(long long int b) const {
    BigInteger tmp(b);
    return this->equalTo(tmp);
}

bool BigInteger::operator!=(const string &b) const {
    BigInteger tmp(b);
    return this->notEqualTo(tmp);
}

bool BigInteger::operator!=(long long int b) const {
    BigInteger tmp(b);
    return this->notEqualTo(tmp);
}
BigInteger BigInteger::operator/(const BigInteger& num){
    return div(num);
}
BigInteger BigInteger::operator/(const long long int num){
    return div(BigInteger(num));
}
BigInteger BigInteger::operator/(string s){
    return div(BigInteger(s));
}
BigInteger BigInteger::operator%(const BigInteger & num){
    return mod(num);
}
BigInteger BigInteger::operator%(const long long int num){
    return mod(BigInteger(num));
}
BigInteger BigInteger::operator%(string num){
    return mod(BigInteger(num));
}
BigInteger BigInteger::operator+(const BigInteger &b2) const{
    return add(b2);
}

BigInteger BigInteger::operator+(const long long int b2) const{
    return add(BigInteger(b2));
}

BigInteger BigInteger::operator+(string b2) const{
    return add(BigInteger(b2));
}

BigInteger BigInteger::operator-(const BigInteger &b2) const {
    return sub(BigInteger(b2));
}

BigInteger BigInteger::operator-(const long long int b2) const {
    return sub(BigInteger(b2));
}

BigInteger BigInteger::operator-(string b2) const {
    return sub(BigInteger(b2));
}
BigInteger& BigInteger::operator/=(const BigInteger &num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator/=(const long long int num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator/=(string num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const BigInteger &num) {
    *this = mod(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const long long int num) {
    *this = mod(num);
    return *this;
}

BigInteger& BigInteger::operator%=(string num) {
    *this = mod(num);
    return *this;
}





























