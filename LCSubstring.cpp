#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<int> > c;
string sub=""; 

int LCS_Length(string X,string Y){
	int m=X.length();
	int n=Y.length();
	int i;
	for(i=0;i<=m;i++){
		c.push_back(vector<int>(n+1));
	}
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(X[i-1]==Y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				if(c[i][j]>sub.length()){
					int k=0;
					sub=""; 
					while(c[i-k][j-k]){
						sub.insert(0,1,X[i-k-1]);
						k++;
					}
				}
			}
			else {
				c[i][j]=0;
			}
		}
	}
	return sub.length();
} 

int main(){
	string X,Y;
	cin>>X>>Y;
	cout<<"The LCSubstring length: "<<LCS_Length(X,Y)<<endl;
	cout<<"最长公共子串："<<sub<<endl;
	/*
	cout<<"表c的数据内容为：\n";
	for(int i=0;i<c.size();i++){
		for(int j=0;j<c[i].size();j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	return 0;
}
