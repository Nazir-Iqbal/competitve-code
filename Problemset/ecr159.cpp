#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int one = 0,zero = 0;
//     for(int i=0;i<n;i++){
//         if(s[i] == '0') zero++;
//         else one++;
//     }
//     if(one==0) cout<<"Yes"<<endl;
//     else if(zero==0) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// Getting Points
// void solve(){
//     int n,p,l,t;
//     cin>>n>>p>>l>>t;
//     int prac= (n-1)/7 +1;
//     int points = (prac/2)*(2*t+l);

//     if(prac&1) points += (t+l);
//     // cout<<points<<" "<<prac<<endl;

//     int ans = 0;
//     if(p<=points){
//         ans += p/(2*t+l);
//         if(p%(2*t+l)!=0) ans += 1;
//     }else{
//         ans += prac/2;
//         if(prac&1) ans++;
//         p-=points;
//         ans += (p/l);
//         if(p%l!=0) ans+=1;
//     }
//     cout<<n-ans<<endl;
// }

// Insert and Equalize
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     set<int> s;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         s.insert(arr[i]);
//     }

//     // edge case
//     if(n==1){
//         cout<<1<<endl;
//         return;
//     }
    
//     // converting all the elements to the maximum element
//     int _max = *max_element(arr,arr+n);
//     int x = _max-arr[n-1];
//     for(int i=0;i<n-1;i++){
//         x = __gcd(x,abs(arr[i]-arr[i+1]));
//     }
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         ans += (abs(_max-arr[i])/x);
//     }
//     int k =-1;
//     int num = _max + (k*x);
//     while(s.find(num)!=s.end()){
//         k--;
//         num = _max + (k*x);
//     }
//     ans -= k;
//     cout<<ans<<'\n';
// }

// GCD and MST
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void solve(){
    int n,p;
    cin>>n>>p;
    int arr[n];
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        vp.push_back({arr[i],i});
    }
    
    DisjointSet dsu(n);
    sort(vp.begin(),vp.end());
    // for(auto ele : vp) cout<<ele.first<<" "<<ele.second<<endl;

    int ans = 0;
    for(auto v : vp){
        int ele = v.first;
        int ind = v.second;
        // cout<<ind<<" "<<arr[ind]<<endl;
        if(ele > p) break;
        // if(dsu.size[ind]>1) continue;

        // going to the left
        int j = ind-1;
        while(j!=-1 && ((arr[j]%arr[ind])==0)){
            // cout<<j<<" "<<ind<<endl;
            if(dsu.findUPar(j)==dsu.findUPar(ind)) break;
            if(dsu.size[j]>1){
                ans+= arr[ind];
                dsu.unionBySize(j,ind);
                break;
            }else{
                ans+= arr[ind];
                dsu.unionBySize(j,ind);
            }
            j--;
        }
        // going right
        j = ind+1;
        while(j!=n && ((arr[j]%arr[ind])==0)){
            if(dsu.findUPar(j)==dsu.findUPar(ind)) break;
            // cout<<j<<" "<<ind<<endl;
            if(dsu.size[j]>1){
                ans+= arr[ind];
                dsu.unionBySize(j,ind);
                break;
            }else{
                ans+= arr[ind];
                dsu.unionBySize(j,ind);
            }
            j++;
        }
    }
    
    // counting the no. of disconnected components
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(dsu.parent[i]==i) cnt++;
    }
    ans += (cnt-1)*p;
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