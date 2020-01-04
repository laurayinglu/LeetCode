
// https://leetcode.com/problems/buddy-strings/submissions/

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() < 2 || B.length() < 2 || (A.length() != B.length())) return false;
        
        // if A and B are the same string
        if(A==B)
        {
            // set store all unique elements of string A
            // return true if they have duplicated elements in A
            if(set<char>(A.begin(), A.end()).size() < A.size()) 
                return true;
            
            return false;
        }
        
        
        int diff[2];
        int cnt = 0;
        // if strings are different
        for(int i = 0; i < A.length(); i++)
        {
            if(A[i] != B[i])
            {
                cnt++;
                if(cnt > 2) return false;
                diff[cnt-1] = i;
            }
        }
        
        if( (A[diff[0]] == B[diff[1]]) && (A[diff[1]] == B[diff[0]]) )
            return true;
           
        return false;
    
    }
};