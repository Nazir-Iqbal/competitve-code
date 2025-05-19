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
//     int h[n],w[n];
//     for(int i=0;i<n;i++) cin>>h[i]>>w[i];
//     int ans = 2*((*max_element(h,h+n))+(*max_element(w,w+n)));
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = INT_MAX;
//     for(int i=0;i<n;i++){
//         vector<int> temp;
//         int local = 0;
//         for(int j=i+1;j<n;j++) if(arr[j]>arr[i]) local++;
//         int _max = INT_MIN;
//         for(int j=0;j<i;j++) _max = max(_max,arr[i]);
//         if(_max>arr[i]){
//             for(int j=0;j<i;j++){
//                 if(arr[j] == _max){
//                     local+=j;
//                     break;
//                 }
//             }
//         }else local += i;
//         ans = min(ans,local);
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int a[n+1];
//     for(int i=1;i<=n;i++) cin>>a[i];
//     vector<pair<int,int>> len;
//     for(int i=1;i<=n;i++){
//         len.push_back({a[i]+i-1,i});
//     }
//     sort(len.begin(),len.end());
//     set<int> st;
//     st.insert(n);
//     int ans = n;
//     for(int i=0;i<n;i++){
//         if(st.find(len[i].first)!=st.end()){
//             int num = len[i].first+len[i].second-1;
//             st.insert(num);
//             ans = max(ans,num);
//         }
//     }
//     cout<<ans<<endl;
// }

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=m;j++) cin>>b[j];
    vector<int> prefix(n+1,0);
    for(int i=1;i<=n;i++) prefix[i] = a[i]+prefix[i-1];
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e18));
    for(int i=0;i<=m;i++) dp[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i][j-1];
            if(a[i]<=b[j]){
                int locate = prefix[i]-b[j];
                int target = lower_bound(prefix.begin(),prefix.end(),locate)-prefix.begin();
                if(dp[target][j]==1e18) continue;
                int cost = min(dp[target][j],dp[target][j-1]) + (m-j);
                dp[i][j] = min(dp[i][j],cost);
            }
        }
    }
    if(dp[n][m] >= 1e18) cout<<-1<<endl;
    else cout<<dp[n][m]<<endl;
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