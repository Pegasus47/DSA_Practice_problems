#include<bits/stdc++.h>
using namespace std;


int main() {
    int no;
    cin >> no;
    int temp;
    for (int i=0;i<no;i++) {
        cin >> temp;
        if (temp%2==0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}