#include<iostream> 
using namespace std;

typedef struct node{
	int q;
	int edge;
	struct node *nextn;
}node;

typedef struct mul{
	int p,sp;
	int min;
	node *n;
	struct mul *nextm;
}mul;

int ShortestPath(mul *graph,int n){
	mul *g,*gq;
	int q,m;
	graph[0].nextm->min=0;
	for(int i=1;i<n;i++){
		g=graph[i].nextm;
		while(g!=NULL){
			node *nd=g->n;
			while(nd!=NULL){
				gq=graph[i-1].nextm;
				q=nd->q;
				while(gq->p!=q) {
					gq=gq->nextm;
				}
				m=gq->min+nd->edge;
				if(m<g->min){
					g->min=m;
					g->sp=nd->q;
				}
				nd=nd->nextn;
			}
			g=g->nextm;
		}
	}
	return graph[n-1].nextm->min;
}

void print_ShortestPath(mul *graph,int n){
	mul *g=graph[n-1].nextm;
	int q;
	int *sp=new int[n];
	sp[n-1]=graph[n-1].nextm->p;
	for(int i=n-1;i>1;i--){
		sp[i-1]=g->sp; 
		g=graph[i-1].nextm;
		while(g->p!=sp[i-1]){ 
			g=g->nextm;
		}
	}
	sp[0]=graph[0].nextm->p;
	cout<<"最短路径为：\n";
	for(int i=0;i<n;i++){
		cout<<sp[i]<<" ";
	}
	return;
}

mul* Init_Graph(int n){
	int p,q,edge;
	mul *graph=new mul[n];
	cout<<"请按照后继节点、前驱节点、边的顺序输入：\n";
	for(int i=0;i<n;i++){
		cout<<"请输入第"<<i+1<<"段的状态数："<<endl;
		int state_n;
		cin>>state_n;
		mul *g0=&graph[i];
		for(int j=0;j<state_n;j++){
			cout<<"第"<<j+1<<"个状态节点、其前驱节点及边的值：" <<endl;
			scanf("%d %d %d",&p,&q,&edge); 
			mul *g=new mul;
			g->p=p;
			g->sp=0;
			g->min=INT_MAX;
			node *nd=new node;
			nd->q=q;
			nd->edge=edge;
			nd->nextn=NULL;
			g->n=nd;
			while(scanf("%d %d %d",&p,&q,&edge)!=EOF){
				node *nd2=new node;
				nd2->q=q;
				nd2->edge=edge;
				nd2->nextn=NULL;
				nd->nextn=nd2;
				nd=nd2;
			}
			g->nextm=NULL;
			g0->nextm=g;
			g0=g;
		}	
	}
	return graph;
} 

int main(){
	int n;
	cout<<"请输入共有多少段：";
	cin>>n;
	mul *graph=Init_Graph(n);
	cout<<"最短路径的代价值为："<<ShortestPath(graph,n)<<endl;
	print_ShortestPath(graph,n);
	return 0;
}
