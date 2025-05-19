#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define li long double 
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int xc,yc,k;
//     cin>>xc>>yc>>k;
//     int tx = k*xc,ty = k*yc;
//     int rem = k;
//     if(k&1) cout<<tx<<" "<<ty<<endl,rem--;
//     else{
//         if(1!=tx-1 && 1!=ty-1){
//             cout<<1<<" "<<1<<endl;
//             cout<<tx-1<<" "<<ty-1<<endl;
//         }else{
//             cout<<0<<" "<<0<<endl;
//             cout<<tx<<" "<<ty<<endl;
//         }
//         rem-=2;
//     }
//     int cnt = 1e5+5;
//     for(int i=0;i<rem;i+=2){
//         cout<<cnt<<" "<<cnt<<endl;
//         cout<<-cnt<<" "<<-cnt<<endl;
//         cnt++;
//     }
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> ans;
//     for(int i=1;i<n;i++) ans.push_back(arr[i]);
//     ans.push_back(arr[0]);
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Perform Operations to Maximize Score
// bool check(vector<pair<int,int>> &vp,int k,int med){
// 	int n = vp.size();
// 	n--;
// 	int need = (n+2)/2,cur=0;
// 	for(int i=n-1;i>=0;i--){
// 		if(vp[i].first>=med) cur++;
// 		else{
// 			if(k==0 || vp[i].second==0) continue;
// 			int req = med - vp[i].first;
// 			if(k>=req)k-=req,cur++;
// 		}
// 	}

// 	return cur>=need;
// }

// void solve(){
// 	int n,k;
// 	cin>>n>>k;
// 	int a[n+1];
// 	for(int i=1;i<=n;i++) cin>>a[i];
// 	bool b[n+1];
// 	for(int i=1;i<=n;i++) cin>>b[i];
// 	vector<pair<int,int>> vp;
// 	for(int i=1;i<=n;i++) vp.push_back({a[i],b[i]});
// 	sort(vp.begin(),vp.end());
// 	// max increase
// 	int mid = n/2-1,ans = 0;
// 	for(int i=0;i<n;i++){
// 		int local = vp[i].first;
// 		if(i>mid) local+=vp[mid].first;
// 		else local += vp[mid+1].first;
// 		if(vp[i].second) local+=k;
// 		ans = max(ans,local);
// 	}
// 	// increasing the median
// 	int local = vp[n-1].first;
// 	int lo = 1,hi = 1e9+7;
// 	while(lo<=hi){
// 		int mid = (lo+hi)/2;
// 		if(check(vp,k,mid)) lo = mid+1;
// 		else hi = mid-1;
// 	}
// 	local += hi;
// 	ans = max(ans,local);
// 	cout<<ans<<endl;
// }

// Determine Winning Islands in Race
// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	int arr[n];
// 	vector<int> adj[n+1];
// 	for(int i=0;i<m;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 	}
// 	vector<int> min_path(n+1,1e9);
// 	min_path[1] = 0;
// 	string ans(n-1,'1');
// 	int j = 2;
// 	for(int i=1;i<=n;i++){
// 		min_path[i] = min(min_path[i],min_path[i-1]+1);
// 		for(int it : adj[i]){
// 			min_path[it] = min(min_path[it],min_path[i]+1);
// 			while(j<(it-min_path[i]-1)){
// 				ans[j-1] = '0';
// 				j++;
// 			}
// 		}
// 		j=max(j,i+2);
// 	}
// 	cout<<ans<<endl;
// }

