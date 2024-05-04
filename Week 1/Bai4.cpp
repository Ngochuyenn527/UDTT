//lay 4 sv tu 6 sv "Trang, Cong, Trung, Binh, Hoan, Mai"
#include<bits/stdc++.h>

using namespace std;

string a[] = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};
int x[100]; //khai bao cuc bo mang a gom 100 ptu gtri == 0
int n=6;
int k=4;
int i;

void next_config(){
	x[i]+=1; 
	i++;
	while(i<=k){
		x[i]=x[i-1]+1;
		i++;
	}
}

void view_config(){
	for(int i=1; i<=k; i++){
		int z=x[i];
		cout<<a[z-1]<<" ";
	}
	cout<<"\n";
}


void listing_config(){
	//sinh cau hinh dau tien
	for(int i=1; i<=k; i++){
		x[i]=i;
	}
	do{
		view_config(); //in ra cau hinh vua sinh
		i=k;
		while(i>0 && x[i]==n-k+i){
			i--;
		}
		if(i>0){
			next_config();
		}
	}
	while(i>0);
}

int main(){
	listing_config();
	return 0;
}
