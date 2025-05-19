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

// void solve(){
//     int n;cin>>n;
//     if(n&1){
//         cout<<0<<endl;
//         return;
//     }
//     n/=2;
//     cout<<(1<<n)<<endl;
// }

// Yet Another Broken Keyboard
void solve(){
    int n,k;
    cin>>n>>k;
    string s;cin>>s;
    set<char> ch;
    for(int i=0;i<k;i++){
        char c;cin>>c;
        ch.insert(c);
    }
    vector<int> dp(n+1,0);
    int len = 0;
    if(ch.find(s[0]) == ch.end()) len = 0,dp[0] = 0;
    else dp[0] = 1,len = 1;
    for(int i=1;i<n;i++){
        if(ch.find(s[i])==ch.end()){
            dp[i] = dp[i-1];
            len = 0;
        }else{
            dp[i] = dp[i-1]+len+1;
            len++;
        }
    }
    cout<<dp[n-1]<<endl;
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