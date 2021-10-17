#include <iostream>
#include <ctime>
#include "BigInteger.h"
int main() {
    clock_t begin = clock();
    for(int i = 0;i<1;i++){
        cout<<BigInteger(999).pow(99)-BigInteger(999).pow(99).excel_sqrt().pow(2)<<endl;
        BigInteger *x = new BigInteger(0);
        *x = BigInteger(999).pow(99)/BigInteger(999).pow(99).excel_sqrt();
        cout<<*x<<endl;
        BigInteger y = BigInteger(999).pow(99).mod(BigInteger(999).pow(99).excel_sqrt());
        cout<<y<<endl;
        cout<<(((*x) * BigInteger(999).pow(99).excel_sqrt()+y) == BigInteger(999).pow(99)?"true":"false");
    }
    clock_t end = clock();
    cout<<endl<<end-begin<<"ms"<<endl;

//    cout<<BigInteger::longlongValue(BigInteger::pow(2,100000));
    return 0;
}
