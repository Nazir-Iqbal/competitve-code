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

// Yarik and Array
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int l=0,r=0;
//     int ans = INT_MIN,sum = 0;
//     while(r<n){
//         if(r-l+1==1) sum+=arr[r];
//         else if(abs(arr[r-1])%2!=abs(arr[r])%2) sum+=arr[r];
//         else{
//             sum = arr[r];
//             l=r;
//         }
//         ans = max(ans,sum);
//         if(sum<0) sum = 0,l = r+1;
//         r++;
//     }
//     cout<<ans<<endl;
// }

// 250 Thousand Tons of TNT
// vector<int> factors[150001];
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = 0;
//     for(int f : factors[n]){
//         vector<int> temp;
//         int sum = 0;
//         for(int i=0;i<n;i++){
//             sum+=arr[i];
//             if((i+1)%f==0) temp.push_back(sum),sum = 0;
//         }
//         if(temp.size()==0) break;
//         int _max = *max_element(temp.begin(),temp.end());
//         int _min = *min_element(temp.begin(),temp.end());
//         ans = max(ans,_max-_min);
//     }
//     cout<<ans<<endl;
// }

// void pre(){
//     for(int i=1;i<=150000;i++){
//         for(int j=i;j<=150000;j+=i) factors[j].push_back(i);
//     }
// }

// Counting Orders
// int mod = 1e9+7;

// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     sort(a,a+n,greater<int> ());
//     sort(b,b+n,greater<int>());
//     int sum = 0,ans = 1;
//     int cur = 0;
//     for(int i=0;i<n;i++){
//         if(a[i]>b[cur]) sum++;
//         else{
//             // cout<<sum<<" "<<cur<<endl;
//             while(a[i]<=b[cur]){
//                 if(sum - cur <=0){
//                     cout<<0<<endl;
//                     return;
//                 }
//                 ans = (ans*(sum-cur))%mod;
//                 cur++;
//             }
//             sum++;
//         }
//     }
//     for(int i=cur;i<n;i++) ans = (ans*(sum-i))%mod;
//     cout<<ans<<endl;
// }

// Fun with Even Subarrays
// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     int ans = 0,ele = arr[n];
//     for(int i=n-1;i>0;i--){
//         if(arr[i]!=ele){
//             // cout<<i<<endl;
//             ans++;
//             if(i>n/2) i-=(n-i-1);
//             else break;
//         }
//     }
//     cout<<ans<<endl;
// }

// Paint the Array
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int gcd1=arr[0],gcd2=arr[1];
//     for(int i=0;i<n;i+=2) gcd1 = __gcd(arr[i],gcd1);
//     for(int i=1;i<n;i+=2) gcd2 = __gcd(arr[i],gcd2);
//     vector<bool> ans(2,1);
//     for(int i=1;i<n;i+=2){
//         if(arr[i]%gcd1 == 0){
//             ans[0] = false;
//             break;
//         }
//     }
//     for(int i=0;i<n;i+=2){
//         if(arr[i]%gcd2 == 0){
//             ans[1] = false;
//             break;
//         }
//     }
//     if(ans[0]) cout<<gcd1<<nline;
//     else if(ans[1]) cout<<gcd2<<nline;
//     else cout<<0<<nline;
// }

// Yet Another Card Deck
void solve(){
    int n,q;cin>>n>>q;
    vector<int> col(51,-1);
    for(int i=1;i<=n;i++){
        int temp;cin>>temp;
        if(col[temp]==-1) col[temp] = i;
    }
    while(q--){
        int temp;cin>>temp;
        cout<<col[temp]<<" ";
        for(int i=0;i<51;i++){
            if(col[i]<col[temp]) col[i]++;
        }
        col[temp] = 1;
    }
    cout<<nline;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // pre();
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}