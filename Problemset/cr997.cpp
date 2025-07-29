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
//     int n,m;
//     cin>>n>>m;
//     int x = m,y = m;
//     for(int i=0;i<n;i++){
//         int xi,yi;
//         cin>>xi>>yi;
//         if(i==0) continue;
//         x+=xi;
//         y+=yi;
//     }
//     int ans = 2*x + 2*y;
//     cout<<ans<<endl;
// }

// void dfs(int node,vector<bool> &vis,vector<int> &ans,vector<int> dir[]){
//     vis[node] = 1;
    
//     for(int it : dir[node]){
//         if(!vis[it]){
//             dfs(it,vis,ans,dir);
//         }
//     }
//     ans.push_back(node);
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> dir[n+1];

//     for(int i=1;i<=n;i++){
//         string s;cin>>s;
//         for(int j=0;j<n;j++){
//             if(s[j] == '1'){
//                 int u = i,v = j+1;
//                 if(u<v) dir[u].push_back(v);
//             }
//         }
//     }

//     vector<int> ans;
//     vector<bool> vis(n+1,0);

//     for(int i=1;i<=n;i++){
//         if(!vis[i]) dfs(i,vis,ans,dir);
//     }
    
//     reverse(ans.begin(),ans.end());

//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     if(n==6){
//         cout<<1<<" "<<1<<" "<<2<<" "<<3<<" "<<1<<" "<<2<<endl;
//     }else{
//         cout<<1<<" "<<1<<" ";
//         for(int i=2;i<=n-2;i++) cout<<i<<" ";
//         cout<<1<<endl;
//     }
// }

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    long ans = (n*(n+1))/2;
    long bad = 0;
    for(int x = 1;x<=10;x++){
        vector<int> b(n);
        for(int i=0;i<n;i++) b[i] = (arr[i]<=x)?-1:1;

        map<int,int> mp;
        int sum1 = 0,sum2 = 0,j=-1;
        for(int i=0;i<n;i++){
            sum2 += b[i];
            if(arr[i] == x){
                while(j<i){
                    if(j==-1) mp[0]++;
                    if(j!=-1){
                        sum1 += b[j];
                        // cout<<sum1<<" ";
                        mp[sum1]++;
                    }
                    j++;
                }
            }
            bad += mp[sum2];
        }
        // cout<<x<<" "<<bad<<"*"<<endl;
    }
    // cout<<ans<<" "<<bad<<endl;
    ans -= bad;
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