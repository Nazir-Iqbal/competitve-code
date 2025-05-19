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

// Stickogon
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int hsn[101] = {0};
//     for(int i=0;i<n;i++) hsn[arr[i]]++;
//     int ans = 0;
//     for(int i=1;i<=100;i++) ans += (hsn[i]/3);
//     cout<<ans<<endl;
// }

// A BIT of a Construction
// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	if(n==1){
// 		cout<<k<<endl;
// 		return;
// 	}
// 	int no = log2(k);
// 	int req = (1<<no)-1;
// 	cout<<req<<" "<<k-req<<" ";
// 	for(int i=0;i<n-2;i++) cout<<0<<" ";
// 	cout<<endl;
// }

// How Does the Rook Move?
int M = 1e9+7;
vector<int> dp(1e6,0);

void pre(){
	dp[0]=dp[1]=1;
	for(int i=2;i<=400000;i++){
		dp[i] = (dp[i-1] + (2*(i-1)*dp[i-2]))%M;
	}
	// for(int i=0;i<1000;i++) cout<<dp[i]<<" ";
	// cout<<endl;
}

void solve(){
	int n,k;
	cin>>n>>k;
	set<int> s;
	for(int i=0;i<k;i++){
		int x,y;cin>>x>>y;
		s.insert(x);
		s.insert(y);
	}
	// using the single state  dp
	// dp[i] --> represents the possible configurations for the matrix of size (iXi)
	int left = n-s.size();
	// vector<int> dp(left+1,0);
	// dp[0] = dp[1] = 1;
	// for(int i=2;i<=left;i++) dp[i] = (dp[i-1] + (2*(i-1)*dp[i-2]))%M;
	// for(int i=0;i<=left;i++) cout<<dp[i]<<" ";
	// cout<<endl;
	cout<<dp[left]<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
	pre();
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}