#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int countPaths(int n, vector<vector<int>>& roads) {
    
    // intinalizing arrays for calculating the ways and distance
    vector<long long> dis(n,1e18),ways(n,0);
    
    // creating the adjacency list
    int m = roads.size();
    vector<pair<long long,long long>> adj[n];
    
    int mod = 1e9+7;
    
    for(int i=0;i<m;i++){
        long long u,v,wt;
        
        u = roads[i][0];
        v = roads[i][1];
        wt = roads[i][2];
        
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    priority_queue<pair<long long,long long>> pq;
    pq.push({0,0});
    dis[0] = 0;
    ways[0] = 1;
    
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]){
            int adjNode = it.first;
            long long wt = it.second;
            
            if(dis[node]+wt<dis[adjNode]){
                dis[adjNode] = dis[node]+wt;
                ways[adjNode] = ways[node];
                pq.push({-dis[adjNode],adjNode});
            }else if(dis[node]+wt==dis[adjNode]){
                // if we get some other node to reach this distance
                ways[adjNode]=(ways[adjNode]+ways[node])%mod;
            }
            
        }
    }
    
    return ways[n-1];
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