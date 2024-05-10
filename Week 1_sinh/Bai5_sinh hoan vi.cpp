//sinh hoan vi cua tap  S = {1, 2, …, n}. 
#include<iostream>

using namespace std;

int x[100], n, k, i; //khai bao cuc bo mang a gom 100 ptu gtri == 0

void view_config(){
	for(int i=1; i<=n; i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void next_config(){
	k=n;
	while(x[k]<x[i]){
		k--;
	}
	
	// dao gtri cua x[i] va x[k]
	swap(x[i], x[k]);
	
	//dao nguoc doan cuoi
	int j=n; i++;
	while(i<j){
		swap(x[i], x[j]);
		i++;
		j--;
	}
}

void listing_configs(){
	//sinh cau hinh dau tien
	for(int i=1; i<=n; i++){
		x[i] = i;
	}
	
	do{
		view_config(); //in cau hinh vua sinh
		i=n-1; //phan tu lien truoc doan cuoi giam dan // vd: {3,2,6,5,4,1} => i=n-1=4
		while(i > 0 && x[i] > x[i+1]){
			i--;
		}
		if(i>0){ // Chua phai cau hinh cuoi 
			next_config();
		}
	}
	while(i>0);
}

int main(){
	cout<<"Nhap n = "; cin>>n;
	listing_configs();
	return 0;
}
