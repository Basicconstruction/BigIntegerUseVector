#include <iostream>
#include <ctime>
#include "BigInteger.h"
int main() {
    clock_t begin = clock();
    for(int i = 0;i<1;i++){
        cout<<BigInteger(99).pow(9999);
    }
    clock_t end = clock();
    cout<<endl<<end-begin<<"ms"<<endl;

//    cout<<BigInteger::longlongValue(BigInteger::pow(2,100000));
    return 0;
}
