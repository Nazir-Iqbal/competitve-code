#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> f;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             f.push_back(i);
//             if(n/i!=i) f.push_back(n/i);
//         }
//     }
//     int ans = 0;
//     for(int i=0;i<f.size();i++){
//         int num = f[i];
//         // if(num==n) continue;
//         vector<int> d;
//         for(int j=0;j<num;j++){
//             vector<int> diff;
//             int prev = arr[j];
//             for(int k=j;k<n;k+=num){
//                 diff.push_back(abs(prev-arr[k]));
//                 prev = arr[k];
//             }
//             int gcd = 0;
//             for(int k=0;k<diff.size();k++) gcd = __gcd(gcd,diff[k]);
//             // if(num==3) cout<<gcd<<nline;
//             d.push_back(gcd);
//         }
//         int gcd = 0;
//         for(int &ele : d) gcd = __gcd(gcd,ele);
//         if(gcd!=1) ans++;
//     }
//     cout<<ans<<nline;
// }

// Good Triples
// void solve(){
//     int n;cin>>n;
//     int ans=1;
//     while(n){
//         int num = n%10;
//         n/=10;
//         int calc = 0;
//         for(int i=0;i<=num;i++){
//             for(int j=0;j<=num;j++){
//                 if(num-i-j>=0)calc++;
//             }
//         }
//         ans*=calc;
//     }
//     cout<<ans<<nline;
// }

// Decreasing String
// void solve(){
//     string s;cin>>s;
//     int n;cin>>n;
//     int len = s.length();
//     int cnt = 0;
//     int num = len-1;
//     while(len<n){
//         len+=num;
//         num--;
//         cnt++;
//     }
//     len = s.length();
//     num++;
//     while(n>num){
//         n-=len;
//         len--;
//     }
//     int pos = n-1;
//     // implementing the deleting characters in O(n) using stack
//     stack<char> st;
//     len = s.length();
//     for(int i=0;i<len;i++){
//         while(!st.empty() && st.top()>s[i] && cnt>0){
//             st.pop();
//             cnt--;
//         }
//         st.push(s[i]);
//     }
//     while(cnt>0) st.pop(),cnt--;
//     string temp;
//     while(!st.empty()) temp.push_back(st.top()),st.pop();
//     reverse(temp.begin(),temp.end());
//     // cout<<temp<<endl;
//     cout<<temp[pos];
// }

// To Become Max
// bool isPossible(int arr[],int n,int k,int mid){
//     for(int i=0;i<n;i++){
//         if(arr[i]>=mid) return true;
//         int moves = mid-arr[i],cnt = 1;
//         for(int j=i+1;j<n;j++){
//             if(arr[j]>=mid-cnt){
//                 if(moves<=k) return true;
//                 break;
//             }
//             moves+=mid-cnt-arr[j];
//             cnt++;
//         }
//     }
//     return false;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     int ans = 0;
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int _max = *max_element(arr,arr+n);
//     // applying the binary search on answer
//     int lo = _max,hi = _max+k;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(isPossible(arr,n,k,mid)) lo = mid+1;
//         else hi = mid-1; 
//     }
//     cout<<hi<<endl;
// }

// Tracking Segments
// bool isPossible(int ind,int n,vector<pair<int,int>> &seg,vector<int> ch){
//     vector<int> pre(n+1,0);
//     for(int i=0;i<ind;i++) pre[ch[i]] = 1;
//     for(int i=1;i<=n;i++) pre[i] += pre[i-1];
//     for(int i=0;i<seg.size();i++){
//         int l = seg[i].first, r = seg[i].second;
//         int o = pre[r]-pre[l-1], z = r-l+1-o;
//         if(o>z) return true;
//     }
//     return false;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<pair<int,int>> seg;
//     for(int i=0;i<m;i++){
//         int l,r;
//         cin>>l>>r;
//         seg.push_back({l,r});
//     }
//     int q;cin>>q;
//     int copy = q;
//     vector<int> ch;
//     while(copy--){
//         int x;cin>>x;
//         ch.push_back(x);
//     }
//     int lo = 1,hi=q;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(isPossible(mid,n,seg,ch)) hi = mid-1;
//         else lo = mid+1;
//     }
//     if(lo>q){
//         cout<<-1<<endl;
//     }else cout<<lo<<endl;
// }

