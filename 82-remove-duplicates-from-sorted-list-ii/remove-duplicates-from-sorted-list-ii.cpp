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

        if(head==NULL or head->next==NULL){return head;}

        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=head;
        ListNode* forw=head->next;


        while(forw){
            int x=curr->val;
            int y=forw->val;
            if(x!=y){
                prev=curr;
                curr=forw;
                forw=forw->next;
            }

            else{
                while(x==forw->val){
                    if(forw->next==NULL){
                        prev->next=NULL;
                        return dummy->next;
                    }
                    forw=forw->next;

                }
                prev->next=forw;
                curr=forw;
                forw=forw->next;
            }
        }
        return dummy->next;
    }
};