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
//     while(n!=1){
//         cout<<n<<" ";
//         if(n&1) n = 3*n+1;
//         else n/=2;
//     }
//     cout<<1<<endl;
// }

// Missing Number
// void solve(){
//     int n;cin>>n;
//     vector<int> hsn(n+1,0);
//     for(int i=0;i<n;i++){
//         int temp;cin>>temp;
//         hsn[temp]++;
//     }
//     for(int i=1;i<=n;i++){
//         if(hsn[i]==0){
//             cout<<i<<endl;
//             break;
//         }
//     }
// }

// Repetitions
// void solve(){
//     string s;cin>>s;
//     int n = s.length();
//     int ans = 1,len=1;
//     for(int i=1;i<n;i++){
//         if(s[i] == s[i-1]) len++;
//         else ans = max(ans,len),len = 1;
//     }
//     ans = max(ans,len);
//     cout<<ans<<endl;
// }

// Increasing Array
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = 0;
//     for(int i=1;i<n;i++){
//         if(arr[i-1] > arr[i]){
//             ans += arr[i-1]-arr[i];
//             arr[i] = arr[i-1];
//         }
//     }
//     cout<<ans<<endl;
// }

// Permutations
// void solve(){
//     int n;cin>>n;
//     if(n==1){
//         cout<<1<<endl;
//         return;
//     }
//     if(n<=3){
//         cout<<"NO SOLUTION"<<endl;
//         return;
//     }
//     for(int i=2;i<=n;i+=2) cout<<i<<" ";
//     for(int i=1;i<=n;i+=2) cout<<i<<" ";
//     cout<<endl;
// }

// Number Spiral
// void solve(){
//     int x,y;
//     cin>>x>>y;
//     int ans = 0;
//     if(y>=x){
//         if(y&1){
//             ans = y*y;
//             ans -= (x-1);
//         }else{
//             ans = (y-1)*(y-1);
//             ans += x;
//         }
//     }else{
//         if(x&1){
//             ans = (x-1)*(x-1) + 1;
//             ans += (y-1);
//         }else{
//             ans = x*x;
//             // cout<<ans<<endl;
//             ans -= (y-1);
//         }
//     }
//     cout<<ans<<endl;
// }

// Two Knights
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int total = ((i*i)*((i*i)-1))/2;
        int attack = 2*(i-1)*(i-2);
        // each box has two attacking positons
        attack *= 2;
        int net = total - attack;
        cout<<net<<nline;
    }
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}