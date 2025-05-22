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
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     int ans = a[n-1];
//     for(int i=0;i<n-1;i++){
//         int diff = a[i]-b[i+1];
//         if(diff>0) ans += diff;
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,a,b,c;
//     cin>>n>>a>>b>>c;
//     int arr[4] = {a,a+b,a+b+c};
//     int left = n%arr[2];
//     int ans = (n/arr[2])*3;
//     // cout<<ans<<" "<<left<<" "<<arr[2]<<endl;
//     for(int i=0;i<3;i++){
//         if(left == 0) break;
//         if(left <= arr[i]){
//             ans += i + 1;
//             break;
//         }
//     }
//     cout<<ans<<endl;
// }

// void print(vector<char> &v){
//     for(char &ele : v) cout<<ele;
//     cout<<endl;
// }

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     int a[m],q[k];
//     for(int i=0;i<m;i++) cin>>a[i];
//     for(int j=0;j<k;j++) cin>>q[j];
//     vector<char> ans(m,'1');
//     if(k==n){
//         print(ans);
//     }else if(k==n-1){
//         vector<bool> arr(n+1,0);
//         for(int i=0;i<k;i++) arr[q[i]] = 1;
//         int ind = 1;
//         for(int i=1;i<=n;i++){
//             if(!arr[i]) ind = i;
//         }
//         for(int i=0;i<m;i++){
//             if(a[i] != ind) ans[i] = '0';
//         }
//         print(ans);
//     }else{
//         for(int i=0;i<m;i++) ans[i] = '0';
//         print(ans);
//     }
// }

// Counting Pairs
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr.begin(),arr.end());
//     int sum = accumulate(arr.begin(),arr.end(),0ll);
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int l = lower_bound(arr.begin()+i+1,arr.end(),sum-(arr[i]+y)) - arr.begin();
//         int r = upper_bound(arr.begin()+i+1,arr.end(),sum-(arr[i]+x)) - arr.begin();
//         r--;
//         if(l>r) continue;
//         ans += (r-l+1);
//     }
//     cout<<ans<<endl;
// }

// Best Price
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> a(n),b(n);
//     set<int> st;
//     for(int i=0;i<n;i++) cin>>a[i],st.insert(a[i]);
//     for(int i=0;i<n;i++) cin>>b[i],st.insert(b[i]);
//     sort(a.begin(),a.end());
//     sort(b.begin(),b.end());
//     int ans = 0;
//     for(int cost : st){
//         int buy = n-(lower_bound(b.begin(),b.end(),cost) - b.begin());
//         int negative = lower_bound(a.begin(),a.end(),cost) - a.begin();
//         // p > a[i] in those for p>b[i]
//         negative -= lower_bound(b.begin(),b.end(),cost) - b.begin();
//         if(negative <= k){
//             ans = max(ans,buy*cost);
//         }
//     }
//     cout<<ans<<endl;
// }

// Joker
// void merge(vector<pair<int,int>> &vp){
//     sort(vp.begin(),vp.end());
//     int l=0,r=0;
//     vector<pair<int,int>> temp;
//     int n = vp.size();
//     for(int i=0;i<n;i++){
//         if(vp[i].first > r){
//             if(r!=0){
//                 temp.push_back({l,r});
//             }
//             l = vp[i].first,r = vp[i].second;
//         }else r = max(r,vp[i].second);
//         if(i==n-1) temp.push_back({l,r});
//     }
//     vp = temp;
// }

// void solve(){
//     int n,m,q;
//     cin>>n>>m>>q;
//     int a[q];
//     for(int i=0;i<q;i++) cin>>a[i];
//     int l = m,r = m;
//     vector<pair<int,int>> seg;
//     // base case
//     if(a[0] == m){
//         seg.push_back({1,1});
//         seg.push_back({n,n});
//     }else{
//         if(a[0] > m) seg.push_back({l,r+1});
//         else seg.push_back({l-1,r});
//     }
//     cout<<2<<" ";
//     for(int i=1;i<q;i++){
//         vector<pair<int,int>> temp;
//         for(int j=0;j<seg.size();j++){
//             l = seg[j].first, r = seg[j].second;
//             if(a[i] < l) temp.push_back({l-1,r});
//             else if(a[i] > r) temp.push_back({l,r+1});
//             else{
//                 temp.push_back({l,r});
//                 temp.push_back({1,1});
//                 temp.push_back({n,n});
//             }
//         }
//         merge(temp);
//         seg = temp;
//         int cnt = 0;
//         for(int i=0;i<seg.size();i++) cnt += (seg[i].second-seg[i].first + 1);
//         cout<<cnt<<" ";
//     }
//     cout<<endl;
// }

// Snakes
int n,q;
 
// int f(int mask,int last,vector<vector<int>> &cost,vector<vector<int>> &dp){
//     // base case
//     if(mask == (1<<n)-1){
//         return 0;
//     }

//     if(dp[mask][last] != -1) return dp[mask][last];
 
//     int ans = INT_MAX;
//     for(int i=0;i<n;i++){
//         if(!(mask&(1<<i))){
//             // cout<<last<<" "<<i+1<<endl;
//             int temp = f(mask|(1<<i),i+1,cost,dp) + cost[last][i+1];
//             ans = min(ans,temp);
//         }
//     }
//     // cout<<last<<" "<<ans<<endl;
//     return dp[mask][last] = ans;
// }
 
void solve(){
    cin>>n>>q;
    vector<pair<int,char>> vp;
    for(int i=0;i<q;i++){
        int num;char c;
        cin>>num>>c;
        vp.push_back({num,c});
    }
    vector<vector<int>> cost(n+1,vector<int>(n+1,0));
    // initialization of the cost
    for(int j=1;j<=n;j++){
        int cnt = 1;
        for(int k=0;k<q;k++){
            int num = vp[k].first;
            char c = vp[k].second;
            if(j == num && c == '+') cnt++;
        }
        cost[0][j] = cnt;
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            int l1 = 1,l2 = 2;
            int len1 = 0,len2 = 0;
            for(int k=0;k<q;k++){
                int num = vp[k].first;
                char c = vp[k].second;
                if(i == num){
                    if(c == '+'){
                        len1++;
                    }else{
                        l1++;
                        len1--;
                    }
                }else if(j == num){
                    if(c == '+'){
                        len2++;
                    }else{
                        l2++;
                        len2--;
                    }
                }
                if(l1 + len1 == l2) l2++; // collision
            }
            // cout<<i<<" "<<j<<" "<<l1<<" "<<len1<<" "<<l2<<" "<<len2<<endl;
            cost[i][j] = (l2+len2)-(l1+len1);
        }
    }
 
    if(n==1){
        cout<<cost[0][1]<<endl;
        return;
    }
    vector<vector<int>> dp((1<<n),vector<int>(n+1,INT_MAX));
    
    // int ans = f(0,0,cost,dp);
    for(int i=0;i<=n;i++) dp[(1<<n)-1][i] = 0;

    for(int mask=(1<<n)-2;mask>=0;mask--){
        for(int last=n;last>=0;last--){
            for(int i=0;i<n;i++){
                if(!(mask&(1<<i))){
                    // cout<<last<<" "<<i+1<<endl;
                    int temp = dp[mask|(1<<i)][i+1] + cost[last][i+1];
                    dp[mask][last] = min(dp[mask][last],temp);
                }
            }
        }
    }

    cout<<dp[0][0]<<endl;
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