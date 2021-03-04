// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
// solution 1: binary search 
       
        long long l = 0;
        long long r = x;
        long long ans = -1;
        
        while(l <= r) {
            long long mid = (l+r)/2;
            if (mid*mid == x)
                return mid;
            
            if (mid*mid <= x) {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid-1;
        }
        
        return ans;
        
// solution2 : use newton rule
// choose x0 = x as initial value
// y = f(x) = x^2 - C = 0, f'(x) = 2x
// at (x0, x0^2-C) with slope = 2x0, y = 0 => x1 = (x/x0+x0)/2
//         long r = x;
//         while (r*r > x){
//             r = (r+x/r)/2;
//         }
        
//         return r;
        
    }
};