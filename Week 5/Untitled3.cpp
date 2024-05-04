#include<bits/stdc++.h>
using namespace std;
struct Chuyenbay{
	string sohieu;
	double giave;
	int soghe;
};

void ktragiave(Chuyenbay s[], int l, int r){
	if(l==r){
		if(s[l].giave > 700000){
			cout<<s[l].sohieu;
		}
	}
	else{
		int m = (l+r) / 2;
		ktragiave(s,l,m);
		ktragiave(s,m+1,r);
	}
	
}

int main(){
	int n=3;
	Chuyenbay s[n] = {
	{"VN005", 2000000, 3}, 
	{"VN002", 600000, 98}, 
	{"VN004", 2000000, 6},
	};
	
	ktragiave(s, 0, n-1);
	return 0;
}