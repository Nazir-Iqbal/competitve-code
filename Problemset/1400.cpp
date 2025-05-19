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

// Dances (Easy version)
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> a,b;
//     a.push_back(1);
//     for(int i=1;i<n;i++){
//         int temp;cin>>temp;
//         a.push_back(temp);
//     }
//     for(int i=0;i<n;i++){
//         int temp;cin>>temp;
//         b.push_back(temp);
//     }
//     sort(a.begin(),a.end());
//     sort(b.begin(),b.end());
//     int l = 0,r = 0;
//     while(r<n){
//         if(a[l]<b[r]) l++ ,r++;
//         else r++;
//     }
//     // cout<<l<<nline;
//     cout<<(n-l)<<nline;
// }

// Iva & Pav
// bool isPossible(int r,vector<vector<int>> &prefix,int k,int l){
//     int num = 0;
//     for(int i=0;i<31;i++){
//         int calc = prefix[r][i]-prefix[l-1][i];
//         if(calc == r-l+1) num+=(1<<i);
//     }
//     if(num>=k) return true;
//     return false;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n+1] = {0};
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     // calculating the prefix sum of the sex bits;
//     vector<vector<int>> prefix(n+1,vector<int>(31,0));
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<31;j++){
//             if(arr[i]&(1<<j)) prefix[i][j]++;
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<31;j++){
//             prefix[i][j] += prefix[i-1][j];
//         }
//     }

//     int q;cin>>q;
//     while(q--){
//         int l,k;cin>>l>>k;
//         // implementing the binary search
//         int lo = l,hi = n;
//         while(lo<=hi){
//             int mid = (lo+hi)/2;
//             if(isPossible(mid,prefix,k,l)) lo = mid+1;
//             else hi = mid-1;
//         }
//         if(hi<l) cout<<-1<<" ";
//         else cout<<hi<<" ";
//     }
//     cout<<nline;
// }

// Copil Copac Draws Trees
// void dfs(int node,int par,vector<int> adj[],map<pair<int,int>,int> &mp,vector<int> &cnt){
//     for(int ele : adj[node]){
//         if(ele != par){
//             int occ1 = mp[{min(node,par),max(node,par)}],occ2 = mp[{min(node,ele),max(ele,node)}];
//             if(occ1<=occ2) cnt[ele] = cnt[node];
//             else cnt[ele] = cnt[node] + 1;
//             dfs(ele,node,adj,mp,cnt);
//         } 
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> adj[n+1];
//     vector<int> ind(n+1,-1);
//     map<pair<int,int>,int> mp;
//     mp[{-1,1}] = 0;
//     for(int i=1;i<n;i++){
//         int u,v;cin>>u>>v;
//         mp[{min(u,v),max(u,v)}] = i;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     vector<int> cnt(n+1,1);
//     dfs(1,-1,adj,mp,cnt);
//     int ans = *max_element(cnt.begin(),cnt.end());
//     cout<<ans<<nline;
// }

// Make It Round
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int two=0,five=0;
//     int copy1 = n;
//     while(copy1%2==0){
//         two++;
//         copy1/=2;
//     }
//     while(copy1%5==0){
//         five++;
//         copy1/=5;
//     }
//     int num = 1;
//     if(two>=five){
//         int diff = two-five;
//         while(num<=m && diff>0) num*=5,diff--;
//         if(num>m) num/=5;
//     }else{
//         int diff = five-two;
//         while(num<=m && diff>0) num*=2,diff--;
//         if(num>m) num/=2;
//     }
//     while(num<=m) num*=10;
//     if(num>m) num/=10;
//     int temp = 1;
//     for(int i=2;i<10;i++) if(num*i<=m) temp = i;
//     num *=temp;
//     cout<<n*num<<endl;
// }

// Add Modulo 10
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     bool flag = false;
//     for(int i=0;i<n;i++){
//         if(arr[i]%10 == 0 || arr[i]%10 == 5){
//             flag = true;
//             break;
//         }
//     }
//     if(flag){
//         for(int i=0;i<n;i++){
//             int num = arr[i]%10;
//             if(num == 0) continue;
//             if(num == 5) arr[i] += 5;
//             else{
//                 cout<<"No"<<endl;
//                 return;
//             }
//         }
//         for(int i=1;i<n;i++){
//             if(arr[i-1]!=arr[i]){
//                 cout<<"No"<<endl;
//                 return;
//             }
//         }
//         cout<<"Yes"<<endl;
//         return;
//     }

//     for(int i=0;i<n;i++){
//         while(arr[i]%10!=6){
//             arr[i] += (arr[i]%10);
//         }
//     }
//     // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
//     // cout<<nline;
//     for(int i=0;i<n;i++) arr[i] %= 20;
//     for(int i=1;i<n;i++){
//         if(arr[i-1]!=arr[i]){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Schedule Management
// bool isPossible(vector<int> &task,int time,int m){
//     int n = task.size();
//     for(int i=1;i<n;i++){
//         if(time>=task[i]){
//             m-=task[i];
//             m-=(time-task[i])/2;
//         }else m -= time;
//         if(m<=0) return true;
//     }
//     return false;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> v(n+1,0);
//     for(int i=1;i<=m;i++){
//         int temp;cin>>temp;
//         v[temp]++;
//     }
//     int lo = 1,hi = 1e9;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(isPossible(v,mid,m)) hi = mid-1;
//         else lo = mid+1;
//     }
//     cout<<lo<<endl;
// }

// Weird Sum
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> adj[100001][2];
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             int col;cin>>col;
//             adj[col][0].push_back(i);
//             adj[col][1].push_back(j);
//         }
//     }
//     unsigned long long ans = 0;
//     for(int i=1;i<=100000;i++){
//         if(adj[i][0].size()>1){
//             int sum1 = accumulate(adj[i][0].begin(), adj[i][0].end(),0);
//             int sum2 = accumulate(adj[i][1].begin(), adj[i][1].end(),0);
//             int len = adj[i][0].size();
//             sort(adj[i][0].begin(),adj[i][0].end());
//             sort(adj[i][1].begin(),adj[i][1].end());
//             for(int j=0;j<len;j++){
//                 ans+=(sum1-((len-j)*adj[i][0][j]))+(sum2-((len-j)*adj[i][1][j]));
//                 sum1-=adj[i][0][j],sum2-=adj[i][1][j];
//             }
//         }
//     }
//     cout<<ans<<endl;
// }

// Fortune Telling
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = x;
//     for(int i=0;i<n;i++) ans += arr[i];
//     if((ans&1) == (y&1)) cout<<"Alice"<<nline;
//     else cout<<"Bob"<<nline;
// }

// Arranging The Sheep
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     vector<int> prefix(n+2,0),suffix(n+2,0);
//     int cnt = 0;
//     for(int i=1;i<=n;i++){
//         prefix[i] = prefix[i-1];
//         if(s[i-1] == '*') cnt++;
//         else prefix[i] += cnt;
//     }
//     cnt = 0;
//     for(int i = n;i>=1;i--){
//         suffix[i] = suffix[i+1];
//         if(s[i-1] == '*') cnt++;
//         else suffix[i] += cnt;
//     }
//     int ans = 1e18;
//     for(int i=1;i<=n;i++){
//         ans = min(ans,prefix[i-1]+suffix[i]);
//         ans = min(ans,prefix[i]+suffix[i+1]);
//     }
//     cout<<ans<<nline;
// }

// Berland Regional
// void solve(){
//     int n;cin>>n;
//     int u[n],s[n];
//     for(int i=0;i<n;i++) cin>>u[i];
//     for(int i=0;i<n;i++) cin>>s[i];
//     vector<int> adj[n+1];
//     for(int i=0;i<n;i++){
// 		adj[u[i]].push_back(s[i]);
//     }
// 	for(int i=1;i<=n;i++){
// 		sort(adj[i].begin(),adj[i].end(),greater<int>());
// 	}
// 	for(int i=1;i<=n;i++){
// 		int len = adj[i].size();
// 		// prefix sum
// 		for(int j=1;j<len;j++){
// 			adj[i][j] += adj[i][j-1];
// 		}
// 	}
// 	vector<int> ans(n+1,0);
// 	for(int i=1;i<=n;i++){
// 		int len = adj[i].size();
// 		for(int j=1;j<=len;j++){
// 			int calc = (len/j)*j;
// 			ans[j]+=adj[i][calc-1];
// 		}
// 	}
// 	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
// 	cout<<endl;
// }

// AND Sequences
// vector<int> f(200001,1);
// int mod = 1e9+7;
// void pre(){
// 	for(int i=1;i<200001;i++) f[i] = (i*f[i-1])%mod;
// }
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++)  cin>>arr[i];
// 	int ele = *min_element(arr,arr+n);
// 	int cnt = 0;
// 	for(int i=0;i<n;i++){
// 		if(ele == arr[i]) cnt++;
// 		if((arr[i]&ele) != ele){
// 			cout<<0<<nline;
// 			return;
// 		}
// 	}
// 	if(cnt<2){
// 		cout<<0<<nline;
// 	}else{
// 		int ans = ((cnt*(cnt-1))%mod*f[n-2])%mod;
// 		cout<<ans<<nline;
// 	}
// }

