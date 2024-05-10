#include<iostream>

using namespace std;

float max(float x[], int l, int r){
	if(l==r) return x[l];
	int m =(l+r)/2;
	float a = max(x, l, m);
	float b = max(x, m+1, r);
	return a>b ? a:b;
}

int main(){
	int n=15;
	float  x[n] = {1.2, 2.6, 0.2, 4.3, 6.4, 2.8, 4.1, 0.2, 0.3, 7.4, 0.7, 0.2, 4.7, 5.3, 0.9};
	cout<<max(x,0,n-1);
	return 0;
}

