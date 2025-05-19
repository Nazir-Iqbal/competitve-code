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
//     vector<int> v(3);
//     for(int i=0;i<3;i++) cin>>v[i];
//     for(int i=0;i<5;i++){
//         sort(v.begin(),v.end());
//         v[0]++;
//     }
//     int ans = 1;
//     for(int i=0;i<3;i++) ans *= v[i];
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[k];
//     for(int i=0;i<k;i++) cin>>arr[i];
//     int ind = max_element(arr,arr+k)-arr;
//     int ans = 0;
//     for(int i=0;i<k;i++){
//         if(i==ind) continue;
//         ans += (arr[i]-1);
//     }
//     ans += (n - arr[ind]);
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<int> ans;
//     for(int i=n;i>m;i--) ans.push_back(i);
//     for(int i=1;i<=m;i++) ans.push_back(i);
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     string s;
//     cin>>s;
//     reverse(s.begin(),s.end());
//     s.push_back('L');
//     reverse(s.begin(),s.end());
//     s.push_back('L');
//     // cout<<s<<endl;
//     vector<int> dp(n+2,1e9);
//     dp[n+1] = 0;
//     for(int i=n;i>=0;i--){
//         if(s[i] == 'L'){
//             for(int j=1;j<=m;j++){
//                 // cout<<i+j<<endl;
//                 if(i+j>n+1) break;
//                 if(s[i+j] != 'C') dp[i] = min(dp[i],dp[i+j]); 
//             }
//         }else if(s[i] != 'C') dp[i] = dp[i+1]+1;
//     }

//     // for(int i=0;i<=n+1;i++) cout<<dp[i]<<" ";
//     // cout<<endl;

//     if(dp[0]>k) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// Novice's Mistake
// int cnt1 = 0;
// int find(int n,int a){
//     int len1 = 0;
//     while(n) n/=10,len1++;
//     len1 *= a;
//     // cnt1++;
//     return len1;
// }

// int find2(int len,int n){
//     int ans = 0;
//     string num = to_string(n);
//     int sz = num.size();
//     int cnt = 1;
//     for(int i=len-1;i>=0;i--){
//         ans += (cnt * (num[i%sz]-'0'));
//         // cout<<ans<<endl;
//         cnt*=10;
//     }
//     return ans;
// }

// void solve(){
//     int n;cin>>n;
//     vector<pair<int,int>> vp;
//     // cout<<find2(4,45)<<endl;
//     // cout<<find(13,5)<<endl;
//     for(int i=1;i<=10000;i++){
//         int len = find(n,i);
//         for(int j = max(len-7ll,1ll);j<len;j++){
//             // cout<<i<<" "<<j<<endl;
//             int num1 = i*n - j; // mathematical expression
//             int num2 = find2(len-j,n);
//             if(num1 == num2){
//                 // cout<<num1<<"*"<<num2<<" "<<len<<" "<<j<<endl;
//                 vp.push_back({i,j});
//             }
//         }
//     }
//     cout<<vp.size()<<endl;
//     for(auto &ele : vp) cout<<ele.first<<" "<<ele.second<<endl;
//     // cout<<cnt1<<endl;
// }

// Valuable Cards
// int t = 1;
void solve(){
    int n,x;cin>>n>>x;
    int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 1;
    set<int> st;
    st.insert(1);
    for(int i=0;i<n;i++){
        if(arr[i] == 1) continue;
        if(x%arr[i]==0){
            int num = x/arr[i];
            if(st.find(num) == st.end()){
                vector<int> temp;
                for(int ele : st){
                    int num = ele*arr[i];
                    if(num>x) break;
                    temp.push_back(num);
                }
                for(int i=0;i<temp.size();i++) st.insert(temp[i]);
                // for(int ele : st) cout<<ele<<" ";
                // cout<<endl;
            }else{
                ans++;
                st.clear();
                st.insert(1);
                st.insert(arr[i]);
            }
        }
    }

    cout<<ans<<endl;
    // t++;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;

	// prime();

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}