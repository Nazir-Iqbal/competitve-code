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

// Sakurako's Exam
// void solve(){
//     int a,b;
//     cin>>a>>b;
//     if(a%2==0 && b%2==0){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     if(a%2==0 && a>0 && b&1){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     cout<<"No"<<endl;

// }

// bool check(int n,int m,string &s){
//     int len = s.size();
//     char mat[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) mat[i][j] = s[i*m+j];
//     }
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<m;j++) cout<<mat[i][j]<<" ";
//     //     cout<<endl;
//     // }
//     for(int i=0;i<m;i++){
//         if(mat[0][i]=='0') return false;
//         if(mat[n-1][i]=='0') return false;
//     }
//     for(int i=1;i<n-1;i++){
//         for(int j=0;j<m;j++){
//             if(j==0||j==m-1){
//                 if(mat[i][j]!='1') return false;
//             }else{
//                 if(mat[i][j] == '1') return false;
//             }
//         }
//     }
//     return true;
// }

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int num1 = sqrt(n);
//     if(num1*num1!=n){
//         cout<<"No"<<endl;
//         return;
//     }
//     if(check(num1,num1,s)){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     cout<<"No"<<endl;
// }

// Longest Good Array
// map<int,int> mp;
// void pre(){
//     int st = 1,cnt = 1,diff = 1;
//     mp[st] = cnt;
//     while(st<=2e9){
//         st+=diff;
//         diff++,cnt++;
//         mp[st] = cnt;
//     }
// }

// void solve(){
//     int l,r;
//     cin>>l>>r;
//     int range = r-l+1;
//     auto it = mp.upper_bound(range);
//     it--;
//     cout<<(*it).second<<endl;
// }

// Sakurako's Hobby
// void dfs(int node,vector<int> &vis,vector<int> &ans,string &s,vector<int> &arr){
//     vector<int> v;
//     int i=node,bl = 0;
//     while(vis[i]==-1){
//         vis[i] = 1;
//         if(s[i-1]=='0') bl++;
//         v.push_back(i);
//         // cout<<i<<" ";
//         i=arr[i];
//     }
//     // cout<<endl;
//     for(int &ele : v) ans[ele] = bl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> arr(n+1,0);
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     string s;cin>>s;
//     vector<int> ans(n+1,-1),vis(n+1,-1);
//     for(int i=1;i<=n;i++){
//         if(vis[i] == -1) dfs(i,vis,ans,s,arr);
//     }
//     for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// Alternating String
// void check(int n,string &s){
//     int suffix1[n+1][26] = {0};
//     int suffix2[n+1][26] = {0};
//     for(int i=n-1;i>=0;i--){
//         if(i&1) suffix1[i][s[i]-'a']++;//cout<<i<<"*"<<endl;
//         else suffix2[i][s[i]-'a']++;
//     }
//     // cout<<s<<endl;
//     for(int i=n-1;i>=0;i--){
//         for(int j=0;j<26;j++){
//             suffix1[i][j] += suffix1[i+1][j];
//             suffix2[i][j] += suffix2[i+1][j];
//         }
//     }
//     // for(int i=0;i<=n;i++){
//     //     for(int j=0;j<26;j++) cout<<suffix1[i][j]<<" ";
//     //     cout<<endl;
//     // }
//     int ans = INT_MAX;
//     if(n%2==0){
//         int max1 = 0,max2=0;
//         for(int i=0;i<26;i++){
//             max1 = max(max1,suffix1[0][i]);
//             max2 = max(max2,suffix2[0][i]);
//         }
//         // cout<<max1<<" "<<max2<<endl;
//         ans = n-max1-max2;
//         cout<<ans<<endl;
//         return;
//     }
//     vector<int> p1(26,0),p2(26,0);
//     for(int i=0;i<n;i++){
//         int max1=0,max2=0;
//         for(int j=0;j<26;j++){
//             max1 = max(max1,suffix2[i+1][j]+p1[j]);
//             max2 = max(max2,suffix1[i+1][j]+p2[j]); 
//         }
//         int calc = n-max1-max2;
//         ans = min(ans,calc);
//         if(i&1) p1[s[i]-'a']++;
//         else p2[s[i]-'a']++;
//     }
//     cout<<ans<<endl;
// }
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     check(n,s);
// }

// Sakurako's Box
// const int mod = 1e9+7;
// long long power(long long a, long long b){
//     long long result = 1;
//     while (b) {
//         if (b & 1)
//             result = (result * a) % mod;
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return result;
// }

// int mmi(int a, int m) 
// {  
//        int ans = power(a, m-2);
//        return ans;  
// } 
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int sum = 0,num = 0;
//     for(int i=n-1;i>0;i--){
//         sum+=arr[i];
//         sum%=mod;
//         int calc = (sum*arr[i-1])%mod;
//         num = (num+calc)%mod;
//     }
//     num%=mod;
//     int den = (n*(n-1))/2;
//     den%=mod;
//     int ans = (num*mmi(den,mod))%mod;
//     cout<<ans<<endl;
// }

void solve(){
    
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    // pre();
    while(t--){
      solve();
    }

    return 0;
}