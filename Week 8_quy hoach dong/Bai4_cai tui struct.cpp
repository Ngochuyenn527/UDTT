#include<iostream>

using namespace std;
//u: so goi hang
//d: danh sach cac goi
//sao cho lay duoc gia tri max ma 0 vuot qua kich thuoc tui

struct goihang{
	int w; //trong luong
	int v; //gia tri
};

void algorithm(goihang x[], int F[7][13], int n, int m){
	//khoi tao dong dau tien co gtri = 0
	for(int j=0; j<=m; j++){
		F[0][j] = 0;
	}
	
	//xuat dong dau tien
	for(int j=0; j<=m; j++){
		cout<<F[0][j]<<" " ;
	}
	cout<<"\n";
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			F[i][j] = F[i-1][j];
			if(x[i].w <= j){
				int temp = x[i].v + F[i-1][j-x[i].w];
				if(F[i][j] < temp){
					F[i][j] = temp;
				}
			}
			cout<<F[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void result(goihang x[], int F[7][13], int n, int m){
	cout<<"Gia tri lon nhat co the lay ma 0 vuot qua kich thuoc cua tui bang: "<<F[n][m]<<"\n";
	int i=n, j=m;
	int count =0;
	cout<<"Danh sach cac goi lay duoc la: ";
	while(i != 0){
		if(F[i][j] != F[i-1][j]){
			cout<<i<<" ";
			count++;
			j = j-x[i].w;
		}
		i--;
	}
	cout<<"\nVoi tong so goi lay duoc la: "<<count<<" goi";
	
}

int main(){
	int n = 6; // so goi hang
	int m = 12; // trong luon cua tui
	goihang x[n+1] = {{0,0},{3,4},{6,5},{2,2},{7,6},{1,1},{5,3}};
	int F[7][13];
	algorithm(x,F,n,m);
	result(x,F,n,m);
	return 0;
	
}
