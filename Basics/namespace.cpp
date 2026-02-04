#include <iostream>
using namespace std;
namespace greet1 {
    void welcome() {
        cout << "Welcome to Namespace one" << endl;
    }
}
namespace greet2 {
    void welcome() {
        cout << "Welcome to Namespace two" << endl;
    }
}
int main() {
    greet1::welcome();
    greet2::welcome();
    return 0;
}
