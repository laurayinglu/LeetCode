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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //A + C
        // B + C
        // A + c + b + c
        // b + c + a + c
        if (!headA || !headB)
            return NULL;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a && b) {
            if (a != b) {
                a = a->next;
                b = b->next;
            }
            // else 
            //     return a;
            
            if (a == b)
                return a;
            
            if (a == NULL)
                a = headB;
            
            if (b == NULL)
                b = headA;
        }
        
        return a;
    }
};