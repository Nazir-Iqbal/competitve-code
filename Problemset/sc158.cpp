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
//     string s;cin>>s;
//     int f=-1,l=-1;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         if(s[i] == 'a'){
//             if(f==-1)f=i;
//             l=i;
//         }
//     }
//     ans = max(ans,l-f+1);
//     f=-1,l=-1;
//     for(int i=0;i<n;i++){
//         if(s[i] == 'b'){
//             if(f==-1)f=i;
//             l=i;
//         }
//     }
//     ans = max(ans,l-f+1);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==1){
//         cout<<arr[0]<<endl;
//         return;
//     }
//     int ans = 0;
//     for(int i=30;i>=0;i--){
//         int cnt=0;
//         for(int j=0;j<n;j++)cnt += ((arr[j]>>i)&1ll);
//         // cout<<i<<" "<<cnt<<endl;
//         if(cnt==n) ans += (1<<i);
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     int ans=0;
//     vector<int> cheap,costly;
//     for(int i=0;i<n;i++){
//         if(a[i]>b[i]) cheap.push_back(i);
//         else costly.push_back(i);
//     }
//     if(costly.size()!=1){
//         for(int i=0;i<n;i++) ans += min(a[i],b[i]);
//     }else{
//         for(int i=0;i<n;i++) ans += b[i];
//         int local = ans;
//         for(int i=0;i<n;i++){
//             if(i == costly[0]) continue;
//             else{
//                 int temp = local - ((b[i]+b[costly[0]]) - (a[i]+a[costly[0]]));
//                 ans = min(ans,temp);
//                 // cout<<temp<<"*"<<local<<" "<<(a[i]+a[costly[0]])<<" "<<ans<<endl;
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<pair<int,int>,int> mp;
//     vector<int> ans;
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         int cur = arr[i],pow = 0;
//         while(cur%2==0) cur/=2,pow++;
//         mp[{cur,pow}]++,cnt++;
//         int now = mp[{cur,pow}];
//         while(now>1){
//             cnt -= now/2;
//             mp[{cur,pow}] = now%2;
//             cnt += mp[{cur,pow}];
//             pow++;
//             mp[{cur,pow}] += (now)/2;
//             now = mp[{cur,pow}];
//         }
//         ans.push_back(cnt);
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve(){
    int n;cin>>n;
    vector<vector<int>> ans;
    vector<pair<int,int>> vp;
    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        vp.push_back({x,y});
    }
    int cc = n;
    DisjointSet dsu(n);
    int tt = 0;
    while(cc!=1){
        if(tt==10) break;
        vector<int> col(n+1,-1);
        for(int i=0;i<n-1;i++){
            int u = vp[i].first,v = vp[i].second;
            if(dsu.findUPar(u)==dsu.findUPar(v)) continue;
            if(col[u]==-1 && col[v]==-1){
            // cout<<u<<" "<<v<<endl;
                col[u] = u;
                col[v] = u;
                dsu.unionBySize(u,v);
            }
        }
        cc=0;
        for(int i=1;i<=n;i++){
            if(dsu.parent[i]==i){
                // cout<<i<<"&"<<endl;
                cc++;
            }
        }
        for(int i=1;i<=n;i++) if(col[i] == -1) col[i] = i;
        ans.push_back(col);
        // cout<<cc<<"*"<<endl;
        tt++;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=1;j<=n;j++) cout<<ans[i][j]<<" ";
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