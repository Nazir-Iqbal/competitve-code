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
//     int n,a,b;
//     cin>>n>>a>>b;
//     string s;cin>>s;
//     int tt = 0;
//     int x = 0,y=0;
//     while(tt<100){
//         for(int i=0;i<n;i++){
//             if(s[i] == 'N') y++;
//             else if(s[i] == 'S') y--;
//             else if(s[i] == 'E') x++;
//             else x--;
//             if(x==a && y==b){
//                 cout<<"Yes"<<endl;
//                 return;
//             }
//         }
//         tt++;
//     }
//     cout<<"No"<<endl;
// }

// void solve(){
//     int n,b,c;
//     cin>>n>>b>>c;
//     if(n==1){
//         if(c==0) cout<<0<<endl;
//         else cout<<1<<endl;
//         return;
//     }
//     if(b==0){
//         if(c>=n) cout<<n<<endl;
//         else if(c>=n-2) cout<<n-1<<endl;
//         else cout<<-1<<endl;
//         return;
//     }
//     if(n-1<c){
//         cout<<n<<endl;
//         return;
//     }
//     int op = ((n-1-c)+b)/b;
//     cout<<n-op<<endl;
// }

// bool check(int x,int n,int m,vector<int> &prefix,vector<int> &suffix,vector<int> &total,int arr[]){
//     if(x == 0){
//         if(prefix[n]>=m) return true;
//         else return false;
//     }
//     for(int i=1;i<=n;i++){
//         int ind = lower_bound(total.begin(),total.end(),total[i-1]+x)-total.begin();
//         if(ind == n+1) break;
//         int partition = prefix[i-1] + suffix[ind+1];
//         if(partition>=m){
//             // cout<<i<<" "<<ind<<" "<<partition<<" "<<suffix[ind+1]<<endl;
//             return true;
//         }
//     }
//     return false;
// }

// void solve(){
//     int n,m,v;
//     cin>>n>>m>>v;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> prefix(n+1,0),suffix(n+2,0),total(n+1,0);
//     int sum = 0;
//     for(int i=1;i<=n;i++){
//         sum += arr[i-1];
//         total[i] = arr[i-1]+total[i-1];
//         prefix[i] = prefix[i-1];
//         if(sum >= v) prefix[i]++,sum = 0;
//     }
//     sum = 0;
//     for(int i=n;i>0;i--){
//         sum += arr[i-1];
//         suffix[i] = suffix[i+1];
//         if(sum>=v) suffix[i]++,sum = 0;
//     }
//     // cout<<check(2,n,m,prefix,suffix,total,arr)<<endl;
//     int lo = 0,hi = 1e18;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,n,m,prefix,suffix,total,arr)) lo = mid+1;
//         else hi = mid-1;
//     }
//     cout<<hi<<'\n';
// }

// Alice's Adventures in Cards
void solve(){
    int n;cin>>n;
    set<int> w1,w2,w3;
    vector<pair<int,int>> v1,v2,v3;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v1.push_back({x,i+1});
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v2.push_back({x,i+1});
    }
    for(int i=0;i<n;i++){
        int x;cin>>x;
        v3.push_back({x,i+1});
    }
    sort(v1.begin(),v1.end(),greater<pair<int,int>>());
    sort(v2.begin(),v2.end(),greater<pair<int,int>>());
    sort(v3.begin(),v3.end(),greater<pair<int,int>>());
    int ind1=0,ind2=0,ind3=0;
    // for(int i=0;i<n;i++) cout<<v1[i].first<<" "<<v1[i].second<<endl;
    bool f1 = true,f2 = true,f3 = true;
    for(int i=0;i<n;i++){
        if(v1[i].second==1) ind1 = i;
        if(v1[i].second==n){
            break;
        }
        w1.insert(v1[i].second);
    }
    for(int i=0;i<n;i++){
        if(v2[i].second==1) ind2 = i;
        if(v2[i].second==n){
            break;
        }
        w2.insert(v2[i].second);
    }
    for(int i=0;i<n;i++){
        if(v3[i].second==1) ind3 = i;
        if(v3[i].second==n){
            break;
        }
        w3.insert(v3[i].second);
    }
    cout<<ind1<<" "<<ind2<<" "<<ind3<<endl;
    for(int i=0;i<ind1;i++){
        int x = v1[i].second;
        if(w2.find(x)!=w2.end()){
            cout<<"Yes"<<endl;
            cout<<2<<endl;
            cout<<"q "<<x<<endl;
            cout<<"k "<<n<<endl;
            return;
        }
        if(w3.find(x)!=w3.end()){
            cout<<"Yes"<<endl;
            cout<<2<<endl;
            cout<<"q "<<x<<endl;
            cout<<"j "<<n<<endl;
            return;
        }
    }
    for(int i=0;i<ind2;i++){
        int x = v2[i].second;
        if(w1.find(x)!=w1.end()){
            cout<<"Yes"<<endl;
            cout<<2<<endl;
            cout<<"k "<<x<<endl;
            cout<<"q "<<n<<endl;
            return;
        }
        if(w3.find(x)!=w3.end()){
            cout<<"Yes"<<endl;
            cout<<2<<endl;
            cout<<"k "<<x<<endl;
            cout<<"j "<<n<<endl;
            return;
        }
    }
    for(int i=0;i<ind3;i++){
        int x = v3[i].second;
        if(w2.find(x)!=w2.end()){
            cout<<"Yes"<<endl;
            cout<<2<<endl;
            cout<<"j "<<x<<endl;
            cout<<"k "<<n<<endl;
            return;
        }
        if(w1.find(x)!=w1.end()){
            cout<<"Yes"<<endl;
            cout<<2<<endl;
            cout<<"j "<<x<<endl;
            cout<<"q "<<n<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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