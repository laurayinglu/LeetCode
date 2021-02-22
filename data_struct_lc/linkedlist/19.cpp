//https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// solution1: find size of the linkedlist
// solution2: use fast/slow pointer to find nth node from the end: fast pointer move n forward at first

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // first find the length of list
//         int size = 0;
//         ListNode* h = head;
//         while(h) {
//             size++;
//             h = h->next;
//         }
        
//         ListNode* t = head;
//         int s = 0;
        
//         // if delete head
//         if ((size-n) == 0) {
//             head = head->next;
//             return head;
//         }
//         while(t) {
//             s++;
//             if (s == (size-n)) {
//                 ListNode* tmp = t->next;
//                 t->next = tmp->next;
//             }
//             t = t->next;  
            
//         }
        
//         return head;
        
        
        // use fast/slow pointer to find nth node from end of list
       
        ListNode* h = head;
        ListNode* slow = h;
        ListNode* fast = h;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        
        if (!fast){ // if delete first node
            return head->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        // delete slow->next
        slow->next = slow->next->next;
        
        return head;
    }
};