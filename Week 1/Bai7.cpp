//Tim so Fibonaci thu n bang de quy co nho
#include<iostream>
using namespace std;

int F(int n){
	if(n==1 || n==2) return 1;
	else return F(n-2) + F(n-1);
}

int main(){
	int n;
	cout<<"Nhap n = "; cin>>n;
	cout<<"F(n) = "<<F(n);
}

