#include <iostream>
#include <vector>
using namespace std;

bool Doors(vector<int>& v,int n,int x) {
    int i=0;
    while (i<n && v[i]==0) {
        //cout << v[i] << " ";
        i++;
    }

    while (x>0 && i<n) {
        //cout << v[i] << " ";
        i++;
        x--;
    }
    while (i<n && v[i]==0) {
        //cout << v[i] << " ";
        i++;
    }

    //cout << "(" << i <<":" << n << ") ";
    if (i==n)
        return true;

    return false;
}

int main() {
    int no;
    cin >> no;
    for (int i=0;i<no;i++) {
        int n,x,temp;
        cin >> n >> x;
        vector<int> v;
        for (int j=0;j<n;j++) {
            cin >>temp;
            v.push_back(temp);
        }
        cout <<(Doors(v,n,x)?"YES":"NO") << endl;
    }
    return 0;
}

// vector<int> v;
// for (int j=0;j<n;j++) {
//     cin >> temp;
//     v.push_back(temp);
// }
// You can simplify:
// vector<int> v(n);
// for (int& val : v) cin >> val;