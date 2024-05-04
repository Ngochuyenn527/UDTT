// char S[] = {‘A’, ‘B’, ‘C’, ‘D’, ‘E’, ‘F’, ‘G’};
#include<bits/stdc++.h>
using namespace std;
int x[100], i, k;
int n = 7;
char a[7]= {'A', 'B', 'C', 'D', 'E', 'F', 'G'};


//liet ke bang pp sinh
void swap(int &a, int &b){
	int temp = a;
	a = b; 
	b = temp;
}

void view_config(){
	for(int i=1; i<=n ;i++){
		int z = x[i];
		cout<<a[z-1]<<" ";
	}
	cout<<endl;
}

void next_config(){
	k=n;
	while(x[k] < x[i]){
		k--;
	}
	
	swap(x[k], x[i]);
	
	int j=n; i++;
	while(i<j){
		swap(x[i], x[j]);
		j--;
		i++;
	}
}

void listing_configs(){
	int count1 = 0;
	for(int i=1; i<=n; i++){
		x[i] = i;
	}
	
	do{
		view_config();
		count1++;
		i=n-1;
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
	for(int i=1; i<=n; i++){
		if(dd[i] == 0){
			x[k] = i;
			if(k==n){
				view_config();
				count2++;
			}
			else{
				dd[i] = 1; // ghi nhan viec chon i cho x[k]
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