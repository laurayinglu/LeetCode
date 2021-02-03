// https://leetcode.com/problems/increasing-decreasing-string/
// count freq of each letter, first choose from smallest to largest, then largest to smallest
// repeat until all freq is 0 
class Solution {
public:
    string sortString(string s) {
        int freq[26] = {0};
        string res = s;
        int size = 0;
        // count the frequncies
        for (int i = 0 ; i < s.length(); i++) {
            freq[s[i]-97]++;
        }
        
        // for (auto a : s) {
        //     ++freq[a-'a'];
        // }
        
        
        while (size < s.length()) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] != 0) {
                    char a = 'a'+i;
                    res[size++] = a ;
                    freq[i]--;
                }
            }
            
            //cout << res <<endl;

             for (int i = 25; i >= 0; i--) {
                if (freq[i] != 0) {
                    char a ='a' + i;
                    res[size++] = a ;
                    freq[i]--;
                }
            }
        }
        
        return res;
    }
};