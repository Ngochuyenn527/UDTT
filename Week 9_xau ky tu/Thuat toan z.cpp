#include<bits/stdc++.h>

using namespace std;

bool z_algo(string p, string t){
	string s = p + "$" + t;
	vector<int>z(s.length());
	int n = s.length(), l=0, r=0;
	z[0] = n;
	for(int i=1; i<n; i++){
		if(i>r){
			l=r=i;
			while(r<n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}
		else if(z[i-l] < r-i+1){
			z[i] = z[i-l];
		}
		else{
			l=i;
			while(r<n && s[r-l] == s[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}
	}
	for(int i = p.length()+1; i<s.length(); i++){
		if(z[i] == p.length()){
			return true;
		}
	}
	return false;
}



int main(){
	string p = "mot";
	string q ="mothaibabon";
	if(z_algo(p,q)){
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
}

