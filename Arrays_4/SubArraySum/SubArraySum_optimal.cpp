#include<iostream>
#include<vector>
#include<map>
using namespace std;

//OPTIMAL: Here we make a map with key as prefix and value as no of times it occurs
//PLEASE REVISIT LATER

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int comp,ans=0,prefix=0;
        map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            comp=prefix-k;
            ans+=mp[comp];
            mp[prefix]++;
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
