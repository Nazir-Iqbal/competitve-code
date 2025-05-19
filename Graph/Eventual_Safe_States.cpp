#include <bits/stdc++.h>
using namespace std;
// #define int long long

// solved using the cycle detection method using the dfs
// detecting cycle will not result in the terminal path
// bool dfscycle(int node,vector<int> adj[],vector<bool> &vis,vector<bool>&vispath,vector<bool> &check){
//     vis[node]=1;
//     vispath[node]=1;
//     for(int child : adj[node]){
//         if(!vis[child]){
//             if(dfscycle(child,adj,vis,vispath,check)){
//                 return true;
//             }
//         }else if(vispath[child]){
//             return true;
//         }
//     }
//     vispath[node] = 0;
//     check[node] = 1;
//     return false;
// }

// vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
//     vector<bool> vis(V,0),vispath(V,0),check(V,0);
//     for(int i=0;i<V;i++){
//         if(!vis[i]) dfscycle(i,adj,vis,vispath,check);
//     }
    
//     vector<int> safehouse;
//     for(int i=0;i<V;i++){
//         if(check[i]) safehouse.push_back(i);
//     }
//     return safehouse;
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