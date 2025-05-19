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

// Permutation Game
// void solve(){
//     int n,k,pb,ps;
//     cin>>n>>k>>pb>>ps;
//     int p[n+1],a[n+1];
//     for(int i=1;i<=n;i++) cin>>p[i];
//     for(int i=1;i<=n;i++) cin>>a[i];
//     int maxb = 0,maxs = 0;
//     vector<bool> visb(n+1,0),viss(n+1,0);
//     int cnt  = 0,sum = 0;
//     while(!visb[pb]){
//         visb[pb] = 1;
//         int diff = k-cnt;
//         if(diff<=0) break;
//         int calc = diff*a[pb] + sum;
//         maxb = max(maxb,calc);
//         sum += a[pb];
//         pb = p[pb];
//         cnt++;
//     }cnt = 0,sum = 0;
//     while(!viss[ps]){
//         viss[ps] = 1;
//         int diff = k-cnt;
//         if(diff<=0) break;
//         int calc = diff*a[ps] + sum;
//         maxs = max(maxs,calc);
//         sum += a[ps];
//         ps = p[ps];
//         cnt++;
//     }
//     // cout<<maxb<<" "<<maxs<<endl;
//     if(maxb==maxs) cout<<"Draw"<<endl;
//     else if(maxb>maxs) cout<<"Bodya"<<endl;
//     else cout<<"Sasha"<<endl;
// }

// Reverse Card (Easy Version)
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int ans = 0;
//     for(int i=1;i<=m;i++) ans += (n+i)/(i*i);
//     cout<<ans-1<<endl;
// }

// Permutation Counting
// bool check(int arr[],int n,int h,int k){
//     int req = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]<h) req+=(h-arr[i]);
//     }
//     if(req>k) return false;
//     return true;
// }

// void solve(){
//     int n,k;cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int lo = 1,hi = 1e13;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(arr,n,mid,k)) lo = mid+1;
//         else hi = mid-1;
//     }
//     if(hi==0) cout<<0<<endl;
//     else{
//         // cout<<hi<<"*"<<endl;
//         int ans =1+(hi-1)*n;
//         int left = k;
//         for(int i=0;i<n;i++){
//             if(arr[i]>hi) ans++;
//             else left -= (hi-arr[i]);
//         }
//         ans += left;
//         cout<<ans<<endl;
//     }
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     set<int> s;
//     for(int i=0;i<n;i++) s.insert(arr[i]);
//     if(s.size()&1) cout<<"Alice"<<endl;
//     else cout<<"Bob"<<endl;
// }

// G1. Ruler (easy version)
// void solve(){
// 	int lo = 2,hi = 999;
// 	while(lo<=hi){
// 		int mid = (lo+hi)/2;
// 		cout<<"? "<<1<<" "<<mid<<endl;
// 		cout.flush();
// 		int x;cin>>x;
// 		if(x>mid) hi = mid-1;
// 		else lo = mid+1;
// 	}
// 	cout<<"! "<<lo<<endl;
// 	cout.flush();
// }

// Ruler (hard version)
// void solve(){
// 	int lo = 0,hi = 1000;
//     while(hi-lo>1){
//         int mid1 = (2*lo+hi)/3;
//         int mid2 = (lo+2*hi)/3;
//         cout<<"? "<<mid1<<" "<<mid2<<endl;
//         cout.flush();
//         int x;cin>>x;
//         int case1 = mid1*mid2;
//         int case2 = (mid1)*(mid2+1);
//         if(x==case1) lo = mid2;
//         else if(x==case2) lo = mid1,hi = mid2;
//         else hi = mid1;
//     }
//     cout<<"! "<<hi<<endl;
// }

// void solve(){
//     string s,val;
//     cin>>s>>val;
//     int k;cin>>k;
//     map<int,int> mp;
//     int n = s.size();
//     for(int i=0;i<26;i++) mp[i] = val[i]-'0';
//     int l=0,r=0,cnt = 0,ans = 0;
//     while(r<n){
//         cnt+=!(mp[s[r]-'a']);
//         while(l<=r && cnt>k){
//             cnt-=!(mp[s[l]-'a']);
//             l++;
//         }
//         ans = max(ans,r-l+1);
//         r++;
//     }
//     cout<<ans<<endl;
// }

bool solve(){
    int n;cin>>n;
    vector<int> f(n+1,0);
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i) f[j]++;
    }
    vector<int> p;
    for(int i=2;i<=n;i++) if(f[i]==1) p.push_back(i);
    for(int i=0;i<p.size();i++) cout<<p[i]<<" ";
    cout<<endl;
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