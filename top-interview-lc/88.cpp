// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         for (int i = m; i < m+n; i++)
//             nums1[i] = nums2[i-m];
        
//         sort(nums1.begin(), nums1.end());
        
        // use two pointers O(m+n)
        // https://leetcode-cn.com/problems/merge-sorted-array/solution/he-bing-liang-ge-you-xu-shu-zu-by-leetcode/
        int p1 = m-1;
        int p2 = n-1;
        int p = m+n-1;
        
        while(p2 >= 0) { 
            if(p1 >= 0 && nums1[p1] >= nums2[p2]){
                nums1[p] = nums1[p1];
                p1--;
            }else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
            
            //nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
        }
        

    }
};