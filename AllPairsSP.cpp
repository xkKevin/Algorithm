#include<iostream>
#include<vector>
#define N 5 //表示有5个顶点 
#define MAX 65535
using namespace std;

void Floyd_Warshall(int edge[][N]){
	int D[N][N];
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			D[i][j]=edge[i][j];
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				if(D[j][k]>D[j][i]+D[i][k]){
						D[j][k]=D[j][i]+D[i][k];
				}
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(D[i][j]>MAX/2) cout<<"# ";
			else cout<<D[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}

int main(){
	char V[N]={'A','B','C','D','E'};
	int edge[N][N]={
		{0,-1,3,MAX,MAX},
		{MAX,0,3,2,2},
		{MAX,MAX,0,MAX,MAX},
		{MAX,1,5,0,MAX},
		{MAX,MAX,MAX,-3,0}
	};
	Floyd_Warshall(edge);
	return 0;
}
