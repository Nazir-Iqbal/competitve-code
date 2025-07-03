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

int dfs(int node,vector<bool> &vis,vector<int> adj[]){

    vis[node] = 1;
    int len = 1;
    for(int it : adj[node]){
        if(!vis[it]){
            len += dfs(it,vis,adj);
        }
    }
    return len;
}

int calculateMax(int network_nodes,vector<int> network_from, vector<int> network_to,vector<int> frequency){
    int n = network_nodes;
    vector<int> adj[n+1];
    
    for(int i=0;i<n-1;i++){
        int u = network_from[i];
        int v = network_to[i];
        int diff = abs(frequency[v-1]-frequency[u-1]);
        if(diff <= 1){
            int u = network_from[i];
            int v = network_to[i];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
    }

    vector<bool> vis(n+1,0);

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int len = dfs(i,vis,adj)-1;
            ans = max(ans,len);
        }
    }
    return ans;   
}
    

void solve(){
    int n;cin>>n;
    vector<int> network_from(n),network_to(n),frequency(n);
    for(int i=0;i<n-1;i++) cin>>network_from[i];
    for(int i=0;i<n-1;i++) cin>>network_to[i];
    for(int i=0;i<n;i++) cin>>frequency[i];
    cout<<calculateMax(n,network_from,network_to,frequency)<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}