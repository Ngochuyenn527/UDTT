//Tinh tong cac so le trong mot day n so nguyen bang de quy
#include<iostream>

using namespace std;

long Sum_odd(int n){
	int sum=0;
	for(int i=1; i<=n; i++){
		if(i%2 != 0){
			sum += i;
		}
	}
	return sum;
}

int main(){
	int n;
	cout<<"Nhap n = "; cin>>n;
	cout<<"Tong cac so le trong day n so nguyen = "<<Sum_odd(n);
	return 0;
}
