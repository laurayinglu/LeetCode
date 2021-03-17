// https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // my solution:
        // vector<int> res(nums1.size());
        // unordered_map<int,int> c;
        // for (int i = 0; i < nums2.size(); i++)
        //     c[nums2[i]] = i;
        // for (int i = 0; i < nums1.size(); i++) {
        //     bool find = false;
        //     for (int j = c[nums1[i]]+1; j < nums2.size(); j++){
        //         if (nums2[j] > nums1[i]){
        //             res[i] = nums2[j];
        //             find = true;
        //             break;
        //         }
        //     }
            
        //     if (!find)
        //         res[i] = -1;
        // }
        
        // return res;

        // solution 2: use a stack to keep track of each element
        // 9 8 7 1 3 4 6
        // push 9 8 7 1 3 4 then find 6 > s.top() so keep poping untill <
        // m is keep track of 1st larger element of nums1

        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums2) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int> ans(nums1.size(), -1);

        for (int i=0; i<nums1.size(); i++)
            if (m.count(nums1[i]))
                ans[i] = m[nums1[i]];
        
        return ans;
    }
};