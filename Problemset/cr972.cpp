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
//     string test = "aeiou";
//     int n;cin>>n;
//     int req = n/5,rem = n%5;
//     string ans;
//     for(int i=0;i<5;i++){
//         if(rem>0) ans.push_back(test[i]),rem--;
//         int temp = req;
//         while(temp) ans.push_back(test[i]),temp--;
//     }
//     cout<<ans<<endl;
// }

// The Strict Teacher (Easy Version)
// void solve(){
//     int n,m,q;
//     cin>>n>>m>>q;
//     vector<int> arr(m,0);
//     for(int i=0;i<m;i++) cin>>arr[i];
//     sort(arr.begin(),arr.end());
//     while(q--){
//         int d;cin>>d;
//         int ans = -1;
//         if(d<arr[0]) ans = arr[0]-1;
//         else if(d>arr[m-1]) ans = n-arr[m-1];
//         else{
//             int ind = upper_bound(arr.begin(),arr.end(),d)-arr.begin();
//             ans = (arr[ind]-arr[ind-1])/2;
//         }
//         cout<<ans<<endl;
//     }
// }

// Lazy Narek
string test = "narek";
bool check(char c){
    for(int i=0;i<5;i++){
        if(test[i] == c) return true;
    }
    return false;
}
int finder(int i,int j,vector<string> &v,int n,int m,vector<vector<int>> &dp){
    // base case
    if(i==n) return -2*j; // removing the score from the own and adding to gpt for the 
    // left out characters
    if(dp[i][j] !=-1) return dp[i][j];
    // not taken
    int notake = finder(i+1,j,v,n,m,dp);
    // taken
    int take = 0,ind = j;
    for(int k=0;k<m;k++){
        if(v[i][k] == test[ind]) ind = (ind+1)%5,take++;
        else if(check(v[i][k])) take--;
    }
    take += finder(i+1,ind,v,n,m,dp);
    return dp[i][j] = max(take,notake);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> dp(n,vector<int>(5,-1));
    cout<<finder(0,0,v,n,m,dp)<<endl;
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