//Thap Ha Noi

#include<iostream>

using namespace std;

void chuyen(n, A, B, C){
	if(n==1) cout<<"Chuyen dia"<< A << "---" << C << endl;
	else{
		chuyen(n-1, A, C, B);
		chuyen(1, A, B, C);
		chuyen(n-1, B, A, C);
	}
}
