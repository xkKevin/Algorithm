#include<iostream>
#include<vector>
#define N 5 //表示有5个顶点 
#define MAX 65535
using namespace std;

void SingleSourceSP(int edge[][N],int source,int SL[],int SP[]){
	int i,j,v;
	int sl;
	bool mark[N]; //用以标记是否找到从源点到其余各点的最短路径 
	for(i=0;i<N;i++){
		SL[i]=edge[source][i];
		mark[N]=0;
	}
	mark[source]=1; 
	SL[source]=0;
	SP[source]=-1;//存放最短路径的前驱点 
	for(i=1;i<N;i++){
		sl=MAX;
		for(j=0;j<N;j++){
			if(sl>SL[j] && mark[j]==0){
				sl=SL[j];
				v=j;
			}
		}
		mark[v]=1;
		for(j=0;j<N;j++){
			sl=SL[v]+edge[v][j];
			if(sl<SL[j]){
				SL[j]=sl;
				SP[j]=v;
			}
		}
	}
	return;
}

void print_ShortestPath(int SL[],int SP[],char V[],int s){
	int i,j;
	vector<char> p;
	for(i=0;i<N;i++){
		p.clear();
		j=i;
		while(SP[j]!=-1){
			p.push_back(V[j]);
			j=SP[j];
		}
		p.push_back(V[s]);
		cout<<V[s]<<"-->"<<V[i]<<" shorstest cost:"<<SL[i]<<endl;
		cout<<"The Shorstes Path:";
		for(j=p.size()-1;j>=0;j--){
			cout<<p[j]<<" ";
		}
		cout<<endl;
	}
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
	int SL[N],SP[N];
	SingleSourceSP(edge,0,SL,SP);
	print_ShortestPath(SL,SP,V,0);
	return 0;
}
