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

// Treasure Chest
// void solve(){
//     int x,y,k;
//     cin>>x>>y>>k;
//     if(y<=x) cout<<x<<endl;
//     else{
//         int left = min(y,x+k);
//         cout<<left + 2*(y-left)<<endl;
//     }
// }

// Points and Minimum Distance
// void solve(){
//     int n;cin>>n;
//     int len = n;
//     n*=2;
//     int arr[n];
//     for(int i=0;i<n;i++)cin>>arr[i];
//     sort(arr,arr+n);
//     vector<int> x,y;
//     int sum = 0;
//     x.push_back(arr[0]),y.push_back(arr[len]);
//     for(int i=1;i<len;i++){
//         sum += arr[i]-arr[i-1];
//         x.push_back(arr[i]);
//     }
//     for(int i=len+1;i<n;i++){
//         sum += arr[i]-arr[i-1];
//         y.push_back(arr[i]);
//     }
//     cout<<sum<<nline;
//     for(int i=0;i<len;i++) cout<<x[i]<<" "<<y[i]<<nline;
// }

// Torn Lucky Ticket
void solve(){
    int n;cin>>n;
    map<pair<int,int>,int> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    // finding the length and the sum of the ticket
    for(int i=0;i<n;i++){
        int sum = 0;
        int len = v[i].size();
        for(int j=0;j<len;j++){
            sum+=(v[i][j]-'0');
        }
        m[{sum,len}]++;
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int len = v[i].size();
        int st = (len+1)/2;
        st--;

        int total = 0;
        for(int j=0;j<len;j++){
            total += (v[i][j]-'0');
        }
        // cout<<i<<" "<<st<<" "<<len<<endl;
        int sum = 0;
        // checking from the forward
        for(int j=0;j<st;j++) sum += (v[i][j]-'0');
        for(int j=st;j<len;j++){
            sum+=(v[i][j]-'0');
            int sz = (j+1) - (len-(j+1));
            int req = sum - (total - sum);
            ans += m[{req,sz}];
        }
        // checking from backward
        sum = 0;
        for(int j=st+1;j<len;j++) sum += (v[i][j]-'0');
        for(int j=st;j>=0;j--){
            sum+=(v[i][j]-'0');
            int sz = len-j-j;
            int req = sum - (total - sum);
            ans += m[{req,sz}];
            cout<<j<<" "<<req<<" "<<sz<<" "<<m[{req,sz}]<<endl;
        }
    }
    cout<<ans<<nline;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}