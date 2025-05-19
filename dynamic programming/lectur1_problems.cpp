#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int M = 1e9+7;

// void solve(){
//     int n;cin>>n;
//     int dp[n+1]={0};
//     dp[0] = 1;
//     for(int i=1;i<=n;i++){
//         // all the states that will help in transition
//         for(int j=1;j<=6;j++){
//             int subProblem = i-j;
//             if(subProblem<0) continue;
//             dp[i] = (dp[i]+dp[subProblem])%M;
//         }
//     }
//     cout<<dp[n]<<endl;
// }

// Minimizing Coins
int n ,m;
const int N = 1e6+1;
const int sz = 101;
int a[sz];
int dp[N];
// int cnt = 0;

// int minimum(int sum){
    
//     // cnt++;
//     // base case
//     if(sum<0) return 1e9;
//     if(sum==0) return 0;

//     // memoisation
//     if(dp[sum]!=-1) return dp[sum];

//     //checking for all the coins
//     for(int i=0;i<n;i++){
//         if(dp[sum]==-1) dp[sum] = minimum(sum-a[i])+1;
//         else dp[sum] = min(minimum(sum-a[i])+1,dp[sum]);
//     }
//     return dp[sum];
// }

// void solve(){
//     cin>>n>>m;
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<=m;i++) dp[i] = 1e9;
//     dp[0] = 0;
//     // tabulation
//     // state dp[i] --> mimum no. of coins requied for making sum equals to i
//     for(int j=1;j<=m;j++){
//         for(int i=0;i<n;i++){
//             if(j-a[i]>=0) dp[j] = min(dp[j],dp[j-a[i]]+1);
//         }
//     }
//     if(dp[m]>=1e9) cout<<-1;
//     else cout<<dp[m];
//     // cout<<cnt<<endl;
// }

// int ways(int sum,int n){
//     if(sum<0) return 0;
//     if(sum==0) return 1;

//     if(dp[sum]!=-1) return dp[sum];
//     dp[sum] = 0;
//     for(int i=0;i<n;i++){
//         dp[sum] = (ways(sum-a[i],n)+dp[sum])%M;
//     }
//     return dp[sum];
// }

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<=m;i++) dp[i] = 0;
    dp[0] = 1;
    // state dp[i] --> no. ways to form sum i
    // sort(a,a+n);
    for(int j=1;j<=m;j++){
        for(int i=0;i<n;i++){
            if((j>=a[i])) dp[j] = (dp[j]+dp[j-a[i]])%M;
        }
    }
    // ways(m,n);
    // cout<<n<<" "<<m<<endl;
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<endl;
    cout<<dp[m];
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();

    return 0;
}