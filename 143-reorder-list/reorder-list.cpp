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

    int count(ListNode* head){
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }


    void reorderList(ListNode* head) {

        int k=count(head);
        k=k/2;

        ListNode* temp=head;
        ListNode* x=head;
        ListNode* prev=NULL;
        ListNode* next=head;
        while(k){
            next=temp->next;
            while(temp->next){
                prev=temp;
                temp=temp->next;
            }
            x->next=temp;
            if(prev!=x){
                prev->next=NULL;
                temp->next=next;
            }

           else{
             return;
           }
            
            temp=next;
            x=next;
            k--;

        }
    }
};