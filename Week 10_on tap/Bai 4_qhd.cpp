/*
cho 1 tui co kich thuoc s
list d[n] dienthoai
Tinh x va a la soluong va ds dienthoai lay duoc 
sao cho tong GIABAN max ma 0 vuot kich thuoc tui
*/

#include<bits/stdc++.h>

using namespace std;

struct Dienthoai{
	string nhanhieu;
	int kichthuoc;
	double giaban;
};


void Q1(Dienthoai d[], int n, int s){
	
	int F[n+1][s+1];
	
	//khoi tao mang moi chua ptu dau tien la {0,0}
	Dienthoai d_new[n+1];
	d_new[0] = {"Samsung",0,0};
	for(int i=0; i<n; i++){
		d_new[i+1] = d[i];
	}

	//khoi tao dong dau tien
	for(int j=0; j<=s; j++){
		F[0][j] = 0;
	}
	
	//xuat dong dau tien
	for(int j=0; j<=s; j++){
		cout<<F[0][j]<<" ";
	}
	cout<<"\n";
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=s; j++){
			F[i][j] = F[i-1][j];
			if(d_new[i].kichthuoc <= j){
				int temp = d_new[i].giaban + F[i-1][j-d_new[i].kichthuoc];
				if(temp > F[i][j]){
					F[i][j] = temp;
				}
			}
			cout<<F[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	//truy vet
	int x=0; //so luong
	Dienthoai a[100]; int z=0; //ds chua cac DIENTHOAI lay duoc
	
	int i=n, j=s;
	while(i!=0){
		if(F[i][j] != F[i-1][j]){
			a[z] = d_new[i];
			z++;
			x++;
			j = j-d_new[i].kichthuoc;
		}
		i--;
	}
	
	cout<<"\nSo luong Dienthoai lay duoc la: "<<x<<"\n";
	
	
	cout<<"-------------------------------------\n";
	cout<<"NHAN HIEU";
	cout<<setw(25)<<"GIA BAN"<<endl;
	cout<<"-------------------------------------\n";
	for(int i=0; i<z; i++){
		cout<<a[i].nhanhieu<<"\t";
		cout<<setw(25)<<a[i].giaban<<"\n";
	}
}

int main(){
	int n=6, s=12;
	
	Dienthoai d[6] = {
					{"Samsung",3,4},
					{"Iphone",6,5},
					{"Oppo",2,2},
					{"Nokia",7,6},
					{"Xiaomi",1,1},
					{"Sony",5,3}
					};
	
	Q1(d,n,s);
	return 0;
	
}
