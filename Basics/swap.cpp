#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int main(){
    int m = 5, n = 10;
    swap(m, n);
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    return 0;
}

