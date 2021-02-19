// https://leetcode.com/problems/assign-cookies/

// greedy: always assign cookie with smallest value that can satisfy child with smallest greed first

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int child = 0;
        int cookie = 0;
        // sort both 
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        // assign
        while (child < g.size() && cookie < s.size()) {
            // find minimum s that satisfy child with smallest content
            if (s[cookie] >= g[child])
                child++;
            
            cookie++;
        }
        
        return child;
        
    }
};