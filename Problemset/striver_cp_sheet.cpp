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

// implementation and constructive problems
// Bit++
// void solve(){
//     int n;cin>>n;
//     int net = 0;
//     for(int i=0;i<n;i++){
//         string s;cin>>s;
//         if(s[0] == '+' || s[2] == '+') net++;
//         else net--;
//     }
//     cout<<net<<endl;
// }

// Chewbaсca and Number
// void solve(){
//     int n;cin>>n;
//     int ans=0;
//     int tens = 1;
//     while(n){
//         int num = n%10;
//         n/=10;
//         if(n==0 && num==9){
//             ans+=(num*tens);
//             tens*=10;
//             continue;
//         }
//         if(num>4) num = 9-num;
//         ans+=(num*tens);
//         tens*=10;
//     }
//     cout<<ans<<endl;
// }

// Buttons
// void solve(){
//     int n;cin>>n;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         ans += (n-i);
//         if(i!=0){
//             ans += (n-i-1)*i;
//         }
//     }
//     cout<<ans<<endl;
// }

// Rooms and Staircases
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int l = -1,r = -1;
//     for(int i=0;i<n;i++) if(s[i] == '1') l = i+1;
//     for(int i=n-1;i>=0;i--) if(s[i] == '1') r=n-i;
//     int ans = 0,temp = 0;
//     ans = max(ans,2*l);
//     ans = max(ans,2*r);
//     for(int i=0;i<n;i++){
//         if(s[i] == '0') temp++;
//         else temp+=2;
//     }
//     ans = max(ans,temp);
//     cout<<ans<<endl;
// }

// Chocolates
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int num = INT_MAX,ans = 0;
//     for(int i=n-1;i>=0;i--){
//         if(num<=0) break;
//         if(arr[i]<num){
//             ans += arr[i];
//             num = arr[i];
//         }else{
//             ans+=(num-1);
//             num--;
//         }
//     }
//     cout<<ans<<endl;
// }

// Hamburgers
// int nb,ns,nc,pb,ps,pc,r;

// bool check(int mid,int r,unordered_map<char,int> &m){
//     int reqb = mid*m['B'],reqs = mid*m['S'],reqc = mid*m['C'];
//     if(nb<reqb){
//         int left = reqb-nb;
//         int price = left*pb;
//         if(r<price) return false;
//         r-=(price);
//     }
//     if(ns<reqs){
//         int left = reqs-ns;
//         int price = left*ps;
//         if(r<price) return false;
//         r-=(price);
//         // if(mid==56) cout<<r<<"*"<<endl;
//     }
//     if(nc<reqc){
//         int left = reqc-nc;
//         int price = left*pc;
//         // if(mid==56) cout<<r<<"*"<<endl;
//         if(r<price) return false;
//         r-=(price);
//     }
//     return true;
// }

// void solve(){
//     string s;cin>>s;
//     cin>>nb>>ns>>nc>>pb>>ps>>pc>>r;
//     int n = s.size();
//     unordered_map<char,int> m;
//     for(int i=0;i<n;i++) m[s[i]]++;

//     int lo = 1,hi = 1e16;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,r,m)) lo = mid+1;
//         else hi = mid-1;
//         // cout<<lo<<" "<<hi<<" "<<mid<<endl;
//     }
//     cout<<hi<<endl;
// }

// Magic Powder - 1
// int n,k;

// bool check(int mid,int k,vector<int> &a,vector<int> &b){
//     for(int i=0;i<n;i++){
//         int req = a[i]*mid;
//         if(b[i]<req){
//             int left = req-b[i];
//             if(k<left) return false;
//             k-=left;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin>>n>>k;
//     vector<int> a(n),b(n);
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];

//     int lo = 1,hi = 2e9;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,k,a,b)) lo = mid+1;
//         else hi = mid-1;
//     }
//     cout<<hi<<endl;
// }

