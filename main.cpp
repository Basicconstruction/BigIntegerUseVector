#include <iostream>
#include <ctime>
#include "BigInteger.h"
#include "mutable/MutableBigInteger.h"
int main() {
    clock_t begin = clock();
    for(int i = 0;i<1;i++){
        //        BigInteger x = BigInteger(999).pow(9);
        //        cout<<x<<endl;
        //        vector<int> c{1,2};
        //        cout<<MutableBigInteger(c).toLongLong()<<endl;
//        cout << ((2 & LONG_MASK));
//        cout<<" "<<((bint)1<<32);
//        cout<<endl;
//        clock_t end = clock();
//        cout<<endl<<end-begin<<"ms"<<endl;
//        int x = 0;
//        int y = 12;
//        int c = - 0b11111111111111111111111111111111;
//        int c2= - 0b01111111111111111111111111111111-1;
////        cout<<c<<endl<<c2<<endl;
//        cout<<x+c2<<endl;
//        cout<<c2+y<<endl;
        int g = 12;
        int h = -12;
        cout<<(g<<1)<<endl<<(g>>1)<<endl;
        cout<<(h<<1)<<endl<<(h>>1)<<endl;

//        cout<<y+0x80000000<<endl;
//        cout<<x+0b10000000000000000000000000000000;
        //    cout<<BigInteger::longlongValue(BigInteger::pow(2,100000));
        return 0;
    }
}
