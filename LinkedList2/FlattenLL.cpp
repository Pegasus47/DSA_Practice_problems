/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==nullptr)
            return head;
        //do not dummy where its not needed
        vector<Node*> v;
        Node* temp=head,*x;
        while(!v.empty() || temp!=nullptr){
            if(temp==nullptr){
                temp=v.back();
                v.pop_back();
                temp->prev=x;
                x->next=temp;
            }
            if(temp->child!=nullptr){
                if(temp->next)  v.push_back(temp->next); //v imp to look at edge cases
                temp->next=temp->child;
                temp->child=nullptr;
                temp->next->prev=temp;
            }
            x=temp;
            temp=temp->next;
        }
        return head;
    }
};