// https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(uint32_t n) {
// solution1: bit manipulation trick
// In the binary representation, the least significant 11-bit in nn always corresponds to a 00-bit in n - 1n−1. Therefore, anding the two numbers nn and n - 1n−1 always flips the least significant 11-bit in nn to 00, and keeps all other bits the same.
// n:  0110110
// n-1:0110101
// &:  0110100
// each time it will turn least significant 1 to be 0
        int count = 0;
    
        while (n) {
            count++;
            n &= (n - 1);
        }

        return count;
        
// solution2: loop and check each of the 32 bits of the number
// depend on number of bits in n, 32 bits is O(1)
//         int count = 0;
//         uint32_t mask = 1;
        
//         for (int i = 0; i < 32; i++) {
//             if ((n&mask) != 0)
//                 count++;

//             mask <<= 1;
//         }
        
//         return count;
    }
};