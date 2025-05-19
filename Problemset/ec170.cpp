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
//     string s1,s2;
//     cin>>s1>>s2;
//     int n=s1.size();
//     int m=s2.size();
//     int ind = 0;
//     for(int i=0;i<min(n,m);i++){
//         if(s1[i] == s2[i]) ind++;
//         else break;
//     }
//     // cout<<ind<<endl;
//     if(ind!=0) ind += (n-ind) + (m-ind)+1;
//     else ind = n+m;
//     cout<<ind<<endl;
// }

// int mod = 1e9+7;
// const int N = 2e6+1;
// int fac[N];

// void pre(){
//     fac[0] = 1;
//     for (int i = 1; i <N; i++)
//         fac[i] = (fac[i - 1] * i) % mod;
// }

// int power(int x,  int y){
//     int res = 1; // Initialize result
 
//     x = x % mod;
 
//     while (y > 0) 
//     {
//         if (y & 1)
//             res = (res * x) % mod;
 
//         y = y >> 1; // y = y/2
//         x = (x * x) % mod;
//     }
//     return res;
// }

// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int j=0;j<n;j++) cin>>b[j];
//     for(int i=0;i<n;i++){
//         if(a[i]==b[i] || b[i] == 0) cout<<1<<endl;
//         else cout<<power(2,b[i])<<endl;
//     }
// }

// New Game
// int get(vector<int> &arr,int k){
//     int l=0,r=0;
//     int n = arr.size();
//     int sum = 0,ans = 0;
//     while(r<n){
//         sum += arr[r];
//         if(r-l+1 == k){
//             ans = max(ans,sum);
//             sum -= arr[l];
//             l++;
//         }
//         r++;
//     }
//     ans = max(ans,sum);
//     return ans;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     map<int,int> mp;
//     for(int i=0;i<n;i++) cin>>arr[i],mp[arr[i]]++;
//     vector<vector<int>> chain;
//     int prev = -1;
//     vector<int> temp;
//     for(auto &ele : mp){
//         if(prev==-1) temp.push_back(ele.second),prev = ele.first;
//         else{
//             if(prev+1==ele.first) temp.push_back(ele.second),prev++;
//             else{
//                 prev = ele.first;
//                 chain.push_back(temp);
//                 temp.clear();
//                 temp.push_back(ele.second);
//             }
//         }
//     }
//     if(temp.size()>0) chain.push_back(temp);
//     int ans = 0;
//     for(int i=0;i<chain.size();i++){
//         int local = get(chain[i],k);
//         ans = max(ans,local);
//     }
//     cout<<ans<<endl;
// }

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 0,local = 0;
    int dp[m+1][m+1] ={0};
    int total = 0,interval = 0;
    for(int i=0;i<n;i++){
        while(i<n && arr[i]==0) total++,interval++,i++;
        if(i<n){
            for(int i=0;i<=interval;i++){
                
            }
        }
    }
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