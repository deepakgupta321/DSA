/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    

        // vector<int> ptr;
        // Node* temp=head;
        
        // while(temp){
        //     Node* pos=head;
        //     int c=0;
        //     while(pos!=temp->random){
        //         pos=pos->next;
        //         c++;
        //     }
        //     ptr.push_back(c);
        //     temp=temp->next;
        // }
        
        // temp=head;
        // vector<int> v;
        // while(temp){
        //     v.push_back(temp->val);
        //     temp=temp->next;
        // }


        // Node* dummy=new Node(0);
        // Node* x=dummy;
        
        // Node* l=new Node(0);

        // for(auto x: v){

        //     Node* temp=new Node(x);
        //     temp->random=l;
        //     dummy->next=temp;
        //     dummy=dummy->next;


        // }
        // Node* j=x->next;
        
        // for(auto pp: ptr){
        //     Node* y=x->next;
        //     Node* temp=NULL;
        //     while(pp--){

        //         y=y->next;

        //     }
        //     j->random=y;
        //     j=j->next;
        // }


        // return x->next;

    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> m;

        Node* dummy=new Node(0);
        Node* h=dummy;
        Node* temp=head;
        while(temp){
            Node* k=new Node(temp->val);
            dummy->next=k;
            dummy=dummy->next;
            m[temp]=k;
            temp=temp->next;
        }

        temp=head;
        Node* head1=h->next;

        while(head){
            
                head1->random=m[head->random];
                head1=head1->next;
                head=head->next;
        }

        return h->next;
        
    }
};