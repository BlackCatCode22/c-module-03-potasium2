#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;

    cout << "Address  of a: " << p << endl;
    cout << "Value of a: " << *p;

    return 0;
}