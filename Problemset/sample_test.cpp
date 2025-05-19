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

void dfs(vector<pair<int,int>> adj[],int &cnt,int node,int par,int weigh,int &signalSpeed){
    if(weigh%signalSpeed==0) cnt++;
    for(auto ele : adj[node]){
        int v = ele.first;
        int wt = ele.second;
        if(v!=par){
            dfs(adj,cnt,v,node,weigh+wt,signalSpeed);
        }
    }
}

vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
    int n = edges.size()+1;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    vector<int> ans(n,0);
    
    for(int i=0;i<=n;i++){
        
        vector<int> p;
        
        for(auto ele : adj[i]){
            int v = ele.first;
            int wt = ele.second;
            int cnt = 0;
            dfs(adj,cnt,v,i,wt,signalSpeed);
            if(cnt>0) p.push_back(cnt);
        }
        cout<<i<<endl;
        for(auto ele : p) cout<<ele<<" ";
        cout<<endl;
        if(p.size()<2) continue;
        int mul=p[0];
        for(auto j=1;j<p.size();j++){
          ans[i] += (mul*p[j]);
          if(i==1) cout<<mul<<" "<<mul*p[j]<<"*";
          mul+=p[j];
        }
    }
    return ans;
}

void solve(){
  vector<vector<int>> edges;
  int m;cin>>m;
  for(int i=0;i<m;i++){
      int u,v,wt;
      cin>>u>>v>>wt;
      edges.push_back({u,v,wt});
  }

  // for(auto ele : edges) cout<<ele[0]<<" "<<ele[1]<<" "<<ele[2]<<endl;

  int ss;cin>>ss;
  vector<int> ans = countPairsOfConnectableServers(edges,ss);
  for(auto ele : ans) cout<<ele<<" ";
  cout<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}