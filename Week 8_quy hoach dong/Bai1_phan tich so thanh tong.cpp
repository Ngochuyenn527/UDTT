#include<iostream>

using namespace std;

//m: so dong => i = 0->m
//n: so cot = so ptu trong 1 dong => j = 0->n

int show(int f[6][6], int m, int n){
	
	//khoi tao dong dau tien i=0
	f[0][0] = 1;
	for(int j=1; j<=n; j++){
		f[0][j] = 0;
	}
	
	//xuat dong dau tien f[0][j]
	for(int j=0; j<=n; j++){
		cout<<f[0][j]<<" ";
	}
	cout<<"\n";
	
	//sinh cac dong tiep theo f[m][n] dong 1->m
	for(int i=1; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i>j){
				f[i][j] = f[i-1][j];
				cout<<f[i][j]<<" ";
			}
			else{
				f[i][j] = f[i-1][j] + f[i][j-i];
				cout<<f[i][j]<<" ";
			//  f(5,5) = f(4,5) + f(5,0) 
			}
		}
		cout<<"\n";
	}
	return f[m][n];
}

int main(){
	int f[6][6];
	//voi n = 5
	cout<<show(f,5,5);
	return 0;
}
