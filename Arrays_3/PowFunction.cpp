#include <iostream>
using namespace std;

//BRUTE: Iterate from 1 to n and keep multipling
//TC=O(n)

//OPTIMISED: If n is even--> x=x*x and if n is odd-->ans*x
//TC=O(log(n))

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1)
            return 1;
        if(x==-1)
            return (n%2==0?1:-1); //edge cases
        double ans=1;
        double sq=x*x;
        long long int nn=n;
        if(n<0){
            nn=1LL*-1*(long)(n);
        }

        while(nn>0){
            if(nn%2==0){
                x=x*x;
                nn=nn/2;
            }
            else{
                ans=ans*x;
                nn--;
            }
        }
        if(n<0)
            ans=1.0/ans;

        return ans;
    }
};

int main() {
    Solution s;
    int x=23,n=3;
    cout << s.myPow(x,n);
    return 0;
}