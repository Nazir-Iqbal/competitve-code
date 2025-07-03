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
//     int n,s;
//     cin>>n>>s;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int d1 = s-arr[0];
//     int d2 = arr[n-1]-s;
//     int ans = 0;
//     if(s>=arr[n-1]) ans = s-arr[0];
//     else if(s<=arr[0]) ans = arr[n-1]-s;
//     else ans = min(2*d1+d2,d1+2*d2);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int hsn[26] = {0};
//     hsn[s[0]-'a']++;
//     hsn[s[n-1]-'a']++;
//     for(int i=1;i<n-1;i++){
//         if(hsn[s[i]-'a'] > 0){
//             cout<<"Yes"<<endl;
//             return;
//         }
//         hsn[s[i]-'a']++;
//     }
//     cout<<"No"<<endl;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>> v(n,vector<int>(m));
//     int _max = INT_MIN;
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>v[i][j];
//             _max = max(_max,v[i][j]);
//         }
//     }
//     map<int,int> mp1,mp2;
//     map<pair<int,int> ,int> pos;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(_max == v[i][j]){
//                 mp1[i]++;
//                 mp2[j]++;
//                 pos[{i,j}]++;
//                 cnt++;
//             }
//         }
//     }
//     for(auto &ele1 : mp1){
//         for(auto &ele2 : mp2){
//             if(ele1.second + ele2.second - pos[{ele1.first,ele2.first}]>= cnt){
//                 // cout<<ele1.first<<" "<<ele1.second<<endl;
//                 // cout<<ele2.first<<" "<<ele2.second<<endl;
//                 cout<<_max-1<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<_max<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int j=0;j<n;j++) cin>>b[j];
//     vector<pair<int,int>> ans;
//     // finding the ith greatest element
//     set<int> s1,s2;
//     for(int it=0;it<n;it++){
//         int cur1 = INT_MIN,cur2 = INT_MIN;
//         int ind1 = -1,ind2 = -1;
//         for(int i=0;i<n;i++){
//             if(s1.find(a[i]) == s1.end()){
//                 if(cur1 < a[i]){
//                     ind1 = i;
//                     cur1 = a[i];
//                 }
//             }
//             if(s2.find(b[i]) == s2.end()){
//                 if(cur2 < b[i]){
//                     ind2 = i;
//                     cur2 = b[i];
//                 }
//             }
//         }
//         if(cur1 > cur2){
//             ans.push_back({3,ind1});
//             if(ind1 != ind2) ans.push_back({3,ind2});
//             swap(a[ind1],b[ind1]);
//             if(ind1 != ind2) swap(a[ind2],b[ind2]);
//             swap(ind1,ind2);
//             swap(cur1,cur2);
//             for(int i=0;i<n-it;i++){
//                 if(a[i] > cur1){
//                     cur1 = a[i];
//                     ind1 = i;
//                 }
//             }
//         }
//         s1.insert(cur1),s2.insert(cur2);
//         while(ind1 < n-1 && a[ind1] > a[ind1+1]){
//             ans.push_back({1,ind1});
//             swap(a[ind1],a[ind1+1]);
//             ind1++;
//         }
//         while(ind2 != (n-1-it)){
//             ans.push_back({2,ind2});
//             swap(b[ind2],b[ind2+1]);
//             ind2++;
//         }
//     }
//     cout<<ans.size()<<endl;
//     for(auto &ele : ans) cout<<ele.first<<" "<<ele.second+1<<endl;
// }

// void solve(){
//     int l,r;
//     cin>>l>>r;
//     int ans = 0;
//     vector<int> v1,v2;
//     while(l>0 || r>0){
//         int num1 = l%10;
//         int num2 = r%10;
//         v1.push_back(num1);
//         v2.push_back(num2);
//         l/=10;
//         r/=10;
//     }
//     reverse(v1.begin(),v1.end());
//     reverse(v2.begin(),v2.end());
    
//     int len = 0;
//     int n = v1.size();
//     for(int i=0;i<n;i++){
//         if(v1[i] == v2[i]) len++;
//         else break;
//     }
//     if(len == n) ans = 2*n;
//     else{
//         ans = 2*len;
//         int ind = len;
//         if(v2[ind]-v1[ind]==1){
//             ans++; // adding the one due to being equal either from l or r
//             int l1 = 0,l2 = 0;
//             for(int i=ind+1;i<n;i++){
//                 if(v1[i] == 9) l1++;
//                 else break;
//             }
//             for(int i=ind+1;i<n;i++){
//                 if(v2[i] == 0) l2++;
//                 else break;
//             }
//             int temp1 = l1,temp2 = l2;
//             if(l1+ind+1 < n){
//                 if(v1[l1+ind+1]==8 && v2[l1+ind+1]==9) temp1++;
//             }
//             if(l2+ind+1 < n){
//                 if(v2[l2+ind+1]==1 && v1[l2+ind+1]==0) temp2++;
//             }
//             // cout<<temp1<<" "<<temp2<<endl;
//             ans += min(temp1,temp2);
//         }
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,s,x;
//     cin>>n>>s>>x;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,vector<int>> mp;
//     int ans = 0, left = -1, sum = 0;
//     mp[0].push_back(-1);
//     // cout<<"*"<<endl;
//     for(int i=0;i<n;i++){
//         if(arr[i] > x){
//             mp.clear();
//             left = -1;
//             sum = 0;
//             mp[0].push_back(i);
//             // cout<<"*"<<endl;
//         }else{
//             sum += arr[i];
//             if(arr[i] == x) left = i;
//             int rem = sum-s;
//             mp[sum].push_back(i);
//             if(left == -1) continue;
//             int sz = mp[rem].size();
//             // cout<<sum<<" "<<rem<<" "<<ans<<" "<<left<<endl;
//             if(sz == 0) continue;
//             int ind = upper_bound(mp[rem].begin(),mp[rem].end(),left-1)-mp[rem].begin();
//             ans += ind;
//         }
//     }
//     cout<<ans<<endl;
// }

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += i*(n-i+1);
    }
    vector<int> prefix(n+1,0);
    for(int i=1;i<=n;i++){
        prefix[i] = prefix[i-1];
        if(s[i-1]=='0') prefix[i]--;
        else prefix[i]++;
    }
    sort(prefix.begin(),prefix.end());
    for(int i=0;i<=n;i++){
        ans += prefix[i]*(i-(n-i));
    }
    cout<<ans/2<<endl;
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