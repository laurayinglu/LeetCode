// https://leetcode.com/problems/partition-labels/

// Greedy idea,  repeatedly choose the smallest left-justified partition,  
// For each letter encountered, process the last occurrence of that letter, 
// extending the current partition [anchor, j] appropriately.

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last(26, 0);
        
        for (int i = 0; i < S.length(); i++) {
            last[S[i]-'a'] = i;
        }
        
        int start = 0; // record the start of the partition
        int end = 0; // record the end of the partition
        vector<int> res;
        for (int i = 0; i < S.length(); i++) {
            end = max(end, last[S[i]-'a']);
            
            if (i == end){
                res.push_back(end-start+1);
                start = end+1;
            }
                
        }
        
        return res;
    }
};