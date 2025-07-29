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
//     int x;cin>>x;
//     int num = 9;
//     while(x){
//         num = min(num,x%10);
//         x/=10;
//     }
//     cout<<num<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];

//     int ans = 0;
//     for(int i=0;i<n-k+1;i++){
//         if(arr[i] == 0){
//             bool flag = true;
//             for(int j=i;j<i+k;j++){
//                 if(arr[j] == 1){
//                     i = j;
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag){
//                 ans++;
//                 i+=k;
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int cur = arr[k-1];
//     sort(arr,arr+n);
//     int water = 1;
//     for(int i=0;i<n;i++){
//         if(arr[i]<=cur) continue;
//         int diff1 = arr[i]-cur;
//         int diff2 = cur-water+1;
//         // cout<<arr[i]<<" "<<cur<<" "<<water<<endl;
//         if(diff2<diff1){
//             cout<<"No"<<endl;
//             return;
//         }
//         water += diff1;
//         cur += diff1;
//     }
//     cout<<"Yes"<<endl;
// }

// vector<pair<int, int>> merge_intervals(vector<pair<int, int>> &intervals) {
//     if (intervals.empty()) return {};

//     vector<pair<int, int>> merged;
//     merged.push_back(intervals[0]);

//     for (int i = 1; i < intervals.size(); i++) {
//         auto &last = merged.back();
//         int curr_start = intervals[i].first;
//         int curr_end = intervals[i].second;

//         if (curr_start <= last.second) {
//             last.second = max(last.second, curr_end);
//         } else {
//             merged.push_back(intervals[i]);
//         }
//     }

//     return merged;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<pair<int,int>> vp;
//     for(int i=0;i<n;i++){
//         int l,r,real;
//         cin>>l>>r>>real;
//         vp.push_back({l,real});
//     }
//     sort(vp.begin(),vp.end());
//     vector<pair<int,int>> merge = merge_intervals(vp);
//     // for(auto ele : merge) cout<<ele.first<<" "<<ele.second<<endl;
//     int ans = k;
//     for(int i=0;i<merge.size();i++){
//         if(merge[i].first<=ans) ans = max(merge[i].second,ans);
//     }
//     cout<<ans<<endl;
// }
// long long gcd(long long a, long long b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

// void solve(){
//     int n;cin>>n;
//     int arr1[n],arr2[n];
//     for(int i=0;i<n;i++) cin>>arr1[i];
//     for(int i=0;i<n;i++) cin>>arr2[i];
//     int num = arr2[0];
//     for(int i=0;i<n;i++){
//         if(gcd(arr1[i],arr2[i])!=num){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         int g = gcd(arr1[i], arr2[i]);
        
//         v[i] = (arr1[i] / g) * arr2[i];
//     }
//     vector<int> v1(n,0),v2(n,0);
//     v1[0] = v[0];
//     v2[n-1] = v[n-1];
//     for(int i=1;i<n;i++){
//         int num = gcd(v1[i-1],v[i]);
//         v1[i] = (num);
//     }
//     for(int i=n-2;i>=0;i--){
//         int num = gcd(v2[i+1],v[i]);
//         v2[i] = (num);
//     }

//     for(int i=0;i<n;i++){
//         if(v1[i] != arr1[i] || v2[i] != arr2[i]){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// square root decompostion
// void dfs(int node, int par,vector<int> &color,vector<vector<pair<int,int>>> &adj,int &cost,vector<bool> &heavy,int root){
//     for(auto ele : adj[node]){
//         if(ele.first == par) continue;
//         int it = ele.first;
//         int wt = ele.second;
//         if(color[node] != color[it]) cost += wt;
//         dfs(it,node,color,adj,cost,heavy,root);
//     }
//     if(adj[node].size() > root){
//         heavy[node] = 1;
//         // cout<<node<<"*"<<endl;
//     }
// }

// void dfs2(int node,int par,vector<vector<pair<int,int>>> &adj,vector<vector<pair<int,int>>> &hadj,vector<bool> &heavy,vector<int> &color,int n,map<pair<int,int>,int> &mp){
//     for(int node = 1;node<=n;node++){
//         for(auto ele : adj[node]){
//             int it = ele.first;
//             int wt = ele.second;
//             if(heavy[node]){
//                 // cout<<node<<" "<<it<<endl;
//                 // hadj[node].second[color[it]]+=wt;
//                 mp[{node,color[it]}] += wt;
//             }
//             if(heavy[it]) hadj[node].push_back({it,wt});
//         }
//     }
// }

// void change(int node,int x,vector<int> &color,vector<vector<pair<int,int>>> &hadj,int &cost,vector<bool> &heavy,vector<vector<pair<int,int>>> &adj,map<pair<int,int>,int> &mp){
//     if(heavy[node]){
//         // color[node] = x;
//         cost += mp[{node,color[node]}];
//         cost -= mp[{node,x}];
    
//     }else{
//         for(auto ele : adj[node]){
//             int it = ele.first;
//             int wt = ele.second;
//             if(color[it]==color[node] && color[it]!=x) cost += wt;
//             else if(color[it]!=color[node] && color[it]==x) cost-=wt;
//         }
//     }

//     // root(n)
//     for(auto ele : hadj[node]){
//         int it = ele.first;
//         int wt = ele.second;
//         // cout<<node<<" "<<it<<" "<<wt<<endl;
//         mp[{it,color[node]}] -= wt;
//         mp[{it,x}] += wt;
//     }
//     color[node] = x;
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     vector<int> color(n+1,0);
//     for(int i=1;i<=n;i++) cin>>color[i];
//     vector<vector<pair<int,int>>> adj(n+1);
//     int root = sqrt(n);
//     vector<bool> heavy(n+1,0);

//     for(int i=0;i<n-1;i++){
//         int u,v,c;
//         cin>>u>>v>>c;
//         adj[u].push_back({v,c});
//         adj[v].push_back({u,c});
//     }
//     int cost = 0;

//     dfs(1,-1,color,adj,cost,heavy,root);
//     // cout<<cost<<endl;

//     vector<vector<pair<int,int>>> hadj(n+1);
//     map<pair<int,int>,int> mp;

//     dfs2(1,-1,adj,hadj,heavy,color,n,mp);


//     while(q--){
//         int v,x;
//         cin>>v>>x;
//         change(v,x,color,hadj,cost,heavy,adj,mp);
//         cout<<cost<<endl;
//     }
// }

void dfs(int node,int par,vector<pair<int,int>> adj[],int &cost,unordered_map<int,int> hadj[],vector<int> &color,vector<pair<int,int>> &parent){
    for(auto ele : adj[node]){
        int it = ele.first;
        int wt = ele.second;
        if(it == par){
            // cout<<node<<" "<<it<<endl;
            parent[node] = {par,wt};
            continue;
        }
        hadj[node][color[it]] += wt;
        if(color[node]!=color[it]) cost += wt;
        dfs(it,node,adj,cost,hadj,color,parent);
    }
}

void change(int v,int x,vector<pair<int,int>> adj[],int &cost,unordered_map<int,int> hadj[],vector<int> &color,vector<pair<int,int>> &parent){
    cost += hadj[v][color[v]];
    cost -= hadj[v][x];
    // cout<<cost<<endl;
    int par =  parent[v].first;
    int wt = parent[v].second;
    if(par != -1){
        // cout<<v<<" "<<par<<" "<<wt<<endl;
        if(color[v] == color[par] && x != color[par]) cost += wt;
        else if(color[v]!=color[par] && x == color[par]) cost -= wt;
        hadj[par][color[v]] -= wt;
        hadj[par][x] += wt;
    }
    color[v] = x;
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> color(n+1);
    for(int i=1;i<=n;i++) cin>>color[i];
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    unordered_map<int,int> hadj[n+1];
    vector<pair<int,int>> parent(n+1,{-1,0});
    int cost = 0;
    dfs(1,-1,adj,cost,hadj,color,parent);
    // cout<<cost<<endl;
    while(q--){
        int v,x;
        cin>>v>>x;
        change(v,x,adj,cost,hadj,color,parent);
        cout<<cost<<endl;
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