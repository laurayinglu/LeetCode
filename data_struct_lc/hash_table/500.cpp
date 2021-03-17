// https://leetcode.com/problems/keyboard-row/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        // my solution:
        vector<string> res;
        string kb[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

        for(string s: words) {
            int idx = -1;
            
            if(kb[0].find(tolower(s[0])) != string::npos)
                idx = 0;
            else if (kb[1].find(tolower(s[0])) != string::npos)
                idx = 1;
            else if (kb[2].find(tolower(s[0])) != string::npos)
                idx = 2;
            else
                continue;
            bool good = true;
            for (int i = 1; i < s.length(); i++){
                if(kb[idx].find(tolower(s[i])) == string::npos){
                    good = false;
                    break;
                }
            }
            if (good)
                res.push_back(s);
        }
        
        return res;

        // solution 2:
        // can save string in unordered_set so find is O(1)
        std::unordered_set  dict1 = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
		std::unordered_set  dict2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'};
		std::unordered_set  dict3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'};

		vector res;

		for (auto &word : words)
		{
			bool d1 = true, d2 = true, d3 = true;

			for (auto & ch : word)
			{
				if (d1) {
					auto it = dict1.find(ch);
					if (it == dict1.end()) d1 = false;
				}

				if (d2) {
					auto it = dict2.find(ch);
					if (it == dict2.end()) d2 = false;
				}

				if (d3) {
					auto it = dict3.find(ch);
					if (it == dict3.end()) d3 = false;
				}
			}

			if (d1 || d2 || d3) res.push_back(word);
		}

		return res;
    }
};