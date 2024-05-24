#include<bits/stdc++.h>

using namespace std;

struct Balo{
	float kichthuoc;
	float kl;
};

void th(){
	cout<<"----------------------------------------------------------------------------\n";
	cout<<"STT";
	cout<<setw(20)<<"KICH THUOC";
	cout<<setw(20)<<"KHOI LUONG"<<endl;
	cout<<"----------------------------------------------------------------------------\n";
}

//sx giam dan
void sort_kl(Balo x[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(x[j].kl < x[j-1].kl){
				Balo temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}
		}
	}
}

void xephang(Balo x[],int n, float k){
	
	int i=0, count =0;
	
	while(k >= x[i].kichthuoc && i<n){
		k -= x[i].kichthuoc;
		cout<<"Lay duoc goi hang thu "<<i+1<<" co kich thuoc la: "<<x[i].kichthuoc<<"\n";
		count++;
		i++;
	}
	
	while(k > 0 && i<n){
		i++;
		if(k >= x[i].kichthuoc && i<n){
			k -= x[i].kichthuoc;
			cout<<"Lay duoc goi hang thu "<<i+1<<" co kich thuoc la: "<<x[i].kichthuoc<<"\n";
			count++;
		}
	}
	cout<<"Tong so Balo duoc xep la: "<<count<<"\n";

}


int main(){
	int n = 5;

	Balo x[n] = {
		{40, 10000}, 
		{30, 5000}, 
		{30, 4000}, 
		{40, 9000}, 
		{100, 500}, 
	};
	
	cout<<"Before sort tang dan khoi luong: \n";
	th();
	for(int i=0; i<n; i++){
		cout<<i+1;
		cout<<setw(20)<<x[i].kichthuoc;
		cout<<setw(20)<<x[i].kl<<endl;
	}
	cout<<"\n";
	
	sort_kl(x,n);
	
	cout<<"After sort tang dan khoi luong: \n";
	th();
	for(int i=0; i<n; i++){
		cout<<i+1;
		cout<<setw(20)<<x[i].kichthuoc;
		cout<<setw(20)<<x[i].kl<<endl;
	}
	cout<<"\n";
	cout<<"So kien hang lay duoc sao cho tong khoi luong xep len xe dat duoc la NHO NHAT va 0 vuot qua kich thuoc cua thung xe la: \n";
	xephang(x,n,70);
}
