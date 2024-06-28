#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <stdbool.h>

using namespace std;


void dfs(vector<vector<int> > &adjlist,int start,int end,int length,vector<bool>&visited)
{
    stack<int> s;
    // vector<bool> visited(length+1,false);
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
                
                if(visited[n]==false)
                {
                s.push(adjlist[node][i]);
                }
            }
        }  
    }
    return ;
}

void addedge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

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
void bfs(vector<vector<int> >&adjList,int start,int end,vector<bool>& visited)
{
    // cout<<"helllo";
    // vector<vector<int> >final(end+1);

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
    int temp=1;
    vector<vector<int> >final(n);
    for (int i = 0; i < n-1; i++)
    {
        if(visited[i+1]==true)
        {
            continue;
        }
        // dfs(adjlist,0,i,n-1,visited);
        bfs(adjlist,i,n,visited);
        if(visited[i+1]==false)
        {
            visited[i+1]=true;
           final[count].push_back(i+1);
            final[count].push_back(i+2);
            count++; 
        }        
            // addedge(adjlist,i-1,i);
            
            // print(adjlist);  
            // for (int i = 0; i < n; i++)
            // {
            //     cout<<visited[i]<< " ";
            // }
             
    //    cout<<endl;
    }
    cout <<count<<endl;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }   
    return 0;
}
