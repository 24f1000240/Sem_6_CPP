#include <iostream>
using namespace std;

int main() {
    cout << "Enter a b c" << "\n";

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    double avg = (a + b + c) / 3.0;
    cout << "Average is: " << avg << endl;

    return 0;
}

