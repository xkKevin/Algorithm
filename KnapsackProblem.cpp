#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Goods{
	int goods_id;
	int value;
	int weight;
	float rate;
}Goods;

bool cmp(Goods x,Goods y){
	return x.rate >= y.rate;
}

int* Knapsack_01(Goods *g,int kc,int n){
	int c=kc,i,j; //c表示当前背包剩余容量 
	int *x=new int[n+2]; //最后两项分别表示装入背包的总重量和总价值 
	for(i=0;i<n+2;i++){
		x[i]=0;
	}
	for(i=0,j=0;i<n;i++){
		if(g[i].weight<=c){
			x[j++]=g[i].goods_id;
			c-=g[i].weight;
			x[n]+=g[i].weight;
			x[n+1]+=g[i].value;
		}
	}
	return x;
}

float* Knapsack_Frac(Goods *g,int kc,int n){
	int c=kc,i; //c表示当前背包剩余容量 
	float *x=new float[n+3]; //最后三项分别表示装入背包的总重量、总价值和最后装入背包的物品的百分比 
	for(i=0;i<n+2;i++){
		x[i]=0;
	}
	x[n+2]=1;
	for(i=0;i<n;i++){
		if(g[i].weight<=c){
			x[i]=g[i].goods_id;
			c-=g[i].weight;
			x[n]+=g[i].weight;
			x[n+1]+=g[i].value;
		}
		else break;
	}
	if(i<n){
		x[n-1]=g[i].goods_id;
		x[n+2]=(float)c/g[i].weight;
		x[n]+=c;
		x[n+1]+=g[i].value*x[n+2];
	}
	return x;
}

void print_01(int *x,int n){
	cout<<"(01背包)按顺序装入背包的物品为：";
	int i=0;
	while(x[i]&&i<n){
		cout<<x[i]<<" ";
		i++;
	}
	cout<<"\n背包总重量为："<<x[n]<<endl;
	cout<<"背包总价值为："<<x[n+1]<<endl;
}

void print_Frac(float *x,int n){
	cout<<"(分数背包)按顺序装入背包的物品为：";
	int i=0;
	while(x[i]&&i<n-1){
		cout<<x[i]<<"(1) ";
		i++;
	}
	cout<<x[n-1]<<"("<<x[n+2]<<")";
	cout<<"\n背包总重量为："<<x[n];
	cout<<"\n背包总价值为："<<x[n+1];
}

int main(){
	int n,kc,i;
	cout<<"请输入物品的个数以及背包的容量："<<endl;
	cin>>n>>kc;
	Goods *g=new Goods[n];
	cout<<"请输入这"<<n<<"个物品的价值和重量："<<endl;
	for(i=0;i<n;i++){
		cin>>g[i].value;
	}
	for(i=0;i<n;i++){
		cin>>g[i].weight;
	}
	for(i=0;i<n;i++){
		g[i].goods_id=i+1;
		g[i].rate=(float)g[i].value/g[i].weight;
	}
	sort(g,g+n,cmp);
	int *x=Knapsack_01(g,kc,n);
	float *xx=Knapsack_Frac(g,kc,n);
	print_01(x,n);
	print_Frac(xx,n);
	return 0;
} 
