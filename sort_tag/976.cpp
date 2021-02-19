// https://leetcode.com/problems/largest-perimeter-triangle/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        // sort and then choose backforward strike = 3
        sort(A.begin(), A.end());
        int per = 0;
        for (int i = A.size()-3; i >= 0; i -= 1) {
            // if satisfy condition 
            if (A[i] + A[i+1] > A[i+2])
                return (A[i]+A[i+1]+A[i+2]);
        
        }
        
        return 0;
    }   
};