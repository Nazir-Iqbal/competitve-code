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

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i] != 0){
//             cnt++;
//             while(i<n && arr[i]!=0) i++;
//         }
//     }
//     cout<<min(cnt,2)<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     if(s[0] == 's') s[0]= '.';
//     if(s[n-1] == 'p') s[n-1]='.';
//     unordered_set<char> st;
//     for(int i=0;i<n;i++) if(s[i] != '.') st.insert(s[i]);
//     if(st.size()==2) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// MEX Cycle
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    x--,y--;
    vector<int> ans(n,0);
    for(int i=0;i<n;i+=2) ans[i] = 0;
    for(int i=1;i<n;i+=2) ans[i] = 1;
    if(n&1) ans[n-1] = 2;
    if(x>y) swap(x,y);
    if(y-x>1){
        if(ans[x] == ans[y]){
            ans[x] = 2;
            if(x==0 && n&1){
                ans[n-1] = 0;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
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