//  Round Dance
// class DisjointSet {
// public:
//     vector<int> parent, size;
//     DisjointSet(int n) {
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };

// void solve(){
//     int n;cin>>n;
//     DisjointSet dsu(n);
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     set<pair<int,int>> edges;
//     for(int i=1;i<=n;i++){
//         // to avoid the multi-edges
//         int u=i,v=arr[i];
//         edges.insert({min(u,v),max(u,v)});
//     }
//     int total = 0,cycle = 0;
//     for(auto &ele : edges){
//         int u = ele.first,v = ele.second;
//         if(dsu.findUPar(u) == dsu.findUPar(v)) cycle++;
//         else dsu.unionBySize(u,v);
//     }
//     for(int i=1;i<=n;i++) if(dsu.parent[i] == i) total++;
//     cout<<min(cycle+1,total)<<" "<<total<<endl;
// }

// Hits Different
// vector<int> ans(1000001,0);
// void pre(){
//     int cur = 1;
//     vector<vector<int>> v(1500,vector<int>(1500,0));
//     for(int i=1;i<1500;i++){
//         if(cur>1e6) break;
//         for(int j=0;j<i;j++){
//             if(cur>1e6) break;
//             v[i-j][j+1] = v[i-j-1][j+1] + v[i-j][j] - v[i-j-1][j] + cur*cur;
//             // cout<<i-j<<" "<<j+1<<" "<<cur<<" "<<v[i-j][j+1]<<endl;
//             ans[cur] = v[i-j][j+1];
//             cur++;
//         }
//     }
// }

// void solve(){
//     int n;cin>>n;
//     cout<<ans[n]<<endl;
// }

// Shocking Arrangement
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
// 	if(n==1){
// 		cout<<"No"<<endl;
// 		return;
// 	}
// 	int cnt = 0,sum = 0;
// 	vector<int> pos,neg;
// 	for(int i=0;i<n;i++){
// 		if(arr[i] == 0) cnt++;
// 		else if(arr[i]<0) neg.push_back(arr[i]);
// 		else pos.push_back(arr[i]);
// 	}
// 	if(cnt==n){
// 		cout<<"No"<<endl;
// 		return;
// 	}
// 	vector<int> ans;
// 	while(cnt--) ans.push_back(0);
// 	int l = 0,r = 0;
// 	while(l<neg.size() && r<pos.size()){
// 		if(sum<=0) ans.push_back(pos[r]),sum+=pos[r],r++;
// 		else ans.push_back(neg[l]),sum+=neg[l],l++;
// 	}
// 	while(l<neg.size()) ans.push_back(neg[l]),l++;
// 	while(r<pos.size()) ans.push_back(pos[r]),r++;
// 	cout<<"Yes"<<endl;
// 	for(int ele : ans) cout<<ele<<" ";
// 	cout<<endl;
// }

// Triangle Coloring
// const int mod = 998244353;
 
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

// int ncr(int n,int r){
// 	int num1=1,num2 = 1;
// 	for(int i=1;i<=n;i++) num1 = (num1*i)%mod;
// 	for(int i=1;i<=r;i++) num2 = (num2*i)%mod;
// 	int num3 = (num2*num2)%mod;
// 	// cout<<num1<<" "<<num3<<endl;
// 	int ans = (num1*power(num3,mod-2))%mod;
// 	return ans;
// }

