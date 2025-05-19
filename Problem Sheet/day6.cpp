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
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     sort(a,a+n),sort(b,b+n);
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int local = INT_MAX;
//         for(int j=0;j<n;j++){
//             local = min(local,abs(a[(i+j)%n]-b[j]));
//         }
//         ans = max(ans,local);
//     }
//     cout<<ans<<endl;
// }

// Tandem Repeats?
// bool check(int n,string &s,int len){
//     int cnt = 0;
//     int l = 0,r=0;
//     while(r<n-len){
//         if(s[r]==s[r+len] || s[r] =='?' || s[r+len]=='?') cnt++;
//         if(r-l+1>len){
//             if(s[l]==s[l+len] || s[l] =='?' || s[l+len]=='?') cnt--;
//             l++;
//         }
//         if(cnt == len){
//             return true;
//         }
//         r++;
//     }
//     return false;
// }

// void solve(){
//     string s;cin>>s;
//     int n = s.size();
//     int ans = 0;
//     // for(int i=0;i<n;i++){
//     //     for(int j=i;j<n;j++){
//     //         int diff = j-i+1;
//     //         int last = j+diff;
//     //         if(last>=n) break;
//     //         bool flag = true;
//     //         for(int k=1;k<=diff;k++){
//     //             if(s[i+k-1]=='?' || s[j+k]=='?') continue;
//     //             if(s[i+k-1]!=s[j+k]){
//     //                 flag = false;
//     //                 break;
//     //             }
//     //         }
//     //         if(flag) ans = max(ans,2*diff);
//     //     }
//     // }

//     // solving using the dp
//     // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//     // for(int i=n-2;i>=0;i--){
//     //     for(int j=i+1;j<n;j++){
//     //         if(s[i]==s[j] || s[i]=='?' || s[j] == '?') dp[i][j] = 1+dp[i+1][j+1];
//     //         else dp[i][j] = 0;
//     //         dp[i][j] = min(dp[i][j],j-i);
//     //         if(dp[i][j] == j-i){
//     //             ans = max(ans,(j-i));
//     //         }
//     //     }
//     // }
//     // cout<<2*ans<<endl;

//     // using the two pointers
//     int len = n/2;
//     // cout<<check(n,s,2)<<endl;
//     for(int i=1;i<=len;i++){
//         if(check(n,s,i)) ans = i;
//     }
//     cout<<2*ans<<endl;
// }

// Arrow Path
// void solve(){
//     int n;cin>>n;
//     string a,b;
//     cin>>a>>b;
//     int j=0;
//     for(int i=1;i<n;i++){
//         if(j==0){
//             if(i&1){
//                 if(a[i] == '<'){
//                     if(b[i-1]=='<'){
//                         cout<<"No"<<endl;
//                         return;
//                     }else j=1;
//                 }
//             }
//         }else{
//             if(i%2==0){
//                 if(i==n-1){
//                     cout<<"Yes"<<endl;
//                     return;
//                 }
//                 if(b[i] == '<'){
//                     if(a[i-1]=='<'){
//                         cout<<"No"<<endl;
//                         return;
//                     }else j = 0;
//                 }
//             }
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Tree Cutting
// calculating the cuts for the size x
// int dfs(int node,int par,vector<int> adj[],int x,int &cnt){
//     int sum = 1;
//     for(int it : adj[node]){
//         if(par == it) continue;
//         int res = dfs(it,node,adj,x,cnt);
//         if(res>=x) cnt++;
//         else sum += res;
//     }
//     if(sum>=x) cnt++,sum = 0;
//     return sum;
// }

// bool check(vector<int> adj[],int x,int k){
//     int cut = 0;
//     dfs(1,-1,adj,x,cut);
//     cut--;
//     if(cut>=k) return true;
//     return false;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> adj[n+1];
//     for(int i=0;i<n-1;i++){
//         int u,v;cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int lo=1,hi=1e9;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(adj,mid,k)) lo = mid+1;
//         else hi = mid-1;
//     }
//     cout<<hi<<endl;
// }

// Binary Search
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     int arr[n+1];
//     int pos = 0;
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//         if(arr[i] == x) pos = i;
//     }
//     if(n==1){
//         cout<<0<<endl;
//         return;
//     }
//     int l = 1 ,r = n+1;
//     int lastl = 0,lastmid = 0;
//     while(r-l>1){
//         int mid = (r+l)/2;
//         if(arr[mid]<=x) l = mid;
//         else r = mid;
//         lastl = l;
//         lastmid = mid;
//     }
//     if(lastl != 1){
//         cout<<1<<endl;
//         cout<<pos<<' '<<lastl<<endl;
//     }else{
//         cout<<2<<endl;
//         cout<<pos<<' '<<lastmid<<endl;
//         swap(arr[pos],arr[lastmid]);
//         l = 1 ,r = n+1;
//         while(r-l>1){
//             int mid = (r+l)/2;
//             if(arr[mid]<=x) l = mid;
//             else r = mid;
//             lastl = l;
//         }
//         cout<<lastmid<<" "<<lastl<<endl;
//     }
// }

// Seraphim the Owl
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int res = 0;
    for(int i=m+1;i<=n;i++) res += min(a[i],b[i]);
    int ans = 1e18,sum = 0;
    for(int i=m;i>=1;i--){
        if(i==1){
            ans = min(res+sum+a[1],ans);
        }
        ans = min(ans,sum+a[i]+res);
        sum += min(a[i],b[i]);
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