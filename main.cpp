#include <iostream>
#include <ctime>
#include "BigInteger.h"
int main() {
    clock_t begin = clock();
    for(int i = 0;i<1;i++){
        BigInteger x(100);
        x = x + 1;
        cout<<x<<endl;
        x = x - 1;
        cout<<x<<endl;
        x = x * 100;
        cout<<x<<endl;
        x = x / 100;
        cout<<x<<"/"<<endl;
        x += 1;
        cout<<x<<endl;
        x -= 1;
        cout<<x<<endl;
        x *= 100;
        cout<<x<<endl;
        x /= 100;
        cout<<x<<endl;
        x = x % 3;
        cout<<x<<endl;
        x %= 2;
        cout<<x<<endl;
        x++;
        cout<<x<<endl;
        x--;
        cout<<x<<endl;
        x += "1234";
        cout<<x<<endl;
    }
    clock_t end = clock();
    cout<<endl<<end-begin<<"ms"<<endl;

//    cout<<BigInteger::longlongValue(BigInteger::pow(2,100000));
    return 0;
}
