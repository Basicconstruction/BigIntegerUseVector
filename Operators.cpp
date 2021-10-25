#include "BigInteger.h"
using std::vector;
using std::list;
using std::deque;
BigInteger& BigInteger::operator = (const BigInteger& num)= default;
BigInteger& BigInteger::operator=(const long long int& num) {
    *this = BigInteger(num);
    return *this;
}
BigInteger &BigInteger::operator=(const string& num) {
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
BigInteger& BigInteger::operator+=(const long long int& num) {
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
BigInteger& BigInteger::operator-=(const long long int& num) {
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


BigInteger BigInteger::operator<<(long long int y) const {
    //bigger
    assert(y>=0);
    BigInteger b2 = *this;
    if(*this==0){
        return BigInteger(0);
    }
    if(y%4==0){
        vector<int> vi = b2.mag;
        deque<int> di(vi.begin(),vi.end());
        for(long long i = 0;i<y/4;i++){
            di.push_front(0);
        }
        b2.mag = vector<int>(di.begin(), di.end());
    }else{
        vector<int> vi = b2.mag;
        ostringstream os;
        std::vector<int>::const_reverse_iterator it = vi.rbegin();
        os<<(*it++);
        for(;it!=vi.rend();){
            int r = *it++;
            if(r>=1000){
                os<<r;
            }else if(r>=100){
                os<<"0"<<r;
            }else if(r>=10){
                os<<"00"<<r;
            }else{
                os<<"000"<<r;
            }
        }
        string s = os.str()+string(y%4,'0');
        vi.resize(s.length()%4==0?s.length()/4:s.length()/4+1);
        BigInteger::putInObject(vi,s);
        deque<int> di(vi.begin(),vi.end());
        y = y - y%4;
        for(long long i = 0;i<y/4;i++){
            di.push_front(0);
        }
        b2.mag = vector<int>(di.begin(), di.end());
    }
    return b2;
}

BigInteger& BigInteger::operator<<(helper isp){
    if(this->equals(BigInteger(0))){
        return *this;
    }
    int a[] = {0};
    copy(a,a+1,std::inserter(this->mag, this->mag.begin()));
    return *this;
}


BigInteger BigInteger::operator>>(const long long int& y) const {
    //smaller
    assert(y>=0);
    BigInteger b2 = *this;
    vector<int> vi = b2.mag;
    ostringstream os;
    std::vector<int>::const_reverse_iterator it = vi.rbegin();
    os<<short(*it);
    ++it;
    for(;it!=vi.rend();it++){
        int r = *it;
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
    b2.mag = vi;
    return b2;
}
BigInteger BigInteger::operator*(const BigInteger& b2)const{
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const string& b2)const{
    return this->mul(b2);
}
BigInteger BigInteger::operator*(const long long int& b2)const{
    return this->mul(b2);
}

BigInteger &BigInteger::operator*=(const BigInteger &b2) {
    (*this).mag = this->mul(b2).mag;
    return *this;
}

BigInteger &BigInteger::operator*=(const string &b2) {
    (*this).mag = this->mul(b2).mag;
    return *this;
}

BigInteger &BigInteger::operator*=(const long long int& b2) {
    (*this).mag = this->mul(b2).mag;
    return *this;
}


bool BigInteger::operator<(const string &b) const {
    BigInteger tmp(b);
    return this->lessThan(tmp);
}
bool BigInteger::operator < (const BigInteger& b) const {
    return this->compareTo(b) < 0;
}
bool BigInteger::operator<(const long long int& b) const {
    BigInteger tmp(b);
    return this->lessThan(tmp);
}


bool BigInteger::operator > (const BigInteger& b) const {
    return this->compareTo(b) > 0;
}
bool BigInteger::operator>(const string& b) const {
    BigInteger tmp(b);
    return this->greaterThan(tmp);
}
bool BigInteger::operator>(const long long int& b) const {
    BigInteger tmp(b);
    return this->greaterThan(tmp);
}


bool BigInteger::operator <= (const BigInteger& b) const {
    return this->compareTo(b) <= 0;
}
bool BigInteger::operator<=(const string& b) const {
    BigInteger tmp(b);
    return this->lessOrEqualTo(tmp);
}
bool BigInteger::operator<=(const long long int& b) const {
    BigInteger tmp(b);
    return this->lessOrEqualTo(tmp);
}


bool BigInteger::operator >= (const BigInteger& b) const {
    return this->compareTo(b) >= 0;
}
bool BigInteger::operator>=(const string& b) const {
    BigInteger tmp(b);
    return this->greaterOrEqualTo(tmp);
}
bool BigInteger::operator>=(const long long int& b) const {
    BigInteger tmp(b);
    return this->greaterOrEqualTo(tmp);
}

bool BigInteger::operator == (const BigInteger& b) const {
    return this->equals(b);
}
bool BigInteger::operator==(const string& b) const {
    BigInteger tmp(b);
    return this->equalTo(tmp);
}
bool BigInteger::operator==(const long long int& b) const {
    BigInteger tmp(b);
    return this->equalTo(tmp);
}

bool BigInteger::operator!=(const string &b) const {
    BigInteger tmp(b);
    return this->notEqualTo(tmp);
}

bool BigInteger::operator != (const BigInteger& b) const {
    return !this->equals(b);
}
bool BigInteger::operator!=(long long int b) const {
    BigInteger tmp(b);
    return this->notEqualTo(tmp);
}


BigInteger BigInteger::operator/(const BigInteger& num)const{
    return div(num);
}
BigInteger BigInteger::operator/(const long long int& num)const{
    return div(BigInteger(num));
}
BigInteger BigInteger::operator/(const string& num)const{
    return div(BigInteger(num));
}


BigInteger BigInteger::operator%(const BigInteger & num)const{
    return mod(num);
}
BigInteger BigInteger::operator%(const long long int& num)const{
    return mod(BigInteger(num));
}
BigInteger BigInteger::operator%(const string& num)const{
    return mod(BigInteger(num));
}


BigInteger BigInteger::operator+(const BigInteger &b2) const{
    return add(b2);
}
BigInteger BigInteger::operator+(const long long int& b2) const{
    return add(BigInteger(b2));
}
BigInteger BigInteger::operator+(const string& b2) const{
    return add(BigInteger(b2));
}


BigInteger BigInteger::operator-(const BigInteger &b2) const {
    return sub(BigInteger(b2));
}
BigInteger BigInteger::operator-(const long long int& b2) const {
    return sub(BigInteger(b2));
}
BigInteger BigInteger::operator-(const string& b2) const {
    return sub(BigInteger(b2));
}


BigInteger& BigInteger::operator/=(const BigInteger &num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator/=(const long long int& num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator/=(const string& num) {
    *this = div(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const BigInteger &num) {
    *this = mod(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const long long int& num) {
    *this = mod(num);
    return *this;
}

BigInteger& BigInteger::operator%=(const string& num) {
    *this = mod(num);
    return *this;
}

































