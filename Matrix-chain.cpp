#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > m,s;

int MatrixChainOrder(vector<int> p){
	int n=p.size()-1;
	int i;
	for(i=0;i<n;i++){ 
		m.push_back(vector<int>(n));  
	}
	for(i=0;i<n-1;i++){ 
		s.push_back(vector<int>(n-1));  
	}
	for(i=0;i<n;i++){
		m[i][i]=0;
	} 
	for(int l=1;l<n;l++){
		for(i=0;i<n-l;i++){
			int j=l+i;
			m[i][j]=INT_MAX;
			for(int k=i;k<j;k++){
				int q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j-1]=k+1;
				}
			}
		}
	}
	return m[0][n-1];
}

void PrintOptimalParens(vector<vector<int> > s,int i,int j){
	if(i==j){
		cout<<"A"<<i<<" ";
	}
	else{
		cout<<"(";
		PrintOptimalParens(s,i,s[i-1][j-2]);
		PrintOptimalParens(s,s[i-1][j-2]+1,j);
		cout<<")";
	}
}

int main(){
	vector<int> p;
	int n;
	while(scanf("%d",&n)!=EOF){
		p.push_back(n);
	}
	cout<<"The least times of multiplication: "<<MatrixChainOrder(p)<<endl;
	PrintOptimalParens(s,1,p.size()-1);
	/*
	for(int i=0;i<m.size();i++){
		for(int j=m[i].size()-1;j>=i;j--){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<s.size();i++){
		for(int j=s[i].size()-1;j>=i;j--){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	return 0;
}
