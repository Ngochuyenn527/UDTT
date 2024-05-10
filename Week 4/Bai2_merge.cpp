#include<iostream>

using namespace std;

void merge(float x[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-(m+1)+1;
	float a[n1], b[n2];
	for(int i=0; i<n1; i++){
		a[i] = x[i+l];
	}
	for(int i=0 ;i<n2; i++){
		b[i] = x[i+m+1];
	}
	
	int i=0, j=0;
	while(i<n1 && j<n2){
		if(a[i]<=b[j]) x[l++] = a[i++];
		else x[l++] = b[j++];
	}
	
	while(i < n1) x[l++] = a[i++];
	while(j < n2) x[l++] = b[j++];
}

void mergeSort(float x[], int l, int r){
	if(l>=r) return;
	int m= (l+r)/2;
	mergeSort(x, l, m);
	mergeSort(x, m+1, r);
	merge(x, l, m, r);
}

int main(){
	int n=15;
	float  x[n] = {1.2, 2.6, 0.2, 4.3, 6.4, 2.8, 4.1, 0.2, 0.3, 7.4, 0.7, 0.2, 4.7, 5.3, 0.9};
	cout<<"Mang truoc khi sap xep:\n";
	for(int i=0; i<n; i++){
		cout<<x[i]<<"  ";
	}
	cout<<"\n";
	mergeSort(x,0,n-1);
	
	cout<<"Mang sau khi sap xep:\n";
	for(int i=0; i<n; i++){
		cout<<x[i]<<"  ";
	}
	return 0;
}
