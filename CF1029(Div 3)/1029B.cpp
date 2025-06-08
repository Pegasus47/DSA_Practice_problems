#include <iostream>
#include <vector>
using namespace std;

void Shrink(int p) {
    int i=1;
    while (i<=p) {
        cout << i << " ";
        i+=2;
    }
    i=(p%2==0?p:p-1);
    while (i>0) {
        cout << i <<" ";
        i-=2;
    }
}

int main() {
    int no;
    cin >> no;
    for (int i=0;i<no;i++) {
        int p;
        cin >> p;
        Shrink(p);
        cout << endl;
    }
    return 0;
}
//the below simulates v.push_front which dont exist for vectors
//myVector.insert(myVector.begin(), 0); // Inserts 0 at the beginning


//makes vector of n+1 size and initialises stuff to 0
//vector<char> seen(n+1, 0);
