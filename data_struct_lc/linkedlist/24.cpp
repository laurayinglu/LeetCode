// https://leetcode.com/problems/swap-nodes-in-pairs/

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
void print(ListNode* head) {
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    
    cout << endl;
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // iterative version
        // curr->1->2->3->4->null
        // head = 1,curr = 0;  (1st loop)
        // first->2->1->3->4->null
        // head = 3, curr = 1; (2nd loop)
        if (!head || !head->next)
            return head;
        
        ListNode* first = new ListNode(0); 
        ListNode* curr = first;
        curr->next = head;
        
        while(head && head->next) { 
            // swap nodes
            ListNode* temp = head->next;
            head->next = temp->next;
            temp->next = head;
            
            curr->next = temp;
            curr = head; // keep track of the previous node
            //print(curr);
            head = head->next;
        }
        
        return first->next;
        
        
        // recursive version
//         if (!head || !head->next)
//             return head;
        
//         ListNode* res = head->next;
//         head->next = swapPairs(res->next);
//         res->next = head;
//         return res;
        
        
        
    }
};