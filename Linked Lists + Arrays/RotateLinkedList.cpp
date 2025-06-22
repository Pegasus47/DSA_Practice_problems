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
    ListNode* rotateRight(ListNode* head, int k) {
        //base case PLSS
        if(head==nullptr)   return head;
        ListNode* temp=head,*prev;
        int size=1;
        while(temp->next!=nullptr){
            temp=temp->next;
            size++;
        }
        cout << size;
        k=k%size;
        temp->next=head;
        temp=head;
        k=size-k; //ALWAYS dry run multiple test cases pls lil bro
        while(k>0){
            prev=temp;
            temp=temp->next;
            k--;
        }
        prev->next=nullptr;
        return temp;
    }
};