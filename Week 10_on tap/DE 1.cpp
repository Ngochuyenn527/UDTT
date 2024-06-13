//THAM LAM + QUY HOACH DONG
//lay nhieu tulanh nhat sao cho 0 vuot gia tien
//lay duoc bnh cai tu
#include<bits/stdc++.h>

using namespace std;

struct Tulanh{
	string ten;
	int dientich;
	double gia;
};

//sx tang dan
void sort(Tulanh d[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(d[j].gia < d[j-1].gia){
				Tulanh temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
			}
		}
	}
}

//mergeSort
void merge(Tulanh d[], int l, int m, int r){    //
	int n1 = m - l + 1 ;
	int n2 = r - (m+1) + 1 ;
	Tulanh a[n1], b[n2];             //
	
	for(int i = 0; i < n1 ; i++){
		a[i] = d[i + l];
	}
	for(int i = 0; i < n2 ; i++){
		b[i] = d[i + (m+1)];
	}
	
	int i = 0 , j = 0;
	while(i < n1 && j < n2){ 
		if(a[i].gia <= b[j].gia) d[l++] = a[i++];   //
		else d[l++] = b[j++];
	} 
	while(i < n1) d[l++] = a[i++];
	while(j < n2) d[l++] = b[j++];
}

//mergeSort : sap xep tang dan cac day con
void mergeSort(Tulanh d[], int l, int r){  //
	if(l >= r) return;
	int m = (l+r) / 2;
	mergeSort(d, l, m);
	mergeSort(d, m+1, r);
	merge(d,l,m,r);
}


void thamlam(Tulanh d[], int n, int p){
	int sl = 0; //sl lay duoc
	Tulanh a[10]; int z=0; //ds lay duoc
	
	int i=0;
	while(d[i].gia <= p && i<n){
		p -= d[i].gia;
		a[z] = d[i];
		i++; 
		z++; 
		sl++;
	}
	
	cout<<"So luong Tu lanh mua duoc la: "<<sl<<"\n";
	
	cout<<"---------------------------------------------------\n";
	cout<<"TEN";
	cout<<setw(25)<<"DIEN TICH";
	cout<<setw(15)<<"GIA BAN"<<endl;
	cout<<"---------------------------------------------------\n";
	for(int i=0; i<z; i++){
		cout<<a[i].ten<<"\t";
		cout<<setw(15)<<a[i].dientich;
		cout<< fixed << setprecision(0)<<setw(15)<<a[i].gia<<"\n";
	}
	
}

void qhd(Tulanh d[], int n, int s){
	
	int F[n+1][s+1];
	
	Tulanh d_new[n+1];
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
			if(d_new[i].dientich <= j){
				int temp = d_new[i].gia + F[i-1][j-d_new[i].dientich];
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
	Tulanh a[100]; int z=0; //ds chua cac DIENTHOAI lay duoc
	cout<<"\nMax value: "<<F[n][s];
	int i=n, j=s;
	while(i!=0){
		if(F[i][j] != F[i-1][j]){
			a[z] = d_new[i];
			z++;
			x++;
			j = j-d_new[i].dientich;
		}
		i--;
	}
	
	cout<<"\nSo luong Dienthoai lay duoc la: "<<x<<"\n";
	
	
	cout<<"---------------------------------------------------\n";
	cout<<"TEN";
	cout<<setw(25)<<"DIEN TICH";
	cout<<setw(15)<<"GIA BAN"<<endl;
	cout<<"---------------------------------------------------\n";
	for(int i=0; i<z; i++){
		cout<<a[i].ten<<"\t";
		cout<<setw(15)<<a[i].dientich;
		cout<< fixed << setprecision(0)<<setw(15)<<a[i].gia<<"\n";
	}
}


int main(){
	int n=6;
	int p=12; //gia tien
	Tulanh d[n] = {
					{"Samsung",3,4},
					{"Iphone",6,5},
					{"Oppo",2,2},
					{"Nokia",7,6},
					{"Xiaomi",1,1},
					{"Sony",5,3}
				};
	
	sort(d,n);
//	mergeSort(d,0,n-1);
	thamlam(d,n,p);
	
	int s = 12; //trong luong tui
	qhd(d,n,s);
	return 0;
}


