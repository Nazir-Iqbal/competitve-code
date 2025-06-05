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
//     for(int i=0;i<n-1;i++){
//         if(!((arr[i]/arr[i+1] > 1) || (arr[i+1]/arr[i] > 1))){
//             cout<<"Yes"<<endl;
//             return ;
//         }
//     }
//     cout<<"No"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     vector<int> hsn(2*n+10,0);
//     vector<pair<int,int>> vp;
//     string ans;
//     for(int i=0;i<n;i++){
//         int l,r;
//         cin>>l>>r;
//         vp.push_back({l,r});
//         if(l==r){
//             hsn[l]++;
//         }
//     }
//     vector<int> prefix(2*n+10,0);
//     for(int i=0;i<2*n+10;i++) prefix[i] = (hsn[i]>0)?1:0;
//     for(int i=1;i<2*n+10;i++) prefix[i] += prefix[i-1];
//     for(int i=0;i<n;i++){
//         int l = vp[i].first, r = vp[i].second;
//         int sum = prefix[r]-prefix[l-1];
//         if(l == r){
//             if(hsn[l] > 1) ans.push_back('0');
//             else ans.push_back('1');
//         }else{
//             if((r-l+1)==sum) ans.push_back('0');
//             else ans.push_back('1');
//         }
//     }
//     cout<<ans<<endl;
// }

// using the shifting
// pair<int,int> f(int l,int r,int k,map<int,pair<int,int>> &dp){
//     int len = (r-l+1);
//     if(l>r || len < k ) return {0,0};

//     if(dp.find(len) != dp.end()){
//         return {dp[len].first + dp[len].second*(l-1) , dp[len].second};
//     }

//     int mid = (len+1)/2;
//     if(len&1){
//         if(len != 1){
//             pair<int,int> left = f(l,mid-1,k,dp);
//             pair<int,int> right = f(mid+1,r,k,dp);
//             pair<int,int> lr = {left.first+right.first + mid, left.second + right.second + 1};
//             dp[len] = {lr.first - (l-1)*lr.second,lr.second};
//             return lr;
//         }else{
//             dp[1] = {1,1};
//             return {l,1};
//         }
//     }else{
//         pair<int,int> left = f(l,mid,k,dp);
//         pair<int,int> right = f(mid+1,r,k,dp);
//         pair<int,int> lr = {left.first+right.first, left.second + right.second};
//         dp[len] = {lr.first - (l-1)*lr.second,lr.second};
//         return lr;
//     }
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     map<int,pair<int,int>> dp;
//     cout<<f(1,n,k,dp).first<<endl;
// }

// using the symmetry to solve the problem
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int sum = 0,ele = 1;
//     int mul = (n+1);
//     while(n>=k){
//         if(n&1) sum += ele;
//         n>>=1;
//         ele<<=1;
//     }
//     int ans = (mul*sum)/2;
//     cout<<ans<<endl;
// }

// Refined Product Optimality
// int MOD = 998244353;
// struct mint {
//   long long x;
//   mint(long long x=0):x((x%MOD+MOD)%MOD){}
//   mint& operator+=(const mint a) {if ((x += a.x) >= MOD) x -= MOD;return *this;}
//   mint& operator-=(const mint a) {if ((x += MOD-a.x) >= MOD) x -= MOD;return *this;}
//   mint& operator*=(const mint a) {(x *= a.x) %= MOD;return *this;}
//   mint operator+(const mint a) const {mint res(*this);return res+=a;}
//   mint operator-(const mint a) const {mint res(*this);return res-=a;}
//   mint operator*(const mint a) const {mint res(*this);return res*=a;}
//   mint pow(long long b) const {
//     mint res(1), a(*this);
//     while (b) {
//       if (b & 1) res *= a;
//       a *= a;
//       b >>= 1;
//     }
//     return res;
//   }
//   // for prime MOD
//   mint inv() const {return pow(MOD-2);}
//   mint& operator/=(const mint a) {return (*this) *= a.inv();}
//   mint operator/(const mint a) const {mint res(*this);return res/=a;}

//   // Relational operators
//   bool operator<(const mint& a) const { return x < a.x; }
//   bool operator>(const mint& a) const { return x > a.x; }
//   bool operator<=(const mint& a) const { return x <= a.x; }
//   bool operator>=(const mint& a) const { return x >= a.x; }
//   bool operator==(const mint& a) const { return x == a.x; }
//   bool operator!=(const mint& a) const { return x != a.x; }
// };
// ostream& operator<<(ostream& os, const mint& a) {os << a.x; return os;}

