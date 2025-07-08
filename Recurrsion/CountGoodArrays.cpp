#include<bits/stdc++.h>
using namespace std;

// the answer is 5^(n/2)+1 * 4^(n/2) if n is odd and
// 5^(n/2) * 4^(n/2) if n is even
// we know the we can calculate exponents in log(n)
//so just call the function twice for 5,4
//NOTE: the mod func is IMPORTANT
class Solution {
public:
    //this is an important property while dealing with such stuff
    //(a×b)modm=[(amodm)×(bmodm)]modm
    long long expo(long long base, long long pow){
        long long ans=1;
        long long mod=1e9+7;
        while(pow > 0){
            if(pow%2==0){
                base=(base*base)%mod;
                pow=pow/2;
            }
            else{
                ans=(ans*base)%mod;
                pow--;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long e=(n+1)/2;
        long long o=n/2;
        long long mod=1e9+7;
        return (int)((expo(5,e)*expo(4,o))%mod);
    }
};

int main() {
    Solution s;
    long long n=50;
    cout << s.countGoodNumbers(n);
}