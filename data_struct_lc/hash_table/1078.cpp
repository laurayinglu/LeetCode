// https://leetcode.com/problems/occurrences-after-bigram/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        // my solution:
        string tar = " " + first + " " + second + " ";
        vector<string> res;
        string temp = " " + text + " ";
        int pos = temp.find(tar);
        while(pos != string::npos) {
            //cout << "come" << endl;
            temp = temp.substr(pos+tar.length());

            int space = temp.find(" ");
            if (space != string::npos)
                res.push_back(temp.substr(0,space));
            else
                return res;

            temp = " " + temp;
            
            pos = temp.find(tar);

        }
       
        return res;

        // solution2: use istringstream
        vector<string> ans;
        istringstream ss(text); // for input
        string prev2, prev, word;
        while (ss >> word) {
            if (prev2 == first && prev == second) ans.push_back(word);
            prev2 = prev;
            prev = word;
        }
        return ans;
        
    }
};