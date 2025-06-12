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

bool find(int st,int n,int p[],int d[],int k){
    int ind = -1;
    for(int i=0;i<n;i++){
        if(st <= p[i]){
            ind = i;
            break;
        }
    }
    if(ind == -1) return true;
    // cout<<ind<<endl;
    map<int,int> mp;
    bool rev = false;
    bool first = true;
    int cur = -1;
    while(mp[cur]<3){
        if(!rev){
            bool flag = true;
            for(int i=ind;i<n;i++){
                int x = 0;
                if(first) x=abs(p[i]-st);
                else x = abs(p[i]-p[cur]);
                int len  = x;
                if(!first) len += st;
                if(d[i]>len) continue;
                if(abs(len-d[i])%k == 0){
                    // cout<<st<<" "<<cur<<" "<<len<<endl;
                    flag = false;
                    rev = true;
                    mp[i]++;
                    cur = i;
                    if(first) st = x;
                    else st += x;
                    ind = i-1;
                    break;
                }
            }
            if(flag) return true;
        }else{
            bool flag = true;
            for(int i=ind;i>=0;i--){
                int x = 0;
                if(first) x=abs(p[i]-st);
                else x = abs(p[i]-p[cur]);
                int len  = x + st;
                if(d[i]>len) continue;
                if(abs(len-d[i])%k == 0){
                    // cout<<st<<" "<<cur<<"*"<<len<<endl;
                    flag = false;
                    rev = false;
                    cur = i;
                    mp[i]++;
                    if(first) st = x;
                    else st += x;
                    ind = i+1;
                    break;
                }
            }
            if(flag) return false;
        }
        first = false;
    }
    return false;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> vis(n,0);
    int p[n],d[n];
    for(int i=0;i<n;i++) cin>>p[i];
    for(int j=0;j<n;j++) cin>>d[j];
    
    int q;cin>>q;
    map<int,bool> mp;
    for(int i=0;i<q;i++){
        int st;cin>>st;
        if(mp.find(st)==mp.end()){
            mp[st] = find(st,n,p,d,k);

        }
        // cout<<st<<" "<<mp[st]<<endl;
        (mp[st])?cout<<"Yes"<<endl:cout<<"No"<<endl;
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