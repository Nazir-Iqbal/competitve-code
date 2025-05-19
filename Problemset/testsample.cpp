#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Dances (Easy version)
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> a,b;
//     a.push_back(1);
//     for(int i=1;i<n;i++){
//         int temp;cin>>temp;
//         a.push_back(temp);
//     }
//     for(int i=0;i<n;i++){
//         int temp;cin>>temp;
//         b.push_back(temp);
//     }
//     sort(a.begin(),a.end());
//     sort(b.begin(),b.end());
//     int l = 0,r = 0;
//     while(r<n){
//         if(a[l]<b[r]) l++ ,r++;
//         else r++;
//     }
//     // cout<<l<<nline;
//     cout<<(n-l)<<nline;
// }

// Iva & Pav
// bool isPossible(int r,vector<vector<int>> &prefix,int k,int l){
//     int num = 0;
//     for(int i=0;i<31;i++){
//         int calc = prefix[r][i]-prefix[l-1][i];
//         if(calc == r-l+1) num+=(1<<i);
//     }
//     if(num>=k) return true;
//     return false;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n+1] = {0};
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     // calculating the prefix sum of the sex bits;
//     vector<vector<int>> prefix(n+1,vector<int>(31,0));
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<31;j++){
//             if(arr[i]&(1<<j)) prefix[i][j]++;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<31;j++){
//             prefix[i][j] += prefix[i-1][j];
//         }
//     }

//     int q;cin>>q;
//     while(q--){
//         int l,k;cin>>l>>k;
//         // implementing the binary search
//         int lo = l,hi = n;
//         while(lo<=hi){
//             int mid = (lo+hi)/2;
//             if(isPossible(mid,prefix,k,l)) lo = mid+1;
//             else hi = mid-1;
//         }
//         if(hi<l) cout<<-1<<" ";
//         else cout<<hi<<" ";
//     }
//     cout<<nline;
// }

// Copil Copac Draws Trees
// void dfs(int node,int par,vector<int> adj[],map<pair<int,int>,int> &mp,vector<int> &cnt){
//     for(int ele : adj[node]){
//         if(ele != par){
//             int occ1 = mp[{min(node,par),max(node,par)}],occ2 = mp[{min(node,ele),max(ele,node)}];
//             if(occ1<=occ2) cnt[ele] = cnt[node];
//             else cnt[ele] = cnt[node] + 1;
//             dfs(ele,node,adj,mp,cnt);
//         } 
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> adj[n+1];
//     vector<int> ind(n+1,-1);
//     map<pair<int,int>,int> mp;
//     mp[{-1,1}] = 0;
//     for(int i=1;i<n;i++){
//         int u,v;cin>>u>>v;
//         mp[{min(u,v),max(u,v)}] = i;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> cnt(n+1,1);
//     dfs(1,-1,adj,mp,cnt);
//     int ans = *max_element(cnt.begin(),cnt.end());
//     cout<<ans<<nline;
// }

// Make It Round
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int two=0,five=0;
//     int copy1 = n;
//     while(copy1%2==0){
//         two++;
//         copy1/=2;
//     }
//     while(copy1%5==0){
//         five++;
//         copy1/=5;
//     }
//     int num = 1;
//     if(two>=five){
//         int diff = two-five;
//         while(num<=m && diff>0) num*=5,diff--;
//         if(num>m) num/=5;
//     }else{
//         int diff = five-two;
//         while(num<=m && diff>0) num*=2,diff--;
//         if(num>m) num/=2;
//     }
//     while(num<=m) num*=10;
//     if(num>m) num/=10;
//     int temp = 1;
//     for(int i=2;i<10;i++) if(num*i<=m) temp = i;
//     num *=temp;
//     cout<<n*num<<endl;
// }

// Add Modulo 10
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     bool flag = false;
//     for(int i=0;i<n;i++){
//         if(arr[i]%10 == 0 || arr[i]%10 == 5){
//             flag = true;
//             break;
//         }
//     }
//     if(flag){
//         for(int i=0;i<n;i++){
//             int num = arr[i]%10;
//             if(num == 0) continue;
//             if(num == 5) arr[i] += 5;
//             else{
//                 cout<<"No"<<endl;
//                 return;
//             }
//         }
//         for(int i=1;i<n;i++){
//             if(arr[i-1]!=arr[i]){
//                 cout<<"No"<<endl;
//                 return;
//             }
//         }
//         cout<<"Yes"<<endl;
//         return;
//     }

//     for(int i=0;i<n;i++){
//         while(arr[i]%10!=6){
//             arr[i] += (arr[i]%10);
//         }
//     }
//     // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
//     // cout<<nline;
//     for(int i=0;i<n;i++) arr[i] %= 20;
//     for(int i=1;i<n;i++){
//         if(arr[i-1]!=arr[i]){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Schedule Management
// bool isPossible(vector<int> &task,int time,int m){
//     int n = task.size();
//     for(int i=1;i<n;i++){
//         if(time>=task[i]){
//             m-=task[i];
//             m-=(time-task[i])/2;
//         }else m -= time;
//         if(m<=0) return true;
//     }
//     return false;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> v(n+1,0);
//     for(int i=1;i<=m;i++){
//         int temp;cin>>temp;
//         v[temp]++;
//     }
//     int lo = 1,hi = 1e9;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(isPossible(v,mid,m)) hi = mid-1;
//         else lo = mid+1;
//     }
//     cout<<lo<<endl;
// }

// Weird Sum
void solve(){
    cout<<"*"<<endl;
    int n,m;
    cin>>n>>m;
    vector<int> colors[100001][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int col;cin>>col;
            colors[col][0].push_back(i);
            colors[col][1].push_back(j);
        }
    }
    int ans = 0;
    for(int i=0;i<=100000;i++){
        int len = colors[i][0].size();
        cout<<i<<" "<<len<<endl;
        if(len>1){
            sort(colors[i][0].begin(),colors[i][0].end());
            ans += (len-1)*(colors[i][0][len-1] - colors[i][0][0]);
            ans += (len-1)*(colors[i][1][len-1] - colors[i][1][0]);
        }
    }
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}