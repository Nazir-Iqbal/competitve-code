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

// GCD to 1 (Easy)
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) arr[i][j] = 2;
//     }
//     for(int i=0;i<min(n,m);i++) arr[i][i] = 3;
//     if(n>m){
//         for(int i=m;i<n;i++) arr[i][m-1] = 3;
//     }else{
//         for(int i=n;i<m;i++) arr[n-1][i] = 3;
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
//         cout<<endl;
//     }
// }

// Replace With First
// int cal(string &s1,string &s2){
//     int n=s1.size();
//     int m=s2.size();
//     string temp1,temp2;
//     for(int i=0;i<m;i++){
//         if(s1[i]!=s2[i]) break;
//         temp1.push_back(s1[i]);
//     }
//     for(int i=0;i<m;i++){
//         if(s1[n-i-1]!=s2[m-i-1] || temp1.size()+temp2.size()==m) break;
//         temp2.push_back(s2[m-i-1]);
//     }
//     reverse(temp2.begin(),temp2.end());
//     string temp = temp1+temp2;
//     // cout<<temp1<<" "<<temp2<<endl;
//     if(temp==s2) return 1;
//     return 2;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     string s1,s2;
//     cin>>s1>>s2;
//     if(s1==s2){
//         cout<<0<<endl;
//         return;
//     }
//     if(m>n){
//         swap(n,m);
//         swap(s1,s2);
//     }
//     if(s1[0]!=s2[0]){
//         cout<<-1<<endl;
//         return;
//     }
//     int seg = cal(s1,s2);
//     if(seg==1){
//         cout<<1<<endl;
//         return;
//     }
//     int ans = 0;
//     for(int i=0;i<m;i++){
//         if(s1[i]!=s2[i]){
//             ans+=2;
//             break;
//         }
//     }
//     if(ans==0){
//         if(n!=m) ans++;
//     }
//     cout<<ans<<endl;
// }

// Prefix Suffix Min Max
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> ans;
//     ans.push_back(2e6);
//     for(int i=1;i<n;i++){
//         int cur = arr[i]-arr[i-1];
//         ans.push_back(cur);
//     }
//     for(int i=0;i<n;i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// Array Concatanation
const int MOD = 1e9+7;
template<const int mod>
struct mint {
    int val;
    constexpr mint(long long x = 0) : val((x % mod + mod) % mod) {}
    explicit operator int() const { return val; }
    mint& operator+=(const mint &b) { val += b.val; val -= mod * (val >= mod); return *this; }
    mint& operator-=(const mint &b) { val -= b.val; val += mod * (val < 0); return *this; }
    mint& operator*=(const mint &b) { val = 1ll * val * b.val % mod; return *this; }
    mint& operator/=(const mint &b) { return *this *= b.inv(); }
    mint inv() const { int x = 1, y = 0, t; for(int a=val, b=mod; b; swap(a, b), swap(x, y)) t = a/b, a -= t * b, x -= t * y; return mint(x); }
    mint power(int b) const { mint a = *this, res(1); for(; b; a *= a, b /= 2)  if(b & 1) res *= a; return res; }
    mint operator-() const { return val == 0 ? 0 : mod - val; }
    mint& operator++() { val = val == mod - 1 ? 0 : val + 1; return *this; }
    mint& operator--() { val = val == 0 ? mod - 1 : val - 1; return *this; }
    mint operator++(int32_t) { mint before = *this; ++*this; return before; }
    mint operator--(int32_t) { mint before = *this; --*this; return before; }
    friend mint operator+(const mint &a, const mint &b) {return mint(a) += b;}
    friend mint operator-(const mint &a, const mint &b) {return mint(a) -= b;}
    friend mint operator*(const mint &a, const mint &b) {return mint(a) *= b;}
    friend mint operator/(const mint &a, const mint &b) {return mint(a) /= b;}
    friend bool operator==(const mint &a, const mint &b) {return a.val == b.val;}
    friend bool operator!=(const mint &a, const mint &b) {return a.val != b.val;}
    friend bool operator<(const mint &a, const mint &b) {return a.val < b.val;}
    friend istream& operator>>(istream &in, mint &a) {return in >> a.val;}
    friend ostream& operator<<(ostream &os, const mint &a) {return os << a.val;}
};
using Mint = mint<MOD>;
namespace comb {
    int n(0);
    vector<Mint> _fac{1}, _invfac{1}, _inv{0};
    void init(int m) {
        m = min (m, MOD - 1);
        if (m <= n) return;
        _fac.resize(m + 1); _invfac.resize(m + 1); _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) _fac[i] = _fac[i - 1] * i;
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) _invfac[i - 1] = _invfac[i] * i, _inv[i] = _invfac[i] * _fac[i - 1];
        n = m;
    }
    Mint fac(int m) { if (m > n) init(2 * m); return _fac[m]; }
    Mint invfac(int m) { if (m > n) init(2 * m); return _invfac[m]; }
    Mint inv(int m) { if (m > n) init(2 * m); return _inv[m]; }
    Mint ncr(int n, int r) { if (n < r || r < 0) return 0; return fac(n) * invfac(r) * invfac(n - r); }
}
using comb::fac; using comb::invfac; using comb::inv; using comb::ncr;
const int mod = 1e9+7;
void solve(){
    int a,b;
    cin>>a>>b;
    int total =a+b;
    int pos = 0,neg = 0,neu=0;
    if(total>1) pos = (total+2)/4;
    if(total>3) neg = (total)/4;
    neu = total-pos-neg;
    Mint ans = 0;
    int range = min(pos,neg);
    for(int i=0;i<=range;i++){
        if(2*i>b) break;
        if(2*i+neu < b) continue;
        int left = b-2*i;
        Mint temp = ncr(pos,i);
        temp *= ncr(neg,i);
        temp *= ncr(neu,left);
        ans += temp;
    }
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