//liet ke cac cach xep 6 sv " Trang, Cong, Trung, Binh, Hoan, Mai " vao 6 ghe " 1, 2, 3, 4, 5, 6 "
#include<iostream>
using namespace std;
string a[6] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
int n=6;
int x[100], k ,i; //khai bao cuc bo mang a gom 100 ptu gtri == 0

void swap(int &a, int &b){
	int temp = a;
	a=b;
	b=temp;
}

void view_config(){
	for(int i=1; i<=n; i++){
		int z=x[i];
		cout<<a[z-1]<<" ";
	}
	cout<<"\n";
}

void next_config(){
	k=n;
	while(x[k]<x[i]){
		k--;
	}
	swap(x[i], x[k]);
	
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
		x[i]=i;
	}
	
	do{
		view_config();
		i = n-1;
		while(i>0 && x[i] > x[i+1]){
			i--;
		}
		if(i>0){
			next_config();
		}
	}
	while(i>0);
}

int main(){
	listing_configs();
	return 0;
	
}
