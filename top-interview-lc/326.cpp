// https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
// solution 1: loop iteration
// TC: O(log3n)
//         if (n < 1)
//             return false;
        
//         while(n % 3 == 0) {
//             n /= 3;
//         }
        
//         return n == 1;

// solution 2: max power of 3 within INT_MAX is 3^19 = 1162261467
        
//         if (n <= 0)
//             return false;
        
//         return 1162261467 % n == 0;

// solution 3: Mathematics: n = 3^i, i = log3n = logbn/logb3
// n is a power of 3 iff i is an integer
        return fmod(log10(n)/log10(3), 1)==0;
        // fmod returns the floating-point remainder of numer/denom (rounded towards zero):

    }
};