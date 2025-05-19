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
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,int> mp;
//     for(int i=0;i<n;i++) mp[arr[i]]++;
//     int ans=0;
//     for(auto ele: mp) ans += (ele.second)/2;
//     cout<<ans<<endl;
// }

// void solve(){
//     int k;cin>>k;
//     int arr[k];
//     map<int,int> mp;
//     for(int i=0;i<k;i++) cin>>arr[i];
//     for(int i=0;i<k;i++) mp[arr[i]]++;
//     int req = k-2;
//     int a,b;
//     for(int i=1;i*i<=k;i++){
//         if(req%i==0){
//             int f = i,s = req/i;
//             if(f==s){
//                 if(mp.find(f)!=mp.end() && mp[f]>1){
//                     a = f,b = f;
//                     break;
//                 }
//             }else{
//                 if(mp.find(f)!=mp.end() && mp.find(s)!=mp.end()){
//                     a = f,b = s;
//                     break;
//                 }
//             }
//         }
//     }
//     cout<<a<<" "<<b<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     if(n<5){
//         cout<<-1<<endl;
//         return;
//     }

//     vector<int> ans;
//     for(int i=1;i<=n;i+=2){
//         if(i==5) continue;
//         ans.push_back(i);
//     }
//     ans.push_back(5),ans.push_back(4);
//     for(int i=2;i<=n;i+=2){
//         if(i==4) continue;
//         ans.push_back(i);
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// void solve(){
//     int n,m,l;
//     cin>>n>>m>>l;
//     map<int,int> mp;
//     for(int i=0;i<n;i++){
//         int l,r;cin>>l>>r;
//         // cout<<l<<" "<<r<<endl;
//         mp[l] = r;
//     }
//     vector<pair<int,int>> vp;
//     for(int i=0;i<m;i++){
//         int x,v;cin>>x>>v;
//         vp.push_back({x,v});
//     }
//     int pow = 1,prev = 1,cnt= 0;
//     priority_queue<int> pq;
//     for(int i=0;i<m;i++){
//         int x = vp[i].first,v = vp[i].second;
//         auto ele = mp.upper_bound(prev);
//         while(ele!=mp.end() && (*ele).first < x){
//             int jump = (*ele).first-1+pow;
//             while(!pq.empty() && jump<=(*ele).second){
//                 pow += pq.top();
//                 pq.pop();
//                 cnt++;
//                 jump = (*ele).first-1+pow;
//             }
//             if(jump<=(*ele).second){
//                 cout<<-1<<endl;
//                 return;
//             }
//             prev = (*ele).second+1;
//             ele = mp.upper_bound(prev);
//         }
//         pq.push(v);
//     }
//     auto ele = mp.upper_bound(prev);
//     while(ele!=mp.end()){
//         int jump = (*ele).first-1+pow;
//         while(!pq.empty() && jump<=(*ele).second){
//             pow += pq.top();
//             pq.pop();
//             cnt++;
//             jump = (*ele).first-1+pow;
//         }
//         if(jump<=(*ele).second){
//             // cout<<(*ele).first<<"*"<<(*ele).second<<endl;
//             cout<<-1<<endl;
//             return;
//         }
//         prev = (*ele).second+1;
//         ele = mp.upper_bound(prev);
//     }
//     cout<<cnt<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string ans;
//     for(int i=0;i<n;i++) ans.push_back('1');

//     int total = 0;
//     cout<<"? "<<1<<" "<<n<<endl;
//     cin>>total;
//     if(total == 0){
//         cout<<"! "<<"IMPOSSIBLE"<<endl;
//         return;
//     }
//     int cnt = 1;
//     int ind = 0;
//     for(int i=1;i<n;i++){
//         if(i+1==n){
//             ans[n-2]='0';
//             ans[n-1]='1';
//             cout<<"! "<<ans<<endl;
//             return;
//         }
//         cout<<"? "<<i+1<<" "<<n<<endl;
//         cnt++;
//         int x;cin>>x;
//         if(x!=total){
//             ans[i-1] = '0';
//             ind = i;
//             break;
//         }
//     }
//     int prev = total;
//     for(int i=n;i>ind;i--){
//         cout<<"? "<<ind<<" "<<i-1<<endl;
//         cnt++;
//         int x;cin>>x;
//         if(prev == x){
//             ans[i-1] = '0';
//         }else prev = x;
//         if(i-1==ind+1){
//             if(x==0) ans[ind]='0';
//             break;
//         }
//     }
//     // cout<<cnt<<endl;
//     cout<<"! "<<ans<<endl;
// }

// Natlan Exploring
const int N = 1e6+1;
const int mod = 998244353;
vector<int> fact[N];

void pre(){
    for(int i=2;i<N;i++){
        fact[i].push_back(i);
        for(int j=2*i;j<N;j+=i) fact[j].push_back(i);
    }
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> dp(n,0);
    dp[0] = 1;
    // for(int i=2;i<=7;i++){
    //     cout<<i<<": ";
    //     for(int ele : fact[i]) cout<<ele<<" ";
    //     cout<<endl;
    // }
    map<int,vector<int>> mp;
    mp[arr[0]].push_back(0);
    for(int f : fact[arr[0]]) mp[f].push_back(0);
    for(int i=1;i<n;i++){
        set<int> st;
        for(int ele : fact[arr[i]]){
            if(mp.find(ele)!=mp.end()){
                for(int ind : mp[ele]) st.insert(ind);
            }
        }
        for(int ele : st) dp[i] = (dp[i]+dp[ele])%mod;
        mp[arr[i]].push_back(i);
        for(int f : fact[arr[i]]) mp[f].push_back(i);
    }
    cout<<dp[n-1]<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    pre();
    solve();

    return 0;
}