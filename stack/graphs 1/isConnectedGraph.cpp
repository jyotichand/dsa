#include<iostream>
using namespace std;

void DFS(bool** edges,int v,bool* visited,int currentVertex)
{
    visited[currentVertex]=true;
    
    for(int i=0;i<v;i++)
    {
        if(edges[currentVertex][i] && !visited[i])
        {
            DFS(edges,v,visited,i);
        }
    }
}

bool isConnected(bool** edges,int v)
{
    bool* visited= new bool[v];
    DFS(edges,v,visited,0);
    
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int v, e;
    cin>>v>>e;
    
    bool**edges = new bool*[v];
    for(int i=0;i<v;i++)
    {
        edges[i]=new bool[v];
        for(int j=0;j<v;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0,a,b;i<e;i++)
    {
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    
    cout<<(isConnected(edges,v)?true:false);
    
    for(int i=0;i<v;++i)
    {
        delete [] edges[i];
    }
    delete [] edges;
}
