#include <iostream>
#include <ctime>
#include "BigInteger.h"
int main() {
    clock_t begin = clock();
    for(int i = 0;i<1;i++){
        BigInteger res;
        res = 1;
        for(int i = 1;i <=10000;i++){
            res *= i;
        }
        cout<<res<<endl;
//        cout<<BigInteger::factorial(10000)<<endl;

    }
    clock_t end = clock();
    cout<<endl<<end-begin<<"ms"<<endl;

//    cout<<BigInteger::longlongValue(BigInteger::pow(2,100000));
    return 0;
}
