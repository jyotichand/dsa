#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> getOneComponent(bool** edges,int startingVertex,int v,bool* visited)
{
    vector<int> component;
    queue<int> pendingNodes;
    pendingNodes.push(startingVertex);
    visited[startingVertex]=true;
    
    while(!pendingNodes.empty())
    {
        int current=pendingNodes.front();
        pendingNodes.pop();
        component.push_back(current);
        for(int i=0;i<v;i++)
        {
            if(edges[current][i] && !visited[i])
            {
                pendingNodes.push(i);
                visited[i]=true;
            }
        }
    }
    return component;
}

vector<vector<int> > getAllComponents(bool** edges,int v)
{
    vector<vector<int> > result;
    bool* visited= new bool[v]();
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
        vector<int> component=getOneComponent(edges,i,v,visited);
        result.push_back(component);
        }
    }
    delete [] visited;
    return result;
}

int main()
{
    int v,e;
    cin>>v>>e;
    
    bool** edges=new bool*[v];
    
    for(int i=0;i<v;i++)
    {
        edges[i]=new bool[v]();
    }
    for(int i=0,a,b;i<e;i++)
    {
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    
    vector<vector<int> > connectedComponents=getAllComponents(edges,v);
    
    for(int i=0;i<connectedComponents.size();i++)
    {
        sort(connectedComponents[i].begin(),connectedComponents[i].end());
        for(int j=0;j<connectedComponents[i].size();j++)
        {
            cout<< connectedComponents[i][j]<<endl;
        }
        cout<<"\n";
    }
}
