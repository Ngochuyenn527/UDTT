#include<iostream>

using namespace std;

//sx tang dan
void bubbleSort(int a[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

int chietnuoc(int a[],int n, int m){
	int i=0, count =0;
	while(m>=a[i] && i<n){
		m-=a[i];
		count++;
		i++;
	}
	return count;
}

int main(){
	int n=5;
	int a[n] = {8,5,4,3,2};
	
	bubbleSort(a,n);
	
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	
	cout<<chietnuoc(a,n,10);
}
