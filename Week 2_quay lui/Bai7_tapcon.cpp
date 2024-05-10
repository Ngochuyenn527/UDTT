#include<iostream>

using namespace std;

int x[100], n=5, k=3, dd[100];
//dd la danh dau so do da duoc ghep vo mang x chua
//neu so do da duoc chon de ghep vo x roi thi gan dd = 1

void Try(int k, int start){
	if(k==0){
		//in tap con hien tai
		for(int i=0; i<n; i++){
			if(dd[i]){
				cout<<i+1<<" ";
			}
		}
		cout<<"\n";
	}
	for(int i=start; i<n; i++){
		dd[i] = 1;
		Try(k-1, i+1);
		dd[i] = 0;
	}
}

int main(){
	Try(k,0);
	return 0;
}

