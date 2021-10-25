#ifndef BIGINTEGERUSEVECTOR_MUTABLEBIGINTEGER_H
#define BIGINTEGERUSEVECTOR_MUTABLEBIGINTEGER_H
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include <bitset>
#include "Arrays.h"
#include "../BigInteger.h"
#include "IntegerHelp.h"
typedef long long bint;
using namespace std;
class MutableBigInteger{
    typedef BigInteger bt;
    typedef MutableBigInteger mbt;
public:
    vector<int> value;
    int intLen;
    int offset{};
    MutableBigInteger(){
        value = vector<int>(1);
        intLen = 0;
    }
    explicit MutableBigInteger(int val){
        value = vector<int>(1);
        intLen = 1;
        value[0] = val;
    }
    explicit MutableBigInteger(int* val,int intLen){
        this->intLen = intLen;
        value.resize(intLen);
        copy(val,val+intLen,value.begin());

    }
    explicit MutableBigInteger(const vector<int>& val){
        value = val;
        intLen = val.size();
    }
    explicit MutableBigInteger(const BigInteger& b){
        intLen = b.mag.size();
        value.resize(intLen);
        value = Arrays::copyOf(b.mag, intLen);
    }
    explicit MutableBigInteger(const MutableBigInteger& val){
        int len = val.intLen;
        value = val.value;
    }
public:
    friend ostream& operator<<(ostream& os,const MutableBigInteger& b);
    /**
     * Makes this number an {#code n}-int number all of whose bits are ones.
     * this may not work in c++
     * */
    void ones(int n){
        if(n>value.size()){
            value = vector<int>(n);
        }
        Arrays::fill(value,-1);
        offset = 0;
        intLen = n;
    }
    /**
     * Internal helper method to return the magnitude array. The caller is not
     * supposed to modify the returned array.
     */
    vector<int> getMagnitudeArray() const{
        if(offset>0||value.size()!=intLen){
            return Arrays::copyOfRange(value,offset,offset+intLen);
        }
        return value;
    }
    /**
     * Convert this MutableBigInteger to a long mag. The caller has to make
     * sure this MutableBigInteger can be fit into long.
     * 同等行为
     */
     bint toLongLong(){
         if(intLen == 0){
             return 0;
         }
         bint d = value[offset] & LONG_MASK;
         return (intLen==2)?d<<32|(value[offset+1]&LONG_MASK):d;
     }
     /**
    * Convert this MutableBigInteger to a BigInteger object.
    */
     bt toBigInteger(int sign) const{
         if(intLen == 0||sign==0){
             return BigInteger(0);
         }
         return {getMagnitudeArray(),sign};
     }
     /**
     * Converts this number to a nonnegative {@code BigInteger}.
     */
     bt toBigInteger(){
         normalize();
         return toBigInteger(isZero()?0:1);
     }
     /**
     * This is for internal use in converting from a MutableBigInteger
     * object into a long value given a specified sign.
     * returns INFLATED if value is not fit into long
     */
     long long toCompactValue(int sign) const {
         if (intLen == 0 || sign == 0)
             return 0L;
         vector<int> mag = getMagnitudeArray();
         int len = mag.size();
         int d = mag[0];
         // If this MutableBigInteger can not be fitted into long, we need to
         // make a BigInteger object for the resultant BigDecimal object.
         if (len > 2 || (d < 0 && len == 2))
             return INFLATED;
         long long v = (len == 2) ?
                 ((mag[1] & LONG_MASK) | (d & LONG_MASK) << 32) :
                 d & LONG_MASK;
         return sign == -1 ? -v : v;
     }
     /**
     * Clear out a MutableBigInteger for reuse.
     */
     void clear(){
         offset = intLen = 0;
         for (int & index : value)
             index = 0;
     }
     /**
     * Set a MutableBigInteger to zero, removing its offset.
     */
     void reset() {
         offset = intLen = 0;
     }
     /**
     * Compare the magnitude of two MutableBigIntegers. Returns -1, 0 or 1
     * as this MutableBigInteger is numerically less than, equal to, or
     * greater than {@code b}.
     */
     int compare(const MutableBigInteger& b) {
         int blen = b.intLen;
         if (intLen < blen)
             return -1;
         if (intLen > blen)
             return 1;

         // Add Integer.MIN_VALUE to make the comparison act as unsigned integer
         // comparison.
         vector<int> bval = b.value;
         for (int i = offset, j = b.offset; i < intLen + offset; i++, j++) {
             int b1 = value[i] + MIN_INT;
             int b2 = bval[j]  + MIN_INT;//+2**31
             if (b1 < b2)
                 return -1;
             if (b1 > b2)
                 return 1;
         }
         return 0;
     }
     /**
     * Returns a value equal to what {@code b.leftShift(32*ints); return compare(b);}
     * would return, but doesn't change the value of {@code b}.
     */
     int compareShifted(const MutableBigInteger& b, int ints) {
         int blen = b.intLen;
         int alen = intLen - ints;
         if (alen < blen)
             return -1;
         if (alen > blen)
             return 1;

         // Add Integer.MIN_VALUE to make the comparison act as unsigned integer
         // comparison.
         vector<int> bval = b.value;
         for (int i = offset, j = b.offset; i < alen + offset; i++, j++) {
             int b1 = value[i] + MIN_INT;
             int b2 = bval[j]  + MIN_INT;
             if (b1 < b2)
                 return -1;
             if (b1 > b2)
                 return 1;
         }
         return 0;
     }
     /**
     * Convert this MutableBigInteger into an int array with no leading
     * zeros, of a length that is equal to this MutableBigInteger's intLen.
     */
     vector<int> toIntArray() {
         vector<int> result(intLen);
         for(int i=0; i < intLen; i++)
             result[i] = value[offset+i];
         return result;
     }
     /**
     * Sets this MutableBigInteger's value array to the specified array.
     * The intLen is set to the specified length.
     */
     void setValue(const vector<int>& val, int length) {
         value = val;
         intLen = length;
         offset = 0;
     }
     /**
 * Sets this MutableBigInteger's value array to a copy of the specified
 * array. The intLen is set to the length of the new array.
 */
     void copyValue(MutableBigInteger src) {
         int len = src.intLen;
         if (value.size() < len)
             value = vector<int>(len);
         copy(src.value.begin()+offset,src.value.begin()+offset+intLen,value.begin());
         intLen = len;
         offset = 0;
     }
     /**
     * Returns true iff this MutableBigInteger has a value of one.
     */
     bool isOne() {
         return (intLen == 1) && (value[offset] == 1);
     }

