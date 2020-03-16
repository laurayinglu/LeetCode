//Given an array of integers A sorted in non-decreasing order, 
//return an array of the squares of each number, also in sorted non-decreasing order.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // two pointers
        vector<int> res;
        
        for(int i = 0; i<A.size(); i++)
            res.push_back(A[i]);
        
        int size = A.size()-1;
        int i = 0;
        int j = size;
        
        for(int k = size; k >= 0; k--)
        {
            if(abs(A[i]) > abs(A[j])){
                res[k] = pow(A[i],2);
                i++;
            }
            else{
                res[k] = pow(A[j],2);
                j--;
            }
        }
        
        return res;
         
    }
};
