#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

bool check(int arr[],int n,int w,int mid){
    int time=0;
    for(int i=0;i<n;i++){
        time += (arr[i]+mid-1)/mid;
    }
    if(time>w) return false;
    return true;
}

void solve(){
    int n,w;cin>>n>>w;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    long long lo=1,hi = 1e9;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(arr,n,w,mid)) hi = mid-1;
        else lo = mid+1;
    }
    cout<<lo<<endl;
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