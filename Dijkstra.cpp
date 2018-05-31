    #include <stdio.h>  
      
    #define M   65535 //�����  
    #define N   5 //������  
      
    //Dijkstra�㷨��������������㵽�����������·��  
    //�������ڽӾ��󡢳�������±ꡢ������顢·��ǰһ���¼  
    void Dijkstra(int Cost[][N], int v0, int Distance[], int prev[])  
    {  
        int s[N];  
        int mindis,dis;  
        int i, j, u;  
        //��ʼ��  
        for(i=0; i<N; i++)  
        {  
            Distance[i] = Cost[v0][i];  
            s[i] = 0;  
            if(Distance[i] == M)  
                prev[i] = -1;  
            else  
                prev[i] = v0;  
        }  
        Distance[v0] = 0;  
        s[v0] = 1; //���v0  
        //�ڵ�ǰ��δ�ҵ����·���Ķ����У�  
        //Ѱ�Ҿ�����̾���Ķ���  
        for(i=1; i < N; i++)  
        {//ÿѭ��һ�Σ����һ�����·��  
            mindis = M;  
            u = v0;  
            for (j=0; j < N; j++) //�������������Ķ���  
                if(s[j]==0 && Distance[j]<mindis)  
                {  
                    mindis = Distance [j];  
                    u = j;  
                } // if����������jѭ������  
            s[u] = 1;  
            for(j=0; j<N; j++) //�޸ĵ���·�����У����ϣ�  
            if(s[j]==0 && Cost[u][j]<M)  
            { //�Ի�δ������·���Ķ���  
                //���������Ķ��� ֱ�������ľ���  
                dis = Distance[u] +Cost[u][j];  
                // ����µ�·�����̣����滻��ԭ·��  
      
                if(Distance[j] > dis)  
                {  
                    Distance[j] = dis;  
                    prev[j] = u;  
                }  
            } // if ����������jѭ������  
        } // iѭ������  
    }  
    // ������·��  
    // ������·��ǰһ���¼����������±ꡢ������±�  
    void PrintPrev(int prev[],int v0,int vn)  
    {  
        int tmp = vn;  
        int i, j;  
        //��ʱ��·��  
        int tmpprv[N];  
        //��ʼ������  
        for(i=0; i < N; i++)  
            tmpprv[i] = 0;  
      
        //��¼������±�  
        tmpprv[0] = vn+1;  
        //�м����ѭ����¼  
        for(i =0, j=1; j < N ;j++)  
        {  
            if(prev[tmp]!=-1 && tmp!=0)  
            {  
                tmpprv[i] = prev[tmp]+1;  
                tmp = prev[tmp];  
                i++;  
            }  
            else break;  
        }  
      
        //���·���������������  
        for(i=N-1; i >= 0; i--)  
        {  
            if(tmpprv[i] != 0)  
            { //�ų�0Ԫ��  
                printf("V%d", tmpprv[i]);  
                if(i)  //�������һ���������   
                    printf("-->");  
            }  
        }  
        printf("-->V%d", vn+1);  
    }  
    //������  
    int main()  
    {  
        //�����������Ķ�������  
        char *Vertex[N]={"V1", "V2", "V3", "V4", "V5"};  
        //�������������ڽӾ���  
        int Cost[N][N]={  
            {0, 10, M, 30, 100},  
            {M, 0, 50, M, M},  
            {M, M, 0, M, 10},  
            {M, M, 20, 0, 60},  
            {M, M, M, M, 0},  
        };  
        int Distance[N]; //�����õ����·������  
        int prev[N];  //�����õ����·��  
        int i;  
        //����Dijkstra�㷨�������󶥵�V1�������������·��  
        //�������ڽӾ��󡢶���������������±ꡢ �������  
        Dijkstra(Cost, 0, Distance, prev);  
        for(i=0; i < N; i++)  
        {  
            //������·������  
            printf("%s-->%s:%d\t", Vertex[0], Vertex[i], Distance[i]);  
            //������·��  
            PrintPrev(prev, 0, i);  
            printf("\n");  
        }  
      
        return 0;  
    }  
