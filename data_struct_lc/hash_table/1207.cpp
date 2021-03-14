// https://leetcode.com/problems/unique-number-of-occurrences/


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // my solution 
        unordered_map<int, int> c;
        set<int> m;
        for (int i = 0; i < arr.size(); i++) {
            c[arr[i]]++;
        }
        
        for (auto it = c.begin(); it != c.end(); it++) {
            if (m.count(it->second))// if already in the list
                return false;
            else
                m.insert(it->second);
        }
        
        return true;

        // solution 2:
        unordered_map<int, int> m;
        unordered_set<int> s;
        for (auto n : arr) ++m[n];
        for (auto& p : m) s.insert(p.second);
        return m.size() == s.size(); // if size are the same then means uniques
    }
};