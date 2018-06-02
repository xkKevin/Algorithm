#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define N 9
#define HASHMAX 362880
int factory[]={1,1,2,6,24,120,720,5040,40320};
bool HashTable[HASHMAX];

typedef struct node{  
    int step;
    string state;
}Graph;
  
int Sequence(string s){
	int result=0;
	for(int i=0;i<N-1;i++){
		int count=0;
		for(int j=i+1;j<N;j++){
			if(s[i]>s[j])
				count++;
		}
		result+=count*factory[N-i-1];
	}
	return result;
} 
   
int Search(Graph Begin){   
	queue<Graph> gs;
	gs.push(Begin);
	//cout<<"Sequence(Begin.state):"<<Sequence(Begin.state)<<endl;
	HashTable[Sequence(Begin.state)]=1;
	while(!gs.empty()){
		Graph temp=gs.front();
		gs.pop();
		if(temp.state=="012345678"){
			return temp.step;
		}
		int i=0;
		while(temp.state[i]!='0'){
			i++;
		}
		int row=i/3,col=i%3;
		Graph subg;
		if(row<2){
			subg=temp;
			subg.step++;
			swap(subg.state[i],subg.state[i+3]);
			if(!HashTable[Sequence(subg.state)]){
				HashTable[Sequence(subg.state)]=1;
				gs.push(subg);
			}
		}
		if(row>0){
			subg=temp;
			subg.step++;
			swap(subg.state[i],subg.state[i-3]);
			if(!HashTable[Sequence(subg.state)]){
				HashTable[Sequence(subg.state)]=1;
				gs.push(subg);
			}
		}
		if(col>0){
			subg=temp;
			subg.step++;
			swap(subg.state[i],subg.state[i-1]);
			if(!HashTable[Sequence(subg.state)]){
				HashTable[Sequence(subg.state)]=1;
				gs.push(subg);
			}
		}
		if(col<2){
			subg=temp;
			subg.step++;
			swap(subg.state[i],subg.state[i+1]);
			if(!HashTable[Sequence(subg.state)]){
				HashTable[Sequence(subg.state)]=1;
				gs.push(subg);
			}
		}
	}
	return -1;
}  
  
int main ()  
{   
    int n;
	char c;
	string str[3]={"","",""};
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<9;j++){
			cin>>c;
			str[i]+=c;
		}
	} 
    for(int i=0;i<n;i++){
    	memset(HashTable,0,sizeof(HashTable));
    	Graph Begin={0,str[i]}; 
    	int step=Search(Begin);
    	if(step==-1)
    		cout<<"cannot"<<endl;
    	else cout<<step<<endl;
	}    
    return 0;  
}

