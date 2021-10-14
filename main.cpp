#include <iostream>
#include <ctime>
#include "BigInteger.h"
void op(const int &x){
    cout<<x<<endl;
}
void ox(int x){
    cout<<x<<endl;
}
void iu(string s){
    cout<<s<<endl;
}
void ix(const string& s){
    cout<<s<<endl;
}
int main() {
    clock_t begin = clock();
    for(int i = 0;i<1;i++){
        string s = "hello";
        iu(s);
        ix(s);
        iu("world");
        ix("hello");
        int llx = 12;
        op(llx);
        ox(llx);
        op(100);
        ox(100);

//        BigInteger res;
//        res = 1;
//        for(int i = 1;i <=1000;i++){
//            res *= i;
//        }
//        cout<<res<<endl;
//        cout<<BigInteger::factorial(10000)<<endl;

    }
    clock_t end = clock();
    cout<<endl<<end-begin<<"ms"<<endl;

//    cout<<BigInteger::longlongValue(BigInteger::pow(2,100000));
    return 0;
}
