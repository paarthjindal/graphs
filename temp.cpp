#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

void dfs(vector<vector<int>>& adjList, int start, vector<bool>& visited) {
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            visited[node] = true;
            for (int i = 0; i < adjList[node].size(); i++) {
                int neighbor = adjList[node][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
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


void addedge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjlist(n);
    vector<bool> visited(n, false);
    vector<vector<int>> final;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addedge(adjlist, u - 1, v - 1);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adjlist, i, visited);
            if (i < n - 1 && !visited[i + 1]) {
                final.push_back({i + 1, i + 2});
                addedge(adjlist, i, i + 1);
                count++;
            }
        }
    }

    cout << count << endl;
    for (auto& edge : final) {
        cout << edge[0] << " " << edge[1] << endl;
    }

    return 0;
}
