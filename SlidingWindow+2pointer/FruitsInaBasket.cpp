#include<iostream>
#include<map> //STL uses RBT to implement this so logn TC for most operations
#include<vector>
using namespace std;


//problem can be converted into 'Longest subarray with max 2 different elements'
//This is the most optimal way to solve with O(n) time and O(1) space
//the slightly unoptimal way is to move the left pointer till the map is valid and then continue
//it takes worst case O(2n) which is mostly fine (give this as the first answer)
//BRUTE is obv- take all subarrays and make sure there are less than 2 different elements within them
//implement brute with a set and not variables

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp; //use a map and not 2 elements
        //key is the element being stored and the value is the frequency of the element
        //intuition to use map is that you need a freq cntr and values so easier
        int l=0,r=0,ans=0;
        //you could technically  use 2 variables and then while moving left pointer
        //towards the right, you could reduce the count of that variable
        //and when one of the variable counts is 0, set the r variable to l
        //and set the new variable to the r one
        //TRY THIS FOR PRACTISE LATER

        while(r<fruits.size()){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2)
                ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v={1,2,3,4,3,2,3,4,3,1,1,4,3,1};
    cout << s.totalFruit(v);
}
