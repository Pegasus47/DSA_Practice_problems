#include <iostream>
#include <vector>
using namespace std;

//MORE OPTIMAL SOLUTION: maintain 2 pointers with a delay of k between them
//TC:O(2*n)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* runner = head;

        // Step 1: Find size
        while (runner != nullptr) {
            size++;
            runner = runner->next;
        }

        // Step 2: Find position from beginning
        int cntr = size - n;
        ListNode* prev = nullptr;
        runner = head;

        // Step 3: Traverse to that node
        for (int i = 0; i < cntr; i++) {
            prev = runner;
            runner = runner->next;
        }

        // Step 4: Delete node
        if (prev == nullptr) {
            // Removing head
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        if (runner != nullptr) {
            prev->next = runner->next;
            delete runner;
        }

        return head;
    }
};

// Helper to create a list from vector
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

// Helper to print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 2;

    ListNode* head = createList(nums);
    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.removeNthFromEnd(head, n);

    cout << "After removing " << n << "th node from end: ";
    printList(head);

    return 0;
}
