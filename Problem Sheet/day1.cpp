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

// Turtle and an Infinite Sequence
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     if(m==0){
//         cout<<n<<endl;
//         return;
//     }
//     int ind = 0;
//     int num1 = max(0ll,n-m),num2 = n+m;
//     // cout<<num1<<" "<<num2<<endl;
//     for(int i=30;i>=0;i--){
//         if(((num1>>i)&1)==0 && ((num2>>i)&1)==1){
//             ind = i;
//             break;
//         }
//     }
//     int ans = 0;
//     for(int i=30;i>ind;i--){
//         if((num1>>i)&1) ans += (1<<i);
//     }
//     for(int i=ind;i>=0;i--) ans += (1<<i);
//     cout<<ans<<endl;
// }

// Permutation of Rows and Columns
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int a[n][m],b[n][m];
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cin>>a[i][j];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cin>>b[i][j];
//     }
//     // if(n==1 || m==1){
//     //     cout<<"Yes"<<endl;
//     //     return;
//     // }
//     set<set<int>> s1,s2;
//     for(int i=0;i<n;i++){
//         set<int> temp1,temp2;
//         for(int j=0;j<m;j++){
//             temp1.insert(a[i][j]);
//             temp2.insert(b[i][j]);
//         }
//         s1.insert(temp1);
//         s2.insert(temp2);
//     }
//     if(s1!=s2){
//         cout<<"No"<<endl;
//         return;
//     }
//     s1.clear(),s2.clear();
//     for(int j=0;j<m;j++){
//         set<int> temp1,temp2;
//         for(int i=0;i<n;i++){
//             temp1.insert(a[i][j]);
//             temp2.insert(b[i][j]);
//         }
//         s1.insert(temp1);
//         s2.insert(temp2);
//     }
//     if(s1!=s2){
//         cout<<"No"<<endl;
//         return;
//     }
//     cout<<"Yes"<<endl;
//     // map<int,int> mc,mr;
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<m;j++){
//     //         cin>>a[i][j];
//     //         mr[a[i][j]] = i;
//     //         mc[a[i][j]] = j;
//     //     }
//     // }
//     // map<pair<int,int>,int> cntr,cntc;
//     // for(int i=0;i<n;i++){
//     //     for(int j=0;j<m;j++){
//     //         cin>>b[i][j];
//     //         if(mc[b[i][j]]!=j){
//     //             cntc[{j,mc[b[i][j]]}]++;
//     //         }
//     //         if(mr[b[i][j]]!=i){
//     //             cntr[{i,mr[b[i][j]]}]++;
//     //         }
//     //     }
//     // }
//     // bool ans = 1;
//     // for(auto ele : cntr){
//     //     ans &= (ele.second==m);
//     // }
//     // for(auto ele : cntc){
//     //     ans &= (ele.second==n);
//     // }

//     // if(ans)cout<<"Yes"<<endl;
//     // else cout<<"No"<<endl;
    
// }

// GCD-sequence
// bool sorted(vector<int> &a){
//     int n = a.size();
//     for(int i=1;i<n;i++){
//         if(a[i-1]>a[i]) return false;
//     }
//     return true;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ind = -1,prev = -1;
//     for(int i=0;i<n-1;i++){
//         int gcd = __gcd(arr[i],arr[i+1]);
//         if(prev>gcd){
//             ind = i;
//             break;
//         }
//         prev = gcd;
//     }
//     if(ind==-1){
//         cout<<"Yes"<<endl;
//         return;
//     }
//     // cout<<ind<<endl;
//     vector<int> a,b,c;
//     for(int i=0;i<n;i++){
//         if(i!=ind-1){
//             int nxt = i+1;
//             if(nxt==ind-1) nxt++;
//             if(nxt<n) a.push_back(__gcd(arr[nxt],arr[i]));
//         }
//         if(i!=ind){
//             int nxt = i+1;
//             if(nxt==ind) nxt++;
//             if(nxt<n) b.push_back(__gcd(arr[nxt],arr[i]));
//         }
//         if(i!=ind+1){
//             int nxt = i+1;
//             if(nxt==ind+1) nxt++;
//             if(nxt<n) c.push_back(__gcd(arr[nxt],arr[i]));
//         }
//     }
//     // for(int ele : c) cout<<ele<<" ";
//     // cout<<endl;
//     bool ans = 0;
//     ans |= sorted(a);
//     ans |= sorted(b);
//     ans |= sorted(c);
//     if(ans) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Sofia and the Lost Operations
// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     set<int> st;
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i],st.insert(b[i]);
//     int m;cin>>m;
//     int d[m];
//     map<int,int> mp;
//     for(int i=0;i<m;i++){
//         cin>>d[i];
//         mp[d[i]]++;
//     }
//     int ind = -1;
//     for(int i=0;i<m;i++){
//         if(st.find(d[i])==st.end()) ind = i;
//     }
//     if(ind == m-1){
//         cout<<"No"<<endl;
//         return;
//     }
//     for(int i=0;i<n;i++){
//         if(a[i] != b[i]){
//             if(mp[b[i]] == 0){
//                 cout<<"No"<<endl;
//                 return;
//             }
//             mp[b[i]]--;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// Job Interview
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<int> p(n+m+1),t(n+m+1);
//     for(int i=0;i<=n+m;i++) cin>>p[i];
//     for(int i=0;i<=n+m;i++) cin>>t[i];
//     int pro = 0,test = 0,buffer = -1,sum= 0;
// 	set<int> program,tester;
//     for(int i=0;i<=n+m;i++){
//         if(p[i]>t[i]){
// 			if(pro<n){
// 				sum += p[i];
// 				program.insert(i);
// 				pro++;
// 			}else{
// 				if(buffer == -1) buffer = i;
// 				else{
// 					sum += t[i];
// 					tester.insert(i);
// 					test++;
// 				}
// 			}
// 		}else{
// 			if(test<m){
// 				sum += t[i];
// 				tester.insert(i);
// 				test++;
// 			}else{
// 				if(buffer == -1) buffer = i;
// 				else{
// 			sum += p[i];
// 					program.insert(i);
// 					pro++;
// 				}
// 			}
// 		}
//     }
// 	vector<int> ans;
// 	for(int i=0;i<n+m+1;i++){
// 		if(i == buffer) ans.push_back(sum);
// 		else{
// 			if(tester.find(i)==tester.end()){
// 				int temp = sum;
// 				temp -= p[i];
// 				temp += p[buffer];
// 				ans.push_back(temp);
// 			}else{
// 				int temp = sum;
// 				temp -= t[i];
// 				temp += t[buffer];
// 				ans.push_back(temp);
// 			}
// 		}
// 	}

