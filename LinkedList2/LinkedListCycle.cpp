#include <iostream>
#include <vector>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        if(head==nullptr || head->next==nullptr) return false;
        do{
            fast=fast->next->next;
            slow=slow->next;
        }while(fast!=slow && fast!=nullptr && fast->next!=nullptr);
        if(fast==nullptr || fast->next==nullptr)
            return false;
        else
            return true;
    }
};

// Utility to create a list with optional cycle
ListNode* createLinkedListWithCycle(const vector<int>& vals, int pos) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    ListNode* cycleNode = nullptr;

    if (pos == 0) cycleNode = head;

    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
        if (i == pos) cycleNode = tail;
    }

    if (pos != -1) {
        tail->next = cycleNode; // create the cycle
    }

    return head;
}

int main() {
    Solution sol;

    // Create a list: 3 -> 2 -> 0 -> -4 and a cycle starting at node 2 (index 1)
    vector<int> vals = {3, 2, 0, -4};
    int pos = 1; // cycle starts at node with value 2

    ListNode* head = createLinkedListWithCycle(vals, pos);

    if (sol.hasCycle(head))
        cout << "Cycle detected!" << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
