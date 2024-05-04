#include<iostream>

using namespace std;

float Pow(float a, int n){
	if(n==1) return a;
	else{
		float x = Pow(a, n/2);
		if(n%2==0) return x*x;
		else return a*x*x;
	}
}

int main(){
	cout<<Pow(2.2,4);
	return 0;
}
