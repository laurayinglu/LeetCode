// https://leetcode.com/problems/first-unique-character-in-a-string/
// solution 1: use hashset
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.length() == 0)
            return -1;
        
        unordered_map<char, int> c;

        for (int i = 0; i < s.length(); i++)
            c[s[i]]++;
        
        for (int i = 0; i < s.length(); i++){
            if (c[s[i]] == 1)
                return i;
        }
       
        return -1;
    
    }
};