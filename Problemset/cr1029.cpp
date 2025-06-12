#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n,x;
//     cin>>n>>x;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int l=-1,r=-1;
//     for(int i=0;i<n;i++){
//         if(arr[i] == 1){
//             if(l==-1) l=i;
//             r = i;
//         }
//     }
//     if(l==-1){
//         cout<<"Yes"<<endl;
//     }else{
//         int len = r-l+1;
//         if(len<=x) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> ans(n);
//     int cur = 1;
//     int l=0,r=n-1;
//     while(l<=r){
//         // cout<<l<<" "<<r<<endl;
//         if(l==r) ans[l] = cur;
//         else{
//             ans[l] = cur;
//             ans[r] = cur+1;
//         }
//         cur+=2;
//         l++,r--;
//     }
//     for(int &ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++) cin>>a[i];
//     map<int,int> mp;
//     for(int i=0;i<n;i++) mp[a[i]]++;
//     int ans = 0;
//     for(int i=n-1;i>=0;i--){
//         set<int> s;
//         map<int,int>mp1;
//         for(auto &ele : mp){
//             // cout<<i<<" "<<ele.first<<" "<<ele.second<<endl;
//             if(ele.second!=0){
//                 s.insert(ele.first);
//                 if(ele.second > 0 ){
//                     mp1[ele.first] = ele.second;
//                 }
//             }
//         }
//         mp = mp1;
//         // for(int ele : s) cout<<ele<<" ";
//         // cout<<endl;
//         while(i>=0 && s.size()!=0){
//             s.erase(a[i]);
//             mp[a[i]]--;
//             i--;
//         }
//         i++;
//         ans++;
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     int x = (n*(a[1]-a[0]) + a[0])/(n+1);
//     int y = (2*a[0]-a[1])/(n+1);
//     // cout<<x<<" "<<y<<endl;
//     if(x<0 || y<0){
//         cout<<"No"<<endl;
//         return;
//     }
//     for(int i=0;i<n;i++){
//         int num = (i+1)*x + (n-i)*y;
//         if(num != a[i]){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Lost Soul
void solve(){
    int n;cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<n;j++) cin>>b[j];
    set<int> s[2];
    set<int> s_alt[2];
    bool flag = 0;
    int ans = 0;
    for(int i=n-1;i>=0;i--){
        if(a[i] == b[i]){
            ans = i+1;
            break;
        }

        if(s[flag].find(b[i]) != s[flag].end() || s[!flag].find(a[i]) != s[!flag].end()){
            ans = i+1;
            break;
        }

        if(i<n-2){
            if(s_alt[flag].find(b[i]) != s_alt[flag].end() || s_alt[!flag].find(a[i]) != s_alt[!flag].end()){
                ans = i+1;
                break;
            }
        }
        s[flag].insert(a[i]);
        s[!flag].insert(b[i]);
        if(i<n-1){
            // cout<<a[i+1]<<endl;
            s_alt[flag].insert(a[i+1]);
            s_alt[!flag].insert(b[i+1]);
        }
        // for(int ele : s_alt[0]) cout<<ele<<" ";
        // cout<<endl;
        flag = !flag;
    }
    cout<<ans<<endl;
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