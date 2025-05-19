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
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int ans = arr[n-1]-arr[0];
//     ans = min(ans,arr[n-2]-arr[1]);
//     ans = min(ans,arr[n-3]-arr[0]);
//     ans = min(ans,arr[n-1]-arr[2]);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<string> v(m);
//     for(int i=0;i<m;i++) cin>>v[i];
//     int pre[n][2] = {0};
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(v[i][j] == '0') pre[j][0]++;
//             else if(v[i][j] == '1') pre[j][1]++;
//         }
//     }
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int left = m - pre[i][0]-pre[i][1];
//         if(m&1){
//             int mid = (m+1)/2;
//             if(pre[i][0]<mid && pre[i][1]<mid)pre[i][0] = mid-1,pre[i][1] = mid;
//             else if(pre[i][0]<mid) pre[i][0] += left;
//             else pre[i][1] += left;
//         }else{
//             int mid = (m)/2;
//             if(pre[i][0]<mid && pre[i][1]<mid) pre[i][0] = mid,pre[i][1] = mid;
//             else if(pre[i][0]<mid) pre[i][0] += left;
//             else pre[i][1] += left;
//         }
//     }
//     for(int i=0;i<n;i++) ans += (pre[i][0]*pre[i][1]);
//     cout<<ans<<endl;
// }

// Anti-Palindrome Queries
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int prefix[n+1][3] = {0};
//     for(int i=1;i<=n;i++){
//         if(arr[i-1]==1) prefix[i][0]++;
//         else if(arr[i-1]==2) prefix[i][1]++;
//         else prefix[i][2]++;
//     }
//     for(int i=2;i<=n;i++){
//         prefix[i][0] += prefix[i-1][0];
//         prefix[i][1] += prefix[i-1][1];
//         prefix[i][2] += prefix[i-1][2];
//     }
//     // for(int i=1;i<=n;i++) cout<<prefix[i][0]<<" "<<prefix[i][1]<<" "<<prefix[i][2]<<endl;
//     for(int i=1;i<=m;i++){
//         int one=0,two=0,three=0;
//         int l,r;
//         cin>>l>>r;
//         one = prefix[r][0]-prefix[l-1][0];
//         two = prefix[r][1]-prefix[l-1][1];
//         three = prefix[r][2]-prefix[l-1][2];
//         // cout<<one<<" "<<two<<" "<<three<<endl;
//         int sz = r-l+1;
//         int mid = sz/2;
//         if(sz&1){
//             cout<<"No"<<endl;
//         }else{
//             if(one!=mid && two!=mid && three!=mid){
//                 cout<<"No"<<endl;
//             }else cout<<"Yes"<<endl;
//         }
//     }
// }

// Completion (Easy)
const int N = 2e5+7;
int fact[N];
int mod = 998244353;

void pre(){
    fact[0] = 1;
    for(int i=1;i<N;i++) fact[i] = (fact[i-1]*i)%mod;
}

// void solve(){
//     int n;cin>>n;
//     int arr[2*n];
//     // for(int i=0;i<10;i++) cout<<i<<" "<<fact[i]<<endl;
//     vector<bool> vis(2*n+1,0);
//     for(int i=0;i<2*n;i++) cin>>arr[i],vis[arr[i]]=1;
//     int u=0,l=0;
//     for(int i=0;i<2*n;i++){
//         if(arr[i] == 0) continue;
//         if(arr[i]<=n){
//             bool flag = false;
//             if(i>0 && arr[i-1]==0) flag = true;
//             else if(i<2*n-1 && arr[i+1]==0) flag=true;
//             if(flag) l++;
//         }else{
//             bool flag = false;
//             if(i>0 && arr[i-1]==0) flag = true;
//             else if(i<2*n-1 && arr[i+1]==0) flag=true;
//             if(flag) u++;
//         }
//     }
//     int leftl=0,leftu = 0;
//     for(int i=1;i<=2*n;i++){
//         if(!vis[i]){
//             if(i<=n) leftl++;
//             else leftu++;
//         }
//     }

//     int ans = 1;
//     ans = (ans * fact[leftl]*fact[leftu])%mod;
//     for(int i=0;i<2*n;i+=2){
//         if(arr[i]==0) ans = (ans*2)%mod;
//     }
//     cout<<ans<<endl;
// }

// Completion (Hard)
void solve(){
    int n;cin>>n;
    int arr[2*n];
    for(int i=0;i<2*n;i++) cin>>arr[i];
    int pairs = 0;
    vector<int> temp;
    set<int> left,right;
    vector<bool> vis(2*n+1,0);
    for(int i=0;i<2*n;i+=2){
        if(arr[i]==0 && arr[i+1]==0) pairs++;
        if(arr[i]!=0 && arr[i+1]!=0) vis[arr[i]]=1,vis[arr[i+1]]=1;
    }
    for(int i=1;i<=2*n;i++){
        if(!vis[i]) temp.push_back(i);
    }
    int sz = temp.size();
    for(int i=0;i<sz/2;i++) left.insert(temp[i]);
    for(int i=sz/2;i<sz;i++) right.insert(temp[i]);
    int l=sz/2,u=sz/2;
    for(int i=0;i<2*n;i++){
        if(vis[arr[i]] || arr[i]==0) continue;
        else{
            // cout<<arr[i]<<endl;
            if(left.find(arr[i])!=left.end()) l--;
            else if(right.find(arr[i])!=right.end())u--;
        }
    }
    // cout<<l<<" "<<u<<endl;
    int ans = (fact[l]*fact[u])%mod;
    for(int i=0;i<pairs;i++) ans = (ans * 2)%mod;
    cout<<ans<<endl;
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