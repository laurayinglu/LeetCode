// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string S) {
        // my solution:
        // if (S.length() == 1)
        //     return S;
        // for (int i = 1; i < S.length(); i++) {
        //     //cout << i << endl;
        //     if (S[i] == S[i-1]){
        //         S.erase(i-1,2);
        //         //cout << S << endl;
        //         i = 0;
        //     }
        // }
        // return S;

        // solution 2: use stack
        string res = "";
        for (char& c : S)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;
    }
};