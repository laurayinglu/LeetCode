// https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        
//         string c = "";
//         for (int i= 0; i < s.length(); i++) {
//             if (isalpha(s[i]) || isdigit(s[i]))
//                 c+=tolower(s[i]);
//         }
        
//         cout << c << endl;
//         int i = 0;
//         int j = c.length() -1;
//         while (i <= j) {
//             cout << c[i] << " "<< c[j] << endl;
//             if (c[i] != c[j])
//                 return false;
//             else{
//                 i++;
//                 j--;
//             }
//         }
        
//         return true;
        
        int i = 0;
        int j = s.length()-1;
        
        while (i <= j) {
            //cout << s[i] << " "<< s[j]<<endl;
            if (!isalnum(s[i])) {
               i++;
            }
            else if (!isalnum(s[j])) {
                j--;
            }
            
            else if (tolower(s[i++]) != tolower(s[j--]))
                return false;

        }
        
        return true;
    }
};