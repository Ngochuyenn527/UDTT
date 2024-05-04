//ucln
#include<iostream>

using namespace std;

int ucln(int a, int b){
	if(a%b == 0){
		return b;
	}
	else{
		return ucln(b, a%b);
	}
}

int ucln_khu(int a, int b){
	if(a%b == 0){
		return b;
	}
	else{
		int r=a%b;
		while(r != 0){
			a=b;
			b=r;
			r=a%b;
		}
		return b;
	}
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<ucln(a,b)<<"\n";
	cout<<ucln_khu(a,b);
	return 0;
}

