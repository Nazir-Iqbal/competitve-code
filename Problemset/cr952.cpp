#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     string a,b;
//     cin>>a>>b;
//     swap(a[0],b[0]);
//     cout<<a<<" "<<b<<endl;
// }

// Maximum Multiple Sum
// int check(int i,int n){
//     int ans = 0;
//     int j=1;
//     while((i*j)<=n){
//         ans += (i*j);
//         j++;
//     }
//     // cout<<ans<<"*"<<endl;
//     return ans;
// }

// void solve(){
//     int n;cin>>n;
//     int ans = 0;
//     int ind=0;
//     for(int i=2;i<=n;i++){
//         int temp = check(i,n);
//         if(ans<=temp){
//             ans = temp;
//             ind = i;
//         }
//     }
//     cout<<ind<<endl;
// }

// Good Prefixes
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int prefix[n]={0};
//     int _max[n]={0};
//     prefix[0] = arr[0];
//     _max[0] = arr[0];
//     for(int i=1;i<n;i++) prefix[i] = prefix[i-1]+arr[i],_max[i] = max(_max[i-1],arr[i]);
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int sum = prefix[i],maxi = _max[i];
//         if(sum-maxi == maxi) ans++;
//     }
//     cout<<ans<<endl;
// }

// Manhattan Circle
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<char>> vv(n,vector<char>(m,0));
//     for(int i=0;i<n;i++){
//         string temp;cin>>temp;
//         for(int j=0;j<m;j++) vv[i][j] = temp[j];
//     }
//     pair<int,int> x,y;
//     // cout<<"*"<<endl;
//     x={0,0};
//     y={0,0};
//     for(int i=0;i<n;i++){
//         int l=-1,r=-1;
//         for(int j=0;j<m;j++){
//             if(vv[i][j] == '#'){
//                 if(l==-1) l = j;
//                 r=j;
//             }
//         }
//         if(l!=-1 && r-l+1>=(x.second-x.first+1)) x.first = l,x.second=r;
//     }
//     for(int j=0;j<m;j++){
//         int l=-1,r=-1;
//         for(int i=0;i<n;i++){
//             if(vv[i][j] == '#'){
//                 if(l==-1) l = i;
//                 r=i;
//             }
//         }
//         if(l!=-1 && r-l+1>=(y.second-y.first+1)) y.first = l,y.second=r;
//     }

//     // cout<<x.first<<" "<<x.second<<endl;
//     int ansx = (x.second+x.first)/2 , ansy = (y.second+y.first)/2;
//     cout<<ansy+1<<" "<<ansx+1<<endl;
// }

// Secret Box
// void solve(){
//     int x,y,z,k;
//     cin>>x>>y>>z>>k;
//     int ans = 0;
//     set<pair<pair<int,int>,int>> s;
//     for(int i=1;i<=x;i++){
//         if(k%i==0){
//             int num = k/i;
//             for(int j=1;j<=min(y,num);j++){
//                 if(num%j==0){
//                     int k = num/j;
//                     if(k<=z){
//                         int leftx = x-i+1;
//                         int lefty = y-j+1;
//                         int leftz = z-k+1;
//                         int temp = (leftx*lefty*leftz);
//                         ans = max(ans,temp);
//                         // s.insert({{tempv[0],tempv[1]},tempv[2]});
//                     }
//                 }
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// Final Boss

// Method 1 : using the priority queue
// void solve(){
//     int h,n;
//     cin>>h>>n;
//     // map<int,int> m;
//     int a[n],c[n];
//     priority_queue<pair<int,int>> pq;
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int j=0;j<n;j++) cin>>c[j];
//     // for(int i=0;i<n;i++) m[c[i]] += a[i];
//     for(int i=0;i<n;i++){
//         h-=a[i];
//         pq.push({-(c[i]+1),i});
//     }
//     if(h<=0){
//         cout<<1<<endl;
//         return;
//     }
//     int j;
//     while(h>0){
//         j = -pq.top().first;
//         int ind = pq.top().second;
//         pq.pop();
//         h-=a[ind];
//         // cout<<h<<" "<<ind<<" "<<j<<endl;
//         pq.push({-(j+c[ind]),ind});
//     }
//     cout<<j<<endl;
// }

