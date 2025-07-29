#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, nuint_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     string s;cin>>s;
//     string ans;
//     int cnt = 0;
//     for(int i=0;i<s.size();i++){
//         if(s[i] == 'T') cnt++;
//     }
//     for(int i=0;i<cnt;i++) ans.push_back('T');
//     for(int i=0;i<s.size();i++){
//         if(s[i] == 'T') continue;
//         ans.push_back(s[i]);
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int a,b,k;
//     cin>>a>>b>>k;
//     int x = __gcd(a,b);
//     int x1 = a/x, x2 = b/x;
//     if(x1 <= k && x2 <= k){
//         cout<<1<<endl;
//     }else cout<<2<<endl;
// }

// pair<int,int> get(int l,int r,int x){
//     int first = -1,last = -1;
//     if(l%x==0) first = l;
//     else first = (l/x+1)*x;
    
//     if(r%x==0) last = r;
//     else last = (r/x)*x;

//     return {first,last};
// }

// void solve(){
//     int l,r;
//     cin>>l>>r;
//     int cnt = 0;
//     vector<int> num = {2,3,5,7};
//     for(int ele : num){
//         pair<int,int> p = get(l,r,ele);
//         int first = p.first;
//         int last = p.second;

//         // cout<<ele<<" "<<first<<" "<<last<<endl;

//         if(first<=last) cnt += (last-first+1)/ele + 1;
//     }

//     num = {6,10,14,15,21,35};

//     for(int ele : num){
//         pair<int,int> p = get(l,r,ele);
//         int first = p.first;
//         int last = p.second;

//         if(first<=last) cnt -= (last-first+1)/ele + 1;
//     }

//     num = {30,42,70,105};

//     for(int ele : num){
//         pair<int,int> p = get(l,r,ele);
//         int first = p.first;
//         int last = p.second;

//         if(first<=last) cnt += (last-first+1)/ele + 1;
//     }

//     num = {210};

//     for(int ele : num){
//         pair<int,int> p = get(l,r,ele);
//         int first = p.first;
//         int last = p.second;

//         if(first<=last) cnt -= (last-first+1)/ele + 1;
//     }

//     int ans = (r-l+1)-cnt;
//     cout<<ans<<endl;
// }

const int mod = 998244353;
const int MOD = 998244353;

int binex(int a , int b , int mod)
{
	a %= mod;
 
	int result = 1;
	b = b % (MOD-1);
	while(b > 0)
	{
		if(b%2 == 1)
			result = (result%mod * a%mod)%mod ;
		a = (a%mod*a%mod)%mod;
		b = b/2;
	}
	return result%mod;
}
 
int inv(int a){
    return binex(a,mod-2,mod)%mod;
}

int dfs(int node,vector<vector<int>> adj[],int m,vector<int> &dp){

    // if we have reached the end
    if(node > m){
        return 1;
    }

    if(dp[node] != -1) return dp[node];

    int ans = 0;
    for(auto &ele : adj[node]){
        int r = ele[0];
        int p = ele[1];
        int q = ele[2];
        int prob = (p*inv(q)%mod)%mod;
        int invprob = ((q-p)*inv(q)%mod)%mod;
        prob = (prob * inv(invprob)%mod)%mod;
        ans = (ans +  prob*dfs(r+1,adj,m,dp)%mod)%mod;
    }

    return dp[node] = ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj[m+1];
    int total = 1;
    for(int i=0;i<n;i++){
        int l,r,p,q;
        cin>>l>>r>>p>>q;
        // cout<<l<<" "<<r<<" "<<p<<" "<<q<<endl;
        adj[l].push_back({r,p,q});
        int prob = (((q - p + mod) % mod) * inv(q)) % mod;
        total = (total % mod * prob % mod) % mod;
    }
    vector<int> dp(m+1,-1);
    int ans = (total*dfs(1,adj,m,dp)%mod)%mod;
    cout<<ans<<endl;
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