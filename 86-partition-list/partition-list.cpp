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
    ListNode* partition(ListNode* head, int x) {


        if(head==NULL or head->next==NULL){return head;}

        ListNode* small=new ListNode(0);
        ListNode* h1=small;
        ListNode* large=new ListNode(0);
        ListNode* h2=large;
        
        ListNode* temp=head;
        while(temp){
            if(temp->val>=x){
                large->next=temp;
                large=large->next;    
            }
            else{
                small->next=temp;
                small=small->next;
            }
            temp=temp->next;
            large->next=NULL;
            small->next=NULL;
        }
        small->next=h2->next;
        return h1->next;
    }
};