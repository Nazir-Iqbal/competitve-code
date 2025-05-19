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

// Primary Task
// void solve(){
//     string s;cin>>s;
//     int n = s.length();
//     if(n<=2){
//         cout<<"No"<<endl;
//         return;
//     }
//     if(s[0]!='1' || s[1]!='0'){
//         cout<<"No"<<endl;
//         return;
//     }
//     if(s[2]=='0'){
//         cout<<"No"<<endl;
//         return;
//     }
//     int num = 0,ten = 1;
//     for(int i=2;i<n;i++){
//         num *= ten;
//         num += (s[i]-'0');
//         ten*=10;
//     }
//     if(num>=2) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Seating in a Bus
// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     vector<bool> seat(n+1,0);
//     seat[arr[1]] = 1;
//     for(int i=2;i<=n;i++){
//         int pos = arr[i];
//         bool flag = true;
//         int left = pos-1,right = pos+1;
//         if(left>=1 && seat[left]==1) flag = false;
//         if(right<=n && seat[right]==1) flag = false;
//         seat[pos] = 1;
//         if(flag){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Numeric String Template
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,vector<int>> mp;
//     for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
//     int q;cin>>q;
//     while(q--){
//         string s;cin>>s;
//         int sz = s.size();
//         bool flag = true;
//         if(sz != n)flag = false;
//         vector<int> hsn(26,0);
//         for(auto ele : mp){
//             set<char> st;
//             for(int i: ele.second){
//                 st.insert(s[i]);
//                 hsn[s[i]-'a']++;
//             }
//             if(st.size()>1){
//                 flag = false;
//                 break;
//             }
//             if(ele.second.size()!=hsn[(*st.begin())-'a']){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// Right Left Wrong
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     string s;cin>>s;
//     int l =0,r=n-1,cnt = 0,ans = 0;
//     while(l<=r){
//         while(l<=r && s[l]!='L'){
//             ans += cnt*arr[l];
//             l++;
//         }
//         if(l<=r && s[r] != 'R'){
//             ans += cnt*arr[r];
//             r--;
//         }
//         if(l<=r && s[r] == 'R' && s[l] == 'L'){
//             cnt++;
//             ans += cnt*(arr[l]+arr[r]);
//             l++,r--;
//         }
//         // cout<<l<<" "<<r<<" "<<cnt<<" "<<ans<<endl;
//     }
//     cout<<ans<<endl;
// }

// Photoshoot for Gorillas
// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<vector<int>> adj(n,vector<int>(m,0));
//     int w;cin>>w;
//     int arr[w];
//     for(int i=0;i<w;i++) cin>>arr[i];
//     sort(arr,arr+w);
//     vector<int> markx(n+1,0),marky(m+1,0);
//     for(int i=0;i<n-k+1;i++) markx[i]++,markx[i+k]--;
//     for(int i=0;i<m-k+1;i++) marky[i]++,marky[i+k]--;
//     for(int i=1;i<=n;i++) markx[i] += markx[i-1];
//     for(int i=1;i<=m;i++) marky[i] += marky[i-1];
//     priority_queue<int> pq;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             adj[i][j] = markx[i]*marky[j];
//             pq.push(-adj[i][j]);
//             if(pq.size()>w) pq.pop();
//         }
//     }
//     int ans = 0;
//     for(int i=0;i<w;i++){
//         int num = -pq.top();
//         pq.pop();
//         ans += num*arr[i];
//     }
//     cout<<ans<<endl;
// }

// Color Rows and Columns
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    // cout<<"*"<<endl;
    vector<vector<int>> op(n+1,vector<int>(k+1,1e18));
    op[0][0] = 0;
    for(int i=1;i<=n;i++){
        int row = a[i],col = b[i];
        for(int j=0;j<=row;j++){
            for(int l=0;l<=col;l++){
                int calc = row*l + col*j - j*l;
                op[i][min(j+l,k)] = min(op[i][min(j+l,k)],calc);
            }
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,1e18));
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            int total = a[i] + b[i];
            for(int l=0;l<=total;l++){
                if(dp[i-1][max(j-l,0ll)]>=1e18) continue;
                int calc = op[i][min(l,k)] + dp[i-1][max(j-l,0ll)];
                dp[i][j] = min(dp[i][j],calc);
            }
        }
    }
    if(dp[n][k]>=1e18) cout<<-1<<endl;
    else cout<<dp[n][k]<<endl;
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