// https://leetcode.com/problems/build-an-array-with-stack-operations/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int s = target.size();
        
        vector<string> res;
        int idx = 0;
        for (int i = 1; i < n+1; i++) {
            if (idx >= s)
                break;
            if (target[idx] != i){
                res.push_back("Push");
                res.push_back("Pop");
            } else{
                res.push_back("Push");
                idx++;
            }
        }
        
        return res;
    }
};
