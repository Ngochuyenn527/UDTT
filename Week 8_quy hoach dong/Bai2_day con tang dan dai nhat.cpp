#include<iostream>

using namespace std;

//bo sung them vao day 2 ptu a[0] = amvocung; a[n+1] = duongvocung

void algorithm(int a[], int L[], int T[], int n){
	a[0] = -2147483648;
	a[n+1] = 2147483647;
	L[n+1] = 1;
	
	for(int i=0; i<=n+1; i++){
		cout<<"a["<<i<<"] = "<<a[i]<<"\n";
	}
	cout<<"\n";
	
	int jmax;
	for(int i=n; i>=0; i--){
		jmax = n+1;
		for(int j=i+1; j<=n+1; j++){
			if(a[j] > a[i] && L[j] > L[jmax]){
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}


//truy vet tren bang phuong an T tim ket qua
void result(int T[], int a[], int n){
	int k = T[0];
	cout<<"Day con: ";
	while(k != n+1){
		cout<<"a["<<k<<"]: "<<a[k]<<" ";
		k = T[k];
	}
}

int main(){
	int n = 10,  a[12], L[12], T[12], k;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	algorithm(a,L,T,n);
	
	result(T,a,n);
	return 0;
}