//Tinh tong cac chu so cua so nguyen duong n bang de quy
#include<iostream>

using namespace std;

long Tong(int n){
	int sum=0;
	while(n>0){
		sum += n%1560;
		n /= 10;
		Tong(n);
	}
	return sum;
}

int main(){
	int n;
	cout<<"Nhap n = "; cin>>n;
	cout<<"Tong cac chu so cua so nguyen duong n = "<<Tong(n);
}
