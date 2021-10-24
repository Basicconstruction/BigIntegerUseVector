#include <iterator>
#include "BigInteger.h"
using namespace std;
using namespace std::string_literals;
ostream& operator<<(ostream& os,const BigInteger & num){
    char fillc = os.fill('0');
    auto it = num.mag.rbegin();
    if(!num.signum){
        os<<"-";
    }
    os<<*it++;
    for(;it!=num.mag.rend(); it++){
        os<<std::setw(4)<<*it;
    }
    os<<setfill(fillc);
    return os;
}
istream &operator>>(istream & is, BigInteger & num) {
    string s;
    getline(cin,s,'\n');
    BigInteger tmp(s);
    num.signum = tmp.signum;
    num.mag = tmp.mag;
    return is;
}

void BigInteger::putInObject(vector<int>& value,ll transferredValue){
    for(int & it : value){
        it = static_cast<int>(transferredValue%10000);
        transferredValue/=10000;
    }
}
string BigInteger::toString() const{
    return BigInteger::toString(*this);
}
string BigInteger::toString(const BigInteger& bigInteger){
    string s;
    s+= bigInteger.signum ? "" : "-";
    ostringstream os;
    std::vector<int>::const_reverse_iterator it = bigInteger.mag.rbegin();
    os<<*it;
    ++it;
    for(;it!=bigInteger.mag.rend(); it++){
        int r = *it;
        if(r>=1000){
            os<<r;
        }else if(r>=100){
            os<<0<<r;
        }else if(r>=10){
            os<<"00"<<r;
        }else{
            os<<"000"<<r;
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
    copy(bigInteger.mag.begin(), bigInteger.mag.end(), out);
    std::cout<<((bigInteger.signum)?'+':'-')<<std::endl;
}

void BigInteger::putInObject(vector<int> &value,const string& transferredValue){
    typedef vector<int>::reverse_iterator vri;
    typedef string::const_iterator sci;
    vri it = value.rbegin();
    sci sit = transferredValue.begin();
    int first = transferredValue.length()%4;
    if(first!=0){
        int res = 0;
        while(first--){
            res *= 10;
            res += static_cast<int>(static_cast<short>(*sit++-'0'));
        }
        *it = res;
        it++;
    }
    for(;it!=value.rend();it++){
        *it = static_cast<int>(*sit-'0')*1000+static_cast<int>(*(++sit)-'0')*100
                +static_cast<int>(*(++sit)-'0')*10+static_cast<int>(*(++sit)-'0');
        sit++;
    }
}

int BigInteger::compareTo(vector<int> v1, vector<int> v2) {
    //假设每个序列都是数据完好的，比如0->[0]而不会是[0][0][0],如果这样会使得错误的快捷比较。这是需要保证的。
    typedef vector<int>::reverse_iterator VJi;
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
BigInteger BigInteger::pow(const BigInteger& bigInteger, const int& times) {
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
    vector<int>::const_reverse_iterator it = num.mag.rbegin();
    res += (*it++);
    while(it!=num.mag.rend()){
        res *= 10000;
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
    vector<int> vec = (*this).mag;
    vector<int>::const_reverse_iterator it = vec.rbegin();
    while(it!=vec.rend()){
        res *= 100;
        res += (*it);
        it++;
    }
    return this->signum?res:-res;
}