// int bs(mint x,vector<pair<mint,int>> &vp){
//     int l = 0,r = vp.size()-1;
//     int ans = -1;
//     while(l<=r){
//         int mid = (l+r)/2;
//         if(vp[mid].first == x){
//             ans = mid;
//             l = mid+1;
//         }else if(vp[mid].first < x) l = mid+1;
//         else r = mid-1;
//     }
//     return ans;
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     vector<mint> a(n),b(n);
//     for(int i=0;i<n;i++) cin>>a[i].x;
//     for(int i=0;i<n;i++) cin>>b[i].x;
//     vector<pair<mint,int>> vp1,vp2;
//     unordered_map<int,int> mp1,mp2;
//     for(int i=0;i<n;i++) vp1.push_back({a[i],i});
//     for(int i=0;i<n;i++) vp2.push_back({b[i],i});
//     sort(vp1.begin(),vp1.end());
//     sort(vp2.begin(),vp2.end());

//     for(int i=0;i<n;i++) mp1[vp1[i].second] = i;
//     for(int i=0;i<n;i++) mp2[vp2[i].second] = i;

//     mint ans = 1;
//     for(int i=0;i<n;i++) ans = ans * min(vp1[i].first,vp2[i].first);

//     cout<<ans.x<<" ";
//     while(q--){
//         int o,x;
//         cin>>o>>x;
//         x--;

//         if(o==1){
//             int ind = mp1[x];
//             mint ele = vp1[ind].first;
//             int last = bs(ele,vp1);
//             swap(vp1[ind],vp1[last]);
//             ans = ans/min(vp1[last].first,vp2[last].first);
//             // cout<<ind<<"$"<<last<<" "<<ele<<" "<<ans<<endl;
//             vp1[last].first += 1;
//             ans = ans * min(vp1[last].first,vp2[last].first);
//             // cout<<ind<<"$"<<last<<" "<<ele<<" "<<ans<<endl;
//             mp1[vp1[last].second] = last;
//             mp1[vp1[ind].second] = ind;
            
//         }else{
//             int ind = mp2[x];
//             mint ele = vp2[ind].first;
//             int last = bs(ele,vp2);
//             // cout<<ind<<"*"<<last<<" "<<ele<<endl;
//             swap(vp2[ind],vp2[last]);
//             ans /= min(vp2[last].first,vp1[last].first);
//             vp2[last].first += 1;
//             ans = ans * min(vp2[last].first,vp1[last].first);
//             mp2[vp2[last].second] = last;
//             mp2[vp2[ind].second] = ind;
//         }

//         cout<<ans.x<<" ";
//     }
//     cout<<endl;
// }

// Resourceful Caterpillar Sequence
// void solve(){
//     int n;cin>>n;
//     vector<int> adj[n+1];
//     vector<pair<int,int>> vp;
//     for(int i=0;i<n-1;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         vp.push_back({u,v});
//     }
//     int ans = 0;
//     unordered_set<int> lnode;
//     for(int i=1;i<=n;i++) if(adj[i].size()==1) lnode.insert(i);
//     ans = lnode.size()*(n-lnode.size());
//     vector<int> inadj[n+1];
//     for(int i=0;i<n;i++){
//         int u = vp[i].first;
//         int v = vp[i].second;
//         if(lnode.count(u) || lnode.count(v)) continue;
//         inadj[u].push_back(v);
//         inadj[v].push_back(u);
//     }

//     cout<<ans<<endl;
// }

// int f(int l,int r,vector<int> &arr,int n){
//     if(l==0 && r==n-1) return 0;
//     if(l<0 || r>=n) return INT_MAX;
//     // cout<<l<<" "<<r<<endl;
//     int left = f(l-1,r,arr,n);
//     if(l-1>=0) left += (arr[r]-arr[l-1]);
//     int right = f(l,r+1,arr,n);
//     if(r+1<n) right += (arr[r+1] - arr[l]);
//     // cout<<l<<" "<<r<<" "<<left<<" "<<right<<endl;
//     return min(left,right);
// }

int f(int l,int r,vector<int> &arr,int n,vector<vector<int>> &dp){
    if(l==0 && r==n-1) return 0;
    if(l<0 || r>=n) return INT_MAX;
    // cout<<l<<" "<<r<<endl;
    if(dp[l][r] != -1) return dp[l][r];
    int left = f(l-1,r,arr,n,dp);
    if(l-1>=0) left += (arr[r]-arr[l-1]);
    int right = f(l,r+1,arr,n,dp);
    if(r+1<n) right += (arr[r+1] - arr[l]);
    // cout<<l<<" "<<r<<" "<<left<<" "<<right<<endl;
    return dp[l][r] = min(left,right);
}

void solve(){
    int n;cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];;
    sort(arr.begin(),arr.end());
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    // cout<<endl;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        // cout<<f(i,i,arr,n,dp)<<endl;
        ans = min(ans,f(i,i,arr,n,dp));
    }
    cout<<ans<<endl;
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