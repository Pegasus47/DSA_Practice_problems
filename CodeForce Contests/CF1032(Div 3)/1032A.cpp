#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void letterhome(int size,int pos,vector<int> v) {
    if (pos>v[0] && pos<v[v.size()-1]) {
        int c=min(pos-v[0],v[v.size()-1]-pos);
        int f=max(pos-v[0],v[v.size()-1]-pos);
        int ans=2*c+f;
        cout << ans << endl;
    }else {
       if (pos<=v[0]) cout << v[v.size()-1]-pos << endl;
       else cout << pos-v[0] <<endl;
    }
}

int main() {
    int nos;
    cin >> nos;
    for (int i=0;i<nos;i++) {
        int size,pos;
        cin >> size >> pos;
        vector<int> v;
        for (int j=0;j<size;j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }
        letterhome(size,pos,v);
    }
    return 0;
}