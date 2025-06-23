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
//     int n,k;
//     cin>>n>>k;
//     string s;
//     for(int i=0;i<k;i++) s.push_back('1');
//     for(int i=k;i<n;i++) s.push_back('0');
//     cout<<s<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     cout<<2*n-3<<endl;
//     for(int i=2;i<=n;i++){
//         cout<<i<<" "<<1<<" "<<i<<endl;
//     }
//     for(int i=1;i<n-1;i++){
//         cout<<i<<" "<<i+1<<" "<<n<<endl;
//     }
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int left = k,ans = 0;
//     for(int bit=0;bit<62;bit++){
//         int cst = (1ll<<bit);
//         for(int i=0;i<n;i++){
//             if(arr[i]&(1ll<<bit)) ans++;
//             else{
//                 if(left >= cst){
//                     left -= cst;
//                     ans++;
//                 }
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// Red Light, Green Light (Easy version)
bool find(int x,int p[],int d[],int k,int n){
    int ind = -1;
    for(int i=0;i<n;i++){
        if(x <=p[i]){
            ind = i;
            break;
        }
    }

    if(ind == -1) return true;

    // staring the simulation
    vector<int> vis(n,0);
    int t = 0;
    bool first = true,rev = false;
    while(true){
        if(!rev){
            // cout<<x<<" "<<t<<" "<<endl;
            bool flag = true;
            for(int i=ind;i<n;i++){
                int dis = abs(p[i]-x);
                int temp = t + dis;
                if(abs(temp-d[i])%k==0){
                    x = p[i];
                    vis[i]++;
                    t+=dis;
                    if(vis[i] > 2) return false;
                    ind = i-1;
                    flag = false;
                    rev = true;
                    break;
                }
            }
            if(flag) return true;
        }else{
            bool flag = true;
            for(int i=ind;i>=0;i--){
                int dis = abs(p[i]-x);
                int temp = t + dis;
                if(abs(temp-d[i])%k==0){
                    x = p[i];
                    vis[i]++;
                    t+=dis;
                    if(vis[i] > 2) return false;
                    ind = i+1;
                    flag = false;
                    rev = false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    return true;
}

void solve(){
    int n,k;
    cin>>n>>k;
    int p[n],d[n];
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++) cin>>d[i];
    map<int,bool> mp;
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(mp.find(x) == mp.end()) mp[x] = find(x,p,d,k,n);
        (mp[x])?cout<<"Yes"<<endl:cout<<"No"<<endl;
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