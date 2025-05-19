#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// // Spell Shortening
// void solve(){
//     // cout<<"Hello"<<endl;
//     int n;cin>>n;
//     string s;cin>>s;
//     int ind = n-1;
//     for(int i=0;i<n-1;i++){
//         if(s[i]>s[i+1]){
//             ind = i;
//             break;
//         }
//     }
//     string ans = "";
//     for(int i=0;i<n;i++){
//         if(i==ind) continue;
//         ans.push_back(s[i]);
//     }
//     cout<<ans<<endl;
// }

// Weapon Choice
// int calc(int h,int x){
//     int time = 0;
//     if(h%x==0) time = h/x;
//     else time = h/x+1;
//     return time;
// }
// void solve(){
//     int h,x,y1,y2,k;
//     cin>>h>>x>>y1>>y2>>k;
//     int time = calc(h,x);
//     int temp = 0;
//     if(y1*k>=h) temp = calc(h,y1);
//     else{
//         temp = k;
//         h-=(y1*k);
//         temp+=calc(h,y2);
//     }
//     cout<<min(temp,time)<<endl;
// }

// Not Prime Permutation
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n<=2){
//         cout<<-1<<endl;
//         return;
//     }
//     int odd=1,even=2;
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         if(arr[i]==1){
//             if(n&1) cout<<n<<" ";
//             else cout<<n-1<<" ";
//         }else if(arr[i]&1){
//             cout<<odd<<" ";
//             odd+=2;
//         }else{
//             cout<<even<<" ";
//             even+=2;
//         }
//     }
//     cout<<endl;
// }

// Equality Etiquette
// void solve(){
//   int x,y;
//   cin>>x>>y;
//   int diff = abs(x-y);
//   if(diff==0){
//     cout<<0<<endl;
//     return;
//   }
//   // cout<<diff<<"*"<<endl;
//   // implement the binary search
//   int lo = 0,hi = 1e9;
//   while(lo<=hi){
//     int mid = (hi+lo)/2;
//     if((mid*(mid+1))/2<diff){
//       lo = mid+1;
//     }else{
//       hi = mid-1;
//     }
//     // cout<<lo<<" "<<hi<<endl;
//   }
//   // cout<<lo<<endl;
//   int sum = (lo*(lo+1))/2;
//   if(sum==diff){
//     cout<<lo<<endl;
//   }else{
//     int absdiff = abs(sum-diff);
//     if(absdiff&1){
//       int sum2 = ((lo+1)*(lo+2))/2;
//       if(abs(sum2-diff)&1) cout<<lo+2<<endl;
//       else cout<<lo+1<<endl;
//     }else cout<<lo<<endl;
//   }
// }

// Spread Spree
void solve(){
  int n,m;
  cin>>n>>m;
  int mod = 998244353;
  if(m>n) swap(n,m);
  int ans = 0;
  int k = n/2;
  int l = max(1ll,m-k);
  int r = min(m,1+k);
  // cout<<l<<" "<<r<<endl;
  ans += ((r*(r+1))/2-(l*(l-1))/2)*(k+1);
  if(n%2==0){
    ans += ((r*(r+1))/2-(l*(l-1))/2)*k;
  }
  cout<<ans%mod<<endl;
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