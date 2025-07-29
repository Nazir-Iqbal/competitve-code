#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int dfs(int node,int par,vector<int> adj[],vector<int> &sub){
    for(int it : adj[node]){
        if(it == par) continue;
        sub[node] += dfs(it,node,adj,sub);
    }
    return 1 + sub[node];
}

int dfs1(int node,int par,vector<int> adj[],vector<int> &sum,vector<int> &sub){
    int cur = 0;
    for(int it : adj[node]){
        if(it == par) continue;
        cur += dfs1(it,node,adj,sum,sub);
    }
    sum[node] = sub[node] + cur;
    return sum[node];
}

void dfs2(int node,int par,int partial_sum,int partial_sub,vector<int> adj[],vector<int> &ans,vector<int> &sum,vector<int> &sub){
    ans[node] = sum[node] + partial_sum + partial_sub;

    // cout<<node<<" "<<partial_sum<<" "<<partial_sub<<endl;
    for(int it : adj[node]){
        if(it == par) continue;
        int p1 = ans[node] - sum[it] - (sub[it]+1);
        int s1 = sub[node] - sub[it];
        dfs2(it,node,p1,partial_sub+s1,adj,ans,sum,sub);
    }
}

void solve(){
    int n;cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" : ";
    //     for(int ele : adj[i]) cout<<ele<<" ";
    //     cout<<endl;
    // }

    vector<int> sub(n+1,0);
    vector<int> sum(n+1,0);
    vector<int> ans(n+1,0);
    dfs(1,-1,adj,sub);
    dfs1(1,-1,adj,sum,sub);
    dfs2(1,-1,0,0,adj,ans,sum,sub);
    // for(int ele : sum) cout<<ele<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}