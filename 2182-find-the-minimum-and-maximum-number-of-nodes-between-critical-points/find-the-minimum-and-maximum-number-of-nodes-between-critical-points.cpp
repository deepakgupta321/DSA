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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next ==NULL or head->next->next==NULL) return {-1,-1};

        vector<int> dis;
        int d=1;
        ListNode* temp=head->next;
        ListNode* prev=head;
        while(temp->next){
            if(temp->val>prev->val && temp->val>temp->next->val){
                dis.push_back(d);
            }
            else if(temp->val<prev->val && temp->val<temp->next->val){
                dis.push_back(d);
            }
            d++;
            temp=temp->next;
            prev=prev->next;
        }

        if(dis.size()<2){
            return {-1,-1};
        }

       
        int minn=INT_MAX;
        for(int i=0; i<dis.size()-1; i++){
            minn=min((dis[i+1]-dis[i]), minn);
        }
        

        return {minn, dis[dis.size()-1]-dis[0]};
        
    }
};