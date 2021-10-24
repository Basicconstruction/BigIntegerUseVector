//
// Created by hay boy on 2021/10/23.
//

#ifndef BIGINTEGERUSEVECTOR_ARRAYS_H
#define BIGINTEGERUSEVECTOR_ARRAYS_H

#include <vector>
#include <iterator>
using namespace std;
namespace Arrays{
    inline vector<int> copyOf(const vector<int>& arr,int intLen){
        return {arr.begin(),arr.begin()+intLen};
    }
    inline vector<int> copyOfRange(const vector<int>& arr,int from,int to){
        return {arr.begin()+from,arr.begin()+to};
    }
    inline void fill(vector<int>& arr,int val){
        for(int & it : arr){
            it = val;
        }
    }
}
#endif //BIGINTEGERUSEVECTOR_ARRAYS_H
