//tinh r la soluong LAPTOP co thong tin bo nho trong la "RAM 16GB"
//tinh s va t la soluong va danhsach sd o cung loai "SSD"
#include<bits/stdc++.h>

using namespace std;

struct Laptop{
	string tenhsx;
	string cauhinh;
	double giaban;
};

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
	int n=5;
	Laptop d[n] = {
				{"HP", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
				{"ACER", "CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB", 12000000},
				{"DELL", "CPU 2GHz upto 4.5GHz-RAM 32GB-SSD 512GB", 15000000},
				{"MACBOOK", "CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB", 15000000},
				{"ASUS", "CPU 2.5GHz upto 3.5GHz-RAM 64GB-SSD 512GB", 15000000},
			};
			
	string p = "RAM 16GB";
	
	int dem = 0;
	for(int i = 0; i < n; i++){
		if(BoyerMooreHorspool(p, d[i].cauhinh)){
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
