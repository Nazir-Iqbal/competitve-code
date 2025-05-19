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

// Yet Another Problem About Pairs Satisfying an Inequality
// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     vector<int> suffix(n+2,0);
//     for(int i=1;i<=n;i++){
//       if(i>arr[i]) suffix[arr[i]]++;
//     }
//     for(int i=n;i>0;i--) suffix[i] += suffix[i+1];
//     int ans = 0;
//     for(int i=1;i<=n;i++){
//       if(i>arr[i]) ans += (suffix[i+1]);
//     }
//     cout<<ans<<nline;
// }

// Deep Down Below
// bool cmp(pair<int,int> x,pair<int,int> y){
//   if(x.first == y.first) return x.second>y.second;
//   return x.first<y.first;
// }

// void solve(){
//   int n;cin>>n;
//   vector<pair<int,int>> v;
//   for(int i=0;i<n;i++){
//     int k;cin>>k;
//     int _max = 0;
//     for(int i=0;i<k;i++){
//       int temp;cin>>temp;
//       _max = max(_max,temp-i);
//     }
//     v.push_back({_max,k});
//   }

//   // checkting for the monster with highest health and increasing the health of
//   // armour by k
//   sort(v.begin(),v.end(),cmp);
//   int base = v[0].first+1,out = 0;
//   for(int i=0;i<n;i++){
//     if(base<=v[i].first) out += v[i].first-base+1,base = v[i].first+1;
//     base+=v[i].second;
//   }

//   cout<<v[0].first+out+1<<endl;
// }

// Box Fitting
// void solve(){
//   int n,w;
//   cin>>n>>w;
//   int arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];
//   vector<int> hsn(31,0);
//   for(int i=0;i<n;i++) hsn[log2(arr[i])]++;
//   // for(int i=0;i<31;i++) cout<<hsn[i]<<" ";
//   // cout<<endl;
//   int cnt=0;
//   int ans = 0;
//   while(cnt<n){
//     ans++;
//     int sum = w;
//     for(int i=30;i>=0;i--){
//       int num = 1<<i;
//       if(hsn[i]>0 && sum>=num){
//         while(hsn[i]>0 && sum>=num){
//           if(cnt==n) break;
//           sum-=num;
//           hsn[i]--;
//           cnt++;
//         }
//       }
//       // cout<<cnt<<endl;
//       if(cnt==n) break;
//     }
//   }
//   cout<<ans<<endl;
// }

// Strange Birthday Party
// void solve(){
//   int n,m;
//   cin>>n>>m;
//   int a[n+1],b[m+1];
//   for(int i=1;i<=n;i++) cin>>a[i];
//   for(int i=1;i<=m;i++) cin>>b[i];
//   sort(a+1,a+n+1,greater<int>());
//   int ind = 1;
//   int ans = 0;
//   for(int i=1;i<=n;i++){
//     if(a[i]>=ind){
//       if(b[ind]==b[a[i]]){
//         ans+=b[ind];
//       }else ans+=b[ind],ind++;
//     }else ans+=b[a[i]];
//       //cout<<ind<<endl;
//   }
//   cout<<ans<<nline;
// }

// Move and Turn
// void solve(){
//   int n;cin>>n;
//   if(n&1){
//     int k = (n-1)/2;
//     cout<<2*(k+1)*(k+2)<<endl;
//   }else{
//     int k = n/2;
//     cout<<(k+1)*(k+1)<<endl;
//   }
// }

// Omkar and Last Class of Math
// void solve(){
//   int n;cin>>n;
//   if(n&1){
//     pair<int,int> ans;
//     int lcm = INT_MAX;
//     for(int i=1;i*i<=n;i++){
//       if(n%i==0){
//         int num1 = i;
//         int num2 = n/i;
//         // calcuclating the lcm using the num1;
//         int calc = (num1*(n-num1))/__gcd(num1,n-num1);
//         if(lcm>calc){
//           ans={num1,n-num1};
//           lcm = calc;
//         }
//         // calculating the lcm using the num2
//         if(num2==n) continue;
//         calc = (num2*(n-num2))/__gcd(num2,n-num2);
//         if(lcm>calc){
//           ans = {num2,n-num2};
//           lcm = calc;
//         }
//       }
//     }
//     cout<<ans.first<<" "<<ans.second<<nline;
//   }else{
//     cout<<n/2<<" "<<n/2<<nline;
//   }
// }

