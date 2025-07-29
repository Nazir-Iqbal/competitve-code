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
//     string s;cin>>s;
//     int n = s.size();
//     int one = 0;
//     for(int i=0;i<n;i++){
//         if(s[i] == '1') one++;
//     }
//     cout<<one<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//     }
//     for(int i=1;i<=n;i++){
//         int left = i-1;
//         int right = n-i;
//         if(arr[i]<=max(2*left,2*right)){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++) cin>>v[i];
//     // cout<<v.size()<<endl;
//     int ans = accumulate(v.begin(),v.end(),0ll);
//     while(v.size()>1){
//         vector<int> temp1,temp2;
//         for(int i=1;i<v.size();i++) temp1.push_back(v[i]-v[i-1]);
//         int sum1 = accumulate(temp1.begin(),temp1.end(),0ll);
//         reverse(v.begin(),v.end());
//         for(int i=1;i<v.size();i++) temp2.push_back(v[i]-v[i-1]);
//         int sum2 = accumulate(temp2.begin(),temp2.end(),0ll);
//         if(sum1 > sum2){
//             ans= max(ans,sum1);
//             v = temp1;
//         }else{
//             ans = max(ans,sum2);
//             v = temp2;
//         }
//     }
//     cout<<ans<<endl;
// }

// void assignDFS(int node,int par,vector<int> &value,vector<pair<int,int>> &nodes,vector<int> adj[]){
//     int val = INT_MIN;
//     for(int ele : adj[node]){
//         if(ele == par) continue;
//         assignDFS(ele,node,value,nodes,adj);
//         val = max(value[ele],val);
//     }

//     int l = nodes[node].first;
//     int r = nodes[node].second;
    
//     // cout<<node<<" "<<l<<" "<<r<<endl;

//     if(val>=l && val<=r){
//         value[node] = val;
//     }else if(val<l){
//         value[node] = l;
//     }else{
//         value[node] = r;
//     }
// }

// void dfs(int node,int par,vector<int> &value,vector<int> adj[],int &cost){
//     for(int ele : adj[node]){
//         if(ele == par) continue;
//         dfs(ele,node,value,adj,cost);
//         if(value[ele] > value[node]){
//             cost += (value[ele]-value[node]);
//         }
//     }

// }

// void solve(){
//     int n;cin>>n;
//     vector<pair<int,int>> nodes(n+1);
//     for(int i=1;i<=n;i++){
//         int l,r;
//         cin>>l>>r;
//         nodes[i] = {l,r};
//     }
//     vector<int> adj[n+1];
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     vector<int> value(n+1,-1);
//     assignDFS(1,-1,value,nodes,adj); // rooted at 1

//     // for(int ele : value) cout<<ele<<" ";
//     // cout<<endl;

//     int cost = 0;
//     dfs(1,-1,value,adj,cost); // rootes at 1
//     cout<<value[1] + cost<<endl;
// }

// The Game (Easy Version)
void dfs(int node,int par,vector<int> adj[],int &ans,vector<int> &set){
    
}

void solve(){
    int n;cin>>n;
    int weight[n+1];
    vector<int> sorted_val;
    for(int i=1;i<=n;i++){
        cin>>weight[i];
        sorted_val.push_back(weight[i]);
    }
    sort(sorted_val.begin(),sorted_val.end());

    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    multiset<int> child;
    
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