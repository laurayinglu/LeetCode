// 53. Maximum Subarray

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = nums.at(0);
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums.at(i);
          
          // This is for the case: all negative nums
            if(nums.at(i) > max)
                max = nums.at(i);
          
          // This is for case with at least one non-negative num
            if(sum < 0){
                sum = 0;
            }
            else if(sum >= max)
                max = sum;   
        }
        return max;
    }
};

/* Other people's solution
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans=A[0],i,j,sum=0;
        for(i=0;i<n;i++){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};
*/
