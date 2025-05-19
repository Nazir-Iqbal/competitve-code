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

// calculating the distance
int y,d;

void dfs(vector<int> adj[],int node,int par,int dis){
	if(dis>d) y = node,d = dis;
	for(int ele : adj[node]){
		if(ele == par) continue;
		dfs(adj,ele,node,dis+1);
	}
}

void solve(){
    int n;cin>>n;
	vector<int> adj[n+1];
	for(int i=0;i<n-1;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(adj,1,-1,0);
	d = 0;
	// cout<<y<<" "<<d<<endl;
	dfs(adj,y,-1,0);
	cout<<d<<endl;
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