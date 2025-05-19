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
//     int arr[n+1];
//     for(int i=0;i<=n;i++) cin>>arr[i];
//     while(true){
//         int ind = -1;
//         for(int i=0;i<n;i++){
//             if(arr[i]<=2*arr[n]){
//                 if(arr[i]>arr[n]) swap(arr[i],arr[n]),ind = i;
//             }
//         }
//         if(ind == -1) break;
//     }
//     int ans = 0;
//     for(int i=0;i<n;i++) ans+=arr[i];
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int cnt = 0;
//     for(int i=0;i<n;i++) if(s[i] == '1') cnt++;
//     if(cnt == 0){
//         cout<<n<<endl;
//         return;
//     }
//     if(cnt&1) cout<<1<<endl;
//     else cout<<0<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int _max = *max_element(arr,arr+n),_min = *min_element(arr,arr+n);
//     int ind1=0,ind2 = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i] == _min) ind1 = i;
//         if(arr[i] == _max) ind2 = i;
//     }

//     if(ind2<ind1) cout<<-1<<endl;
//     else{
//         cout<<n-2<<endl;
//         for(int i=0;i<n-2;i++) cout<<1<<" "<<3<<endl;
//     }
// }

// Normal is Good
void solve(){
    int n;cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 0,cnt = 1,sum = 0;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) cnt++;
        else{
            if(arr[i-1]!=2) ans += (cnt*(cnt+1))/2;
            cnt=1;
        }
    }
    if(arr[n-1]!=2) ans += (cnt*(cnt+1))/2;
    // cout<<ans<<endl;
    // counting the no pairs where cnt(1) == cnt(3);
    map<int,int> mp;
    mp[0] = 1;
    for(int i=0;i<n;i++){
        sum += (arr[i]-2);
        ans += mp[sum];
        mp[sum]++;
    }
    // excluding the pairs of equal 1 & 3 
    mp.clear();
    mp[0] = 1,sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 2){
            mp.clear();
            mp[0]  = 1;
            sum = 0;
            continue;
        }
        sum += (arr[i]-2);
        ans -= mp[sum];
        // cout<<sum<<" "<<mp[sum]<<" "<<ans<<endl;
        mp[sum]++;
    }
    cout<<ans<<endl;
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