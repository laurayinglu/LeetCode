// https://leetcode.com/problems/reverse-linked-list/
// each time reverse a node, leep track of the prev node

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
//     ListNode* reverseList(ListNode* head) {
//         // iterative version
//         ListNode *prev = nullptr, *next;
        // while (head) {
        //    next = head->next;
        //    head->next = prev;
        //    prev = head;
        //    head = next;
        // }
        // return prev;
//     }
    
    ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
        // recursive version 
        if (!head) // head == NULL
            return prev;
        
        ListNode* next = head->next;
        head->next = prev;
        
        
        return reverseList(next, head);
    
    }
};