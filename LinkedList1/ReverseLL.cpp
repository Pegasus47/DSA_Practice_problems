#include <iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            ListNode* old = prev;
            prev = temp;
            temp = temp->next;
            prev->next = old;
        }
        return prev;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to create a linked list from an array
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}

// int size=0,dup=k;
// while(temp!=nullptr){
//     temp=temp->next;
//     size++;
// }
// cout<<size<<endl;
// size/=k;
// for(int i=0;i<size;i++){
//     k=dup;
//     temp=prev->next;
//     while(k>0){
//         ListNode* old=prev;
//         prev=temp;
//         temp=temp->next;
//         prev->next=old;
//         k--;
//     }
//     cout << head->val << " " << temp->val;
//     head->next=temp;
// }