//Sinh day nhi phan bang pp quay lui

#include<iostream>

using namespace std;

int x[100], n;

void show(){
	for(int i=1; i<=n; i++){
		cout<<x[i];
	}
	cout<<"\n";
}

void Try(int k){
	for(int i=0; i<=1; i++){
		x[k] = i;
		if(k == n){  // ptu cuoi
			show();
		}
		else{
			Try(k+1);
		}
	}
}

int main(){
	cin>>n;
	Try(1);
	return 0;
}
