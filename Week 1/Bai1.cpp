#include<iostream>
using namespace std;
int a[100];//khai bao cuc bo mang a gom 100 ptu gtri == 0
int n; 

void incauhinh(int a[], int n){
	for(int i=0; i<n; i++){
		cout<<a[i];
	}
	cout<<"\n";
}

void datBang0(int a[], int n, int vt){
	for(int i=vt; i<n; i++){
		a[i]=0;
	}
}


// xet tu cuoi len dau, tim so 0, thay so 0 => 1, cac ptu phia sau 1=>0
// 101011 + 1 = 101100
void sinhChuoiNhiPhan(int a[], int n){
	incauhinh(a,n);
	int i=n-1; //duyet tu cuoi tìm a[i]=0
	while(i>0){
		if(a[i] == 1) i--;
		if(a[i] == 0){
			a[i] = 1;
			datBang0(a,n,i+1); 
			incauhinh(a,n);
			i=n-1;
		}
	}
	
}
int main(){
	cout<<"Nhap n: "<<endl;
	cin>>n;
	sinhChuoiNhiPhan(a,n);
	cout<<a[5];
}
