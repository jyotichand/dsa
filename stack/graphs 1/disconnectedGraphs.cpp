#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

void printBFS(int** edges , int n, int sv, bool* visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty())
    {
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(i==currentVertex)
            {
                continue;
            }
            if(edges[currentVertex][i]==1 && !visited)
            {
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
}

void BFS (int** edges,int n)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}


void printDFS(int** edges,int n,int sv,bool* visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue;
        }
        if(edges[sv][i]==1)
        {
            if(visited[i])
            {
                continue;
            }
            printDFS(edges,n,i,visited);
        }
    }
}

void DFS (int** edges, int n)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            printDFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

vector<int>* getDFSPathHelper(int** edges,int v,int start,int end,bool* visited)
{
    if(start==end)
    {
        vector<int> *output=new vector<int>();
        output->push_back(end);
        return output;
    }
    visited[start]=true;
    for(int i=0;i<v;i++)
    {
        if(edges[start][i] && !visited[i])
        {
            vector<int>* smallOutput=getDFSPathHelper(edges,v,i,end,visited);
            if(smallOutput!=NULL)
            {
                smallOutput->push_back(start);
                return smallOutput;
            }
        }
    }
    return NULL;
}

vector<int>* getDFSPath(int** edges,int v,int start,int end)
{
    bool* visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    vector<int>* output=getDFSPathHelper(edges,v,start,end,visited);
    return output;
}

vector<int>* getBFSPath(int** edges,int v,int start,int end)
{
    queue<int> bfsQ;
    bool* visited= new bool[v];
    
    bfsQ.push(start);
    visited[start]=true;
    
    bool pathFound=false;
    
    unordered_map<int,int> parent;
    while(!bfsQ.empty() && !pathFound)
    {
        int front=bfsQ.front();
        bfsQ.pop();
        
        for(int i=0;i<v;i++)
        {
            if(edges[front][i] && !visited[i])
            {
                parent[i]=front;
                bfsQ.push(i);
                visited[i]=true;
                if(i==end)
                {
                    pathFound=true;
                    break;
                }
            }
        }
    }
    delete [] visited;
    
    if(!pathFound)
    {
        return NULL;
    }
    else{
    vector<int>* output= new vector<int>();
    
    int current=end;
    output->push_back(end);
    
    while(current!=start)
    {
        current=parent[current];
        output->push_back(current);
    }
    return output;
    }
}

int main()
{
    int n;
    int e;
    cin>> n >> e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    
   // cout<<"DFS"<<endl;
  //  DFS(edges,n);
    
    cout<<"BFS"<<endl;
    BFS(edges,n);
    
    int start,end;
    cin>>start>>end;
    
    vector<int>* output=getBFSPath(edges,n,start,end);
    
    if(output!=NULL)
    {
        for(int i=0;i<output->size();i++)
        {
            cout<<output->at(i)<<" ";
        }
        delete output;
    }
    else
    {
        cout<<"No path fount"<<endl;
    }
    //delete the visited array and the edges that we had
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    
}


