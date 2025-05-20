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

// void solve(int tt){
//     int n;cin>>n;
//     if(n%33==0) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Kevin and Permutation
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> ans(n,0);
//     int cur = 1;
//     for(int i=k-1;i<n;i+=k){
//         ans[i] = cur;
//         cur++;
//         if(i+k > n-1 && i!=n-1){
//             ans[n-1] = cur;
//             cur++;
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(ans[i] == 0){
//             ans[i] = cur;
//             cur++;
//         }
//     }
//     for(int &it : ans) cout<<it<<" ";
//     cout<<endl;
// }

// bool check(string &s1,string &s2){
//     for(int i=s1.size()-1;i>=0;i--){
//         if(s1[i] == '1' && s2[i] == '0') return true;
//         else if(s1[i]=='0' && s2[i] == '1') return false;
//     }
//     return false;
// }

// void solve(){
//     string s;cin>>s;
//     int n = s.size();
//     reverse(s.begin(),s.end());
//     string ans = "0";
//     int l = 0,r = 0;
//     for(int i=0;i<n;i++){
//         int prev = i;
//         string temp = s;
//         for(int j=i;j<n;j++){
//             if(temp[j-i]=='0' && temp[j] == '1'){
//                 // cout<<i<<" "<<j<<endl;
//                 while(prev<=j){
//                     if(temp[prev]=='1'){
//                         if(temp[prev-i]=='0') temp[prev-i] = '1';
//                         else temp[prev-i] = '0';
//                     }
//                     prev++;
//                 }
//             }
//         }
//         if(prev == i) continue;
//         if(ans == "0" || check(temp,ans)){
//             ans = temp;
//             l = i,r = prev-1;
//         }
//     }
//     // cout<<ans<<endl;
//     cout<<1<<" "<<n<<" "<<(n-r)<<" "<<(n-l)<<endl;
// }

// Kevin and Competition Memories
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> a(n),b(m);
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<m;i++) cin>>b[i];
//     int ind=-1,rating=a[0];
//     sort(a.begin(),a.end(),greater<int>());
//     for(int i=0;i<n;i++){
//         if(rating==a[i]) break;
//         ind = i;
//     }
//     int point = 0;
//     for(int i=0;i<m;i++){
//         if(b[i] <= rating) b[i] = 1e9+7;
//     }
//     sort(b.begin(),b.end(),greater<int>());
//     vector<int> c(m,0);
//     int cur = 0,l=0,r=0;
//     while(l<=ind && r<m){
//         if(a[l] >= b[r]) cur++,l++;
//         else{
//             c[r] = cur;
//             r++; // easy problem
//         }
//     }
//     while(r<m) c[r] = cur,r++;
//     sort(c.begin(),c.end());
//     // for(int ele : c) cout<<ele<<" ";
//     // cout<<endl;
//     vector<int> ans;
//     for(int k=1;k<=m;k++){
//         int sum = 0;
//         for(int rank=k-1;rank<m;rank+=k){
//             sum += c[rank]+1;
//             // cout<<k<<" "<<c[rank]+1<<endl;
//         }
//         ans.push_back(sum);
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Kevin and Bipartite Graph
void solve(){
    int n,m;
    cin>>n>>m;
    if(m>=2*n){
        cout<<"No"<<endl;
        return;
    }
    vector<int> sample(2*n,0);
    int cur = 1;
    for(int i=0;i<2*n;i+=2){
        sample[i] = cur;
        sample[i+1] = cur;
        cur++;
    }
    int st = 0;
    vector<vector<int>> ans(2*n,vector<int>(m));
    for(int j=0;j<m;j++){
        for(int i=0;i<2*n;i++){
            ans[i][j] = sample[(i+st)%(2*n)];
        }
        st++;
    }
    cout<<"Yes"<<endl;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<m;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
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