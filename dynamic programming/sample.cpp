#include <bits/stdc++.h>

using namespace std;
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
// {
//     priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//     vector<int> dis(V,1e9);
//     dis[S] = 0;
//     pq.push({0,S});
//     while(!pq.empty()){
//         int node = pq.top().second;
//         pq.pop();
//         for(auto &it : adj[node]){
//             int child = it.first;
//             int dist = it.second;
//             if(dis[node]+dist<dis[child]){
//                 dis[child] = dis[node]+dist;
//                 pq.push({dis[child],child});
//             }
//         }
//     }
//     return dis;
// }

// vector<int> minimum(int n,int m,vector<vector<int>> roads,vector<int> c){
//     vector<pair<int,int>> adj1[n+1];
//     vector<pair<int,int>> adj2[n+1];
//     for(int i=0;i<m;i++){
//         int u,v,wt1,wt2;
//         u = roads[i][0];
//         v = roads[i][1];
//         wt1 = roads[i][2];
//         wt2 = roads[i][3];

//         adj1[u].push_back({v,wt1});
//         adj1[v].push_back({u,wt1});
        
//         adj2[u].push_back({v,wt2});
//         adj2[v].push_back({u,wt2});
//     }
//     vector<int> ans;
//     for(int i=1;i<=n;i++){
//         vector<int> dis1 = dijkstra(n+1,adj1,i);
//         vector<int> dis2 = dijkstra(n+1,adj2,i);
//         int cst = INT_MAX;
//         for(int j=1;j<=n;j++) cst = min(cst,dis1[j]+dis2[j]+c[j]);
//         ans.push_back(cst);
//     }
//     return ans;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> roads;
//     for(int i=0;i<m;i++){
//         int u,v,wt1,wt2;
//         cin>>u>>v>>wt1>>wt2;
//         roads.push_back({u,v,wt1,wt2});
//     }
//     vector<int> c(n+1);
//     for(int i=1;i<=n;i++) cin>>c[i];
//     vector<int> ans = minimum(n,m,roads,c);

//     for(auto ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// long long maximumSum(int N,int A[],int B[],int X){
//     // cout<<N<<" "<<X<<endl;
//     vector<vector<int>> dp(N+1,vector<int>(X+1,-1e9));

//     for(int i=0;i<=N;i++) dp[i][0] = 0;


//     for(int i=1;i<=N;i++){
//         for(int j=1;j<=X;j++){
//             if(j-B[i-1]>=0) dp[i][j] = max(dp[i-1][j],dp[i-1][j-B[i-1]] + A[i-1]);
//             else dp[i][j] = dp[i-1][j];
//         }
//     }

//     return dp[N][X];
// }

map<pair<long long,long long>,long long> mp;

int cnt = 0;
long long recur(int X,int a[],int b[],int i){
    cnt++;
    if(i<0) return -1e18;
    if(X==0) return 0;
    if(mp.find({X,i})!=mp.end()) return mp[{X,i}];
    // cout<<max(recur(X,a,b,i-1),recur(X-b[i-1],a,b,i-1) + a[i-1]);
    return mp[{X,i}] = max(recur(X,a,b,i-1),recur(X-b[i-1],a,b,i-1) + a[i-1]);
}

long long maximumSum(int N,int A[],int B[],int X){
    return recur(X,A,B,N);
}

void solve(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int x;cin>>x;
    cout<<maximumSum(n,a,b,x)<<endl;
    cout<<cnt<<endl;
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