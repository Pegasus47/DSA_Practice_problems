#include<iostream>
#include<vector>
using namespace std;

//This is the optimal solution with no extra space
//Lmax and Rmax is maintained and water above each block is calculated
//NOTE: The smaller of the two is moved forward and if both are the same, in this case, right is moved back
//PLS REVISE

class Solution {
public:
    int trap(vector<int>& height) {
        int temp,l=0,r=height.size()-1,lmax=0,rmax=0,ans=0;
        while(l<r){
            temp=0; //not really needed, just remove the +=
            if(lmax>height[l] && rmax>height[l]){
                temp+=min(lmax,rmax)-height[l];
            }
            else if(lmax>height[r] && rmax>height[r]){
                temp+=min(lmax,rmax)-height[r];
            }

            lmax=max(lmax,height[l]); //update the max from both the sides
            rmax=max(rmax,height[r]);

            if(height[r]>height[l]) //move the smaller pointer as it is the blocking factor
                l++;
            else
                r--;
            ans+=temp;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(v);
}
