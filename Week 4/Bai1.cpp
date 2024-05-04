#include<bits/stdc++.h>

using namespace std;

struct Hocsinh{
	string ten;
	string hodem;
	string namsinh;
	string diachi;
};
//sapxep ten
void merge(Hocsinh x[], int l, int m, int r){
	int n1 = m-l+1;
	int n2 = r-(m+1)+1;
	Hocsinh a[n1], b[n2];
	for(int i=0; i<n1; i++){
		a[i] = x[i+l];
	}
	for(int i=0; i<n2; i++){
		b[i] = x[i+m+1];
	}
	
	int i=0, j=0;
	while(i<n1 && j<n2){
		if(a[i].ten <= b[j].ten) x[l++] = a[i++];
		else x[l++] = b[j++];
	}
	while(i < n1) x[l++] = a[i++];
	while(j < n2) x[l++] = b[j++];
}

void mergeSort(Hocsinh x[], int l, int r){
	if(l>=r) return ;
	int m = (l+r)/2;
	mergeSort(x, l, m);
	mergeSort(x, m+1, r);
	merge(x, l, m, r);
}

void displayList(Hocsinh x[], int &n){
	cout<<"----------------------------------------------------------------------------\n";
	cout<<"STT";
	cout<<setw(10)<<"TEN";
	cout<<setw(20)<<"HO DEM";
	cout<<setw(20)<<"NAM SINH";
	cout<<setw(20)<<"DIA CHI"<<endl;
	cout<<"----------------------------------------------------------------------------\n";

	for(int i=0; i<n; i++){
		cout<<i+1;
		cout<<setw(10)<<x[i].ten;
		cout<<setw(20)<<x[i].hodem;
		cout<<setw(20)<<x[i].namsinh;
		cout<<setw(20)<<x[i].diachi<<endl;
	}
}


int search(Hocsinh x[], string &t, int l, int r){
	
	if(l > r) return -1;
	else{
		int m = (l+r)/2;
		if(x[m].ten == t) return m;
		else if(t > x[m].ten) return search(x, t, m+1, r);
		else return search(x, t, l, m);
	}	
}

int main(){
	int n=6;
	Hocsinh x[n] = {
	{"Huyen", "Ngoc", "2004", "Ha Noi"},
	{"Dat", "Bui", "2004", "Ha Noi"},
	{"Doan", "Ngo", "2004", "Quang Ninh"},
	{"Son", "Luong", "2000", "Ha Noi"},
	{"Dai", "Pham", "2005", "HCM"},
	{"Ninh", "Duc", "2006", "Ha Nam"},
	};
	displayList(x,n);
	cout<<"\n";
	
	mergeSort(x, 0, n-1);
	displayList(x,n);
	cout<<"\n";
	
	string m;
	cout<<"Nhap ten cua mot hoc sinh: "; cin>>m;
	if(search(x,m,0,n-1)){
		cout<<"Vi tri ten tim kiem duoc la: "<<search(x,m,0,n-1)<<"\n";
//		cout<<"----------------------------------------------------------------------------\n";
//		cout<<setw(10)<<"TEN";
//		cout<<setw(20)<<"HO DEM";
//		cout<<setw(20)<<"NAM SINH";
//		cout<<setw(20)<<"DIA CHI"<<endl;
//		cout<<"----------------------------------------------------------------------------\n";
		cout<<x[search(x,m,0,n-1)].ten;
		cout<<setw(20)<<x[search(x,m,0,n-1)].hodem;
		cout<<setw(20)<<x[search(x,m,0,n-1)].namsinh;
		cout<<setw(20)<<x[search(x,m,0,n-1)].diachi<<"\n";
	}
		
	return 0;
}
