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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast)
        {
            if(fast->next == NULL) // odd num nodes
            {
                return slow;
            }
            else if(fast->next->next == NULL) // even num nodes
            {
                return slow->next;
            }
            else
            {
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        
        return slow;
        
    }
};

// while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
// return slow;