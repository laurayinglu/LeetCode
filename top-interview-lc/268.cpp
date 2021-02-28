// https://leetcode.com/problems/missing-number/
// solution 1: sum(1,n) - sum of array 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
//         int sum = 0;
//         int size = nums.size();
//         for (int i = 0; i < size; i++) {
//             sum += nums[i];
//         }
        
//         int s = (1+size)*size/2;

//         return (s-sum);
        
        // use bit manipulation
        int res = nums.size();
        
        for (int i = 0; i < nums.size(); i++) 
            res ^= (i ^ nums[i]);
        
        return res;
    }
};

// solution2: use bit manipulation XOR 0 ^ 0 = 1, a ^ 1 = a (a != 1);
// eg. n = 3; 2 1 3, with index 0,1,2
// 3 ^(2^0)^(1^1)^(3^2) = 0

// solution3: sort, basically compare with index+1(or previous number + 1) to check 

// solution4: use hashset, find the one that didn't occur
        // Set<Integer> numSet = new HashSet<Integer>();
        // for (int num : nums) numSet.add(num);

        // int expectedNumCount = nums.length + 1;
        // for (int number = 0; number < expectedNumCount; number++) {
        //     if (!numSet.contains(number)) {
        //         return number;
        //     }
        // }
        // return -1;