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
//     int l,r;
//     cin>>l>>r;
//     int even = 0,odd = 0;
//     for(int i=l;i<=r;i++){
//         if(i&1) odd++;
//         else even++;
//     }
//     int ans = min(odd/2,even);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int _max = *max_element(arr,arr+n);
//     while(m--){
//         char c;cin>>c;
//         int l,r;
//         cin>>l>>r;
//         if(l<=_max && r>=_max){
//             if(c=='+') _max++;
//             else _max--;
//         }
//         cout<<_max<<" ";
//     }
//     cout<<endl;
// }

// Dora and C++
void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int g = __gcd(a,b);
	for(int i=0;i<n;i++) arr[i] = arr[i]%g;
	sort(arr,arr+n);
	int ans = arr[n-1]-arr[0];
	for(int i=0;i<n-1;i++){
		ans = min(ans,arr[i]+g-arr[i+1]);
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