// Rendez-vous de Marian et Robin
// void dijk(int node,vector<pair<int,int>> adj[],vector<vector<int>> &dist,vector<bool> &hsn,int n){
// 	dist[node][0] = 0;
// 	if(hsn[node]) dist[node][1] = 0;
// 	priority_queue<pair<int,pair<int,bool>>> pq;
// 	vector<vector<bool>> vis(n+1,vector<bool>(2,0));
// 	pq.push({0,{node,hsn[node]}});
// 	while(!pq.empty()){
// 		int cur = pq.top().second.first;
// 		bool horse = pq.top().second.second;
// 		int dis = -pq.top().first;
// 		pq.pop();
// 		if(vis[cur][horse]) continue;
// 		for(auto &ele : adj[cur]){
// 			int it = ele.first;
// 			int wt = ele.second;
// 			if(horse) wt/=2;
// 			if(wt+dis<=dist[it][horse]){
// 				dist[it][horse] = wt+dis;
// 				if(!horse) pq.push({-(wt+dis),{it,hsn[it]}});
// 				else pq.push({-(wt+dis),{it,1}});
// 			}
// 		}
// 		vis[cur][horse] = 1;
// 	}
// }

// void solve(){
// 	int n,m,k;
// 	cin>>n>>m>>k;
// 	vector<pair<int,int>> adj[n+1];
// 	vector<bool> hsn(n+1,0);
// 	for(int i=0;i<k;i++){
// 		int temp;cin>>temp;
// 		hsn[temp]=1;
// 	}
// 	for(int i=0;i<m;i++){
// 		int u,v,wt;
// 		cin>>u>>v>>wt;
// 		adj[u].push_back({v,wt});
// 		adj[v].push_back({u,wt});
// 	}
// 	vector<vector<int>> dist1(n+1,vector<int> (2,1e15));
// 	vector<vector<int>> dist2(n+1,vector<int> (2,1e15));
// 	dijk(1,adj,dist1,hsn,n);
// 	dijk(n,adj,dist2,hsn,n);
// 	int ans = 1e15;
// 	for(int i=1;i<=n;i++){
// 		int temp1 = min(dist1[i][0],dist1[i][1]), temp2 = min(dist2[i][0],dist2[i][1]);
// 		ans = min(ans,max(temp1,temp2));
// 	}
// 	if(ans >= 1e15) cout<<-1<<"\n";
// 	else cout<<ans<<'\n';
// 	// for(int i=1;i<=n;i++) cout<<dist1[i][0]<<" "<<dist1[i][1]<<endl;
// 	// for(int i=1;i<=n;i++) cout<<dist2[i][0]<<" "<<dist2[i][1]<<endl;
// }

// Zhan's Blender
// void solve(){
// 	int n;cin>>n;
// 	int x,y;cin>>x>>y;
// 	if(x>=y) cout<<(n+y-1)/y<<endl;
// 	else  cout<<(n+x-1)/x<<endl;
// }

// Battle for Survive
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int num = arr[n-2];
// 	for(int i=n-3;i>=0;i--) num -=arr[i];
// 	int ans = arr[n-1]-num;
// 	cout<<ans<<endl;
// }

// Password Cracking
// void solve(){
// 	int n;cin>>n;
// 	string ans ="";
// 	bool flag = true;
// 	while(ans.size()<n){
// 		if(flag){
// 			string temp = ans + "0";
// 			cout<<"? "<<temp<<endl;
// 			cout.flush();
// 			bool x;cin>>x;
// 			if(x){
// 				ans = ans + "0";
// 				continue;
// 			}else{
// 				temp = ans + "1";
// 				cout<<"? "<<temp<<endl;
// 				cout.flush();
// 				cin>>x;
// 				if(x){
// 					ans = ans + "1";
// 					continue;
// 				}else{
// 					flag = false;
// 					temp = "0" + ans;
// 					cout<<"? "<<temp<<endl;
// 					cout.flush();
// 					cin>>x;
// 					if(x) ans = "0"+ans;
// 					else ans = "1"+ans;
// 				}
// 			}
// 		}else{
// 			string temp = "0"+ans;
// 			cout<<"? "<<temp<<endl;
// 			cout.flush();
// 			bool x;cin>>x;
// 			if(x) ans = "0"+ans;
// 			else ans = "1"+ans;
// 		}
// 	}
// 	cout<<"! "<<ans<<endl;
// 	cout.flush();
// }

