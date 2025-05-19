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
//     int _max = *max_element(arr,arr+n);
//     bool odd = false,even = false;
//     for(int i=0;i<n;i++){
//         if(arr[i]==_max){
//             if(i&1) odd = true;
//             else even = true;
//         }
//     }
//     int ans = _max;
//     if(even) ans += (n+1)/2;
//     else ans += n/2;
//     cout<<ans<<endl;
// }

// All Pairs Segments
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     map<int,int> mp;
//     for(int i=0;i<n;i++) cin>>arr[i];
//     mp[n-1] = 1;
//     for(int i=1;i<n;i++){
//         mp[i*(n-i+1)-1]++;
//         mp[i*(n-i)] += (arr[i]-arr[i-1]-1);
//     }
//     for(int i=0;i<k;i++){
//         int temp;cin>>temp;
//         cout<<mp[temp]<<" ";
//     }
//     cout<<nline;
// }

// Cards Partition
// pigeon hole principle
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int total = 0;
//     for(int i=0;i<n;i++) total += arr[i];
//     int _min = *max_element(arr,arr+n);
//     int ans = 1;
//     for(int i=2;i<=n;i++){
//         int decks = (total+i-1)/i;
//         int left = k;
//         left -= (decks*i)-total;
//         if(left<0) continue;
//         if(decks<_min){
//             left -= (_min-decks)*i;
//             if(left<0) continue;
//         }
//         ans = i;
//     }
//     cout<<ans<<nline;
// }

// Tree Pruning
// maximum depth of each node
// void maxdepth(int node,int par,vector<int> adj[],vector<int> &v,int d){
// 	v[node] = d;
// 	for(int ele : adj[node]){
// 		if(ele == par) continue;
// 		maxdepth(ele,node,adj,v,d+1);
// 		v[node] = max(v[node],v[ele]);
// 	}
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
// 	map<int,int> mp;
// 	vector<int> v(n+1,0),prefix(n+1,0),suffix(n+1,0);
// 	maxdepth(1,0,adj,v,0);
// 	for(int i=2;i<=n;i++) mp[v[i]]++;
// 	for(int i=1;i<=n;i++) prefix[i] = mp[i] + prefix[i-1];
// 	mp.clear();
// 	// no. of nodes at different levels
// 	queue<pair<int,pair<int,int>>> q;
// 	q.push({0,{1,0}});
// 	while(!q.empty()){
// 		int lvl = q.front().first;
// 		int node = q.front().second.first;
// 		int par = q.front().second.second;
// 		q.pop();
// 		for(int ele : adj[node]){
// 			if(ele == par) continue;
// 			mp[lvl+1]++;
// 			q.push({lvl+1,{ele,node}});
// 		}
// 	}
// 	// calculating the operation to make all the leaf node at level i
// 	for(int i=n-1;i>=1;i--) suffix[i] = suffix[i+1]+mp[i];
// 	int ans = INT_MAX;
// 	for(int i=1;i<n;i++){
// 		int op = prefix[i-1] + suffix[i+1];
// 		ans = min(ans,op);
// 	}
// 	cout<<ans<<endl;
// }

