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
//     int ans=(n/4);
//     if(n%4) ans++;
//     cout<<ans<<endl;
// }

// Scale
// void solve(){
//     int n,k;cin>>n>>k;
//     vector<vector<int>> v(n,vector<int>(n,0));
//     for(int i=0;i<n;i++){
//         string temp;cin>>temp;
//         for(int j=0;j<n;j++){
//             if(temp[j] == '1') v[i][j]++;
//         }
//     }
//     vector<vector<int>> ans;
//     for(int i=0;i<n;i+=k){
//         vector<int> temp;
//         for(int j=0;j<n;j+=k) temp.push_back(v[i][j]);
//         ans.push_back(temp);
//     }
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<ans[0].size();j++) cout<<ans[i][j];
//         cout<<endl;
//     }
// }

// Sort
// void solve(){
//     int n,q;cin>>n>>q;
//     string a,b;
//     cin>>a>>b;
//     vector<vector<int>> pre1(n+1,vector<int>(26,0)),pre2(n+1,vector<int>(26,0));
//     // cout<<"*"<<endl;
//     for(int i=1;i<=n;i++) pre1[i][a[i-1]-'a']++;
//     for(int i=1;i<=n;i++) pre2[i][b[i-1]-'a']++;
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<26;j++){
//             pre1[i][j] += pre1[i-1][j];
//             pre2[i][j] += pre2[i-1][j];
//         }
//     }
//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         int diff = 0;
//         for(int i=0;i<26;i++){
//             int cnt1 = pre1[r][i]-pre1[l-1][i];
//             int cnt2 = pre2[r][i]-pre2[l-1][i];
//             diff += abs(cnt1-cnt2);
//         }
//         cout<<diff/2<<endl;
//     }
// }

// Fun
// void solve(){
//     int n,x;cin>>n>>x;
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;i*j<=n && i+j<=x;j++){
//             int sum = i+j,pro = i*j;
//             int div = (n-pro)/sum;
//             ans += min(div,x-sum);
//         }
//     }
//     cout<<ans<<endl;
// }

// Decode
int mod = 1e9+7;
void solve(){
    // cout<<"*"<<endl;
    string s;cin>>s;
    int n = s.length();
    map<int,int> mp;
    int ans = 0,sum = 0;
    mp[0] = 1;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0') sum--;
        else sum++;
        ans = (ans+mp[sum]*(n-i+1))%mod;
        mp[sum] += (i+1);
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