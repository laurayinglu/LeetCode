// https://leetcode.com/problems/short-encoding-of-words/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        for (string w : s)
            for (int i = 1; i < w.size(); ++i)
                s.erase(w.substr(i)); // remove all substring in the set
        int res = 0;
        for (string w : s) res += w.size() + 1;
        return res;
        
        // solution 2: Trie（字典树用于判断字符串是否存在或者是否具有某种字符串前缀)
    }
};