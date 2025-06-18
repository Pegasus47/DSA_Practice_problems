#include <iostream>
#include <vector>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy= new ListNode(); //use a dummy/sentinel node (makes lyf easier)
        ListNode* f=list1,*s=list2,*tail=dummy;
        while(f!=nullptr && s!=nullptr){ //NOTE: Remember the && and not the ||
            if(f->val <= s->val){
                tail->next=f;
                f=f->next;
            }else{
                tail->next=s;
                s=s->next;
            }
            tail=tail->next; //whatever is done in both if-else, get it outside
        }
        if(f!=nullptr)
            tail->next=f; //connect the remaining if any left
        else if(s!=nullptr)
            tail->next=s;

        return dummy->next; //this would be the head
    }
};
// Helper function to create a linked list from a vector
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

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 4};
    vector<int> nums2 = {1, 3, 4};

    ListNode* list1 = createList(nums1);
    ListNode* list2 = createList(nums2);
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged list: ";
    printList(merged);

    return 0;
}
