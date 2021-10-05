#include <iostream>
#include <ctime>
#include "BigInteger.h"

int main() {

    clock_t begin = clock();
    for(int i = 0;i<20;i++){
        cout<<BigInteger::toString(BigInteger::pow(8,1000));
    }
    clock_t end = clock();
    cout<<endl<<end-begin<<"ms"<<endl;

    return 0;
}
