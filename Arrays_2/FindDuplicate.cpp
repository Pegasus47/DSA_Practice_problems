#include <iostream>
#include <vector>
using namespace std;

//BRUTE: Check for every element if duplicate exists
//TC=O(n²) SC=O(1)
//BETTER 1: Sort and check if 2 consecutive numbers are same
//TC=O(n*logn) SC=O(1/n) --> depending on sorting method
//BETTER 2: Use a hashmap with keys as [1,n] and values as no of occurences
//TC=O(n) SC=O(n)
//OPTIMISED: Floyd's fast and slow pointers
//TC=O(n) SC=O(1)

//NOTE: See proof of Floyd's fast and slow pointers later while revising

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow]; //move to the index pointed out by the number
            fast=nums[nums[fast]]; //move 2 steps
        }while(slow!=fast); //you need a do while as the first
        //comparison should be made only after both have moved a step

        fast=nums[0]; //second loop both move at same speed fast starting from 0
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution s;
    vector<int> arr={1,3,4,2,2};
    cout << s.findDuplicate(arr);
}

