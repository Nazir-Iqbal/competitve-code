#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int finder(int w,int n,int x,vector<int> &arr,vector<vector<vector<int>>> &dp){
    if(n==0){
        if(w==0) return 1;
        else return 0;
    }
    if(x<0) return 0;
    if(dp[w][n][x]!=-1) return dp[w][n][x];
    int ans = 0;
    if(w-arr[x]>=0) ans = finder(w-arr[x],n-1,x-1,arr,dp);
    ans += finder(w,n,x-1,arr,dp);
    return dp[w][n][x] = ans;
}

void solve(){
    int w;
    cin>>w;
    int n,x;
    cin>>n>>x;
    vector<int> arr(x);
    for(int i=0;i<x;i++) cin>>arr[i];
    vector<vector<vector<int>>> dp(w+1,vector<vector<int>>(n+1,vector<int>(x+1,-1)));
    cout<<finder(w,n,x-1,arr,dp)<<endl;
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