// void solve(){
// 	int n;cin>>n;
// 	// no.s of ways of choosing the color
// 	int ways = ncr(n/3,n/6);
// 	// cout<<ways<<endl;
// 	int per = 1;
// 	for(int i=0;i<n/3;i++){
// 		vector<int> arr(3);
// 		for(int j=0;j<3;j++) cin>>arr[j];
// 		int mn = *min_element(arr.begin(),arr.end());
// 		int cnt = count(arr.begin(),arr.end(),mn);
// 		// cout<<mn<<" "<<cnt<<endl;
// 		per = (cnt*per)%mod;
// 	}
// 	int ans = (per*ways)%mod;
// 	cout<<ans<<endl;
// }

// Equal Frequencies
// bool cmp(pair<int,char> x,pair<int,char> y){
// 	if(x.first==y.first) return x.second<y.second;
// 	return x.first>y.first;
// }

// void solve(int t,int tt){
// 	int n;cin>>n;
// 	string s;cin>>s;
// 	vector<int> f;
// 	// we fixed the no. of k to take
// 	for(int i=1;i<=26;i++){
// 		if(n%i==0) f.push_back(i);
// 	}
// 	int hsn[26] = {0};
// 	for(int i=0;i<n;i++) hsn[s[i]-'a']++;
// 	vector<pair<int,char>> v;
// 	for(int i=0;i<26;i++){
// 		v.push_back({hsn[i],(char)('a'+i)});
// 	}
// 	sort(v.begin(),v.end(),cmp);
// 	// for(auto ele : v) cout<<ele.first<<" "<<ele.second<<endl;
// 	int match=0;
// 	string ans;
// 	for(int j=0;j<f.size();j++){
// 		int num = f[j];
// 		int freq = n/num;
// 		int temp_hsn[26];
// 		for(int i=0;i<26;i++) temp_hsn[i] = hsn[i];
// 		// cout<<num<<" "<<freq<<endl;
// 		set<char> st;
// 		for(int i=0;i<num;i++) st.insert(v[i].second);
// 		// for(char ele : st) cout<<num<<" "<<ele<<endl;
// 		string temp;
// 		for(int i=0;i<n;i++){
// 			if(st.find(s[i])==st.end()){
// 				for(char ele : st){
// 					if(temp_hsn[ele-'a']<freq){
// 						temp_hsn[ele-'a']++;
// 						temp.push_back(ele);
// 						break;
// 					}
// 				}
// 			}else{
// 				if(temp_hsn[s[i]-'a']>freq){
// 					for(char ele : st){
// 						if(temp_hsn[ele-'a']<freq){
// 							temp_hsn[ele-'a']++;
// 							temp_hsn[s[i]-'a']--;
// 							temp.push_back(ele);
// 							break;
// 						}
// 					}
// 				}else temp.push_back(s[i]);
// 			}
// 		}
// 		int temp_match = 0;
// 		for(int i=0;i<n;i++) if(s[i] == temp[i]) temp_match++;
// 		if(temp_match>match){
// 			match = temp_match;
// 			ans = temp;
// 		}
// 		// cout<<temp<<endl;
// 	}
// 	cout<<n-match<<endl;
// 	cout<<ans<<endl;
// }

// Flexible String
// void com(vector<set<char>> &v,vector<char> &dis,int k,int ind,set<char> &temp){
// 	// base conditions
// 	if(temp.size()==k){
// 		v.push_back(temp);
// 		return;
// 	}
// 	if(ind >= dis.size()) return;
// 	// taking the element at index ind;
// 	temp.insert(dis[ind]);
// 	com(v,dis,k,ind+1,temp);
// 	temp.erase(dis[ind]);
// 	// not taking
// 	com(v,dis,k,ind+1,temp);
// }

// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	string a,b;
// 	cin>>a>>b;
// 	set<char> st;
// 	for(int i=0;i<n;i++) st.insert(a[i]);
// 	vector<char> dis;
// 	for(char ele : st) dis.push_back(ele);
// 	k = min(k,(int)dis.size());
// 	vector<set<char>> vv;
// 	set<char> temp;
// 	com(vv,dis,k,0,temp);
// 	int ans = 0;
// 	for(int i=0;i<vv.size();i++){
// 		int len = 0,local = 0;
// 		for(int j=0;j<n;j++){
// 			if(a[j] == b[j] || vv[i].count(a[j])) len++;
// 			else{
// 				local += (len*(len+1))/2;
// 				len = 0;
// 			}
// 		}
// 		local += (len*(len+1))/2;
// 		ans = max(ans,local);
// 	}
// 	cout<<ans<<nline;
// }

