#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

// the above code will just work for n square 
bool dfs(vector<vector<int> > &adjlist,int start,int end,int length)
{
    stack<int> s;
    vector<bool> visited(length+1,false);
    s.push(start);
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        
        if(visited[node]==false)
        {
            // cout<<node<<" ";
            visited[node]=true;
            for(int i=0;i<adjlist[node].size();i++)
            {
                int n=adjlist[node][i];
                if(n==end)
                {
                    return true;
                }
                if(visited[n]==false)
                {
                s.push(adjlist[node][i]);
                }
            }
        }  
    }
    return false;
}


void order(vector<vector<int> > &adjlist,int start,int end,int length)
{
    stack<int> s;
    vector<bool> visited(length+1,false);
    int count=0;
    int var=start;
    s.push(start);
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        
        if(visited[node]==false)
        {
            // cout<<node<<" ";
            visited[node]=true;
            for(int i=0;i<adjlist[node].size();i++)
            {
                
                int n=adjlist[node][i];
                if(n==end)
                {
                    return ;
                }
                if(visited[n]==false)
                {
                s.push(adjlist[node][i]);
                }
            }
        }  
    }
    return ;
}
void addedge1(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
   adjList[v].push_back(u);
}

void bfs(vector<vector<int> >&adjList,int start,int end,vector<bool>& visited)
{
    vector<vector<int> >final(end+1);

    queue<int> q;
    int ans=0;
    // vector<bool> visited(adjList.size()+1,false);
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int count=0;
        int node=q.front();
        q.pop();
        // cout<<node<<" ";
        for(int i=0;i<adjList[node].size();i++)
        {
            int n=adjList[node][i];
            if(n!=node+1)
            {
                count++;

            }
            if(visited[n]==false)
            {
                q.push(n);
                visited[n]=true;
            }
        }
    }
}

// for directed
void addedge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}
// for undirected


void print(vector<vector<int> >& adjList)
{
    for(int i=0;i<adjList.size();i++)
    {
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int m,k;
    scanf("%d", &m);
    vector<vector<int> >adjlist(n);
    int arr[m][2];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        addedge(adjlist, arr[i][0]-1, arr[i][1]-1);
        addedge(adjlist, arr[i][1]-1, arr[i][0]-1);
    }
    bool check=false;
    int count=0;
    vector<bool>visited(n);
    for (int i = 0; i < n; i++)
    {
        if(visited[i]==true)
        {
            continue;
        }
        bfs(adjlist,i,n,visited);
        if(visited[i+1]==false)
        {
            

        }
        
      
    }
    // cout <<count<<endl;
    // for (int i = 0; i < count; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout<<final[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }   
    return 0;
}