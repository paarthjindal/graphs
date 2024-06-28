// to find the minimum distance of all the vertices from a single vertex.

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void dijkstra_algo(int n, int e, vector<vector<pair<int, int>>> v)
{

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push(make_pair(0, 0)); // weight and vertex
    parent[0] = -1;
    dist[0] = 0;
    while (p.empty() == false)
    {
        // int idx = find_min_vertex(visited , dist, n);
        pair<int, int> pi = p.top();
        p.pop();
        visited[pi.second] = true;
        for (auto ele : v[pi.second])
        {
            if (visited[ele.first] == false && (ele.second + pi.first) < dist[ele.first])
            {
                parent[ele.first] = pi.second;
                dist[ele.first] = ele.second + pi.first;
                p.push({dist[ele.first], ele.first});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << parent[i] << " with weight -> " << dist[i] << "\n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> v(n);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    dijkstra_algo(n, e, v);
}