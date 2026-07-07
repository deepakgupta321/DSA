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
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL or head->next==NULL){return head;}

        stack<int> s;
        s.push(head->val);

        ListNode* temp=head->next;
        while(temp){
            while(!s.empty() and temp->val>s.top()){
                s.pop();
            }   
                s.push(temp->val);
                temp=temp->next;  
        }

        temp=head;
        stack<int> k;
        while(!s.empty()){
            k.push(s.top());
            s.pop();
        }
        ListNode* prev=NULL;
        while(!k.empty()){
            prev=temp;
            temp->val=k.top();
            k.pop();
            temp=temp->next;
        }
        
        prev->next=NULL;
        return head;
    }
};