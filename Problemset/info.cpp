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

int mod = 1e9+7;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int q,two;cin>>q>>two;
    vector<int> range(n+2,0);
    while(q--){
        int l,r;
        cin>>l>>r;
        range[l]++;
        range[r+1]--;
    }
    long long ans = 0;
    set<int> s;
    for(int i=1;i<=n;i++) range[i] += range[i-1];
    for(int i=1;i<=n;i++){
        if(range[i]<1) continue;
        s.insert(arr[i-1]);
    }
    long long cnt = 0;
    for(int i=1;i<=n;i++){
        cnt++;
        if(range[i]<1){
            if(s.find(arr[i-1])==s.end()){
                ans = (ans + (cnt*(cnt+1))/2)%mod;
                cnt=0;
            }
        }
    }
    if(cnt>0) ans = (ans + (cnt*(cnt+1))/2)%mod;
    
    cout<<ans<<endl;
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