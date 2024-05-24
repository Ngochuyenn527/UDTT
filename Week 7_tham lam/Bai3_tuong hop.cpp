#include<bits/stdc++.h>

using namespace std;

//sx tang dan mang f
void bubbleSort(float a[], int n){
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(a[j] < a[j-1]){
				float temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}

void tuonghop(int n, float s[], float f[]){
	vector<int> schedule;
	float last_finish = 0;
	for(int i=0; i<n; i++){
		if(s[i] >= last_finish){
			schedule.push_back(i);
			last_finish = f[i];
		}
	}
//	for(int s : schedule){
//		cout<<s<<" ";
//	}

//	for(int i=0; i<schedule.size(); i++){
//		cout<<schedule[i]<<" ";
//	}
//	cout<<"\n";
	
	int x[n];
	for(int i=0; i<n; i++){
		x[i] = 0;
	}
	
	for(int s : schedule){
		x[s] = 1;
	}
	
	for(int i=0; i<n; i++){
		cout<<x[i]<<" ";
	}
	
	
}

int main(){
	int n = 5;
	float s[5] = {8,9,10,11,12};
	float f[5] = {8.5,11,11.5,12.5,13};
	bubbleSort(f,n);
	tuonghop(n,s,f);

	return 0;
}
