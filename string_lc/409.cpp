// https://leetcode.com/problems/longest-palindrome/

// my solution : find longest char with odd number
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> c;
        for (int i = 0; i < s.length(); i++) {
            c[s[i]]++;
        }
        
        int res = 0;
        int max = 0;
        for (auto it = c.begin(); it != c.end(); it++) {
             //cout << it->second << endl;
            if (it->second % 2 == 0)
                res += it->second;
            else{
                if (it->second > max){
                    //cout << max << endl;
                    if (max > 0)
                        res += (max-1);
                    max = it->second;
                }else{
                    res += it->second-1;
                }
            }
                
        }
        
        return res+max;

        // solution 2:
        // int cnt[58] = {0};
        // for (char c : s) {
        //     cnt[c - 'A'] += 1;
        // }
        // int res = 0;
        // for (int x :cnt){
        //     if (x % 2== 0)
        //         res += x;
        //     else
        //         res += (x-1);
        // }
        
        // if (res < s.length()) // means there's odd occurrence
        //     res += 1;
        
        // return res;
    }
};