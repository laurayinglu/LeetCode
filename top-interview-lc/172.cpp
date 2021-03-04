// https://leetcode.com/problems/factorial-trailing-zeroes/
// basically find how many 2*5 => since 2 is far more than 5 so we take all the numbers with 5 as a factor
// O(n) : log5(n)
class Solution {
public:
    int trailingZeroes(int n) {
        // my solution
        // based on https://www.purplemath.com/modules/factzero.htm
        // find number of 5 within n, 25 has 5*5 2 5
        int p = 1;
        int ans = 0;
        while (pow(5,p) <= n) {
            ans += (n/pow(5,p));
            p++;
        }
        
        return ans;

        // solution 2: recursion
        if (n == 0)
            return 0;
        
        return n/5 + trailingZeroes(n/5);

        // solution 3; iterative version 
        int ans = 0;
        while (n >= 1) {
            ans += (n/5);
            n /= 5;
        }
        
        return ans;
    }
};