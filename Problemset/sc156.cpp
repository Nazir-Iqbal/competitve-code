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
//     int odd = 0,even = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]&1) odd++;
//         else even++;
//     }
//     // cout<<even<<' '<<odd<<endl;
//     if(odd==0){
//         cout<<0<<endl;
//         return;
//     }
//     int ans = (1+even) +(odd-1)/2;
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,k;cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int small = 0,second = n-k-1;
//     if(second == 0) second++;
//     int ans = arr[n-1] +arr[n-2]+arr[small]+arr[second];
//     if(k==1){
//         int res = ans;
//         res += (arr[n-1]-arr[second]);
//         ans = max(ans,res);
//     }
//     cout<<ans<<endl;
// }


// Count Triplets
// int left(int arr[],int n,int i){
//     int l = max(0,i-101);
//     int ans = 0;
//     for(int k=l;k<=i;k++){
//         int diff = abs(arr[k]-arr[i]);
//         int dis = abs(k-i);
//         if(dis==diff){
//             ans += abs(k-i)+1;
//         }else if(diff>dis){
//             int req = diff-dis;
//             if(req&1) continue;
//             req/=2;
//             if(i+req<n) ans++;
//             if(k-req>=0) ans++;
//         }    }
//     return ans;
// }

// int right(int arr[],int n,int i){
//     int r = min(n-1,i+101);
//     int ans = 0;
//     for(int k=i+1;k<=r;k++){
//         int diff = abs(arr[k]-arr[i]);
//         int dis = abs(k-i);
//         if(dis==diff) ans += abs(k-i)+1;
//         else if(diff>dis){
//             int req = diff-dis;
//             if(req&1) continue;
//             req/=2;
//             if(k+req<n) ans++;
//             if(i-req>=0) ans++;
//         }
//     }
//     return ans;
// }
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = 0;
//     // ans = left(arr,n,2);
//     for(int i=0;i<n;i++){
//         ans += left(arr,n,i);
//         ans += right(arr,n,i);
//     }
//     cout<<ans<<endl;
// }

// Balance Difficulties
// bool check(vector<int> &arr,int n,int k,int mid){
//     vector<int> c = arr;
//     c[0] += mid;
//     for(int i=1;i<n;i++){
//         if(c[i]-mid>c[i-1]+k) return false;
//         c[i] = min(c[i-1]+k,mid+c[i]);
//     }
//     return true;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==1){
//         cout<<0<<endl;
//         cout<<arr[0]<<endl;
//         return;
//     }
//     int lo=0,hi = 1e10;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(arr,n,k,mid)) hi = mid-1;
//         else lo = mid+1;
//     }
//     vector<int> c = arr;
//     c[0] += lo;
//     for(int i=1;i<n;i++){
//         c[i] = min(c[i-1]+k,lo+c[i]);
//     }
//     cout<<lo<<endl;
//     for(int ele : c) cout<<ele<<" ";
//     cout<<endl;
// }

// Interval Cliques
// int lis(vector<int> &arr){
//     int n = arr.size();
//     vector<int> temp;
//     for(int i=0;i<n;i++){
//         if(temp.empty()) temp.push_back(arr[i]);
//         else if(temp[temp.size()-1]<arr[i]) temp.push_back(arr[i]);
//         else{
//             int ind= lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
//             temp[ind] = arr[i];
//         }
//     }
//     return temp.size();
// }

// void solve(){
//     int n;cin>>n;
//     vector<pair<int,int>> vp;
//     for(int i=0;i<n;i++){
//         int u,v;
//         cin>>u>>v;
//         vp.push_back({u,v});
//     }
//     sort(vp.begin(),vp.end());
//     vector<int> seq;
//     for(int i=0;i<n;i++) seq.push_back(vp[i].second);
//     int ans = lis(seq);
//     cout<<ans<<endl;
// }

// Keep Magnets Separated
// int diameter 

void solve(){
    int n;cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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