// Method 2 : using the binary search
// bool check(int sum,int a[],int c[],int n,int day,int h){
// 	int damage = sum;
// 	for(int i=0;i<n;i++){
// 		damage +=(a[i])*((day-1ll)/c[i]);
// 		damage = min(damage,200001ll);
// 	}
// 	// cout<<day<<" "<<h<<" "<<damage<<" "<<sum<<endl;
// 	if(damage>=h) return true;
// 	return false;
// }

// void solve(){
// 	int h,n;
// 	cin>>h>>n;
// 	int a[n],c[n];
// 	int sum = 0;
// 	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
// 	for(int i=0;i<n;i++) cin>>c[i];
// 	int l = 1,r = 1e13;
// 	while(l<=r){
// 		int mid = (l+r)/2;
// 		if(check(sum,a,c,n,mid,h)) r = mid-1;
// 		else l = mid+1;
// 	}
// 	cout<<l<<nline;
// }

// D-Function
// int mod = 1e9+7;

// long long power(long long a, long long b){
//     long long result = 1;
//     while (b) {
//         if (b & 1)
//             result = (result * a) % mod;
//         a = (a * a) % mod;
//         b >>= 1;
//     }
//     return result;
// }

// void solve(){
// 	int l,r,k;
// 	cin>>l>>r>>k;
// 	int num = 9/k+1;
// 	int ans = (mod + (power(num,r) - power(num,l)))%mod;
// 	cout<<ans<<endl;
// }

// H1. Maximize the Largest Component (Easy Version)
int n,m;
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

void merge(int i,int j,DisjointSet &dsu,vector<vector<int>> &grid){
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    int node = i*m + j;
    for(int k=0;k<4;k++){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '#'){
            int it = nx*m + ny;
            // cout<<node<<" "<<nx<<" "<<ny<<" "<<it<<endl;
            dsu.unionBySize(node,it);
        }
    }
}

void solve(){
    cin>>n>>m;
    DisjointSet dsu(n*m);

    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++) grid[i][j] = s[j];
    }

    // merging all the conected components
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '#') merge(i,j,dsu,grid);
        }
    }

    // for(int i = 0;i<n*m;i++) cout<<i<<" "<<dsu.size[i]<<endl;

    int ans = 0;

    // checking for the size of the independent components
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int node = i*m+j;
            if(grid[i][j] == '#') ans = max(ans,dsu.size[node]);
        }
    }
    // cout<<ans<<endl;

    // applying operations on row
    for(int i=0;i<n;i++){
        int temp = 0;
        unordered_set<int> s;
        for(int j=0;j<m;j++){
            int node = i*m + j;
            if(grid[i][j] == '.'){
                temp++;
                vector<int> dx = {1,0,-1,0};
                vector<int> dy = {0,1,0,-1};
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '#'){
                        int it = nx*m + ny;
                        int par = dsu.findUPar(it);
                        if(s.find(par)==s.end()){
                            temp += dsu.size[par];
                            s.insert(par);
                        }
                    }
                }
                // cout<<i<<" "<<j<<" "<<temp<<endl;
            }else{
                int par = dsu.findUPar(node);
                if(s.find(par)==s.end()){
                    temp += dsu.size[par];
                    s.insert(par);
                }
            }
        }
        ans = max(ans,temp);
    }

    // applying operation for the columns
    for(int j=0;j<m;j++){
        int temp = 0;
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            int node = i*m + j;
            if(grid[i][j] == '.'){
                temp++;
                vector<int> dx = {1,0,-1,0};
                vector<int> dy = {0,1,0,-1};
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '#'){
                        int it = nx*m + ny;
                        int par = dsu.findUPar(it);
                        if(s.find(par)==s.end()){
                            temp += dsu.size[par];
                            s.insert(par);
                        }
                    }
                }
                // cout<<i<<" "<<j<<" "<<temp<<endl;
            }else{
                int par = dsu.findUPar(node);
                if(s.find(par)==s.end()){
                    temp += dsu.size[par];
                    s.insert(par);
                }
            }
        }
        ans = max(ans,temp);
    }

    cout<<ans<<nline;
}


int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // sieve();
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}