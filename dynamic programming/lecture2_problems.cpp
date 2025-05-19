#include <bits/stdc++.h>

using namespace std;

#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int M = 1e9+7;

// #define int long long

// add one 
// int N = 2e5+1;
// vector<vector<int>> dp(N,vector<int>(10,0));

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     // declaring the dp array
//     // cout<<n<<" "<<m<<endl;

//     // state --> dp[i][j]--> count of j the digit in i th state

//     // initializing the dp array
//     vector<int> digits(10,0);
//     while(n){
//         int num = n%10;
//         n/=10;
//         digits[num]++;
//     }

//     int ans = 0;
//     for(int i=0;i<10;i++){
//         ans = (ans+(digits[i]*dp[m][i])%M)%M;
//     }
//     cout<<ans<<endl;
    
// }
// int M = 1e9+7;
// int n ,m;
// const int N = 1e6+1;
// const int sz = 101;
// int a[sz];
// int dp[sz][N];
 
// int32_t main(){
//     FIO;
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<n;i++) cin>>a[i];
    
//     for(int i=0;i<=m;i++) dp[0][i] = 0;
//     for(int i=0;i<=n;i++) dp[i][0] = 1;

//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(j-a[i-1]>=0) dp[i][j] = (dp[i-1][j] + dp[i][j-a[i-1]])%M;
//             else dp[i][j] = dp[i-1][j];
//         }
//     }

//     cout<<dp[n][m];

//     return 0;
// }

// Removing Digits


// int32_t main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     FIO;
//     // precomputing the values
//     int t;cin>>t;
//     for(int i=0;i<10;i++){
//         // finding for the one occurence of the each digit
//         dp[0][i] = 1;
//     }
//     for(int i=1;i<N;i++){
//         for(int j=1;j<=9;j++){
//             dp[i][j] = (dp[i][j] + dp[i-1][j-1])%M;
//         }
//         // edge case for no. 9;
//         dp[i][0] = (dp[i][0] + dp[i-1][9])%M;
//         dp[i][1] = (dp[i][1] + dp[i-1][9])%M;
//     }
//     while(t--){
//         solve();
//     }
// }

// void solve(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,1e9);

//     dp[0] = 0;

//     // dp[i] --> minimum value to make i to zero

//     for(int i=1;i<=n;i++){
//         int num = i;
//         while(num){
//             int digit = num%10;
//             num/=10;
//             if(i-digit>=0) dp[i] = min(dp[i-digit]+1,dp[i]);
//         }
//     }

//     // for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
//     // cout<<endl;

//     cout<<dp[n]<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<string> v;
//     for(int i=0;i<n;i++){
//         string s;cin>>s;
//         v.push_back(s);
//     }

//     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//     dp[1][1] = 1;


//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             // with no traps at i-1 , j-1
//             if(i==1 && j==1) dp[i][j] = 1;
//             else dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
//             // if there are no. of ways passing through this will become zero
//             if(v[i-1][j-1]=='*') dp[i][j] = 0;
//         }
//     }
//     // for(int i=0;i<=n;i++){
//     //     for(int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
//     //     cout<<endl;
//     // }

//     cout<<dp[n][n];
// }

// void solve(){
//     int n,x;
//     cin>>n>>x;
//     int price[n],pages[n];

//     for(int i=0;i<n;i++) cin>>price[i];
//     for(int i=0;i<n;i++) cin>>pages[i];

//     vector<vector<int>> dp(n+1,vector<int>(x+1,0));

//     // transitions;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=x;j++){
//             if(j-price[i-1]>=0) dp[i][j] = max(dp[i-1][j],dp[i-1][j-price[i-1]] + pages[i-1]);
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
    
//     cout<<dp[n][x];
// }

// Array Description
// void solve(){
//     int n,m;
//     cin>>n>>m;

//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
    
//     // dp[i][j] --> all the possible ways to fill the array up till index i with j as the element
//     vector<vector<long long>> dp(n,vector<long long> (m+2,0));

//     // base case
//     vector<int> prev(m+2,0);
//     for(int i=1;i<=m;i++){
//         if(a[0] != 0){
//             prev[a[0]] = 1;
//             break;
//         }else{
//             prev[i] = 1;
//         }
//     }

//     vector<int> cur(m+2,0);
//     // defining the transitions
//     for(int i=1;i<n;i++){
//         for(int j=1;j<=m;j++){
//             if(a[i]!=0){
//                 cur[a[i]] = (prev[a[i]-1] + prev[a[i]] + prev[a[i]+1])%M;
//                 break;
//             }else{
//                 cur[j] = (prev[j-1] + prev[j] + prev[j+1])%M;
//             }
//         }
//         prev = cur;
//         // reinitializing the array the zeroes
//         for(int i=1;i<=m;i++) cur[i] = 0;
//     }

//     long long ans = 0;
//     for(int i=1;i<=m;i++) ans=(ans + prev[i])%M;
//     cout<<ans;
// }

// Counting Towers
void solve(){
    int n;cin>>n;
    vector<vector<int>> dp(n,vector<int>(2,0));
    // defining the base cases
    dp[n-1][0] = 1,dp[n-1][1] = 1;
    for(int i=n-2;i>=0;i--){
        // takging case one 
        dp[i][0] = (((((((dp[i+1][0]+dp[i+1][0])%M)+dp[i+1][0])%M)+dp[i+1][0])%M) + dp[i+1][1])%M;
        // taking case two
        dp[i][1] = (((dp[i+1][1]+dp[i+1][1])%M) + dp[i+1][0])%M;
    }
    int ans = (dp[0][0] + dp[0][1])%M;
    cout<<ans<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
        solve();
    }

    return  0;
}