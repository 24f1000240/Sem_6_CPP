#include<iostream>
using namespace std;
class Integer {
    int m, n;
public:
    Integer(int x){
        m = x;
        n = 0;
    }
    Integer(int x, int y){
        m = x;
        n = y;
    }
    void display() {
        cout << "m = " << m << "\n";
        cout << "n = " << n << "\n";
    }
};
int main() {
    Integer obj1(50);
    Integer obj2(25, 75);
    cout << "\nOBJECT 1\n";
    obj1.display();
    cout << "\nOBJECT 2\n";
    obj2.display();

    return 0;
}
