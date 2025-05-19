#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n,target;
//     cin>>n>>target;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,int> mp;
//     for(int i=0;i<n;i++) mp[arr[i]]++;
//     int ans = 0;
//     for(int i=0;i<n;i++) ans += mp[arr[i]+target], ans += mp[arr[i]-target];
//     cout<<ans/2<<endl;
// }


// void solve(){
//     int n,s0,k,b,m,a;
//     cin>>n>>s0>>k>>b>>m>>a;
//     vector<int> s(n);
//     s[0] = s0;
//     for(int i=1;i<n;i++) s[i] = ((k*s[i-1])%m+b)%m + 1 + s[i-1];
//     int cur = -1,ans = 0;
//     for(int i=n-1;i>=0;i--){
//         while(cur<n-1 && s[cur+1]*s[i]<=a) cur++;
//         ans += (cur+1);
//     }
//     cout<<ans<<endl;
// }

// E - Mod Sigma Problem
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> prefix(n+1,0);
//     for(int i=1;i<=n;i++) prefix[i] = (prefix[i-1]+arr[i-1])%m;
//     int sum = 0,ans = 0;
//     oset<int> os;
//     for(int i=1;i<=n;i++){
//         os.insert(prefix[i]);
//         int x = (i-os.order_of_key(prefix[i]+1));
//         ans += (i*prefix[i] - sum + x*m);
//         sum += prefix[i];
//     }
//     cout<<ans<<endl;
// }

// Make a Tree
// void dfs(int node,int par,int deg,vector<int> adj[],vector<int> &temp,vector<int> &degree,set<int> cont[]){
//     if(deg==degree[node]){
//         for(int &ele : adj[node]){
//             if(cont[node].find(ele)==cont[node].end() && temp[ele]==0){
//                 temp[ele] = node;
//                 cont[node].insert(ele);
//                 cont[ele].insert(node);
//                 degree[node]--,degree[ele]--;
//                 break;
//             }
//         }
//     }

//     for(int ele : adj[node]){
//         if(ele == par) continue;
//         dfs(ele,node,deg,adj,temp,degree,cont);
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> adj[n+1];
//     vector<int> degree(n+1,0);
//     for(int i=0;i<n-1;i++){
//         int u,v;cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         degree[u]++,degree[v]++;
//     }
//     set<int> con[n+1];
//     int mov = *max_element(degree.begin(),degree.end());
//     vector<vector<int>> ans;
//     for(int i=mov;i>0;i--){
//         vector<int> temp(n+1,0);
//         dfs(1,0,i,adj,temp,degree,con);
//         ans.push_back(temp);
//     }
//     cout<<mov<<endl;
//     for(int i=0;i<mov;i++){
//         for(int j=1;j<=n;j++){
//             if(ans[i][j] == 0) cout<<j<<" ";
//             else cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// void solve(){
//     int l,r,k;
//     cin>>l>>r>>k;
//     int r1 = r/k;
//     if(l>r1) cout<<0<<endl;
//     else cout<<r1-l+1<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string s1,s2;
//     cin>>s1>>s2;
//     int one = 0,zero = 0;
//     for(int i=0;i<n;i++) (s1[i]=='0')?zero++:one++;
//     for(int i=0;i<n-1;i++){
//         if(one>0 && zero>0){
//             (s2[i]=='0')?one--:zero--;
//         }else{
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// bool check(int k,int n,vector<int> &f,int arr[]){
//     int cur = k;
//     for(int i=n;i>0;i--){
//         if(f[i-1]>=cur) return true;
//         if(arr[i]>=cur) cur--;
//         else cur++;
//         // cout<<i<<" "<<f[i-1]<<" "<<cur<<endl;
//     }
//     return false;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     vector<int> f(n+1,0);
//     for(int i=1;i<=n;i++){
//         f[i] = f[i-1];
//         if(f[i]<arr[i]) f[i]++;
//         else if(f[i]>arr[i]) f[i]--;
//     }
//     for(int i=1;i<=n;i++) f[i] = max(f[i],f[i-1]);
//     // for(int i=1;i<=n;i++) cout<<f[i]<<" ";
//     // cout<<endl;
//     // cout<<check(4,n,f,arr)<<endl;
//     int lo = 0,hi = n+1;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(mid,n,f,arr)) lo = mid+1;
//         else hi = mid-1;
//     }
//     cout<<hi<<endl;
// }