// Ball in Berland
// void solve(){
// 	int a,b,k;
// 	cin>>a>>b>>k;
// 	int a1[k],a2[k];
// 	for(int i=0;i<k;i++) cin>>a1[i];
// 	for(int i=0;i<k;i++) cin>>a2[i];
// 	map<int,int> cnt1,cnt2;
// 	for(int i=0;i<k;i++){
// 		cnt1[a1[i]]++;
// 		cnt2[a2[i]]++;
// 	}
// 	int ans = 0;
// 	for(int i=0;i<k;i++) ans += (k-cnt1[a1[i]]-cnt2[a2[i]] + 1);
// 	//  counted every pair twice
// 	// pairs 1 2 is counted for  3 4 and 3 4 counted for 1 2
// 	cout<<ans/2<<nline;
// }

// Zero Remainder Array
// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	map<int,int> m;
// 	for(int i=0;i<n;i++){
// 		int calc = (k-arr[i]%k)%k;
// 		m[calc]++;
// 	}
// 	int ans = 0,last = 0,moves = 1;
// 	for(auto ele : m){
// 		if(ele.first==0) continue;
// 		if(ele.second>=moves){
// 			ans +=k*(ele.second-moves),moves = ele.second;
// 			last = ele.first;
// 		}
// 		// cout<<ele.first<<" "<<ele.second<<" "<<ans<<nline;
// 	}
// 	if(last!=0) ans+=last+1;
// 	cout<<ans<<nline;
// }

