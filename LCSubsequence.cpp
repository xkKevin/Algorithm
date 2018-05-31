#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<int> > c;
vector<vector<char> > b; //其中'c'表示公共字符，'u'表示向上，'l'表示向左 

int LCS_Length(string X,string Y){
	int m=X.length();
	int n=Y.length();
	int i;
	for(i=0;i<=m;i++){
		c.push_back(vector<int>(n+1));
	}
	for(i=0;i<m;i++){
		b.push_back(vector<char>(n));
	}
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(X[i-1]==Y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i-1][j-1]='c'; //common
			}
			else {
				if(c[i-1][j]>c[i][j-1]){
					c[i][j]=c[i-1][j];
					b[i-1][j-1]='u'; //up
				}
				else{
					c[i][j]=c[i][j-1];
					b[i-1][j-1]='l'; //up
				}
			}
		}
	}
	return c[m][n];
} 

void Print_LCS(vector<vector<char> > b,string X,int i,int j){
	if(i*j==0) return;
	if(b[i-1][j-1]=='c'){
		Print_LCS(b,X,i-1,j-1);
		cout<<X[i-1];
	}
	else {
		if(b[i-1][j-1]=='u'){
			Print_LCS(b,X,i-1,j);
		}
		else
			Print_LCS(b,X,i,j-1);
	}
	return;
}
int main(){
	string X,Y;
	cin>>X>>Y;
	cout<<"The LCSubsequence length: "<<LCS_Length(X,Y)<<endl;
	Print_LCS(b,X,X.length(),Y.length());
	/*
	for(int i=0;i<c.size();i++){
		for(int j=0;j<c[i].size();j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<b.size();i++){
		for(int j=0;j<b[i].size();j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	return 0;
}
