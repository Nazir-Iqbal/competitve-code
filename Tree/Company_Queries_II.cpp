#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// binary lifting
vector<vector<int>> up;
vector<int> level;

void dfs(int node,int par,int lvl,vector<int> child[]){
    level[node] = lvl;
    for(int it : child[node]){
        if(it == par) continue;
        dfs(it,node,lvl+1,child);
    }
}

void pre(int n,vector<int> &parent){
    up = vector<vector<int>> (18,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++) up[0][i] = parent[i];

    for(int i=1;i<18;i++){
        for(int j=1;j<=n;j++){
            if(up[i-1][j]!=-1){
                up[i][j] = up[i-1][up[i-1][j]];
            }
        }
    }
}

int lca(int n,int u,int v){
    if(level[u] > level[v]) swap(u,v);

    int diff = level[v] - level[u];

    // cout<<u<<" "<<v<<endl;
    for(int i=0;i<18;i++){
        if(diff & (1<<i)){
            v = up[i][v];
        }
    }
    if(v == u) return u;

    for(int i=17;i>=0;i--){
        if(up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }
    }

    return up[0][v];
}

void solve(){
    int n,q;cin>>n>>q;
    vector<int> parent(n+1,-1);
    vector<int> child[n+1];
    for(int i=2;i<=n;i++){
        cin>>parent[i];
        child[parent[i]].push_back(i);
    }
    pre(n,parent);

    level = vector<int>(n+1,1);
    dfs(1,-1,1,child);
    // cout<<"*"<<endl;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(n,u,v)<<endl;
    }
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