// Johnny and Another Rating Drop
// void solve(){
// 	int n;cin>>n;
// 	int ans = 0;
// 	// notice pattern while drawing the sequece
// 	for(int i=0;i<63;i++) ans += (n/(1ll<<i));
// 	cout<<ans<<endl;
// }

// Orac and Models
// void solve(){
// 	int n;cin>>n;
// 	int arr[n+1];
// 	for(int i=1;i<=n;i++) cin>>arr[i];
// 	vector<int> dp(n+1,1);
// 	dp[0] = 0;
// 	dp[1] = 1;
// 	for(int i=2;i<=n;i++){
// 		int len = sqrt(n);
// 		for(int j=1;j<=len;j++){
// 			if(i%j==0){
// 				if(arr[j]<arr[i]) dp[i] = max(dp[i],dp[j]+1);
// 				if(arr[i/j]<arr[i]) dp[i] = max(dp[i],dp[i/j]+1);
// 			}
// 		}
// 	}
// 	cout<<*max_element(dp.begin(),dp.end())<<nline;
// }

// Journey Planning
// void solve(){
// 	int n;cin>>n;
// 	int b[n];
// 	for(int i=0;i<n;i++) cin>>b[i];
// 	vector<int> diff;
// 	for(int i=0;i<n;i++) diff.push_back(i+1-b[i]);
// 	map<int,int> m;
// 	for(int i=0;i<n;i++) m[diff[i]]+=b[i];
// 	int ans = 0;
// 	for(auto ele : m) ans = max(ans,ele.second);
// 	cout<<ans<<nline;
// }

// The Number of Products
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int bal = 0,cnt1 = 0,cnt2 = 0;
// 	int ans = 0;
// 	for(int i=0;i<n;i++){
// 		if(bal&1) cnt2++;
// 		else cnt1++;
// 		if(arr[i]<0) bal++;
// 		if(bal&1) ans += cnt2;
// 		else ans += cnt1;
// 	}
// 	cout<<(n*(n+1))/2 - ans<<" "<<ans<<endl;
// }

