#include<bits/stdc++.h>

using namespace std;

struct Goihang{
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

//sx tang dan
void sort_kl(Goihang x[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(x[j].kl < x[j-1].kl){
				Goihang temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}
		}
	}
}

void tromhang(Goihang x[],int n, float k){
	
	int i=0;
	while(k >= x[i].kichthuoc && i<n){
		k -= x[i].kichthuoc;
		cout<<"Lay duoc goi hang thu "<<i+1<<" co kich thuoc la: "<<x[i].kichthuoc<<"\n";
		i++;
	}
}


int main(){
	int n = 5;

	Goihang x[n] = {
		{40, 10000}, 
		{60, 5000}, 
		{80, 4000}, 
		{30, 9000}, 
		{100, 500}, 
	};
	
	cout<<"Before sort khoi luong: \n";
	th();
	for(int i=0; i<n; i++){
		cout<<i+1;
		cout<<setw(20)<<x[i].kichthuoc;
		cout<<setw(20)<<x[i].kl<<endl;
	}
	cout<<"\n";
	
	sort_kl(x,n);
	
	cout<<"After sort khoi luong: \n";
	th();
	for(int i=0; i<n; i++){
		cout<<i+1;
		cout<<setw(20)<<x[i].kichthuoc;
		cout<<setw(20)<<x[i].kl<<endl;
	}
	cout<<"\n";

	cout<<"Nhung goi hang sao cho tong kl cac goi hang duoc chon la nho nhat va tong kich thuoc khong vuot qua kich thuoc balo la: \n";
	tromhang(x,n,200);
}
