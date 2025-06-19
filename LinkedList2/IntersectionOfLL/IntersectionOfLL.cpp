//brute would be to check every node in m for every node in n
//this is optimised TIME
//THIS IS THE NON OPTIMAL WAY
//TC: O(n+m) SC:O(n+m)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> A;
        vector<ListNode*> B;
        ListNode* temp=headA;
        while(temp!=nullptr){
            A.push_back(temp);
            cout << temp->val << " ";
            temp=temp->next;
        }
        temp=headB;
        cout << endl;
        while(temp!=nullptr){
            B.push_back(temp);
            cout << temp->val << " ";
            temp=temp->next;
        }
        bool b=false;
        while(!A.empty() && !B.empty()){
            if(A.back()!=B.back()){
                b=true;
                return temp;
            }
            temp=A.back();
            A.pop_back();
            B.pop_back();
        }
        if(b==false)
            return temp;
        return nullptr;
    }
};