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

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n>2){
//         cout<<"No"<<endl;
//         return;
//     }
//     if(arr[1]-arr[0]>1){
//         cout<<"Yes"<<endl;
//     }else cout<<"No"<<endl;
// }

// Game with Doors
// void solve(){
//     int l,r,L,R;
//     cin>>l>>r;
//     cin>>L>>R;
//     int hsn[110]={0};
//     for(int i=l;i<=r;i++) hsn[i]++;
//     for(int i=L;i<=R;i++) hsn[i]++;
//     int cnt = 0,le=-1,ri=-1;
//     for(int i=1;i<=100;i++){
//         if(hsn[i]>1){
//             cnt++;
//             if(le==-1) le = i;
//             ri = i;
//         }
//     }
//     // for(int i=0;i<10;i++) cout<<hsn[i]<<" ";
//     // cout<<endl;
//     // cout<<le<<" "<<ri<<endl;
//     if(cnt==0){
//         cout<<1<<endl;
//     }else{
//         int ans = ri-le;
//         if(hsn[le-1]>0) ans++;
//         if(hsn[ri+1]>0) ans++;
//         cout<<ans<<endl;
//     }
// }

// Splitting Items
// void solve(){
//     int n,k;cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n,greater<int>());
//     int left = k;
//     for(int i=0;i<n;i++){
//         if(left == 0) break;
//         if(i&1){
//             int diff = arr[i-1]-arr[i];
//             int taken = min(left,diff);
//             left -= taken;
//             arr[i]+= taken;
//         }
//     }
//     int sum1 = 0,sum2 = 0;
//     for(int i=0;i<n;i++){
//         if(i&1) sum2+=arr[i];
//         else sum1+=arr[i];
//     }
//     // for(int ele : arr) cout<<ele<<" ";
//     // cout<<endl;
//     int diff = sum1-sum2;
//     cout<<diff<<endl;
// }

// Colored Portals
// class DisjointSet {
//     vector<int>parent, size;
// public:
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

// int dfs(int node,int par,vector<int> adj[],vector<int> &prefix,vector<bool> &vis){
//     vis[node]= true;
//     if(par!=-1){
//         prefix[node] += prefix[par]+abs(node-par);
//     }
//     for(int ele : adj[node]){
//         if(ele == par) continue;
//         dfs(ele,node,adj,prefix,vis);
//     }
// }

// void solve(){
//     int n,q;cin>>n>>q;
//     vector<string> v(n+1);
//     for(int i=1;i<=n;i++) cin>>v[i];
//     vector<pair<int,pair<int,int>>> edges;
//     map<char,set<int>> mp;
//     for(int i=1;i<=n;i++){
//         mp[v[i][0]].insert(i);
//         mp[v[i][1]].insert(i);
//     }
//     int prev = -1,prev2 = -1;
//     for(auto &ele : mp){
//         for(auto it : ele.second){
//             if(prev == -1 || prev2!=ele.first){
//                 prev = it;
//                 prev2 = ele.first;
//                 continue;
//             }
//             edges.push_back({abs(it-prev),{prev,it}});
//             prev = it;
//         }
//     }
//     sort(edges.begin(),edges.end());
//     // for(auto ele : edges) cout<<ele.first<<" "<<ele.second.first<<" "<<ele.second.second<<endl;
//     DisjointSet dsu(n);
//     vector<int> adj[n+1];
//     for(int i=0;i<edges.size();i++){
//         int u = edges[i].second.first,v = edges[i].second.second;
//         if(dsu.findUPar(u)!=dsu.findUPar(v)){
//             dsu.unionBySize(u,v);
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//     }
//     vector<int> prefix(n+1,0);
//     vector<bool> vis(n+1,0);
//     for(int i=0;i<n;i++){
//         if(!vis[i]) dfs(i,-1,adj,prefix,vis);
//     }
//     while(q--){
//         int a,b;
//         cin>>a>>b;
//         if(dsu.findUPar(a)!=dsu.findUPar(b)){
//             cout<<-1<<endl;
//             continue;
//         }
//         cout<<abs(prefix[a]-prefix[b])<<endl;
//     }
// }

void solve(){
    int n,q;
    cin>>n>>q;
    vector<string> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    map<string,set<int>> mp;
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
		mp[v[i]].insert(i);
	}
	int a,b;
	cin>>a>>b;
	int ans = INT_MAX;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			string temp;
			temp.push_back(v[a][i]),temp.push_back(v[b][j]);
			sort(temp.begin(),temp.end());
			auto it1 = mp[temp].upper_bound(a),it2 = mp[temp].upper_bound(b);
			if(it1!=mp[temp].end()){

			}
			if(it2!=mp[temp].end()){
				
			}
		}
	}
    cout<<ans<<endl;
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