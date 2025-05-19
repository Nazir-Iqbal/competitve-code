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

// sour candy
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	sort(arr,arr+n);
// 	int ans = 0;
// 	for(int i=0;i<n;i++){
// 		ans = max(ans,(n-i)*arr[i]);
// 	}
// 	cout<<ans<<endl;
// }

// Crafty Coloring (Easy)  -> using brute force
// void solve(){
//     int n,m;cin>>n>>m;
// 	int len;cin>>len;
// 	string s;cin>>s;
// 	int req = min(n,m);
// 	vector<vector<char>> arr(n,vector<char>(m,'.'));
// 	int cur = 0;
// 	for(int i=0;i<req;i++){
// 		for(int j=0;j<n;j++) arr[j][cur] = s[i%len];
// 		for(int j=0;j<m;j++) arr[cur][j] = s[i%len];
// 		cur++;
// 	}
// 	int cnta = 0,cntb = 0;
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			if(arr[i][j] == 'A') cnta++;
// 			else if(arr[i][j] == 'B') cntb++;
// 		}
// 	}
// 	if(cnta>cntb) cout<<"Alice"<<endl;
// 	else if(cnta<cntb) cout<<"Bob"<<endl;
// 	else cout<<"Draw"<<endl;
// }
// Crafty Coloring (Easy)  -> using the counting approach
// void solve(){
// 	int n,m;cin>>n>>m;
// 	int len;cin>>len;
// 	string s;cin>>s;
// 	int cnta=0,cntb=0,oca = 0 , ocb = 0;
// 	int req = min(n,m);
// 	for(int i=0;i<req;i++){
// 		if(s[i%len]=='A') cnta+=(n+m-1),cnta-=2*oca,cntb-=2*ocb,oca++;
// 		else cntb+=(n+m-1),cnta-=2*oca,cntb-=2*ocb,ocb++;
// 	}
// 	if(cnta>cntb) cout<<"Alice"<<endl;
// 	else if(cnta<cntb) cout<<"Bob"<<endl;
// 	else cout<<"Draw"<<endl;
// }

// Glass Bridge (Easy)
// const int mod = 1e9+7;
// struct mint {
//   int val;
//   constexpr mint(long long x = 0) : val((x % mod + mod) % mod) {}
//   explicit operator int() const { return val; }
//   mint &operator+=(const mint &b) {
//     val += b.val;
//     val -= mod * (val >= mod);
//     return *this;
//   }
//   mint &operator-=(const mint &b) {
//     val -= b.val;
//     val += mod * (val < 0);
//     return *this;
//   }
//   mint &operator*=(const mint &b) {
//     val = 1ll * val * b.val % mod;
//     return *this;
//   }
//   mint &operator/=(const mint &b) { return *this *= b.inv(); }
//   mint inv() const {
//     int x = 1, y = 0, t;
//     for (int a = val, b = mod; b; swap(a, b), swap(x, y))
//       t = a / b, a -= t * b, x -= t * y;
//     return mint(x);
//   }
//   mint power(int b) const {
//     mint a = *this, res(1);
//     for (; b; a *= a, b /= 2)
//       if (b & 1) res *= a;
//     return res;
//   }
//   mint operator-() const { return val == 0 ? 0 : mod - val; }
//   mint &operator++() {
//     val = val == mod - 1 ? 0 : val + 1;
//     return *this;
//   }
//   mint &operator--() {
//     val = val == 0 ? mod - 1 : val - 1;
//     return *this;
//   }
//   mint operator++(int32_t) {
//     mint before = *this;
//     ++*this;
//     return before;
//   }
//   mint operator--(int32_t) {
//     mint before = *this;
//     --*this;
//     return before;
//   }
//   friend mint operator+(const mint &a, const mint &b) { return mint(a) += b; }
//   friend mint operator-(const mint &a, const mint &b) { return mint(a) -= b; }
//   friend mint operator*(const mint &a, const mint &b) { return mint(a) *= b; }
//   friend mint operator/(const mint &a, const mint &b) { return mint(a) /= b; }
//   friend bool operator==(const mint &a, const mint &b) {
//     return a.val == b.val;
//   }
//   friend bool operator!=(const mint &a, const mint &b) {
//     return a.val != b.val;
//   }
//   friend bool operator<(const mint &a, const mint &b) { return a.val < b.val; }
//   friend istream &operator>>(istream &in, mint &a) { return in >> a.val; }
//   friend ostream &operator<<(ostream &os, const mint &a) { return os << a.val; }
// };

// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	vector<vector<mint>> dp(m+1,vector<mint> (n+1,0));
// 	for(int i=0;i<=m;i++) dp[i][0] = 1;
// 	// using pull dp
// 	// for(int i=1;i<=m;i++){
// 	// 	for(int j=1;j<=n;j++){
// 	// 		dp[i][j] = dp[i-1][j-1]/2 + dp[i-1][j]/2;
// 	// 	}
// 	// }

