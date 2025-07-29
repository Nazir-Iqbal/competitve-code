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
//     set<int> s1,s2;
//     for(int i=0;i<n;i++){
//         int temp;
//         cin>>temp;
//         s1.insert(temp);
//     }
//     for(int j=0;j<n;j++){
//         int temp;
//         cin>>temp;
//         s2.insert(temp);
//     }
//     int sz = s1.size()*s2.size();
//     if(sz > 2) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     if(n==k){
//         vector<int> v(k/2+1,0);
//         for(int i=2;i<=n;i+=2) v[i/2] = arr[i];
//         for(int i=1;i<=k/2;i++){
//             if(v[i]!=i){
//                 cout<<i<<endl;
//                 return;
//             }
//         }
//         cout<<k/2+1<<endl;
//     }else{
//         for(int i=2;i<=n-k+2;i++){
//             if(arr[i]!=1){
//                 cout<<1<<endl;
//                 return;
//             }
//         }
//         cout<<2<<endl;
//     }
// }

// int tt = 1;

// void solve(){
//     int n;cin>>n;
//     int arr[n][n];
//     vector<vector<int>> suffix(n,vector<int>(n,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++) cin>>arr[i][j];
//         suffix[i][n-1] = arr[i][n-1];
//     }

//     // if(tt == 898){
//     //     cout<<n<<"*";
//     //     for(int i=0;i<n;i++){
//     //         for(int j=0;j<n;j++) cout<<arr[i][j]<<"*";
//     //     }
//     //     cout<<endl;
//     // }

//     for(int i=0;i<n;i++){
//         for(int j=n-2;j>=0;j--) suffix[i][j] = suffix[i][j+1]+arr[i][j];
//     }
//     int ans = 0,cur = n;
//     vector<bool> taken(n+1,0);
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(suffix[j][i] == cur){
//                 // cout<<i<<" "<<j<<" "<<cur<<endl;
//                 if(!taken[j]){
//                     taken[j] = 1;
//                     ans++;
//                     break;
//                 }
//             }
//         }
//         cur--;
//     }
//     cout<<min(ans+1,n)<<endl;
//     tt++;
// }

void solve(){
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int> adj1[n+1],adj2[n+1];
    int m;cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    vector<bool> good(n+1,0);
    for(int i=1;i<=n;i++){
        unordered_set<int> s1,s2;
        for(int ele : adj1[i]) s1.insert(ele);
        for(int ele : adj2[i]) s2.insert(ele);
        for(int ele : s1){
            if(s2.find(ele) != s2.end()){
                good[i] = 1;
                break;
            }
        }
    }

    // for(int i = 1;i<=n;i++){
    //     if(good[i]) cout<<i<<" ";
    // }
    // cout<<endl;

    // two stat dijkstra
    // v1 --> for graph1 v2 --> for graph2
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dis(n+1,vector<int>(n+1,INT_MAX));
    pq.push({0,{k1,k2}});
    dis[k1][k2] = 0;
    while(!pq.empty()){
        int node1 = pq.top().second.first;
        int node2 = pq.top().second.second;
        int cost = pq.top().first;
        pq.pop();

        for(int ele1 : adj1[node1]){
            for(int ele2 : adj2[node2]){
                int add = abs(ele1-ele2);
                if(add + cost < dis[ele1][ele2]){
                    dis[ele1][ele2] = add + cost;
                    pq.push({add+cost,{ele1,ele2}});
                }
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
    // }

    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        if(good[i]){
            ans = min(ans,dis[i][i]);
        }
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
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