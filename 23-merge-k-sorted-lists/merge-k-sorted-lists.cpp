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

    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummy=new ListNode(0);
        ListNode* x=dummy;
        while(h1 and h2){
            if(h1->val<h2->val){
                dummy->next=h1;
                h1=h1->next;
                dummy=dummy->next;
            }

            else{
                dummy->next=h2;
                h2=h2->next;
                dummy=dummy->next;
            }
            
        }
                    if(h1!=NULL){
                dummy->next=h1;
            }
            if(h2!=NULL){
                dummy->next=h2;
            }
return x->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1 ){
            return lists[0];
        }
        if(lists.size()==0){
            return NULL;
        }
        ListNode* result=lists[0];
        for(int i=1; i<lists.size(); i++){
            ListNode* l=lists[i];
            result=merge(result,l);

        }

        return result;

    }
};