     /**
      * Returns true iff this MutableBigInteger has a value of zero.
      */
     bool isZero() const {
         return (intLen == 0);
     }
     /**
     * Returns true iff this MutableBigInteger is even.
     */
     bool isEven() {
         return (intLen == 0) || ((value[offset + intLen - 1] & 1) == 0);
     }

     /**
      * Returns true iff this MutableBigInteger is odd.
      */
     bool isOdd() {
         return !isZero() && ((value[offset + intLen - 1] & 1) == 1);
     }
     /**
     * Returns true iff this MutableBigInteger is in normal form. A
     * MutableBigInteger is in normal form if it has no leading zeros
     * after the offset, and intLen + offset <= value.length.
     */
     bool isNormal() {
         if (intLen + offset > value.size())
             return false;
         if (intLen == 0)
             return true;
         return (value[offset] != 0);
     }
     /**
     * Returns a String representation of this MutableBigInteger in radix 10.
     */
     string toString() const {
         BigInteger b = toBigInteger(1);
         return b.toString();
     }
     /**
      * Like {@link #rightShift(int)} but {@code n} can be greater than the length of the number.
      */
     void safeRightShift(int n) {
         if (n/32 >= intLen) {
             reset();
         } else {
             rightShift(n);
         }
     }


/**
      * Right shift this MutableBigInteger n bits. The MutableBigInteger is left
      * in normal form.
      */
     void rightShift(int n) {
         if (intLen == 0)
             return;
         int nInts = IntegerHelp::shr3(n,5);
         int nBits = n & 0x1F;
         this->intLen -= nInts;
         if (nBits == 0)
             return;
         int bitsInHighWord = BigInteger::bitLengthForInt(value[offset]);
         if (nBits >= bitsInHighWord) {
             this->primitiveLeftShift(32 - nBits);
             this->intLen--;
         } else {
             primitiveRightShift(nBits);
         }
     }
     /**
     * Like {@link #leftShift(int)} but {@code n} can be zero.
     */
     void safeLeftShift(int n) {
         if (n > 0) {
             leftShift(n);
         }
     }

