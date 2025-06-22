#include<iostream>
#include<vector>
using namespace std;

//This is the optimised brute approach
//BRUTE of this is to find the element STRICTLY greater to current element to its left and right
//It will be TC=O(n²) and SC=O(1)
//You could reduce the SC from 2n to n by calculating prefixMax on the fly
//TC is already optimised but the space is not

class Solution {
public:
    int trap(vector<int>& height) {
        int temp,ans=0;
        vector<int> prefixMax(height.size()),suffixMax(height.size()); //defines the size

        //Below is to calculate the prefix MAX
        prefixMax[0]=height[0];
        for(int i=1;i<height.size();i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
        }

        //Below is to calculate the suffix MAX
        suffixMax[height.size()-1]=height.back();
        for(int i=height.size()-2;i>-1;i--){
            suffixMax[i]=max(height[i],suffixMax[i+1]);
        }

        //This for loop checks if the element is strictly smaller and sums up water on top of each block
        for(int i=0;i<height.size();i++){
            if(height[i]<prefixMax[i] && height[i]<suffixMax[i]){
                temp=min(prefixMax[i],suffixMax[i])-height[i];
                ans+=temp;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(v);
}
