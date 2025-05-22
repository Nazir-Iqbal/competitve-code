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
//     if(n<4){
//         cout<<1<<endl;
//     }else{
//         int cur = 1;
//         while(n>3){
//             n /= 4;
//             cur<<=1;
//         }
//         cout<<cur<<endl;
//     }
// }

// Digits
void solve(){
    int n,d;cin>>n>>d;
    n = min(n,9ll);
    for(int i=1;i<=n;i++) d *= i;
    vector<int> ans;
    for(int i=1;i<10;i+=2) if(d%i==0) ans.push_back(i);
    for(int &ele : ans) cout<<ele<<" ";
    cout<<endl;
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