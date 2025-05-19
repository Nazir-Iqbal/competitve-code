#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Farmer John's Challenge
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     if(k==1){
//         for(int i=1;i<=n;i++) cout<<i<<" ";
//         cout<<nline;
//     }else if(k==n){
//         for(int i=0;i<n;i++) cout<<1<<" ";
//         cout<<nline;
//     }else{
//         cout<<-1<<nline;
//     }
// }

// Bessie and MEX
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int mex=0;
//     vector<int> ans;
//     set<int> s;
//     s.insert(n-arr[n-1]);
//     for(int i=0;i<n-1;i++){
//         for(int j=mex;j<=(i+1);j++){
//             if(j-arr[i]>=0 && s.find(j-arr[i]) == s.end()){
//                 s.insert(j-arr[i]);
//                 ans.push_back(j-arr[i]);
//                 mex = j;
//                 break;
//             }
//         }
//     }
//     ans.push_back(n-arr[n-1]);
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<nline;
// }

// Bessie's Birthday Cake (Easy Version)
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     map<int,int> m;
//     vector<int> v(x);
//     for(int i=0;i<x;i++){
//         cin>>v[i];
//         m[v[i]]++;
//     }
//     set<int> use;
//     for(int i=0;i<x;i++){
//         use.insert(v[i]);
//         int f = v[i]+1,fo = v[i]+2;
//         if(f>n) f-=n;
//         if(fo>n) fo-=n;
//         int b = v[i]-1,bo = v[i]-2;
//         if(b<1) b += n;
//         if(bo<1) bo += n;
//         if(m[f] == 0 && m[fo] == 1) use.insert(f);
//         if(m[b] == 0 && m[bo] == 1) use.insert(b);
//     }
//     cout<<use.size()-2<<nline;
// }

// Bessie's Birthday Cake (Hard Version)
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     map<int,int> m;
//     vector<int> v(x);
//     for(int i=0;i<x;i++){
//         cin>>v[i];
//         m[v[i]]++;
//     }
//     set<int> use;
//     for(int i=0;i<x;i++){
//         use.insert(v[i]);
//         int f = v[i]+1,fo = v[i]+2;
//         if(f>n) f-=n;
//         if(fo>n) fo-=n;
//         int b = v[i]-1,bo = v[i]-2;
//         if(b<1) b += n;
//         if(bo<1) bo += n;
//         if(m[f] == 0 && m[fo] == 1) use.insert(f),m[f]++;
//         if(m[b] == 0 && m[bo] == 1) use.insert(b),m[b]++;
//         if(m[f] == 0 && m[fo] == 0){
//             if(y>0){
//                 use.insert(fo),use.insert(f);
//                 m[fo]++,m[f]++;
//                 y--;
//             }
//         }
//         if(m[b] == 0 && m[bo] == 0){
//             if(y>0){
//                 use.insert(bo),use.insert(b);
//                 m[bo]++,m[b]++;
//                 y--;
//             }
//         }
//     }
//     int sz = use.size() + (2*y);
//     // cout<<sz<<" "<<n<<endl;
//     sz = min(n,sz);
//     cout<<sz-2<<nline;
// }

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> v(x);
    for(int i=0;i<x;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int ans = x;
    vector<int> odd,even;
    // calculating the diff
    for(int i=0;i<x-1;i++){
        int diff = v[i+1]-v[i]-1;
        if(diff&1) odd.push_back(diff);
        else even.push_back(diff);
    }
    int diff = n-v[x-1] + v[0]-1;
    if(diff&1) odd.push_back(diff);
    else even.push_back(diff);
    //
    // taking 3 are more benificial then any other odd no.
    sort(odd.begin(),odd.end());
    for(int i=0;i<odd.size();i++){
        int need = odd[i]/2;
        if(need<=y) ans+=odd[i],y-=need;
        else ans+=(2*y),y=0;
    }
    for(int i=0;i<even.size();i++){
        int need = even[i]/2;
        // cout<<even[i]<<"*"<<endl;
        if(y==0) break;
        if(need<=y) ans+=even[i],y-=need;
        else ans+=(2*y),y=0;
    }
        // cout<<diff<<" "<<ans<<endl;
    cout<<ans-2<<endl;
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