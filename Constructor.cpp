//
// Created by hay boy on 2021/9/30.
//
#include "BigInteger.h"
#include "Utils.h"
using namespace std;
using namespace std::string_literals;
BigInteger::BigInteger(long long int initNum) {
    if (initNum >= 0) {
        over0 = true;
    }
    else {
        initNum = -initNum;
        over0 = false;
    }
    this->value = convertNumToString(initNum);
    this->effectiveLength = this->value.length();
    this->deploy = this->getDeploy();
}
BigInteger::BigInteger(const string& initWithString) {
    string initHelper = initWithString;
    size_t posFix = 0;
    if (initWithString == "-0") {
        this->value = "0";
        this->over0 = true;
        this->deploy = this->getDeploy();
        this->effectiveLength = 1;
        return;
    }
    if (initHelper[0] == '-') {
        //-12344
        //no -000989
        this->over0 = false;
        posFix = 1;
    }
    else if (initHelper[0] == '0') {
        //08990
        //0000798
        //0000
        size_t nonZeroBit;
        nonZeroBit = nonZero(string(initHelper));
        this->over0 = true;
        if (nonZeroBit == initHelper.length()) {
            this->value = "0";
        }
        else {
            this->value = string(initHelper.begin() + nonZeroBit, initHelper.end());
        }
        this->effectiveLength = this->value.length();
        this->deploy = this->getDeploy();
        return;

    }
    else if (initHelper[0] == '+') {
        //+9009
        //no +000789
        this->over0 = true;
        posFix = 1;
    }
    else {
        //989080
        this->over0 = true;
    }
    this->value = string(initHelper.begin() + posFix, initHelper.end());
    this->effectiveLength = this->value.length();
    this->deploy = this->getDeploy();
}
BigInteger::BigInteger(const string& initWithDeploy, bool simplifyDeploy) {
    vector<string> x = getOrigin(initWithDeploy);
    this->over0 = convertStringToBool(string(x[0]));
    this->value = string(x[1]);
    this->effectiveLength = this->value.length();
    if (simplifyDeploy) {
        if (this->value == "0") {
            this->over0 = true;
        }
        this->deploy = getDeploy();
    }
    else {
        this->deploy = string(initWithDeploy);
    }
}
BigInteger::BigInteger(const BigInteger& bi) {
    //拷贝构造函数，不应再函数前面添加explicit，即使它只有一个参数
    //似乎可以看作构造函数，即从BigInteger构造BigInteger
    this->over0 = bi.over0;
    this->value = bi.value;
    this->effectiveLength = bi.effectiveLength;
    this->deploy = bi.deploy;
}
