// https://leetcode.com/problems/roman-to-integer/
// start from end and once find previous one is smaller then subtract it
// can also start from begining, same idea

class Solution {
public:
    int romanToInt(string s) {
        if (s.length() == 0)
            return 0;
        
        int res = 0;
        unordered_map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50; 
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        
        res += roman[s.back()];
        for (int i = s.length()-2; i >= 0; i--) {
            if (roman[s[i]] < roman[s[i+1]]){ 
                res-=roman[s[i]];
            }
            else 
                res+= roman[s[i]];
        }
        
        return res;
    }
};