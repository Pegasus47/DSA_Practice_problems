#include<iostream>
#include<vector>
using namespace std;

//BRUTE: Count all subarrays and check their sum
//SIDENOTE: A subarray is contigious while a subsequence might not be
//TC: O(n²) and SC: O(1)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum,ans=0;
        for(int i=0;i<nums.size();i++){ //NOTE: all subarrays can be iterated over in O(n²) TC
            sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k)
                    ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={1,2,3,-3,1,1,1,4,2,-3};
    int target=3;
    cout << s.subarraySum(v,target) << endl;
    return 0;
}
