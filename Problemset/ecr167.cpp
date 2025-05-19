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

// Catch the Coin
// void solve(){
//     int x,y;
//     cin>>x>>y;
//     if(y<-1){
//         cout<<"No"<<endl;
//         return;
//     }
//     cout<<"Yes"<<endl;
// }

// Substring and Subsequence
// void solve(){
//     string a,b;
//     cin>>a>>b;
//     int n = a.size() , m = b.size();
//     int len = 0;
//     for(int i=0;i<m;i++){
//         int local = 0;
//         for(int j=0;j<n;j++){
//             if(b[i+local] == a[j]) local++;
//         }
//         // cout<<local<<endl;
//         len = max(local,len);
//     }
//     cout<<n+(m-len)<<endl;
// }

// Two Movies
// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int j=0;j<n;j++) cin>>b[j];
//     int neta = 0,netb = 0,pos=0,neg=0;
//     for(int i=0;i<n;i++){
//         if(a[i] == 1 && b[i] == 1) pos++;
//         else if(a[i] == -1 && b[i] == -1) neg++;
//         else{
//             if(a[i]>=b[i]) neta+=a[i];
//             else netb+=b[i];
//         }
//     }
//     // now distributing equally
//     while(pos){
//         if(neta<netb) neta++;
//         else netb++;
//         pos--;
//     }
//     // cout<<neta<<" "<<netb<<endl;
//     while(neg){
//         if(neta<netb) netb--;
//         else neta--;
//         neg--;
//     }
//     cout<<min(neta,netb)<<endl;
// }

// Smithing Skill
// solving using prefix sum , dynamic programming and math
void solve(){
    int n,m;
    cin>>n>>m;
    int a[n],b[n],c[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<m;i++) cin>>c[i];
    int range = *max_element(a,a+n);
    // calculating the best for th e given a[i] class
    vector<int> best(range+1,INT_MAX);
    for(int i=0;i<n;i++){
        best[a[i]] = min(best[a[i]],a[i]-b[i]);
    }
    // calculating the best in the range from 1->i;
    for(int i=1;i<=range;i++) best[i] = min(best[i-1],best[i]);
    for(int i=0;i<=range;i++){
        if(best[i] == INT_MAX) best[i] = -1;
        else break;
    }
    // calculating the best forge till i
    vector<int> bf(range+1,0);
    for(int i=1;i<=range;i++){
        if(best[i] == -1) continue;
        bf[i] += 2 + bf[i-best[i]]; 
    }
    int ans  = 0;
    for(int i=0;i<m;i++){
        if(c[i] <= range) ans += bf[c[i]];
        else{
            // minimum no. of operations to be applied so that c[i]<=range
            int diff = c[i] - range;
            int k = diff/best[range];
            // cout<<"*"<<endl;
            if(diff%best[range] != 0) k++;
            ans += 2*k + bf[c[i] - k*best[range]];
        }
    }
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