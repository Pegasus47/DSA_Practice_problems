#include <iostream>
#include <vector>
using namespace std;
// Brute: Check for every element if it occurs n/2 times or more
//TC: O(n²) SC: O(1)
// Better: Make a hashmap with every element being the key and value being no of occurence
//TC: O(n) SC: O(n)
// Optimal: Boyer–Moore majority vote algorithm
//TC: O(n) SC:O(1)

//Note: If there exists no majority element, this will still give you a wrong candidate

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m,cntr=0;
        for(int i=0;i<nums.size();i++){
            if(cntr==0){
                m=nums[i];
            }
            if(nums[i]==m)
                cntr++;
            else
                cntr--;
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<int> v= {2,3,3,4,5,6,3,3,3};
    cout << s.majorityElement(v);
}