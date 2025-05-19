#include <bits/stdc++.h>
using namespace std;
// #define int long long

// bool dfs(int node,vector<int> &vis,vector<int> adj[],int color){
//     vis[node]=color;
//     for(auto child : adj[node]){
//         if(vis[child]==-1){
//             int ncolor = !color;
//             if(!dfs(child,vis,adj,ncolor)){
//                 return false;
//             }
//         }else if(vis[child]==vis[node]) return false;
//     }
//     return true;
// }

// // solving using the bfs
// bool bfs(int node,vector<int> &vis,vector<int> adj[]){
//     queue<int> q;
//     q.push(node);
//     vis[node]=0;
//     while(!q.empty()){
//         int par = q.front();
//         q.pop();
//         for(int child : adj[par]){
//             if(vis[child]==-1){
//                 vis[child] = !vis[par];
//                 q.push(child);
//             }else if(vis[child]==vis[par]){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// bool isBipartite(int V, vector<int>adj[]){
//     // Code here
//     vector<int> vis(V,-1);
//     for(int i=0;i<V;i++){
//         if(vis[i]==-1){
//             if(!bfs(i,vis,adj)) return false;
//         }
//     }
//     return true;
// }

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