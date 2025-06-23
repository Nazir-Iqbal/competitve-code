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
//     if(n&1){
//         cout<<n<<" ";
//         for(int i=1;i<n;i++) cout<<i<<" ";
//         cout<<endl;
//     }else cout<<-1<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int ele = 0;
//     for(int i=1;i<n;i++){
//         if(arr[i]%arr[0] == 0) ele = __gcd(ele,arr[i]);
//     }
//     if(ele == arr[0]) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int a[n+1],b[n+1];
//     for(int i=1;i<=n;i++) cin>>a[i];
//     for(int j=1;j<=n;j++) cin>>b[j];
//     map<pair<int,int>,int> mp;
//     int cnt = 0,eq = 0;
//     for(int i=1;i<=n;i++){
//         if(a[i] == b[i]) cnt++,eq = a[i];
//         mp[{a[i],b[i]}] = i;
//     }
//     if(cnt == 1 && n%2==0){
//         cout<<-1<<endl;
//         return;
//     }
//     if(cnt == 0 && n&1){
//         cout<<-1<<endl;
//         return;
//     }
//     if(cnt>1){
//         cout<<-1<<endl;
//         return;
//     }
//     vector<pair<int,int>> ans;
//     if(cnt == 1){
//         int pos1 = mp[{eq,eq}];
//         int pos2 = (n+1)/2;
//         if(pos1 != pos2){
//             ans.push_back({pos1,pos2});
//             int first = a[pos2];
//             int second = b[pos2];
//             mp[{eq,eq}] = pos2;
//             mp[{first,second}] = pos1;
//             swap(a[pos1],a[pos2]);
//             swap(b[pos1],b[pos2]);
//         }
//     }
//     for(auto &ele : mp){
//         int first = ele.first.first;
//         int second = ele.first.second;
//         int pos1 = ele.second;
//         if(first == second) continue;
//         if(mp.count({second,first})==0){
//             cout<<-1<<endl;
//             return;
//         }
//         int pos2 = mp[{second,first}];
//         int ac = n+1-pos2;
//         // cout<<ac<<" "<<pos1<<endl;
//         if(ac == pos1) continue;
//         int first1 = a[ac];
//         int second1 = b[ac];
//         mp[{first,second}] = ac;
//         mp[{first1,second1}]=pos1;
//         swap(a[pos1],a[ac]);
//         swap(b[pos1],b[ac]);
//         ans.push_back({ac,pos1});
//     }
//     cout<<ans.size()<<endl;
//     for(int i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;
// }

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    int len = n - (m*k);
    if(len <= k){
        for(int i=0;i<n;i++) cout<<i%k<<" ";
        cout<<endl;
    }else{
        int seq = n/(m+1);
        for(int i=0;i<n;i++) cout<<i%seq<<" ";
        cout<<endl;
    }
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