// Minimize the Difference
// bool check1(int arr[],int n,int mx){
// 	int extra = 0;
// 	for(int i=0;i<n;i++){
// 		if(arr[i]>=mx) extra+=(arr[i]-mx);
// 		else{
// 			if(extra>0) extra-=min(extra,(mx-arr[i]));
// 		}
// 	}
// 	if(extra>0) return false;
// 	return true;
// }

// bool check2(int arr[],int n,int mn){
// 	int extra = 0;
// 	for(int i=0;i<n;i++){
// 		if(arr[i]>=mn) extra += (arr[i]-mn);
// 		else{
// 			int req = (mn-arr[i]);
// 			if(req>extra) return false;
// 			else extra-=req;
// 		}
// 	}
// 	return true;
// }

// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int lo=0,hi = 1e18;
// 	while(lo<=hi){
// 		int mid = (lo+hi)/2;
// 		if(check1(arr,n,mid)) hi = mid-1;
// 		else lo = mid+1;
// 	}
// 	int mx = lo;
// 	lo=0,hi = 1e18;
// 	while(lo<=hi){
// 		int mid = (lo+hi)/2;
// 		if(check2(arr,n,mid)) lo = mid+1;
// 		else hi = mid-1;
// 	}
// 	int mn = hi;
// 	cout<<abs(mx-mn)<<endl;
// }

// Klever Permutation
// void solve(){
// 	int n,k;cin>>n>>k;
// 	vector<int> ans(n+1,0);
// 	int even = 1,odd = n;
// 	for(int i=1;i<=k;i++){
// 		for(int j=i;j<=n;j+=k){
// 			if(i&1) ans[j] = odd,odd--;
// 			else ans[j] = even,even++;
// 		}
// 	}
// 	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
// 	cout<<endl;
// }

// Find the Different Ones!
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	vector<int> diff(n+1,0);
// 	int prev = n;
// 	for(int i=n;i>=1;i--){
// 		if(arr[i-1]!=arr[prev-1]) diff[prev]=i,prev = i;
// 	}
// 	for(int i=n-1;i>=2;i--){
// 		if(diff[i]==0){
// 			if(arr[i]==arr[i-1]) diff[i] = diff[i+1];
// 		}
// 	}
// 	int q;cin>>q;
// 	while(q--){
// 		int l,r;
// 		cin>>l>>r;
// 		int point = diff[r];
// 		if(point>=l) cout<<point<<" "<<r<<endl;
// 		else cout<<-1<<" "<<-1<<endl;
// 	}
// 	cout<<endl;
// }

// Squaring
// using the prefix operation
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int last = 0,ans = 0;
// 	for(int i=1;i<n;i++){
// 		int prev = arr[i-1],cur=arr[i];
// 		int c1 = 0,c2 = 0;
// 		while(cur<prev){
// 			if(cur == 1){
// 				cout<<-1<<endl;
// 				return;
// 			}
// 			c1++;
// 			cur *= cur;
// 		}
// 		while(prev*prev<=cur){
// 			if(prev==1){
// 				c2 = -1;
// 				break;
// 			}
// 			c2++;
// 			prev *= prev;
// 		}
// 		if(c1>0) last+=c1;
// 		else if(c2==-1) last = 0;
// 		else last = max(0ll,last-c2);
// 		ans += last;
// 	}
// 	cout<<ans<<endl;
// }

// using the mathematical approach
// int diff = 1e-10;
// void solve(){
// 	int n;cin>>n;
// 	li arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	li b[n];
// 	for(int i=0;i<n;i++){
// 		if(arr[i]==1){
// 			b[i] = -1;
// 			continue;
// 		}
// 		b[i] = log2(log2(arr[i]));
// 	}
// 	int  ans = 0;
// 	for(int i=1;i<n;i++){
// 		if(b[i]<b[i-1]){
// 			if(arr[i]==1){
// 				cout<<-1<<endl;
// 				return;
// 			}
// 			li op = (li)ceil(b[i-1]-b[i]);
// 			b[i]+=op;
// 			ans += op;
// 		}
// 	}
// 	cout<<ans<<endl;
// }

void solve(){
	
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}