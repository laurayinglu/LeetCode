// https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        // solution 1: use 2 vectors, one is count of each string, the other is the minimal common freq 
        vector<int> cnt(26, INT_MAX);
        vector<string> res;
        for (string s: A) {
            vector<int> cnt1(26,0);
            for (int i = 0; i < s.length(); i++) {
                cnt1[s[i]-'a']++;
            }
            // update cnt
            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cnt[i],cnt1[i]);
            }
            
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++){
                res.push_back(string(1, i+'a'));
            }
        }
        
        return res;
    }
};