//
// Created by hay boy on 2021/9/30.
//
/**通用的方法的抽离。*/
#include "Utils.h"
unsigned long long math_pow(int x,int y){
    unsigned long long res = 1;
    while(y--){
        res *= x;
    }
    return res;
}