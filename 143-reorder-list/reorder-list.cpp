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
    ListNode* middle(ListNode*& head){
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* next=head;
        while(head){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {

        if(head==NULL or head->next==NULL){
            return;
        }
        ListNode* left=head;
        ListNode* r=middle(head);
        ListNode* right=reverse(r);
        
        ListNode* dummy=new ListNode(0);
        ListNode* y=dummy;

        while(left and right){
            dummy->next=left;
            left=left->next;
            dummy=dummy->next;
            dummy->next=right;
            right=right->next;
            dummy=dummy->next;
            
            
            
        }

        head=y->next;
        
    }
};