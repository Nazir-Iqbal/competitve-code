#include <bits/stdc++.h>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int y,dis;

void dfs(vector<int> adj[],int node,int par,int d){
    if(d>dis) dis = d,y = node;
    for(int ele : adj[node]){
        if(ele == par) continue;
        dfs(adj,ele,node,d+1);
    }
}

void solve(){
    int n;cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,1,-1,0);
    dis = 0;
    dfs(adj,y,-1,0);
    cout<<dis<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}