// Given a 32 bit unsigned int flip all its bits and return the result in integer.
// We cannot use ~n as CPU treats number as signed and give -2 for ~1 as it calculate its 2s 
// complement. Use uint32_t u is for unsigned, for signed use int32_t 
// also to use a wall of 32 1's use 0xFFFFFFFF 0x means hex and F is of 4 bits 8*4=32.

#include <iostream>
#include <cstdint> // Standard header for uint32_t

using namespace std;

__UINT32_TYPE__  flippingBits(__UINT32_TYPE__ n){
    return ~n;

    // OR
    // return n^0xFFFFFFFF;
}
int main(){
    cout << flippingBits(1);
    return 0;
}