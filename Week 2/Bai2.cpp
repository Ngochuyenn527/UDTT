// F = 1, 1, 2, 3, 5, 8, 13

#include<iostream>

using namespace std;

int F(int n){
	if(n==0 || n==1) return 1;
	else{
		return F(n-1) + F(n-2);
	}
}

int Fk(int n){
	if(n==0 || n==1) return 1;
	else{
		int fn, f0=1, f1=1;
		for(int i=2; i<=n; i++){
		fn = f1 + f0;
		f0 = f1;
		f1 = fn;
		}
		return fn;
	}
}

int main(){
	int n;
	cout<< Fk(1);
	return 0;
}


