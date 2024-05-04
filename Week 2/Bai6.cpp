//Liet ke hoan vi theo pp quay lui

#include<iostream>

using namespace std;

int x[100], n, dd[100];
//dd la danh dau so do da duoc ghep vo mang x chua
//neu so do da duoc chon de ghep vo x roi thi gan dd = 1

void show(){
	for(int i=1; i<=n; i++){
		cout<<x[i];
	}
	cout<<"\n";
}

void Try(int k){
	for(int i=1; i<=n; i++){
		if(dd[i] == 0){ //i chua duoc chon truoc do
			x[k] = i;
			if(k==n){ // tim duoc ptu cuoi
				show();
			}
			else{
				dd[i] = 1; // ghi nhan viec chon i cho x[k]
				Try(k+1);
				dd[i] = 0; // huy ghi nhan viec chon i cho x[k] 
			}
		}
	}
}

int main(){
	cin>>n;
	Try(1);
	return 0;
}

