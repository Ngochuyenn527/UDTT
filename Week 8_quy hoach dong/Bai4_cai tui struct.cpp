#include<bits/stdc++.h>

using namespace std;
//u: so goi hang
//d: danh sach cac goi
//sao cho lay duoc gia tri max ma 0 vuot qua kich thuoc tui

struct goihang{
	int w; //kich thuoc
	int v; //gia tri
};

struct ketqua{
	int u ; 
	vector<goihang> d; 
};

ketqua algorithm(goihang x[], int n, int m){
	
	int F[n+1][m+1];
	
	goihang x_new[n+1];
	x_new[0] = {0,0};
	for(int i=0; i<n; i++){
		x_new[i+1] = x[i];
	}
	
	//khoi tao dong dau tien co gtri = 0
	for(int j=0; j<=m; j++){
		F[0][j] = 0;
	}
	
	//xuat dong dau tien
	for(int j=0; j<=m; j++){
		cout<<F[0][j]<<setw(10) ;
	}
	cout<<"\n";
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			F[i][j] = F[i-1][j];
			if(x_new[i].w <= j){
				int temp = x[i].v + F[i-1][j-x_new[i].w];
				if(F[i][j] < temp){
					F[i][j] = temp;
				}
			}
			cout<<F[i][j]<<setw(10);
		}
		cout<<"\n";
	}
	
	//truy vet
	ketqua result; 
	int i=n, j=m;
	while(i != 0){
		if(F[i][j] != F[i-1][j]){
			result.d.push_back(x_new[i]);
			result.u++;
			j = j-x_new[i].w;
		}
		i--;
	}
	return result ; 
}

	


int main(){
	int n = 5; // so goi hang
	int m = 7; // trong luong cua tui
	
	goihang x[n] = {
						{7, 100}, 
						{3, 50}, 
						{1, 40}, 
						{3, 90}, 
						{10, 50}, 
					};
					
	ketqua result = algorithm(x,n,m);
	cout << "So luong: " << result.u  << endl ;
	cout << "Danh dach goi hang " ; 
	for(int i = 0 ; i < result.d.size();i++){
		cout << result.d[i].w << " " ;
	}
	return 0;
	
}
