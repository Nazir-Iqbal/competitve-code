#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
int M = 1e9+7;
// using namespace __gnu_pbds;

#define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Cookie Day
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int cnt = 0,ans=INT_MAX;
//     for(int i=0;i<n;i++){
//         cnt = arr[i]/k;
//         if(cnt>0) ans = min(ans,arr[i]%k);
//     }
//     if(ans!=INT_MAX) cout<<ans<<endl;
//     else cout<<-1<<endl;
// }

// Another Good String
// void solve(){
//     int n,q;
//     cin>>n>>q;
//     string s;cin>>s;
//     for(int i=0;i<q;i++){
//         char c;cin>>c;
//         s.push_back(c);
//     }
//     int lo=0,hi=0,total=0;
//     vector<int> ans;
//     // sliding window
//     while(hi<n+q){
//         if(s[lo]==s[hi]) total = max(total,hi-lo+1);
//         else lo = hi;
//         if(hi>=n-1) ans.push_back(total);
//         hi++;
//     }
//     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// K Odd Sum
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> ans;
//     int lo=0,le=0;
//     for(int i=1;i<=k;i++)ans.push_back(i);
//     if(ans[k-1]&1){
//         lo=ans[k-1];
//         if(k>1) le = ans[k-2];
//         for(int i=lo+2;i<=n;i+=2) ans.push_back(i);
//         for(int i=le+2;i<=n;i+=2) ans.push_back(i);
//     }else{
//         le=ans[k-1];
//         lo = ans[k-2];
//         for(int i=le+2;i<=n;i+=2) ans.push_back(i);
//         for(int i=lo+2;i<=n;i+=2) ans.push_back(i);
//     }
//     for(int i=0;i<n;i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// Unalike Gcd & Lcm
// void solve(){
//     int x,q;
//     cin>>x>>q;
//     map<int,int> mp;
//     for(int i=2;i*i<=x;i++){
//         if(x%i==0){
//             while(x%i==0){
//                 mp[i]++;
//                 x/=i;
//             }
//         }
//     }
//     if(x!=1) mp[x]++;
//     // for(auto ele : mp){
//     //     cout<<ele.first<<" "<<ele.second<<endl;
//     // }
//     while(q--){
//         int p;
//         cin>>p;
//         int ans=1;
//         for(auto ele : mp){
//             if(ele.second%p==0){
//                 int calc = ele.second/p;
//                 if(calc<ele.second) ans = (ans*2)%M;
//             }
//         }
//         cout<<ans<<endl;
//     }
// }

// Xorred
void solve(){
    
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}