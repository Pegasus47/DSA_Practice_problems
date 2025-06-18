#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        int temp;
        node->val=node->next->val;
        node->next=node->next->next;
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

ListNode* createList(const vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : nums) {
        if (!head) {
            head = new ListNode(num);
            tail = head;
        } else {
            tail->next = new ListNode(num);
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    Solution s;
    vector<int> v={4,5,1,9};
    ListNode* head=createList(v);
    cout << "Original List: ";
    printList(head);
    s.deleteNode(head->next);
    cout << "After Deletion: ";
    printList(head);
    return 0;
}