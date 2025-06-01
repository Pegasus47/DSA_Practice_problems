//You have to find the best dates to buy and sell stocks
//SC=>O(1) 
//TC=>O(n)
#include <iostream>
#include <climits>
#include <vector>
using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int max_diff=0;
        for(int i=0;i<prices.size();i++){
            if(buy>prices[i]){
                buy=min(buy,prices[i]);
                continue;
            } //this will make sure that the minimum is always before the max
            max_diff=max(max_diff,prices[i]-buy);
        }
        return max_diff;
    }
};

int main(){
    Solution s; 
    vector<int> v={7,1,5,3,6,4};
    cout << s.maxProfit(v);
}
