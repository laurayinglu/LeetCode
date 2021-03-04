// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        // my solution 
        int sign = 1;
        if (x < 0)
            sign = -1;
        
        x = abs(x);
        int ans = 0;
        while (x >= 1) {
            if (ans > (INT_MAX-x%10)/10)
                return 0;
            ans = ans*10 + x%10;
            x /= 10;
        }
        
        return ans*sign;
    
    }
};