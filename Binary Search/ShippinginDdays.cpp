#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(vector<int>& weights,int days,int k){
        int cnt=0,ptr=0,time=0;
        while(ptr<weights.size()){
            if(cnt+weights[ptr]>k){
                time++;
                cnt=0;
            }
            cnt+=weights[ptr];
            ptr++;
        }
        if(cnt>0) time++;
        return time<=days;
    } 
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),mid; //note to use*
        int high=accumulate(weights.begin(),weights.end(),0); //accumulate is kinda sexy
        int ans=0;
        while(low<=high){
            mid=low+(high-low)/2; 
            if(helper(weights,days,mid)){
                ans=mid; 
                high=mid-1; 
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};