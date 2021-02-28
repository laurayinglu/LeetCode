// https://leetcode.com/problems/excel-sheet-column-number/
// can see this as binary representation but with base 26
// eg. BAC = 26^2*('B'-'A'+1) + 26^1*1+26^0*3 
class Solution {
public:
    int titleToNumber(string s) {
        // using pow could be slower
//         int res = 0;
        
//         int size = s.length()-1;
        
//         for(int i = 0; i < s.length(); i++) {
//             res += pow(26, size--)*(s[i]-'A'+1);
//         }
        
//         return res;
        
        int result = 0;
        for (int i = 0; i < s.size(); i++)
            result = result * 26 + (s.at(i) - 'A' + 1);
        
        return result;
    }
};