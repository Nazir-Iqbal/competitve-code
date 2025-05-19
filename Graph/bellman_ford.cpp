#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

/*  Function to implement Bellman Ford
*   edges: vector of vectors which represents the graph
*   S: source vertex to start traversing graph with
*   V: number of vertices
*/
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dis(V,1e8);
    dis[S] = 0;
    
    // relaxing the edges V-t times
    for(int i=0;i<V;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dis[u]!=1e8 && dis[u]+wt<dis[v]){
                dis[v] = dis[u]+wt;
            }
        }
    }
    
    // relaxing for V time to check for the negative cylce
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        if(dis[u]!=1e8 && dis[u]+wt<dis[v]) return {-1};
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