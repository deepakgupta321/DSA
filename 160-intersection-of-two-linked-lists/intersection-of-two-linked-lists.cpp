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
        ListNode *d= headA;
        while(d->next!=NULL){
            d=d->next;
        }
        ListNode *h=d;
        d->next=headA;
        ListNode *slow=headB;
        ListNode* fast=slow;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=headB;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                h->next=NULL;
                return fast;
            }
        }

        h->next=NULL;
        return NULL;
        
    }
};