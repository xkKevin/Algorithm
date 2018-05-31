#include<iostream>
#include<vector>
#include <algorithm>
#define N 6 //表示有5个顶点 
#define MAX 65535
using namespace std;

bool SingleSourceSP(int edge[][N],int source,int SL[],int SP[]){
	int i,v;
	int sl;
	vector<int> VS;
	for(i=0;i<N;i++){
		VS.push_back(i);
		SL[i]=edge[source][i];
		if(SL[i]<MAX) SP[i]=source;//存放最短路径的前驱点
		else SP[i]=-1;
	}
	VS.erase(find(VS.begin(),VS.end(),source));
	SP[source]=-1;
	int count=0;
	while(!VS.empty()){
		
		for(i=0;i<N;i++){
			cout<<SL[i]<<" ";
		}
		cout<<"\n";
		for(i=0;i<VS.size();i++){
			cout<<VS[i]<<" ";
		}
		cout<<"\n";
		
		sl=MAX;
		for(i=0;i<VS.size();i++){
			if(sl>SL[VS[i]]){
				sl=SL[VS[i]];
				v=i;
			}
		}
		for(i=0;i<N;i++){
			sl=SL[VS[v]]+edge[VS[v]][i];
			if(sl<SL[i]){
				SL[i]=sl;
				SP[i]=VS[v];
				if(find(VS.begin(),VS.end(),i)==VS.end()){
					VS.push_back(i);
				}
			}
		}
		VS.erase(VS.begin()+v);
		if(++count>=3*N) return false;
	}
	cout<<"count:"<<count<<endl;
	return true;
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
		if(SL[i]>MAX/2){
			cout<<"There is no shorstest path from "<<V[s]<<" to "<<V[i]<<endl;
		}
		else{
			cout<<V[s]<<"-->"<<V[i]<<" shorstest cost:"<<SL[i]<<endl;
			cout<<"The Shorstes Path:";
			for(j=p.size()-1;j>=0;j--){
				cout<<p[j]<<" ";
			}
			cout<<endl;
		}
	}
}

int main(){
	char V[6]={'A','B','C','D','E','F'};
	/* 
	int edge[N][N]={
		{0,-1,3,MAX,MAX},
		{MAX,0,3,2,2},
		{MAX,MAX,0,MAX,MAX},
		{MAX,1,5,0,MAX},
		{MAX,MAX,MAX,-3,0}
	};*/
	/*
	int edge[N][N]={
		{0,2,5,6,MAX},
		{MAX,0,MAX,3,MAX},
		{MAX,-1,0,MAX,6},
		{MAX,MAX,-2,0,5},
		{MAX,MAX,MAX,MAX,0}
	};
	int edge[N][N]={
		{0,1,MAX,MAX,MAX},
		{MAX,0,1,MAX,MAX},
		{MAX,MAX,0,MAX,1},
		{-5,MAX,MAX,0,MAX},
		{MAX,MAX,MAX,1,0}
	};
	int edge[N][N]={
		{0,4,5,6,3},
		{-3,0,1,MAX,-2},
		{MAX,MAX,0,MAX,-4},
		{MAX,MAX,MAX,0,-6},
		{MAX,3,MAX,MAX,0},
	};*/
	int edge[N][N]={
		{0,4,5,6,3,7},
		{MAX,0,1,MAX,-2,MAX},
		{MAX,MAX,0,MAX,-4,MAX},
		{MAX,MAX,MAX,0,-6,MAX},
		{MAX,3,MAX,MAX,0,MAX},
		{MAX,MAX,MAX,MAX,-8,0}
	};
	int SL[N],SP[N];
	if(SingleSourceSP(edge,0,SL,SP)){
		print_ShortestPath(SL,SP,V,0);
	}
	else{
		cout<<"存在负环\n";
	}
	return 0;
}
