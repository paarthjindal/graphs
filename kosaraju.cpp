#include<bits/stdc++.h>
using namespace std;

void dfs1(vector<bool>&visited, int ele, vector<vector<int>>v1, stack<int>&st){
    visited[ele] = true;

    for(auto ele2: v1[ele]){
        if(visited[ele2] == false){
            dfs1(visited, ele2, v1, st);
        }
    }
    st.push(ele);
}

void dfs2(int ele, vector<bool>&visited, vector<vector<int>>v ){
    visited[ele] = true;

    for(auto ele2: v[ele]){
        if(visited[ele2] == false)
        {
            dfs2(ele2 , visited, v);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<int>>v1(n);
    vector<vector<int>>v2(n);
    for(int i=0;i<e; i++){
        int a,b;
        cin>>a>>b;

        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    stack<int>st;
    vector<bool>visited1(n, false);
    for(int i=0;i<n; i++){
        if(visited1[i] == false){
            dfs1(visited1 , i, v1, st);
        }
    }

    vector<bool>visited2(n, false);
    int count = 0;
    
    while (!st.empty())
    {
        int top = st.top();

        visited2[top] = true;
        for(auto ele: v2[top]){
            dfs2(ele , visited2 , v2);
        }   
        while(st.empty()==false && visited2[st.top()] == true){
            st.pop();
        }
        count +=1;
    }
}