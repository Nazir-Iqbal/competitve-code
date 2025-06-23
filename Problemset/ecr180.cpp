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
//     int a,x,y;
//     cin>>a>>x>>y;
//     if(x>y) swap(x,y);
//     if(a>=x && a<=y){
//         cout<<"No"<<endl;
//         return;
//     }
//     cout<<"Yes"<<endl;
// }

// bool check(int n,int arr[]){
//     for(int i=1;i<n-1;i++){
//         if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) return true;
//         if(arr[i-1]>arr[i] && arr[i]<arr[i+1]) return true;
//     }
//     return false;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     for(int i=0;i<n-1;i++){
//         if(abs(arr[i]-arr[i+1])<=1){
//             cout<<0<<endl;
//             return;
//         }
//     }
//     if(check(n,arr)) cout<<1<<endl;
//     else cout<<-1<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr.begin(),arr.end());
//     for(int i=0;i<n;i++){

//     }
//     int ans = 0;
//     int ind2 = lower_bound(arr.begin(),arr.end(),arr[n-1]) - arr.begin();
//     // cout<<ind2<<endl;
//     for(int i=0;i<n-2;i++){
//         for(int j=i+1;j<n-1;j++){
//             int k1 = arr[n-1]-arr[i]-arr[j] + 1;
//             int k2 = arr[i]+arr[j];
//             int ind1 = lower_bound(arr.begin(),arr.end(),k1)-arr.begin();
//             int ind2 = lower_bound(arr.begin(),arr.end(),k2)-arr.begin();

//             ind1 = max(j+1,ind1);

//             if(ind1 >= ind2) continue;
//             ans += (ind2-ind1);
//         }
//     }
//     cout<<ans<<endl;
// }

// int hg(int node,int par,vector<int> adj[]){
//     int total = 0;
//     for(int ele : adj[node]){
//         if(ele == par) continue;
//         total = max(hg(ele,node,adj),total);
//     }
//     return total+1;
// }

// int hg(int node,int par,vector<int> adj[],vector<int> &height){
//     int total = 0;
//     for(int ele : adj[node]){
//         if(ele == par) continue;
//         total = max(hg(ele,node,adj,height),total);
//     }
//     return height[node] = total+1;
// }

// void dfs(int node,vector<bool> &vis,vector<int> adj[],int &cnt,vector<pair<int,int>> &ans,queue<pair<int,int>> &q,vector<int> &height){
//     if(cnt>=3) return;

//     for(int ele : adj[node]){
//         if(vis[ele]) continue;
//         if(cnt >= 3) return;
//         if(height[ele] >= (3-cnt)){
//             cnt++;
//             vis[ele] = 1;
//             ans.push_back({node,ele});
//             q.push({ele,0});
//             dfs(ele,vis,adj,cnt,ans,q,height);
//         }
//     }
// }

void print(queue<pair<int,int>>q){
    while(!q.empty()){
        cout<<q.front().first<<" "<<q.front().second<<endl;
        q.pop();
    }
}

void solve(){
    int n;cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n<3){
        cout<<"No"<<endl;
        return;
    }
    int cnt = 1;
    vector<pair<int,int>> ans;
    queue<pair<int,int>> q;
    vector<bool> vis(n+1,0);

    // int st = -1;
    // for(int i=1;i<=n;i++){
    //     if(hg(i,-1,adj) > 2 && adj[i].size()>2){
    //         st = i;
    //         break;
    //     }
    // }

    // vector<int> height(n+1,0);
    // hg(st,-1,adj,height);

    // cout<<st<<endl;
    // for(int i=1;i<=n;i++) cout<<height[i]<<" ";
    // cout<<endl;

    int st = -1;
    for(int i=1;i<=n;i++){
        if(adj[i].size()==2){
            st=i;
            ans.push_back({adj[i][0],i});
            ans.push_back({i,adj[i][1]});
            q.push({adj[i][0],0}),q.push({adj[i][1],1});
            vis[i]=1,vis[adj[i][0]]=1,vis[adj[i][1]]=1;
            break;
        }
    }

    if(st == -1){
        cout<<"No"<<endl;
        return;
    }
    // vis[st]=1;
    // q.push({st,0});
    // dfs(st,vis,adj,cnt,ans,q,height);

    // print(q);
    
    while(!q.empty()){
        int node = q.front().first;
        int lvl = q.front().second;
        q.pop();
        // cout<<node<<endl;
        
        for(int ele : adj[node]){
            if(vis[ele]) continue;
            vis[ele] = 1;
            q.push({ele,lvl+1});
            // cout<<node<<" "<<ele<<"*"<<lvl<<endl;
            if(lvl&1){
                ans.push_back({ele,node});
            }else{
                ans.push_back({node,ele});
            }
        }
        // cout<<"*"<<endl;
    }
    cout<<"Yes"<<endl;
    for(auto ele : ans) cout<<ele.first<<" "<<ele.second<<endl;
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