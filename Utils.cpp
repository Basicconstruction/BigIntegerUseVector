#include "Utils.h"
unsigned long long math_pow(int x,int y){
    unsigned long long res = 1;
    while(y--){
        res *= x;
    }
    return res;
}
