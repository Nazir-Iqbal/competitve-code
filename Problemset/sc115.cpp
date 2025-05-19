#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     x-=n;
//     if(x<0){
//         cout<<"No"<<endl;
//         return;
//     }
//     y-=3*(n-x);
//     if(y<0) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;

// }

// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     sort(a,a+n,greater<int>());
//     sort(b,b+n);
//     int number = a[0]+b[0];
//     for(int i=0;i<n;i++){
//         if(number!=a[i]+b[i]){
//             cout<<-1<<endl;
//             return;
//         }
//     }
//     for(int i=0;i<n;i++) cout<<a[i]<<" ";
//     cout<<endl;
//     for(int i=0;i<n;i++) cout<<b[i]<<" ";
//     cout<<endl;
// }

// Greedy LIS Algorithm
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     if(n==1 && x==0){
//         cout<<1<<endl;
//         return;
//     }
//     if(n<=x+1 && x!=0){
//         cout<<-1<<endl;
//         return;
//     }
//     for(int i=0;i<n-1;i++){
//         if(i==n-2-x) cout<<n<<" ";
//         cout<<i+1<<" ";
//     }
//     cout<<endl;
// }

// Make All Zero

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ind = 0;
//     vector<int> v;
//     int ele = arr[0];
//     for(int i=0;i<n;i++){
//         if(ele>=arr[i]){
//             v.push_back(i);
//             ele = min(ele,arr[i]);
//         }
//     }
//     reverse(v.begin(),v.end());
//     int ans = n;
//     int len = v.size();
//     for(int i=0;i<len;i++){
//         int calc = arr[v[i]] + (n-len) + (len-i-1);
//         // cout<<calc<<"*"<<endl;
//         ans = min(ans,calc);
//     }
//     cout<<ans<<endl;
// }

// Binary Grid Forces
const int N = 1e6+1;
int mod = 1e9+7;
int fact[N];

// binary exponentiation
int exp(int a,int b,int mod){
    int ans = 1;
    while(b){
        if(b&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> vs(n);
    for(int i=0;i<n;i++) cin>>vs[i];
    if(n==1){
        cout<<1<<endl;
        return;
    }
    bool movable[m] = {0};
    for(int i=n-1;i>0;i--){
        int cnt = 0;
        for(int j=0;j<m;j++){
            if(vs[i][j]=='1') cnt++;
        }
        if(cnt<2){
            for(int j=0;j<m;j++) movable[j] = 0;
            continue;
        }
        bool flag = false;
        for(int j=0;j<m;j++){
            if(movable[j] && vs[i][j]=='1'){
                flag = true;
                break;
            }
        }
        if(flag){
            for(int j=0;j<m;j++){
                if(vs[i][j]=='1') movable[j]=1;
            }
        }else{
            for(int j=0;j<m;j++){
                if(vs[i][j]=='1') movable[j]=1;
                else movable[j] = 0;
            }
        }
    }
    int zero = 0,one = 0;
    for(int i=0;i<m;i++){
        if(movable[i]){
            if(vs[0][i]=='1')one++;
            else zero++;
        }
    }
    int temp = fact[one]*fact[zero];
    // modular mulatiplicative inverse
    int  inv = exp(temp,mod-2,mod);
    int ans = (fact[one+zero]*inv)%mod;
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    while(t--){
      solve();
    }

    return 0;
}