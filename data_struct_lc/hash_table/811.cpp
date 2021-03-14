// https://leetcode.com/problems/subdomain-visit-count/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count;
        for (string s: cpdomains) {
            int i = s.find(" ");
            int n = stoi(s.substr(0,i));
            string rest = s.substr(i+1);
            cout << rest << endl;
            for (int i = 0; i < rest.size(); ++i)
                if (rest[i] == '.')
                    count[rest.substr(i + 1)] += n; // substring after "."
            count[rest] += n;
        }
        
        vector<string> res;
        for (auto k : count)
            res.push_back (to_string(k.second) + " " + k.first);
        
        return res;
    }
};