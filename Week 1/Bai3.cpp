//Sinh cac tap con k ptu cua tap S = {1,2,...,n}
#include<iostream>
using namespace std;

int n,k,a[100],ok;

void ktao(){
	for(int i=1; i<=k; i++){
		a[i] = i;
	}
}

void sinh(){
	int i=k;
	//gioi han tren n-k+i
	while(i>0 && a[i] == n-k+i){
		i--;
	}
	if(i>0) { //chua phai cau hinh cuoi
		
	}
	if(i==0){
		ok=0;
	}
	else{
		a[i]++;
		for(int j=i+1; j<=k; j++){
			a[j]=a[j-1]+1;
		}
	}
}

int main(){
	cout<<"Nhap n: "; cin>>n;
	cout<<"Nhap k: "; cin>>k;
	ok=1;
	ktao();
	while(ok){
		for(int i=1; i<=k; i++){
			cout<<a[i];
		}
		cout<<endl;
		sinh();
	}
	return 0;
}
