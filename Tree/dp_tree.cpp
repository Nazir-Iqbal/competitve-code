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

// Subordinates
// void dfs(int node,int par,vector<int> adj[],vector<int> &ans){
//     for(int it : adj[node]){
//         if(it==par) continue;
//         dfs(it,node,adj,ans);
//         ans[node] += ans[it];
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> adj[n+1];
//     for(int i=2;i<=n;i++){
//         int x;cin>>x;
//         adj[i].push_back(x);
//         adj[x].push_back(i);
//     }
//     vector<int> ans(n+1,1);
//     dfs(1,-1,adj,ans);
//     for(int i=1;i<=n;i++) cout<<ans[i]-1<<" ";
//     cout<<endl;
// }

// Choosing Capital for Treeland
void dfs1(int node,int par,vector<pair<int,int>> adj[],int &total,vector<int> &red,vector<int> &dis){
    for(auto it : adj[node]){
        int child = it.first;
        int wt = it.second;
        if(child==par) continue;
        total+=wt;
        red[child]+=wt+red[node];
        dis[child] = 1+dis[node];
        dfs1(child,node,adj,total,red,dis);
    }
}

void dfs2(int node,int par,vector<pair<int,int>> adj[],int &total,vector<int> &red,vector<int> &dis,int &ind,vector<int> &ans){
    int cst = (total - red[node])/*no. of red edges excluding the one on the path*/ + (dis[node]-red[node])/*no. of green edges on the path*/;
    // cout<<node<<" "<<cst<<endl;
    if(cst<ind){
        ans.clear();
        ind = cst;
        ans.push_back(node);
    }else if(cst==ind) ans.push_back(node);
    for(auto it : adj[node]){
        int child = it.first;
        int wt = it.second;
        if(child == par) continue;
        dfs2(child,node,adj,total,red,dis,ind,ans);
    }
}

void solve(){
    int n;cin>>n;
    vector<pair<int,int>> adj[n+1];
    // Need to calculate the no. of up going paths
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }
    int total = 0;
    vector<int> red(n+1,0),dis(n+1,0);
    dfs1(1,-1,adj,total,red,dis);
    // cout<<total<<endl;
    // for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
    // cout<<endl;
    int ind=INT_MAX;
    vector<int> ans;
    dfs2(1,-1,adj,total,red,dis,ind,ans);
    sort(ans.begin(),ans.end());
    cout<<ind<<endl;
    for(int ele : ans) cout<<ele<<" ";
    cout<<endl;
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