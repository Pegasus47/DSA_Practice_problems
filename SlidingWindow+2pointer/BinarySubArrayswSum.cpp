#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//Brute is to generate all the subarrays and check each one
//Better than that is to do the solution hidden in the comments below
//prefix sum and put it in hashmap similar to 'SubArray Sum Equal K'
//OPTIMAL: If we can find everything <= 2 and then find everything <= 1
//and subtract it, we will get == 2

//NOTE: Revise this

//Whenever you arent sure about how to proceed with left or right, remember this approach
class Solution {
public:
    int lessOrEqualSubArray(vector<int>& nums,int goal){ //this solves <=
        if(goal<0)
            return 0;
        int l=0,r=0,sum=0,cntr=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            cntr+=(r-l+1); //this calculates all the subarrays of that element
            //till l, coz all of them are technically possible
            //ALWAYS LET THE checking be after moving the second pointer so that the r=nums.size() case
            //is considered
            r++;
        }
        return cntr;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=lessOrEqualSubArray(nums,goal);
        int b=lessOrEqualSubArray(nums,goal-1);
        return a-b;
    }
};

int main() {
    Solution s;
    vector<int> nums={1,0,1,0,1};
    int goal=2;
    cout << s.numSubarraysWithSum(nums,goal);
}


// int numSubarraysWithSum(vector<int>& nums, int goal) {
//     int ans=0,rsum=0,l=0,r=0;
//     unordered_map<int,int> um;
//     um.insert({0,1});
//     for(int i=0;i<nums.size();i++){
//         rsum=rsum+nums[i];
//         int comp=rsum-goal;
//         if(um.find(comp)!=um.end()){
//             ans+=um[comp];
//         }
//         um[rsum]++;
//     }
//     return ans;
// }
