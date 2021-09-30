#include <iostream>
#include "BigInteger.h"
int main() {
    high_resolution_clock::time_point beginTime = high_resolution_clock::now();
//    for(int i = 0;i < 10;i++){
//
////        cout<<BigInteger::getFibo(10000)<<endl;
//    }
    cout<<BigInteger::factorial(1000).value;
    high_resolution_clock::time_point endTime = high_resolution_clock::now();
    milliseconds timeInterval = std::chrono::duration_cast<milliseconds>(endTime - beginTime);
    cout << "\nRunning Time " << timeInterval.count()  << "ms" << endl;
    return 0;
}
