//
// Created by hay boy on 2021/10/3.
//
#include <iterator>
#include "BigInteger.h"

BigInteger BigInteger::add(const BigInteger &num) const {
    short carry = 0;
    vector<int> tem = this->mag;
    vector<int> added = num.mag;
    vector<int> longOne, shortOne;
    if ((this->signum && num.signum) || (!this->signum && !num.signum)) {
        if (tem.size() >= added.size()) {
            longOne = tem;
            shortOne = added;
        } else {
            longOne = added;
            shortOne = tem;
        }
        vector<int>::iterator it = longOne.begin();
        vector<int>::iterator it2 = shortOne.begin();
        for (; it != longOne.end(); it++) {
            if (it2 != shortOne.end()) {
                int tmp = (*it) + (*it2) + carry;
                if (tmp >= 10000) {
                    carry = 1;
                    *it = tmp - 10000;
                } else {
                    carry = 0;
                    *it = tmp;
                }
                it2++;
            } else {
                int tmp = (*it) + carry;
                if (tmp >= 10000) {
                    carry = 1;
                    *it = tmp - 10000;
                } else {
                    carry = 0;
                    *it = tmp;
                }
            }
        }
        if (carry > 0) {
            longOne.push_back(1);
        }
        BigInteger res;
        res.signum = this->signum;
        res.mag.swap(longOne);
        return res;
    } else {
        int cres = compareTo(tem, added);
        BigInteger res;
        if (cres == 0) {
            return BigInteger(0);
        } else if (cres == 1) {
            res.signum = this->signum;
            longOne = tem;
            shortOne = added;
        } else {
            res.signum = !this->signum;
            longOne = added;
            shortOne = tem;
        }
        vector<int>::iterator it = longOne.begin();
        vector<int>::iterator it2 = shortOne.begin();
        for (; it != longOne.end(); it++) {
            if (it2 != shortOne.end()) {
                int tmp = (*it) - (*it2) - carry;
                if (tmp < 0) {
                    tmp = tmp + 10000;
                    carry = 1;
                } else {
                    carry = 0;
                }
                *it = tmp;
                it2++;
            } else {
                int tmp = (*it) - carry;
                if (tmp < 0) {
                    tmp = tmp + 10000;
                    carry = 1;
                } else {
                    carry = 0;
                }
                *it = tmp;
            }
        }
        assert(carry == 0);
        res.mag.swap(longOne);
        std::vector<int>::iterator back_i = res.mag.end() - 1;
        for (; back_i != res.mag.begin(); back_i--) {
            if (*back_i == 0) {
                res.mag.erase(back_i);
            } else {
                break;
            }
        }
        return res;

    }
}

BigInteger BigInteger::add(const long long &num) const {
    BigInteger b2(num);
    return add(b2);
}

BigInteger BigInteger::add(const string &num) const {
    BigInteger b2(num);
    return add(b2);
}


int BigInteger::compareTo(const BigInteger &num) const {
    if (this->signum && !num.signum) {
        return 1;
    } else if (!this->signum && num.signum) {
        return -1;
    } else {
        int getSignal = compareTo((*this).mag, num.mag);
        if (getSignal == 0) {
            return 0;
        } else {
            return getSignal * (this->signum ? 1 : -1);
        }
    }
}

int BigInteger::compareTo(const long long int &num) const {
    BigInteger b2(num);
    return compareTo(b2);
}

int BigInteger::compareTo(const string &num) const {
    BigInteger b2(num);
    return compareTo(b2);
}


BigInteger BigInteger::sub(const BigInteger &num) const {
    BigInteger b2 = -num;
    return this->add(b2);
}

BigInteger BigInteger::sub(const long long &num) const {
    BigInteger b0(num);
    BigInteger b2 = -b0;
    return this->add(b2);
}

BigInteger BigInteger::sub(const string &num) const {
    BigInteger b0(num);
    BigInteger b2 = -b0;
    return this->add(b2);
}

bool BigInteger::equals(const BigInteger &num) const {
    if (this->compareTo(num) == 0) {
        return true;
    } else {
        return false;
    }
}

bool BigInteger::equals(const long long int &num) const {
    if (this->compareTo(num) == 0) {
        return true;
    } else {
        return false;
    }
}

