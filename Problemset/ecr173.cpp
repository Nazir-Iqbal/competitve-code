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
//     if(n<4){
//         cout<<1<<endl;
//     }else{
//         int cur = 1;
//         while(n>3){
//             n /= 4;
//             cur<<=1;
//         }
//         cout<<cur<<endl;
//     }
// }

// Digits
// bool check(int n,int d){
//     int num = 1;
//     for(int i=1;i<=n;i++) num*=i;
//     // cout<<num<<" "<<n<<" "<<d<<endl;
//     num*=d;
//     return (num%9==0);
// }

// void solve(){
//     int n,d;cin>>n>>d;
//     vector<int> ans;
//     ans.push_back(1);
//     if(d%3==0 || (n>2)) ans.push_back(3);
//     if(d%5 == 0) ans.push_back(5);
//     if(d%7 == 0 || (n>2)) ans.push_back(7);
//     if(d%9==0 || (n>5) || (check(n,d))) ans.push_back(9);
//     for(int &ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Sums on Segments
// pair<int,int> f(int left,int right,int arr[]){
//     int l = arr[left],r = arr[left];
//     int sum = 0;
//     for(int i=left;i<=right;i++){
//         sum += arr[i];
//         if(sum < 0) sum = 0;
//         r = max(sum,r);
//     }
//     sum = 0;
//     for(int i=left;i<=right;i++){
//         sum += arr[i];
//         if(sum > 0) sum = 0;
//         l = min(l,sum);
//     }
//     return {l,r};
// }

// void merge(vector<pair<int,int>> &vp){
//     sort(vp.begin(),vp.end());

//     int l = vp[0].first, r = vp[0].second;
//     vector<pair<int,int>> temp;
//     for(int i=1;i<vp.size();i++){
//         if(vp[i].first <= r) r = max(r,vp[i].second);
//         else{
//             temp.push_back({l,r});
//             l = vp[i].first,r = vp[i].second;
//         }
//     }
//     temp.push_back({l,r});
//     vp = temp;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ind = -1;
//     for(int i=0;i<n;i++){
//         if(arr[i] != -1 && arr[i] != 1){
//             ind = i;
//             break;
//         }
//     }
//     vector<pair<int,int>>  vp;
//     vp.push_back({0,0});
//     if(ind == -1){
//         // cout<<"*"<<endl;
//         vp.push_back(f(0,n-1,arr));
//     }else{
//         if(ind != 0) vp.push_back(f(0,ind-1,arr));
//         if(ind != n-1) vp.push_back(f(ind+1,n-1,arr));
//         int l = arr[ind],r = arr[ind],cur = ind-1,sum = arr[ind];
//         while(cur>=0){
//             sum += arr[cur];
//             l = min(sum,l);
//             r = max(sum,r);
//             cur--;
//         }
//         cur = ind+1,sum = l;
//         while(cur<n){
//             sum += arr[cur];
//             l = min(sum,l);
//             cur++;
//         }
//         cur = ind+1,sum = r;
//         while(cur<n){
//             sum += arr[cur];
//             r = max(sum,r);
//             cur++;
//         }
//         vp.push_back({l,r});
//     }
//     merge(vp);
//     int cnt = 0;
//     for(int i=0;i<vp.size();i++) cnt += (vp[i].second - vp[i].first + 1);
//     cout<<cnt<<endl;
//     for(int i=0;i<vp.size();i++){
//         for(int j=vp[i].first;j<=vp[i].second;j++) cout<<j<<" ";
//     }
//     cout<<endl;
// }

// void solve(){
// 	int l,r,g;
// 	cin>>l>>r>>g;
// 	int nl = (l+g-1)/g;
// 	int nr = r/g;
// 	if(nl>=nr){
// 		if(nl == nr && nl == 1){
// 			cout<<nl*g<<" "<<nl*g<<endl;
// 			return;
// 		}
// 		cout<<-1<<" "<<-1<<endl;
// 		return;
// 	}
// 	// cout<<nl<<" "<<nr<<endl;
// 	int ansl = -1,ansr = -1;
// 	for(int i=nl;i<=min(nl+30,nr);i++){
// 		for(int j=nr;j>=max(nl,nr-30);j--){
// 			// cout<<i<<" "<<j<<endl;
// 			if(i>j) continue;
// 			if(__gcd(i,j)==1){
// 				if((j-i) > ansr-ansl){
// 					ansl = i;
// 					ansr = j;
// 				}
// 			}
// 		}
// 	}
// 	cout<<ansl*g<<" "<<ansr*g<<endl;
// }

// E. Matrix Transformation
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
	vis[node] = 1;
	pathVis[node] = 1;

	// traverse for adjacent nodes
	for (auto it : adj[node]) {
		// when the node is not visited
		if (!vis[it]) {
			if (dfsCheck(it, adj, vis, pathVis) == true)
				return true;
		}
		// if the node has been previously visited
		// but it has to be visited on the same path
		else if (pathVis[it]) {
			return true;
		}
	}

	pathVis[node] = 0;
	return false;
}

bool cycle(vector<int> adj[],int n,int m,int node){
	int vis[n+m+1] = {0};
	int pathVis[n+m+1] = {0};
	return dfsCheck(node,adj,vis,pathVis);
}

int getBit(int num,int bit){
	return (num>>bit)&1;
}

bool check(vector<vector<int>> &a,vector<vector<int>> &b,int k){
	int n = a.size();
	int m = a[0].size();
	vector<int> adj[n+m+1];
	vector<bool> mustrow(n+1,0);
	vector<bool> mustcol(m+1,0);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(getBit(a[i][j],k) != getBit(b[i][j],k)){
				if(getBit(a[i][j],k)) mustrow[i] = 1;
				else mustcol[j] = 1;
			}
			if(getBit(b[i][j],k)==0) adj[j+n].push_back(i);
			else adj[i].push_back(j+n);
		}
	}

	for(int i=0;i<n;i++){
		if(mustrow[i] && cycle(adj,n,m,i)) return false;
	}
	for(int j=0;j<m;j++){
		if(mustcol[j] && cycle(adj,n,m,j+n)) return false;
	}
	return true;
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	vector<vector<int>> b(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>a[i][j];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>b[i][j];
	}

	for(int i=30;i>=0;i--){
		if(!check(a,b,i)){
			cout<<"No"<<endl;
			return;
		}
	}
	cout<<"Yes"<<endl;
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