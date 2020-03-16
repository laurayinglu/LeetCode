/* Given two arrays, write a function to compute their intersection.
 Each element in the result should appear as many times as it shows in both arrays.
 The result can be in any order.

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
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

