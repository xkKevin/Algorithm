#include<iostream>
#include<vector> 
#define N 6 //��ʾ��N������ 
#define MAX 65535
using namespace std;

bool judgeMark (bool mark[]) { //�����нڵ㶼��S�����У��򷵻�true 
	for (int i = 0; i < N; i++) {
		if (mark[i] == 0)
			return false;
	}
	return true;
}

bool DijkstraModify(int edge[][N],int source,int SL[],int SP[]) {
	//soure��ʾԴ�㣬SL[i]���Դ�㵽��i�Žڵ�����·��ֵ��������ΪMAX��SP[i]��Ŵ�Դ�㵽i�ڵ�����·����ǰ���ڵ㣬������Ϊ-1
	bool *mark = new bool[N]; //��ǹ���ֵΪ1���Ľ���ʾ�Ѿ�����S�����У�ֵΪ0�Ľ���ʾ��V-S������
	int *count = new int[N];//count[i] ��ʾ��Դ�㵽�ý��i�����·�������������нڵ�ĸ��� 
	int i;
	for (i = 0;i < N;i++) {
		mark[i] = 0;
		SL[i] = edge[source][i];
		if(SL[i]<MAX) {
			SP[i] = source; //������·����ǰ����
			count[i] = 2; 
		} 
		else SP[i] = -1;
	}
	mark[source] = 1;  //�ȴ�V������ȡ��Դ�㵽S���ϣ�������̾��Ǳ�ǣ� 
	SP[source] = -1;
	int v; //��ֵΪV-S������ SLֵ��С�Ľ�㣬�� SL[v] = min{SL[i]} (i��S-V�����ڣ� 
	bool marked = judgeMark(mark); //�ж����нڵ��Ƿ񶼱���ǣ����ж����нڵ��Ƿ���S������ 
	while(!marked){
		int sl = MAX; 
		for (i = 0;i < N;i++){
			if (mark[i] == 0 && sl > SL[i]) { //ȡ��δ����ǵĽڵ���SLֵ��С�Ľ�㣨Dijkstra�����Ͼ���̰���㷨�� 
				sl = SL[i];
				v = i; 
			} 
		}
		mark[v] = 1; //���ý�����S������ 
		for(i = 0;i < N;i++){ //�����е����ɳڲ��� 
			sl = SL[v] + edge[v][i];
			if (sl < SL[i]){  
				SL[i] = sl;
				SP[i] = v;
				count[i] = count[v] + 1; //��ǰsource�����i�����·����i��ǰ���ڵ�Ϊv
				if (count[i] > N) return false; //���·���Ľڵ������ֵΪN������N˵�����ڸ��� 
				mark[i] = 0; //ͬʱ�ڵ�iҪ�Ż�V-S�����У���Ϊ�ý����ܻ�Ľ������ڵ�����·���� 
			}
		}
		marked = judgeMark(mark); //�ж����нڵ��Ƿ���S�����У����ڣ���������нڵ�����·�����ҵ� 
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
		cout<<"���ڸ���\n";
	}
	return 0;
}

