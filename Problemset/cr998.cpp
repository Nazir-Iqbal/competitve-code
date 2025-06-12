#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int a1,a2,a4,a5;
//     cin>>a1>>a2>>a4>>a5;
//     int ans = 0;
//     for(int i=-300;i<=300;i++){
//         int local = 0;
//         if(a1 + a2 == i) local++;
//         if(a2 + i == a4) local++;
//         if(i + a4 == a5) local++;
//         ans = max(ans,local);
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> arr(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cin>>arr[i][j];
//         sort(arr[i].begin(),arr[i].end());
//     }
//     if(n==1){
//         cout<<1<<endl;
//         return;
//     }
//     for(int i=0;i<n;i++){
//         for(int j=1;j<m;j++){
//             // cout<<i<<" "<<arr[i][j]<<" "<<arr[i][j-1]<<endl;
//             // cout<<i<<" "<<j<<endl;
//             if(arr[i][j]-arr[i][j-1] == 1){
//                 cout<<-1<<endl;
//                 return;
//             }
//         }
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(arr[j][0] == i){
//                 cout<<j+1<<" ";
//                 break;
//             }
//         }
//     }
//     cout<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     vector<int> hsn(n+1,0);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         hsn[arr[i]]++;
//     }
//     vector<int> p;
//     int odd = 0;
//     for(int i=0;i<n;i++){
//         int num = k-arr[i];
//         // cout<<arr[i]<<" "<<num<<endl;
//         if(hsn[arr[i]]==0) continue;

//         if(num <= 0 || num>n || hsn[num]==0) odd+=hsn[arr[i]];
//         else{
//             int times = min(hsn[num],hsn[arr[i]]);
//             if(arr[i] == num) times/=2;
//             if(times != 0) p.push_back(times);
//             odd += hsn[arr[i]];
//             if(arr[i] != num) odd += hsn[num];
//             odd -= 2*times;
//             hsn[arr[i]] = 0;
//             hsn[num] = 0;
//         }
//     }
//     int ans = 0;
//     if(odd%2==0) ans = accumulate(p.begin(),p.end(),0);
//     else ans = accumulate(p.begin(),p.end(),-p.size());
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(arr[0] > arr[1]){
//         cout<<"No"<<endl;
//     }else{
//         for(int i=1;i<n;i++){
//             int _min = min(arr[i-1],arr[i]);
//             arr[i-1] -= _min;
//             arr[i] -= _min;
//             // cout<<arr[i-1]<<" "<<arr[i]<<" "<<_min<<endl;
//             if(arr[i-1] > arr[i]){
//                 cout<<"No"<<endl;
//                 return;
//             }
//         }
//         cout<<"Yes"<<endl;
//     }
// }

// class DisjointSet {
//     vector<int> parent, size;
// public:
//     DisjointSet(int n) {
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

// void solve(){
//     int n,m1,m2;
//     cin>>n>>m1>>m2;
//     DisjointSet dsu1(n),dsu2(n);
//     vector<int> adj1[n+1],adj2[n+1];
//     for(int i=0;i<m1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj1[u].push_back(v);
//     }
//     for(int i=0;i<m2;i++){
//         int u,v;
//         cin>>u>>v;
//         adj2[u].push_back(v);
//     }
//     for(int i=1;i<=n;i++){
//         for(int &it : adj2[i]){
//             dsu2.unionBySize(i,it);
//         }
//     }
//     // removing the nodes;
//     int moves = 0;
//     for(int i=1;i<=n;i++){
//         for(int &it : adj1[i]){
//             if(dsu2.findUPar(it) != dsu2.findUPar(i)){
//                 // cout<<i<<" "<<it<<endl;
//                 moves++;
//             }else dsu1.unionBySize(it,i);
//         }
//     }
//     // adding the nodes;
//     for(int i=1;i<=n;i++){
//         for(int &it : adj2[i]){
//             if(dsu1.findUPar(it) != dsu1.findUPar(i)){
//                 moves++;
//                 dsu1.unionBySize(it,i);
//             }
//         }
//     }
//     cout<<moves<<endl;
// }

long MOD = 1e9+7;
const int N = 1e5+7;
long fact[100000];
vector<int> factor[N];

long fexp(long a, long b){
    long ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

long nCr(int N, int K){
    return fact[N] * fexp(fact[K] * fact[N-K] % MOD, MOD-2) % MOD;
}

int pre(){
    fact[0] = 1;
    for(int i = 1; i < 100000; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }

    for(int i=2;i<N;i++){
        for(int j=2*i;j<N;j+=i){
            factor[j].push_back(i);
        }
    }
}

void solve(){
    int k,n;
    cin>>k>>n;
    
    vector<vector<int>> dp(k+1,vector<int>(30));

    for(int i=1;i<=k;i++) dp[i][1] = 1;
    for(int j=1;j<30;j++) dp[1][j] = 1;
    
    for(int i=2;i<=k;i++){
        for(int j=2;j<30;j++){
            for(int &ele : factor[i]){

            }
        }
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    pre();
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}