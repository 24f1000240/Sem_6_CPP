#include <iostream>
using namespace std;
class temp {
private:
    float F, C;
public:
    void getFahrenheit() {
        cout << "Enter Fahrenheit: ";
        cin >> F;
    }
    void convertToCelsius() {
        C=((5.0 / 9.0)*(F - 32));
    }
    void display() {
        cout<<"Celsius is: "<< C << endl;
    }
};
int main() {
    temp t;
    t.getFahrenheit();
    t.convertToCelsius();
    t.display();
    return 0;
}

