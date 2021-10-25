//
// Created by hay boy on 2021/10/25.
//

#ifndef BIGINTEGERUSEVECTOR_INTEGERHELP_H
#define BIGINTEGERUSEVECTOR_INTEGERHELP_H

#include <bitset>

using namespace std;

class IntegerHelp {
public:
    /**
 * Returns the number of zero bits preceding the highest-order
 * ("leftmost") one-bit in the two's complement binary representation
 * of the specified {@code int} value.  Returns 32 if the
 * specified value has no one-bits in its two's complement representation,
 * in other words if it is equal to zero.
 *
 * <p>Note that this method is closely related to the logarithm base 2.
 * For all positive {@code int} values x:
 * <ul>
 * <li>floor(log<sub>2</sub>(x)) = {@code 31 - numberOfLeadingZeros(x)}
 * <li>ceil(log<sub>2</sub>(x)) = {@code 32 - numberOfLeadingZeros(x - 1)}
 * </ul>
 *
 * @param i the value whose number of leading zeros is to be computed
 * @return the number of zero bits preceding the highest-order
 *     ("leftmost") one-bit in the two's complement binary representation
 *     of the specified {@code int} value, or 32 if the value
 *     is equal to zero.
 * @since 1.5
 * 行为与 java Integer.numberOfLeadingZeros(int i)一致。带入12,-12,140000验证。没有其他验证示例。
     * 注意这里并没有使用"无符号"右移，因为这并不是必须的，因为传入的阐述本身就是大于0的，且是signed int。
     * 使用 >>= 和 java中的 >>>= 行为一致，也与自行设计的shr3(int i)行为一致，但是自行设计的shr3具有
     * 额外的消耗，故bucai不采用shr3，而采用效率更高的>>(>>=)
     */
    static int numberOfLeadingZeros(int i) {
        // HD, Count leading 0's
        if (i <= 0)
            return i == 0 ? 32 : 0;
        int n = 31;
        if (i >= 1 << 16) {
            n -= 16;
//            i = shr3(i, 16);
            i >>= 16;
        }
        if (i >= 1 << 8) {
            n -= 8;
//            i = shr3(i, 8);
            i >>= 8;
        }
        if (i >= 1 << 4) {
            n -= 4;
//            i = shr3(i, 4);
            i >>= 4;
        }
        if (i >= 1 << 2) {
            n -= 2;
//            i = shr3(i, 2);
            i >>= 2;
        }
        return n - (i>>1);
    }


    /**
     * 展示int数字的内存位布局。
     * @param int num
     * @returns void
     * @since 1.0
     * */
    static void showBytes(int num){
        if(num>0){
            bitset<32> sets;
            for (int j = 0; j <= 31; j++) {
                bool tp = num & 1;
                sets[j] = tp;
                num = (num >> 1);
            }
            for(int i = 31;i>=0;i--){
                cout<<sets[i];
            }
        }else{
            num = -num;
            bitset<32> sets;
            for (int j = 0; j <= 31; j++) {
                bool tp = num & 1;
                sets[j] = tp;
                num = (num >> 1);
            }
            sets.flip();
            int notZero = 31;
            for (int j = 0; j <= 31; j++) {
                if (!sets[j]) {
                } else {
                    notZero = j;
                    break;
                }
            }
            for (int j = notZero; j <= 31; j++) {
                if (sets.test(j)) {
                    sets.flip(j);
                } else {
                    sets.flip(j);
                    break;
                }
            }
            sets[31] = true;
            for(int i = 31;i>=0;i--){
                cout<<sets[i];
            }
        }
    }
    static int shr3(int num, int n) {
        if (num >= 0) {
            return num >> n;
        }
        bitset<32> sets;
        num = -num;
        for (int j = 0; j <= 31; j++) {
            bool tp = num & 1;
            sets[j] = tp;
            num = (num >> 1);
        }
        sets.flip();
        int notZero = 31;
        for (int j = 0; j <= 31; j++) {
            if (!sets[j]) {
            } else {
                notZero = j;
                break;
            }
        }
        for (int j = notZero; j <= 31; j++) {
            if (sets.test(j)) {
                sets.flip(j);
            } else {
                sets.flip(j);
                break;
            }
        }
        sets[31] = true;
        sets >>= n;
        return (int) sets.to_ullong();
    }
};

#endif //BIGINTEGERUSEVECTOR_INTEGERHELP_H
