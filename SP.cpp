#include<limits.h>  
#include<iostream> 
#include<memory.h> 
using namespace std;  
void Init_Graph(int N,int k,int** S, int **C)  
{  
    int X;  
    int i,j;  
    int temp=N;  
    cout<<"输入边的长度：输入1 2 4 表示点1 与 2的边的长度为 4：首数字为0表示结束输入"<<endl;  
    cin>>i;  
    while (i!=0)  
    {  
        cin>>j;  
        cin>>C[i][j];  
        cin>>i;  
    }  
    cout<<"输入每个阶段有哪些点：输入：X 1 2 3表示该阶段有X个点，分别为1,2,3："<<endl;  
    for (i=1;i<=k;i++)  
    {  
        cout<<"输入第"<<i<<"阶段的状态的点数：";  
        cin>>X;  
        cout<<"这些点分别为：";  
        for (j=0;j<X;j++)  
        {  
            cin>>S[i][j];  
        }  
    }  
}  
void Plan(int N,int k,int **S,int **F,int** C,int *result)  
{  
    int i,j,t=N;  
    int m;  
    int point;  
    //cout<<S[k][0]<<" ";  
    point=S[k][0];  
    for (i=k-1;i>=1;i--)//阶段  
    {  
        j=0;//i阶段的状态  
        while (S[i][j]!=0)//状态  
        {  
            m=0;//i+1阶段的状态  
            F[i][j]=INT_MAX;  
            if (C[S[i][j]][point]==INT_MAX)  
            {  
                while (S[i+1][m]!=0)  
                {  
                    if (C[S[i][j]][S[i+1][m]]!=INT_MAX)  
                    {  
                        if (F[i][j]>(F[i+1][m]+C[S[i][j]][S[i+1][m]]))  
                        {  
                            F[i][j] = F[i+1][m] + C[S[i][j]][S[i+1][m]];  
                            result[S[i][j]]=S[i+1][m];  
                            t--;  
                        }  
                    }  
                    m++;  
                }  
            }  
            else  
            {  
                while (S[i+1][m]!=0)  
                {  
                    if (F[i][j]>(F[i+1][m]+C[S[i][j]][S[i+1][m]]))  
                    {  
                        F[i][j] = F[i+1][m] + C[S[i][j]][S[i+1][m]];  
                        result[S[i][j]]=S[i+1][m];  
                        t--;  
                    }  
                    m++;  
                }  
            }  
            j++;  
        }  
    }  
    cout<<"符合条件的点为："<<endl;  
    t=0;  
    result[t]=1;  
    cout<<result[t]<<" ";  
    t=result[t];  
    while (t<N)  
    {  
        cout<<result[t]<<" ";  
        t=result[t];  
    }  
    cout<<endl<<"最短距离为：";  
    cout<<F[i+1][0]<<endl;  
}  
int main(int argc,char *argv[])  
{  
    int N,k;  
    int i,j;  
    int **C,**S,**F;//C:边的长度，S;每个阶段的状态；F：记录每个阶段的状态中的点到终点的距离  
    int *result;//输出点  
    cout<<"输入点的个数：";  
    cin>>N;  
    cout<<"输入阶段数：";  
    cin>>k;  
    C=new int*[N+1];  
    //C=(int **)malloc(sizeof(int*)*(N+1));  
    for (i=0;i<N+1;i++)  
    {  
        //C[i]=(int *)malloc(sizeof(int)*(N+1));  
        C[i]=new int[N+1];  
        for (j=0;j<N+1;j++)  
        {  
            C[i][j]=INT_MAX;  
        }  
    }  
    S= new int*[N+1];  
    for (i=0;i<N+1;i++)  
    {  
        S[i]=new int[N+1];  
        memset(S[i],0,sizeof(int)*(N+1));  
    }  
    F=new int *[N+1];  
    for (i=0;i<N+1;i++)  
    {  
        F[i]=new int [N+1];  
        for (j=0;j<N+1;j++)  
        {  
            F[i][j]=0;  
        }  
    }  
    result=new int[N+1];  
    memset(result,0,sizeof(int)*(k+1));  
    Init_Graph(N,k,S,C);  
    /* 
    多段图的动态规划方法 
    阶段：k 
    状态：Sk:即每个阶段可供选择的点的位置 
    决策：u 
    规划方程：f(k)=min(f(k+1)+边u的长度。 
    f(k)表示：k点到终点的最短路径长度 
    初始值：F(k)=0; 
    */  
    Plan(N,k,S,F,C,result);  
    delete []result;  
    for (i=0;i<N+1;i++)  
    {  
        delete []C[i];  
    }  
    delete []C;  
    for (i=0;i<N+1;i++)  
    {  
        delete []S[i];  
    }  
    delete []S;  
    for (i=0;i<N+1;i++)  
    {  
        delete []F[i];  
    }  
    delete []F;  
    return 0;  
}  
