/*
EXAMPLE:
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // iterative method
//     ListNode* reverseList(ListNode* head) {
//         ListNode* newTail = NULL;
//         ListNode* temp = head;
//         while(temp)
//         {
//             ListNode* newHead = new ListNode(temp->val);
//             newHead->next = newTail;
//             newTail = newHead;
//             temp = temp->next;
//         }
        
//         return newTail;
//     }
    
    // recursive method
    // suppose head->next has been reversed
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        // 1->2->3->4
        ListNode* p = reverseList(head->next); // 4->3->2->NULL
        head->next->next = head; // 2->1
        head->next = NULL;
        
        return p;
    }
    
};