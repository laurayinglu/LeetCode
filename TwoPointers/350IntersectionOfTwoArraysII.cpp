/* Given two arrays, write a function to compute their intersection.
 Each element in the result should appear as many times as it shows in both arrays.
 The result can be in any order.

Follow up:

- What if the given array is already sorted? How would you optimize your algorithm?
1) Classic two pointer problem

- What if nums1's size is small compared to nums2's size? Which algorithm is better?
1) 

- What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
1) Map-Reduce (maybe)
*/

class Solution {

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

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

            res.push_back(nums1[l]);
            s++;
            l++;

        }

        return res;
    }
    
};
// time: O(nlogn)
// space: O(1)
// we can also use hashmap to record frequencies

// equivalent way
  sort(a.begin(), a.end()); 
  sort(b.begin(), b.end());
  a.erase(set_intersection(a.begin(), a.end(), b.begin(),b.end(), a.begin()), a.end());
  return a;

// use hashmap version
  unordered_map<int, int> ctr;
    for (int i : a)
        ctr[i]++;
    vector<int> out;
    for (int i : b)
        if (ctr[i]-- > 0)
            out.push_back(i);
    return out;
