//Tinh tong cac so le trong mot mang n so nguyen bang pp chia de tri
//Tinh gtri TBC cua cac so le do
#include<iostream>

using namespace std;

void Tong(int x[], int l, int r, long &sum, long &count){
	if(l==r){
		if(x[l] % 2 != 0){
			sum += x[l];
			count++;
		}
	}
	else{
		int m = (l+r)/2;
		Tong(x,l,m,sum,count);
		Tong(x,m+1,r,sum,count);
	}
}

int main(){
	int n, x[n];
	cout<<"Nhap n = "; cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	long sum = 0, count = 0;
	Tong(x,0,n-1,sum,count);
	cout<<sum<<" "<<count;
	return 0;
}
