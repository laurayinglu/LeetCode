
//Given an array consisting of n integers, 
//find the contiguous subarray of given length k 
//that has the maximum average value. And you need to output the maximum average value.

// sliding solution
double findMaxAverage(vector<int>& nums, int k) {
    double sum=0, res=INT_MIN;
    for(int i=0;i<nums.size();i++) {
        if(i<k) sum+=nums[i];
        else {
            res=max(sum, res);
            sum+=nums[i]-nums[i-k];
        }
    }
    res=max(sum, res);
    return res/k;
}

// time: O(n)
// space: O(1)

// my solution: better way is use cumulative sum, sum[i] = sum[i-1]+nums.at(i)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        if(nums.size() <= k) 
            return accumulate(nums.begin(), nums.end(), sum)/(k*1.0);
        
       
        double avg = 0;
        
        for(int i = 0; i<k; i++) {sum += nums.at(i);}
        avg = sum/k;
        double max = avg;
        
        for(int i = 0; i <= nums.size()-k; i++)
        {
            // since k-1 elements are the same
            if((i+k) < nums.size()-1 && nums.at(i+k) >= nums.at(i))
            {
                continue;
            }
            
            sum = 0;
            for(int j = 0; j < k; j++)
            {
                sum += nums.at(i + j);
            }
            
            avg = sum/k;
            
            if(avg >=max)
                max = avg;    
        }
        
        return max;
     
        }
};


// Runtime: 1480 ms, faster than 5.09%
// Memory Usage: 16 MB, less than 100.00%

