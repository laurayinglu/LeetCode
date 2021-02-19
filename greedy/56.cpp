// https://leetcode.com/problems/merge-intervals/
// sort intervals by left interval, then loop and merge
// use res.back() to track the last one in res

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return intervals;
        
        int n = intervals.size();
        vector<vector<int>> res;
        // sort the intervals by ending interval
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {
          return a[0] < b[0];
        });
        
        int index = 0;
        res.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <=  res.back()[1]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else {
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        
        return res;
    }
};