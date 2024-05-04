//Co n chiec xe tai
#include<bits/stdc++.h>

using namespace std;

struct Xetai{
	string bienso;
	float taitrong;
};

//xac dinh xe tai co trong tai max
int max(Xetai x[], int l, int r){ //tra ve index
	if(l==r) return l;
	int m = (l+r) / 2;
	int a = max(x, l, m); 
	int b = max(x, m+1, r);
	return x[a].taitrong > x[b].taitrong ? a:b;
}

Xetai Max(Xetai x[], int l, int r){ //tra ve Xetai
	if(l==r) return x[l];
	int m = (l+r) / 2;
	Xetai a = Max(x, l, m); 
	Xetai b = Max(x, m+1, r);
	return a.taitrong > b.taitrong ? a:b;
}

// Sap xep tang dan taitrong sd MergeSort
void merge(Xetai x[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-(m+1)+1;
	Xetai a[n1], b[n2];
	
	for(int i=0; i<n1; i++){
		a[i] = x[i+l];
	}
	for(int i=0; i<n2; i++){
		b[i] = x[i +(m+1)];
	}
	
	int i=0, j=0;
	while(i<n1 && j<n2){
		if(a[i].taitrong <= b[j].taitrong) x[l++] = a[i++];
		else x[l++] = b[j++];
	}
	
	while(i < n1) x[l++] = a[i++];
	while(j < n2) x[l++] = b[j++];
}

void mergeSort(Xetai x[], int l, int r){
	if(l >= r) return;
	int m = (l+r) / 2;
	mergeSort(x, l, m);
	mergeSort(x, m+1, r);
	merge(x,l,m,r);
}

void hienthi(Xetai x[], int &n){
	cout<<"STT";
	cout<<setw(20)<<"BIEN SO";
	cout<<setw(20)<<"TAI TRONG";
	cout<<endl;
	for(int i=0; i<n; i++){
		if(x[i].taitrong){
			cout<<i+1;
			cout<<setw(20)<<x[i].bienso;
			cout<<setw(20)<<x[i].taitrong;
			cout<<"\n";
		}
		
	}
}
//Tim vi tri de chen 1 Xetai moi vao list sao cho list not change
// k la vi tri muon chen
//Chen them vao vtri thu 3 <=> i=2, k=3

int insert(Xetai x[], int k, int &n){

	Xetai s = {"99C-999.99", 9.9};
		
	if(k>0 && k<=n){
		for(int i=n-(n-7+1); i>=k-1; i--){
			x[i+1] = x[i];
		}
		x[k-1] = s;
		return 1;
	}
	else return 0;
	
}
int main(){
	int n = 100;
	Xetai x[n] = {
	{"29C-888.24", 1.4}, 
	{"29C-888.64", 2.2}, 
	{"29C-888.45", 6.2}, 
	{"29C-888.85", 1.2}, 
	{"29C-888.34", 1.4}, 
	{"29C-888.87", 1.9}, 
	{"29C-888.35", 4.2}
	
	};
	
	Xetai a = Max(x,0,6);
	cout<<"Xe co trong tai max co bien so = "<<a.bienso<<" va trong tai = "<<a.taitrong<<"\n";

	mergeSort(x, 0, 6);
	hienthi(x,n);
	cout<<"\n";

	insert(x,3,n);
	hienthi(x,n);

	return 0;

}



