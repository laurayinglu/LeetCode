// https://leetcode.com/problems/intersection-of-two-arrays/
// Unordered sets are containers that store unique elements in no particular order, 
// and which allow for fast retrieval of individual elements based on their value.

// solution2: sort two vectors then used 2 pointers
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
            if (m.count(a)) { // count != 0 means has same value in set m
                res.push_back(a);
                m.erase(a);
            }
        return res;
        
    }
};