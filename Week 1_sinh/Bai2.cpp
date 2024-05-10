//sinh chuoi ki tu do dai chi chua 2 ky tu 'a' va 'b'
//a=0, b=1
#include<iostream>

using namespace std;
string a[100]; //khai bao cuc bo mang a gom 100 ptu gtri == 0
int n;


void sinhcauhinh1(){
	for(int i=0; i<n; i++){
		a[i] = "a";
	}
}

void incauhinh(){
	for(int i=0; i<n; i++){
		cout<<a[i];
	}
	cout<<endl;
}

void datbang_a(int vt){
	for(int i=vt; i<n; i++){
		a[i]="a";
	}
}

void sinhChuoi(){
	int i=n-1;   
	sinhcauhinh1(); 
	incauhinh();                                                                                                                                                                                                                                                         
	while(i>0){
		if(a[i]=="b") i--;
		if(a[i]=="a"){
			a[i]="b";
			datbang_a(i+1);
			incauhinh();
			i=n-1;
		}
	}
}

int main(){
	cout<<"Nhap n: ";
	cin>>n;
	sinhChuoi();
	
}
