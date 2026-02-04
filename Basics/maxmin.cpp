#include<iostream>
using namespace std;
int& max(int &x, int &y){
	if(x>y)
		return x;
	else
		return y;
}
int main(){
	int a,b;
	cout << "Enter the value of a and b: " << "\n";
	cin >> a >> b;
	max(a,b)-=1;
	cout << "The greater among the two is:" << max(a,b)<< "\n";
	return 0;
}
