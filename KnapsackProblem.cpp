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
	int c=kc,i,j; //c��ʾ��ǰ����ʣ������ 
	int *x=new int[n+2]; //�������ֱ��ʾװ�뱳�������������ܼ�ֵ 
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
	int c=kc,i; //c��ʾ��ǰ����ʣ������ 
	float *x=new float[n+3]; //�������ֱ��ʾװ�뱳�������������ܼ�ֵ�����װ�뱳������Ʒ�İٷֱ� 
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
	cout<<"(01����)��˳��װ�뱳������ƷΪ��";
	int i=0;
	while(x[i]&&i<n){
		cout<<x[i]<<" ";
		i++;
	}
	cout<<"\n����������Ϊ��"<<x[n]<<endl;
	cout<<"�����ܼ�ֵΪ��"<<x[n+1]<<endl;
}

void print_Frac(float *x,int n){
	cout<<"(��������)��˳��װ�뱳������ƷΪ��";
	int i=0;
	while(x[i]&&i<n-1){
		cout<<x[i]<<"(1) ";
		i++;
	}
	cout<<x[n-1]<<"("<<x[n+2]<<")";
	cout<<"\n����������Ϊ��"<<x[n];
	cout<<"\n�����ܼ�ֵΪ��"<<x[n+1];
}

int main(){
	int n,kc,i;
	cout<<"��������Ʒ�ĸ����Լ�������������"<<endl;
	cin>>n>>kc;
	Goods *g=new Goods[n];
	cout<<"��������"<<n<<"����Ʒ�ļ�ֵ��������"<<endl;
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
