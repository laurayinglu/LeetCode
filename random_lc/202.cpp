// https://leetcode.com/problems/happy-number/
// use fast/slow pointer to detect cycle: Floyd's Cycle detection
// solution2: use hashmap to check if the element is already in the set
int next(int num) {
    int sum = 0;
    while(num != 0) {
        sum += (num%10)*(num%10);
        num = num/10;
    }
    
    return sum;
}
class Solution {
public:
    bool isHappy(int n) {
        int fast = next(n);
        int slow = n;
        // use fast/slow pointer to detect cycle
        while (fast != slow) {
            slow = next(slow);
            fast = next(next(fast));
        }
        
        return (slow==1);

        // use hashmap to check if it's already in the set
        // unordered_set<int> s;
        // while(n != 1){
        //     //cout <<n<< endl;
        //     if (s.find(n) == s.end()) // the number is not in the set
        //         s.insert(n);
        //     else 
        //         return false;
            
        //     n = next(n);
            
        // }
        
        // return true;
        
    }
};