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
//     int x1,y1,x2,y2;
//     cin>>x1>>y1>>x2>>y2;
//     if((x1>y1 && x2<y2) || (x1<y1 && x2>y2)) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
    
// }

// Collatz Conjecture
// void solve(){
//     int x,y,k;
//     cin>>x>>y>>k;
//     x++,k--;
//     int req = (y-(x%y))%y;
//     while(k>=req){
//         x += req;
//         while(x%y==0) x /= y;
//         k-=req;
//         req = (y-(x%y))%y;
//         if(x == 1) break;
//         // cout<<x<<" "<<k<<' '<<req<<endl;
//     }
//     // cout<<x<<" "<<k<<' '<<req<<endl;
//     int ans = x + k;
//     if(x == 1){
//         ans -= k;
//         ans += (k%(y-1));
//     }
//     cout<<ans<<endl;

// }

// Boring Day
// method 1 : dp + binary search on  the prefix sum
// int search(vector<int> &pre,int l,int r,int cur){
//     int lo = 1,hi = cur;
//     int ans = -1;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         int req = pre[cur] - pre[mid-1];
//         if(req>=l && req<=r){
//             ans = mid;
//             lo = mid+1;
//         }
//         if(req>r) lo = mid+1;
//         else if(req<l) hi = mid-1;
//     }
//     return ans;
// }

// void solve(){
//     int n,l,r;
//     cin>>n>>l>>r;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> pre(n+1,0);
//     for(int i=1;i<=n;i++) pre[i] += pre[i-1] + arr[i-1];
//     vector<int> dp(n+1,0);
//     for(int i=1;i<=n;i++){
//         if(arr[i-1]>r) dp[i] = dp[i-1];
//         else{
//             int ind = search(pre,l,r,i);
//             // cout<<ind<<"*"<<i<<endl;
//             if(ind == -1) dp[i] = dp[i-1];
//             else dp[i] = max(dp[i-1],1+dp[ind-1]);
//         }
//     }
//     // for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
//     // cout<<endl;
//     cout<<dp[n]<<endl;
// }   

// method 2 : two pointers / sliding window
// void solve(){
//     int n,l,r;
//     cin>>n>>l>>r;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int lo=0,hi=0,sum=0,ans = 0;
//     while(hi<n){
//         sum += arr[hi];
//         while(sum>r && lo<=hi){
//             sum-=arr[lo];
//             lo++;
//         }
//         if(sum>=l && sum<=r){
//             ans++;
//             sum = 0;
//             lo = hi+1;
//         }
//         hi++;
//     }
//     cout<<ans<<endl;
// }

// Beauty of the mountains
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> range(n+1,vector<int>(m+1));
    vector<vector<char>> type(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>range[i][j];
    }
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=m;j++) type[i][j] = s[j-1];
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(type[i][j] == '0') x+=range[i][j];
            else y+=range[i][j];
        }
    }
    // cout<<x<<" "<<y<<endl;
    if(x==y){
        cout<<"Yes"<<endl;
        return;
    }

    // calculating the 2d prefix sum
    vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            prefix[i][j] = (type[i][j] - '0') + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
            // cout<<prefix[i][j]<<" ";
        }
        // cout<<endl;
    }
    // cout<<"*"<<endl;
    // diophantite equation
    int gcd = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int nx = i-k+1,ny = j-k+1;
            if(nx>0 && ny>0){
                int be = prefix[i][j] - (prefix[i][ny-1] + prefix[nx-1][j] - prefix[nx-1][ny-1]);
                int al = (k*k)-be;
                int diff = abs(x-y);
                int num = abs(al-be);
                // cout<<diff<<" "<<al<<" "<<be<<endl;
                if(num == 0) continue;
                gcd = __gcd(gcd,num);
                if(diff%gcd == 0){
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }

    cout<<"No"<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}