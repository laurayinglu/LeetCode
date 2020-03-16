// Given two arrays, write a function to compute their intersection.

// example: 
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
    // my version
    vector<int> res;
    set<int> ans;
    if(nums1.size() == 0 || nums2.size() == 0) return res;

    // sort both vectors
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int l = 0;
    int s = 0;

    while(l < nums1.size() && s < nums2.size())
    {
        if(nums1[l] > nums2[s]) {
            s++;
            continue;}
        if(nums1[l] < nums2[s]){
            l++;
            continue;}

        ans.insert(nums1[l]);
        s++;
        l++;

    }
        
    for(auto x : ans){
      res.push_back(x);
      ans.erase(x);
    }

    return res;
    }
    
    
// another way: convert both vectors to sets
        
//     unordered_set<int> m(nums1.begin(), nums1.end());
//     vector<int> res;
//     for (auto a : nums2)
//     if (m.count(a)) {
//         res.push_back(a);
//         m.erase(a);
//     }
//     return res;
    
};
