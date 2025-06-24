#include<bits/stdc++.h>
using namespace std;
//classic sliding window problem
//notice that whenever you are asked max score or something in an array, it is sliding window
//in this case the window starts and ends at the last

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0,ans=0,r=k-1,l=k-1;
        while(l>=0){
            sum+=cardPoints[l];
            l--;
        }
        ans=sum;
        l=cardPoints.size()-1;
        while(r>=0){
            sum-=cardPoints[r];
            r--;
            sum+=cardPoints[l];
            l--;
            ans=max(ans,sum);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={7,1,3,4,5,6,1};
    int k=3;
    cout << s.maxScore(v,k);
}