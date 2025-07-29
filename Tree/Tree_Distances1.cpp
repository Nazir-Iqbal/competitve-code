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

int dfs1(int node,int par,vector<int> adj[],vector<int> &depth){
    int cur = 0;
    for(int it : adj[node]){
        if(it == par) continue;
        cur = max(cur,dfs1(it,node,adj,depth));
    }
    depth[node] = cur;
    return cur + 1;
}

void dfs2(int node,int par,int partial_ans,vector<int> adj[],vector<int> &dis,vector<int> &depth){
    dis[node] = max(depth[node],1+partial_ans);
    int n = adj[node].size();
    vector<int> prefix(n+1,0);
    vector<int> suffix(n+2,0);
    for(int i=1;i<=n;i++){
        int it = adj[node][i-1];
        if(it == par) prefix[i] = max(prefix[i-1],1 + partial_ans);
        else prefix[i] = max(prefix[i-1],1+depth[it]);
    }
    for(int i=n;i>=1;i--){
        int it = adj[node][i-1];
        if(it == par) suffix[i] = max(suffix[i+1],1+partial_ans);
        else suffix[i] = max(suffix[i+1],1+depth[it]);
    }

    // cout<<node<<" "<<partial_ans<<" : ";
    // for(int ele : prefix) cout<<ele<<" ";
    // cout<<endl;

    for(int i=1;i<=n;i++){
        int it = adj[node][i-1];
        if(it == par) continue;
        int child_partial_ans = max(prefix[i-1],suffix[i+1]);
        dfs2(it,node,child_partial_ans,adj,dis,depth);
    }
}

void solve(){
    int n;cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" : ";
    //     for(int ele : adj[i]) cout<<ele<<" ";
    //     cout<<endl;
    // }

    vector<int> depth(n+1,0);
    vector<int> dis(n+1,0);
    dfs1(1,-1,adj,depth);
    dfs2(1,-1,-1,adj,dis,depth);
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