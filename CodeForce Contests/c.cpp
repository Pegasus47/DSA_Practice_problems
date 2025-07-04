#include<bits/stdc++.h>
using namespace std;

void presuf() {
    int size,temp,mx=INT_MIN,mxx,mn=INT_MAX,mnn;
    cin >> size;
    vector<int> v(size),pre(size),suf(size);
    for (int i=0;i<size;i++) {
        cin >> temp;
        v[i]=temp;
    }
    pre[0]=v[0];
    for (int i=1;i<size;i++) {
        pre[i]=min(pre[i-1],v[i]);
    }
    suf[size-1]=v[size-1];
    for (int i=size-2;i>=0;i--) {
        suf[i]=max(suf[i+1],v[i]);
    }
    for (int i= 0;i<size;i++) {
        if (v[i]==pre[i] || v[i]==suf[i])
            cout << "1";
        else
            cout << "0";
    }
}


int main() {
    int no;
    cin >> no;
    for (int i=0;i<no;i++) {
        presuf();
        cout << endl;
    }
}