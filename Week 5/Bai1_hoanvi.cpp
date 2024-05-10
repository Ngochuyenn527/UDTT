/*
G gom 4 chiec ghe mac 'A', 'B', 'C', 'D'  => b[4]
N gom 4 nguoi {Tung, Cuc, Truc, Mai}   => a[4]
*/

#include<bits/stdc++.h>

using namespace std;

string a[4] = {"Tung", "Cuc", "Truc", "Mai"};
string b[4] = {"A", "B", "C", "D"};
int x[100], n = 4, k, i;

//liet ke hoan vi bang pp sinh
void swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void view_config(){
	//cout G
	cout<<b[0];
	for(int i=1; i<n ;i++){
		cout<<setw(10)<<b[i];
	}
	cout<<"\n";
	
	//cout N
	for(int i=1; i<=n ;i++){
		int z = x[i];
		cout<<a[z-1]<<setw(10);
	}
	cout<<"\n";
}


void next_config(){
	//tim x[k] thuoc day giam dan vua du lon hon x[i]
	k=n;
	while(x[k]<x[i]){ 
		k--;            
	}
	swap(x[i], x[k]); //dao vi tri
	
	int j=n; i++; // dao nguoc doan cuoi => sx tang dan
	while(i<j){
		swap(x[i], x[j]);
		i++;
		j--;
	}	
}

void listing_configs(){
	int count1 = 0;
	//sinh cau hinh dau tien
	for(int i=1; i<=n; i++){
		x[i] = i;
	}
	
	do{
		view_config();
		count1++;
		i = n-1; // duyet tu cuoi ve dau, tim doan cuoi giam dan dai nhat
		while(i>0 && x[i] > x[i+1]){
			i--;
		}
		if(i>0){
			next_config();
		}
	}
	while(i>0);
	cout<<"Tong so cach xep cua pp sinh la: "<<count1<<endl;
}


//liet ke hoan vi bang pp quay lui
int dd[100];
//dd la danh dau so do da duoc ghep vo mang x chua
//neu so do da duoc chon de ghep vo x roi thi gan dd = 1

int count2 = 0;
void Try(int k){
	for(int i=1; i<=n ;i++){
		if(dd[i] == 0){ //i chua duoc chon truoc do
			x[k] = i;
			if(k==n){
				view_config();
				count2++;
			}
			else{
				dd[i] = 1;  // ghi nhan viec chon i cho x[k]
				Try(k+1);
				dd[i] = 0;  // huy ghi nhan viec chon i cho x[k]
			}
		}
	}
}


int main(){

	listing_configs();
	cout<<"\n";
	Try(1);
	cout<<"Tong so cach xep cua pp quay lui la: "<<count2<<endl;

	
	return 0;
}