// 	// using push dp
// 	dp[0][0] = 1;
// 	for(int i=0;i<m;i++){
// 		for(int j=0;j<n;j++){
// 			// die 
// 			dp[i+1][j+1] += dp[i][j]/2;
// 			// survive
// 			dp[i+1][j] += dp[i][j]/2;
// 		}
// 	}

// 	for(int i=1;i<=m;i++) cout<<dp[i][n]<<" ";
// 	cout<<endl;
// }

// Glass Bridge (Hard)

// const int N = 5e5+1;
// int p = 1e9+7;
// unsigned long long fac[N];
// void pre(){
// 	fac[0] = 1;
// 	for (int i = 1; i <N; i++)
// 		fac[i] = (fac[i - 1] * i) % p;
// }

// unsigned long long power(unsigned long long x, int y){
// 	unsigned long long res = 1; // Initialize result

// 	x = x % p;

// 	while (y > 0) {
// 		if (y & 1)
// 			res = (res * x) % p;
// 		y = y >> 1; // y = y/2
// 		x = (x * x) % p;
// 	}
// 	return res%p;
// }

// // Returns n^(-1) mod p
// unsigned long long modInverse(unsigned long long n){
// 	return power(n, p - 2);
// }

// unsigned long long nCrModPFermat(unsigned long long n,int r){
// 	// If n<r, then nCr should return 0
// 	if (n < r)
// 		return 0;
// 	// Base case
// 	if (r == 0)
// 		return 1;

// 	return (fac[n] * modInverse(fac[r]) % p*modInverse(fac[n - r]) % p)% p;
// }

// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	vector<int> dp(m+1,0);
// 	for(int i=1;i<=m;i++){
// 		dp[i] = (dp[i-1]+(nCrModPFermat(i-1,n-1)*modInverse(power(2,i))%p))%p;
// 	}
// 	for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
// 	cout<<endl;
// }

// Penchick and Desert Rabbit
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	vector<int> premax(n,0),sufmin(n,0);
// 	premax[0] = arr[0];
// 	sufmin[n-1] = arr[n-1];
// 	for(int i=1;i<n;i++) premax[i] = max(premax[i-1],arr[i]);
// 	for(int i=n-2;i>=0;i--) sufmin[i] = min(arr[i],sufmin[i+1]);
// 	vector<int> dp(n,0);
// 	dp[n-1] = premax[n-1];
// 	for(int i=n-2;i>=0;i--){
// 		int left = premax[i];
// 		int right = sufmin[i+1];
// 		// cout<<arr[left]<<" "<<arr[right]<<endl;
// 		if(left>right) dp[i] = dp[i+1];
// 		else dp[i] = premax[i];
// 	}
// 	for(int i=0;i<n;i++) cout<<dp[i]<<" ";
// 	cout<<endl;
// 	deque<int> dq;

// }

// Alice's Adventures in "Chess"
// void solve(){
//     int n,a,b;
//     cin>>n>>a>>b;
//     string s;cin>>s;
//     int x=0,y=0;
//     int tt = 100;
//     if(x==a && y==b){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     while(tt--){
//         for(int i=0;i<n;i++){
//             if(s[i] == 'N') y++;
//             else if(s[i]=='S') y--;
//             else if(s[i]=='E') x++;
//             else x--;
//             if(x==a && y==b){
//                 cout<<"Yes"<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<"No"<<endl;
// }

// Natlan Exploring
const int N = 1e6+1;
vector<int> f[N];
const int mod = 998244353;
void pre(){
    for(int i=2;i<N;i++){
        if(f[i].size()>0) continue;
        for(int j=i;j<N;j+=i) f[j].push_back(i);
    }
}

void combination(vector<pair<int,int>> &com,vector<int> &f,int ind,int cnt,int num,int n){
    if(ind==n){
        if(cnt > 0) com.push_back({cnt,num});
        return;
    }
    // take
    cnt++,num*=f[ind];
    combination(com,f,ind+1,cnt,num,n);
    cnt--,num/=f[ind];
    combination(com,f,ind+1,cnt,num,n);
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> dp(n,0);
    vector<int> sum(N,0);
    dp[0] = 1;
    vector<pair<int,int>> com1;
    combination(com1,f[arr[0]],0,0,1,f[arr[0]].size());

    for(int j=0;j<com1.size();j++) sum[com1[j].second] += dp[0];

    for(int i=1;i<n;i++){
        vector<pair<int,int>> com;
        combination(com,f[arr[i]],0,0,1,f[arr[i]].size());

        //applying the incluion exclusion principle
        for(int j=0;j<com.size();j++){
            if(com[j].first&1) dp[i] += sum[com[j].second];
            else dp[i] -= sum[com[j].second];
            dp[i] = (mod+dp[i])%mod;
        }
        for(int j=0;j<com.size();j++) sum[com[j].second] = (sum[com[j].second]+dp[i])%mod;
    }
    cout<<dp[n-1]<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
	pre();
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}