#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Wallet Exchange
// void solve(){
//     int a,b;
//     cin>>a>>b;
//     int odd=0,even=0;
//     if(a&1) odd++;
//     else even++;
//     if(b&1) odd++;
//     else even++;
//     if(odd>0 && even>0) cout<<"Alice"<<endl;
//     else cout<<"Bob"<<endl;
// }

// Plus-Minus Split
// void solve(){
//     int n;cin>>n;
//     string s;
//     cin>>s;
//     int sum = 0;
//     for(int i=0;i<n;i++){
//         if(s[i]=='-') sum--;
//         else sum++;
//     }
//     cout<<abs(sum)<<endl;
// }

// Grouping Increases
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ac = arr[n-1],bc=0;
    int ans = 0;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>=ac && arr[i]>=bc){
            if(ac>bc) ac = arr[i];
            else bc=arr[i];
        }else if(arr[i]>=ac) ac = arr[i];
        else if(arr[i]>=bc) bc = arr[i];
        else{
            ans++;
            if(ac>bc) ac = arr[i];
            else bc=arr[i];
        }
    }
    cout<<ans<<endl;
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