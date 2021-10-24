#include "BigInteger.h"
using namespace std;
using namespace std::string_literals;
BigInteger::~BigInteger() = default;//并没有指针型对象，无需显式释放空间
BigInteger::BigInteger(long long int initNum) {
    if (initNum >= 0) {
        signum = true;
    }
    else {
        initNum = -initNum;
        signum = false;
    }
    int p = 4;
    ll tmp = initNum;
    tmp/=10000;
    while(tmp>0){
        tmp/=10000;
        p+=4;
    }
    int eff_size = p/4;
    this->mag = vector<int>(eff_size);
    putInObject(this->mag, initNum);
}
BigInteger::BigInteger(string initStr) {
    //ignore initStr such as "000123";
    if(initStr[0]=='+'){
        this->signum = true;
        initStr = string(initStr.begin()+1,initStr.end());
    }else if(initStr[0]=='-'){
        this->signum = false;
        initStr = string(initStr.begin()+1,initStr.end());
    }else{
        this->signum = true;
    }
    unsigned int size = initStr.size();
    size = size % 4==0?size/4:size/4+1;
    this->mag = vector<int>(size);
    putInObject(this->mag, initStr);
}
BigInteger::BigInteger(const BigInteger &bigInteger) {
    this->signum = bigInteger.signum;
    this->mag = vector<int>(bigInteger.mag);//like .assign()
}
BigInteger::BigInteger(){
    this->signum = true;
    this->mag = vector<int>(1, 0);
}

