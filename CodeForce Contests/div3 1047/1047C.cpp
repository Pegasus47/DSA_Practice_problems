#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
     cin >> t;
    while (t--) {
        long long a,b;
        cin >> a >> b;
        if (a%2==0 && b%2==1) {
            cout << -1 << endl;
        }
        else if (a%2==1 && b%2==0 && b%4!=0) {
            cout << -1 << endl;
        }
        else {
            if (b%2==1) {
                cout << a*b+1 << endl;
            }
            else if (b%2==0 && a%2==0){
                long long temp=b/2;
                b=2;
                cout << max(a,b)*temp+min(a,b) << endl;
            }
            else {
                int temp=b/4;
                b=2;
                a=a*2;
                cout << a*temp+b << endl;
            }
        }
    }
}