// Shuffle
// void solve(){
//   int n,x,m;
//   cin>>n>>x>>m;
//   vector<pair<int,int>> v;
//   for(int i=0;i<m;i++){
//     int l,r;cin>>l>>r;
//     v.push_back({l,r});
//   }
//   int l=-1,r=-1;
//   int ind = 0;
//   for(int i=0;i<m;i++){
//     if(x>=v[i].first && x<=v[i].second){
//       ind = i;
//       l = v[i].first,r = v[i].second;
//       break;
//     }
//   }
//   int ans = 1;
//   if(l==-1){
//     cout<<ans<<nline;
//     return;
//   }
//   for(int i=ind;i<m;i++){
//     if(l>v[i].second || r<v[i].first) continue;
//     l=min(l,v[i].first);
//     r=max(r,v[i].second);
//   }
//   // cout<<l<<" "<<r<<endl;
//   ans = r-l+1;
//   cout<<ans<<endl;
// }

// Most socially-distanced subsequence
// void solve(){
//   int n;cin>>n;
//   int arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];
//   vector<int> ans;
//   ans.push_back(arr[0]);
//   for(int i=1;i<n-1;i++){
//     if(arr[i-1]>arr[i] && arr[i]>arr[i+1]) continue;
//     if(arr[i-1]<arr[i] && arr[i]<arr[i+1]) continue;
//     ans.push_back(arr[i]);
//   }
//   ans.push_back(arr[n-1]);
//   cout<<ans.size()<<nline;
//   for(int ele : ans) cout<<ele<<" ";
//   cout<<nline;
// }

// Buying Shovels
// void solve(){
//   int n,k;
//   cin>>n>>k;
//   int ans = INT_MAX;
//   for(int i=1;i*i<=n;i++){
//     if(i>k) break;
//     if(n%i==0){
//       ans = min(ans,n/i);
//       if(n/i <= k) ans = min(i,ans);
//     }
//   }
//   cout<<ans<<nline;
// }

// Product of Three Numbers
// void solve(){
//   int n;cin>>n;
//   for(int i=2;i<=1000;i++){
//     if(n%i==0){
//       int temp1 = n/i;
//       for(int j=2;j*j<=temp1;j++){
//         if(temp1%j==0){
//           int k = temp1/j;
//           set<int> s;
//           s.insert(i),s.insert(j),s.insert(k);
//           if(s.size()==3){
//             cout<<"Yes"<<nline;
//             cout<<i<<" "<<j<<" "<<k<<nline;
//             return;
//           }
//         }
//       }
//     }
//   }
//   cout<<"No"<<nline;
// }

// Just Eat It!
// void solve(){
//   int n;cin>>n;
//   int arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];
//   int sum = 0,temp = 0,total = 0;
//   for(int i=1;i<n;i++){
//     total += arr[i];
//     temp+=arr[i];
//     if(temp<0) temp = 0;
//     sum = max(sum,temp);
//   }
//   total += arr[0];
//   if(total<=sum){
//     cout<<"No"<<nline;
//     return;
//   } 
//   temp = 0;
//   for(int i=0;i<n-1;i++){
//     temp+=arr[i];
//     if(temp<0) temp = 0;
//     sum = max(sum,temp);
//   }
//   if(total<=sum){
//     cout<<"No"<<nline;
//     return;
//   }
//   cout<<"Yes"<<nline;
// }

// Balanced Tunnel
// void solve(){
//   int n;cin>>n;
//   int a[n],b[n];
//   for(int i=0;i<n;i++) cin>>a[i];
//   for(int i=0;i<n;i++) cin>>b[i];
//   int hsn[n+1] = {0};
//   for(int i=0;i<n;i++) hsn[b[i]]=i+1;
//   int cnt = 0,ind = 0;
//   for(int i=0;i<n;i++){
//     if(hsn[a[i]]>ind){
//       ind = hsn[a[i]];
//       cnt++;
//     }
//   }
//   cout<<n-cnt<<endl;
// }

