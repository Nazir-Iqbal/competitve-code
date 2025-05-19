#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n";


// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Line Trip
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     int arr[n+1];
//     arr[0] = 0;
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     int _max = 0;
//     for(int i=1;i<=n;i++) _max = max(arr[i]-arr[i-1],_max);
//     _max = max(2*(x-arr[n]),_max);
//     cout<<_max<<nline;
// }

// Chip and Ribbon
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = 0;
//     for(int i=1;i<n;i++){
//         if(arr[i-1]>arr[i]) ans += arr[i-1]-arr[i]; 
//     }
//     ans += arr[n-1]-1;
//     cout<<ans<<nline;
// }

// Add, Divide and Floor
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==1){
//         cout<<0<<nline;
//         return;
//     }
//     int _min = *min_element(arr,arr+n);
//     int _max = *max_element(arr,arr+n);
//     int calc = _max-_min;
//     for(int i=0;i<=61;i++){
//         int power = 1<<i;
//         if(power>calc){
//             calc = i;
//             break;
//         }
//     }
//     if(calc==0){
//         cout<<0<<nline;
//         return;
//     }

//     cout<<calc<<nline;
//     if(calc>n) return;
//     while(_max!=_min){
//         if(_max&1){
//             _min = _min/2;
//             _max = _max/2;
//             cout<<0<<' ';
//         }else{
//             _min = (_min+1)/2;
//             _max = (_max+1)/2;
//             cout<<1<<' ';
//         }
//     }
//     cout<<nline;
// }

// Yet Another Monster Fight
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> prefix(n+1,0),suffix(n+1,0);

    // calculcating the prefix and suffix
    for(int i=1;i<=n;i++) prefix[i] = arr[i-1] + n - i;
    for(int i=1;i<=n;i++) suffix[i] = arr[i-1] + i-1;

    // caculating the prefix and suffix maxima
    vector<int> premax(n+1,0),sufmax(n+2,0);
    for(int i=1;i<=n;i++) premax[i] = max(prefix[i],premax[i-1]);
    for(int i=n;i>=1;i--) sufmax[i] = max(suffix[i],sufmax[i+1]);

    // for(int ele : suffix) cout<<ele<<" ";
    // cout<<nline;

    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        int cur = arr[i-1];
        cur = max(cur,max(premax[i-1],sufmax[i+1]));
        ans = min(ans,cur);
    }
    cout<<ans<<nline;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }

    solve();

    return 0;
}