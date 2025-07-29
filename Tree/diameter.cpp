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

// method1 1
// int dis,point;
// void dfs(int node,int par,int d,vector<int> adj[]){
//     if(d > dis) dis = d,point = node;

//     for(int it : adj[node]){
//         if(it == par) continue;
//         dfs(it,node,d+1,adj);
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> adj[n+1];
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
    
//     dfs(1,-1,0,adj);
//     dis = 0;
//     dfs(point,-1,0,adj);

//     cout<<dis<<endl;
// }

// method 2
int ans;
int dfs(int node,int par,vector<int> adj[]){
    int lh = 0,rh = 0;
    for(int it : adj[node]){
        if(it == par) continue;
        int dis = dfs(it,node,adj);
        if(dis>lh){
            rh = lh;
            lh = dis;
        }else if(dis > rh) rh = dis;
    }

    ans = max(ans,lh + rh);
    return 1 + lh;
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
    dfs(1,-1,adj);
    cout<<ans<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();
    return 0;
}