// WOW Factor
// void solve(){
//   string s;cin>>s;
//   int n = s.length();
//   int prev=0,cur=0,o=0;
//   int ans = 0,total = 0;
//   for(int i=n-1;i>=0;i--){
//     if(i!=n-1 && s[i] == 'v' && s[i+1] == 'o'){
//       if(cur>1) prev+=(cur-1);
//       total += o*prev;
//       // cout<<i<<" "<<prev<<" "<<o<<" "<<cur<<" "<<total<<endl;
//       cur = 0;
//       o = 0;
//     }
//     if(s[i] == 'o') o++;
//     else{
//       cur++;
//       if(cur>1) ans+=total;
//       // cout<<cur<<" "<<total<<" "<<ans<<endl;
//     }
//   }
//   // cout<<o<<" "<<cur<<endl;
//   // if(s[0] == 'v') ans+=(cur-1)*total;
//   cout<<ans<<nline;
// }

// Alyona and a Narrow Fridge
// void solve(){
//   int n,h;
//   cin>>n>>h;
//   int arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];
//   int ans = 0;
//   for(int i=0;i<n;i++){
//     vector<int> temp;
//     for(int j=0;j<=i;j++) temp.push_back(arr[j]);
//     sort(temp.begin(),temp.end(),greater<int> ());
//     int len = i+1;
//     int sum = 0;
//     for(int j=0;j<len;j+=2){
//       sum +=temp[j];
//     }
//     // cout<<sum<<nline;
//     if(sum>h) break;
//     ans = i+1;
//   }
//   cout<<ans<<nline;
// }

// Good Array
// void solve(){
//   int n;cin>>n;
//   int arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];
//   multiset<int> s;
//   int total = 0;
//   vector<int> ans;
//   for(int i=0;i<n;i++){
//     total += arr[i];
//     s.insert(arr[i]);
//   }
//   for(int i=0;i<n;i++){
//     total -= arr[i];
//     s.erase(s.find(arr[i]));
//     // for(int ele : s) cout<<ele<<" ";
//     // cout<<endl;
//     if(total%2==0){
//       int sum = total/2;
//       if(s.find(sum)!=s.end()) ans.push_back(i);
//     }
//     total+=arr[i];
//     s.insert(arr[i]);
//   }
//   cout<<ans.size()<<nline;
//   for(int ele : ans) cout<<ele+1<<" ";
//   cout<<nline;
// }

// Mahmoud and Ehab and the bipartiteness
// void dfs(int node,int par,vector<int> adj[],int col,int &a,int &b){
//   if(col&1) a++;
//   else b++;
//   for(int it : adj[node]){
//     if(it==par) continue;
//     dfs(it,node,adj,col+1,a,b);
//   }
// }
// void solve(){
//   int n;cin>>n;
//   vector<int> adj[n+1];
//   for(int i=1;i<n;i++){
//     int u,v;
//     cin>>u>>v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }
//   // cout<<"*"<<endl;
//   int a=0,b=0;
//   dfs(1,-1,adj,1,a,b);
//   int ans = a*b-n+1;
//   cout<<ans<<endl;
// }

// Average Sleep Time
// void solve(){
//   int n,k;
//   cin>>n>>k;
//   float arr[n];
//   for(int i=0;i<n;i++) cin>>arr[i];
//   int l=0,r=0;
//   double sz = 0,sum = 0,total = 0;
//   while(r<n){
//     sum+=arr[r];
//     if(r-l+1 == k){
//       total+=sum;
//       sz++;
//       sum-=arr[l];
//       l++;
//     }
//     r++;
//   }
//   // cout<<total<<endl;
//   double ans = total/sz;
//   cout<<fixed<<setprecision(10)<<ans<<nline;
// }

// Simple Strings
void solve(){
  string s;cin>>s;
  int n = s.length();
  int l = 0,r=0;
  while(r<n){
    if(s[l]!=s[r]){
      if(r-l+1<3) l=r;
      else{
        set<char> st;
        st.insert('a'),st.insert('b'),st.insert('c');
        st.erase(s[l]),st.erase(s[r]);
        char c = *st.begin();
        for(int i=l+1;i<r;i+=2) s[i] = c;
        l = r;
      }
    }
    r++;
  }
  if(r-l+1>2){
    set<char> st;
    st.insert('a'),st.insert('b'),st.insert('c');
    st.erase(s[l]),st.erase(s[r]);
    char c = *st.begin();
    for(int i=l+1;i<r;i+=2){
      s[i] = c;
    } 
  }
  cout<<s<<nline;
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