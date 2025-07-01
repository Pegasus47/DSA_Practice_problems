#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<int>& piles, int h,int k){
        long long int sum=0;
        for(int i : piles){
            sum+=ceil(i/(double)k);
        }

        return sum<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,mid,high=*(max_element(piles.begin(),piles.end()));
        int k=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(helper(piles,h,mid)){
                k=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return k;
    }
};

