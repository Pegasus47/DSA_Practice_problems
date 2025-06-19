#include <iostream>
#include <vector>
using namespace std;

/*
    This code checks if a singly linked list is a palindrome.

    Approach:
    1. Use two pointers (slow and fast) to find the middle of the list.
    2. Reverse the second half of the list.
    3. Compare the first half and the reversed second half node by node.
    4. If all values match, it's a palindrome; otherwise, it's not.

    Time Complexity: O(n)
    Space Complexity: O(1) (in-place reversal)
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Helper function to reverse a linked list
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

    // Main function to check if a list is a palindrome
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;

        // Step 1: Find middle
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Step 2: Adjust slow pointer for odd-length lists
        if (fast != nullptr && fast->next == nullptr)
            slow = slow->next;

        // Step 3: Reverse second half
        slow = reverseList(slow);

        // Step 4: Compare both halves
        ListNode* temp = head;
        while (slow != nullptr) {
            if (temp->val != slow->val)
                return false;
            temp = temp->next;
            slow = slow->next;
        }
        return true;
    }
};

// Helper function to create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* tail = head;
    for (int i = 1; i < vals.size(); i++) {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

// Main function for testing
int main() {
    vector<int> values = {1, 2, 3, 2, 1}; // Change this to test other cases
    ListNode* head = createList(values);

    Solution sol;
    bool result = sol.isPalindrome(head);

    if (result)
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is not a palindrome." << endl;

    return 0;
}
