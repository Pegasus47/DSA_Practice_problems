#include<iostream>
#include<vector>
using namespace std;

//Note that this problem can also be reframed as 'Longest Subarray with max k zeros'
//Brute Force Solution is to just go through each subarray to check which can be acceptable
//TC=O(n²) SC=O(1)
//OPTIMISED SOLN- Keep L and R pointers such that there are a max of K zeros b/w them
//Move R if there are less or equal to K zeros and move L otherwise
//TC:O(2n) SC:O(1)


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,l=0,r=0,z=0;
        while(r<nums.size()){
            if(nums[r]==0)
                z++;
            while(z>k){
                if(nums[l]==0)
                    z--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

//Below is a slightly better optimised soln
//it follows the intuition that if ans is 5, there is no need to decrease ans by getting l closer
//instead just move both l and r together till zeros are less than k
//IMP: Keep in check when you are able to update the (max) -->if condition

// while(r<nums.size()){
//     if(nums[r]==0)
//         z++;
//     if(z>k){
//         if(nums[l]==0)
//             z--;
//         l++;
//     }
//     if(z<=k)
//         ans=max(ans,r-l+1);
//     r++;
// }

int main() {
    Solution s;
    vector<int> v={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    cout << s.longestOnes(v,k);
}