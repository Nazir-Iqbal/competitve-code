#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define nline '\n'
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Edit Distance
// void solve(){
//     string a,b;
//     cin>>a>>b;
//     int n = a.size();
//     int m = b.size();
//     // cout<<n<<endl;
//     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//     //intializing the base cases
//     for(int i=0;i<=n;i++) dp[i][0] = i;
//     for(int j=1;j<=m;j++) dp[0][j] = j;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             // if chracters are equal
//             if(a[i-1]==b[j-1]){
//                 dp[i][j] = dp[i-1][j-1];
//             }else{
//                 // case of deleting and adding
//                 int alter = min(dp[i-1][j],dp[i][j-1])+1;
//                 // case of replacing
//                 int rep = dp[i-1][j-1]+1;

//                 // taking minimum of them
//                 dp[i][j] = min(alter,rep);
//             }
//         }
//     }

//     cout<<dp[n][m]<<endl;
// }

// Rectangle Cutting
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));

//     // by cutting the rectangle(iXj) into two pieces we actually deivde it into
//     // two parts of horizonatally or horizontally (iXk,iX(j-k))
//     // vertically (kXj,(i-k)Xj)


//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(i==j) dp[i][j] = 0;
//             else{
//                 // if cur was made verticle
//                 int ver = 1e9;
//                 for(int k=1;k<i;k++ ) ver = min(ver,dp[k][j] + dp[i-k][j]);
//                 // if cut was maid horizontal
//                 int hor = 1e9;
//                 for(int k=1;k<j;k++) hor = min(hor,dp[i][j-k] + dp[i][k]);
//                 dp[i][j] = min(ver+1,hor+1);
//             }
//         }
//     }

//     cout<<dp[n][m]<<endl;
// }

// Money Sums
// void solve(){
//     int n; cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     set<int> prev,cur;
//     prev.insert(0);
//     for(int i=0;i<n;i++){
//         for(int ele : prev){
//             int sum = ele + arr[i];
//             // taking arr[i]
//             cur.insert(sum);
//             // not taking arr[i]
//             cur.insert(ele);
//         }
//         prev = cur;
//         cur.clear();
//     }
//     cout<<prev.size()-1<<'\n';
//     for(int ele : prev){
//         if(ele == 0) continue;
//         cout<<ele<<' ';
//     }
//     cout<<'\n';
// }

// Dima and a Bad XOR
void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    //  dp[i][j] --> xor of no. equals to j in the i the row
    vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>> (1024,{0,0}));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>arr[i][j];
    }
    // base case
    dp[0][0] = {1,0};
    for(int i=1;i<=n;i++){
        for(int j=0;j<=1023;j++){
            // basing through evry element in the row
            for(int k=0;k<m;k++){
                if(dp[i-1][j^arr[i-1][k]].first == 1){
                    // cout<<j<<"*"<<k<<endl;
                    dp[i][j].first = 1;
                    dp[i][j].second = k;
                    break;
                }
            }
        }
    }

    // backtracking the answer
    vector<int> ans;
    for(int j=1;j<1024;j++){
        if(dp[n][j].first==1){
            // cout<<j<<endl;
            int i = n;
            while(i>0){
                // representing the element of the current row
                int ind = dp[i][j].second;
                ans.push_back(ind);
                j ^= arr[i-1][ind];
                i--;
            }
            break;
        }
    }

    reverse(ans.begin(),ans.end());
    if(ans.size()>0){
        cout<<"TAK"<<nline;
        for(int ele : ans) cout<<ele+1<<' ';
        cout<<endl;
    }else{
        cout<<"NIE"<<nline;
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;

    solve();

    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }

    return 0;
}