     /**
      * Left shift this MutableBigInteger n bits.
      */
     void leftShift(int n) {
         /*
          * If there is enough storage space in this MutableBigInteger already
          * the available space will be used. Space to the right of the used
          * ints in the value array is faster to utilize, so the extra space
          * will be taken from the right if possible.
          */
         if (intLen == 0)
             return;
         int nInts = IntegerHelp::shr3(n,5);
         int nBits = n&0x1F;
         int bitsInHighWord = BigInteger::bitLengthForInt(value[offset]);

         // If shift can be done without moving words, do so
         if (n <= (32-bitsInHighWord)) {
             primitiveLeftShift(nBits);
             return;
         }

         int newLen = intLen + nInts +1;
         if (nBits <= (32-bitsInHighWord))
             newLen--;
         if (value.size() < newLen) {
             // The array must grow
             vector<int> result(newLen);
             for (int i=0; i < intLen; i++)
                 result[i] = value[offset+i];
             setValue(result, newLen);
         } else if (value.size() - offset >= newLen) {
             // Use space on right
             for(int i=0; i < newLen - intLen; i++)
                 value[offset+intLen+i] = 0;
         } else {
             // Must use space on left
             for (int i=0; i < intLen; i++)
                 value[i] = value[offset+i];
             for (int i=intLen; i < newLen; i++)
                 value[i] = 0;
             offset = 0;
         }
         intLen = newLen;
         if (nBits == 0)
             return;
         if (nBits <= (32-bitsInHighWord))
             primitiveLeftShift(nBits);
         else
             primitiveRightShift(32 -nBits);
     }



























public:
     const static bint LONG_MASK = 0xffffffff;
     const static int MIN_INT = - 0b01111111111111111111111111111111-1;
     const static bint INFLATED = -9223372036854775807;//-9223372036854775808
     void normalize(){
         if(intLen==0){
             offset = 0;
             return;
         }
         int index = offset;
         if(value[index]!=0){
             return;
         }
         int indexBound = index+intLen;
         do{
             index++;
         }while(index<indexBound&&value[index]==0);
         int numZeros = index - offset;
         intLen -= numZeros;
         offset = (intLen==0?0:offset+numZeros);
     }
     bool isZero(){
         return intLen==0;
     }

private:
    /**
     * Left shift this MutableBigInteger n bits, where n is
     * less than 32.
     * Assumes that intLen > 0, n > 0 for speed
     */
    void primitiveLeftShift(int n){
         vector<int>& val = value;
         int n2 = 32 - n;
         for (int i=offset, c=val[i], m=i+intLen-1; i < m; i++) {
             int b = c;
             c = val[i+1];
             val[i] = (b << n) | IntegerHelp::shr3(c,n2);
         }
         val[offset+intLen-1] <<= n;
    }
    /**
 * Right shift this MutableBigInteger n bits, where n is
 * less than 32.
 * Assumes that intLen > 0, n > 0 for speed
    */
    void primitiveRightShift(int n){
        vector<int>& val = value;
        int n2 = 32 - n;
        for (int i=offset+intLen-1, c=val[i]; i > offset; i--) {
            int b = c;
            c = val[i-1];
            val[i] = (c << n2) |IntegerHelp::shr3(b,n);
        }
        val[offset] = IntegerHelp::shr3(val[offset],n);
    }

};

#endif //BIGINTEGERUSEVECTOR_MUTABLEBIGINTEGER_H
