#include <iostream>
#include <ctime>
#include "BigInteger.h"
int main() {
    clock_t begin = clock();
    for(int i = 0;i<1;i++){
//        cout<<BigInteger::toString(BigInteger::pow(2,10000));
//        cout<<BigInteger::toString(BigInteger::factorial(3000));
//        BigInteger::printSelf(BigInteger::fibo(100));
//        std::cout<<BigInteger::pow(8,1000).toString()<<endl;
//        BigInteger::pow(8,1000).printSelf();
//        std::cout<<BigInteger(2).pow(10000)<<endl;
//        std::cout<<BigInteger::toString(BigInteger::pow(8,1000));
        BigInteger x(-123);
        cin>>x;
//        cout<<x<<endl;
        cout<<x.pow(1000);

    }
    clock_t end = clock();
    cout<<endl<<end-begin<<"ms"<<endl;

//    cout<<BigInteger::longlongValue(BigInteger::pow(2,100000));
    return 0;
}
