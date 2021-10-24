#include "MutableBigInteger.h"
ostream& operator<<(ostream& os,const MutableBigInteger& b){
    auto it = b.value.begin();
    while(it!=b.value.end()){
        os<<*it++<<" ";
    }
    return os;
}