// Add 1 or 2 Game
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	if(n==1){
// 		cout<<0<<endl;
// 		return;
// 	}
// 	sort(arr,arr+n);
// 	vector<pair<int,int>> vp,merge;
// 	for(int i=1;i<n;i++){
// 		vp.push_back({arr[i]-arr[i-1]+1,arr[i]+arr[i-1]-1});
// 	}
// 	sort(vp.begin(),vp.end());
// 	int l=-1,r=-1;
// 	for(int i=0;i<vp.size();i++){
// 		if(l==-1) l=vp[i].first,r=vp[i].second;
// 		else{
// 			if(vp[i].first<=r) l = min(vp[i].first,l),r = max(vp[i].second,r);
// 			else{
// 				merge.push_back({l,r});
// 				l = vp[i].first,r = vp[i].second;
// 			}
// 		}
// 	}
// 	merge.push_back({l,r});
// 	int ans = 0;
// 	for(int i=0;i<merge.size();i++) ans += (merge[i].second-merge[i].first+1);
// 	cout<<ans<<endl;
// }

// Count Winning Subarrays
// void solve(){
// 	int n;cin>>n;
// 	int arr[n+1];
// 	for(int i=1;i<=n;i++) cin>>arr[i];
// 	int ans=0,left = 1;
// 	for(int i=1;i<=n;i++) if(arr[i]==1) ans++;
// 	for(int i=1;i<n;i++){
// 		if(arr[i]==1 && arr[i+1]==1){
// 			ans += (i-left+1)*(n-i);
// 			left = i+1;
// 		}else if(i<n-1){
// 			if(arr[i]==1 && arr[i+2]==1){
// 				ans += (i-left+1)*(n-i-1);
// 				left = i+1;
// 			}
// 		}
// 	}
// 	cout<<ans<<endl;
// }

// Direction Change
// void solve(){
// 	int a,b;
// 	cin>>a>>b;
// 	if(b>a) swap(a,b);
// 	if(b==1){
// 		if(a>2){
// 			cout<<-1<<endl;
// 			return;
// 		}
// 		if(a==2){
// 			cout<<1<<endl;
// 			return;
// 		}
// 		if(a==1){
// 			cout<<0<<endl;
// 			return;
// 		}
// 	}

// 	if(a==b){
// 		cout<<2*(b-1)<<endl;
// 	}else{
// 		int dis = 2*(b-1);
// 		int left = ((a-b)/2)*4;
// 		if((a-b)&1) left++;
// 		cout<<dis+left<<endl;
// 	}
// }

// Social Distance
// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	if(n>m){
// 		cout<<"No"<<endl;
// 		return;
// 	}
// 	sort(arr,arr+n);
// 	int total = 0;
// 	if(n==1) total += 2*(arr[0])+1;
// 	else{
// 		total = 1; // for 1 st person sitting
// 		for(int i=1;i<n-1;i++){
// 			total += arr[i]+1;
// 		}
// 		total += (2*arr[n-1])+1;
// 	}
// 	if(total<=m) cout<<"Yes"<<endl;
// 	else cout<<"No"<<endl;
// }

// Make it Increasing
// int look(int arr[],int n,int ind){
// 	int prev=0,mov = 0,next = 0;
// 	for(int i=ind-1;i>=0;i--){
// 		if(arr[i]>prev){
// 			mov++;
// 			prev = arr[i];
// 		}else{
// 			int req = (prev+arr[i])/arr[i];
// 			mov += req;
// 			prev = arr[i]*req;
// 		}
// 	}
// 	for(int i=ind+1;i<n;i++){
// 		if(arr[i]>next){
// 			mov++;
// 			next = arr[i];
// 		}else{
// 			int req = (next+arr[i])/arr[i];
// 			mov += req;
// 			next = arr[i]*req;
// 		}
// 	}
// 	return mov;
// }

// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	int ans = 1e18;
// 	for(int i=0;i<n;i++){
// 		int local = look(arr,n,i);
// 		ans = min(ans,local);
// 	}
// 	cout<<ans<<endl;
// }

// Colorful Tree (Easy Version)
// void solve(){
// 	int n;cin>>n;
// 	vector<int> adj[n+1];
// 	for(int i=0;i<n-1;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// 	int ans = 0;
// 	for(int i=1;i<=n;i++){
// 		if(adj[i].size()>1) ans+=2;
// 		else ans+=3;
// 	}
// 	cout<<ans<<endl;
// }

// Vlad and an Odd Ordering
// void solve(){
//     int n,k;
// 	cin>>n>>k;
// 	int out = (n+1)/2,two = 1,total = n;
// 	while(k>out){
// 		k-=out;
// 		total = total-out;
// 		out =(total+1)/2;
// 		two*=2;
// 	}
// 	int num = 1 + (k-1)*2;
// 	int ans = two*(num);
// 	cout<<ans<<endl;
// }

// Xometry (Easy Version)
vector<int> cnt(2e6+5);
void solve(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans += 8*cnt[arr[i]^arr[j]];
			cnt[arr[i]^arr[j]]++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cnt[arr[i]^arr[j]]--;
		}
	}
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

	// solve();

    return 0;
}