#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        stack<int> ts;
        vector<int> pse(nums.size());
        vector<int> pge(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!ts.empty() && nums[ts.top()]<nums[i]){
                ts.pop();
            }
            if(ts.empty())
                pge[i]=-1;
            else
                pge[i]=ts.top();
            ts.push(i);
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty())
                pse[i]=-1;
            else
                pse[i]=st.top();

            st.push(i);
        }
        while(!st.empty()) //cleaning up stacks takes time
            st.pop();
        while(!ts.empty()) //just use new stacks
            ts.pop();
        vector<int> nge(nums.size());
        vector<int> nse(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!ts.empty() && nums[ts.top()]<=nums[i]){ // <= only once to allow
                // duplicates from only 1 side
                ts.pop();
            }
            if(ts.empty())
                nge[i]=nums.size();
            else
                nge[i]=ts.top();
            ts.push(i);
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty())
                nse[i]=nums.size();
            else
                nse[i]=st.top();

            st.push(i);
        }
        long long mn=0,mx=0,sum=0;
        for(int i=0;i<nums.size();i++){
            mn=mn+(1LL*(i-pse[i])*(nse[i]-i)*nums[i]); // 1LL*everything else
            mx=mx+(1LL*(i-pge[i])*(nge[i]-i)*nums[i]); //either else it overflow then 1LL
        }
        sum=mx-mn;
        return sum;
    }
};

