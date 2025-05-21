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

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i] != 0){
//             cnt++;
//             while(i<n && arr[i]!=0) i++;
//         }
//     }
//     cout<<min(cnt,2)<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     if(s[0] == 's') s[0]= '.';
//     if(s[n-1] == 'p') s[n-1]='.';
//     unordered_set<char> st;
//     for(int i=0;i<n;i++) if(s[i] != '.') st.insert(s[i]);
//     if(st.size()==2) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// MEX Cycle
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     x--,y--;
//     vector<int> ans(n,0);
//     for(int i=0;i<n;i+=2) ans[i] = 0;
//     for(int i=1;i<n;i+=2) ans[i] = 1;
//     if(n&1) ans[n-1] = 2;
//     if(x>y) swap(x,y);
//     if(y-x>1){
//         if(ans[x] == ans[y]){
//             ans[x] = 2;
//             if(x==0 && n&1){
//                 ans[n-1] = 0;
//             }
//         }
//     }
//     for(int i=0;i<n;i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// Shift + Esc
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> dp(n+1,vector<int>(m+1,1e16+7));
    vector<vector<int>> arr(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>arr[i][j];
    }
    // intitalize
    dp[1][0] = 0;
    for(int rot = 0;rot<m;rot++){
        vector<int> temp(m+1,0);
        for(int j=1;j<=m;j++){
            // cout<<rot<<" "<<(j+rot-1)%m+1<<endl;
            temp[j] = temp[j-1] + arr[1][(j+rot-1)%m+1];
            if(j==1) temp[j] += rot*k;
            dp[1][j] = min(temp[j],dp[1][j]);
        }
    }

    for(int i=2;i<=n;i++){
        for(int rot=0;rot<m;rot++){
            vector<int> temp(m+1,1e16+7);
            for(int j=1;j<=m;j++){
            // handling the rotations
                int cur = (j+rot-1)%m+1;
                // cout<<i<<" "<<rot<<" "<<(j+rot-1)%m+1<<endl;
                int left = temp[j-1] + arr[i][cur];
                int up = dp[i-1][j] + arr[i][cur] + rot*k;
                temp[j] = min(left,up);
                dp[i][j] = min(dp[i][j],temp[j]);
            }
        }
    }

    cout<<dp[n][m]<<nline;
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