#include <bits/stdc++.h>
using namespace std;

void aboveTheClouds(int size,string s) {
    array<int,26> freq={0};
    for (char c: s)
        freq[c-'a']++;
    for (int i=1;i<size-1;i++) {
        if (freq[s[i]-'a']>1) {
            cout << "YES" <<endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int nos;
    cin >> nos;
    for (int i=0;i<nos;i++) {
        int size;
        string s;
        cin >> size >> s;
        aboveTheClouds(size,s);
    }
}
