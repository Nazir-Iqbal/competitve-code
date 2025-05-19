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

// Nene's Game
// void solve(){
//     int n,q;
//     cin>>n>>q;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> ans;
//     vector<int> query(q);
//     for(int i=0;i<q;i++) cin>>query[i];
//     int small = arr[0];
//     for(int i=0;i<q;i++) ans.push_back(min(query[i],small-1));
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Nene and the Card Game
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int hsn[n+1] = {0};
//     for(int i=0;i<n;i++) hsn[arr[i]]++;
//     int ans = 0;
//     for(int i=0;i<=n;i++){
//         if(hsn[i]>1) ans+=hsn[i]-1;
//     }
//     cout<<ans<<endl;
// }

// Nene's Magical Matrix
void solve(){
    int n;cin>>n;
    int cnt = 1;
    int ans = 0;
    for(int i=1;i<=n;i++) ans += (i*(2*cnt-1)),cnt++;
    cout<<ans<<" "<<2*n<<endl;
    for(int i=n;i>=1;i--){
        cout<<1<<" "<<i<<" ";
        for(int j=1;j<=n;j++) cout<<j<<" ";
        cout<<endl;
        cout<<2<<" "<<i<<" ";
        for(int j=1;j<=n;j++) cout<<j<<" ";
        cout<<endl;
    }
    
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