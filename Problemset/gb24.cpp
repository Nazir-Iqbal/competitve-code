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
//     for(int i=0;i<n-1;i++){
//         if(!((arr[i]/arr[i+1] > 1) || (arr[i+1]/arr[i] > 1))){
//             cout<<"Yes"<<endl;
//             return ;
//         }
//     }
//     cout<<"No"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     vector<int> hsn(2*n+10,0);
//     vector<pair<int,int>> vp;
//     string ans;
//     for(int i=0;i<n;i++){
//         int l,r;
//         cin>>l>>r;
//         vp.push_back({l,r});
//         if(l==r){
//             hsn[l]++;
//         }
//     }
//     vector<int> prefix(2*n+10,0);
//     for(int i=0;i<2*n+10;i++) prefix[i] = (hsn[i]>0)?1:0;
//     for(int i=1;i<2*n+10;i++) prefix[i] += prefix[i-1];
//     for(int i=0;i<n;i++){
//         int l = vp[i].first, r = vp[i].second;
//         int sum = prefix[r]-prefix[l-1];
//         if(l == r){
//             if(hsn[l] > 1) ans.push_back('0');
//             else ans.push_back('1');
//         }else{
//             if((r-l+1)==sum) ans.push_back('0');
//             else ans.push_back('1');
//         }
//     }
//     cout<<ans<<endl;
// }

// using the shifting
// pair<int,int> f(int l,int r,int k,map<int,pair<int,int>> &dp){
//     int len = (r-l+1);
//     if(l>r || len < k ) return {0,0};

//     if(dp.find(len) != dp.end()){
//         return {dp[len].first + dp[len].second*(l-1) , dp[len].second};
//     }

//     int mid = (len+1)/2;
//     if(len&1){
//         if(len != 1){
//             pair<int,int> left = f(l,mid-1,k,dp);
//             pair<int,int> right = f(mid+1,r,k,dp);
//             pair<int,int> lr = {left.first+right.first + mid, left.second + right.second + 1};
//             dp[len] = {lr.first - (l-1)*lr.second,lr.second};
//             return lr;
//         }else{
//             dp[1] = {1,1};
//             return {l,1};
//         }
//     }else{
//         pair<int,int> left = f(l,mid,k,dp);
//         pair<int,int> right = f(mid+1,r,k,dp);
//         pair<int,int> lr = {left.first+right.first, left.second + right.second};
//         dp[len] = {lr.first - (l-1)*lr.second,lr.second};
//         return lr;
//     }
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     map<int,pair<int,int>> dp;
//     cout<<f(1,n,k,dp).first<<endl;
// }

// using the symmetry to solve the problem
void solve(){
    int n,k;
    cin>>n>>k;
    int cur = 1,sum = 0;
    int mul = (n+1);
    while(n>=k){
        if(n&1) sum += cur;
        n>>=1;
        cur<<=1;
    }
    cout<<mul*sum/2<<endl;
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