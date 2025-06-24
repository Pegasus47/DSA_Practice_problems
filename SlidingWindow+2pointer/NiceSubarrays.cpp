#include<iostream>
#include<vector>
using namespace std;

//same principle as binarysum
//REVISE LATER

class Solution {
public:
    int lessOrEqual(vector<int>& nums,int k){
        int l=0,r=0,cnt=0,ans=0;
        while(r<nums.size()){
            if(nums[r]%2==1)
                cnt++;
            while(cnt>k){
                if(nums[l]%2==1)
                    cnt--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=lessOrEqual(nums,k);
        int b=lessOrEqual(nums,k-1);
        return a-b;
    }
};

int main() {
    Solution s;
    vector<int> v={1,1,2,2,1,1,2};
    int k=3;
    cout << s.numberOfSubarrays(v,k);
}