bool BigInteger::equals(const string &num) const {
    if (this->compareTo(num) == 0) {
        return true;
    } else {
        return false;
    }
}


BigInteger BigInteger::abs(const BigInteger &num) {
    BigInteger b2 = num;
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::abs(const string &num) {
    BigInteger b2 = BigInteger(num);
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::abs(const long long int &num) {
    BigInteger b2 = BigInteger(num);
    b2.signum = true;
    return b2;
}

BigInteger BigInteger::singleMul(const int &b) const {
    if (b == 0) {
        return {};
    } else if (b == 1) {
        return *this;
    }
    BigInteger tis = *this;
    int expr;
    int push = 0;
    for(int & i : tis.mag){
        expr = i*b+push;
        if(expr>=10000){
            push = expr / 10000;
            expr %= 10000;
        }else{
            push = 0;
        }
        i = expr;
    }
    if(push>0){
        tis.mag.push_back(push);
    }
    return tis;
}

BigInteger BigInteger::mul(const BigInteger &b2) const {
    BigInteger res;
    BigInteger tis = *this;
    vector<int>::const_reverse_iterator rit = b2.mag.rbegin();
    for (; rit != b2.mag.rend(); rit++) {
        res << ip;
        res += tis.singleMul(*rit);
    }
    res.signum = (this->signum == b2.signum);
    return res;
}

BigInteger BigInteger::mul(const long long int &b2) const {
    return this->mul(BigInteger(b2));
}

BigInteger BigInteger::mul(const string &b2) const {
    return this->mul(BigInteger(b2));
}


bool BigInteger::lessThan(const BigInteger &b) const {
    return this->compareTo(b) < 0;
}

bool BigInteger::lessThan(const long long int &b) const {
    return this->compareTo(b) < 0;
}

bool BigInteger::lessThan(const string &b) const {
    return this->compareTo(b) < 0;
}


bool BigInteger::greaterThan(const BigInteger &b) const {
    return this->compareTo(b) > 0;
}

bool BigInteger::greaterThan(const long long int &b) const {
    return this->compareTo(b) > 0;
}

bool BigInteger::greaterThan(const string &b) const {
    return this->compareTo(b) > 0;
}


bool BigInteger::lessOrEqualTo(const BigInteger &b) const {
    return this->compareTo(b) <= 0;
}

bool BigInteger::lessOrEqualTo(const long long int &b) const {
    return this->compareTo(b) <= 0;
}

bool BigInteger::lessOrEqualTo(const string &b) const {
    return this->compareTo(b) <= 0;
}


bool BigInteger::greaterOrEqualTo(const BigInteger &b) const {
    return this->compareTo(b) >= 0;
}

bool BigInteger::greaterOrEqualTo(const long long int &b) const {
    return this->compareTo(b) >= 0;
}

bool BigInteger::greaterOrEqualTo(const string &b) const {
    return this->compareTo(b) >= 0;
}


bool BigInteger::equalTo(const BigInteger &b) const {
    return this->compareTo(b) == 0;
}

bool BigInteger::equalTo(const string &b) const {
    return this->compareTo(b) == 0;
}

bool BigInteger::equalTo(const long long int &b) const {
    return this->compareTo(b) == 0;
}


bool BigInteger::notEqualTo(const BigInteger &b) const {
    return this->compareTo(b) != 0;
}

bool BigInteger::notEqualTo(const long long int &b) const {
    return this->compareTo(b) != 0;
}

bool BigInteger::notEqualTo(const string &b) const {
    return this->compareTo(b) != 0;
}


BigInteger BigInteger::div(const BigInteger &num, bool open) const {
    if (open && this->lessThan(BigInteger(9223372036854775807))) {
        return BigInteger((*this).toLonglongValue() / num.toLonglongValue());
    }
    if (num.equalTo(BigInteger(0))) {
        throw runtime_error("num shouldn't be the zero");
    }
    BigInteger tmp;
    if (num.equalTo(BigInteger(1))) {
        return *this;
    } else if (num.equalTo(BigInteger(-1))) {
        tmp = *this;
        tmp.signum = !tmp.signum;
        return tmp;
    }
    if (compareTo(num.mag, (*this).mag) == 1) {
        return BigInteger(0);
    }
    tmp.mag = (*this).mag;
    tmp.signum = true;
    string s = tmp.toString();
    size_t len = s.length();
    size_t p = 0;
    for (; p < len;) {
        BigInteger y(string(s.begin(), s.begin() + 1 + p));
        if (y < num) {
            p++;
        } else {
            break;
        }
    }
    BigInteger *t = new BigInteger(string(s.begin(), s.begin() + 1 + p));
    short cal;
    int newp = p;
    BigInteger res;
    while (true) {
        if (*t < num) {
            res = (res << 1);
        } else {
            cal = divHelp(*t, num);
            res = (res << 1).add(cal);//unpredict problem when use +
        }
        tmp -= ((num * cal) << (len - 1 - newp));
        if (res.toString().length() == len - p) {
            break;
        }
        newp++;
        {
            BigInteger foyer = (*t).sub((num * cal));
            if (foyer.equalTo(BigInteger(0))) {
                t = new BigInteger(static_cast<int>((*this).toString()[newp] - '0'));
            } else {
                *t = (foyer << 1).add(static_cast<int>((*this).toString()[newp] - '0'));
            }
        }
        cal = 0;
    }
    res.signum = ((*this).signum == num.signum);
    return res;
}

BigInteger BigInteger::div(const long long int &num) const {
    BigInteger ft(num);
    return div(ft);
}

BigInteger BigInteger::div(const string &num) const {
    BigInteger ft(num);
    return div(ft);
}


BigInteger BigInteger::mod(const BigInteger &num) const {
    if (this->lessThan(BigInteger(9223372036854775807))) {
        return BigInteger((*this).toLonglongValue() % num.toLonglongValue());
    }
    if (compareTo(num.mag, (*this).mag) == 1) {
        if (this->signum) {
            return *this;
        } else {
            return (*this) + num;
        }
    }
    BigInteger tmp = (*this);
    if (!this->signum) {
        while (tmp.lessThan(BigInteger(0))) {
            tmp += num;
        }
    }
    string s = tmp.toString();
    size_t len = s.length();
    size_t p = 0;
//    BigInteger b = num;
    for (; p < len;) {
        BigInteger y(string(s.begin(), s.begin() + 1 + p));
        if (y < num) {
            p++;
        } else {
            break;
        }
    }
    BigInteger *t = new BigInteger(string(s.begin(), s.begin() + 1 + p));
    short cal;
    int newp = p;
    int resultLen = 0;
    while (true) {
        if (*t < num) {
        } else {
            cal = divHelp(*t, num);
        }
        resultLen++;
        tmp -= ((num * cal) << (len - 1 - newp));
        if (resultLen == len - p) {
            break;
        }
        newp++;
        {
            BigInteger foyer = (*t).sub((num * cal));
            if (foyer.equalTo(BigInteger(0))) {
                t = new BigInteger(static_cast<int>((*this).toString()[newp] - '0'));
            } else {
                *t = (foyer << 1).add(static_cast<int>((*this).toString()[newp] - '0'));
            }
        }
        cal = 0;
    }
    return tmp;

}

BigInteger BigInteger::mod(const long long int &num) const {
    return mod(BigInteger(num));
}

BigInteger BigInteger::mod(const string &num) const {
    return mod(BigInteger(num));
}

BigInteger &BigInteger::toAbs() {
    this->signum = true;
    return *this;
}

BigInteger BigInteger::newton_sqrt() const {
    //deprecated need to update the algorithm,designed for the main repo.
    BigInteger res(1);
    bool t = true;
    while (t) {
        res = (res + (*this) / res) / 2;
        t = (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ||
            (res * res >= (*this) && (res - 1) * (res - 1) < (*this));
        t = !t;
        cout << t << endl;
    }
    return (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ? res : res - 1;
}

BigInteger BigInteger::excel_sqrt() const {
    short len;
    short ori;
    short num = short(*(this->mag.rbegin()));
    ori = sqrtDict[num];
    len = this->mag.size();
    BigInteger res(ori);
    res = res << len;
    bool t = true;
    while (t) {
        res = (res + (*this) / res) / 2;
        t = (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ||
            (res * res >= (*this) && (res - 1) * (res - 1) < (*this));
        t = !t;
    }
    return (res * res <= (*this) && (res + 1) * (res + 1) > (*this)) ? res : res - 1;
}



