// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// with 349 II
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // sort two vectors
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i1 = 0;
        int i2 = 0;
        vector<int> res;
        while (i1 < nums1.size() && i2 < nums2.size()){
            if (nums1[i1] < nums2[i2])
                i1++;
            else if (nums1[i1] > nums2[i2])
                i2++;
            else {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
        }
        
        return res;
        
        
        // solution2: hashtable
        // if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
        // vector<int> ret;
        // unordered_map<int,int> map1;
        // for(int num:nums1) map1[num]++;
        // for(int num:nums2) {
        //     if(map1.find(num)!=map1.end() && map1[num]>0) {
        //         ret.push_back(num);
        //         map1[num]--;
        //     }
        // }
        // return ret;
    }
};