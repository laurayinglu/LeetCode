// https://leetcode.com/problems/next-greater-element-ii/
// for circular array, we can double the array and then use nums[i%n] to get the element
// using stack to store the index
/*

The key of approach#3 is that when we are trying to find the next greater number for 
the ith number and num[i] >= num[i+1], what do we do next? In the brute force way, 
we will go on to check num[i+2], num[i+3]... and there is much redundant work here. 
The better way is to check the next greater number of num[i+1]. If the next greater number 
of num[i+1] is still not greater than num[i], go on to check its next greater number. 

*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> s; // index stack
        for (int i = 0; i < n * 2; i++) {
            int num = nums[i % n]; 
            while (!s.empty() && nums[s.top()] < num) {
                next[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }   
        return next;
    }
};