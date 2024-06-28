//tinh tong tat ca cac so trong mang a theo chia de tri
#include<iostream>

using namespace std;

float tong_chiadetri(float a[], int l, int r){
	if(l==r){
		return a[l];
	}
	else{
		int m = (l+r)/2;
		return tong_chiadetri(a,l,m) + tong_chiadetri(a,m+1,r);
	}
}

float tong_dequy(float a[], int n){
	if(n==0){
		return 0;
	}
	else{
		return a[n-1] + tong_dequy(a,n-1);
	}
}

//tinh tong tat ca cac so le trong mang a gom n so nguyen
int tongsole_chiadetri(int a[], int l, int r, int &sum, int &count){
	if(l==r){
		if(a[l]%2 != 0){
			sum+=a[l];
			count++;
		}
	}
	else{
		int m = (l+r) / 2;
		tongsole_chiadetri(a,l,m,sum,count);
		tongsole_chiadetri(a,m+1,r,sum,count);
	}
}

int tongsole_dequy(int a[], int n, int &sum, int &count){
	if(n==0){
		return 0;
	}
	else{
		if(a[n-1]%2 != 0){
			count++;
			sum += a[n-1];
			tongsole_dequy(a,n-1,sum,count);
		} 
		else tongsole_dequy(a,n-1,sum,count);
	}
}

int search_cdt(float a[], float &k, int l, int r){
	if(l==r){
		if(a[l]==k){
			return l;
		}
		else{
			return -1;
		}
	}
	int m =(l+r)/2;
	int x=search_cdt(a,k,l,m);
	int y=search_cdt(a,k,m+1,r);
	if (x>0 ) return x;
	if(y>0) return y;
}

int search_dequy(float a[], int n, float &k){
	if(a[n-1] == k){
		return n-1;
	}
	if(n<0){
		return -1;
	}
	return search_dequy(a,n-1,k);
}


float max_cdt(float x[], int l, int r){
	if(l==r) return x[l];
	int m =(l+r)/2;
	float a = max_cdt(x, l, m);
	float b = max_cdt(x, m+1, r);
	return a>b ? a:b;
}

float max_dequy(float a[], int n){
	if(n==1) return a[0];
	double x = max_dequy(a,n-1);
	return x>a[n] ? x:a[n];
}



int main(){
	int n=10; 
	float a[n] = {1,1,1,1,1,1,1,1,1,1};
	int b[n] = {1,2,1,2,1,2,1,2,1,2};
	
	cout<<tong_chiadetri(a,0,n-1)<<"\n";
	cout<<tong_dequy(a,n)<<"\n";
	
	
	int sum = 0, count = 0;
	tongsole_chiadetri(b,0,n-1,sum,count);
	cout<<sum<<" "<<count<<"\n";
	
	int sum1=0, count1=0;
	tongsole_dequy(b,n,sum1,count1);
	cout<<sum1<<" "<<count1<<"\n";

}
