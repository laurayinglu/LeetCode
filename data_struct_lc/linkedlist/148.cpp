// https://leetcode.com/problems/sort-list/

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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right) {
        //cout << left->val << " "<< right->val<<endl;
        //ListNode* dummy = new ListNode(0);
        ListNode dummy(-1);
        ListNode* head = &dummy;
        while(left && right) {
            if (left->val < right->val) {
                head->next = left;
                left = left->next;
            } else {
                head->next = right;
                right = right->next;
            } 
            
            head = head->next;
        }
        head->next = (left) ? left : right;
        
        return dummy.next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        // merge sort: O(nlogn)
        
        // step1: split the linkedlist
        ListNode* mid = getMid(head);
        ListNode* tmp = mid->next;
        mid->next = NULL;
        
        head = sortList(head);
        ListNode* right = sortList(tmp);
        
        return merge(head, right);
        
    }
};