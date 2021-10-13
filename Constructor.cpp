//
// Created by hay boy on 2021/9/30.
//
#include "BigInteger.h"
#include "Utils.h"
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
    int p = 2;
    ll tmp = initNum;
    tmp/=100;
    while(tmp>0){
        tmp/=100;
        p+=2;
    }
    int eff_size = p/2;
    this->value = vector<jbyte>(eff_size);
    putInObject(this->value,initNum);
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
    size = size % 2==0?size/2:size/2+1;
    this->value = vector<jbyte>(size);
    putInObject(this->value,initStr);
}
BigInteger::BigInteger(const BigInteger &bigInteger) {
    this->signum = bigInteger.signum;
    this->value = vector<jbyte>(bigInteger.value);//like .assign()
}
BigInteger::BigInteger(){
    this->signum = true;
    this->value = vector<jbyte>(1,0);
}

