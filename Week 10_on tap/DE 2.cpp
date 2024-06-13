//THAM LAM + BOYER

#include<bits/stdc++.h>

using namespace std;

struct Tulanh{
	string tenhsx;
	string cauhinh;
	double gia;
};


//sx tang dan
void sort(Tulanh d[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(d[j].gia < d[j-1].gia){
				Tulanh temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
			}
		}
	}
}

//mergeSort
void merge(Tulanh d[], int l, int m, int r){    //
	int n1 = m - l + 1 ;
	int n2 = r - (m+1) + 1 ;
	Tulanh a[n1], b[n2];             //
	
	for(int i = 0; i < n1 ; i++){
		a[i] = d[i + l];
	}
	for(int i = 0; i < n2 ; i++){
		b[i] = d[i + (m+1)];
	}
	
	int i = 0 , j = 0;
	while(i < n1 && j < n2){ 
		if(a[i].gia <= b[j].gia) d[l++] = a[i++];   //
		else d[l++] = b[j++];
	} 
	while(i < n1) d[l++] = a[i++];
	while(j < n2) d[l++] = b[j++];
}

//mergeSort : sap xep tang dan cac day con
void mergeSort(Tulanh d[], int l, int r){  //
	if(l >= r) return;
	int m = (l+r) / 2;
	mergeSort(d, l, m);
	mergeSort(d, m+1, r);
	merge(d,l,m,r);
}

void thamlam(Tulanh d[], int n, int p){
	int sl = 0; //sl lay duoc
	Tulanh a[10]; int z=0; //ds lay duoc
	
	int i=0;
	while(d[i].gia <= p && i<n){
		p -= d[i].gia;
		a[z] = d[i];
		i++; 
		z++; 
		sl++;
	}
	
	cout<<"So luong Tu lanh mua duoc la: "<<sl<<"\n";
	
	cout<<"---------------------------------------------------\n";
	cout<<"TENHSX";
	cout<<setw(25)<<"CAU HINH";
	cout<<setw(25)<<"GIA BAN"<<endl;
	cout<<"---------------------------------------------------\n";
	for(int i=0; i<z; i++){
		cout<<a[i].tenhsx<<"\t";
		cout<<setw(25)<<a[i].cauhinh<<"\t";
		cout<< fixed << setprecision(0)<<setw(25)<<a[i].gia<<"\n";
	}
	
}


int char_in_string(char x, string p){
	for(int i = p.length()-1; i>=0; i--){
		if(p[i] == x) return i;
	}
	return -1;
}


bool BoyerMooreHorspool(string p, string t){
	int v = p.length(), i=v-1;
	while(i < t.length()){
		int k = v-1;
		while(t[i] == p[k] && k>-1){
			i--;
			k--;
		} 
		if(k < 0){
			return true;
		}
		else{
			int x = char_in_string(t[i], p);
			if(x > p.length()-1) i=i+v;
			else i=i+v-x-1;
		}
	}
	return false;
}

int main(){
	int n=6;
	int tien=12; //gia tien

	Tulanh d[n] = {
				{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 4},
				{"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 5},
				{"DELL", "CPU 2GHz upto 4.5GHz-RAM 32GB-SSD 512GB", 2},
				{"MACBOOK", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 6},
				{"ASUS", "CPU 2.5GHz upto 3.5GHz-RAM 64GB-SSD 512GB", 1},
				{"ASUS", "CPU 2.5GHz upto 3.5GHz-RAM 64GB-SSD 512GB", 3},

			};
			
			
	sort(d,n);
//	mergeSort(d,0,n-1);
	thamlam(d,n,tien);
	
	
	cout<<"---------------------------------------------------\n";
	cout<<"TENHSX";
	cout<<setw(25)<<"CAU HINH";
	cout<<setw(25)<<"GIA BAN"<<endl;
	cout<<"---------------------------------------------------\n";
	
	string p = "RAM 16GB";
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(BoyerMooreHorspool(p, d[i].cauhinh)){
			cout<<d[i].tenhsx<<"\t";
			cout<<setw(25)<<d[i].cauhinh<<"\t";
			cout<< fixed << setprecision(0)<<setw(25)<<d[i].gia<<"\n";
			dem++;
		}
	}
	if(dem != 0){
		cout << "So luong Laptop co thong tin bo nho trong la "<<p<<" la: "<< dem << " lan\n";
	}
	 else{
		cout << "Khong ton tai";
	}
	return 0;		
	
}
