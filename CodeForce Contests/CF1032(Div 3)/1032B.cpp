#include<iostream>
#include<string>
using namespace std;

void aboveTheClouds(int size,string s) {
    bool f;
    for (int i=1;i<s.length()-1;i++) {
        string a,b,c;
        a=s.substr(0,i);
        b=s[i];
        c=s.substr(i+1);
        string com=a+c;

        if (com.find(b)!=string::npos) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int main() {
    int nos;
    cin >> nos;
    for (int i=0;i<nos;i++) {
        int size;
        string s;
        cin >> size;
        cin >> s;
        aboveTheClouds(size,s);
    }
}