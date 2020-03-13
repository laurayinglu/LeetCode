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



// better solution
