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
//     int n,m;
//     cin>>n>>m;
//     string s1,s2;
//     cin>>s1>>s2;
//     int cnt1 = 0,cnt2 = 0;
//     for(int i=0;i<n;i++) if(s1[i] == 'a') cnt1++;
//     for(int i=0;i<m;i++) if(s2[i] == 'a') cnt2++;
    
//     if(cnt1!=cnt2){
//         cout<<"NO"<<endl;
//         return;
//     }

//     int oc1 = 0,oc2 = 0;
//     for(int i=0;i<n;i++){
//         if(s1[i] == 'a'){
//             oc1 = i;
//             break;
//         }
//     }
//     for(int i=0;i<m;i++){
//         if(s2[i] == 'a'){
//             oc2 = i;
//             break;
//         }
//     }

//     if(oc1 != oc2){
//         cout<<"NO"<<endl;
//         return;
//     }

//     if(cnt1==0 && n!=m){
//         cout<<"NO"<<endl;
//         return;
//     }
//     cout<<"YES"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> b(n);
//     for(int i=0;i<n;i++) cin>>b[i];
//     int ans = 2*n-1;
//     int def = 0;
//     if(b[0]==0) def++;
//     if(b[n-1]==1) def++;
//     if(def>1) ans--;
//     cout<<ans<<endl;
// }

// bool pal(string s,int n){
//     for(int i=0;i<n;i++){
//         if(s[i] != s[n-i-1]) return false;
//     }
//     return true;
// }

// bool check(string &s,int n){
//     for(int i=2;i<n;i+=2){
//         if(s[i]!=s[i-2]) return false;
//     }

//     for(int i=3;i<n;i+=2){
//         if(s[i]!=s[i-2]) return false;
//     }
//     return true;
// }

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     if(pal(s,n)){
//         cout<<0<<endl;
//         return;
//     }
//     if(n==2){
//         cout<<-1<<endl;
//         return;
//     }
//     if(n>=4){
//         if(check(s,n))cout<<-1<<endl;
//         else cout<<1<<endl;
//         return;
//     }
//     cout<<1<<endl;
// }
int mod = 998244353;

int power(int x, int y, int p){

    int res = 1;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res * x)%mod;
 
        y = y >> 1;
 
        x = (x * x)%mod;
    }
    return res % p;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int sub = (power(m,n/2,mod)*(m+1))%mod,ans = 0;

    for(int i=1;i<=m;i++){
        int val1 = m/i;
        int val2 = val1+1;

        int c1 = i-m%i;
        int c2 = m%i;

        int num = ((c1*power(val1,2,mod))%mod + (c2*power(val2,2,mod))%mod)%mod;
        ans = (ans + power(num,n/2,mod))%mod;
    }

    ans = (mod+(ans-sub))%mod;
    if(n&1) ans = (ans*m)%mod;
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