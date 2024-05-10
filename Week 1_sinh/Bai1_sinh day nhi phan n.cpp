//sinh chuoi nhi phan co do dai n
#include<iostream>
using namespace std;
int x[100], n = 3, i; //khai bao cuc bo mang x gom 100 ptu gtri == 0

void view_config(){
	for(int i=1; i<=n; i++){
		cout<<x[i];
	}
	cout<<"\n";
}

void next_config(){
	x[i] = 1;
	i++;
	while(i<=n){
		x[i] = 0;  //Dat  x[i+1], …,x[n] =0
		i++;
	}
}
void listing_configs(){
	do{
		view_config(); // in cau hinh vua sinh
		i=n;
		while( i > 0 && x[i] == 1){
			i--;
		}
		if(i > 0){
			next_config();
		}
	}
	while( i > 0);
}

int main(){
	listing_configs();
	return 0;
}

