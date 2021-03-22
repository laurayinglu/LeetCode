// https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head)
            return false;
        if (!head->next)
            return true;
        
        vector<int> v;
        
        ListNode* curr = head;
        while(curr){
            v.push_back(curr->val);
            curr = curr->next;
        }
        
        int r = v.size()-1;
        int l = 0;
        
        while(l <= r) {
            if (v[l]!=v[r])
                return false;
            l++;
            r--;      
        }
        
        return true;
        
    }
};

// solution 2: reverse the first half and check if it's the same as the second half
        if (!head)
            return false;
        if (!head->next)
            return true;
        
        bool even = false;
        
        ListNode* mid = head;
        ListNode* fast = head;
        while(fast && fast->next){
            mid = mid->next;
            fast = fast->next->next;
        }
        
        
        // reverse the first half
        ListNode* curr = NULL;
    
        while(head != mid) {
            ListNode* temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
        }
        
        if (fast && !fast->next) //odd
            mid = mid->next;
        
        while(curr) {
            if (curr->val != mid->val)
                return false;
            
            curr = curr->next;
            mid = mid->next;
        }
        
        return true;