// Interesting Sequence
// int calc(int a,int b){
// 	int ind = -1;
// 	for(int i=62;i>=0;i--){
// 		if(((1ll<<i)&a) != ((1ll<<i)&b)){
// 			ind = i;
// 			break;
// 		}
// 	}
// 	int ans = 0;
// 	for(int i=61;i>ind;i--){
// 		if((1ll<<i)&a) ans += (1ll<<i);
// 	}
// 	// cout<<a<<" "<<b<<" "<<ind<<" "<<ans<<endl;
// 	return ans;
// }

// void solve(){
// 	int n,x;
// 	cin>>n>>x;
// 	if(n&x!=x){
// 		cout<<-1<<endl;
// 		return;
// 	}
// 	int lo = n , hi = 2e18;
// 	int ans=-1;
// 	// calc(20,24);
// 	while(lo<=hi){
// 		int mid = (lo+hi)/2;
// 		int num = calc(n,mid);
// 		// cout<<lo<<" "<<hi<<endl;
// 		if(num<x) hi = mid-1;
// 		else if(num>x) lo = mid+1;
// 		else{
// 			ans = mid;
// 			hi = mid-1;
// 		}
// 	}
// 	cout<<ans<<endl;
// }

// Sending a Sequence Over the Network
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	bool dp[n+1] = {0};
// 	dp[0] = 1;
// 	for(int i=1;i<=n;i++){
// 		// checking for the left
// 		if(i-arr[i-1]>=1){
// 			dp[i] |= dp[i-arr[i-1]-1];
// 		}
// 		//  checking for the right
// 		if(i+arr[i-1]<=n){
// 			dp[i+arr[i-1]] |= dp[i-1];
// 		}
// 	}
// 	if(dp[n]) cout<<"Yes"<<endl;
// 	else cout<<"No"<<endl;
// }

// Meeting on the Line
// double check(double mid,double x[], double y[], int n){
// 	double dis = 0;
// 	for(int i=0;i<n;i++) dis = max(dis,abs(mid-x[i]) + y[i]);
// 	// cout<<dis<<endl;
// 	return dis;
// }

// void solve(){
// 	int n;cin>>n;
// 	double x[n],t[n];
// 	for(int i=0;i<n;i++) cin>>x[i];
// 	for(int i=0;i<n;i++) cin>>t[i];
// 	double ans = 0;
// 	double lo = 0,hi = 1e8;
// 	double diff = 0.0000001;
// 	while(hi-lo>=diff){
// 		double mid = (lo+hi)/2;
// 		// cout<<lo<<" "<<hi<<" "<<mid<<endl;
// 		if(check(mid-diff,x,t,n)>=check(mid,x,t,n)){
// 			ans = mid;
// 			lo = mid+diff;
// 		}else hi = mid-diff;
// 	}
// 	cout<<fixed<<setprecision(6)<<ans<<endl;
// }

// Split Into Two Sets
// checking for bipartite
// bool dfs(int node,vector<int> adj[],vector<int> &vis,int col){
// 	vis[node] = col;
// 	col = !col;
// 	// cout<<node<<" "<<col<<endl;
// 	for(int ele : adj[node]){
// 		if(vis[ele] == -1){
// 			if(!dfs(ele,adj,vis,col)) return false;
// 		}else if(vis[ele] != col) return false;
// 	}
// 	return true;
// }

