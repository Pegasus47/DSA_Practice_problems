#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int temp;
        for (int i=1;i<=n;i++){
            cin >> temp;
            cout << n+1-temp << " ";
        }
        cout  << endl;
    }
    return 0;
}