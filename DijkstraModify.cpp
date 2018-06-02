#include<iostream>
#include<vector> 
#define N 6 //表示有N个顶点 
#define MAX 65535
using namespace std;

bool judgeMark (bool mark[]) { //若所有节点都在S集合中，则返回true 
	for (int i = 0; i < N; i++) {
		if (mark[i] == 0)
			return false;
	}
	return true;
}

bool DijkstraModify(int edge[][N],int source,int SL[],int SP[]) {
	//soure表示源点，SL[i]存放源点到第i号节点的最短路径值，若无则为MAX。SP[i]存放从源点到i节点的最短路径的前驱节点，若无则为-1
	bool *mark = new bool[N]; //标记过（值为1）的结点表示已经进入S集合中，值为0的结点表示在V-S集合中
	int *count = new int[N];//count[i] 表示从源点到该结点i的最短路径所经过的所有节点的个数 
	int i;
	for (i = 0;i < N;i++) {
		mark[i] = 0;
		SL[i] = edge[source][i];
		if(SL[i]<MAX) {
			SP[i] = source; //存放最短路径的前驱点
			count[i] = 2; 
		} 
		else SP[i] = -1;
	}
	mark[source] = 1;  //先从V集合中取出源点到S集合（这个过程就是标记） 
	SP[source] = -1;
	int v; //其值为V-S集合中 SL值最小的结点，即 SL[v] = min{SL[i]} (i在S-V集合内） 
	bool marked = judgeMark(mark); //判断所有节点是否都被标记，即判断所有节点是否都在S集合中 
	while(!marked){
		int sl = MAX; 
		for (i = 0;i < N;i++){
			if (mark[i] == 0 && sl > SL[i]) { //取出未被标记的节点中SL值最小的结点（Dijkstra本质上就是贪心算法） 
				sl = SL[i];
				v = i; 
			} 
		}
		mark[v] = 1; //将该结点放入S集合中 
		for(i = 0;i < N;i++){ //对所有点做松弛操作 
			sl = SL[v] + edge[v][i];
			if (sl < SL[i]){  
				SL[i] = sl;
				SP[i] = v;
				count[i] = count[v] + 1; //当前source到结点i的最短路径中i的前驱节点为v
				if (count[i] > N) return false; //最短路径的节点数最大值为N，超过N说明存在负环 
				mark[i] = 0; //同时节点i要放回V-S集合中，因为该结点可能会改进其他节点的最短路径。 
			}
		}
		marked = judgeMark(mark); //判断所有节点是否都在S集合中，若在，则表明所有节点的最短路径已找到 
	}
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
	if(DijkstraModify(edge,0,SL,SP)){
		print_ShortestPath(SL,SP,V,0);
	}
	else{
		cout<<"存在负环\n";
	}
	return 0;
}

