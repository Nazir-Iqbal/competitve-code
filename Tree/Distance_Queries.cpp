#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// binary lifting
vector<vector<int>> up;

void pre(int n,vector<int> &parent){
    up = vector<vector<int>> (19,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++){
        up[0][i] = parent[i];
    }

    for(int i=1;i<19;i++){
        for(int j=1;j<=n;j++){
            if(up[i-1][j] != -1)
                up[i][j] = up[i-1][up[i-1][j]];
        }
    }
}

void bfs(int node,int par,int lvl,vector<int> adj[],vector<int> &level,vector<int> &parent){

    queue<vector<int>> q;
    q.push({node,par,lvl});

    while(!q.empty()){
        int node = q.front()[0];
        int par = q.front()[1];
        int lvl = q.front()[2];
        q.pop();
        parent[node] = par;
        level[node] = lvl;

        for(int it : adj[node]){
            if(it == par) continue;
            q.push({it,node,lvl+1});
        }
    }
}

int lca(int u,int v,vector<int> adj[],vector<int> &level,vector<int> &parent){
    if(level[u] > level[v]) swap(u,v);

    int diff = level[v] - level[u];

    for(int i=0;i<19;i++){
        if(diff &(1<<i)){
            v = up[i][v];
        }
    }

    if(u==v) return u;

    for(int i=18;i>=0;i--){
        if(up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }
    }
    return parent[u];
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    int n,q;
    cin>>n>>q;
    vector<int> child[n+1];
    
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        child[u].push_back(v);
        child[v].push_back(u);
    }

    vector<int> level(n+1,0);
    vector<int> parent(n+1,-1);

    bfs(1,-1,1,child,level,parent);
    pre(n,parent);

    while(q--){
        int u,v;
        cin>>u>>v;
        // cout<<u<<" "<<v<<endl;
        int common = lca(u,v,child,level,parent);
        int ans = level[u] + level[v] - 2*level[common];
        cout<<ans<<nline;
    }
    return 0;
}