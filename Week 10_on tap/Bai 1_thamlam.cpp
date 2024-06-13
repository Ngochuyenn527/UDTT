//cho mot so tien p
//mot list d gom n chiec quat khac nhau gia ban gom: tenhsx, mau, giaban
//Tinh c va s la soluong va ds nhieu nhat cac quat co the mua voi so tien p

#include<bits/stdc++.h>

using namespace std;

struct Quatban{
	string tenhsx;
	string mausac;
	double giaban;
};

//sx tang dan giaban
void sort(Quatban d[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(d[j].giaban < d[j-1].giaban){
				Quatban temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
			}
		}
	}
}

//mergeSort
void merge(Quatban d[], int l, int m, int r){    //
	int n1 = m - l + 1 ;
	int n2 = r - (m+1) + 1 ;
	Quatban a[n1], b[n2];             //
	
	for(int i = 0; i < n1 ; i++){
		a[i] = d[i + l];
	}
	for(int i = 0; i < n2 ; i++){
		b[i] = d[i + (m+1)];
	}
	
	int i = 0 , j = 0;
	while(i < n1 && j < n2){ 
		if(a[i].giaban <= b[j].giaban) d[l++] = a[i++];   //
		else d[l++] = b[j++];
	} 
	while(i < n1) d[l++] = a[i++];
	while(j < n2) d[l++] = b[j++];
}

//mergeSort : sap xep tang dan cac day con
void mergeSort(Quatban d[], int l, int r){  //
	if(l >= r) return;
	int m = (l+r) / 2;
	mergeSort(d, l, m);
	mergeSort(d, m+1, r);
	merge(d,l,m,r);
}



//p la so tien muon mua
void G1(Quatban d[], int n, int p){
	
	int c=0; //so luong quat lay duoc
	Quatban s[100]; int z=0; ////ds chua cac QUAT lay duoc
	
	int i=0;
	while(d[i].giaban <= p && i<n){
		p -= d[i].giaban;
		s[z] = d[i];
		i++;
		z++;
		c++;
	}
	
	cout<<"So luong quat mua duoc la: "<<c<<"\n";
	
	cout<<"-------------------------------------\n";
	cout<<"HSX";
	cout<<setw(25)<<"GIA BAN"<<endl;
	cout<<"-------------------------------------\n";
	for(int i=0; i<z; i++){
		cout<<s[i].tenhsx;
		cout<<setw(20)<<s[i].giaban;
		cout<<"\n";
	}
}


int main(){
	int n=5;
	int p = 1500;
	
	Quatban d[n] = {{"Toyota", "white", 700},
					{"Toyota", "baclk", 400},
					{"Toyota", "white", 200},
					{"Toyota", "white", 900},
					{"Toyota", "white", 100},
				};
	
//	sort(d,n);
	mergeSort(d, 0, n-1);
	
	G1(d,n,p);
	return 0;
	
}
