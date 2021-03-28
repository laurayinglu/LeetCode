class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m-1;
        int r = n-1;
        int pos = m+n-1;
        while (l >= 0 && r >= 0){
            nums1[pos--] = (nums1[l] > nums2[r]) ? nums1[l--]:nums2[r--];
        }
        
        while(r >= 0) {
            nums1[pos--] = nums2[r--];
        }
    }
};

// 1 3 5 0 0 0 
// 2 4 6
// 1 2 3 4 5 6

// once all nums2 elements are inserted, then the rest of the nums1 is sorted