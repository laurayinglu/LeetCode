// https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.length() == 0)
            return 0;
        
        string co = s;
        reverse(co.begin(), co.end());
        if ( co == s)
            return 1;
        
        return 2;
    }
};