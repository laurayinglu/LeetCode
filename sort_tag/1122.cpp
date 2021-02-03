// https://leetcode.com/problems/relative-sort-array/

// vector<int> arr;
// int getIndex(vector<int> v, int K)
// {
//     int index = -1;
//     auto it = find(v.begin(), v.end(), K);
    
//     if (it != v.end()) 
//     {
//         index = it - v.begin();
//     }
//     return index;
// }

// bool compare(int a, int b) {
//     // if the index of a is smaller than index of b
//     if (getIndex(arr, a) == -1 && getIndex(arr, b) != -1) {
//         return false;
//     } else if (getIndex(arr, a) != -1 && getIndex(arr, b) == -1)
//         return true;
//     else if (getIndex(arr, a) == -1 && getIndex(arr, b) == -1)
//         return a < b;
    
//     return getIndex(arr, a) < getIndex(arr, b);
// }



// solution uses map <value in arr1: freq of value>
// a Map in C++ is sorted in increasing order based on its key.
class Solution {
public:
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // arr = arr2;
        // sort(arr1.begin(), arr1.end(), compare);
        // return arr1;
        
       // solution2: using map
        map<int, int> m;
        for (auto i : arr1) m[i]++;
        int pos = 0;
        for (auto j : arr2) {
            while(m[j]-- > 0) arr1[pos++] = j;
        }
        
        // By default, Map(Key: value) m{(1,1), (2, 3), (3,2),...}
        for (auto it : m) {
            while(it.second-- > 0) arr1[pos++] = it.first;
        }
        return arr1;
    
    }
    
};