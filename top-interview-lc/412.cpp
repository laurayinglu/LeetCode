// https://leetcode.com/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
//         vector<string> res(n);
//         for (int i = 1; i <= n; i++) {
//             if (i% 3 == 0 && i%5 == 0)
//                 res[i-1] = "FizzBuzz";
//             else if(i%3 == 0)
//                 res[i-1] = "Fizz";
//             else if (i%5 == 0)
//                 res[i-1] = "Buzz";
//             else
//                 res[i-1] = to_string(i);
//         }
        
//         return res;
        
        // solution2: using 4 for loops instead of module since it's more expensive
        
        vector<string> res(n);
        for(int i = 1;i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for(int i = 2;i < n; i += 3) {
            res[i] = "Fizz";
        }
        for(int i = 4;i < n; i += 5) {
            res[i] = "Buzz";
        }
        for(int i = 14;i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
        
    }
};