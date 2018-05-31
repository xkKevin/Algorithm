#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void scheduling(vector<int> jobs){
	sort(jobs.begin(),jobs.end());
	cout<<"调度顺序为：";
	int i,tJob=0,tSum=0;
	for(int i=0;i<jobs.size();i++){
		cout<<jobs[i]<<" ";
		tJob+=jobs[i];
		tSum+=tJob;
	}
	cout<<"\n最小平均完成时间：" <<(float)tSum/jobs.size();
	return; 
}

int main(int argc, char *argv[])
{
	int t;
	vector<int> jobs;
	while(scanf("%d",&t)!=EOF){
		jobs.push_back(t);
	}
	scheduling(jobs);
	return 0;
}

