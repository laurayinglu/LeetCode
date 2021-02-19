// https://leetcode.com/problems/check-array-formation-through-concatenation/
#include <vector>
#include <iostream>

using namespace std;

int find(vector<int>& arr, int a) {
    for (int i = 0 ; i < arr.size(); i++) {
        if (arr[i] == a)
            return i;
    }
    
    return -1;
}

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        bool res = true;
        for (int i = 0; i < pieces.size(); i++) {
            int index = find(arr, pieces[i][0]);
            if (index == -1)
                return false;
            for (int j = 0; j < pieces[i].size(); j++) {
                if ((index + j)>=arr.size() || arr[index+j] != pieces[i][j])
                    return false;
            }
        }
        
        return res;
    }
};
