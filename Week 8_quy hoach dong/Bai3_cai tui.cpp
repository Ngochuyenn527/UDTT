#include<iostream>

using namespace std;

//n goi hang: n+1 dong => i = 0->n
//m la trong luong cua moi goi: m+1 cot => j = 0->m

//Bang F gom n+1 dong, m+1 cot
void algorithm(int F[7][13], int w[], int v[], int n, int m){
	
	//khoi tao dong dau tien i = 0
	for(int j=0; j<=m; j++){
		F[0][j] = 0;
	}
	//xuat dong dau tien i = 0
	for(int j=0; j<=m; j++){
		cout<<F[0][j]<<" ";
	}
	cout<<"\n";
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			F[i][j] = F[i-1][j]; // khong lay goi thu i
			if(w[i] <= j){
				int temp = v[i] + F[i-1][j-w[i]]; // temp = gia tri; 
				if(F[i][j] < temp){ 
					F[i][j] = temp; // lay goi thu i
				}
			}
			cout<<F[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void result(int F[7][13], int w[], int v[], int n, int m){
	cout<<"Max value: "<<F[n][m]<<"\n";
	int i=n, j=m;
	cout<<"Danh sach cac goi lay duoc la: ";
	while(i != 0){
		if(F[i][j] != F[i-1][j]){
			cout<<i<<" ";
			j = j - w[i]; //lay goi thu i
		}
		i--;
	}
}

int main(){
	int n=6; // so goi hang
	int m=12; // trong luong cua tui 
	int w[n+1] = {0,3,6,2,7,1,5}; // trong luong
	int v[n+1] = {0,4,5,2,6,1,3}; // gia tri
	int F[7][13];
	algorithm(F,w,v,n,m);
	result(F,w,v,n,m);
	return 0;
	

	
}
