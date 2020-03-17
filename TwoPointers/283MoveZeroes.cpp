/*
Given an array nums, write a function to move all 0's to the end of it 
while maintaining the relative order of the non-zero elements.

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

NOTE:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/


/* This is a 2 pointer approach. 
The fast pointer which is denoted by variable "cur" does the job of processing new elements. 
If the newly found element is not a 0, we record it just after the last found non-0 element. 
The position of last found non-0 element is denoted by the slow pointer "lastNonZeroFoundAt" variable. 
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // SOLUTION I
        int lastNonZeroFoundAt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }

        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
    
    // SOLUTION II
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
    
};
