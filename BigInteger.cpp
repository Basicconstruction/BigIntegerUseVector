#include <iterator>
#include "BigInteger.h"
using namespace std;
using namespace std::string_literals;
ostream& operator<<(ostream& os,const BigInteger & num){
    char fillc = os.fill('0');
    auto it = num.value.rbegin();
    if(!num.signum){
        os<<"-";
    }
    os<<short(*it++);
    for(;it!=num.value.rend();it++){
        os<<std::setw(2)<<short(*it);
    }
    os<<setfill(fillc);
    return os;
}
istream &operator>>(istream & is, BigInteger & num) {
    string s;
    getline(cin,s,'\n');
    BigInteger tmp(s);
    num.signum = tmp.signum;
    num.value = tmp.value;
    return is;
}

void BigInteger::putInObject(vector<jbyte>& value,ll transferredValue){
    typedef vector<jbyte>::iterator vji;
    for(unsigned char & it : value){
        it = static_cast<jbyte>(transferredValue%100);
        transferredValue/=100;
    }
}
string BigInteger::toString() const{
    return BigInteger::toString(*this);
}
string BigInteger::toString(const BigInteger& bigInteger){
    string s;
    s+= bigInteger.signum ? "" : "-";
    ostringstream os;
    std::vector<jbyte>::const_reverse_iterator it = bigInteger.value.rbegin();
    os<<short(*it);
    ++it;
    for(;it!=bigInteger.value.rend();it++){
        jbyte r = *it;
        if(int(r)>=10){
            os<<(short)r;
        }else{
            os<<0<<short(r);
        }
    }
    s+= os.str();
    return s;
}
void BigInteger::printSelf() const {
    BigInteger::printSelf(*this);
}
void BigInteger::printSelf(const BigInteger& bigInteger){
    std::ostream_iterator<int> out(std::cout," ");
    copy(bigInteger.value.begin(),bigInteger.value.end(),out);
    std::cout<<((bigInteger.signum)?'+':'-')<<std::endl;
}

void BigInteger::putInObject(vector<jbyte> &value,const string& transferredValue){
    typedef vector<jbyte>::reverse_iterator vji;
    typedef string::const_iterator si;
    vji it = value.rbegin();
    si sit = transferredValue.begin();
    if(transferredValue.length()%2!=0){
        *it = static_cast<jbyte>(static_cast<short>(*sit-'0'));
        it++;sit++;
    }
    for(;it!=value.rend();it++){
        *it = static_cast<jbyte>(static_cast<short>(*sit-'0')*10+static_cast<short>(*(++sit)-'0'));
        sit++;
    }
}

int BigInteger::compareTo(vector<jbyte> v1, vector<jbyte> v2) {
    //假设每个序列都是数据完好的，比如0->[0]而不会是[0][0][0],如果这样会使得错误的快捷比较。这是需要保证的。
    typedef vector<jbyte>::reverse_iterator VJi;
    if(v1.size()>v2.size()){
        return 1;
    }else if(v1.size()<v2.size()){
        return -1;
    }else{
        VJi it1 = v1.rbegin();
        VJi it2 = v2.rbegin();
        for(;it1!=v1.rend();it1++,it2++){
            if(*it1>*it2){
                return 1;
            }else if(*it1<*it2){
                return -1;
            }
        }
        return 0;

    }
}
BigInteger BigInteger::value_of(const long long int& num) {
    return BigInteger(num);
}
BigInteger BigInteger::value_of(const string& num) {
    return BigInteger(num);
}
BigInteger BigInteger::value_of(const BigInteger &num) {
    return num;
}
BigInteger BigInteger::pow(int times){
    return BigInteger::pow(*this,times);
}
BigInteger BigInteger::pow(BigInteger& bigInteger, const int& times) {
    if(times == 0){
        return BigInteger::value_of(1);
    }else if(times == 1){
        return bigInteger;
    }
    BigInteger res;
    res = 1;
    for(int i = 0; i < times; i++){
        res *= bigInteger;
    }
    return res;
}
BigInteger BigInteger::pow(const string& num, const int& times) {
    BigInteger tmp(num);
    return BigInteger::pow(tmp,times);
}

BigInteger BigInteger::pow(const long long int& num, const int& times) {
    BigInteger tmp(num);
    return BigInteger::pow(tmp,times);
}

BigInteger BigInteger::factorial(BigInteger num) {
    if(num == 0){
        return BigInteger(1);
    }
    BigInteger res;
    for(;num>=1;num--){
        res *= num;
    }
    return res;
}

BigInteger BigInteger::factorial(const string& num) {
    return BigInteger::factorial(BigInteger(num));
}
BigInteger BigInteger::factorial(const int& num) {
    if(num==0||num==1){
        return BigInteger(1);
    }
    BigInteger res(1);
    for(int i = 2;i<num;i++){
        res *= BigInteger(i);
    }
    return res;
}
BigInteger BigInteger::fibo(const long long int& p) {
    if (p == 0) {
        return BigInteger(0);
    } else if (p == 1) {
        return BigInteger(1);
    } else {
        BigInteger x(1);
        BigInteger y(0);
        BigInteger z(1);
        for (int h = 2; h <= p; h++) {
            x = y;
            y = z;
            z = x.add(y);
        }
        return z;
    }
}
ll BigInteger::longlongValue() const {
    return BigInteger::longlongValue(*this);
}
ll BigInteger::longlongValue(const BigInteger &num) {
    ll res = 0;
    vector<jbyte>::const_reverse_iterator it = num.value.rbegin();
    res += (*it++);
    while(it!=num.value.rend()){
        res *= 100;
        res += *it;
        it++;
    }
    return res;
}

short divHelp(BigInteger &b1, const BigInteger &b2){
    for (short k = 2; k <= 9; ++k) {
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
long long int BigInteger::toLonglongValue()const{
    long long int res = 0;
    vector<jbyte> vec = (*this).value;
    vector<jbyte>::const_reverse_iterator it = vec.rbegin();
    while(it!=vec.rend()){
        res *= 100;
        res += (*it);
        it++;
    }
    return this->signum?res:-res;
}














