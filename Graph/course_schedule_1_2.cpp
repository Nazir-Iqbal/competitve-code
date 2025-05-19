#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
vector<int> findOrder(int N, int P, vector<vector<int>> pr) 
{
    vector<int> adj[N];
  for(int i=0;i<P;i++){
      auto p = pr[i];
      adj[p[0]].push_back(p[1]);
  }
  // uisng the bfs
  vector<int> indegree(N,0);
  for(int i=0;i<N;i++){
      for(auto it : adj[i]){
          indegree[it]++;
      }
  }
  queue<int> q;
  vector<int> order;
  for(int i=0;i<N;i++){
      if(indegree[i]==0) q.push(i);
  }
  while(!q.empty()){
      int node = q.front();
      q.pop();
      order.push_back(node);
      for(auto it : adj[node]){
          indegree[it]--;
          if(indegree[it]==0) q.push(it);
      }
  }
  reverse(order.begin(),order.end());
  if(order.size()==N) return order;
  return {};
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