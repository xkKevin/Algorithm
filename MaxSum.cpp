#include<iostream>
#include<vector>
using namespace std;

vector<int> sum;
int MaxSum(vector<int> x){
	int n=x.size();
	int *c=new int[n+1];
	c[0]=0;
	sum.push_back(0);
	for(int i=1;i<=n;i++){ 
		if(x[i-1]<=0) {
			c[i]=c[i-1];
			int m=sum[i-1]+x[i-1];
			if(m<0) m=0;
			sum.push_back(m);
		}
		else {
			if(c[i-1]>sum[i-1]+x[i-1]){
				c[i]=c[i-1];
				sum.push_back(sum[i-1]+x[i-1]);
			}
			else{
				c[i]=sum[i-1]+x[i-1];
				sum.push_back(c[i]);
			}
		}
	}
	cout<<"c表：  ";
	for(int i=1;i<=n;i++)
		cout<<c[i]<<" ";
	cout<<endl<<"sum表：";
	for(int i=1;i<=n;i++)
		cout<<sum[i]<<" ";
	cout<<endl;
	int result=c[n];
	delete[] c;
	return result;
}

void Print_Max_Sequence(vector<int> x,int max){
	int n=sum.size();
	while(sum[--n]!=max);
	int i=n;
	while(sum[--i]>0);
	cout<<"最大和子序列为："; 
	while(i<n){
		cout<<x[i++]<<" ";
	}
	return;
}

//优化算法 (不需要借助表 c、sum) 
/*
int MaxSum(vector<int> x){
	int maxSum=0,sum=0;  
    for(int i=0;i<x.size();i++){  
        sum+=x[i];  
        if(sum>maxSum){  
            maxSum=sum;  
        }else if(sum<0){  
            sum=0;  
        }  
    }
    return maxSum;
}
*/

int main(){
	vector<int> x;
	int n;
	while(scanf("%d",&n)!=EOF){
		x.push_back(n);
	}
	int max=MaxSum(x);
	cout<<"The Max Sum is: "<<max<<endl;
	Print_Max_Sequence(x,max);
	return 0;
}
