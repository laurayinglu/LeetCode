// https://leetcode.com/problems/sum-of-square-numbers/
// Similar to Two Sum

class Solution {
public:
    bool judgeSquareSum(int c) {
        int r = sqrt(c);
        int l = 0;
        
        while(l <= r) {
            //cout << l << " "<< r<< " ";
            int s = c - r*r;
            if (s == l*l)
                return true;
            else if (s > l*l) // l*l + r*r<c=>l*l< c- r*r
                l++;
            else
                r--;
        }
        
        return false;
    }
};