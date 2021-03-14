// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/588/week-1-march-1st-march-7th/3660/

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
        // solution 1: get length of each linkedlist and traverse O(n)
//         if (!headA || !headB)
//             return NULL;
//         int la = 0;
//         int lb = 0;
        
//         ListNode* pa = headA;
//         ListNode* pb = headB;
        
//         while (pa != NULL) {
//             la++;
//             pa = pa->next;
//         }
        
//         while (pb != NULL) {
//             lb++;
//             pb = pb->next;
//         }
        
// //        cout << la << lb << endl;
        
//         pa = headA;
//         pb = headB;
        
//         if (lb > la) {
//             for (int i = 0; i < (lb-la);  i++)
//                 pb = pb->next;
//         }
//         else {
//             for (int i = 0; i < (la-lb);  i++)
//                 pa = pa->next;
//         }
        
//         cout << pa->val << " "<<pb->val<< endl;
            
//         if (pa == pb)
//             return pa;
        
//         while(pa!=NULL && pb!=NULL) {
//             cout << pa->val << " "<<pb->val<< endl;
//             pa = pa->next;
//             pb = pb->next;
//             if(pa == pb)
//                 return pa;

//         }
        
//         return null;
        
        // solution 2: two pointer iterate O(n)
        // Linked list A: a*c (c is common part), B: b*c
        // a*c*b*c; b*c*a*c
        // iterate a*c*b then would get c
        
        if (!headA || !headB)
            return NULL;
        
        ListNode* pa = headA;
        ListNode* pb = headB;
        
        while(pa != pb && pa != NULL && pb != NULL){
            pa = pa->next;
            pb = pb ->next;
            if (pa == pb)
                return pa;
            
            if (pa == NULL)
                pa = headB;
            
            if (pb == NULL)
                pb = headA;
        } 
        
        return pa;
        
        
    }
};