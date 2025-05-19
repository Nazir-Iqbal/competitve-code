#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// topological sort using the DFS
void topoSort(int node, vector<pair<int,int>> adj[], vector<bool> &vis, stack<int> &st){
    vis[node] = true;
    for(auto &it : adj[node]){
        int v = it.first;
        if(!vis[v]) topoSort(v,adj,vis,st);
    }
    
    st.push(node);
}

    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
    //creating adjacency list for the wt
    vector<pair<int,int>> adj[N];
    for(int i=0;i<M;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }
    
    stack<int> st;
    vector<bool> vis(N,0);
    for(int i=0;i<N;i++){
        if(!vis[i]) topoSort(i,adj,vis,st);
    }
    
    // calculating the distance 
    vector<int> dis(N,1e9);
    // mark the distance of the source node as zero
    dis[0] = 0;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dis[node]+wt < dis[v]){
                dis[v] = dis[node]+wt;
            }
        }
    }
    
    for(int i=0;i<N;i++){
        if(dis[i]==1e9) dis[i] = -1;
    }
    
    return dis;
}


void solve(){
    
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}