// void solve(){
// 	int n;cin>>n;
// 	vector<int> adj[n+1];
// 	bool flag = false;
// 	for(int i=0;i<n;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[v].push_back(u);
// 		adj[u].push_back(v);
// 		if(u==v || adj[u].size()>2 || adj[v].size()>2) flag = true;
// 	}
// 	if(flag){
// 		cout<<"NO"<<endl;
// 		return;
// 	}
// 	vector<int> vis(n+1,-1);
// 	for(int i=1;i<=n;i++){
// 		if(vis[i] == -1){
// 			if(!dfs(i,adj,vis,0)){
// 				cout<<"NO"<<endl;
// 				return;
// 			}
// 		}
// 	}
// 	cout<<"YES"<<endl;
// }


// Fixed Point Guessing
// void query(int l,int r,int &ans){
// 	if(l==r){
// 		cout<<"? "<<l<<" "<<r<<endl;
// 		int x;cin>>x;
// 		ans = x;
// 		return;
// 	}
// 	int mid = (l+r)/2;
// 	cout<<"? "<<l<<" "<<mid<<endl;
// 	cout<<flush;
// 	int cnt = 0;
// 	for(int i=l;i<=mid;i++){
// 		int x;cin>>x;
// 		if(x>=l && x<=mid) cnt++;
// 	}

// 	if(cnt&1) query(l,mid,ans);
// 	else query(mid+1,r,ans);

// }

// void solve(){
// 	int n;cin>>n;
// 	int ans;
// 	query(1,n,ans);
// 	cout<<"! "<<ans<<endl;
// 	cout<<flush;
// }

// Maximum Product Strikes Back
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	vector<pair<int,int>> vp;
// 	int prev = -1;
// 	for(int i=0;i<n;i++){
// 		if(arr[i] == 0){
// 			if(prev+1<i){
// 				vp.push_back({prev+1,i-1});
// 			}
// 			prev = i;
// 		}
// 	}
// 	if(arr[n-1]!=0) vp.push_back({prev+1,n-1});
// 	// for(auto ele : vp) cout<<ele.first<<" "<<ele.second<<endl;
// 	pair<int,int> ans = {0,n};
// 	int two = 0;
// 	for(int i=0;i<vp.size();i++){
// 		int l = vp[i].first, r = vp[i].second;
// 		int neg = 0,cnt = 0;
// 		for(int j=l;j<=r;j++){
// 			if(arr[j]%2==0) cnt++;
// 			if(arr[j]<0) neg++;
// 		}
// 		if(neg%2==0){
// 			if(cnt>two){
// 				two = cnt;
// 				ans.first = l;
// 				ans.second = n-1-r;
// 			}
// 		}else{
// 			// taking from the left side
// 			int cnt1=0,cnt2=0,ind1=0,ind2=0;
// 			for(int j=l;j<=r;j++){
// 				if(arr[j]%2==0) cnt1++;
// 				if(arr[j]<0){
// 					ind1 = j+1;
// 					break;
// 				}
// 			}
// 			for(int j=r;j>=l;j--){
// 				if(arr[j]%2==0) cnt2++;
// 				if(arr[j]<0){
// 					ind2 = j-1;
// 					break;
// 				}
// 			}
// 			// cout<<cnt-cnt1<<" "<<cnt-cnt2<<endl;
// 			if(cnt1>=cnt2){
// 				if(cnt-cnt2>two){
// 					two = cnt-cnt2;
// 					ans.first = l;
// 					ans.second = n-1-ind2;
// 				}
// 			}else{
// 				if(cnt-cnt1>two){
// 					two = cnt-cnt1;
// 					ans.first = ind1;
// 					ans.second = n-1-r;
// 				}
// 			}
// 		}
// 	}
// 	cout<<ans.first<<" "<<ans.second<<endl;
// }

// Make Them Equal
// int dp[1001];
// void pre(){
// 	for(int i=0;i<=1000;i++) dp[i] = INT_MAX;
// 	dp[1] = 0;
// 	for(int i=1;i<=1000;i++){
// 		for(int j=1;j<=i;j++){
// 			if(i+i/j>1000) continue;
// 			dp[i+i/j] = min(dp[i+i/j],dp[i]+1);
// 		}
// 	}
// 	// for(int i=0;i<=1000;i++) cout<<i<<" "<<dp[i]<<endl;
// }

// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	vector<int> b(n),c(n);
// 	for(int i=0;i<n;i++) cin>>b[i];
// 	for(int i=0;i<n;i++) cin>>c[i];
// 	int maxi = *max_element(b.begin(),b.end());
	
// 	if(n*12<=k){
// 		int ans = 0;
// 		for(int i=0;i<n;i++) ans += c[i];
// 		cout<<ans<<endl;
// 	}else{
// 		// knapsack dp
// 		vector<vector<int>> kp(n+1,vector<int>(k+1,0));
// 		for(int i=1;i<=n;i++){
// 			for(int j=0;j<=k;j++){
// 				kp[i][j] = kp[i-1][j];
// 				if(j-dp[b[i-1]]>=0) kp[i][j] = max(kp[i-1][j-dp[b[i-1]]]+c[i-1],kp[i][j]); 
// 			}
// 		}
// 		cout<<kp[n][k]<<endl;
// 	}
// }

// Keshi Is Throwing a Party
// bool isPossible(int mid,vector<int> &a,vector<int> b){
// 	int n = a.size();
// 	int cnt = 0;
// 	for(int i=0;i<n;i++){
// 		if(b[i]>=cnt && a[i]>=(mid-cnt-1)) cnt++;
// 	}
// 	if(cnt>=mid) return true;
// 	return false;
// }

// void solve(){
// 	int n;cin>>n;
// 	vector<int> a(n),b(n);
// 	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
// 	int lo=0,hi=n;
// 	while(lo<=hi){
// 		int mid = (lo+hi)/2;
// 		if(isPossible(mid,a,b)) lo = mid+1;
// 		else hi = mid-1;
// 	}
// 	cout<<hi<<endl;
// }

// void solve(){
// 	int n,q;
// 	cin>>n>>q;
// 	string s;cin>>s;
// 	vector<vector<int>> v(6,vector<int>(n+1,0));
// 	// applying the next permutation function
// 	int cur = 0;
// 	string sample = "abc";
// 	do{
// 		for(int i=0;i<n;i++){
// 			v[cur][i+1] += !(s[i] == sample[i%3]);
// 		}
// 		cur++;
// 	}while(next_permutation(sample.begin(),sample.end()));

// 	// taking the prefix sum
// 	for(int i=0;i<6;i++){
// 		for(int j=1;j<=n;j++) v[i][j] += v[i][j-1];
// 	}

// 	// for(int i=0;i<6;i++){
// 	// 	for(int j=1;j<=n;j++) cout<<v[i][j]<<" ";
// 	// 	cout<<endl;
// 	// }

// 	while(q--){
// 		int l,r;
// 		cin>>l>>r;
// 		int ans = INT_MAX;
// 		for(int i=0;i<6;i++){
// 			ans = min(ans,v[i][r]-v[i][l-1]);
// 		}
// 		cout<<ans<<endl;
// 	}
// }

// Erase and Extend (Easy Version)
// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	string s;cin>>s;
// 	string ans = "";
// 	for(int i=0;i<k;i++) ans.push_back('z');
// 	for(int i=1;i<=min(n,k);i++){
// 		string temp;
// 		for(int j=0;j<k;j++) temp.push_back(s[j%i]);
// 		if(temp<ans) ans = temp;
// 	}
// 	cout<<ans<<endl;
// }

// Parsa's Humongous Tree
// void dfs(int node,int par,vector<vector<int>> &dp,vector<int> adj[],vector<pair<int,int>> &vp){
// 	for(int it : adj[node]){
// 		if(it==par) continue;
// 		dfs(it,node,dp,adj,vp);
// 		dp[node][0] += max(dp[it][0] + abs(vp[node].first-vp[it].first),dp[it][1] + abs(vp[node].first-vp[it].second));
// 		dp[node][1] += max(dp[it][0] + abs(vp[node].second-vp[it].first),dp[it][1] + abs(vp[node].second-vp[it].second));
// 	}
// }

