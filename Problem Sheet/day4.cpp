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

// Photoshoot for Gorillas
// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     int w;cin>>w;
//     int arr[w];
//     for(int i=0;i<w;i++) cin>>arr[i];
//     sort(arr,arr+w);
//     vector<int> vx(n+1,0),vy(m+1,0);
//     for(int i=0;i<n-k+1;i++) vx[i]++,vx[i+k]--;
//     for(int i=0;i<m-k+1;i++) vy[i]++,vy[i+k]--;
//     for(int i=1;i<n;i++) vx[i] += vx[i-1];
//     for(int i=1;i<m;i++) vy[i] += vy[i-1];
//     priority_queue<int> pq;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             pq.push(-(vx[i]*vy[j]));
//             if(pq.size()>w) pq.pop();
//         }
//     }
//     int ans = 0;
//     for(int i=0;i<w;i++){
//         int top = -pq.top();
//         ans += (top*arr[i]);
//         pq.pop();
//     }
//     cout<<ans<<endl;
// }

// Expected Median
// #define MOD 1000000007 
// #define MAXN 1000001 
 
// long long factorial[MAXN]; 
// long long inverse_factorial[MAXN]; 
 
// // Function to calculate modular exponentiation (x^y % p) 
// long long power(long long x, long long y, long long p) { 
//     long long res = 1; 
//     x = x % p; 
 
//     while (y > 0) { 
//         if (y & 1) 
//             res = (res * x) % p; 
 
//         y = y >> 1; 
//         x = (x * x) % p; 
//     } 
 
//     return res; 
// } 

// void precompute_factorials() { 
//     factorial[0] = 1; 
//     inverse_factorial[0] = 1; 
 
//     for (int i = 1; i < MAXN; i++) { 
//         factorial[i] = (factorial[i - 1] * i) % MOD; 
//         inverse_factorial[i] = power(factorial[i], MOD - 2, MOD); 
//     } 
// } 

// long long nCr(int n, int r) { 
//     if (r > n) 
//         return 0; 
 
//     long long res = (factorial[n] * inverse_factorial[r]) % MOD; 
//     res = (res * inverse_factorial[n - r]) % MOD; 
 
//     return res; 
// } 

// void solve(){
//     int n,k;cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int o = 0,z = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i] == 1) o++;
//         else z++;
//     }
//     int oreq = k/2+1,zreq = k/2,ans = 0;
//     while(oreq<=o && zreq>=0){
//         int left = nCr(o,oreq);
//         int right = nCr(z,zreq);
//         int temp = (left*right)%MOD;
//         ans = (ans + temp)%MOD;
//         oreq++,zreq--;
//     }
//     cout<<ans<<endl;
// }

// Triple Operations
// vector<int> three;
// void pre(){
//     three.push_back(1);
//     int cur = 1;
//     for(int i=1;i<30;i++){
//         cur *=3;
//         if(cur>1e8) break;
//         three.push_back(cur);
//     }
// }

// void solve(){
//     int l,r;
//     cin>>l>>r;
//     int cur = l,ans = 0;
//     while(cur) ans++,cur/=3;
//     cur = l;
//     int len = three.size();
//     for(int i=0;i<len;i++){
//         if(l<=three[i]){
//             if(three[i]>r){
//                 ans += i*(r-cur+1);
//                 break;
//             }else{
//                 ans+= i*(three[i]-cur);
//                 cur = three[i];
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// Everything Nim
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> un;
//     set<int> used;
//     for(int i=0;i<n;i++){
//         if(used.find(arr[i])==used.end()){
//             un.push_back(arr[i]);
//             used.insert(arr[i]);
//         }
//     }
//     n = un.size();
//     if(n==1){
//         cout<<"Alice"<<endl;
//         return;
//     }
//     sort(arr,arr+n);
//     int pos = 0;
//     for(int i=0;i<n;i++){
//         if(i==0){
//             if(un[0] == 1) pos++;
//             else break;
//         }else{
//             if(un[i]-un[i-1]==1) pos++;
//             else break;
//         }
//     }
//     if(pos==n) pos--;
//     if(pos&1) cout<<"Bob"<<endl;
//     else cout<<"Alice"<<endl;
// }

// Colored Portals
// bool intersect(string a,string b){
//     set<char> st;
//     for(int i=0;i<2;i++) st.insert(a[i]),st.insert(b[i]);
//     if(st.size()==4) return false;
//     return true;
// }

// void solve(){
//     int n,q;
//     cin>>n>>q;
//     vector<string>v(n);
//     map<string,set<int>> mp;
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//         mp[v[i]].insert(i);
//     }
//     vector<int> ans;
//     while(q--){
//         int l,r;
//         cin>>l>>r;
//         l--,r--;
//         string sl = v[l],sr = v[r];
//         if(intersect(sl,sr)) ans.push_back(abs(r-l));
//         else{
//             int local = -1;
//             for(int i=0;i<2;i++){
//                 for(int j=0;j<2;j++){
//                     string temp;
//                     temp.push_back(sl[i]),temp.push_back(sr[j]);
//                     sort(temp.begin(),temp.end());
//                     if(mp[temp].size()==0) continue;
//                     auto it = mp[temp].lower_bound(l);
//                     if(it!=mp[temp].end()){
//                         int point = *it;
//                         int dis = abs(point-l) + abs(r-point);
//                         if(local == -1) local = dis;
//                         else local = min(local,dis);
//                     }
//                     if(it!=mp[temp].begin()){
//                         it--;
//                         int point = *it;
//                         int dis = abs(point-l) + abs(r-point);
//                         if(local == -1) local = dis;
//                         else local = min(local,dis);
//                     }
//                 }
//             }
//             ans.push_back(local);
//         }
//     }
//     for(int ele : ans) cout<<ele<<endl;
// }

// Guess The Tree
void solve(){
    int n;cin>>n;
    vector<bool> vis(n+1,0);
    vector<pair<int,int>> edges;
    for(int i=2;i<=n;i++){
        // log2N times because path is cut in half
        int init = 1;
        cout<<"? "<<init<<" "<<i<<endl;
        cout.flush();
        int x;cin>>x;
        while(x!=init){
            init=x;
            cout<<"? "<<init<<" "<<i<<endl;
            cout.flush();
            cin>>x;
        }
        edges.push_back({init,i});
    }
    cout<<"! ";
    for(auto ele : edges) cout<<ele.first<<" "<<ele.second<<" ";
    cout<<endl;
    cout.flush();
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}