//Tim max bang pp chia de tri

#include<iostream>

using namespace std;

int max(int x[], int l, int r){
	if(l==r) return x[l];
	int m = (l+r)/2;
	int a = max(x,l,m);
	int b = max(x,m+1,r);
	return (a>b) ? a:b;
}

int main(){
	int n, x[n];
	cout<<"Nhap n = "; cin>>n;
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	cout<<"Max = "<<max(x,0,n-1);
	return 0;
}
