#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// prims algorithm
int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<bool> vis(V,0);
    priority_queue<pair<int,int>> pq;
    // {wt,node}
    pq.push({0,0});
    
    int sum = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        sum-=wt;
        for(auto it : adj[node]){
            int adjnode = it[0];
            int wt = it[1];
            if(!vis[adjnode]) pq.push({-wt,adjnode});
        }
    }
    return sum;
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