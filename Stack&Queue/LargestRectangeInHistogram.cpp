#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> p,n;
        vector<int> nse(heights.size());
        vector<int> pse(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            while(!n.empty() && heights[n.top()]>heights[i]){
                n.pop();
            }
            if(n.empty())
                nse[i]=heights.size();
            else
                nse[i]=n.top();

            n.push(i);
        }
        for(int i=0;i<heights.size();i++){
            while(!p.empty() && heights[p.top()]>=heights[i]){ //dicover >= pls
                p.pop();
            }
            if(p.empty())
                pse[i]=-1;
            else
                pse[i]=p.top();
            p.push(i);
        }
        int large=0;
        for(int i=0;i<heights.size();i++){
            int wide=nse[i]-pse[i]-1;
            int area=wide*heights[i];
            large=max(large,area);
        }
        return large;
    }
};