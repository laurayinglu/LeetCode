//https://leetcode.com/problems/sort-array-by-parity-ii/

// the second one is in-place, make sure odd number are in the right place then the even number must 
// be in the right place

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
//         int p_even = 0; // record index of even 
//         int p_odd = 1;
        
//         vector<int> res = A;
//         //print(res);
//         for (int i = 0 ; i < A.size(); i++) {
//             if (A[i] % 2 == 0) {// if it's even 
//                 res[p_even] = A[i];
//                 p_even += 2;
//             }
        
//             if (A[i] %2 == 1) {// if it's odd
//                 res[p_odd] = A[i];
//                 p_odd += 2;
//             }
        
//         }
        
//         return res;
        
        
        
        // in place solution 
       for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
        while (i < A.size() && A[i] % 2 == 0) i += 2;
        while (j < A.size() && A[j] % 2 == 1) j += 2;
        if (i < A.size()) swap(A[i], A[j]);
        }
        return A;
    }
};
    