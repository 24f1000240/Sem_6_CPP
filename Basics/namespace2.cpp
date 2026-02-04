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
using namespace greet1;
int main() {
    welcome();
    return 0;
}
