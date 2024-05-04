//Sinh cac tap con k ptu cua tap S = {1,2,...,n}

#include<iostream>
using namespace std;

int x[100]; //khai bao cuc bo mang a gom 100 ptu gtri == 0

int n, k, i;

void next_config(){
	x[i]+=1;
	i++;
	while(i<=k){
		x[i] = x[i-1]+1;
		i++;
	}
}

void view_config(){
	for(int i=1; i<=k; i++){
		cout<<x[i];
	}
	cout<<"\n";
}

void listing_configs(){
	//sinh cau hinh dau tien
	for(int i=1; i<=k; i++){
		x[i] = i;
	}
	do{
		view_config(); //sinh xong thi in cau hinh
		i=k;
		while(i>0 && x[i] == n-k+i){
			i--;
		}
		if(i>0){
			next_config();
		}
	}
	while(i>0);
}

int main(){
	cout<<"Nhap n = "; cin>>n;
	cout<<"Nhap k = "; cin>>k;
	listing_configs();
	return 0;
}
