#include <bits/stdc++.h>
using namespace std;

//for every element we have to find the index of the next smaller element and prev smaller element
//now the number of total subarrays will be (i-prev)*(next-i)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse(arr.size()), nse(arr.size());
        stack<int> prev,next; //can do with 1 stack also
        for(int i=0;i<arr.size();i++){
            while(!prev.empty() && arr[i]<arr[prev.top()]){ //since we are storing the indicies, make sure to check them
                //no <= as we are handling that case in the other
                prev.pop();
            }
            if(prev.empty())
                pse[i]=-1; //if not store -1
            else 
                pse[i]=prev.top();
            prev.push(i);
        }
        for(int i=arr.size()-1;i>=0;i--){
            while(!next.empty() && arr[i]<=arr[next.top()]){ //handle the duplicates case only 1 time
                next.pop();
            }
            if(next.empty())
                nse[i]=arr.size(); //here this as assume the next smallest is out of the array
            else 
                nse[i]=next.top();
            next.push(i); //dont forget to push
        }
        long long sum=0;
        long long MOD=1e9+7; //use this as MOD
        for(int i=0;i<arr.size();i++){
            long long l=i-pse[i];
            long long r=nse[i]-i; 

            sum = (sum + (((arr[i] * l) % MOD) * r) % MOD) % MOD;
        }
        return sum;
    }
};