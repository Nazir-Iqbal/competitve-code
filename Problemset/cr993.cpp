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
//     int n;cin>>n;
//     cout<<n-1<<endl;
// }

// void solve(){
//     string s;cin>>s;
//     int n = s.size();
//     unordered_map<char,char> m;
//     m['p'] = 'q';
//     m['w'] = 'w';
//     m['q'] = 'p';
//     string ans;
//     for(int i=n-1;i>=0;i--){
//         ans.push_back(m[s[i]]);
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int m;cin>>m;
//     int a,b,c;
//     cin>>a>>b>>c;
//     int total = min(a,m) + min(b,m);
//     total += min(c,2*m-total);
//     cout<<total<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> ans(n,0);
//     vector<bool> vis(n+1,0);
//     for(int i=0;i<n;i++){
//         int num;cin>>num;
//         if(!vis[num]){
//             ans[i] = num;
//             vis[num] = 1;
//         }
//     }
//     int cur = 0;
//     for(int i=0;i<n;i++){
//         if(ans[i] == 0){
//             while(vis[cur+1]) cur++;
//             ans[i] = cur+1;
//             cur++;
//         }
//     }
//     for(int &i : ans) cout<<i<<" ";
//     cout<<endl;
// }

// Insane Problem using binary search
// void solve(int tt){
//     long long k,l1,r1,l2,r2;
//     cin>>k>>l1>>r1>>l2>>r2;
// 	long long pow = 1ll;
// 	int ans = 0;
// 	for(int i=0;i<31;i++){
// 		long long st = max(l1,(pow+l2-1)/pow);
// 		long long end = min(r1,r2/pow);
// 		// cout<<st<<" "<<end<<" "<<pow<<endl;
// 		if(st<=end) ans += (end-st+1);
// 		if(pow*k>1e9) break;
// 		pow*=k;
// 	}
// 	cout<<ans<<endl;
// }

// Easy Demon Problem
// const int N = 2e5+1;
// vector<int> f[N];

// void pre(){
// 	for(int i=1;i<N;i++){
// 		for(int j=i;j<N;j+=i){
// 			f[j].push_back(i);
// 		}
// 	}
// }

// void solve(){
// 	int n,m,q;
// 	cin>>n>>m>>q;
// 	int arr[n],brr[m];
// 	long long suma = 0,sumb = 0;
// 	for(int i=0;i<n;i++) cin>>arr[i],suma += arr[i];
// 	for(int i=0;i<m;i++) cin>>brr[i],sumb += brr[i];;
// 	set<long long> sa,sb;
// 	for(int i=0;i<n;i++){
// 		suma -= arr[i];
// 		sa.insert(suma);
// 		suma += arr[i];
// 	}
// 	for(int j=0;j<m;j++){
// 		sumb -= brr[j];
// 		sb.insert(sumb);
// 		sumb += brr[j];

// 	}
// 	while(q--){
// 		int x;cin>>x;
// 		if(x==0){
// 			if(sa.count(0) || sb.count(0)) cout<<"Yes"<<endl;
// 			else cout<<"No"<<endl;
// 		}if(x>0){
// 			vector<int> factors = f[x];
// 			bool flag = false;
// 			for(int i=0;i<factors.size();i++){
// 				int a = factors[i],b = x/a;
// 				// cout<<a<<" "<<b<<endl;
// 				if((sa.count(a) && sb.count(b)) || (sa.count(-a) && sb.count(-b))){
// 					flag = true;
// 					break;
// 				}
// 			}
// 			if(flag) cout<<"Yes"<<endl;
// 			else cout<<"No"<<endl;
// 		}else{
// 			x = abs(x);
// 			vector<int> factors = f[x];
// 			bool flag = false;
// 			for(int i=0;i<factors.size();i++){
// 				int a = factors[i],b = x/a;
// 				if((sa.count(-a) && sb.count(b)) || (sa.count(a) && sb.count(-b))){
// 					flag = true;
// 					break;
// 				}
// 			}
// 			if(flag) cout<<"Yes"<<endl;
// 			else cout<<"No"<<endl;
// 		}
// 	}
// }

// Medium Demon Problem (easy version)
// int dfs(int node,int par,vector<int> &dp,vector<int> &indegree,vector<int> adj[],int &cnt){
// 	if(indegree[node] > 0) return 0;
// 	if(dp[node]!=-1) return dp[node];