// void solve(){
// 	int n;cin>>n;
// 	vector<pair<int,int>> vp;
// 	vp.push_back({0,0});
// 	for(int i=0;i<n;i++){
// 		int l,r;
// 		cin>>l>>r;
// 		vp.push_back({l,r});
// 	}
// 	vector<int> adj[n+1];
// 	for(int i=1;i<n;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// 	vector<vector<int>> dp(n+1,vector<int>(2,0));
// 	// cout<<"*"<<endl;
// 	dfs(1,-1,dp,adj,vp);
// 	int ans = max(dp[1][0],dp[1][1]);
// 	cout<<ans<<endl;
// }

// Planar Reflections
// solving using the 3 state dp
// const int M = 1e9+7;
// int dp[1001][1001][2];
// int n,k;

// int reflections(int i,int j,int d){
// 	// creating the base case 
// 	if(i>n || i<1 || j==1) return 0;
// 	if(dp[i][j][d]!=-1) return dp[i][j][d];

// 	// taking the direction sitations as 0 or 1
// 	if(d){
// 		return dp[i][j][1] = (1 + reflections(i+1,j-1,0) + reflections(i-1,j,1))%M;
// 	}else{
// 		return dp[i][j][0] = (1 + reflections(i-1,j-1,1) + reflections(i+1,j,0))%M;
// 	}

// }

