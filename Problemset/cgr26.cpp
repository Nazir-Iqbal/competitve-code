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

// Strange Splitting
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,int> m;
//     for(int i=0;i<n;i++) m[arr[i]]++;
//     int ind = 0,cnt = 0;
//     for(auto ele : m){
//         if(ele.second >= cnt){
//             ind = ele.first;
//             cnt =ele.second;
//         }
//     }
//     if(m.size()==1){
//         cout<<"No"<<endl;
//         return;
//     }else{
//         cout<<"Yes"<<endl;
//         bool flag = true;
//         for(int i=0;i<n;i++){
//             if(arr[i] == ind && flag) cout<<"B",flag = false;
//             else cout<<"R";
//         }
//         cout<<endl;
//     }
// }

// Large Addition
// void solve(){
//     string s;cin>>s;
//     int n = s.size();
//     for(int i=0;i<n-1;i++){
//         if(s[i] == '0'){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     if(s[0] > '1' || s[n-1]=='9') cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
    
// }

// Magnitude (Easy Version)
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int with=0,without=0;
//     for(int i=0;i<n;i++){
//         // cout<<with<<" "<<without<<endl;
//         int temp1 = min(without+arr[i],with+arr[i]);
//         int temp2 = max(abs(with+arr[i]),abs(without+arr[i]));
//         with = temp2,without=temp1;
//     }
//     cout<<max(with,abs(without))<<endl;
// }

// method 2 : applying operation only ones
// that will at the mininmum point of the array
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int sum = 0,mn = 0;
//     for(int i=0;i<n;i++){
//         sum += arr[i];
//         mn = min(sum,mn);
//     }
//     // cout<<sum<<" "<<mn<<endl;
//     cout<<sum-2*mn<<endl;
// }

// Magnitude (Hard Version)
// int mod = 998244353;
// // int cnt = 0;
// int ways(vector<int> &arr,int ind,int num,int &ans,int &n,unordered_map<int,int> dp[]){
//     // cnt++;
//     if(ind==n){
//         // cout<<num<<endl;
//         if(num == ans) return 1;
//         else return 0;
//     }

//     if(dp[ind].find(num) != dp[ind].end()) return dp[ind][num];
//     if(num+arr[ind] == abs(num+arr[ind])) return dp[ind][num] = (2*ways(arr,ind+1,num+arr[ind],ans,n,dp))%mod;
//     else return dp[ind][num] = (ways(arr,ind+1,num+arr[ind],ans,n,dp)+ways(arr,ind+1,abs(num+arr[ind]),ans,n,dp))%mod;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int with=0,without=0;
//     // vector<int> dp[n+1][2] = {0};
//     // dp[0][0] = 1,dp[0][1] = 1;
//     for(int i=0;i<n;i++){
//         // cout<<with<<" "<<without<<endl;
//         int temp1 = min(without+arr[i],with+arr[i]);
//         int temp2 = max(abs(with+arr[i]),abs(without+arr[i]));
//         with = temp2,without=temp1;
//     }
//     int ans = max(with,abs(without));
//     // cout<<ans<<endl;
//     unordered_map<int,int> dp[n+1];
//     int total = ways(arr,0,0,ans,n,dp);
//     // cout<<dp[{0,0}]<<" "<<total<<endl;
//     // cout<<pow(2,24)<<endl;
//     // cout<<cnt<<"*"<<endl;
//     cout<<dp[0][0]<<nline;
// }

// method 2
int mod = 998244353;

long long power(long long a, long long b){
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum = 0,mn = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        mn = min(sum,mn);
    } sum = 0;
    if(mn==0){
        cout<<power(2,n)<<nline;
        return;
    }
    int ans=0,neg=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0) neg++;
        if(sum == mn) ans = (ans+power(2,n-neg))%mod;
    } 
    cout<<ans<<nline;
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