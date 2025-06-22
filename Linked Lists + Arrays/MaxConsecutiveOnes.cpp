#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cntr=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                cntr++;
            else
                cntr=0;
            ans=max(ans,cntr);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(v);
    
}