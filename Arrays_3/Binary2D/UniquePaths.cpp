#include <iostream> //cannot use include<bits/stdc++> as it is
#include <vector> //spcific to the GNU GCC complier and CLion uses Clang
using namespace std;
//NOTE: Revisit when DP

//BRUTE: The brute force solution is DP. Make table and count all possibilities
//TC: O(n+m) SC: O(n+m)
//OPTIMIAL: Based on Math
//No of ways=(total steps)!/((right steps)!*(down steps)!)
//TC: O(min{n,m}) SC:O(1)
//OR you could choose how to arrange right and down steps wrt to total steps
//No of ways=(m+n-2)C(n-1) or (m+n-2)C(m-1)
//TC: O(n-1) or O(m-1) SC:O(1)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int total=m+n-2;
        if(total<1) //base
            return 1;
        long double res=1;
        long double bot=1; //doesnt need to be long but uk
        int hi=max(m,n)-1;
        int low=min(m,n)-1;
        while(total>hi){ //this is running low no of times basically
            res=res*total;
            total--;
            if(low>0){
                bot=bot*low;
                low--;
            }
        }
        res =  res/bot;
        return (int)res; //typecast before returning
    }
};

int main() {
    Solution s;
    int m=7,n=3;
    cout << s.uniquePaths(m,n) << endl;
    return 0;
}
