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
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int cnt = 0,ans = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]>=k) cnt+=arr[i];
//         else if(arr[i]==0){
//             if(cnt>0) cnt--,ans++;
//         }
//     }
//     cout<<ans<<endl;
// }

// Robin Hood and the Major Oa
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int sum = ((n*(n+1))/2) - ((n-k)*(n-k+1)/2);
//     // cout<<sum<<endl;
//     if(sum&1) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// Robin Hood in Town
// bool check(int n,int a[],int x){
//    int arr[n];
//     for(int i=0;i<n;i++) arr[i] = a[i];
//     int sum = 0;
//     for(int i=0;i<n;i++) sum+=arr[i];
//     sum += x;
//     int avg = (sum+n-1)/n;
//     int ind = max_element(arr,arr+n)-arr;
//     arr[ind]+=x;
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(2*arr[i]>=avg) continue;
//         cnt++;
//     }
//     if(cnt>n/2) return true;
//     else return false;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     // cout<<check(n,arr,100)<<endl;
//     int lo = 0,hi = 1e16;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(n,arr,mid)) hi = mid-1;
//         else lo = mid+1;
//     }
//     if(lo<1e16) cout<<lo<<endl;
//     else cout<<-1<<endl;
// }

// Robert Hood and Mrs Hood
// void solve(){
//     int n,d,k;
//     cin>>n>>d>>k;
//     vector<pair<int,int>> vp;
//     for(int i=0;i<k;i++){
//         int l,r;
//         cin>>l>>r;
//         vp.push_back({l,r});
//     }
//     sort(vp.begin(),vp.end());
//     vector<int> jobs;
//     int st = 1,end = 1;
//     int ind = 0,cur = 0;
//     priority_queue<int> pq;
//     while(end<=n){
//         while(ind<k && end == vp[ind].first){
//             cur++;
//             pq.push(-vp[ind].second);
//             ind++;
//         }

//         if(end-st+1==d){
//             jobs.push_back(cur);
//             while(!pq.empty() && -pq.top()<=st) pq.pop(),cur--;
//             st++;
//         }
//         end++;
//     }
//     // for(int ele : jobs) cout<<ele<<" ";
//     // cout<<endl;
//     int _min = *min_element(jobs.begin(),jobs.end()),_max = *max_element(jobs.begin(),jobs.end());
//     int bro = 0,mom = 0;
//     for(int i=0;i<jobs.size();i++){
//         if(jobs[i] == _min) if(mom == 0) mom = i+1;
//         if(jobs[i] == _max) if(bro == 0) bro = i+1;
//     }
//     cout<<bro<<" "<<mom<<endl;
// }

// Rendez-vous de Marian et Robin
void dijk(int node,vector<pair<int,int>> adj[],vector<int> &dist){
    priority_queue<pair<int,int>> pq;
    pq.push({0,node});
    int horse = -1;
    dist[node] = 0;
    while(!pq.empty()){
        int par = pq.top().second,dis = -pq.top().first;
        pq.pop();
        for(auto it : adj[par]){
            int temp = it.second;
            if(temp+dis < dist[it.first]){
                dist[it.first] = temp+dis;
                pq.push({-dist[it.first],it.first});
            }
        }
    }
}

void hh(int node,vector<pair<int,int>> adj[],vector<int> &dist){
    priority_queue<pair<int,int>> pq;
    pq.push({0,node});
    while(!pq.empty()){
        int par = pq.top().second,dis = -pq.top().first;
        pq.pop();
        for(auto it : adj[par]){
            int temp = it.second/2;
            if(temp+dis < dist[it.first]){
                dist[it.first] = temp+dis;
                pq.push({-dist[it.first],it.first});
            }
        }
    }
}

void solve(){
    int n,m,horse;
    cin>>n>>m>>horse;
    vector<bool> hsn(n+1,0);
    for(int i=0;i<horse;i++){
        int temp;cin>>temp;
        hsn[temp] = 1;
    }
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int> dist(n+1,1e18),ndist(n+1,1e18),cdist(n+1,1e18),cndist(n+1,1e18);
    dijk(n,adj,dist);
    int time = 0,taken = 0;
    for(int i=1;i<=n;i++){
        if(hsn[i]){
            if(time == 0) time = i,taken = dist[i];
            else{
                if(taken>dist[i]) time = i,taken = dist[i];
            }
        }
    }
    // cout<<time<<" "<<taken<<endl;
    hh(time,adj,ndist);
    for(int i=1;i<=n;i++) dist[i] = min(dist[i],taken+ndist[i]);
    // companion
    dijk(1,adj,cdist);
    int ctime = 0,ctaken = 0;
    for(int i=1;i<=n;i++){
        if(hsn[i]){
            if(ctime == 0) ctime = i,ctaken = cdist[i];
            else{
                if(ctaken>cdist[i]) ctime = i,ctaken = cdist[i];
            }
        }
    }
    // cout<<ctime<<" "<<ctaken<<endl;
    hh(ctime,adj,cndist);
    for(int i=1;i<=n;i++) cdist[i] = min(cdist[i],ctaken+cndist[i]);
    // for(int i=1;i<=n;i++) cout<<i<<" : "<<cdist[i]<<endl;

    int ans = INT_MAX;
    for(int i=1;i<=n;i++) ans = min(ans,max(cdist[i],dist[i]));
    if(ans == INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
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