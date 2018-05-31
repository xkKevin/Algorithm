#include <iostream>
using namespace std ;

const int MAX_VERTEX_NUM = 20 ;
const int INFINIT = 65535 ;

struct VertexNode
{
    char data [ 2 ];
    int op ;
};
struct Graph
{
    VertexNode VertexNode [ MAX_VERTEX_NUM ];
    int ** Matrix ;
    int vertexNum ;
    int edgeNum ;
};

void CreateGraph (Graph & g )
{
     g . Matrix = NULL ;
     int i , j , edgeStart , edgeEnd , weight ;
     cout << "Please input vertex and edge num (vnum enum):" << endl ;
     cin >> g . vertexNum >> g . edgeNum ;
    
     cout << "Please input vertex information (v1) /n note: every vertex info end with Enter" << endl ;
     for (i = 0 ;i < g . vertexNum ;i ++ )
     {
         cin >> g . VertexNode [ i ]. data ; // vertex data info.
     }
     int n = g . vertexNum ;

     // in order to use like D[i][j]
     g . Matrix = new int * [ n];
     for (i = 0 ; i < n; ++ i )
     {
         g . Matrix [ i ] = new int [ n];
     }

     for (i = 0 ; i < n; i ++ )
     {
        for (j = 0 ;j < n; j ++ )
        {
            if (j == i )
                g . Matrix [ i ][ j ] = 0 ;
            else
                g . Matrix [ i ][ j ] = INFINIT ;
        }
     }
     cout << "Please input edge information(start end weight):" << endl ;
     for (j = 0 ; j < g . edgeNum ; j ++ )
     {
         cin >> edgeStart >> edgeEnd >> weight ;

         g . Matrix [ edgeStart - 1 ][ edgeEnd - 1 ] = weight ;
     }
}

void PrintAdjMatrix (const Graph & g )
{
    int i , j , n, weight ;
    n = g . vertexNum ;
    cout << "Adjacent matrix for this graph is: /n " ;
    for (i = 0 ; i < n; i ++ )
    {
        for (j = 0 ; j < n; j ++ )
        {
            weight = g . Matrix [ i ][ j ];
            if (weight == INFINIT )
                cout << "INF /t " ;
            else
            {
                cout << weight << " /t " ;
            }
        }
        cout << " /n " ;
    }
    cout << "The original edge info is: /n " ;
    for (int i = 0 ; i < n; i ++ )
    {
        for (j = 0 ; j < n; j ++ )
        {
            if (g . Matrix [ i ][ j ] < INFINIT && i != j )
                cout << g . VertexNode [ i ]. data << "->" << g . VertexNode [ j ]. data << " /n " ;
        }
    }
}
void DeleteGraph (Graph & g )
{
    if (g . Matrix != NULL )
        delete [] g . Matrix ;
    g . Matrix = NULL ;
}
void PrintShortestMatrix (int ** matrix , int size )
{
    cout << "The shortest path matrix is: /n " ;
    int weight ;
    for (int i = 0 ; i < size ; ++ i )
    {
        for (int j = 0 ; j < size ; ++ j )
        {
            weight = matrix [ i ][ j ];
            if (weight == INFINIT )
                cout << "INF /t " ;
            else
            {
                cout << weight << " /t " ;
            }
        }
        cout << " /n " ;
    }
}
void PrintShortestPath (int ** path , int i , int j )
{
    static int fi = 0 ;
    static int fj = 0 ;
    if (fi == 0 )
    {
        cout << "The shortest path from v" << i + 1 << " to v" << j + 1 << " is: /n " ;
        cout << "v" << i + 1 << "->" ;
        fi = 1 ;
    }
    if (path [ i ][ j ] == INFINIT )
        return ;
    int k = path [ i ][ j ];
    cout << "v" << k + 1 << "->" ;
    PrintShortestPath (path , i , k );
    PrintShortestPath (path , k , j );
    if (fj == 0 )
    {
        cout << "v" << j + 1 << endl ;
        fj = 1 ;
    }
}
void FloydWarshall (Graph & g )
{
    int i , j , k , n;
    n = g . vertexNum ;
    int ** d = new int * [ n];
    int ** path = new int * [ n];

    for (i = 0 ; i < n; ++ i )
    {
        d [ i ] = new int [ n];
        path [ i ] = new int [ n];
    }
    for (i = 0 ; i < n; ++ i )
    {
        for (j = 0 ; j < n; ++ j )
        {
            d [ i ][ j ] = g . Matrix [ i ][ j ];
            path [ i ][ j ] = INFINIT ;
        }
    }

    for (k = 0 ; k < n; k ++ )
    {
        for (i = 0 ; i < n; i ++ )
        {
            for (j = 0 ; j < n; j ++ )
            {
                if (d [ i ][ k ] + d [ k ][ j ] < d [ i ][ j ])
                {
                    d [ i ][ j ] = d [ i ][ k ] + d [ k ][ j ];
                    path [ i ][ j ] = k ;
                }
            }
        }
    }
    PrintShortestMatrix (d , n);
    //input i-1, j-1
    PrintShortestPath (path , 3 , 1 );
    delete [] d ;
    delete [] path ;
}

int main (int argc , const char ** argv )
{
    Graph g ;
    CreateGraph (g );
    PrintAdjMatrix (g );
    FloydWarshall (g );
    DeleteGraph (g );
    return 0 ;
} 
