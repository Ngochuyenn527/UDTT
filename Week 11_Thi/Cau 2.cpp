//DE 1: THAM LAM + QHD;
//DE 2: THAM LAM + BOYER
//DE 3: THAM LAM + Z
//DE 4: THAM LAM + CHON 1 TRONG 2 (BOYER || Z)
#include<bits/stdc++.h>

using namespace std;

struct xekhach{
	string ten;
	int slkhach;
	double gia;
};

//tra ve sl it nhat co the lay, so tien thu duoc la p > m
int thamlam1(xekhach d[], int n, double m, double&p){
	//sort giam dan
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(d[j].gia > d[j-1].gia){
				xekhach temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
			}
		}
	}
	
	int i=0; 
	while(i<n && m>0){
		m-=d[i].gia;
		p+=d[i].gia;
		i++;
	}
	return i;
}

//tinh sl ptu it nhat co the lay ma tong gia tri p bang dung c
int thamlam2(xekhach d[], int n, double m, double&p){
	//sort giam dan
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(d[j].gia > d[j-1].gia){
				xekhach temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
			}
		}
	}
	
	int i=0; 
	int dem=0;
	while(i<n && d[i].gia<=m){
		m-=d[i].gia;
		p+=d[i].gia;
		dem++;
		i++;
	}
	//it nhat
	while(m>0 && i<n){
		i++;
		if(d[i].gia<=m){
			m-=d[i].gia;
			p+=d[i].gia;
			dem++;
		}
	}
	if(m==0){
		return dem;
	}
	else{
		return -1;
	}
}

//tra ve sl nhieu nhat co the lay, so tien thu duoc la p < m
int thamlam3(xekhach d[], int n, double m, double&p){
	//sort tang dan
	for(int i=1; i<=n; i++){
		for(int j=n-1; j>=i; j--){
			if(d[j].gia < d[j-1].gia){
				xekhach temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
			}
		}
	}
	
	int i=0; 
	while(i<n && p+d[i].gia<m){
		p+=d[i].gia;
		i++;
	}
	return i;
}

//tra ve sl, tong gia tien lon nhat
int qdh(xekhach d[], int n, int m, double &t){
	int f[n+1][m+1];
	
	xekhach dnew[n+1];
	dnew[0] = {"A",0,0};
	for(int i=0; i<n; i++){
		dnew[i+1] = d[i];
	}
	
	for(int j=0; j<=m; j++){
		f[0][j] = 0;
//		cout<<f[0][j]<<" ";
	}
	cout<<"\n";
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			f[i][j] = f[i-1][j];
			if(dnew[i].slkhach <= j){
				int temp = dnew[i].gia + f[i-1][j-dnew[i].slkhach];
				if(temp > f[i][j]){
					f[i][j] = temp;
				}
			}
//			cout<<f[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	int i=n,j=m;
	int dem = 0;
	t = f[n][m];
	while(i != 0){
		if(f[i][j] != f[i-1][j]){
			dem++;
			j-=dnew[i].slkhach;
		}
		i--;
	}
	return dem;
}

//tra ve sl va danh sach xe co ten chua chu "An";
int char_in_string(char x, string p){
	for(int i=p.length()-1; i>=0; i--){
		if(p[i] == x) return i;
	}
	return -1;
}

bool boyer(string p, string t){
	int v=p.length(), i=v-1;
	while(i<t.length()){
		int k=v-1;
		while(t[i] == p[k] & k>-1){
			k--;i--;
		}
		if(k<0){
			return true;
		}
		else{
			int x=char_in_string(t[i], p);
			if(x<0) i=i+v;
			else i=i+v-x-1;
		}
	}
	return false;
}

int dem_boyer(xekhach d[], int n, vector<int> &index){
	int dem=0;
	for(int i=0; i<n; i++){
		if(boyer("An",d[i].ten)){
			dem++;
			index.push_back(i);
		}
	}
	return dem;
}


//tra ve sl va danh sach xe co ten chua chu "An";
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

int dem_z(xekhach d[], int n, vector<int>&index){
	int dem=0;
	for(int i=0; i<n; i++){
		if(z_algo("An", d[i].ten)){
			dem++;
			index.push_back(i);
		}
	}
	return dem;
}





int main(){

	int n=5;
	xekhach d[n]={
				{"An nhien",20,5000000},
				{"Binh An",20,4000000},
				{"Thanh Cong",15,3000000},
				{"Hai Yen",10,2000000},
				{"Tuan Tu",10,1000000}
				};

	float m =10000000; //so tien
	int v=45; //cho ngoi
	
	
	
	cout<<"tra ve sl it nhat co the lay, so tien thu duoc la p > m\n";
	double p =0;
	int kq1 = thamlam1(d,n,m,p);
	if(kq1==0){
		cout<<"Khong co xe khach nao duoc su dung";
	}
	else{
		cout<<"So chuyen xe it nhat can sd la: "<<kq1<<"\n";
		cout<<"Tong tien ve thu duoc la p = "<<p<<" lon hon m = "<<m<<"\n";
	}
	
	
	
	cout<<"\ntra ve sl it nhat co the lay ma tong gia tri p bang dung c\n";
	double pp=0;
	int kq3=thamlam2(d,n,m,pp);
	if(kq3 == -1){
		cout<<"Khong co xe khach nao duoc su dung";
	}
	else{
		cout<<"So chuyen xe nhieu nhat can sd la: "<<kq3<<"\n";
		cout<<"Tong tien ve thu duoc la p = "<<pp<<" bang dung so tien m = "<<m<<"\n";
	}
	
	
	
	cout<<"\ntra ve sl nhieu nhat co the lay, so tien thu duoc la p < m\n";
	double ppp=0;
	int kq4=thamlam3(d,n,m,ppp);
	if(kq4 == 0){
		cout<<"Khong co xe khach nao duoc su dung";
	}
	else{
		cout<<"So chuyen xe nhieu nhat can sd la: "<<kq4<<"\n";
		cout<<"Tong tien ve thu duoc la p = "<<ppp<<" bang dung so tien m = "<<m<<"\n";
	}
	
	
	//qhd
	double t;
	int kq2 = qdh(d,n,v,t);
	if(kq2 == 0){
		cout<<"Khong chon duoc chuyen xe nao";
	}
	else{
		cout<<"So cac chuyen xe duoc dua vao nha cho la: "<<kq2<<"\n";
		cout<<"Voi tong tien ve thu duoc la lon nhat la: "<<t<<"\n";
	}
	
	
	
	//BOYER
	vector<int>index;
	int kq5 = dem_boyer(d,n,index);
	if(kq5 ==0){
		cout<<"0 ton tai xe nao";
	}
	else{
		cout<<"Co "<<kq5<<" xe\n";
		cout<<"Cac xe co vi tri la:";
		for(int i=0; i<index.size(); i++){
			cout<<index[i]<<" ";
		}
	}
	cout<<"\n";
	
	
	
	//z
	vector<int>index2;
	int kq6 = dem_z(d,n,index2);
	if(kq6 ==0){
		cout<<"0 ton tai xe nao";
	}
	else{
		cout<<"\nCo "<<kq6<<" xe\n";
		cout<<"Cac xe co thong tin la:";
		for(int i=0; i<kq6; i++){
			cout<<"\n"<<d[index2[i]].ten<<" "<<d[index2[i]].slkhach;
		}
	}
}
