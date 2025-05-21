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
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     int ans = a[n-1];
//     for(int i=0;i<n-1;i++){
//         int diff = a[i]-b[i+1];
//         if(diff>0) ans += diff;
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,a,b,c;
//     cin>>n>>a>>b>>c;
//     int arr[4] = {a,a+b,a+b+c};
//     int left = n%arr[2];
//     int ans = (n/arr[2])*3;
//     // cout<<ans<<" "<<left<<" "<<arr[2]<<endl;
//     for(int i=0;i<3;i++){
//         if(left == 0) break;
//         if(left <= arr[i]){
//             ans += i + 1;
//             break;
//         }
//     }
//     cout<<ans<<endl;
// }

// void print(vector<char> &v){
//     for(char &ele : v) cout<<ele;
//     cout<<endl;
// }

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     int a[m],q[k];
//     for(int i=0;i<m;i++) cin>>a[i];
//     for(int j=0;j<k;j++) cin>>q[j];
//     vector<char> ans(m,'1');
//     if(k==n){
//         print(ans);
//     }else if(k==n-1){
//         vector<bool> arr(n+1,0);
//         for(int i=0;i<k;i++) arr[q[i]] = 1;
//         int ind = 1;
//         for(int i=1;i<=n;i++){
//             if(!arr[i]) ind = i;
//         }
//         for(int i=0;i<m;i++){
//             if(a[i] != ind) ans[i] = '0';
//         }
//         print(ans);
//     }else{
//         for(int i=0;i<m;i++) ans[i] = '0';
//         print(ans);
//     }
// }

// Counting Pairs
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr.begin(),arr.end());
//     int sum = accumulate(arr.begin(),arr.end(),0ll);
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int l = lower_bound(arr.begin()+i+1,arr.end(),sum-(arr[i]+y)) - arr.begin();
//         int r = upper_bound(arr.begin()+i+1,arr.end(),sum-(arr[i]+x)) - arr.begin();
//         r--;
//         if(l>r) continue;
//         ans += (r-l+1);
//     }
//     cout<<ans<<endl;
// }

// Best Price
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    set<int> st;
    for(int i=0;i<n;i++) cin>>a[i],st.insert(a[i]);
    for(int i=0;i<n;i++) cin>>b[i],st.insert(b[i]);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    for(int cost : st){
        int buy = n-(lower_bound(b.begin(),b.end(),cost) - b.begin());
        int negative = lower_bound(a.begin(),a.end(),cost) - a.begin();
        // p > a[i] in those for p>b[i]
        negative -= lower_bound(b.begin(),b.end(),cost) - b.begin();
        // cout<<cost<<" "<<buy<<" "<<negative<<endl;
        if(negative <= k){
            ans = max(ans,buy*cost);
        }
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