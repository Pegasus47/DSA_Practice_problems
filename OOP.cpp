#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int salary;
public: //cons always have to be public
    Employee():name(""),salary(0) {
        cout << "default" <<endl;
    } //default cont -->no parameters
    Employee(string n, int s) : name(n), salary(s) { //this is list initialization
        cout<< "Parametrized"<<endl;
    }
    Employee(const Employee& e) {
        cout << "Copy" <<endl;
        name=e.name;
        salary=e.salary;
    }
};

int main() {
    Employee e1; //default is called //stored on stack //no pointer here
    Employee e2("neha",100);
    return 0;
}