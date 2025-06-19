#include <iostream>
#include <vector>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* Solution class with reverseKGroup function */
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

//NOTE: This is the optimal solution but is written in not the best way soo pls take this lite later

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* temp=head,*prev=nullptr,*old,*headm=dummy;
        int size=0,dup=k;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        cout<<size<<endl;
        temp=head;
        head=dummy;
        size=size/k;
        for(int i=0;i<size;i++){
            k=dup;
            headm=head;
            head=head->next;
            prev=nullptr;
            while(k>0){
                old=prev;
                prev=temp;
                temp=temp->next;
                prev->next=old;

                k--;
            }
            head->next=temp;
            headm->next=prev;
            //cout << prev->val << temp->val << old->val ;
        }
        return dummy->next;
    }
};

/* Helper to create a linked list from vector */
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    for (int i = 1; i < vals.size(); ++i) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

/* Helper to print a linked list */
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* Main function to test */
int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    int k = 3;

    ListNode* head = createList(values);
    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(newHead);

    return 0;
}
