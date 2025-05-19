#include <bits/stdc++.h>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int x=-1,y=-1,dis = 0;
void dfs1(vector<int> adj[],int node,int par,int d,bool flag){
    if(d>dis){
        if(flag) x=node;
        else y=node;
        dis = d;
    }
    for(int it : adj[node]){
        // cout<<it<<endl;
        if(it==par) continue;
        dfs1(adj,it,node,d+1,flag);
    }
}

void dfs2(vector<int> adj[],int node,int par,int d,vector<int> &dis){
    dis[node] = max(dis[node],d);
    for(int it : adj[node]){
        if(it==par) continue;
        dfs2(adj,it,node,d+1,dis);
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
    if(n==1){
        cout<<0<<endl;
        return;
    }
    dfs1(adj,1,-1,0,1);
    dis = 0;
    dfs1(adj,x,-1,0,0);
    // cout<<x<<" "<<y<<endl;
    vector<int> dis(n+1,0);
    dfs2(adj,x,-1,0,dis);
    dfs2(adj,y,-1,0,dis);
    for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    cout<<endl;
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