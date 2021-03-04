//https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
//          vector<int> res;
//         if (digits[digits.size()-1] < 9){
//             digits[digits.size()-1] += 1;
//             return digits;
//         }
        
//         res.push_back(0);
//         bool flag = true; // represent increment 1 to previous
//         for (int i = digits.size()-2; i >=0; i--) {
//             if (digits[i] == 9 && flag){
//                 res.push_back(0);
//             }
//             else{
//                 if(flag){
//                     res.push_back(digits[i]+1);
//                     flag = false;
//                 }
//                 else
//                     res.push_back(digits[i]);
                    
//             }
//         }
        
//         if (flag)
//             res.push_back(1);

//         reverse(res.begin(), res.end());
        
//         return res;
        
        
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }
        digits[0] =1;
        digits.push_back(0);
        
        return digits;
    }
};