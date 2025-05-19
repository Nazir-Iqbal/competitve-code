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
//     int x,y,k;
//     cin>>x>>y>>k;
//     if(x==y){
//         cout<<0<<" "<<0<<" "<<x<<" "<<y<<endl;
//         cout<<x<<" "<<0<<" "<<0<<" "<<y<<endl;
//     }else{
//         if(k<=y && k<=x){
//             cout<<0<<" "<<0<<" "<<0<<" "<<y<<endl;
//             cout<<0<<" "<<0<<" "<<x<<" "<<0<<endl;
//         }else{
//             if(x>y){
//                 int diff = x-y;
//                 cout<<0<<" "<<0<<" "<<y<<" "<<y<<endl;
//                 cout<<x<<" "<<0<<" "<<diff<<" "<<y<<endl;
//             }else{
//                 int diff = y-x;
//                 cout<<0<<" "<<diff<<" "<<x<<" "<<y<<endl;
//                 cout<<0<<" "<<y-diff<<" "<<x<<" "<<0<<endl;
//             }
//         }
//     }
// }

void print(set<int> s){
    for(int ele : s) cout<<ele<<" ";
    cout<<endl;
}

bool check(int n,int arr[],int k){
    set<int> s;
    bool used = true;
    for(int i = 0;i<n;i++){
        if(i==0){
            if(arr[i+1]-arr[i]<=k){
                s.insert(arr[0]);
                // print(s);
                continue;
            }
            used = false;
            s.insert(arr[0]+k);
            continue;
        }
        int left = arr[i]-k;
        if(s.lower_bound(left)==s.end()){
            if(i!=n-1){
                if(arr[i+1]-arr[i]<=k){
                    s.insert(arr[i]);
                    continue;
                }
            }
            // cout<<i<<"*"<<endl;
            if(used){
                used = false;
                s.insert(arr[i]+k);
                // print(s);
                continue;
            }
            return false;
        }
        s.insert(arr[i]);
    }
    return true;
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==1){
        cout<<1<<endl;
        return;
    }
    int lo = 1,hi = 1e18;
    // cout<<check(n,arr,5)<<endl;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(n,arr,mid)) hi = mid-1;
        else lo = mid+1;
    }
    cout<<lo<<endl;
}

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     set<int> st0,st1;
//     for(int i=0;i<n;i++){
//         if(s[i] == '1') st1.insert(i+1);
//         else st0.insert(i+1);
//     }
//     int ans = 0;
//     for(int i=n-1;i>=0;i--){
//         if(s[i]=='1'){
//             if(st1.find(i+1)==st1.end()) continue;
//             st1.erase(i+1);
//             if(st0.size()!=0){
//                 int ind = *st0.rbegin();
//                 ans += ind;
//                 st0.erase(ind);
//             }else if(st1.size()!=0){
//                 int ind = *st1.begin();
//                 ans += ind;
//                 // cout<<i<<"*"<<ind<<endl;
//                 st1.erase(ind);
//             }else ans += i+1;
//         }else{
//             if(st0.find(i+1)==st0.end()) continue;
//             ans += i+1;
//             // cout<<i<<"*"<<ans<<endl;
//             st0.erase(i+1);
//         }
//     }
//     cout<<ans<<endl;
// }

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