// Pipeline
// void solve(){
//     int n,k;cin>>n>>k;
//     if(n==1){
//         cout<<0<<endl;
//         return;
//     }
//     int _max = (k*(k-1))/2 + 1;
//     if(n<=k){
//         cout<<1<<endl;
//         return;
//     }
//     if(_max<n){
//         cout<<-1<<endl;
//         return;
//     }
//     int lo = 1,hi = k-1;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         int sum = (k*(k-1))/2 - (mid*(mid-1))/2 + 1;
//         // cout<<mid<<" "<<sum<<endl;
//         if(sum>=n) lo = mid+1;
//         else hi = mid-1;
//     }
//     // cout<<hi<<endl;
//     cout<<k-hi<<endl;
// }

// Poisoned Dagger
// bool check(int k,int h,int arr[],int n){
//     int cur = arr[0],dam = 0;
//     for(int i=1;i<n;i++){
//         if(cur+k<=arr[i])dam += k;
//         else dam += (arr[i]-cur);
//         cur = arr[i];
//     }
//     dam+=k;
//     if(dam>=h) return true;
//     return false;
// }

// void solve(){
//     int n,h;
//     cin>>n>>h;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int lo=1,hi=1e18;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,h,arr,n)) hi = mid-1;
//         else lo = mid+1;
//     }
//     cout<<lo<<endl;
// }

// Mike and Chocolate Thieves
// int calc (int n){
//     int k = cbrt(n);
//     int ways = 0;
//     // cout<<k<<"*"<<endl;
//     for(int i=2;i<=k;i++){
//         int last = (i*i*i);
//         ways += (n/last);
//         // cout<<ways<<endl;
//     }
//     return ways;
// }

// void solve(){
//     int m;cin>>m;
//     int lo = 1,hi = 1e16;
//     int ans = -1;
//     // cout<<calc(152)<<endl;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         int num = calc(mid);
//         if(num==m){
//             ans = mid;
//             hi = mid-1;  
//         }else if(num>m) hi = mid-1;
//         else lo = mid+1;
//     }
//     cout<<ans<<endl;
// }

// Increasing by Modulo
// int n,m;

// bool check(int mid,vector<int> &arr){
//     // starting by making the elements as minimum as possible
//     int prev = 0;
//     for(int i=0;i<n;i++){
//         if(prev<=arr[i]){
//             // greedily decreasing the previous values to be as lo as possible
//             int req = ((prev+m)-arr[i])%m;
//             // cout<<prev<<" "<<arr[i]<<" "<<req<<endl;
//             if(mid<req) prev = arr[i];
//         }else{
//             int req = prev-arr[i];
//             if(mid<req) return false;
//         }
//     }
//     return true;
// }

// void solve(){
//     cin>>n>>m;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     // cout<<check(1,arr)<<endl;
//     int lo = 0,hi = m;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,arr)) hi = mid-1;
//         else lo = mid+1;
//     }
//     cout<<lo<<endl;
// }

// Vasya and Robot
// int x,y,n;
// string s;
// void remove(int ind,int &netx,int &nety){
//     if(s[ind] == 'U') nety--;
//     else if(s[ind] == 'D') nety++;
//     else if(s[ind] == 'L') netx++;
//     else netx--;
// }

// void update(int ind,int &netx,int &nety){
//     if(s[ind] == 'U') nety++;
//     else if(s[ind] == 'D') nety--;
//     else if(s[ind] == 'L') netx--;
//     else netx++;
// }

// bool check(int mid,int netx,int nety){
//     int l=0,r=0;
//     // two pointers / sliding window
//     while(r<n){
//         remove(r,netx,nety);
//         if(r-l+1 == mid){
//             int req = abs(netx-x) + abs(nety-y);
//             if(req<=mid && ((req&1) == (mid&1))) return true;
//             update(l,netx,nety);
//             l++;
//         }
//         r++;
//     }
//     return false;
// }

