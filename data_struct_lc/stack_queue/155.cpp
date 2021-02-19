// https://leetcode.com/problems/min-stack/

// solution1: using vector to implement
// or can use Node to implement, Node(x,min, next)
/*void push(int x) {
    if (head == null)
        head = new Node(x, x, null);
    else 
        head = new Node (x, min(x, head.getMin(), head));
}*/

class MinStack {
private:
    vector<pair<int, int>> minStack; // <value, minvalue>
public:
    MinStack() {}
    void push(int x) {
        if(minStack.empty()) 
            minStack.push_back({x,x});
        else 
            minStack.push_back({x, min(minStack.back().second, x)});
    }
    
    void pop() {
        minStack.pop_back(); // pop from the back, follow LIFO
    }
    
    int top() {
        return minStack.back().first;
    }
    
    int getMin() {
        return minStack.back().second;
    }
};

// solution2: using 2 stacks

// class MinStack {
// public:
    
//     /** initialize your data structure here. */
//     stack<int> min;
//     stack<int> s;
    
//     MinStack() {}
    
//     void push(int x) {
//         s.push(x);
//         if (min.empty() || x <= min.top())
//             min.push(x);
//     }
    
//     void pop() {
        
//         if (!min.empty() && min.top() == s.top() )
//             min.pop();
            
//         s.pop();
//     }
    
//     int top() {
//         return s.top();
//     }
    
//     int getMin() {
//         return min.top();
//     }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */