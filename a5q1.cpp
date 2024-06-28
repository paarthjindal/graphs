#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> *adjlist, int *vis, int key)
{
    vis[key] = 1;
    // cout << key;
    for (int i : adjlist[key])
        if (!vis[i])
            dfs(adjlist, vis, i);
}
int call_dfs(vector<int> *adjlist, int *vis, int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(adjlist, vis, i);
            count++;
        }
        else
            continue;
    }
    return count;
}
void print_roads(vector<int> *adjlist, int *vis, int n)
{
    dfs(adjlist, vis, 1);
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(adjlist, vis, i);
            cout << "1 " << i << "\n";
        }
    }
}
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    vector<int> adjlist[n + 1];
    int visarr[n + 1];
    for (int j = 0; j < n + 1; j++)
        visarr[j] = 0;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1;
        cin >> v2;
        adjlist[v1].push_back(v2);
        // swap(v1, v2);
        adjlist[v2].push_back(v1);
    }
    int a = call_dfs(adjlist, visarr, n);
    cout << a-1 << "\n";
    for (int j = 1; j < n + 1; j++)
        visarr[j] = 0;
    print_roads(adjlist, visarr, n);
    // dfs(adjlist, visarr, 1);
    // for (int j = 0; j < n + 1; j++)
    //     cout << visarr[j];
}