// solving using the dp
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int prefix[n],dp[n],cur = 1;
//     prefix[0] = 1;
//     for(int i=1;i<n;i++){
//         if(arr[i]<cur) cur--;
//         else if(arr[i]>cur) cur++;
//         prefix[i] = max(prefix[i-1],cur);
//     }
//     dp[0] = 0;
//     for(int i=1;i<n;i++){
//         // if l,r range is taken before i
//         dp[i] = dp[i-1];
//         if(dp[i-1]>arr[i]) dp[i]--;
//         else if(dp[i-1]<arr[i]) dp[i]++;
//         //  if i is inside the range
//         dp[i] = max(dp[i],prefix[i-1]);
//     }
//     cout<<dp[n-1]<<endl;
// }

// Cool Graph
// const int N = 1e5+7;
// set<int> adj[N];

// void dfs(int node,int par,vector<int> &vis,set<int> &st,vector<vector<int>> &ans){
//     vis[node] = 1;
//     vector<int> child;
//     for(int ele : adj[node]){
//         if(ele == par) continue;
//         child.push_back(ele);
//     }

//     while(child.size()>=2){
//         int a = child.back();
//         int b = child[child.size()-2];
//         child.pop_back();
//         child.pop_back();
//         ans.push_back({node,a,b});

//         // removing the elements;
//         adj[node].erase(a);
//         adj[node].erase(b);
//         adj[a].erase(node);
//         adj[b].erase(node);

//         if(adj[a].find(b)==adj[a].end()){
//             adj[a].insert(b);
//             adj[b].insert(a);
//         }else{
//             adj[a].erase(b);
//             adj[b].erase(a);
//         }
//     }

//     if(child.size()==1){
//         dfs(child[0],node,vis,st,ans);
//     }else st.insert(node);
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=0;i<=n;i++) adj[i].clear();
//     for(int i=0;i<m;i++){
//         int u,v;cin>>u>>v;
//         adj[u].insert(v);
//         adj[v].insert(u);
//     }

//     vector<int> vis(n+1,0);
//     set<int> st; // for storing the last point of every node
//     vector<vector<int>> ans; // for storing the answer
//     for(int i=1;i<=n;i++){
//         if(!vis[i]) dfs(i,-1,vis,st,ans);
//     }

//     int a = -1;
//     for(int ele : st){
//         if(adj[ele].size()){
//             a = ele;
//             st.erase(ele);
//             break;
//         }
//     }

//     if(a!=-1){
//         int b = *adj[a].begin();
//         for(int ele : st){
//             ans.push_back({a,b,ele});
//             b = ele; // to avoid the formation of cycle
//         }
//     }
//     cout<<ans.size()<<endl;
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<3;j++) cout<<ans[i][j]<<" ";
//         cout<<endl;
//     }
// }

// Make a Tree
// const int N = 1e3+5;
// set<int> adj[N];

// void dfs(int node,int par,int deg,vector<int> &degree,vector<int> &vis,vector<int> &temp){
//     vis[node] = 1;
//     if(degree[node]==deg){
//         int ele = -1;
//         for(int it : adj[node]){
//             if(it != par && temp[it]==0){
//                 ele = it;
//                 break;
//             }
//         }

//         // applying the changes
//         if(ele!=-1){
//             degree[node]--,degree[ele]--;
//             adj[node].erase(ele);
//             adj[ele].erase(node);
//             // applying the color
//             temp[node] = node;
//             temp[ele] = node;
//         }
//     }
//     if(adj[node].size()){
//         for(int ele : adj[node]){
//             if(ele == par) continue;
//             dfs(ele,node,deg,degree,vis,temp);
//         }
//     }
// }

