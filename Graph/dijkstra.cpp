#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// implementing the dijkstra using the priority queue
// can be implemented using the queue but would take the extra iterations
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dis(V,1e9);
    dis[S] = 0;
    pq.push({0,S});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto &it : adj[node]){
            int child = it[0];
            int dist = it[1];
            if(dis[node]+dist<dis[child]){
                dis[child] = dis[node]+dist;
                pq.push({dis[child],child});
            }
        }
    }
    return dis;
}

// implementing the dijkstra using the set
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>> s;
    vector<int> dis(V,1e9);
    dis[S] = 0;
    s.insert({0,S});
    while(!s.empty()){
        int node = (*s.begin()).second;
        int dist = (*s.begin()).first;
        s.erase({dist,node});
        
        for(auto &it : adj[node]){
            int adjE = it[0];
            int adjW = it[1];
            
            if((dist+adjW)<dis[adjE]){
                // it already existed in the set
                if(dis[adjE]!=1e9) s.erase({dis[adjE],adjE});
                
                dis[adjE] = dist+adjW;
                s.insert({dis[adjE],adjE});
            }
        }
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