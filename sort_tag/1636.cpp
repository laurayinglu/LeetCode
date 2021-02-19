// https://leetcode.com/problems/sort-array-by-increasing-frequency/
// // utility comparator function to pass to the sort() module
// bool sortByVal(int a, int b) 
// { 
//     if (a == b.second)
//         return a.first > b.first;
    
//     return (a.second < b.second); 
// } 


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
    
//         map<int, int> m;
//         for (auto i : nums) 
//             m[i]++;
        
//         vector<pair<int, int> > A; 
  
//         // Copy key-value pair from Map 
//         // to vector of pairs 
//         for (auto& it : m) { 
//             A.push_back(it); 
//         } 
//         // sort the map based on freq
//         sort(A.begin(), A.end(), sortByVal);
        
//         // check the map 
        
//         int pos = 0;
//         for (auto it : A) {
//             while(it.second-- > 0) 
//                 nums[pos++] = it.first;
//         }
        
//         return nums;
        
        
        unordered_map<int, int> count;
        for (int a: nums)
            count[a]++;
        
        sort(begin(nums), end(nums), [&](int a, int b) {
            return count[a] == count[b] ? a > b : count[a] < count[b];
        });
        return nums;

    }
};

// O(nlogn)
// O(n)
// use a map for counting freq, then sort nums by count