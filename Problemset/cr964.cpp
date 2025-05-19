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
//     int ans = (n/10)+(n%10);
//     cout<<ans<<endl;
// }

// void solve(){
//     int a1,a2,b1,b2;
//     cin>>a1>>a2>>b1>>b2;
//     int ans = 0;
//     if(a1>b1 && a2>b2) ans+=2;
//     else if(a1==b1 && a2>b2) ans+=2;
//     else if(a1>b1 && a2==b2) ans+=2;
//     if(a1>b2 && a2>b1) ans+=2;
//     else if(a1==b2 && a2>b1) ans+=2;
//     else if(a1>b2 && a2==b1) ans+=2;
//     cout<<ans<<endl;
// }

// Showering
// void solve(){
//     int n,s,m;
//     cin>>n>>s>>m;
//     vector<int> hsn(m+2,0);
//     for(int i=0;i<n;i++){
//         int l,r;cin>>l>>r;
//         hsn[l]++,hsn[r+1]--;
//     }
//     for(int i=1;i<=m;i++) hsn[i] += hsn[i-1];
//     int cnt = 0;
//     // for(int ele : hsn) cout<<ele<<" ";
//     // cout<<endl;
//     for(int i=0;i<=m;i++){
//         if(i==m){
//             if(cnt>=s){
//                 cout<<"Yes"<<endl;
//                 return;
//             }
//         }
//         if(hsn[i]==0)cnt++;
//         else{
//             if(cnt>=s){
//                 cout<<"Yes"<<endl;
//                 return;
//             }
//             if(hsn[i+1]==0) cnt = 1;
//             else cnt=0;
//         }
//     }
    
//     cout<<"No"<<endl;
// }

// Slavic's Exam
// void solve(){
//     string s,t;
//     cin>>s>>t;
//     int n = s.length(),m = t.length();
//     int cnt = 0;
//     for(int i=0;i<n;i++) if(s[i] == '?') cnt++;
//     if(cnt>=m){
//         int j=0;
//         for(int i=0;i<n;i++){
//             if(s[i] == '?'){
//                 if(j == m){
//                     s[i] = 'a';
//                     continue;
//                 }
//                 s[i] = t[j];
//                 j++;
//             }
//         }
//         cout<<"Yes"<<endl;
//         cout<<s<<endl;
//     }else{
//         int j=0;
//         for(int i=0;i<n;i++){
//             if(s[i] == t[j]){
//                 j++;
//                 continue;
//             }
//             if(s[i] == '?'){
//                 if(j==m){
//                     s[i] = 'a';
//                     continue;
//                 }
//                 s[i] = t[j];
//                 j++;
//             }
//         }
//         if(j==m){
//             cout<<"Yes"<<endl;
//             cout<<s<<endl;
//         }else cout<<"No"<<endl;
//     }
// }

// vector<int> hsn(15,0);
// const int N=1e5+7;

// void pre(){
//     for(int i=1;i<15;i++){
//         hsn[i] = pow(3,i)-1;
//     }
// }

// void solve(){
//     // for(int i=0;i<15;i++) cout<<i<<" "<<hsn[i]<<endl;
//     int l,r;
//     cin>>l>>r;
//     int tempo = l;
//     int ans = 0,temp=l+1,prev = -1;
//     while(tempo){
//         ans += 2;
//         tempo/=3;
//     }
//     // cout<<ans<<"*"<<endl;
//     while(temp<=r){
//         int ind = 0;
//         for(int i=1;i<15;i++){
//             if(temp<=hsn[i]){
//                 ind = i;
//                 break;
//             }
//         }
//         int diff = min(r,hsn[ind]) - temp + 1;
//         ans += (ind)*diff;
//         // cout<<ind<<" "<<temp<<" "<<r<<" "<<diff<<endl;
//         temp = min(r+1,hsn[ind]+1);
//     }
//     cout<<ans<<endl;
// }

#define MOD 1000000007 
#define MAXN 1000001 
 
long long factorial[MAXN]; 
long long inverse_factorial[MAXN]; 
 
// Function to calculate modular exponentiation (x^y % p) 
long long power(long long x, long long y, long long p) { 
    long long res = 1; 
    x = x % p; 
 
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % p; 
 
        y = y >> 1; 
        x = (x * x) % p; 
    } 
 
    return res; 
} 
 
// Function to precompute factorials and their inverses 
void precompute_factorials() { 
    factorial[0] = 1; 
    inverse_factorial[0] = 1; 
 
    for (int i = 1; i < MAXN; i++) { 
        factorial[i] = (factorial[i - 1] * i) % MOD; 
        inverse_factorial[i] = power(factorial[i], MOD - 2, MOD); 
    } 
} 
 
// Function to calculate nCr % MOD 
long long nCr(int n, int r) { 
    if (r > n) 
        return 0; 
 
    long long res = (factorial[n] * inverse_factorial[r]) % MOD; 
    res = (res * inverse_factorial[n - r]) % MOD; 
 
    return res; 
} 

void solve(){
    // long long t = nCr(5,2);
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int one = 0,zero = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1) one++;
        else zero++;
    }
    int ans = 0;
    int o = one,z = zero;
    int oreq = k/2+1,zreq = k/2;
    while(oreq<=o && zreq>=0){
        int left = nCr(z,zreq);
        int  right = nCr(o,oreq);
        int temp = (left*right)%MOD;
        ans = (ans+temp)%MOD;
        oreq++,zreq--;
    }
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    precompute_factorials();
    while(t--){
      solve();
    }

    return 0;
}