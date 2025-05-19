#include <bits/stdc++.h>
using namespace std;
// #define int long long

// Function to detect cycle in a directed graph.
// bool dfscycle(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &vispath){
//     vis[node] = 1;
//     vispath[node] = 1;
    
//     // checking for the paths of the children
//     for(int child : adj[node]){
//         if(!vis[child]){
//             if(dfscycle(child,adj,vis,vispath)) return true;
//         }
//         // if the node is again visited in the same path then cycle exist
//         else if(vispath[child]) return true;
//     }
    
//     // backtracking the path due to possiblity of the divergent paths
//     vispath[node] = 0;
//     return false;
// }

// bool isCyclic(int V, vector<int> adj[]) {
//     vector<bool> vis(V,0);
//     vector<bool> vispath(V,0);
//     for(int i=0;i<V;i++){
//         if(dfscycle(i,adj,vis,vispath)) return true;
//     }
//     return false;
// }

// Function to detect cycle in a directed graph using the single visited array.
bool dfscycle(int node,vector<int> adj[],vector<int> &vis){
    vis[node] = 2;
    //vispath[node] = 1;
    
    // checking for the paths of the children
    for(int child : adj[node]){
        if(vis[child]==0){
            if(dfscycle(child,adj,vis)) return true;
        }
        // if the node is again visited in the same path then cycle exist
        else if(vis[child]==2) return true;
    }
    
    // backtracking the path due to possiblity of the divergent paths
    //vispath[node] = 0;
    vis[node] = 1;
    return false;
}

// using the bfs
bool bfsisCyclic(int V, vector<int> adj[]) {
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto ele : adj[i]) indegree[ele]++;
    }
    queue <int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0) q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto &it : adj[node]){
            indegree[it]--;
            // if the indegree becomes zero push it in the queue
            if(indegree[it]==0) q.push(it);
        }
    }
    if(cnt==V) return false;
    return true;
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