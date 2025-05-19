#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Count Subarrays
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> hsn(n+1,0);
//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j=i;j<n;j++){
//             sum+=arr[j];
//             if(sum>n) break;
//             hsn[sum]++;
//         }
//     }
//     for(int i=1;i<=n;i++) cout<<hsn[i]<<" ";
//     cout<<endl;
// }

// const int p = 998244353;
 
// int power(int a, int b)
// {
//     int result = 1;
//     while (b) {
//         if (b & 1)
//             result = (result * a) % p;
//         a = (a * a) % p;
//         b >>= 1;
//     }
//     return result;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     // int ans = 1;
//     // if(n&1) ans = ((n*(power(2,n-2)-1)*(power(2,k)-1))+ans)%p;
//     // else ans= (((power(2,n-1)-1)*(power(2,k)-1))+ans)%p;
//     if(k==0){
//         cout<<1<<endl;
//         return;
//     }
//     // cout<<power(2,n-1)<<endl;
//     int ans = (power(power(2,n-1),k))%p;
//     cout<<ans<<endl;
// }

// bool cmp(pair<int,int> x,pair<int,int> y){
//     if(x.first==y.first) return x.second>y.second;
//     return  x.first>y.first;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[2*n];
//     for(int i=0;i<2*n;i++) cin>>arr[i];
//     vector<int> first(n+1,-1),last(n+1,0);
//     for(int i=0;i<2*n;i++){
//         if(first[arr[i]]==-1) first[arr[i]]=i;
//         else last[arr[i]] = i;
//     }
//     vector<pair<int,int>> v;
//     for(int i=1;i<=n;i++){
//         int diff = last[i]-first[i];
//         v.push_back({diff,i});
//     }
//     sort(v.begin(),v.end(),cmp);
//     for(int i=0;i<n;i++) cout<<v[i].second<<" ";
//     cout<<endl;
// }

// Construct Permutation
void solve(){
    int n,k;
    cin>>n>>k;

    int mx = (n-1)*(n-1);
    int mn = (n*(n-1))/2;

    if(k>mx || k<mn){
        cout<<-1<<endl;
        return;
    }

    int lo = 2,hi=n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(((mid-1)*(mid-2))/2>k) lo = mid+1;
        else hi = mid-1; 
    }
    cout<<lo<<" "<<hi<<endl;
    vector<int> ans;
    if(((lo-1)*(lo-2))/2!=k) cout<<-1<<endl;
    else{
        for(int i=1;i<n;i++){
            if(i==k) ans.push_back(n);
            else ans.push_back(i);
;        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}