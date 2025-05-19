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
// int n;
// int vp[10001][2];
// int dp[10001][30][30];

// double dist(int i,int j){
//     double ans = (vp[i][0]-vp[j][0])*(vp[i][0]-vp[j][0])+(vp[i][1]-vp[j][1])*(vp[i][1]-vp[j][1]);
//     ans = sqrt(ans);
//     return ans;
// }

// double recur(int ind,int cont,int skip,vector<vector<vector<double>>> &dp){
//     int last = ind - cont - 1;
//     if(skip>=30) return 1e9;
//     if(dp[ind][cont][skip]>0) return dp[ind][cont][skip];

//     // base case
//     if(ind == n-1){
//         double cst = dist(last,ind);
//         if(skip>0) cst += (1<<(skip-1));
//         return dp[ind][cont][skip] = cst;
//     }
//     double take = dist(last,ind) + recur(ind+1,0,skip,dp);
//     double nottake = recur(ind+1,cont+1,skip+1,dp);
//     return dp[ind][cont][skip] = min(take,nottake);
// }

// void solve(){
//     cin>>n;
//     vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(30,vector<double>(30,-1)));
//     for(int i=0;i<n;i++){
//         cin>>vp[i][0]>>vp[i][1];
//     }
//     cout<<fixed<<setprecision(8)<<recur(1,0,0,dp)<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==1){
//         cout<<1<<endl;
//         return;
//     }
//     if(n&1){
//         int ans=1e18;
//         for(int i=0;i<n;i++){
//             int local = 1;
//             for(int j=0;j<n;j+=2){
//                 if(j==i) j--;
//                 else local = max(local,arr[j+1]-arr[j]);
//             }
//             ans = min(ans,local);
//         }
//         cout<<ans<<endl;
//     }else{
//         int ans = 1;
//         for(int i=0;i<n;i+=2) ans = max(ans,arr[i+1]-arr[i]);
//         cout<<ans<<endl;
//     }
// }

// pair<int,int> convert(int x,vector<int> &block){
//     int bno = lower_bound(block.begin(),block.end(),x)-block.begin();
//     int ind = x;
//     if(bno!=0) ind = x-block[bno-1];
//     return {ind,bno+1};
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> p(n+1,0),ps(n+1,0),pss(n+2,0),block;
//     for(int i=1;i<=n;i++){
//         p[i] = p[i-1]+arr[i-1];
//         ps[i] = ps[i-1]+p[i];
//         block.push_back(n-i+1);
//     }
//     for(int i=1;i<n;i++) block[i] += block[i-1];
//     for(int i=n;i>0;i--) pss[i] = pss[i+1] + (n-i+1)*arr[i-1];
//     for(int i=1;i<=n;i++) pss[i]+=pss[i-1];
//     int q;cin>>q;
//     while(q--){
//         int l,r;cin>>l>>r;
//         auto cvt1 = convert(l,block);
//         auto cvt2 = convert(r,block);
//         int i1 = cvt1.first,j1 = cvt1.second;
//         int i2 = cvt2.first,j2 = cvt2.second;
//         int ans = pss[j2-1]-pss[j1-1];
//         int rem1 = (ps[i1+j1-2] - ps[j1-1]) - (p[j1-1])*(i1-1);
//         ans -= rem1;
//         int add1 = (ps[i2+j2-1] - ps[j2-1]) - (p[j2-1])*(i2);
//         ans += add1;
//         cout<<ans<<endl;
//     }
// }

// Sliding
// void solve(){
//     int n,m,r,c;
//     cin>>n>>m>>r>>c;
//     int ans = (n-r)*m + (m-c) + (n-r)*(m-1);
//     cout<<ans<<endl;
// }

// Everyone Loves Tres
// void solve(){
//     int n;cin>>n;
//     if(n&1 && n<5){
//         cout<<-1<<endl;
//         return;
//     }
//     string ans;
//     for(int i=0;i<n;i++) ans.push_back('3');
//     if(n&1){
//         ans[n-1] = '6';
//         ans[n-2] = '6';
//         ans[n-4] = '6';
//     }else{
//         ans[n-1] = '6';
//         ans[n-2] = '6';
//     }
//     cout<<ans<<endl;
// }

// Alya and Permutation
// void solve(){
//     int n;cin>>n;
//     if(n==6){
//         cout<<7<<endl;
//         cout<<1<<" "<<2<<" "<<4<<" "<<6<<" "<<5<<" "<<3<<endl;
//         return;
//     }
//     vector<int> ans;
//     if(n&1){
//         for(int i=1;i<n-1;i++){
//             if(i==1 || i==3) continue;
//             ans.push_back(i);
//         }
//         ans.push_back(1);
//         ans.push_back(3);
//         ans.push_back(n-1);
//         ans.push_back(n);
        
