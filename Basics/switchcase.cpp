#include <iostream>
using namespace std;
enum shape
{
    circle,
    rectangle,
    triangle
};
int main()
{
    cout << "Enter shape code: ";
    int code;
    cin >> code;
    while (code >= circle && code <= triangle)
    {
        switch (code)
        {
            case circle:
                cout << "Circle selected" << endl;
                break;

            case rectangle:
                cout << "Rectangle selected" << endl;
                break;

            case triangle:
                cout << "Triangle selected" << endl;
                break;
            default:
            	cout << "Invalid entry. \n";
        }
        break;
    }
    return 0;
}
