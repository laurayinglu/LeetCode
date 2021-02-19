// https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
      
        if (s.length() != t.length())
            return false;
        
//         // use a map to count freq
//         map<char, int> count1;
//         for (char a: s)
//             count1[a]++;
        
//         map<char, int> count2;
//         for (char a: t)
//             count2[a]++;
        
//         // check if freq is the same 
//         if (count1.size() != count2.size())
//             return false;
//         else {
//             for (int i = 0 ; i < s.size(); i++) {
//                 if (count1[s[i]] != count2[s[i]])
//                     return false;
//             }
//         }
        
//         return true;
        
        // use only one map to track, +1 for freq in s, -1 for freq in t, finally should be 0
        map<char, int> count;
        
        for (int i = 0 ; i < s.size(); i++) {
            count[s[i]]++;
            count[t[i]]--;
        }
        
        for (auto f: count) {
            if (f.second)
                return false;
        }
        
        return true;
        
        // can also use int freq[26] for record freq, which is faster
    }
};