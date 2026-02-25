#include<iostream>
using namespace std;
class cons{
	int a;
	public:
	cons(){
		cout<<"Constructor is invoked!"<<endl;
	}
	void display(){
        	int a = 2;
        	cout<<"Value a = "<<a<<"\n";
	}
};
int main(){
	cons c1;
	return 0;
}
