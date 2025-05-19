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
//     int n,k;
//     cin>>n>>k;
//     int ans = (n*k - k + 1);
//     cout<<ans<<endl;
// }

// K-Sort
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> diff;
//     int ans = 0;
//     for(int i=1;i<n;i++){
//         if(arr[i-1]>arr[i]){
//             diff.push_back(arr[i-1]-arr[i]);
//             arr[i] = arr[i-1];
//         }
//     }
//     sort(diff.begin(),diff.end());
//     int cur = 0;
//     for(int i=0;i<diff.size();i++){
//         int sz = diff.size()-i;
//         ans += (sz + 1)*(diff[i]-cur);
//         cur = diff[i];
//     }
//     cout<<ans<<endl;
// }

// Basil's Garden
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = arr[n-1];
//     for(int i=n-2;i>=0;i--){
//       ans = max(ans+1,arr[i]);
//     }
//     cout<<ans<<endl;
// }

// World is Mine
// int recur(vector<int> &cnt,int ind,int rem,vector<vector<int>> &dp,int sz){
// 	if(ind == sz) return 0;

// 	if(dp[ind][rem] != -1) return dp[ind][rem];

// 	// not blocking case
// 	dp[ind][rem] = max(dp[ind][rem],recur(cnt,ind+1,rem+1,dp,sz));

// 	if(rem>=cnt[ind]) dp[ind][rem] = max(dp[ind][rem],1 + recur(cnt,ind+1,rem-cnt[ind],dp,sz));
// 	return dp[ind][rem];
// }

void solve(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int hsn[n+1] = {0};
	for(int i=0;i<n;i++) hsn[arr[i]]++;
	vector<int> cnt;
	for(int i=0;i<=n;i++) if(hsn[i]>0) cnt.push_back(hsn[i]);
	int sz = cnt.size();
	vector<vector<int>> dp(sz+1,vector<int>(sz+1,0));
	// i --> index j-->remaining cakes
	// dp[i][j] --> maximum no. of cakes blocked
	for(int i=1;i<=sz;i++){
		for(int j=1;j<i;j++){
			dp[i][j] = max(dp[i][j],dp[i-1][j+1]);
			if(j>=cnt[i-1]) dp[i][j] = max(dp[i][j],1+dp[i-1][j-cnt[i-1]]);
		}
	}
	// cout<<sz-recur(cnt,0,0,dp,sz)<<endl;
	cout<<sz-dp[sz][sz-1]<<endl;
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