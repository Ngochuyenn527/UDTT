#include<bits/stdc++.h>

using namespace std;

struct Xetai{
	string bienso;
	int taitrong;
};


void sort_taitrong(Xetai x[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(x[j].taitrong > x[j-1].taitrong){
				Xetai temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}
		}
	}
}

bool taitrong_changing(int sum, int n, Xetai x[], int s[]){
	
	for(int i=0; i<n ;i++){
		s[i] = 0;
	}
	
	int i=0;
	while(sum > 0 && i<n){
		s[i] = sum / x[i].taitrong;
		sum = sum - s[i] * x[i].taitrong;
		i++;
	}
	if(sum > 0){
		for(int i=n-1; i>=0; i++){
			if(x[i].taitrong >= sum){
				s[i]++;
				sum = 0;
				break;
			}
		}
	}
	if(sum == 0) return 1;
}


int main(){
	
	int n = 5, s[n];

	Xetai x[n] = {
		{"29C-888.24", 10000}, 
		{"29C-888.64", 5000}, 
		{"29C-888.85", 4000}, 
		{"29C-888.34", 9000}, 
		{"29C-888.34", 500}, 


	};
	
	sort_taitrong(x,n);
	cout<<"After sort: ";
	for(int i=0; i<n; i++){
		cout<<x[i].taitrong<<" ";
	}
	
	if(taitrong_changing(7000,n,x,s)){
		int count = 0;
		for(int i=0; i<n; i++){
			if(s[i] != 0){
				count+= s[i];
				cout<<"\nLay "<<s[i]<< " xe tai co bien so "<<x[i].bienso<<"\n";
			}
		}
		cout<<"Can su dung it nhat "<<count<<" chiec xe tai";
	}
}
