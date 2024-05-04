//Tinh a^n bang pp chia de tri ( double a, int n > 0)

#include<iostream>

using namespace std;

double Pow(double a, int n){
	if(n==1){
		return a;
	}
	else{
		double x = Pow(a, n/2);
		if(n%2 == 0){
			return x*x;
		}
		else{
			return a*x*x;
		}
	}
}

int main(){
	cout<<Pow(2,5);
	return 0;
}

