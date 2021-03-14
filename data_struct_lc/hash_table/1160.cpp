// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // my solution 
        // int res = 0;
        
        // unordered_map<char, int> m2;
        // // record freq of chars
        // for (int i = 0; i < chars.length(); i++) {
        //     m2[chars[i]]++;
        // }
        
        // for (string s: words){
        //     unordered_map<char, int> m;
        //     for (int i = 0; i < s.length(); i++) {
        //         m[s[i]]++;
        //     }
            
        //     // compare 
        //     bool good = true;
        //     for (auto k:s){
        //         if (m2[k] < m[k]){
        //             good = false;
        //             break;
        //         }
        //     }
            
        //     if (good){
        //         cout << s << endl;
        //         res += s.length();
        //     }
        // }
        
        // return res;

        // solution 2:
        vector<int> cnt(26);
        int res = 0;
          for (auto ch : chars) ++cnt[ch - 'a'];
          for (auto w : words) {
            
            vector<int> cnt1 = cnt;
            bool match = true;
            // each time -1 if it uses char from cnt
            for (auto ch : w) {
              if (--cnt1[ch - 'a'] < 0) {
                match = false;
                break;
              }
            }
            if (match) res += w.size();
          }
        return res;
    }
};