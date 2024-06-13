#include<bits/stdc++.h>

using namespace std;

//lay ra vi tri xh dau tien cua T[i] = x trong P
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
			int x = char_in_string(t[i], p);//vi tri xh cua T[i] = x trong P duyet tu cuoi len dau
			cout<<"vi tri xuat hien dau tien cua x la: "<<x<<"\n";
			if(x > p.length()-1) i=i+v; // neu P 0 chua x
			else i=i+v-x-1;
		}
	}
	return false;
}

int main(){
	string t = "mothaihgbabonnamsaubay";
	string p = "namsau";

	bool kq = BoyerMooreHorspool(p,t);
	if(kq) cout << "Q la chuoi con cua chuoi P\n";
	else cout << "Q khong la chuoi con cua chuoi P\n";
	return 0;
	
}
