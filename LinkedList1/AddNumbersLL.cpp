#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        int carry=0,val;
        while(l1!=nullptr && l2!=nullptr){
            val=l1->val+l2->val+carry;
            carry=0;
            if(val>9){
                carry++;
                val=val-10;
            }
            ListNode* l = new ListNode(val);
            tail->next=l;
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;
        }
        ListNode* rem=nullptr;
        if(l1!=nullptr)
            rem=l1;
        else if(l2!=nullptr)
            rem=l2;
        while(rem!=nullptr){
            val=rem->val+carry;
            carry=0;
            if(val>9){
                carry++;
                val=val-10;
            }
            ListNode* l = new ListNode(val);
            tail->next=l;
            tail=tail->next;
            rem=rem->next;
        }
        if(carry==1){
            ListNode* l = new ListNode(1);
            tail->next=l;
            tail=tail->next;
        }

        return dummy->next;
    }
};

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

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    vector<int> l1={2,4,3};
    vector<int> l2={5,6,4};
    ListNode* L=createList(l1);
    ListNode* LL=createList(l2);
    cout << "First Number : ";
    printList(L);
    cout << "Second Number : ";
    printList(LL);
    cout << "Added: ";
    ListNode* add=s.addTwoNumbers(L,LL);
    printList(add);

}