#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;\

// binary lifting
vector<vector<int>> up;

void pre(int n,vector<int> &parent){
    up = vector<vector<int>> (16,vector<int>(n,0));
    for(int i=0;i<n;i++){
        up[0][i] = parent[i];
    }

    for(int i=1;i<16;i++){
        for(int j=0;j<n;j++){
            up[i][j] = up[i-1][j];
            if(up[i][j] != -1){
                up[i][j] = up[i-1][up[i][j]];
            }
        }
    }
}

void dfs(int node,int par,int lvl,vector<int> adj[],vector<int> &level,vector<int> &parent){
    parent[node] = par;
    level[node] = lvl;

    for(int it : adj[node]){
        if(it == par) continue;
        dfs(it,node,lvl+1,adj,level,parent);
    }
}

int lca(int u,int v,vector<int> adj[],vector<int> &level,vector<int> &parent){
    if(level[u] > level[v]) swap(u,v);

    int diff = level[v] - level[u];

    for(int i=0;i<16;i++){
        if(diff &(1<<i)){
            v = up[i][v];
        }
    }

    if(u==v) return u;

    for(int i=15;i>=0;i--){
        if(up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }
    }
    
    return parent[u];
}

void solve(){
    int n;cin>>n;
    vector<int> child[n];
    vector<bool> notroot(n,0);
    
    for(int i=0;i<n;i++){
        int m;cin>>m;
        for(int j=0;j<m;j++){
            int v;cin>>v;
            notroot[v] = true;
            child[i].push_back(v);
        }
    }

    int root = 0;
    for(int i=0;i<n;i++){
        if(!notroot[i]){
            root = i;
            break;
        }
    }

    vector<int> level(n,0);
    vector<int> parent(n,-1);

    dfs(root,root,1,child,level,parent);
    pre(n,parent);

    int q;cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v,child,level,parent)<<nline;
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}