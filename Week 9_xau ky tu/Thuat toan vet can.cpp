#include<bits/stdc++.h>

using namespace std;

int indexOf(const char *p, const char *t){
	int m = strlen(p); // xau con
	int n = strlen(t) - m; // xau cha
	for(int i=0; i<=n; i++){
		int j=0;
		while(j<m && t[i+j] == p[j]){
			j++;
		}
		if(j==m){
			return i;
		}
	}
	return -1;
}

int main(){
	char p = 'abc';
	char t = 'xyzabcdef';
	cout<<indexOf(p, t);
	return 0;
}
