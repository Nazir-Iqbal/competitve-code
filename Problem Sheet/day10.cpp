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

// int recur(int n,int k){
//     if(n<k) return n;

//     int num = k;
//     while((num*k)<=n) num*=k;
//     // cout<<n<<" "<<k<<" "<<num<<endl;
//     return 1+recur(n-num,k);
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     if(k==1){
//         cout<<n<<endl;
//         return;
//     }
//     cout<<recur(n,k)<<endl;
// }

// Brightness Begins
// void solve(){
//     int k;cin>>k;
//     int lo = 1,hi = k+k;
//     int ans=2e18;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         int calc = mid-floor((sqrtl(mid)));
//         // cout<<mid<<" "<<calc<<" "<<sqrtl(mid)<<endl;
//         if(calc==k){
//             ans = min(ans,mid);
//             hi = mid-1;
//         }else if(calc<k) lo = mid+1;
//         else hi = mid-1;
//     }
//     cout<<ans<<endl;
// }

// Bitwise Balancing
// void solve(){
//     int b,c,d;
//     cin>>b>>c>>d;
//     int a = 0;
//     for(int i=61;i>=0;i--){
//         bool bbit = (b>>i)&1ll;
//         bool cbit = (c>>i)&1ll;
//         bool set = (d>>i)&1ll;
//         if(set){
//             if(!bbit & !cbit) a |= (1ll<<i);
//             if(!bbit & cbit){
//                 cout<<-1<<endl;
//                 return;
//             }
//         }else{
//             if(cbit & bbit) a |= (1ll<<i);
//             if(!cbit & bbit){
//                 cout<<-1<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<a<<endl;
// }

// Connect the Dots
// class DisjointSet {
// public:
//     vector<int> parent, size;
//     DisjointSet(int n) {
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n+1][11] = {0};
//     for(int i=0;i<m;i++){
//         int a,d,k;
//         cin>>a>>d>>k;
//         arr[a][d] = max(arr[a][d],k);
//     }
//     DisjointSet dsu(n);

//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=10;j++){
//             int k = 1;
//             while(arr[i][j]!=0){
//                 int cur = i+j*k;
//                 k++;
//                 arr[i][j]--;
//                 arr[i][j] = max(arr[i][j],arr[cur][j]);
//                 arr[cur][j] = 0;
//                 dsu.unionBySize(i,cur);
//             }
//         }
//     }

//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         if(dsu.findUPar(i)==i){
//             // cout<<i<<endl;
//             ans++;
//         }
//     }
//     cout<<ans<<endl;
// }

// Meaning Mean
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int ans = arr[0];
//     for(int i=1;i<n;i++){
//         ans = (ans+arr[i])/2;
//     }
//     cout<<ans<<endl;
// }

// Maximize Mex
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int hsn[n+1] = {0};
//     for(int i=0;i<n;i++) if(arr[i]<=n) hsn[arr[i]]++;
//     map<int,int> mp;
//     int ans = n;
//     for(int i=0;i<n;i++){
//         int num = i%x;
//         if(hsn[i]==0){
//             if(mp[num]>0) mp[num]--;
//             else{
//                 ans = i;
//                 break;
//             }
//         }else mp[num]+= hsn[i]-1;
//     }
//     cout<<ans<<endl;

// }

// Adjust The Presentation (Easy Version)
// int n,m,q;
// const int maxn = 2e5+10;
// int a[maxn],b[maxn],orig[maxn];
// set<int> pos[maxn];
// bool flag[maxn];
// int ans = 0;

// void check(int ind){
//     if(ind<=0 || ind>n) return;
//     ans -= flag[ind];
//     flag[ind] = false;
//     if(ind == 1) flag[ind] = true;
//     else{
//         if((*pos[a[ind-1]].begin()) <= (*pos[a[ind]].begin())) flag[ind] = true;
//     }
//     ans+= flag[ind];
// }

// void solve(){
//     cin>>n>>m>>q;
//     for(int i=1;i<=n;i++){
//         cin>>a[i];
//         orig[a[i]] = i;
//         pos[i].clear();
//         pos[i].insert(INT_MAX);
//     }

//     for(int i=1;i<=m;i++){
//         cin>>b[i];
//         pos[b[i]].insert(i);
//     }
//     ans = 0;
//     for(int i=1;i<=n;i++){
//         flag[i] = false;
//         check(i);
//     }

//     if(ans == n) cout<<"YA"<<endl;
//     else cout<<"TIDAK"<<endl;

//     for(int i=0;i<q;i++){
//         int u,v;
//         cin>>u>>v;
//         pos[b[u]].erase(u);
//         pos[v].insert(u);

//         check(orig[b[u]]);
//         check(orig[b[u]]+1);
//         b[u] = v;
//         check(orig[b[u]]);
//         check(orig[b[u]]+1);

//         if(ans == n) cout<<"YA"<<endl;
//         else cout<<"TIDAK"<<endl;
//     }

// }

// Attribute Checks
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<vector<int>> dp(m+1,vector<int>(m+1,0));
//     vector<int> st,in;
//     int total = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==0){
//             total++;
//             sort(st.begin(),st.end());
//             sort(in.begin(),in.end());
//             for(int j=0;j<=total;j++){
//                 if(j!=0){
//                     int val = (upper_bound(in.begin(),in.end(),j-1)-in.begin()) + (upper_bound(st.begin(),st.end(),total-j)-st.begin());
//                     dp[total][j] = max(dp[total][j],dp[total-1][j-1]+val);
//                 }
//                 if(j<total){
//                     int val = (upper_bound(in.begin(),in.end(),j)-in.begin()) + (upper_bound(st.begin(),st.end(),total-j-1)-st.begin());
//                     dp[total][j] = max(dp[total][j],dp[total-1][j]+val);
//                 }
//             }
//             st.clear();
//             in.clear();
//         }else if(arr[i]>0) in.push_back(arr[i]);
//         else st.push_back(-arr[i]);
//     }
//     // for(int i=0;i<=m;i++){
//     //     for(int j=0;j<=m;j++) cout<<dp[i][j]<<" ";
//     //     cout<<endl;
//     // }

//     int ans = 0;
//     sort(in.begin(),in.end());
//     sort(st.begin(),st.end());
//     for(int i=0;i<=m;i++){
//         int val = (upper_bound(in.begin(),in.end(),i)-in.begin()) + (upper_bound(st.begin(),st.end(),m-i)-st.begin());
//         ans = max(ans,dp[m][i] + val);
//     }
//     cout<<ans<<endl;
// }

// bool check(vector<int> &arr,int x){
//     for(int i=0;i<arr.size();i++){
//         if(arr[i] == x) return true;
//     }
//     return false;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> arr[n];
//     for(int i=0;i<n;i++){
//         int c;cin>>c;
//         for(int j=0;j<c;j++){
//             int temp;cin>>temp;
//             arr[i].push_back(temp);
//         }
//     }
//     int x;cin>>x;
//     set<int> hsn[200];
//     for(int i=0;i<n;i++){
//         if(check(arr[i],x)) hsn[arr[i].size()].insert(i+1);
//     }
//     bool flag = true;
//     for(int i=1;i<200;i++){
//         if(hsn[i].size()>0){
//             cout<<hsn[i].size()<<endl;
//             for(int ele : hsn[i]) cout<<ele<<" ";
//             cout<<endl;
//             flag = false;
//             break;
//         }
//     }
//     if(flag){
//         cout<<0<<endl;
//         cout<<endl;
//     }
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     string s;cin>>s;
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,int> mp;
//     vector<int> v;
//     for(int i=0;i<n;i++){
//         v.push_back(mp[arr[i]]);
//         mp[arr[i]] = i+1;
//     }
//     for(int i=0;i<n;i++){
//         if(v[i] == 0) v[i] = mp[arr[i]];
//     }
//     string ans;
//     for(int i=0;i<n;i++) ans.push_back(s[v[i]-1]);
//     cout<<ans<<endl;
// }

// D - LOWER 
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int q;cin>>q;
    int flag = -1;
    set<int> st;
    while(q--){
        int type,pos;
        char c;
        cin>>type>>pos>>c;
        // cout<<type<<" "<<pos<<" "<<c<<endl;
        if(type==1){
            s[pos-1] = c;
            st.insert(pos-1);
        }else if(type==2){
            flag = 0;
            st.clear();
        }else{
            flag = 1;
            st.clear();
        }
    }
    // cout<<flag<<endl;
    if(flag == -1){
        cout<<s<<endl;
        return;
    }
    if(flag){
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()) s[i] = toupper(s[i]);
        }
    }else{
        for(int i=0;i<n;i++){
            if(st.find(i)==st.end()) s[i] = tolower(s[i]);
        }
    }
    cout<<s<<endl;
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