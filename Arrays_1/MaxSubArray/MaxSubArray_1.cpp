#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int m=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum=sum+nums[j];
                m=max(m,sum); //use another array instead of MAX function for worst case
            }
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<int> v={5,4,-1,7,8};
    cout << "MAX: " << s.maxSubArray(v);
}