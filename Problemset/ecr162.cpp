#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];

//     int ans=0;
//     int zero = 0;
//     bool flag = false;
//     for(int i=0;i<n;i++){
//         if(arr[i]==1 && flag){
//             ans += zero;
//             zero=0;
//         }
//         if(flag){
//             if(arr[i] == 0) zero++;
//         }
//         if(arr[i] == 1) flag = true;
//     }
//     cout<<ans<<endl;
// }

// Monsters Attack!
// struct mon{
//     int health,distance;
// };

// bool cmp(mon x,mon y){
//     return x.distance<y.distance;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     mon monster[n];
//     for(int i=0;i<n;i++) cin>>monster[i].health;
//     for(int i=0;i<n;i++){
//         int dis;
//         cin>>dis;
//         dis = abs(dis);
//         monster[i].distance = dis;
//     }

//     // sort(monster,monster+n,cmp);

//     int hsn[n+1] = {0};
//     for(int i=0;i<n;i++){
//         hsn[monster[i].distance] += monster[i].health;
//     }

//     int extra = 0;
//     for(int i=1;i<=n;i++){
//         extra = (extra+k) - hsn[i];
//         // cout<<extra<<endl;
//         if(extra<0){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Find B
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> prefix(n+1,0),ones(n+1,0);
//     for(int i=1;i<=n;i++){
//         prefix[i] = arr[i-1] + prefix[i-1];
//         if(arr[i-1]==1) ones[i] += ones[i-1]+1;
//         else ones[i] = ones[i-1];
//     }

//     // for(auto ele : ones) cout<<ele<<" ";
//     // cout<<endl;

//     while(m--){
//         int l,r;
//         cin>>l>>r;
//         int sum = prefix[r]-prefix[l-1];
//         int range = (r-l)+1;
//         int one = ones[r]-ones[l-1];
//         int calc = sum - range;
//         // cout<<calc<<" "<<one<<endl;
//         if(range==1){
//             cout<<"No"<<endl;
//             continue;
//         }
//         if(calc>=one) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// Slimes
bool isPossible(int mid,int point,vector<int> &cnt,vector<int> &prefix,int ele){
    int l = min(mid,point);
    int r = max(mid,point);
    int sum = 0,distinct = 0;
    if(l==0) sum = prefix[r],distinct = cnt[r];
    else sum = prefix[r] - prefix[l-1],distinct = cnt[r] - cnt[l];
    // if(point==3) cout<<mid<<" "<<ele<<" "<<sum<<" "<<distinct<<endl;
    if(sum>ele && distinct>0) return true;
    return false;
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    // for debug
    // if(tt==88){
    //     for(int ele : arr) cout<<ele<<' ';
    //     cout<<'\n';
    // }

    vector<int> cnt(n,0),prefix(n,0);
    for(int i=1;i<n;i++){
        if(arr[i] != arr[i-1]) cnt[i] = cnt[i-1]+1;
        else cnt[i] = cnt[i-1];
    }

    prefix[0] = arr[0];
    for(int i=1;i<n;i++) prefix[i] = arr[i] + prefix[i-1];
    // for(int ele : cnt) cout<<ele<<' ';
    // cout<<endl;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        // cout<<"*"<<endl;
        if(i!=0){
            if(arr[i]<arr[i-1]){
                ans[i] = 1;
                continue;
            }
        }
        if(i!=n-1){
            if(arr[i]<arr[i+1]){
                ans[i] = 1;
                continue;
            }
        }
        // checking from the left side
        int lo = 0,hi = i-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(isPossible(mid,i-1,cnt,prefix,arr[i])) lo = mid+1;
            else hi = mid-1;
            // if(i==4) cout<<lo<<" "<<hi<<" "<<mid<<endl;
        }
        if(hi!=-1){
            ans[i] = (i-hi);
        }
        // cout<<i<<" "<<lo<<" "<<hi<<endl;

        lo = i+1,hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(isPossible(mid,i+1,cnt,prefix,arr[i])) hi = mid-1;
            else lo = mid+1;
        }
        if(lo!=n){
            if(ans[i]!=-1) ans[i] = min((lo-i),ans[i]);
            else ans[i] = (lo-i);
        }

    }
    for(int ele : ans) cout<<ele<<" ";
    cout<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    // int tt=1;
    while(t--){
      solve();
    }

    return 0;
}