//     }else{
//         int x = log2(n);
//         int num1 = (1<<x)-1,num2 = (1<<x)-2;
//         for(int i=1;i<n;i++){
//             if(i==1 || i==3 || i==num1 || i==num2) continue;
//             ans.push_back(i);
//         }
//         ans.push_back(1);
//         ans.push_back(3);
//         ans.push_back(num2);
//         ans.push_back(num1);
//         ans.push_back(n);
//     }
//     int total = 0;
//     for(int i=0;i<n;i++){
//         if(i&1) total |= ans[i];
//         else total &= ans[i];
//     }
//     cout<<total<<endl;
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// D. Yet Another Real Number Problem
// const int N = 6e6+1;
// vector<int> mul(N,1);
// const int mod = 1e9+7;

// void pre(){
//     for(int i=1;i<N;i++) mul[i] = (mul[i-1]*2)%mod;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     vector<int> ans(n+1,0);
//     stack<pair<int,int>> st;
//     for(int i=1;i<=n;i++){
//         int c = 0;
//         while(!(arr[i]&1)){
//             arr[i]/=2;
//             c++;
//         }
//         ans[i] = ans[i-1];
//         while(!st.empty()){ // atmax 30
//             if(c>30 || st.top().first<(mul[c]*arr[i])){
//                 int num = st.top().first, two = st.top().second;
//                 st.pop();
//                 ans[i] = (mod+(ans[i]%mod - (mul[two]*num)%mod))%mod;
//                 ans[i] = (ans[i]+num)%mod;
//                 c+=two;
//             }else break;
//         }
//         ans[i] = (ans[i] + (mul[c]*arr[i])%mod)%mod;
//         // cout<<arr[i]<<" "<<c<<" "<<mul[c]<<" "<<ans[i]<<endl;
//         st.push({arr[i],c});
//     }
//     for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     bool arr[2*n];
//     for(int i=0;i<2*n;i++) cin>>arr[i];
//     int cnt0 = 0,cnt1 = 0;
//     for(int i=0;i<2*n;i++) (arr[i])?cnt1++:cnt0++;
//     cout<<(cnt1&1)<<" "<<min(cnt0,cnt1)<<endl;
// }

// void solve(){
//     int n,k;cin>>n>>k;
//     if(n==1){
//         cout<<1<<'\n'<<1<<'\n';
//         return;
//     }
//     if(k==1 || k==n){
//         cout<<-1<<endl;
//         return;
//     }
//     cout<<3<<endl;
//     if((k-1)%2==0){
//         cout<<1<<" "<<k-1<<" "<<k+2<<endl;
//     }else cout<<1<<" "<<k<<" "<<k+1<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int cnt = INT_MAX;
//     for(int i=0;i<n-1;i++){
//         int ind = lower_bound(arr,arr+n,arr[i]+arr[i+1])-arr;
//         int total = i + (n-ind);
//         cnt = min(cnt,total);
//     }
//     cout<<cnt<<endl;
// }

// Genokraken
// void solve(){
//     int n;cin>>n;
//     vector<int> par(n,0),leaf(n,0);
//     for(int i=0;i<n;i++) leaf[i] = i;
//     int ind = 2;
//     while(ind<n){
//         cout<<"? "<<1<<" "<<ind<<endl;
//         bool x;cin>>x;
//         if(!x){
//             par[ind]=1;
//             break;
//         }else ind++;
//     }
//     int cur = 2,node = ind+1;
//     while(cur<n && node<n){
//         cout<<"? "<<cur<<" "<<node<<endl;
//         bool x;cin>>x;
//         if(x) cur++;
//         else{
//             par[node]=leaf[cur];
//             leaf[cur]=node;
//             node++;
//         }
//     }

//     // for(int i=node;i<n;i++) par[i] = i-1;
//     cout<<"! ";
//     for(int i=1;i<n;i++) cout<<par[i]<<" ";
//     cout<<endl;
// }

// struct job{
//     int deadline;
//     int profit;
// };

// bool cmp(job a,job b){
//     return a.profit>b.profit;
// }

// void solve(){
//     int n;cin>>n;
//     vector<job> arr(n);
//     int time = 0;
//     for(int i=0;i<n;i++) cin>>arr[i].deadline,time = max(time,arr[i].deadline);
//     for(int i=0;i<n;i++) cin>>arr[i].profit;
//     sort(arr.begin(),arr.end(),cmp);
//     vector<bool> slot(n,1);
//     int ans=0;
//     for(int i=0;i<n;i++){
//         for(int j=arr[i].deadline-1;j>=0;j--){
//             if(slot[j]){
//                 ans += arr[i].profit;
//                 slot[j] = 0;
//                 break;
//             }
//         }
//     }
//     cout<<ans<<endl;
// }


void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int sum = 0,l=0,r=0;
    while(r<n){
        if(l==r){
            if(r!=n-1 && abs(arr[r+1]-arr[r]==1)) r++;
            else sum += arr[r],l++;
            r++;
        }else if(r==n-1 || ((arr[r]-arr[r-1]!=arr[r+1]-arr[r]) || abs(arr[r]-arr[r-1])!=1)){
            int len = r-l+1,oc=1;
            while(len!=0){
                sum += arr[l]*(len*oc);
                cout<<len<<" "<<oc<<" "<<arr[l]<<endl;
                len--,oc++,l++;
            }
            r++;
        }else r++;
    }
    cout<<sum<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    // pre();
    // cout<<"*"<<endl;
    while(t--){
      solve();
    }
    // solve();
    return 0;
}