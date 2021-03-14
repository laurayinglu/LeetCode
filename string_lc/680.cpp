// https://leetcode.com/problems/valid-palindrome-ii/

// class Solution {
// public:
//     bool isPalindrome(string::iterator low, string::iterator high) 
//     { 
//         while (low < high) 
//         { 
//            if (*low != *high) 
//               return false; 
//            low++; 
//            high--; 
//         } 
//         return true; 
//     } 
    
//     bool validPalindrome(string s) {
        // solution 1:  brute force TLE
//         if (s.length() == 0)
//             return false;
        
//         if (isPalindrome(s))
//             return true;
        
//         unordered_map<char, int> c;
//         for (int i = 0; i < s.length(); i++) {
//             c[s[i]]++;
//         }
        
//         for (int i = 0; i < s.length(); i++) {
//             if (c[s[i]] == 1) {
//                 string t = s;
//                 t.erase(t.begin()+i);
//                 if (isPalindrome(t))
//                     return true;
//             }
//         }
        
        
//         return false;
        
//     }
// };

// solution 2: greedy
class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
            if (s[i] != s[j]) 
                return isp(s, i + 1, j) || isp(s, i, j - 1);
        
        return true;
    }

private:
    bool isp(string s, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--)
            if (s[i] != s[j]) return false;
        return true;
    }
};