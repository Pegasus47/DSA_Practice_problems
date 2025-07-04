#include<bits/stdc++.h>
using namespace std;

int main() {
    int no;
    cin >> no;
    for (int i=0;i<no;i++) {
        int temp,n,x,k;
        vector<int> v;
        cin >> n >> x >> k;
        for (int j=0;j<n;j++) {
            cin >> temp;
            v.push_back(temp);
        }
        int max_elem=*max_element(v.begin(),v.end());
        if (k>1 || v[x-1]==max_elem)
            cout<<"YES"<<endl;
        else
            cout << "NO" << endl;
    }
}