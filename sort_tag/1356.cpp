//https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/


unsigned int num_bits(int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

bool compare(int a, int b) {
   
    if (num_bits(a) == num_bits(b)) 
        return a < b;
        
    return (num_bits(a) < num_bits(b));
    
    //return num_bits(a) == num_bits(b) ? a<b:num_bits(a) < num_bits(b);

}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        // first sort arr in ascending order 
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};