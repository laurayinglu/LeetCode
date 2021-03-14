// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        // my solution:
        // unordered_map<int, int> c;
        // int n = A.size()/2;
        //If we ever find a repeated element, it must be the answer. Let's call this answer the major element.
        // for (int i = 0; i < A.size(); i++){
        //     c[A[i]]++;
        //     if (c[A[i]]>1)
        //         return A[i];
        // }
        
        // return 0;

        // solution 2: using set
        unordered_set<int> seen;
        for (int a: A) {
            if (seen.count(a))
                return a;
            seen.insert(a);
        }

        // solution 3:
        for (int i = 2; i < A.size(); ++i)
            if (A[i] == A[i - 1] || A[i] == A[i - 2])
                return A[i];
        // exception case: xxyz or xyzx
        return A[0];

    }
};