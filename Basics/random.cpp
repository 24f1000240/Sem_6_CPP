#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;

int main(){
	int max=6;
	int min=1;
	srand(time(0));
	short first=(rand()%(max-min+1))+min;
	short second=(rand()%(max-min+1))+min;
	cout<<first<<" "<<second<<endl;
}
