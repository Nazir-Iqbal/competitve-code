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
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> mat(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++) cin>>mat[i][j];
//     }

//     if(n==1 && m==1){
//         cout<<-1<<endl;
//         return;
//     }
//     if(m==1){
//         vector<int> temp(n);
//         for(int i=0;i<n;i++) temp[(i+1)%n] = mat[i][0];
//         for(int i=0;i<n;i++) mat[i][0] = temp[i];
//     }else{
//         for(int i=0;i<n;i++){
//             vector<int> temp(m);
//             for(int j=0;j<m;j++) temp[(j+1)%m] = mat[i][j];
//             for(int j=0;j<m;j++) mat[i][j] = temp[j];
//         }
//     }

//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cout<<mat[i][j]<<" ";
//         cout<<endl;
//     }
// }

// Fun Game
// void solve(){
//     int n;cin>>n;
//     string s,t;
//     cin>>s>>t;
//     for(int i=0;i<n;i++){
//         if(s[i] == '1') break;
//         if(s[i]!=t[i]){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Hungry Games
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> prefix(n+1,0);
//     for(int i=1;i<=n;i++) prefix[i] = prefix[i-1]+arr[i-1];
//     vector<int> dp(n+1,0);
//     for(int i=n;i>=1;i--){
//         int total = x + prefix[i-1]+1;
//         int ind = lower_bound(prefix.begin()+i,prefix.end(),x+prefix[i-1]+1) - prefix.begin();
//         // cout<<ind<<"*"<<total<<endl;
//         if(ind > n) dp[i] = n-i+1;
//         else if (ind == n) dp[i] = n-i; // where the first sum greater than x is the last no.
//         else dp[i] = dp[ind+1] + ind-i;
//     }
//     // for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
//     // cout<<endl;

//     int ans = 0;
//     for(int i=1;i<=n;i++) ans += dp[i];
//     cout<<ans<<endl;
// }

// Funny Game
void solve(){
    // answer is always possible due to pigeonhole principle
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<pair<int,int>> edges;
    vector<bool> used(n,1);
    for(int i=n-1;i>=1;i--){
        vector<int> hsn(i,-1);
        for(int j=0;j<n;j++){
            if(used[j]){
                if(hsn[arr[j]%i]!=-1){
                    edges.push_back({hsn[arr[j]%i]+1,j+1});
                    used[hsn[arr[j]%i]] = 0;
                    break;
                }
                hsn[arr[j]%i] = j;
            }
        }
    }
    reverse(edges.begin(),edges.end());
    cout<<"Yes"<<endl;
    for(auto &ele : edges) cout<<ele.first<<" "<<ele.second<<endl;
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