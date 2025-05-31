#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=max(nums[i],sum+nums[i]);
            m=max(m,sum);
        }
        return m; //if they ask you to include an empty subarray
        // return (m>0?m:0);
    }
};

int main() {
    Solution s;
    vector<int> v={5,4,-1,7,8};
    cout << "MAX: " << s.maxSubArray(v);
}