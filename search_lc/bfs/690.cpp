// https://leetcode.com/problems/employee-importance/

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:

    int getImportance(vector<Employee*> employees, int id) {
        if (employees.size() == 0)
            return 0;
        int res = 0;
        unordered_map<int, Employee*> m;
        for (auto e:employees)
            m.insert({e->id,e});
        
        queue<Employee*> q;
        
        // find first one to push
        q.push(m[id]);
    
        while (!q.empty()) {
            Employee* cur = q.front();
            q.pop();
            res += cur->importance;
            int size = cur->subordinates.size();// number of subor
            for (int i = 0; i < size; i++) {// push all sub in
                q.push(m[cur->subordinates[i]]);
            }
        }
        
        return res;
        
    }
    
    // use hashmap and dfs
//     unordered_map<int, Employee*> m;
    
//     int getImportance(vector<Employee*> employees, int id){
//         for (auto e:employees)
//             m.insert({e->id,e});
        
//         return dfs(id);
//     }
//     // importance recursion
//     int dfs(int id) {
//         Employee* cur = m[id];
//         int res = cur->importance;
//         for (int idx: cur->subordinates){
//             res += dfs(idx);
//         }
        
//         return res;
//     }
};