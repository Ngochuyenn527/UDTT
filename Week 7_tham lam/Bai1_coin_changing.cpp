#include<bits/stdc++.h>

using namespace std;

//cho so tien n
// a chua cac menh gia cua dong tien => can duoc sx giam dan
// s chua cac so luong cua m dong tien 

//vd m = 4 => s[4] = {0,0,0,0}, a[4] = {10,5,2,1}
//Output: Cho biet so luong dong tien it nhat de co tong menh gia bang n


//sx mang chua cac menh gia tien giam dan
void bubbleSort(int a[], int m){
	for(int i=1; i<m; i++){
		for(int j=m-1; j>=i; j--){
			if(a[j]>a[j-1]){
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}


bool coin_changing(int n, int a[], int s[], int m){
	//khoi tao mang s[] chua cac gtri 0
	for(int i=0; i<m ;i++){
		s[i] = 0;
	}
	
	int i=0;
	while(n>0 && i<m){
		s[i] = n/a[i];  // so dong a[i] nhieu nhat co the lay
		n = n-a[i]*s[i]; // tinh so tien con lai
		i++;
	}
	if(n>0) return false;
	return true;
}

int main(){
	int m = 4, s[m];
	int a[4] = {10,2,5,1};
	
	bubbleSort(a,m);
	
	cout<<"After sort: ";
	for(int i=0; i<m; i++){
		cout<<a[i]<<" ";
	}
	
	int n;
	cout<<"\nNhap so tien n = "; cin>>n;
	if(coin_changing(n,a,s,m)){
		for(int i=0; i<m ;i++){
			if(s[i] != 0){
				cout<<"Lay "<<s[i]<<" dong "<<a[i]<<"\n";
			}
		}
	}
	else{
		cout<<"0 co phuong an chon";
	}
}