// Basketball Exercise
// void solve(){
// 	int n;cin>>n;
// 	int arr[n][2];
// 	for(int i=0;i<n;i++) cin>>arr[i][0];
// 	for(int i=0;i<n;i++) cin>>arr[i][1];
// 	vector<vector<int>> dp(n,vector<int>(3,0));
// 	dp[0][0] = arr[0][0];
// 	dp[0][1] = arr[0][1];
// 	dp[0][2] = max(dp[0][0],dp[0][1]);
// 	for(int i=1;i<n;i++){
// 		dp[i][0] = max(dp[i-1][1] + arr[i][0],dp[i-1][0]);
// 		dp[i][1] = max(dp[i-1][0] + arr[i][1],dp[i-1][1]);
// 		dp[i][2] = max(dp[i][0],dp[i][1]);
// 	}
// 	cout<<dp[n-1][2]<<nline;
// }

// Candy Box (easy version)
// void solve(){
// 	int n;cin>>n;
// 	vector<int> hsn(n+1,0);
// 	map<int,int> m;
// 	for(int i=0;i<n;i++){
// 		int temp;cin>>temp;
// 		m[temp]++;
// 	}
// 	for(auto ele : m) hsn[ele.second]++;
// 	for(int i=1;i<=n;i++){
// 		if(hsn[i]>1){
// 			int j = i-1;
// 			while(j>0 && hsn[i]>1){
// 				if(hsn[j] == 0) hsn[j] = 1,hsn[i]--;
// 				j--;
// 			}
// 		}
// 	}
// 	int ans = 0;
// 	for(int i=1;i<=n;i++) if(hsn[i] > 0) ans+=i;
// 	cout<<ans<<nline;
// }

// Lost Numbers
// void solve(){
// 	vector<int> ans(6,0);
// 	vector<int> p = {4,8,15,16,23,42};
// 	for(int i=0;i<4;i++){
// 		cout<<"? "<<i+1<<" "<<i+2<<endl;
// 		cout.flush();
// 		cin>>ans[i];
// 	}

// 	do{
// 		bool good = 1;
// 		for(int i=0;i<4;i++){
// 			good &= (p[i]*p[i+1] == ans[i]);
// 		}
// 		if(good) break;
// 	}while(next_permutation(p.begin(),p.end()));

// 	cout<<"! ";
// 	for(int ele : p) cout<<ele<<" ";
// 	cout<<endl;
// 	cout.flush();

// }

// Queen
// void dfs(vector<pair<int,int>> adj[],int node,int res,vector<int> &ans){
// 	bool flag = false;
// 	if(res == 0) flag = true;
// 	for(auto it : adj[node]){
// 		if(it.second == 0) flag = true;
// 		dfs(adj,it.first,it.second,ans);
// 	}
// 	// cout<<node<<" "<<flag<<endl;
// 	if(!flag){
// 		ans.push_back(node);
// 	}
// }

// void solve(){
// 	int n;cin>>n;
// 	vector<pair<int,int>> adj[n+1];
// 	int root = 0;
// 	for(int i=1;i<=n;i++){
// 		int v,res;
// 		cin>>v>>res;
// 		if(v == -1){
// 			root = i;
// 			continue;
// 		}
// 		adj[v].push_back({i,res});
// 	}
// 	vector<int> ans;
// 	dfs(adj,root,0,ans);
// 	sort(ans.begin(),ans.end());
// 	if(ans.size()==0){
// 		cout<<-1<<endl;
// 		return;
// 	}
// 	for(int ele : ans) cout<<ele<<" ";
// 	cout<<endl;
// }

// Tape
// void solve(){
// 	int n,m,k;
// 	cin>>n>>m>>k;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int ans = n;
// 	vector<int> seg;
// 	for(int i=1;i<n;i++) seg.push_back(arr[i] - arr[i-1] - 1);
// 	sort(seg.begin(),seg.end());
// 	for(int i=0;i<(n-k);i++) ans += seg[i];
// 	cout<<ans<<endl;
// }

// Mashmokh and ACM
int mod = 1e9+7;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> dp(k+1,vector<int>(n+1,0));
	vector<int> f[n+1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i) f[j].push_back(i);
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<i<<": ";
	// 	for(int ele : f[i]) cout<<ele<<" ";
	// 	cout<<endl;
	// }
	for(int i=1;i<=n; i++) dp[1][i] = 1;
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int ele : f[j]) dp[i][j] = (dp[i][j] + dp[i-1][ele])%mod;
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++) ans = (ans + dp[k][i])%mod;
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