/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

// use fast-slow two pointers
class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)  return 0;
     
        int i = 0; // slow pointer
        for(int j = 0; j<nums.size(); j++) // j is the fast pointer
        {
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
   }
}

// Basically this solution is moving the unique elements to be the first x elements in vector
// it doesn't actually remove the duplicated elements
// [1,1,2,2,3,4,4,4,5]->[1,2,3,4,5,4,4,4,5]


// my version
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)  return 0;
        unordered_map<int, int> umap;
       
        for(int i = 0; i<nums.size(); i++)
        {
            umap[nums[i]]+=1;
            if(umap[nums[i]]>1)
            {
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        
        return nums.size();
    }
};
