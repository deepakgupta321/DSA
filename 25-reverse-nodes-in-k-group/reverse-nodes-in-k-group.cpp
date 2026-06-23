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

    void reverse(ListNode* &curr, int k, ListNode* &pre){
        ListNode* next=NULL;
        ListNode* prev=NULL;
        ListNode* temp=curr;
        while(k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            k--;
        }
        pre->next=prev;
        pre=temp;
        temp->next=curr;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or head->next==NULL){
            return head;
        }

        if(k==1){
            return head;
        }
        
        int c=count(head);
        c=c/k;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* pre=dummy;
        ListNode* curr=head;
        while(c){
            reverse(curr,k,pre);
            c--;
        }

      return dummy->next;
    }
};