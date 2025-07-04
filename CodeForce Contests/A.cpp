#include<bits/stdc++.h>
using namespace std;

int main() {
    int no;
    cin >> no;
    for (int i=0;i<no;i++) {
        int n;
        cin >> n;
        if (n%4==0)
            cout << "Bob"<<endl;
        else
            cout << "Alice"<<endl;
    }
}
