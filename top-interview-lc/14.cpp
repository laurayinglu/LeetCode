// https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    // solution 1: horizontal scanning
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.size() == 0)
//             return "";
//         string res = "";
//         int s = 0;
//         //for (int i = 0; i < strs.size(); i++) {
//         while (s < strs[0].size()){
//             char a = strs[0][s];
//             //cout << a<< endl;
//             for (int j = 1; j < strs.size(); j++) {
//                 if (s >= strs[j].size())
//                     return res;
//                 if (strs[j][s] != a)
//                    return res;
//             }
//             res += a;
//             s++;
//         }
        
//         return res;

//     }
// solution 2: vertical scanning
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string prefix = strs[0];
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (!prefix.size()) {
                break;
            }
        }
        return prefix;
    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index;
        }
        return str1.substr(0, index);
    }

};