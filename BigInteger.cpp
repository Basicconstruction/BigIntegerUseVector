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
    char c;
    cin>>c;
    string s;
    if(c=='+'){
        cin>>s;
    }else if(c=='-'){
        cin>>s;
        s.insert(0,"-");
    }else if(c>='0'&&c<='9'){
        cin>>s;
        s.insert(0,string(1,c));
    }else{
        is.setstate(std::ios::failbit);
        cerr<<"error when revolve the input chars\n";
        return is;
    }
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

void BigInteger::putInObject(vector<jbyte> &value,string transferredValue){
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
BigInteger BigInteger::value_of(long long int num) {
    return BigInteger(num);
}
BigInteger BigInteger::value_of(string num) {
    return BigInteger(num);
}
BigInteger BigInteger::value_of(BigInteger &num) {
    return num;
}
BigInteger BigInteger::pow(int times){
    return BigInteger::pow(*this,times);
}
BigInteger BigInteger::pow(BigInteger& bigInteger, int times) {
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
BigInteger BigInteger::pow(string num, int times) {
    BigInteger tmp(num);
    return BigInteger::pow(tmp,times);
}

BigInteger BigInteger::pow(long long int num, int times) {
    BigInteger tmp(num);
    return BigInteger::pow(tmp,times);
}

BigInteger BigInteger::factorial(BigInteger num) {
    if(num==0||num==1){
        return BigInteger(1);
    }
    BigInteger res;
    for(;num>=1;num--){
        res *= num;
    }
    return res;
}

BigInteger BigInteger::factorial(string num) {
    return BigInteger::factorial(BigInteger(num));
}
BigInteger BigInteger::factorial(int num) {
    if(num==0||num==1){
        return BigInteger(1);
    }
    BigInteger res(1);
    for(int i = 2;i<num;i++){
        res *= BigInteger(i);
    }
    return res;
}
BigInteger BigInteger::fibo(long long int p) {
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














