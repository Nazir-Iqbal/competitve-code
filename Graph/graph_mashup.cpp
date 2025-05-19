#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// New Year Transportation
// void solve(){
//     int n,t;
//     cin>>n>>t;
//     t--;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int i = 0;
//     while(i<n){
//         // cout<<i<<" "<<arr[i]<<nline;
//         if(i==t){
//             cout<<"Yes"<<nline;
//             return;
//         }
//         i = arr[i] + i;
//     }
//     cout<<"No"<<endl;
// }

// Rumor
// void dfs(int node,vector<int> adj[],vector<int> &vis){
//     vis[node] = true;
//     for(auto it : adj[node]){
//         if(!vis[it]) dfs(it,adj,vis);
//     }
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     vector<pair<int,int>> vp;
//     vector<int> adj[n+1];
//     for(int i=1;i<=m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         // cout<<u<<" "<<v<<nline;
//     }

//     for(int i=1;i<=n;i++){
//         vp.push_back({arr[i],i});
//     }
//     sort(vp.begin(),vp.end());
//     int sum = 0;
//     vector<int> vis(n+1,0);
//     for(int i=0;i<n;i++){
//         int coins = vp[i].first;
//         int node = vp[i].second;
//         if(!vis[node]){
//             sum += coins;
//             dfs(node,adj,vis);
//         }
//     }
//     cout<<sum<<nline;
// }

// News Distribution
// solution using DSU
// class DisjointSet {
// public:
//     vector<int> parent, size;
//     DisjointSet(int n) {
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };


// void solve(){
//     int n,m;
//     cin>>n>>m;
//     DisjointSet ds(n);
//     while(m--){
//         int k;
//         cin>>k;
//         vector<int> p(k);
//         for(int i=0;i<k;i++) cin>>p[i];
//         if(k<2) continue;
//         int st = p[0];
//         for(int i=1;i<k;i++){
//             if(ds.findUPar(st)!=ds.findUPar(p[i])) ds.unionBySize(st,p[i]);
//         }
//     }
//     for(int i=1;i<=n;i++){
//         cout<<ds.size[ds.findUPar(i)]<<" ";
//     }
//     cout<<nline;
// }

// NP-Hard Problem
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> adj[n+1];
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     // finding the bipartitide graph
//     // vector<int> a,b;
//     vector<int> vis(n+1,-1);
//     for(int i=1;i<=n;i++){
//         if(vis[i]==-1){
//             queue<pair<int,int>> q;
//             q.push({i,0});
//             vis[i] = 0;
//             while(!q.empty()){
//                 int u = q.front().first;
//                 int col = q.front().second;
//                 q.pop();
//                 for(auto it : adj[u]){
//                     if(vis[it] == -1){
//                         if(col==0) vis[it] = 1,q.push({it,1});
//                         else vis[it] = 0,q.push({it,0});
//                     }else{
//                         if(vis[u] == vis[it]){
//                             // cout<<u<<" "<<it<<endl;
//                             cout<<-1<<endl;
//                             return;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     int cnt = 0;
//     for(int i=1;i<=n;i++) if(vis[i] == 0) cnt++;
//     cout<<cnt<<endl;
//     for(int i=1;i<=n;i++) if(vis[i] == 0) cout<<i<<" ";
//     cout<<endl;
//     cout<<n-cnt<<endl;
//     for(int i=1;i<=n;i++) if(vis[i] == 1) cout<<i<<" ";
//     cout<<endl;
// }

// Bear and Friendship Condition
// class DisjointSet {
// public:
//     vector<int> parent, size;
//     DisjointSet(int n) {
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> adj[n+1];
//     DisjointSet dsu(n);
//     for(int i=0;i<m;i++){
//         int u,v;cin>>u>>v;
//         dsu.unionBySize(u,v);
//         adj[v].push_back(u);
//         adj[u].push_back(v);
//     }

//     for(int i=1;i<=n;i++){
//         if(adj[i].size()+1!=dsu.size[dsu.parent[i]]){
//             // cout<<i<<" "<<dsu.size[dsu.parent[i]]<<endl;
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Substring
bool topoSort(int V, vector<int> adj[]){
    vector<int> indegree(V+1,0);
    for(int i=1;i<=V;i++){
        for(auto ele : adj[i]) indegree[ele]++;
    }
    queue <int> q;
    for(int i=1;i<=V;i++){
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
    return (cnt==V);
}

void solve(){
    int n,m;
    cin>>n>>m;
    string nodes;
    cin>>nodes;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(!topoSort(n,adj)){
        cout<<-1<<endl;
        return;
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}