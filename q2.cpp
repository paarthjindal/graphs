#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
using namespace std;
int main()
{
    // n for no of office m for normal and k for fiber connections
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> lat1(m);
    vector<int> lat2(k);
    vector<vector<int> >mat1(m);
    vector<int> mat2(k);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mat1[i].push_back(a);
        mat1[i].push_back(b);
        lat1.push_back(c);
    }
    for (int i = 0; i < k; i++)
    {
        int a,b;
        cin>>a>>b;
        mat2.push_back(a);
        lat2.push_back(b);
    }
    
    return 0;
}