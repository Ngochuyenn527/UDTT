//mergeSort : mix two sorted array => one array
#include<bits/stdc++.h>

using namespace std;

//merge : tron 2 day con gom : day1[l, m], day2[m+1, r]
void merge(int x[], int l, int m, int r){
	int n1 = m - l + 1 ;
	int n2 = r - (m+1) + 1 ; // tinh so ptu trong 1 khoang
	int a[n1], b[n2];
	
	for(int i = 0; i < n1 ; i++){
		a[i] = x[i + l];
	}
	for(int i = 0; i < n2 ; i++){
		b[i] = x[i + (m+1)];
	}
	
	int i=0, j=0;
	while(i < n1 && j < n2){
		if(a[i] <= b[j]){
			x[l] = a[i];
			l++; i++;
		} // or x[l++] = a[i++];
		else{
			x[l] = b[j];
			l++; j++;
		} // or x[l++] = b[j++];
	}
	
	while(i < n1){ //so ptu chua duoc duyet het
		x[l] = a[i]; 
		l++; i++;  // or x[l++] = a[i++];
	}
	
	while(j < n2){
		x[l] = b[j];
		l++; j++;  // or x[l++] = b[j++];
	}
}

//mergeSort : sap xep tang dan cac day con
void mergeSort(int x[], int l, int r){
	if(l >= r) return;
	int m = (l+r) / 2;
	mergeSort(x, l, m);
	mergeSort(x, m+1, r);
	merge(x,l,m,r);
}

int main(){
	
//	int n = 100;
//	int x[100];
//	srand(time(NULL));
//	for(int i=0; i<n; i++){
//		x[i] = rand() % 1000;
//	}
//	mergeSort(x, 0, n-1);
//	for(int a : x){
//		cout<<a<<" ";
//	}
//	return 0;
	int n=5, x[n];
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	cout<<"Befor merge sort: ";
	for(int i=0; i<5; i++){
		cout<<x[i] <<" ";
	}
	cout << endl ;
	mergeSort(x, 0, n-1);
	//mergeSort function
	cout<<"After merge sort: ";
	for(int i=0; i<5; i++){
		cout<<x[i]<<" ";
	}
}



/*
void merge(int x[], int l, int m, int r){
	int n1 = m - l + 1 ; 
	int n2 = r - m ; 
	int a[n1] , b[n2] ; 
	for(int i = 0 ; i < n1 ; i++){
		a[i] = x[i+l];
	}
	for(int i = 0;i < n2 ;i++){
		b[i] = x[i + m + 1];
	}
	
	int i = 0 , j = 0;
	while(i < n1 && j < n2){ 
		if(a[i] <= b[j]) x[l++] = a[i++];
		else x[l++] = b[j++];
	} 
	while(i < n1) x[l++] = a[i++];
	while(j < n2) x[l++] = b[j++];
}

*/


