// https://leetcode.com/problems/sqrtx/submissions/
class Solution {
public:
    int mySqrt(int x) {
        // from [0,x] binary search
        
        int l = 1;
        int r = x;
        if (x == 0)
            return 0;
        
        while(l <= r) {
            int mid = l + (r-l)/2; // avoid division by 0
            if (mid == x/mid)
                return mid;
            else if(mid < x/mid)
                l = mid + 1;
            else
                r = mid -1;
        }
        
        return r
    }
};

// Newton

long x = a;
    while (x * x > a) {
        x = (x + a / x) / 2;
}
return x;