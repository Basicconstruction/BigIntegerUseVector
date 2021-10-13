//
// Created by hay boy on 2021/10/3.
//
#include <iterator>
#include "BigInteger.h"
typedef std::vector<jbyte>::iterator vji;
typedef std::vector<jbyte>::reverse_iterator vjri;
typedef std::vector<short>::iterator vsi;
typedef std::vector<short>::reverse_iterator vsri;
BigInteger& BigInteger::add(const BigInteger &num){
    short carry = 0;
    vector<jbyte> tem = this->value;
    vector<jbyte> added = num.value;
    vector<jbyte> longOne,shortOne;
    if((this->signum&&num.signum)||(!this->signum&&!num.signum)){
        if(tem.size()>=added.size()){
            longOne = tem;
            shortOne = added;
        }else{
            longOne = added;
            shortOne = tem;
        }
        vji it = longOne.begin();
        vji it2 = shortOne.begin();
        for(;it!=longOne.end();it++){
            if(it2!=shortOne.end()){
                short tmp = (*it) + (*it2) + carry;
                if(tmp>=100){
                    carry = 1;
                    *it = jbyte(tmp - 100);
                }else{
                    carry = 0;
                    *it = tmp;
                }
                it2 ++;
            }else{
                short tmp = (*it) + carry;
                if(tmp>=100){
                    carry = 1;
                    *it = jbyte(tmp - 100);
                }else{
                    carry = 0;
                    *it = tmp;
                }
            }
        }
        if(carry>0){
            longOne.push_back(1);
        }
        this->value.swap(longOne);
        return *this;
    }else{
        int res = compareTo(tem,added);
        if(res==0){
            *this = BigInteger(0);
            return *this;
        }else if(res==1){
            longOne = tem;
            shortOne = added;
        }else{
            this->signum = !this->signum;
            longOne = added;
            shortOne = tem;
        }
        vji it = longOne.begin();
        vji it2 = shortOne.begin();
        for(;it!=longOne.end();it++){
            if(it2!=shortOne.end()){
                short tmp = (*it) - (*it2) - carry;
                if(tmp<0){
                    tmp = tmp + 100;
                    carry = 1;
                }else{
                    carry = 0;
                }
                *it = tmp;
                it2 ++;
            }else{
                short tmp = (*it) - carry;
                if(tmp<0){
                    tmp = tmp + 100;
                    carry = 1;
                }else{
                    carry = 0;
                }
                *it = tmp;
            }
        }
        assert(carry==0);
        this->value.swap(longOne);
        std::vector<jbyte>::iterator back_i = this->value.end()-1;
        for(;back_i!=this->value.begin();back_i--){
            if(*back_i==0){
                this->value.erase(back_i);
            }else{
                break;
            }
        }
        return *this;

    }
}
BigInteger& BigInteger::add(long long int num){
    BigInteger b2(num);
    return add(b2);
}
BigInteger& BigInteger::add(const string &num){
    BigInteger b2(num);
    return add(b2);
}
int BigInteger::compareTo(const BigInteger &num)const{
    if(this->signum&&!num.signum){
        return 1;
    }else if(!this->signum&&num.signum){
        return -1;
    }else{
        int getSignal = compareTo((*this).value,num.value);
        if(getSignal==0){
            return 0;
        }else{
            return getSignal * (this->signum?1:-1);
        }
    }
}

int BigInteger::compareTo(const string &num) {
    BigInteger b2(num);
    return compareTo(b2);
}

int BigInteger::compareTo(long long int num) {
    BigInteger b2(num);
    return compareTo(b2);
}
BigInteger& BigInteger::sub(const BigInteger &num) {
    BigInteger b2 = -num;
    return this->add(b2);
}

BigInteger& BigInteger::sub(const string &num) {
    BigInteger b0(num);
    BigInteger b2 = -b0;
    return this->add(b2);
}

