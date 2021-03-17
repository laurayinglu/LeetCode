// https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        if (ops.size() < 1)
            return 0;
        stack<int> s;
        int res = 0;
        for(int i = 0; i < ops.size(); i++) {
            if (s.empty()){
                s.push(stoi(ops[i]));
                res += stoi(ops[i]);
            }
            else{
                if (ops[i] == "C"){
                    res -= s.top();
                    s.pop();
                }
                else if(ops[i] == "D"){
                    res += s.top()*2;
                    s.push(s.top()*2);
                }
                else if (ops[i] == "+") {
                    int prev = s.top();
                    s.pop();
                    int prev2 = s.top();
                    int sum = prev + prev2;
                    s.push(prev);
                    s.push(sum);
                    res += sum;
                }else
                {
                    s.push(stoi(ops[i]));
                    res += stoi(ops[i]);
                }
            }
            
           // cout << ops[i]<<" "<<res << endl;
        }
        
        return res;  

        // SOLUTION2 : can also use vector 
        vector<int> rounds;
        int lastIndex=0;
        
        for(string str : ops){
            if(isdigit(str[0]) || str[0] == '-'){
                rounds.push_back(std::stoi(str));
            }
            else if(str[0] == '+'){
                rounds.push_back(rounds[lastIndex]+rounds[lastIndex-1]);
            }
            else if(str[0] == 'D'){
                rounds.push_back(2*rounds[lastIndex]);
            }
            else if(str[0] == 'C'){
                rounds.pop_back();
            }
            
            lastIndex = rounds.size()-1;
        }
        
        return accumulate(rounds.begin(), rounds.end(),0); // calculates sum of vector
    }
    
};