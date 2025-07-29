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

int recur(int node,int par,bool take,vector<int> adj[],vector<vector<int>> &dp){

    if(dp[node][take] != -1) return dp[node][take];

    unordered_map<int,int> mp;
    int sum = 0;
    for(int it : adj[node]){
        if(it == par) continue;
        // cout<<node<<" "<<it<<endl;
        int ans = max(recur(it,node,0,adj,dp),recur(it,node,1,adj,dp));
        mp[it] = ans;
        sum += ans;
    }

    if(!take){
        return dp[node][take] = sum;
    }else{
        int ans = 0;
        for(int it : adj[node]){
            if(it == par) continue;
            int temp = 1 + recur(it,node,0,adj,dp) + (sum - mp[it]);
            ans = max(ans,temp);
        }
        return dp[node][take] = ans;
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
    vector<vector<int>> dp(n+1,vector<int>(2,-1));
    int ans = max(recur(1,-1,0,adj,dp),recur(1,-1,1,adj,dp));
    cout<<ans<<endl;
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