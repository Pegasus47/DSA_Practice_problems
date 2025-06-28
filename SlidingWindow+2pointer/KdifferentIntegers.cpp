#include<bits/stdc++.h>
using namespace std;

//This is similar to all the other 2 pointers where you have to COUNT the no of subarrays
//remember this approach

class Solution {
public:
    int lessThanOrEqual(vector<int>& nums,int k){
        unordered_map<int,int> um;
        int r=0,l=0,cnt=0;
        while(r<nums.size()){
            um[nums[r]]++;
            while(um.size()>k){
                um[nums[l]]--;
                if(um[nums[l]]==0)
                    um.erase(nums[l]);
                l++;
            }
            //always AFTER the removing walla loop
            //warna after removing you are left with a valid subarray which you wont be checking
            //at the last iteration
            if(um.size()<=k){
                cnt+=(r-l+1);
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a=lessThanOrEqual(nums,k);
        int b=lessThanOrEqual(nums,k-1);
        return a-b;
    }
};
int main() {
    Solution s;
    vector<int> v={1,2,1,2,3};
    int k=2;
    cout << s.subarraysWithKDistinct(v,k);
}

