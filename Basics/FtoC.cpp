#include <iostream>
using namespace std;

int main() {
    float F,C;
    cout<<"Enter Fahrenheit: ";
    cin>>F;
    C = (5.0 / 9.0) * (F - 32);
    cout << "Celsius is: " << C << endl;
    return 0;
}

