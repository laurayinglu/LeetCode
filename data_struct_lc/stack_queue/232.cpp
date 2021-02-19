// https://leetcode.com/problems/implement-queue-using-stacks/
// s1 is for input
// s2 is for output

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    /** Initialize your data structure here. */
    MyQueue() { }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        // first push in first stack 
        s1.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int top = 0;
        // pop from s2 if s2 is not empty
        if (s2.empty()){
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        top = s2.top();
        s2.pop();
            
        return top;
    }
    
    /** Get the front element. */
    int peek() {

        // pop from s2 if s2 is not empty
        if (s2.empty()){
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
                 
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (s2.empty() && s1.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */