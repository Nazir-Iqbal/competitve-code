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
//     int l,r;
//     cin>>l>>r;
//     if(l==1 && r==1){
//         cout<<1<<endl;
//         return;
//     }

//     cout<<r-l<<endl;
// }

// void solve(){
//     int n,l,r;
//     cin>>n>>l>>r;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     vector<int> left,right,middle;
//     for(int i=1;i<l;i++) left.push_back(arr[i]);
//     for(int i=r+1;i<=n;i++) right.push_back(arr[i]);
//     sort(left.begin(),left.end());
//     sort(right.begin(),right.end());
//     int ans = 0;
//     for(int i=l;i<r+1;i++) ans += arr[i],middle.push_back(arr[i]);
//     sort(middle.begin(),middle.end(),greater<int>());
//     int diff = 0;
//     for(int i=0;i<middle.size();i++){
//         if(i == left.size()) break;
//         if(left[i] >= middle[i]) break;
//         diff += abs(left[i] - middle[i]);
//     }
//     int temp = ans;
//     ans = ans - diff;
//     diff = 0;
//     for(int i=0;i<middle.size();i++){
//         if(i == right.size()) break;
//         if(right[i] >= middle[i]) break;
//         diff += abs(right[i] - middle[i]);
//     }
//     ans = min(ans,temp-diff);
//     cout<<ans<<endl;
// }

// void dfs(int node,vector<bool> &vis,vector<int> adj[],vector<int> &child){
//     vis[node] = 1;
//     child[node] = adj[node].size();
//     for(int it : adj[node]){
//         if(vis[it]) continue;
//         dfs(it,vis,adj,child);
//     }
// }


// void solve(){
//     int n;cin>>n;
//     vector<int> adj[n+1];
//     for(int i=0;i<n-1;i++){
//         int u,v;cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     if(n==2){
//         cout<<0<<endl;
//         return;
//     }

//     vector<int> degree(n+1,0);
//     vector<bool> vis(n+1,0);
    
//     dfs(1,vis,adj,degree);

//     // for(int i=1;i<=n;i++) cout<<degree[i]<<" ";
//     // cout<<endl;

//     vector<pair<int,int>> v;
//     for(int i=1;i<=n;i++) v.push_back({degree[i],i});
//     sort(v.begin(),v.end(),greater<pair<int,int>>());
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         unordered_set<int> s;
//         s.insert(i);
//         for(int it : adj[i]){
//             int temp = degree[i]+degree[it] - 2;
//             ans = max(ans,temp);
//             // cout<<i<<" "<<it<<" "<<temp<<endl;
//             s.insert(it);
//         }
//         for(int j=0;j<v.size();j++){
//             int deg = v[j].first;
//             int node =v[j].second;
//             if(s.find(node)==s.end()){
//                 int temp = degree[i]+deg-1;
//                 ans = max(ans,temp);
//                 // cout<<node<<" "<<i<<" "<<temp<<endl;
//                 break;
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

int search(vector<int> &sa,vector<int> &sb,int l,int r,int k){
    int n = sa.size(), m = sb.size();
    while(r-l>=3){
        int mid1 = (2*l+r)/3;
        int mid2 = (2*r+l)/3;

        int val1 = sa[mid1] + sb[k-mid1];
        int val2 = sa[mid2] + sb[k-mid2];
        
        if(val1==val2){
            l = mid1;
            r = mid2;
        }else if(val1 > val2){
            r = mid2;
        }else{
            l = mid1;
        }
    }

    int ans = 0;
    // cout<<l<<"*"<<r<<endl;
    for(int i=l;i<=r;i++){
        ans = max(ans,sa[i]+sb[k-i]);
    }
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    vector<int> sa,sb;
    sa.push_back(0),sb.push_back(0);
    for(int i=0;i<n/2;i++){
        int diff1 = a[n-1-i] - a[i];
        diff1 += sa[i];
        sa.push_back(diff1);
    }

    for(int i=0;i<m/2;i++){
        int diff2 = b[m-1-i] - b[i];
        diff2 += sb[i];
        sb.push_back(diff2);
    }

    int k = 1;
    vector<int> ans;
    while(100){
        int l = max(0ll,2*k-m);
        int r = min(k,n-k);
        // cout<<k<<" "<<l<<" "<<r<<endl;
        if(l>r) break;

        if(l==r){
            ans.push_back(sa[l]+sb[k-l]);
        }else if(l+1==r){
            int temp = max(sa[l]+sb[k-l],sa[r]+sb[k-r]);
            ans.push_back(temp);
        }else{
            int temp = search(sa,sb,l,r,k);
            ans.push_back(temp);
        }
        k++;
    }

    cout<<ans.size()<<endl;
    // for(int ele : sa) cout<<ele<<" ";
    // cout<<endl;
    // for(int ele : sb) cout<<ele<<" ";
    // cout<<endl;
    for(int ele : ans) cout<<ele<<" ";
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