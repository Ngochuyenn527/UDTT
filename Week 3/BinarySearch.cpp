//chi ap dung voi day da duoc sx
#include <bits/stdc++.h>

using namespace std;

int BinarySearch(int x[],int k, int left, int right){
	if(left>right) return -1;
	else{
			int mid = (left+right)/2;
			if(x[mid]==k) return mid;
			else if(k>x[mid]) return BinarySearch(x,k,mid+1,right);
		    else return BinarySearch(x,k,left,mid-1);
	}
}

void merge(int x[] , int l , int  m , int l){
	
}
int main(){
	int n; cin>>n;
	int x[n];
	for(int i=0; i<n; i++){
		cin>>x[i];
	}
	cout<<BinarySearch(x,1,0,n-1);
	return 0;
}