// void solve(){
// 	cin>>n>>k;
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=k;j++){
// 			for(int l=1;l<=2;l++) dp[i][j][l] = -1;
// 		}
// 	}

// 	int ans = (1 + reflections(1,k,0))%M;
// 	cout<<ans<<endl;
// }

// Advertising Agency
// const int mod = 1e9 + 7;
 
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

// int fact(int n){
// 	int res = 1;
// 	for(int i=1;i<=n;i++) res = (res*i)%mod;
// 	return res;
// }

// int ncr(int n,int r){
// 	int num = fact(n);
// 	int den = (fact(r)*fact(n-r))%mod;
// 	int mmi = power(den,mod-2);
// 	int res = (num*mmi)%mod;
// 	return res;
// }

// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	sort(arr,arr+n,greater<int>());
// 	int sum = 0;
// 	for(int i=0;i<k;i++) sum+=arr[i];
// 	int hsn[1001] = {0};
// 	for(int i=0;i<n;i++) hsn[arr[i]]++;
// 	int left = k;
// 	int ans = 0;
// 	for(int i=1000;i>=1;i--){
// 		if(left==0) break;
// 		if(hsn[i]>0){
// 			if(hsn[i]>=left){
// 				ans += ncr(hsn[i],left);
// 				break;
// 			}else left-=hsn[i];
// 		}
// 	}
// 	cout<<ans<<endl;
// }

// Row GCD
// void solve(){
// 	int n,m,a1,x,b1;
// 	cin>>n>>m>>a1;
// 	int g = 0;
// 	for(int i=1;i<n;i++) cin>>x,g = __gcd(g,abs(x-a1));
// 	for(int i=0;i<m;i++) cin>>b1,cout<<__gcd(g,a1+b1)<<" ";
// 	cout<<endl;
// }

// Chocolate Bunny
// taking the straight mod and reverse mod
// void solve(){
//     int n;cin>>n;
//     vector<int> ans(n+1,0);
//     int ind1=1,ind2=2;
//     for(int i=1;i<n;i++){
//         int x1,x2;
//         cout<<"? "<<ind1<<" "<<ind2<<endl;
//         cin>>x1;
//         cout<<"? "<<ind2<<" "<<ind1<<endl;
//         cin>>x2;
//         if(x1>x2){
//             ans[ind1] = x1;
//             for(int j=ind1;j<=n;j++){
//                 if(ans[j]==0 && j!=ind2){
//                     ind1 = j;
//                     break;
//                 }
//             }
//         }else{
//             ans[ind2] = x2;
//             for(int j=ind2;j<=n;j++){
//                 if(ans[j]==0 && j!=ind1){
//                     ind2 = j;
//                     break;
//                 }
//             }
//         }
//     }
//     if(ans[ind1]==0) ans[ind1] = n;
//     else ans[ind2] = n;
//     cout<<"! ";
//     for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// Good Subarrays
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     vector<int> prefix(n+1,0);
//     prefix[0] = 0;
//     for(int i=1;i<=n;i++){
//         prefix[i] = prefix[i-1] + (s[i-1]-'0');
//     }

//     map<int,int> cnt;
//     int ans = 0;
//     for(int i=0;i<=n;i++) cnt[prefix[i] - i]++;
//     for(auto ele : cnt){
//         int x = ele.second;
//         ans += (x *( x -1 ))/2;
//     }
//     cout<<ans<<endl;
// }

// Array Walk
// void solve(){
//     int n,k,z;
//     cin>>n>>k>>z;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> prefix(n,0),_max(n+1,0);
//     prefix[0] = arr[0];
//     _max[0] = arr[0]+arr[1];
//     for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + arr[i];
//     for(int i=1;i<n;i++) _max[i] = max(_max[i-1],arr[i]+arr[i+1]);
//     int ans = 0;
//     for(int i=0;i<=z;i++){
//         int left = k-2*i;
//         if(left<0) break;
//         int temp = prefix[left];
//         temp += i*(_max[left]);
//         // cout<<z<<" "<<left<<" "<<temp<<endl;
//         ans = max(temp,ans);
//     }
//     cout<<ans<<endl;
// }

// Orac and LCM
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==1){
//         cout<<arr[0]<<nline;
//         return;
//     }
//     vector<int> _gcd(n,0);
//     _gcd[n-1] = arr[n-1];
//     // taking the prefix gcd
//     for(int i=n-2;i>=0;i--) _gcd[i] = __gcd(_gcd[i+1],arr[i]);
//     int ans = 0;
//     for(int i=0;i<n-1;i++){
//         int calc = (arr[i] * _gcd[i+1])/_gcd[i];
//         // cout<<calc<<"*"<<endl;
//         ans = __gcd(calc,ans);
//     }
//     cout<<ans<<nline;
// }

// Linova and Kingdom
// calculating the subtree sum
// void bfs(vector<int> &cont,vector<int> adj[]){
//     queue<pair<int,int>> q;
//     q.push({1,0});
//     cont[1] = 0;
//     while(!q.empty()){
//         int node = q.front().first;
//         int par = q.front().second;
//         q.pop();
//         for(int it : adj[node]){
//             if(it == par) continue;
//             cont[it] = cont[node] + 1;
//             q.push({it,node});
//         }
//     }
// }

// void dfs(int node,int par,vector<int> &subtree,vector<int> adj[]){
//     for(int it : adj[node]){
//         if(it == par) continue;
//         dfs(it,node,subtree,adj);
//     }
//     subtree[par] += subtree[node];
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     vector<int> adj[n+1];
//     for(int i=1;i<n;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     // calculating the contributions and subtree size
//     vector<int> subtree(n+1,1),cont(n+1,0);
//     bfs(cont,adj);
//     dfs(1,0,subtree,adj);
//     // calculating the net contributions
//     vector<int> net(n,0);
//     for(int i=1;i<=n;i++){
//         net[i-1] = cont[i] - (subtree[i] - 1);
//     }
//     // cout<<"*"<<endl;
//     sort(net.begin(),net.end(),greater<int>());
//     int ans = 0;
//     // for(int i=0;i<n;i++) cout<<net[i]<<"*"<<endl;
//     for(int i=0;i<k;i++) ans+= net[i];
//     cout<<ans<<endl;
// }

// Kuroni and Impossible Calculation
void solve(){
    int n,m;cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 1;
    // by using the pigeon hole priciple
    if(n>m){
        cout<<0<<nline;
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans = (ans*abs(arr[i] - arr[j]))%m;
            if(ans == 0){
                cout<<0<<nline;
                return;
            }
        }
    }

    cout<<ans<<nline;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // pre();
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }

	solve();

    return 0;
}