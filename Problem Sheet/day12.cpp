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
//     int _min = *min_element(arr,arr+n),_max = *max_element(arr,arr+n);
//     int ans = (n-1)*(_max-_min);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string ans;
//     ans.push_back('1');
//     for(int i=0;i<n-1;i++) ans.push_back('0');
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     if(s[n-1]=='1' || s[0]=='1'){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     for(int i=1;i<n;i++){
//         if(s[i]=='1' && s[i-1]=='1'){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     cout<<"No"<<endl;
// }

// QED's Favorite Permutation
// const int N = 2e5+7;
// int arr[N];
// bool f[N],b[N];

// bool check(int x){
//     return !f[x]&&!b[x]&&b[x+1];
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     int x = 0;
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//         x = max(x,arr[i]);
//         f[i] = x==i;
//     }
//     string s;cin>>s;
//     for(int i=0;i<n;i++) b[i+1] = s[i]=='R';
//     int cnt = 0;
//     for(int i=1;i<n;i++){
//         cnt += check(i);
//     }
//     while(q--){
//         int i;cin>>i;
//         cnt -= check(i)+check(i-1);
//         b[i] ^=1;
//         cnt += check(i)+check(i-1);
//         cout<<(cnt?"No":"Yes")<<'\n';
//     }
// }

// D - Magical Cookies
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<char>> arr(n,vector<char>(m));
//     vector<vector<int>> rx(n,vector<int>(26,0)),cx(m,vector<int>(26,0));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//             rx[i][arr[i][j]-'a']++;
//             cx[j][arr[i][j]-'a']++;
//         }
//     }
//     int ti = n+m;
//     int rc = n,cc = m;
//     vector<bool> fr(n,0),fc(m,0);
//     while(ti--){
//         vector<pair<int,int>> pr,pc;
//         for(int i=0;i<n;i++){
//             if(fr[i]) continue; // already deleted
//             for(int j=0;j<26;j++){
//                 if(rx[i][j] == cc && cc>1){
//                     pr.push_back({i,j});
//                 }
//             }
//         }

//         for(int i=0;i<m;i++){
//             if(fc[i]) continue;
//             for(int j=0;j<26;j++){
//                 if(cx[i][j] == rc && rc>1){
//                     pc.push_back({i,j});
//                 }
//             }
//         }

//         // eliminating the selected rows and columns
//         for(auto ele : pr){
//             fr[ele.first] = 1;
//             for(int i=0;i<m;i++) cx[i][ele.second]--;
//             rc--;
//         }

//         for(auto ele : pc){
//             fc[ele.first] = 1;
//             for(int i=0;i<n;i++) rx[i][ele.second]--;
//             cc--;
//         }

//     }
//     cout<<rc*cc<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     arr[0] = 0;
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     map<int,int> mp;
//     vector<int> dp(n+1,0);
//     int sum = 0;
//     mp[sum] = 0;
//     for(int i=1;i<=n;i++){
//         sum += arr[i];
//         if(mp.find(sum)==mp.end()){
//             dp[i] = dp[i-1];
//         }else{
//             dp[i] = max(dp[i-1],dp[mp[sum]]+1);
//             // cout<<mp[sum]<<endl;
//         }
//         mp[sum] = i;
//     }
//     cout<<dp[n]<<endl;
// }

// Kosuke's Sloth
// const int mod = 1e9+7;

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     if(k==1){
//         cout<<n%mod<<endl;
//         return;
//     }
//     int ind = 3;
//     int fib1 = 1,fib2=1;
//     while(true){
//         int num =(fib1+fib2)%k;
//         if(num==0) break;
//         fib1 = fib2,fib2 = num;
//         ind++;
//     }
//     int ans = ((n%mod)*ind)%mod;
//     cout<<ans<<endl;
// }

// E - Prerequisites
void dfs(int node,vector<int> adj[],vector<bool> &vis){
    vis[node] = 1;
    for(int &ele : adj[node]){
        if(!vis[ele]) dfs(ele,adj,vis);
    }
}

void solve(){
    int n;cin>>n;
    vector<int> adj[n+1];
    vector<int> tra[n+1];
    vector<int> indegree(n+1,0);
    for(int i=1;i<=n;i++){
        int sz;cin>>sz;
        for(int j=0;j<sz;j++){
            int ele;cin>>ele;
            adj[ele].push_back(i);
            tra[i].push_back(ele);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
            topo.push_back(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int &ele : adj[node]){
            indegree[ele]--;
            if(indegree[ele]==0){
                q.push(ele);
                topo.push_back(ele);
            }
        }
    }
    vector<bool> vis(n+1,0);
    dfs(1,tra,vis);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(vis[topo[i]]){
            if(topo[i]!=1) ans.push_back(topo[i]);
        }
    }
    for(int ele : ans) cout<<ele<<" ";
    cout<<endl;
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