// 	for(int ele : ans) cout<<ele<<" ";
// 	cout<<endl;
// }

// Paint the Tree
// void dfs(int node,int par,vector<int> adj[],int b,vector<int> &temp,vector<int> &ans){
// 	temp.push_back(node);
// 	if(node == b){
// 		ans = temp;
// 		return;
// 	}

// 	for(int it : adj[node]){
// 		if(it == par) continue;
// 		dfs(it,node,adj,b,temp,ans);
// 	}
// 	temp.pop_back();
// }

// int dfs2(int node,int par,vector<int> adj[]){
// 	int dis = 1;
// 	for(int it : adj[node]){
// 		if(it == par) continue;
// 		dis = max(dis,dfs2(it,node,adj)+1);
// 	}
// 	return dis;
// }

// void solve(){
// 	int n;cin>>n;
// 	int a,b;cin>>a>>b;
// 	vector<int> adj[n+1];
// 	for(int i=0;i<n-1;i++){
// 		int u,v;
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}

// 	vector<int> path,temp;
// 	dfs(a,-1,adj,b,temp,path);
// 	int ind = (path.size()-1)/2;
// 	int d = dfs2(path[ind],-1,adj);
// 	int ans = (2*(n-1)-d) + (path.size()-ind);
// 	cout<<ans<<endl;
// }

// Beautiful Triple Pairs
void solve(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	map<pair<int,pair<int,int>>,int> mp;
	for(int i=0;i<n-2;i++){
		mp[{arr[i],{arr[i+1],arr[i+2]}}]++;
		mp[{-1,{arr[i+1],arr[i+2]}}]++;
		mp[{arr[i],{-1,arr[i+2]}}]++;
		mp[{arr[i],{arr[i+1],-1}}]++;
	}
	int ans = 0;
	for(int i=0;i<n-2;i++){
		int f = arr[i];
		int s = arr[i+1];
		int t = arr[i+2];
		int total = mp[{arr[i],{arr[i+1],arr[i+2]}}];
		// cout<<total<<" "<<mp[{-1,{arr[i+1],arr[i+2]}}]<<" "<<mp[{arr[i],{-1,arr[i+2]}}]<<" "<<mp[{arr[i],{arr[i+1],-1}}]<<endl;
		ans += (mp[{-1,{arr[i+1],arr[i+2]}}]-total);
		ans += (mp[{arr[i],{-1,arr[i+2]}}]-total);
		ans += (mp[{arr[i],{arr[i+1],-1}}]-total);

	}
	cout<<ans/2<<endl;
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