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
//     int n;cin>>n;
//     int maxa = INT_MIN , maxb = INT_MIN;
//     for(int i=0;i<n;i++){
//         int a,b;
//         cin>>a>>b;
//         maxa = max(a,maxa);
//         maxb = max(b,maxb);
//     }
//     cout<<(maxa+maxb)*2<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];

//     int ans = INT_MAX;

//     for(int i=0;i<n;i++){
//         int moves = i;
//         for(int j=i;j<n;j++){
//             if(arr[j] > arr[i]) moves++;
//         }
//         ans = min(ans,moves);
//     }

//     cout<<ans<<endl;
    
// }

// int recur(int sz,map<int,vector<int>> &mp,map<int,int> &dp){
    
//     if(dp.find(sz) != dp.end()) return dp[sz];

//     int ans = sz;
//     for(int &ele : mp[sz]){
//         int len = sz + ele;
//         if(mp.find(len) != mp.end()){
//             ans = max(ans,recur(len,mp,dp));
//         }
//         else ans = max(len,ans);
//     }
//     return dp[sz] = ans;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,vector<int>> mp;
//     for(int i=1;i<n;i++){
//         int sz = arr[i] + i;
//         if(sz >= n) mp[sz].push_back(i);
//     }

//     map<int,int> dp;
//     recur(n,mp,dp);

//     cout<<dp[n]<<endl;
// }

int recur(int i,int j,int a[],int b[],int m,int n,vector<vector<int>> &dp){
    
    // base case
    if(i>=n) return 0;
    if(j>=m) return 1e9;
    if(a[i] > b[j]) return 1e9;

    if(dp[i][j] != -1) return dp[i][j];

    int not_take = recur(i,j+1,a,b,m,n,dp);

    // take
    int sum = 0,ind = 0;
    while(i+ind<n && sum + a[i+ind] <= b[j]) sum += a[i+ind],ind++;
    // cout<<i<<" "<<j<<endl;
    int take = (m-(j+1)) + recur(i+ind,j,a,b,m,n,dp);

    return dp[i][j] = min(not_take,take);
}

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

    int ans = recur(0,0,a,b,m,n,dp);

    if(ans == 1e9) cout<<-1<<endl;
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