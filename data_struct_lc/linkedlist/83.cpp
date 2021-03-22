// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr){
            if (curr->val == prev->val) {
                // delete curr
                prev->next = curr->next;
                curr = prev->next;
            }else {
                //ListNode* temp = curr->next;
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};

        // ListNode* curr = head;
        
        // while(curr && curr->next) {
        //     if (curr->val == curr->next->val)
        //         curr->next = curr->next->next;
        //     else
        //         curr = curr->next;
        // }
        
        // return head;