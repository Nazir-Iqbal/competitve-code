#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void print(vector<int> &ans){
//     for(int &ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<pair<int,int>> vp1,vp2,left1,left2;
//     for(int i=1;i<n-1;i+=2) vp1.push_back({arr[i],i});
//     for(int i=2;i<n-1;i+=2) vp2.push_back({arr[i],i});
//     left1 = vp2,left2 = vp1;
//     left1.push_back({arr[0],0}),left1.push_back({arr[n-1],n-1});
//     left2.push_back({arr[0],0}),left2.push_back({arr[n-1],n-1});
//     vector<int> ans1(n),ans2(n);
//     sort(vp1.begin(),vp1.end(),greater<pair<int,int>>());
//     sort(vp2.begin(),vp2.end(),greater<pair<int,int>>());
//     sort(left1.begin(),left1.end(),greater<pair<int,int>>());
//     sort(left2.begin(),left2.end(),greater<pair<int,int>>());
//     int cnt = 1;
//     for(int i=0;i<left1.size();i++) ans1[left1[i].second] = cnt,cnt++;
//     for(int i=0;i<vp1.size();i++) ans1[vp1[i].second] = cnt,cnt++;
//     cnt = 1;
//     for(int i=0;i<left2.size();i++) ans2[left2[i].second] = cnt,cnt++;
//     for(int i=0;i<vp2.size();i++) ans2[vp2[i].second] = cnt,cnt++;
//     int count1 = 0,count2 = 0;
//     for(int i=1;i<n-1;i++){
//         int f = ans1[i-1]+arr[i-1];
//         int s = ans1[i]+arr[i];
//         int t = ans1[i+1]+arr[i+1];
//         if(f<s && s>t) count1++;
//     }
//     for(int i=1;i<n-1;i++){
//         int f = ans2[i-1]+arr[i-1];
//         int s = ans2[i]+arr[i];
//         int t = ans2[i+1]+arr[i+1];
//         if(f<s && s>t) count2++;
//     }
//     if(count1>count2) print(ans1);
//     else print(ans2);
// }

// Cat, Fox and the Lonely Array
// bool check(int k,int n,int arr[],int target){
//     int l =0,r=0;
//     int hsn[30] = {0};
//     while(r<n){
//         int num = 0;
//         for(int i=0;i<30;i++){
//             if((arr[r]>>i)&1) hsn[i]++;
//             if(hsn[i]) num+=(1<<i);
//         }

//         if(r-l+1==k){
//             if(num != target) return false;
//             for(int i=0;i<30;i++){
//                 if((arr[l]>>i)&1) hsn[i]--;
//             }
//             l++;
//         }
//         r++;
//     }
//     return true;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int target = 0;
//     for(int i=0;i<n;i++) target|=arr[i];
//     int lo =1 ,hi = n;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,n,arr,target)) hi = mid-1;
//         else lo = mid+1;
//     }
//     cout<<lo<<endl;
// }

// XOUR
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,priority_queue<int>> mp;
//     for(int i=0;i<n;i++){
//         mp[arr[i]>>2].push(-arr[i]);
//     }
//     for(int i=0;i<n;i++){
//         cout<<-mp[arr[i]>>2].top()<<" ";
//         mp[arr[i]>>2].pop();
//     }
//     cout<<endl;
// }

// Circle Perimeter

// int find(int n){
//     int ans = 2*n-1;
//     for(int i=1;i<n;i++){
//         int num = n*n-i*i;
//         int y = sqrt(num);
//         if(y*y==num) y--;
//         ans += 2*(2*y+1);
//     }
//     return ans;
// }

// void solve(){
//     int n;cin>>n;
//     int num1 = find(n);
//     int num2 = find(n+1);
//     int ans = num2-num1;
//     cout<<ans<<endl;

// }

// Find the Car
// void solve(){
//     int n,k,q;
//     cin>>n>>k>>q;
//     vector<int> a(k+1,0),b(k+1,0);
//     for(int i=1;i<=k;i++) cin>>a[i];
//     for(int i=1;i<=k;i++) cin>>b[i];
//     while(q--){
//         int d;cin>>d;
//         int ind = lower_bound(a.begin(),a.end(),d)-a.begin();
//         int ans = 0;
//         // cout<<ind<<"*"<<endl;
//         if(a[ind]==d) ans = b[ind];
//         else{
//             ans = b[ind-1] + (d-a[ind-1])*(b[ind]-b[ind-1])/(a[ind]-a[ind-1]);
//         }
//         cout<<ans<<" ";
//     }
//     cout<<endl;

// }

// Game on Tree (Medium)
// void dfs(int node,int par,vector<int> adj[],vector<bool> &dp,int cnt){
//     if(cnt&1) dp[node] = false;
//     else dp[node] = true;
//     for(int it : adj[node]){
//         // cout<<it<<" "<<node<<endl;
//         if(it == par) continue;
//         cnt++;
//         dfs(it,node,adj,dp,cnt);
//         cnt--;
//         if(cnt&1){
//             if(dp[it]==1) dp[node] = 1;
//         }else{
//             if(dp[it]==0) dp[node] = 0;
//         }
//     }
// }

// void solve(){
//     int n,t;
//     cin>>n>>t;
//     vector<int> adj[n+1];
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<bool> dp(n+1,0);
//     int pos;cin>>pos;
//     dfs(pos,-1,adj,dp,1);
//     if(dp[pos]) cout<<"Ron"<<endl;
//     else cout<<"Hermione"<<endl;
// }

// Minimizing the Sum
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<vector<int>> dp(n+1,vector<int>(k+1,1e18));
//     // intializing the values
//     int sum = 0;
//     for(int i=0;i<=k;i++) dp[0][i] = 0;
//     for(int i=1;i<=n;i++) sum += arr[i-1],dp[i][0] = sum;
//     for(int i=1;i<=n;i++){
//         // dp[i][0] = min(dp[i][0],dp[i-1][k]+arr[i-1]);
//         for(int j=1;j<=k;j++){
//             int _min = arr[i-1];
//             for(int l=0;l<=j;l++){
//                 int diff = i-l;
//                 if(diff<1){
//                     dp[i][j] = dp[i][j-1];
//                     continue;
//                 }
//                 _min = min(_min,arr[diff-1]);
//                 int calc = _min*(l+1) + dp[diff-1][j-l];
//                 // cout<<i<<" "<<j<<" "<<diff<<" "<<_min<<" "<<calc<<endl;
//                 dp[i][j] = min(dp[i][j],calc);
//             }
//             // if(j!=0) dp[i][j] = min(dp[i][j],dp[i][j-1]);
//         }
//     }

//     cout<<dp[n][k]<<endl;
// }

// Cells Arrangement
// void solve(){
//     int n;cin>>n;
//     cout<<1<<" "<<1<<endl;
//     cout<<1<<" "<<2<<endl;
//     int x = 3,y=3;
//     while(x<=n){
//         cout<<x<<" "<<y<<endl;
//         x++,y++;
//     }
//     cout<<endl;
// }

// Permutation Game
void solve(){
    int n,k,pb,ps;
    cin>>n>>k>>pb>>ps;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }
    // solve();
    return 0;
}