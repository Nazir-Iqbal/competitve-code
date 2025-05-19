#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define float double
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Greetings
// void solve(){
//     int n;cin>>n;
//     vector<pair<int,int>> vp(n);
//     for(int i=0;i<n;i++) cin>>vp[i].first>>vp[i].second;
//     sort(vp.begin(),vp.end());
//     int ans = 0;
// 	oset<int> os;
//     for(int i=0;i<n;i++) os.insert(vp[i].second);
// 	for(int i=0;i<n;i++){
// 		ans += os.order_of_key(vp[i].second);
// 		os.erase(vp[i].second);
// 	}
// 	cout<<ans<<nline;
// }

// Block Sequence
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	vector<int> dp(n+1,0);
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	for(int i=n-1;i>=0;i--){
// 		// choice to delete the element
// 		dp[i] = 1+dp[i+1];
// 		// choice 2 to paint the element
// 		if(i+arr[i]+1<=n) dp[i] = min(dp[i],dp[i+arr[i]+1]);
// 	}
// 	cout<<dp[0]<<nline;
// }

// Palindrome Basis
// int n,m;
// vector<vector<int>> dp;
// vector<int> palindrome;
// int mod = 1e9+7;
// int N=40000;
// void pre(){
// 	for(int i=1;i<=9;i++) palindrome.push_back(i);
// 	for(int i=1;i<=9;i++) palindrome.push_back(i*10+i);
// 	for(int i=1;i<=9;i++){
// 		for(int j=0;j<=9;j++) palindrome.push_back(i*100 + j*10 + i);
// 	}
// 	for(int i=1;i<=9;i++){
// 		for(int j=0;j<=9;j++) palindrome.push_back(i*1000 + j*100 + j*10 + i);
// 	}
// 	bool flag = false;
// 	for(int i=1;i<=9;i++){
// 		for(int j=0;j<=9;j++){
// 			for(int k=0;k<=9;k++){
// 				int num = i*10000 + j*1000 + k*100 + j*10 + i;
// 				if(num>N){
// 					flag = true;
// 					break;
// 				}
// 				palindrome.push_back(num);
// 			}
// 			if(flag) break;
// 		}
// 		if(flag) break;
// 	}
// 	n = N;
// 	m = palindrome.size();
// 	dp.resize(n+1,vector<int>(m+1,0));
// 	for(int i=0;i<=m;i++) dp[0][i] = 1;
// 	for(int i=1;i<=n;i++){
// 		for(int j=1;j<=m;j++){
// 			dp[i][j] = dp[i][j-1];
// 			if(i-palindrome[j-1]>=0) dp[i][j] = (dp[i][j] + dp[i-palindrome[j-1]][j])%mod;
// 		}
// 	}
// }

// void solve(){
// 	int num;cin>>num;
// 	cout<<dp[num][m]<<nline;
// }

// Line Empire
// void solve(){
// 	int n,a,b;
// 	cin>>n>>a>>b;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int c1 = 0,cc = 0,c2 = 0;
// 	int ans = b*(arr[0]-0);
// 	c2 = 1;
// 	int con = 1;
// 	// calculating the possibility of conquering the kingdom along
// 	// with the movement of the kingdom
// 	while(c2<n){
// 		while(cc<c2 && ( (a*abs(c1-arr[cc])) <= (b*(n-con)*abs(c1-arr[cc])) ) ){
// 			ans += a*abs(c1-arr[cc]);
// 			c1=arr[cc];
// 			cc++;
// 		}
// 		ans += b*abs(c1-arr[c2]);
// 		c2++,con++;
// 	}
// 	cout<<ans<<nline;
// }

// Factorials and Powers of Two
// vector<int> f(16,1);
// void pre(){
// 	for(int i=1;i<=15;i++) f[i] = i*f[i-1];
// }

// int recur(int n,int ind,map<pair<int,int>,int> &dp){
// 	//  base case
// 	if(ind==0){
// 		return __builtin_popcountll(n);
// 	}

// 	if(dp.find({n,ind})!=dp.end()) return dp[{n,ind}];
	
// 	// not inclcude;
// 	int ans = recur(n,ind-1,dp);
// 	// include
// 	if(n>=f[ind]){
// 		int include = 1 + recur(n-f[ind],ind-1,dp);
// 		ans = min(ans,include);
// 	}
// 	return dp[{n,ind}] = ans;
// }

// void solve(){
// 	int n;cin>>n;
// 	map<pair<int,int>,int> dp;
// 	int ans = recur(n,15,dp);
// 	cout<<ans<<endl;
// }

// AGAGA XOOORRR
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int total = 0;
// 	for(int i=0;i<n;i++) total ^= (arr[i]);
// 	if(total==0){
// 		cout<<"Yes"<<nline;
// 		return;
// 	}
// 	vector<int> prefix(n+1,0);
// 	for(int i=1;i<=n;i++) prefix[i] = (prefix[i-1]^arr[i-1]);

// 	for(int i=1;i<=n-2;i++){
// 		for(int j=i+1;j<=n-1;j++){
// 			int num1 = prefix[i];
// 			int num2 = prefix[j]^prefix[i];
// 			int num3 = prefix[n]^prefix[j];
// 			// cout<<num1<<" "<<num2<<" "<<num3<<nline;
// 			if(num1 == num2 && num2 == num3){
// 				cout<<"Yes"<<nline;
// 				return;
// 			}
// 		}
// 	}
// 	cout<<"No"<<nline;
// }

// Eastern Exhibition
// void solve(){
// 	int n;cin>>n;
// 	vector<int> x(n),y(n);
// 	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
// 	sort(x.begin(),x.end());
// 	sort(y.begin(),y.end());
// 	// x and y both are independent so we can find the minimum for both independently
// 	// to find the minimum distance in line we just take the distance betweent he median values
// 	int cnt = 1;
// 	if(n&1){
// 		cout<<1<<nline;
// 	}else{
// 		int m2 = n/2,m1 = (n-1)/2;
// 		// cout<<m1<<" "<<m2<<nline;
// 		int cnt = (x[m2]-x[m1]+1)*(y[m2]-y[m1]+1);
// 		cout<<cnt<<nline;
// 	}
// }

// 13th Labour of Heracles
// void dfs(int node,int par,vector<int> adj[],vector<int> &hsn){
// 	// hsn[node]++;
// 	for(int it : adj[node]){
// 		// cout<<adj[node].size()<<" "<<node<<" "<<it<<nline;
// 		hsn[it]++;
// 		if(it!=par) dfs(it,node,adj,hsn);
// 	}
// }

// void solve(){
// 	int n;cin>>n;
// 	int weight[n+1];
// 	for(int i=1;i<=n;i++) cin>>weight[i];
// 	vector<int> hsn(n+1,0);
// 	vector<int> adj[n+1];
// 	for(int i=0;i<n-1;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// 	dfs(1,-1,adj,hsn);
// 	vector<int> joint;
// 	// for(int i=0;i<=n;i++) cout<<hsn[i]<<" ";
// 	// cout<<nline;
// 	for(int i=1;i<=n;i++){
// 		while(hsn[i]>1) joint.push_back(i),hsn[i]--;
// 	}
// 	for(int i=0;i<joint.size();i++) joint[i] = weight[joint[i]];
// 	sort(joint.begin(),joint.end(),greater<int>());
// 	int ans = 0;
// 	for(int i=1;i<=n;i++) ans += weight[i];
// 	cout<<ans<<" ";
// 	for(int i=0;i<joint.size();i++){
// 		ans+=joint[i];
// 		cout<<ans<<" ";
// 	}
// 	cout<<nline;
// }

// k-Amazing Numbers
// void solve(){
// 	int n;cin>>n;
// 	int arr[n+1];
// 	for(int i=1;i<=n;i++) cin>>arr[i];
// 	vector<int> diff(n+1,-1),prev(n+1,1);
// 	for(int i=1;i<=n;i++){
// 		if(diff[arr[i]] == -1) diff[arr[i]] = i-1;
// 		else diff[arr[i]] = max(diff[arr[i]],(i-prev[arr[i]]-1));
// 		prev[arr[i]] = i;
// 	}
// 	for(int i=1;i<=n;i++){
// 		if(diff[arr[i]] != -1){
// 			diff[arr[i]] = max(diff[arr[i]],(n-prev[arr[i]]));
// 		}
// 	}
// 	// for(int i=1;i<=n;i++) cout<<diff[i]<<" ";
// 	// cout<<endl;
// 	vector<int> v(n+1,INT_MAX);
// 	for(int i=1;i<=n;i++){
// 		if(diff[i] == -1) continue;
// 		v[diff[i]] = min(v[diff[i]],i);
// 	}
// 	for(int i=1;i<=n;i++){
// 		v[i] = min(v[i-1],v[i]);
// 	}
// 	for(int i=1;i<=n;i++){
// 		if(v[i-1]==INT_MAX) cout<<-1<<" ";
// 		else cout<<v[i-1]<<" ";
// 	}
// 	cout<<endl;
// }

// Balanced Bitstring
// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	string s;cin>>s;
// 	vector<int> v(k,-1);
// 	for(int i=0;i<n;i++){
// 		int num = i%k;
// 		int calc = s[i]-'0';
// 		if(s[i] == '?') continue;
// 		if(v[num]==-1) v[num] = calc;
// 		else{
// 			if(v[num]!=calc){
// 				cout<<"No"<<endl;
// 				return;
// 			}
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		if(v[i%k] == -1) continue;
// 		s[i] = char('0'+v[i%k]);
// 	}
// 	// cout<<s<<endl;
// 	int one=0,zero=0,extra=0;
// 	for(int i=0;i<k;i++){
// 		if(s[i] == '1') one++;
// 		else if(s[i] == '0') zero++;
// 		else extra++;
// 	}
// 	if(one!=zero){
// 		int diff = abs(one-zero);
// 		if(diff>extra){
// 			cout<<"No"<<endl;
// 			return;
// 		}
// 		int left = extra-diff;
// 		if(left&1){
// 			cout<<"No"<<endl;
// 			return;
// 		}
// 	}
// 	cout<<"Yes"<<endl;
// }

// Powered Addition
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int num = 0;
// 	for(int i=1;i<n;i++){
// 		if(arr[i]<arr[i-1]){
// 			num = max(num,arr[i-1]-arr[i]);
// 			arr[i] = arr[i-1];
// 		}
// 	}
// 	int ind = -1;
// 	for(int i=0;i<31;i++){
// 		if(num&(1<<i)) ind = i;
// 	}
// 	cout<<ind+1<<nline;
// }

// K-Complete Word
// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	string s;cin>>s;
// 	int ans = 0,sum = 0;
// 	int cnt = n/k;
// 	for(int i=0;i<k/2;i++){
// 		map<char,int> hsn;
// 		hsn[s[i]]++;
// 		for(int j=1;j<=cnt;j++){
// 			hsn[s[j*k-i-1]]++;
// 			int calc = j*k + i;
// 			if(calc<n) hsn[s[calc]]++;
// 		}
// 		int ele = 0;
// 		for(int i='a';i<='z';i++) ele = max(ele,hsn[i]);
// 		sum += ele;
// 	}
// 	if(k&1){
// 		int j = k/2;
// 		map<char,int> hsn;
// 		while(j<n){
// 			hsn[s[j]]++;
// 			j+=k;
// 		}
// 		int ele = 0;
// 		for(int i='a';i<='z';i++) ele = max(ele,hsn[i]);
// 		sum += ele;

// 	}
// 	ans = n - sum;
// 	cout<<ans<<nline;
// }

// Ehab and Path-etic MEXs
// void solve(){
// 	int n;cin>>n;
// 	vector<pair<int,int>> edges;
// 	for(int i=0;i<n-1;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		edges.push_back({u,v});
// 	}
// 	vector<int> degree(n+1,0);
// 	for(int i=0;i<n-1;i++){
// 		degree[edges[i].first]++;
// 		degree[edges[i].second]++;
// 	}
// 	vector<pair<int,int>> vp;
// 	for(int i=0;i<n-1;i++){
// 		int num = min(degree[edges[i].first],degree[edges[i].second]);
// 		vp.push_back({num,i});
// 	}
// 	sort(vp.begin(),vp.end());
// 	vector<int> ans(n-1);
// 	for(int i=0;i<n-1;i++){
// 		ans[vp[i].second] = i;
// 	}
// 	for(int ele : ans) cout<<ele<<nline;
// }

// Count Subrectangles
// void solve(){
// 	int n,m,k;
// 	cin>>n>>m>>k;
// 	vector<int> a(n),b(m);
// 	for(int i=0;i<n;i++) cin>>a[i];
// 	for(int i=0;i<m;i++) cin>>b[i];
// 	vector<int> prefixa(n+1,0),prefixb(m+1,0);
// 	for(int i=1;i<=n;i++) prefixa[i] = prefixa[i-1] + a[i-1];
// 	for(int i=1;i<=m;i++) prefixb[i] = prefixb[i-1] + b[i-1];
// 	vector<pair<int,int>> f;
// 	for(int i=1;i*i<=k;i++){
// 		if(k%i==0){
// 			int num1,num2;
// 			num1 = i;
// 			num2 = k/i;
// 			f.push_back({num1,num2});
// 			if(num1!=num2) f.push_back({num2,num1});
// 		}
// 	}
// 	// for(int i=0;i<f.size();i++) cout<<f[i].first<<" "<<f[i].second<<nline;
// 	int ans = 0;
// 	for(int i=0;i<f.size();i++){
// 		int num1,num2;
// 		num1 = f[i].first;
// 		num2 = f[i].second;
// 		// checking row,colum
// 		int x = 0,y = 0;
// 		for(int j=1;j<=n;j++){
// 			if(j+num1-1 > n) break;
// 			if(prefixa[j+num1-1]-prefixa[j-1] == num1) x++;
// 		}
// 		for(int j=1;j<=m;j++){
// 			if(j+num2-1 > m) break;
// 			if(prefixb[j+num2-1] - prefixb[j-1] == num2) y++;
// 		}
// 		// cout<<x<<" "<<y<<endl;
// 		ans += (x*y);
// 	}
// 	cout<<ans<<nline;
// }

// Zero Array
// void solve(){
// 	int n;cin>>n;
// 	int sum = 0,ele = 0;
// 	for(int i=0;i<n;i++){
// 		int temp;cin>>temp;
// 		ele = max(ele,temp);
// 		sum+=temp;
// 	}

// 	if(sum&1) cout<<"NO"<<nline;
// 	else{
// 		if(sum-ele >= ele) cout<<"YES"<<endl;
// 		else cout<<"NO"<<endl;
// 	}
// }

// Edgy Trees
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

// void dfs(int node,vector<pair<int,int>> adj[],vector<bool> &vis,int &ans){
// 	vis[node] = true;
// 	ans++;
// 	// cout<<node<<" "<<ans<<endl;
// 	for(auto it : adj[node]){
// 		int v = it.first;
// 		int wt = it.second;
// 		if(vis[v]== 1) continue;
// 		if(wt == 0) dfs(v,adj,vis,ans);
// 	}

// }

// void solve(){
// 	int n,k;cin>>n>>k;
// 	vector<pair<int,int>> adj[n+1];
// 	for(int i=0;i<n-1;i++){
// 		int u,v,wt;
// 		cin>>u>>v>>wt;
// 		adj[u].push_back({v,wt});
// 		adj[v].push_back({u,wt});
// 	}
// 	vector<bool> vis(n+1,0);
// 	vector<int> com;
// 	for(int i=1;i<=n;i++){
// 		if(!vis[i]){
// 			int sz = 0;
// 			dfs(i,adj,vis,sz);
// 			// cout<<i<<" "<<sz<<endl;
// 			com.push_back(sz);
// 		}
// 	}
// 	int ans = power(n,k);
// 	for(int i=0;i<com.size();i++){
// 		ans = (mod + ans - power(com[i],k))%mod;
// 	}
// 	cout<<ans<<nline;
// }

// Zero Quantity Maximization
// void solve(){
// 	int n;cin>>n;
// 	int a[n],b[n];
// 	for(int i=0;i<n;i++) cin>>a[i];
// 	for(int i=0;i<n;i++) cin>>b[i];
// 	int ans = 0;
// 	map<pair<int,int>,int> m;
// 	for(int i=0;i<n;i++){
// 		if(a[i] == 0){
// 			if(b[i] == 0) ans++;
// 		}else{
// 			int num = __gcd(a[i],b[i]);
// 			a[i] /= num;
// 			b[i] /=num;
// 			m[{a[i],b[i]}]++;
// 		}
// 	}
// 	int maxi = 0;
// 	for(auto ele : m) maxi = max(ele.second,maxi); 
// 	ans+=maxi;
// 	cout<<ans<<nline;
// }

// Lunar New Year and a Wander
// void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &ans,priority_queue<int> &pq){
// 	vis[node] = 1;
// 	ans.push_back(node);
// 	for(int it : adj[node]){
// 		if(!vis[it]) pq.push(-it);
// 	}
// 	while(!pq.empty()){
// 		int num = -pq.top();
// 		pq.pop();
// 		if(!vis[num]){
// 			dfs(num,adj,vis,ans,pq);
// 		}
// 	}
// }

// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	vector<int> adj[n+1];
// 	vector<int> vis(n+1,0);
// 	for(int i=0;i<m;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// 	vector<int> ans;
// 	priority_queue<int> pq;
// 	dfs(1,adj,vis,ans,pq);
// 	for(int ele : ans) cout<<ele<<" ";
// 	cout<<endl;
// }

// Division and Union
// void solve(){
// 	int n;cin>>n;
// 	vector<pair<int,pair<int,int>>> vp;
// 	for(int i=0;i<n;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		vp.push_back({v,{u,i}});
// 	}
// 	sort(vp.begin(),vp.end());
// 	int ind = -1;
// 	int minl = vp[n-1].second.first;
// 	for(int i=n-1;i>=1;i--){
// 		if(minl>vp[i-1].first){
// 			ind = i;
// 			break;
// 		}
// 		minl = min(minl,vp[i-1].second.first);
// 	}
// 	vector<int> ans(n);
// 	if(ind == -1) cout<<-1<<nline;
// 	else{
// 		for(int i=0;i<n;i++){
// 			if(i<ind) ans[vp[i].second.second] = 1;
// 			else ans[vp[i].second.second] = 2;
// 		}
// 		for(int ele : ans) cout<<ele<<" ";
// 		cout<<nline;
// 	}
// }

// The Fair Nut and String
// int mod = 1e9+7;
// void solve(){
// 	string s;cin>>s;
// 	int n=s.length();
// 	string temp;
// 	for(int i=0;i<n;i++){
// 		if(s[i] !='a' && s[i] != 'b') continue;
// 		temp.push_back(s[i]);
// 	}
// 	n=temp.length();
// 	// cout<<temp<<endl;
// 	vector<int> dp(n+1,0);
// 	int prev = 0;
// 	if(temp[0] == 'a') dp[1] = 1;
// 	else dp[1] = 0;
// 	for(int i=2;i<=n;i++){
// 		if(temp[i-1] == 'a') dp[i] = (1+dp[prev]+dp[i-1])%mod;
// 		else if(temp[i-2]=='a' && temp[i-1]=='b') dp[i] = dp[i-1],prev=i-1;
// 		else dp[i] = dp[i-1];
// 	}
// 	// for(int ele : dp) cout<<ele<<" ";
// 	// cout<<endl;
// 	cout<<dp[n]<<nline;
// }

// Cut 'em all!
// int dfs(int node,int par,int &cut,vector<int> adj[]){
// 	int sz = 1;
// 	for(int it : adj[node]){
// 		if(it!=par){
// 			int num = dfs(it,node,cut,adj);
// 			if(num%2==0) cut++;
// 			sz+=num;
// 		}
// 	}
// 	return sz;
// }

// void solve(){
// 	int n;cin>>n;
// 	vector<int> adj[n+1];
// 	for(int i=0;i<n-1;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// 	int cuts = 0;
// 	int sz = dfs(1,-1,cuts,adj);
// 	if(sz&1){
// 		cout<<-1<<nline;
// 		return;
// 	}
// 	cout<<cuts<<nline;
// }

// Nested Segments
// bool cmp(pair<int,pair<int,int>> x,pair<int,pair<int,int>> y){
// 	if(x.first==y.first){
// 		return x.second>y.second;
// 	}
// 	return x.first<y.first;
// }

// void solve(){
// 	int n;cin>>n;
// 	vector<pair<int,pair<int,int>>> vp;
// 	for(int i=1;i<=n;i++){
// 		int l,r;
// 		cin>>l>>r;
// 		vp.push_back({r,{l,i}});
// 	}
// 	sort(vp.begin(),vp.end(),cmp);
// 	vector<pair<int,int>> prefix;
// 	int num = vp[0].second.first,ind = vp[0].second.second;
// 	for(int i=0;i<n;i++){
// 		if(num<vp[i].second.first){
// 			num = vp[i].second.first;
// 			ind = vp[i].second.second;
// 		}
// 		prefix.push_back({num,ind});
// 	}
// 	pair<int,int> ans = {-1,-1};
// 	for(int i=n-1;i>0;i--){
// 		int l1 = prefix[i-1].first;
// 		int l2 = vp[i].second.first;
// 		if(l1>=l2){
// 			ans.first = prefix[i-1].second;
// 			ans.second = vp[i].second.second;
// 			break;
// 		}
// 	}
// 	cout<<ans.first<<" "<<ans.second<<endl;
// }

// Minimize the error
// void solve(){
// 	int n,k1,k2;
// 	cin>>n>>k1>>k2;
// 	int total = k1+k2;
// 	vector<int> a(n),b(n);
// 	for(int i=0;i<n;i++) cin>>a[i];
// 	for(int i=0;i<n;i++) cin>>b[i];
// 	priority_queue<int> pq;
// 	for(int i=0;i<n;i++){
// 		int diff = abs(a[i]-b[i]);
// 		if(diff>0) pq.push(diff);
// 	}
// 	while(!pq.empty() && total>0){
// 		int num = pq.top();
// 		pq.pop();
// 		num--,total--;
// 		if(num==0) continue;
// 		pq.push(num);
// 	}
// 	int ans = 0;
// 	if(total>0){
// 		if(total&1) ans = 1;
// 		else ans = 0;
// 	}else{
// 		while(!pq.empty()){
// 			ans += (pq.top()*pq.top());
// 			pq.pop();
// 		}
// 	}
// 	cout<<ans<<nline;
// }

// Pride
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	int gcd = 0;
// 	for(int i=0;i<n;i++) cin>>arr[i],gcd = __gcd(gcd,arr[i]);
// 	if(gcd!=1){
// 		cout<<-1<<nline;
// 		return;
// 	}
// 	int cnt = 0;
// 	for(int i=0;i<n;i++){
// 		if(arr[i] == 1)  cnt++;
// 	}
// 	if(cnt>0){
// 		cout<<n-cnt<<nline;
// 		return;
// 	}
// 	int len = INT_MAX;
// 	for(int i=0;i<n;i++){
// 		int gcd1 = 0;
// 		for(int j=i;j<n;j++){
// 			gcd1 = __gcd(gcd1,arr[j]);
// 			if(gcd1==1) len = min(len,j-i);
// 		}
// 	}
// 	cout<<len+(n-1)<<nline;
// }

// Two TVs
// void solve(){
// 	int n;cin>>n;
// 	vector<pair<int,int>> vp;
// 	for(int i=0;i<n;i++){
// 		int l,r;
// 		cin>>l>>r;
// 		vp.push_back({l,r});
// 	}
// 	sort(vp.begin(),vp.end());
// 	int tv1 = -1,tv2 = -1;
// 	for(int i=0;i<n;i++){
// 		if(tv1<vp[i].first) tv1 = vp[i].second;
// 		else if(tv2<vp[i].first) tv2 = vp[i].second;
// 		else{
// 			cout<<"No"<<nline;
// 			return;
// 		}
// 	}
// 	cout<<"Yes"<<nline;
// }

// Little Girl and Maximum Sum
void solve(){
	int n,q;
	cin>>n>>q;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end(),greater<int> ());
	int hsn[n+2] = {0};
	int sum = 0;
	while(q--){
		int l,r;
		cin>>l>>r;
		hsn[l]++,hsn[r+1]--;
	}
	for(int i=1;i<=n;i++) hsn[i]+=hsn[i-1];
	vector<int> cnt;
	for(int i=1;i<=n;i++) cnt.push_back(hsn[i]);
	sort(cnt.begin(),cnt.end(),greater<int> ());
	for(int i=0;i<n;i++){
		sum+=(cnt[i]*v[i]);
	}
	cout<<sum<<nline;
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