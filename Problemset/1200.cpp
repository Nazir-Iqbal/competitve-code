#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Tandem Repeats?
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int num = 2;
//     for(int i=1;i<62;i++){
//         set<int> s;
//         for(int i=0;i<n;i++){
//             s.insert(arr[i]%num);
//         }
//         if(s.size()==2) break;
//         num*=2;
//     }
//     cout<<num<<endl;
// }

// Differential Sorting
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     bool flag = true;
//     for(int i=1;i<n;i++){
//         if(arr[i-1]>arr[i]){
//             flag = false;
//             break;
//         }
//     }
//     if(flag){
//         cout<<0<<endl;
//         return;
//     }
//     if(arr[n-1]<arr[n-2] || arr[n-1]<0){
//         cout<<-1<<nline;
//         return;
//     }
//     cout<<n-2<<endl;
//     for(int i=n-3;i>=0;i--){
//         cout<<i+1<<" "<<i+2<<" "<<n<<endl;
//     }
// }

// Pleasant Pairs
// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     int ind[2*n+1]={0};
//     for(int i=1;i<=n;i++){
//         cin>>arr[i];
//         ind[arr[i]] = i;
//     }
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=(2*n)/arr[i];j++){
//             // if(arr[i]>j) break;
//             if(arr[i]==j) continue;
//             if(ind[j] == 0) continue;
//             // cout<<arr[i]<<" "<<j<<endl;
//             if(arr[i]*j == i+ind[j]) ans++;
//         }
//     }
//     cout<<ans/2<<endl;
// }

// Stable Groups
// void solve(){
//     int n,k,x;
//     cin>>n>>k>>x;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int ans = 1;
//     vector<int> bk;
//     for(int i=1;i<n;i++){
//         int diff = arr[i] - arr[i-1];
//         if(diff>x) bk.push_back((diff-1)/x);
//     }
//     sort(bk.begin(),bk.end());
//     // for(int ele : bk) cout<<ele<<" ";
//     // cout<<endl;
//     int sz = 0;
//     for(int i=0;i<bk.size();i++){
//         if(sz>=k) ans++;
//         else{
//             if(sz+bk[i] > k) ans++,sz+=bk[i];
//             else sz+=bk[i];
//         }
//     }
//     cout<<ans<<endl;
// }

// Prinzessin der Verurteilung
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     set<string> st;
//     for(char i='a';i<='z';i++){
//         string temp;temp.push_back(i);
//         if(s.find(temp) == string::npos) st.insert(temp);
//     }
//     // cout<<st.size()<<endl;
//     if(!st.empty()){
//     // cout<<"*"<<endl;
//         cout<<(*st.begin())<<nline;
//         return;
//     }
//     for(char i='a';i<='z';i++){
//         for(char j='a';j<='z';j++){
//             string temp;
//             temp.push_back(i),temp.push_back(j);
//             if(s.find(temp) == string::npos) st.insert(temp);
//         }
//     }
//     if(!st.empty()){
//         cout<<(*st.begin())<<nline;
//         return;
//     }
//     for(char i='a';i<='z';i++){
//         for(char j='a';j<='z';j++){
//             for(char k='a';k<='z';k++){
//                 string temp;
//                 temp.push_back(i),temp.push_back(j),temp.push_back(k);
//                 if(s.find(temp) == string::npos) st.insert(temp);
//             }
//         }
//     }
//     if(!st.empty()){
//         cout<<(*st.begin())<<nline;
//         return;
//     }
// }

// Palindrome Game (easy version)
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(s[i] == '0') cnt++;
//     }
//     if(cnt==0) cout<<"DRAW"<<nline;
//     else if(cnt==1) cout<<"BOB"<<nline;
//     else{
//         if(n&1){
//             if(s[n/2]=='1') cout<<"BOB"<<nline;
//             else{
//                 if(cnt==2) cout<<"BOB"<<nline;
//                 else cout<<"ALICE"<<endl;
//             }
//         }else cout<<"BOB"<<nline;
//     }
// }

// Same Differences
// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     map<int,int> mp;
//     int ans = 0;
//     for(int i=n;i>0;i--){
//         mp[arr[i] - i]++;
//         ans += (mp[arr[i]-i]-1);
//     }
//     cout<<ans<<nline;
// }

// AND 0, Sum Big
// int mod = 1e9+7;
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int ans = 1;
//     for(int i=0;i<k;i++) ans = (ans*n)%mod;
//     cout<<ans<<endl;
// }

// Flip the Bits
// void solve(){
//     int n;cin>>n;
//     string a;cin>>a;
//     string b;cin>>b;
//     int prefix[n+1] = {0};
//     for(int i=1;i<=n;i++){
//         if(a[i-1] == b[i-1]) prefix[i] = 0;
//         else{
//             prefix[i] = prefix[i-1]+1;
//             prefix[i-1] = 0;
//         }
//     }
//     // for(int ele : prefix) cout<<ele<<" ";
//     // cout<<endl;
//     int one[n+1] = {0},zero[n+1] = {0};
//     for(int i=1;i<=n;i++){
//         if(a[i-1]=='0') zero[i] = zero[i-1]+1,one[i] = one[i-1];
//         else one[i] = one[i-1]+1,zero[i] = zero[i-1]; 
//     }
//     for(int i=1;i<=n;i++){
//         if(prefix[i]!=0){
//             if(i&1){
//                 cout<<"No"<<endl;
//                 return;
//             }else{
//                 int l = i-prefix[i]+1;
//                 int r = i;
//                 int o1 = one[r];
//                 int z1 = zero[r];
//                 int o2 = one[l-1];
//                 int z2 = zero[l-1];
//                 // cout<<o<<" "<<z<<" "<<l<<" "<<r<<endl;
//                 if(o1!=z1 || o2!=z2){
//                     cout<<"No"<<endl;
//                     return;
//                 }
//             }
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// M-arrays
// void solve(){
//     int n,m;cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,int> cnt;
//     for(int i=0;i<n;i++){
//         arr[i] = arr[i]%m;
//         cnt[arr[i]]++;
//     }
//     int ans = n;
//     for(int i=0;i<=m/2;i++){
//         if(cnt[i] == 0) continue;
//         if(i==0) ans-=(cnt[0]-1);
//         else{
//             int l = i;
//             int r = m-i;
//             if(l==r) ans-=(cnt[l]-1);
//             else{
//                 int take = 2*min(cnt[l],cnt[r]);
//                 if(cnt[l]!=cnt[r]) take++;
//                 ans-=(take-1);
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// Cat Cycle
// void solve(){
//     int n,k;cin>>n>>k;
//     int ans = 0;
//     if(n&1){
//         int mid = n/2;
//         ans = (k+((k-1)/mid))%n;
//     }else ans = k%n;
//     if(ans==0) ans = n;
//     cout<<ans<<endl;
// }

// Districts Connection
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int l = -1,r=-1;
//     for(int i=0;i<n;i++){
//         if(l==-1) l = i;
//         else if(arr[i] != arr[l]){
//             r=i;
//             break;
//         }
//     }
//     if(l==-1 || r==-1){
//         cout<<"No"<<nline;
//         return;
//     }
//     cout<<"Yes"<<nline;
//     bool vis[n] = {0};
//     vis[l] = 1,vis[r] = 1;
//     cout<<l+1<<" "<<r+1<<nline;
//     for(int i=0;i<n;i++){
//         if(!vis[i]){
//             vis[i] = 1;
//             if(arr[i] == arr[l]){
//                 cout<<i+1<<" "<<r+1<<nline;
//             }else cout<<i+1<<" "<<l+1<<nline;
//         }
//     }
// }

// Rock and Lever
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 0;
    bool vis[n] = {0};
    for(int i=31;i>=0;i--){
        int num = (1ll<<i);
        int cnt =  0;
        for(int j=0;j<n;j++){
            if(arr[j]>=num){
                if(!vis[j]) cnt++;
                vis[j] = 1;
                // cout<<i<<" "<<arr[j]<<endl;
            }
        }
        ans += (cnt*(cnt-1))/2;
    }
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }
    // solve();
    return 0;
}