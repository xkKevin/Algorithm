#include<limits.h>  
#include<iostream> 
#include<memory.h> 
using namespace std;  
void Init_Graph(int N,int k,int** S, int **C)  
{  
    int X;  
    int i,j;  
    int temp=N;  
    cout<<"����ߵĳ��ȣ�����1 2 4 ��ʾ��1 �� 2�ıߵĳ���Ϊ 4��������Ϊ0��ʾ��������"<<endl;  
    cin>>i;  
    while (i!=0)  
    {  
        cin>>j;  
        cin>>C[i][j];  
        cin>>i;  
    }  
    cout<<"����ÿ���׶�����Щ�㣺���룺X 1 2 3��ʾ�ý׶���X���㣬�ֱ�Ϊ1,2,3��"<<endl;  
    for (i=1;i<=k;i++)  
    {  
        cout<<"�����"<<i<<"�׶ε�״̬�ĵ�����";  
        cin>>X;  
        cout<<"��Щ��ֱ�Ϊ��";  
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
    for (i=k-1;i>=1;i--)//�׶�  
    {  
        j=0;//i�׶ε�״̬  
        while (S[i][j]!=0)//״̬  
        {  
            m=0;//i+1�׶ε�״̬  
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
    cout<<"���������ĵ�Ϊ��"<<endl;  
    t=0;  
    result[t]=1;  
    cout<<result[t]<<" ";  
    t=result[t];  
    while (t<N)  
    {  
        cout<<result[t]<<" ";  
        t=result[t];  
    }  
    cout<<endl<<"��̾���Ϊ��";  
    cout<<F[i+1][0]<<endl;  
}  
int main(int argc,char *argv[])  
{  
    int N,k;  
    int i,j;  
    int **C,**S,**F;//C:�ߵĳ��ȣ�S;ÿ���׶ε�״̬��F����¼ÿ���׶ε�״̬�еĵ㵽�յ�ľ���  
    int *result;//�����  
    cout<<"�����ĸ�����";  
    cin>>N;  
    cout<<"����׶�����";  
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
    ���ͼ�Ķ�̬�滮���� 
    �׶Σ�k 
    ״̬��Sk:��ÿ���׶οɹ�ѡ��ĵ��λ�� 
    ���ߣ�u 
    �滮���̣�f(k)=min(f(k+1)+��u�ĳ��ȡ� 
    f(k)��ʾ��k�㵽�յ�����·������ 
    ��ʼֵ��F(k)=0; 
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
