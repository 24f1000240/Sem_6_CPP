#include<iostream>
#include<cstring>
using namespace std;

class bird{
	public:
	char c;
	char ty[10];
	void exist(){
		cout<<"it is existing\n";
	}
};

int main(){
	bird b1;
	b1.c='b';
	strcpy(b1.ty,"Flying");
	cout<<"Color= "<<b1.c<<"\n";
	cout<<"Type= "<<b1.ty<<endl;
	b1.exist();
	return 0;
}