// void solve(){
//     cin>>n;
//     cin>>s;
//     cin>>x>>y;
//     int d = abs(x)+ abs(y);
//     if(d>n || ((d&1) != (n&1))){
//         cout<<-1<<endl;
//         return;
//     }
//     int netx=0,nety=0;
//     for(int i=0;i<n;i++) update(i,netx,nety);
//     if(netx==x && nety==y){
//         cout<<0<<endl;
//         return;
//     }
//     // applying binary search on the answer to find the minimum length
//     int lo=1,hi=n;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,netx,nety)) hi = mid-1;
//         else lo = mid+1;
//         // cout<<lo<<" "<<hi<<endl;
//     }
//     cout<<lo<<endl;

// }

// Multiplication Table
// int n,m,k;
// bool check(int mid){
//     int total = 0;
//     for(int i=1;i<=n;i++) total += min(m,(mid-1)/i);
//     // cout<<total<<endl;
//     if(total < k) return true;
//     return false;
// }

// void solve(){
//     cin>>n>>m>>k;
//     int lo = 1,hi = n*m+1;
//     // check(3);
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid)) lo = mid+1;
//         else hi = mid-1;
//     }
//     cout<<hi<<endl;
// }

// Stressful Training
// int n,k;
// vector<int> a,b;
// priority_queue<pair<int,int>> pq;

// bool check(int mid,vector<int> a,priority_queue<pair<int,int>> pq){
//     int i=0;
//     while(i<k){
//         int req = -pq.top().first;
//         int ind = pq.top().second;
//         // cout<<ind<<"#"<<req<<" "<<i<<endl;
//         pq.pop();
//         if(req<i) return false;
//         a[ind] += mid;
//         // if(a[ind]>INT_MAX) a[ind]-=mid;
//         req = a[ind]/b[ind];
//         // cout<<ind<<"*"<<req<<" "<<a[ind]<<endl;
//         pq.push({-req,ind});
//         i++;
//     }
//     return true;
// }

// using the array method
// bool check(int mid,vector<int> a,vector<vector<int>> charge){
//     int ind = 0,cur = 0;
//     int loop = 1;
//     while(cur<k && loop==1){
//         loop = 0;
//         for(int i=ind;i<k;i++){
//             if(charge[i].size()==0) continue;
//             if(i<cur) return false; 
//             int node = charge[i][charge[i].size()-1];
//             charge[i].pop_back();
//             a[node] += mid;
//             if(a[node]>1e16) a[node]-=mid;
//             int net = a[node]/b[node];
//             // cout<<mid<<" "<<i<<" "<<net<<" "<<node<<endl;
//             if(net<k) charge[net].push_back(node);
//             cur++,ind = i;
//             loop = 1;
//             break;
//         }
//         // cout<<loop<<endl;
//     }

//     for(int i=0;i<k-1;i++) if(charge[i].size()!=0) return false;
//     // cout<<"*"<<endl;
//     return true;
// }

// void solve(){
//     cin>>n>>k;
//     a.resize(n),b.resize(n);
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];

//     // solving using the priority queue
//     // for(int i=0;i<n;i++) pq.push({-(a[i]/b[i]),i});
//     // cout<<check(5,a,pq)<<endl;

//     // cout<<"*"<<endl;
//     vector<vector<int>> charge(k);

//     for(int i=0;i<n;i++) if(a[i]/b[i]<k) charge[a[i]/b[i]].push_back(i);
//     // cout<<check(5,a,charge)<<endl;

//     int lo = 0,hi = 1e13;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         // cout<<mid<<endl;
//         if(check(mid,a,charge)) hi = mid-1;
//         else lo = mid+1;
//     }
//     int range = 1e13;
//     if(lo>range) cout<<-1<<endl;
//     else cout<<lo<<endl;
// }

// Knapsack
void solve(){
    int w;cin>>w;
    int arr[8];
    for(int i=0;i<8;i++) cin>>arr[i];
    vector<int> dp();
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();

    return 0;
}