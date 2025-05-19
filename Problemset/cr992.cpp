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

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++){
//         bool flag = true;
//         for(int j=0;j<n;j++){
//             if(i==j) continue;
//             int diff = abs(a[i]-a[j]);
//             if(diff%k==0){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag){
//             cout<<"Yes"<<endl;
//             cout<<i+1<<endl;
//             return;
//         }
//     }
//     cout<<"No"<<endl;
// }

// Paint a Strip
// void solve(){
//     int n;cin>>n;
//     if(n==1){
//         cout<<1<<endl;
//         return;
//     }
//     int st = 1,op=1;
//     while(st<n){
//         op++;
//         st = 2*(st+1);
//         // cout<<st+1<<endl;
//     }
//     cout<<op<<endl;
// }

// Ordered Permutations
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int choices = 1e16;
//     if(n<61) choices = (1ll<<(n-1));
//     if(k>choices){
//         cout<<-1<<endl;
//         return;
//     }
//     k--;
//     vector<int> ans(n,0);
//     int l = 0,r = n-1,cur = 1;
//     vector<int> bits(n-1,0);
//     int sz = 0;
//     while(k){
//         bits[sz] = (k&1);
//         k>>=1;
//         sz++;
//     }
//     reverse(bits.begin(),bits.end());
//     for(int i=0;i<bits.size();i++){
//         // cout<<cur<<" "<<l<<" "<<r<<endl;
//         if(bits[i]) ans[r] = cur,r--;
//         else ans[l] = cur,l++;
//         cur++;
//     }
//     ans[l] = n;
//     for(int &ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// void dfs(int node,int par,vector<int> adj[],vector<int> &ans){
//     for(int &it : adj[node]){
//         if(par == it) continue;
//         if(abs(ans[node]-ans[it])==2) ans[it] = ans[node]-1;
//         dfs(it,node,adj,ans);
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> odd,even;
//     queue<pair<int,int>> q;
//     vector<int> adj[n+1];
//     for(int i=1;i<n;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> vis(n+1,0);
//     q.push({1,1});
//     vis[1] = 1;
//     while(!q.empty()){
//         int node = q.front().first;
//         int dep = q.front().second;
//         q.pop();
//         if(dep&1) odd.push_back(node);
//         else even.push_back(node);
//         for(int &it : adj[node]){
//             if(!vis[it]){
//                 vis[it] = 1;
//                 q.push({it,dep+1});
//             }
//         }
//     }
//     int cnt = 2;
//     vector<int> ans(n+1,0);
//     for(int i=0;i<even.size();i++) ans[even[i]] = cnt,cnt+=2;
//     cnt = 2*n;
//     for(int i=0;i<odd.size();i++) ans[odd[i]] = cnt,cnt-=2;
//     dfs(1,-1,adj,ans);
//     for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
//     cout<<nline;
// }

// Control of Randomness
int mod = 998244353;

void dfs(int node,int par,vector<int> &parent,vector<int> adj[]){
    parent[node] = par;
    for(int &it : adj[node]){
        if(par == it) continue;
        dfs(it,node,parent,adj);
    }
}

// for even steps
int f(int node,int p,vector<int> adj[],vector<int> &par,vector<vector<int>> &dp){
    if(p<0) return 1e9; // steps using the negative coins is not possible
    if(node == 1) return 0;
    if(node == -1) return -1;

    if(dp[node][p] != -1) return dp[node][p];

    // transitions
    int c = adj[node].size(),y = par[par[node]];
    int without = (f(y,p,adj,par,dp) + 2*c)%mod; // without using coins
    int with = (f(y,p-1,adj,par,dp) + 2)%mod; // with using the coins
    return dp[node][p] = min(with,without);
}

void solve(){
    int n,q;cin>>n>>q;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> par(n+1,0);
    dfs(1,-1,par,adj);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    while(q--){
        int x,p;
        cin>>x>>p;
        cout<<1+f(par[x],p,adj,par,dp)<<endl;
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}