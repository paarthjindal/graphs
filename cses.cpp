#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <stdbool.h>
 
using namespace std;
 
// # define int long long  
 
void dfs(vector<vector<long long int> > &adjlist,long long int start,long long int end,long long int length,vector<bool>&visited)
{
    stack<long long int> s;
    // vector<bool> visited(length+1,false);
    s.push(start);
    while(!s.empty())
    {
        long long int node=s.top();
        s.pop();
        
        if(visited[node]==false)
        {
            // cout<<node<<" ";
            visited[node]=true;
            for(long long int i=0;i<adjlist[node].size();i++)
            {
                long long int n=adjlist[node][i];
                
                if(visited[n]==false)
                {
                s.push(adjlist[node][i]);
                }
            }
        }  
    }
    return ;
}
 
void addedge(vector<vector<long long int> >& adjList, long long int u, long long int v)
{
    adjList[u].push_back(v);
}
 
void print(vector<vector<long long int> >& adjList)
{
    for(long long int i=0;i<adjList.size();i++)
    {
        for(long long int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
}
void bfs(vector<vector<long long int> >&adjList,long long int start,long long int end,vector<bool>& visited)
{
    // cout<<"helllo";
 
 
    queue<long long int> q;
    long long int ans=0;
    // vector<bool> visited(adjList.size()+1,false);
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        long long int count=0;
        long long int node=q.front();
        q.pop();
        // cout<<node<<" ";
        for(long long int i=0;i<adjList[node].size();i++)
        {
            long long int n=adjList[node][i];
           
            if(visited[n]==false)
            {
                q.push(n);
                visited[n]=true;
            }
        }
    }
}
 
void addedge1(vector<vector<long long int> >& adjList, long long int u, long long int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
 
int main()
{
    long long int n;
    cin>>n;
    long long int m,k;
    cin>>m;
    vector<vector<long long int> >adjlist(n);
    long long int arr[m][2];
    for (long long int i = 0; i < m; i++)
    {
        // scanf("%d %d", &arr[i][0], &arr[i][1]);
        cin>>arr[i][0];
        cin>>arr[i][1];
        addedge(adjlist, arr[i][0]-1, arr[i][1]-1);
        addedge(adjlist, arr[i][1]-1, arr[i][0]-1);
    }
    bool check=false;
    long long int count=0;
    vector<bool>visited(n);
    long long int temp=1;
    vector<vector<long long int> >final(n);
    for (long long int i = 0; i < n-1; i++)
    {
        if(visited[i+1]==true)
        {
        bfs(adjlist,i,n,visited);

            continue;
        }
        // dfs(adjlist,0,i,n-1,visited);
        bfs(adjlist,i,n,visited);
        visited[i]=true;
        if(visited[i+1]==false)
        {
            // visited[i+1]=true;
           final[count].push_back(temp);
            final[count].push_back(i+2);
            temp=i+2;
            count++; 
        }        
            // addedge(adjlist,i-1,i);
            
            // print(adjlist);  
            // for (long long int i = 0; i < n; i++)
            // {
            //     cout<<visited[i]<< " ";
            // }
             
    //    cout<<endl;
    }
    cout <<count<<endl;
    for (long long int i = 0; i < count; i++)
    {
        for (long long int j = 0; j < 2; j++)
        {
            cout<<final[i][j]<<" ";
        }
        cout<<endl;
    }   
    return 0;
}