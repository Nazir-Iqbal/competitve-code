#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     int len = 2*n;
//     int arr[len];
//     for(int i=0;i<len;i++) cin>>arr[i];
//     sort(arr,arr+len);
//     int sum = 0;
//     for(int i=0;i<len;i+=2) sum+=arr[i];
//     cout<<sum<<'\n';
// }

// Permutation Printing
// void solve(){
//     int n;cin>>n;
//     vector<int> ans;
//     for(int i=1;i<=n/2;i++){
//         ans.push_back(i);
//         ans.push_back(n-i+1);
//     }
//     if(n&1) ans.push_back((n+1)/2);
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<'\n';
// }

// Lexicographically Largest
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     set<int> s;
//     for(int i=n-1;i>=0;i--){
//         arr[i]+=(i+1);
//     }
//     sort(arr,arr+n,greater<int>());
//     int _min = arr[0];
//     for(int i=1;i<n;i++){
//         if(arr[i]>=_min){
//             _min--;
//             arr[i] = _min;
//             // cout<<i<<" "<<arr[i]<<endl;
//         }else _min = arr[i];
//     }
//     vector<int> ans;
//     for(int ele : arr) ans.push_back(ele);
//     for(int &ele : ans) cout<<ele<<' ';
//     cout<<'\n';
// }

// Sum over all Substrings
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int temp = 0;
//             for(int k=i;k<=j;k++){
//                 if(s[k] == '1') temp++,k+=2;
//             }
//             ans += temp;
//         }
//     }
//     cout<<ans<<'\n';
// }

// Sum over all Substrings
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int> dp(n+3,0);
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            dp[i] = dp[i+3] + (n-i);
        }else dp[i] = dp[i+1];
        ans += dp[i];
    }
    cout<<ans<<'\n';
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