// void solve(){
//     int n;cin>>n;
//     for(int i=1;i<=n;i++) adj[i].clear();
//     vector<int> degree(n+1,0);
//     for(int i=0;i<n-1;i++){
//         int u,v;cin>>u>>v;
//         adj[u].insert(v);
//         adj[v].insert(u);
//         degree[u]++,degree[v]++;
//     }

//     int mov = *max_element(degree.begin(),degree.end());
//     vector<vector<int>> ans;

//     for(int i=mov;i>0;i--){
//         vector<int> vis(n+1,0),temp(n+1,0);
//         for(int j=1;j<=n;j++){
//             if(!vis[j]) dfs(j,-1,i,degree,vis,temp);
//         }
//         ans.push_back(temp);
//     }
//     cout<<mov<<endl;
//     for(int i=0;i<ans.size();i++){
//         for(int j=1;j<=n;j++){
//             if(ans[i][j] == 0) cout<<j<<" ";
//             else cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// E. Common Generator
// const int N = 4e5+1;
// vector<bool> prime(N,1);
// vector<int> spf(N,-1);

// void pre(){
//     prime[0]=prime[1]=0;
//     for(int i=2;i<N;i++){
//         if(prime[i]){
//             spf[i] = i;
//             for(int j=2*i;j<N;j+=i){
//                 if(spf[j]==-1) spf[j] = i;
//                 prime[j] = 0;
//             }
//         }
//     }
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     set<int> st;
//     for(int i=0;i<n;i++){
//         if(prime[arr[i]]) st.insert(arr[i]);
//     }
//     if(st.size()>1) cout<<-1<<endl;
//     else if(st.size()==0) cout<<2<<endl;
//     else{
//         int p = *st.begin();
//         for(int i=0;i<n;i++){
//             if(arr[i] == p || arr[i] == 2*p) continue;
//             if(arr[i]<p || (arr[i]<2*p && arr[i]>p)){
//                 cout<<-1<<endl;
//                 return;
//             }else{
//                 if(arr[i]%2==0) continue;
//                 else{
//                     int sp = spf[arr[i]];
//                     int num = (2*p)/sp;
//                     if(num*sp<2*p) num++;
//                     num *= sp;
//                     if(num&1) num+=sp; // first even occurence of multiple of sp greater than 2*p
//                     if(arr[i]<=num){
//                         // cout<<p<<" "<<arr[i]<<" "<<num<<endl;
//                         cout<<-1<<endl;
//                         return;
//                     }
//                 }
//             }
//         }
//         cout<<p<<endl;
//     }
// }

// Library of Magic
void solve(){
    int n;cin>>n;
	int xor3 = 0,xor2 = 0,a,b,c;
	cout<<"xor "<<1<<' '<<n<<endl;
	cin>>xor3;
	int l = 1,r = n;
	if(xor3!=0){
		while(l<=r){
			int mid = l + (r-l)/2;
			cout<<"xor "<<l<<' '<<mid<<endl;
			int x;cin>>x;
			if(x==0) l = mid+1;
			else if(x==xor3) r = mid;
			else{
				if (x <= mid) {
                    cout << "xor " << x << ' ' << x << endl;
                    int y;
                    cin >> y;
                    if (y == x) {
                        a=x;
                        xor2 = xor3 ^ x;
                        l = mid + 1;
                        break;
                    }
                }
                a=(xor3 ^ x);
                xor2 = x;
                r = mid;
                break;
			}
		}
	}else{
		for(int i=0;i<=60;i++){
			cout<<"xor "<<(1ll<<i)<<' '<<(1ll<<(i+1))-1<<endl;
			int x;cin>>x;
			if(x){
				a = x;
				l = x+1;
				xor2 = x;
				break;
			}
		}
	}
	while(l<=r){
		int mid = l + (r-l)/2;
		cout<<"xor "<<l<<' '<<mid<<endl;
		int x;cin>>x;
		if(x==0) l = mid+1;
		else if(x==xor2) r = mid;
		else{
			b = x;
			c = xor2^x;
			break;
		}
	}
	cout<<"ans "<<a<<' '<<b<<' '<<c<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }
    // solve();

    return 0;
}