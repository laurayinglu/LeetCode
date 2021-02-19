// https://leetcode.com/problems/non-overlapping-intervals/
// the same as "Given a collection of intervals, find the maximum number of intervals that are non-overlapping." 
// Sorting Interval.end in ascending order is O(nlogn), then traverse intervals array to get the maximum number of non-overlapping intervals is O(n). Total is O(nlogn).

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0; 
        }
        // sort the intervals by ending interval
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {
          return a[1] < b[1];
        });
        
        int n = intervals.size();
        int prev = intervals[0][1]; // first ending interval
        int total = 1; // count max number of intervals that has no overlapping
        
        // each time compare with left interval to see if overlapping
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prev){ // has no overlapping
                total++;
                prev = intervals[i][1];
            }
        }
        // [[1,11],[2,12],[11,22]]
        // 
        return n-total;
    }
};

// [[1,2],[2,3],[3,4],[1,3]]
// [1,2],[2,3],[1,3],[3,4]