BigInteger& BigInteger::sub(long long num) {
    BigInteger b0(num);
    BigInteger b2 = -b0;
    return this->add(b2);
}
bool BigInteger::equals(const BigInteger& num) {
    if (this->compareTo(num) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool BigInteger::equals(const string& num) {
    if (this->compareTo(num) == 0) {
        return true;
    }
    else {
        return false;
    }
}
bool BigInteger::equals(const long long int num) {
    if (this->compareTo(num) == 0) {
        return true;
    }
    else {
        return false;
    }
}
BigInteger BigInteger::abs(const BigInteger & num) {
    BigInteger b2 = num;
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::abs(string num) {
    BigInteger b2 = BigInteger(num);
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::abs(long long int num) {
    BigInteger b2 = BigInteger(num);
    b2.signum = true;
    return b2;
}
void BigInteger::getSignaledData(vector<short>& clubs, vector<jbyte>& data) {
    vjri rit = data.rbegin();
    bool n2 = *rit>=10;
    clubs.reserve(n2 ? data.size() * 2 : data.size() * 2 - 1);
    vji it = data.begin();
    for(; it != data.end() - 1; it++){
        short sn2 = *it;
        if(sn2>=10){
            clubs.push_back(sn2 % 10);
            clubs.push_back(sn2 / 10);
        }else{
            clubs.push_back(sn2);
            clubs.push_back(0);
        }
    }
    short snr1 = *it;
    /**处理最高位*/
    if(n2){
        clubs.push_back(snr1 % 10);
        clubs.push_back(snr1 / 10);
    }else{
        clubs.push_back(snr1);
    }
}
BigInteger BigInteger::singleMul(short b) const {
    if(this->lessThan(BigInteger(922337203685477580))){
        return BigInteger((*this).toLonglongValue()*b);
    }
    if(b==0){
        return {};
    }else if(b==1){
        return *this;
    }
    vector<jbyte> copyThis = (*this).value;
    vector<short> mul_oper;
    getSignaledData(mul_oper,copyThis);
    vsi vsit = mul_oper.begin();
    short push = 0;
    for(; vsit != mul_oper.end(); vsit++){
        *vsit = *vsit * b+push;
        if(*vsit>=10){
            push = *vsit / 10;
            *vsit = *vsit % 10;
        }else{
            push = 0;
        }
    }
    if(push!=0){
        mul_oper.push_back(push);
    }
    vector<jbyte> pre_res(0);
    unsigned int len_of_mul_oper = mul_oper.size();
    bool len_of_mul_oper_2 = (len_of_mul_oper % 2 == 0);
    pre_res.resize(len_of_mul_oper_2 ? len_of_mul_oper / 2 : len_of_mul_oper / 2 + 1);
    vjri pre_res_it = pre_res.rbegin();
    vsri mul_oper_it = mul_oper.rbegin();
    if(!len_of_mul_oper_2){
        *pre_res_it++ = *mul_oper_it++;
    }
    for(; pre_res_it != pre_res.rend(); pre_res_it++){
        *pre_res_it = (*mul_oper_it++) * 10 + (*mul_oper_it++);
    }
    BigInteger res;
    res.value.swap(pre_res);
    return res;
}
BigInteger BigInteger::mul(const BigInteger &b2)const{
    BigInteger res;
    vector<jbyte> longOne,shortOne;
    if((*this).value.size()>=b2.value.size()){
        longOne = (*this).value;
        shortOne = b2.value;
    }else{
        longOne = b2.value;
        shortOne = (*this).value;
    }
    BigInteger tmp;
    tmp.value.swap(longOne);
    vector<short> parts;
    getSignaledData(parts,shortOne);
    for(int i = 0;i<parts.size();i++){
        res += (tmp.singleMul(parts[i])<<i);
    }
    res.signum = (this->signum==b2.signum);
    return res;
}

BigInteger BigInteger::mul(long long int b2) const{
    return this->mul(BigInteger(b2));
}

BigInteger BigInteger::mul(const string &b2) const{
    return this->mul(BigInteger(b2));
}
bool BigInteger::lessThan(const BigInteger &b)const{
    return this->compareTo(b) < 0;
}

bool BigInteger::greaterThan(const BigInteger &b)const{
    return this->compareTo(b) > 0;
}

bool BigInteger::lessOrEqualTo(const BigInteger &b)const{
    return this->compareTo(b) <= 0;
}

bool BigInteger::greaterOrEqualTo(const BigInteger &b)const{
    return this->compareTo(b) >= 0;
}

bool BigInteger::equalTo(const BigInteger &b)const{
    return this->compareTo(b) == 0;
}

bool BigInteger::notEqualTo(const BigInteger &b)const{
    return this->compareTo(b) != 0;
}
BigInteger BigInteger::div(const BigInteger &num) {
    if(this->lessThan(BigInteger(9223372036854775807))){
        return BigInteger((*this).toLonglongValue()/num.toLonglongValue());
    }
    if(num.equalTo(BigInteger(0))){
        throw runtime_error("num shouldn't be the zero");
    }
    BigInteger tmp;
    if(num.equalTo(BigInteger(1))){
        return *this;
    }else if(num.equalTo(BigInteger(-1))){
        tmp = *this;
        tmp.signum = !tmp.signum;
        return tmp;
    }
    if(compareTo(num.value,(*this).value)==1){
        return BigInteger(0);
    }
    tmp.value = (*this).value;
    tmp.signum = true;
    string s = tmp.toString();
    size_t len = s.length();
    size_t p = 0;
    BigInteger b = num;
    for(;p<len;){
        BigInteger y(string(s.begin(),s.begin()+1+p));
        if(y<b){
            p++;
        }else{
            break;
        }
    }
    BigInteger* t = new BigInteger(string(s.begin(),s.begin()+1+p));
    short cal;
    int newp = p;
    BigInteger res;
    while(true){
        if(*t<b){
            res = (res<<1);
        }else{
            cal = divHelp(*t,b);
            res = (res<<1).add(cal);//unpredict problem when use +
        }
        tmp -= ((b*cal)<<(len-1-newp));
        if(res.toString().length()==len-p){
            break;
        }
        newp++;
        {
            BigInteger foyer = (*t).sub((b*cal));
            if(foyer.equalTo(BigInteger(0))){
                t = new BigInteger(static_cast<int>((*this).toString()[newp]-'0'));
            }else{
                *t = (foyer<<1).add(static_cast<int>((*this).toString()[newp]-'0'));
            }
        }
        cal = 0;
    }
    res.signum = ((*this).signum==num.signum);
    return res;
}
BigInteger BigInteger::div(const long long int num){
    BigInteger ft(num);
    return div(ft);
}
BigInteger BigInteger::div(string num){
    BigInteger ft(num);
    return div(ft);
}
BigInteger BigInteger::mod(const BigInteger & num){
    if(this->lessThan(BigInteger(9223372036854775807))){
        return BigInteger((*this).toLonglongValue()%num.toLonglongValue());
    }
    BigInteger res;
    if(compareTo(num.value,(*this).value)==1){
        if(this->signum){
            res.value = (*this).value;
            return res;
        }else{
            res = (*this).add(num);
            return res;
        }
    }
    BigInteger tmp = (*this);
    if(!this->signum){
        while(tmp.lessThan(BigInteger(0))){
            tmp += num;
        }
    }
    string s = tmp.toString();
    size_t len = s.length();
    size_t p = 0;
    BigInteger b = num;
    for(;p<len;){
        BigInteger y(string(s.begin(),s.begin()+1+p));
        if(y<b){
            p++;
        }else{
            break;
        }
    }
    BigInteger* t = new BigInteger(string(s.begin(),s.begin()+1+p));
    short cal;
    int newp = p;
    res = 0;
    while(true){
        if(*t<b){
            res = (res<<1);
        }else{
            cal = divHelp(*t,b);
            res = (res<<1).add(cal);//unpredict problem when use +
        }
        tmp -= ((b*cal)<<(len-1-newp));
        if(res.toString().length()==len-p){
            break;
        }
        newp++;
        {
            BigInteger foyer = (*t).sub((b*cal));
            if(foyer.equalTo(BigInteger(0))){
                t = new BigInteger(static_cast<int>((*this).toString()[newp]-'0'));
            }else{
                *t = (foyer<<1).add(static_cast<int>((*this).toString()[newp]-'0'));
            }
        }
        cal = 0;
    }
    return tmp;

}
BigInteger BigInteger::mod(const long long int num){
    return mod(BigInteger(num));
}
BigInteger BigInteger::mod(string num){
    return mod(BigInteger(num));
}





