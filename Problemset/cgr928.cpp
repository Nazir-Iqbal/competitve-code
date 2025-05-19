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

// void solve(int tt){
//     int n;cin>>n;
//     if(n%33==0) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Kevin and Permutation
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> ans(n,0);
    int cur = 1;
    for(int i=k-1;i<n;i+=k){
        ans[i] = cur;
        cur++;
        if(i+k > n-1 && i!=n-1){
            ans[n-1] = cur;
            cur++;
        }
    }
    for(int i=0;i<n;i++){
        if(ans[i] == 0){
            ans[i] = cur;
            cur++;
        }
    }
    for(int &it : ans) cout<<it<<" ";
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