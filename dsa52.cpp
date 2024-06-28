#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;


bool dfs(vector<vector<int> > &adjlist,int start,int end)
{
    stack<int> s;
    vector<bool> visited(end+1,false);
    s.push(start);
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
         if(visited[node]==true)
        {
            cout<<"i am wrong"<<endl;
            return true;
        }
        if(visited[node]==false)
        {
            cout<<node<<" ";
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
    return false;
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



void addedge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    int n;
    scanf("%d", &n);
    int m,k;
    scanf("%d %d", &m, &k);
    vector<vector<int> >adjlist(n);
    int arr[m][2];
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        addedge(adjlist, arr[i][0]-1, arr[i][1]-1);
        addedge(adjlist, arr[i][1]-1, arr[i][0]-1);
    }
    bool check=false;
    for (int i = 0; i < n; i++)
    {
        // check=dfs(adjlist,i,n-1);
        
        if(check==true)
        {
            break;
        }
       cout<<endl;
    }
    
    if(check==true)
    {
        cout<<"present";
    } 
    else
    {
        cout<<"not present";
    }

    
    return 0;
}