// 	int maxi = 0;
// 	for(int &it : adj[node]){
// 		if(it == par) continue;
// 		maxi = max(maxi,1+dfs(it,node,dp,indegree,adj,cnt));
// 	}
// 	cnt = max(cnt,maxi);
// 	return dp[node] = maxi;
// }

// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	vector<int> adj[n+1];
// 	vector<int> indegree(n+1,0);
// 	for(int i=0;i<n;i++){
// 		adj[i+1].push_back(arr[i]);
// 		indegree[arr[i]]++;
// 	}
// 	queue<int> q;
// 	for(int i=1;i<=n;i++) if(indegree[i]==0) q.push(i);
// 	while(!q.empty()){
// 		int node = q.front();
// 		q.pop();
// 		for(int &it : adj[node]){
// 			indegree[it]--;
// 			if(indegree[it]==0) q.push(it);
// 		}
// 	}
// 	int zero = 0;
// 	vector<int> dp(n+1,-1);
// 	for(int i=1;i<=n;i++){
// 		if(indegree[i] == 0){
// 			dfs(i,-1,dp,indegree,adj,zero);
// 		}
// 	}
// 	cout<<zero+2<<endl;
// }

// Medium Demon Problem (hard version)

// int dfs(int node,int par,vector<int> &dp,vector<int> &indegree,vector<int> adj[],int &cnt){
// 	if(indegree[node] > 0) return 0;
// 	if(dp[node]!=-1) return dp[node];

// 	int maxi = 1;
// 	for(int &it : adj[node]){
// 		if(it == par) continue;
// 		maxi += dfs(it,node,dp,indegree,adj,cnt);
// 	}
// 	// cout<<node<<" "<<maxi<<endl;
// 	cnt = max(cnt,maxi);
// 	return dp[node] = maxi;
// }

// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	vector<int> adj[n+1];
// 	vector<int> indegree(n+1,0);
// 	for(int i=0;i<n;i++){
// 		adj[i+1].push_back(arr[i]);
// 		indegree[arr[i]]++;
// 	}
// 	queue<int> q;
// 	for(int i=1;i<=n;i++) if(indegree[i]==0) q.push(i);
// 	while(!q.empty()){
// 		int node = q.front();
// 		q.pop();
// 		for(int &it : adj[node]){
// 			indegree[it]--;
// 			if(indegree[it]==0) q.push(it);
// 		}
// 	}
// 	vector<int> radj[n+1];
// 	for(int i=1;i<=n;i++){
// 		for(int &j : adj[i]){
// 			radj[j].push_back(i);
// 		}
// 	}
// 	int zero = 0;
// 	vector<int> dp(n+1,-1);
// 	for(int i=1;i<=n;i++){
// 		if(indegree[i] == 0){
// 			dfs(i,-1,dp,indegree,radj,zero);
// 		}
// 	}
// 	cout<<zero+2<<endl;
// }

void print(vector<vector<int>> &v){
	for(auto ele : v){
		for(int it : ele) cout<<it<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void solve(){
	int n,q;
	cin>>n>>q;
	vector<vector<int>> p(n+1,vector<int>(n+1,0)), px(n+1,vector<int>(n+1,0)), py(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int num;cin>>num;
			p[i][j] = num + (p[i-1][j] + p[i][j-1] - p[i-1][j-1]);
			px[i][j] = (i-1)*num + (px[i-1][j] + px[i][j-1] - px[i-1][j-1]);
			py[i][j] = j*num + (py[i-1][j] + py[i][j-1] - py[i-1][j-1]);
		}
	}
	// print(p);
	// print(px);
	// print(py);

	while(q--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int s = p[x2][y2] - (p[x2][y1-1] + p[x1-1][y2] - p[x1-1][y1-1]);
		int sr = px[x2][y2] - (px[x2][y1-1] + px[x1-1][y2] - px[x1-1][y1-1]);
		int sc = py[x2][y2] - (py[x2][y1-1] + py[x1-1][y2] - py[x1-1][y1-1]);
		int len = y2-y1+1;
		int snr = sr - (x1-1)*s;
		int snc = sc - (y1-1)*s;
		// cout<<s<<" "<<snr<<" "<<snc<<' '<<len<<endl;
		int ans = len*snr + snc;
		cout<<ans<<" ";
	}
	cout<<endl;
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