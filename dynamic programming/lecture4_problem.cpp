#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

int M = 1e9+7;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


// Removal Game
// void solve(){
//   int n;cin>>n;
//   int arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];

//   // precalculating the sum in the range i->j
//   int sum = 0;
//   for(int i=0;i<n;i++) sum+=arr[i];

//   int dp[n][n] = {0};
//   for(int i=0;i<n;i++) dp[i][i] = arr[i];

//   for(int i=n-1;i>=0;i--){
//     for(int j=i;j<n;j++){
//       if(i==j) continue; // base case;
//       else{
//         // we have two choices 
//         int forward = arr[i] - dp[i+1][j];
//         int backward = arr[j] - dp[i][j-1];
//         dp[i][j] = max(forward,backward);
//       }
//     }
//   }
  
//   cout<<(sum+dp[0][n-1])/2<<endl;
// }


// Two Sets II
// int binpow(int a, int b, int m) {
//     a %= m;
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }

// void solve(){
//   int n;cin>>n;
//   int sum = (n*(n+1))/2;
//   if(sum&1){
//     cout<<0<<endl;
//     return;
//   }
//   sum = sum/2;
//   vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
//   // base case
//   for(int i=0;i<=n;i++) dp[i][0] = 1;

//   for(int i=1;i<=n;i++){
//     for(int j=1;j<=sum;j++){
//       if(i<=j){
//         dp[i][j] = (dp[i-1][j-i] + dp[i-1][j])%M;
//       }else dp[i][j] = dp[i-1][j];
//     }
//   }


//   // modular multiplicative inverse
//   int mmi = binpow(2,M-2,M);

//   cout<<(dp[n][sum]*mmi)%M<<endl;

// }

// Projects
struct job{
  int start,end,pay;
};

bool cmp(job x, job y){
  return x.end < y.end;
}

// binary search
int bin_sr(vector<job> &v,int ele){
  int n=v.size();
  int lo = 0 , hi = n-1;
  while(lo<=hi){
    int mid = (lo+hi)/2;
    if(v[mid].end < ele) lo = mid+1;
    else hi = mid-1;
    // cout<<lo<<" "<<hi<<endl;
  }

  if(v[hi].end<ele) return hi;
  else return -1;
}

void solve(){
  int n;
  cin>>n;
  vector<job> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i].start>>v[i].end>>v[i].pay;
  }
  sort(v.begin(),v.end(),cmp);

  // dp[i] --> maximum sum achievable till i the job
  vector<int> dp(n,0);

  // for(auto ele : v) cout<<ele.end<<" ";
  // cout<<endl;

  // base case 
  dp[0] = v[0].pay;

  for(int i=1;i<n;i++){
    
    int not_take = dp[i-1];
    int take = v[i].pay;

    int ind = bin_sr(v,v[i].start);

    // cout<<v[i].start<<" "<<ind<<endl;

    if(ind == -1) dp[i] = not_take;
    else{
      take += dp[ind];
      dp[i] = max(take,not_take);
    }
    
  }

  cout<<dp[n-1]<<'\n';
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    // FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();

    return 0;
}