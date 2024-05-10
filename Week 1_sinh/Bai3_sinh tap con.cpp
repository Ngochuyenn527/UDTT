//Sinh cac tap con k ptu cua tap S = {1,2,...,n}
#include<iostream>

using namespace std;

int x[100], n=3, k=2, i; //khai bao cuc bo mang x gom 100 ptu gtri == 0

void view_config(){
	for(int i=1; i<=k; i++){
		cout<<x[i]<<" ";
	}
	cout<<"\n";
}

void next_config(){
	x[i]+=1;
	i++;
	while(i<=k){
		x[i] = x[i-1]+1;
		i++;
	}
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
	listing_configs();
	return 0;
}
