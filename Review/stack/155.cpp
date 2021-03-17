// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s; // normal stack
    stack<int> m; // for saving min values
    MinStack() {}
    
    void push(int x) {
        s.push(x);
        if (m.empty() || x <= m.top())
            m.push(x);
    }
    
    void pop() {   
        if (!m.empty() && !s.empty() && s.top() == m.top())
            m.pop();
        
        if (!s.empty())
            s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// class MinStack {
// private:
//     vector<pair<int, int>> minStack; // <value, minvalue>
// public:
//     MinStack() {}
//     void push(int x) {
//         if(minStack.empty())
//             minStack.push_back({x,x});
//         else
//             minStack.push_back({x, min(minStack.back().second, x)});
//     }

//     void pop() {
//         minStack.pop_back(); // pop from the back, follow LIFO
//     }
    
//     int top() {
//         return minStack.back().first;
//     }
    
//     int getMin() {
//         return minStack.back().second;
//     }
// };
