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
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ind = -1;
//     vector<int> v;
//     for(int i=0;i<n;i++){
//         if(arr[i]%2==0){
//             v.push_back(arr[i]);
//             ind = i;
//             break;
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(arr[i]&1){
//             v.push_back(arr[i]);
//         }
//     }
//     for(int i=0;i<n;i++){
//         if(arr[i]%2==0){
//             if(ind != i) v.push_back(arr[i]);
//         }
//     }
//     int sum = 0,ans = 0;
//     for(int i=0;i<n;i++){
//         sum +=v[i];
//         if(sum%2==0){
//             ans++;
//             while(sum%2==0) sum>>=1;
//         }
//     }
//     cout<<ans<<endl;
// }

// bool check(int num1,int num2,int num3,int num4){
//     if(num1+num2+num3<=num4) return false;
//     if(num1+num2+num4<=num3) return false;
//     if(num1+num3+num4<=num2) return false;
//     if(num2+num3+num4<=num1) return false;

//     return true;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     map<int,int> freq;
//     for(int i=0;i<n;i++) cin>>arr[i],freq[arr[i]]++;
//     sort(arr,arr+n);

//     for(int i=0;i<n-1;i++){
//         if(arr[i] == arr[i+1]){
//             int req = 2*arr[i];
//             if(i!=0 && i+2!=n){
//                 int prev = arr[i-1];
//                 int next = arr[i+2];
//                 int taken = next-prev;
//                 if(taken<req){
//                     cout<<prev<<" "<<arr[i]<<" "<<arr[i]<<" "<<next<<endl;
//                     return;
//                 }
//             }
//             for(int j=0;j<n-1;j++){
//                 if(j==i || j==i+1) continue;
//                 if(j+1==i) continue;
//                 int taken = arr[j+1]-arr[j];
//                 if(taken < req){
//                     cout<<arr[i]<<" "<<arr[i]<<" "<<arr[j]<<" "<<arr[j+1]<<endl;
//                     return;
//                 }
//             }
//         }
//     }

//     cout<<-1<<endl;
// }

// dp i,j --> no. of configurations till i th position , j if the i th person is liar/truth
int mod = 998244353;

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
// 	map<pair<int,int>,int> odp;

// 	if(n==1){
// 		if(arr[0] == 0) cout<<2<<endl;
// 		else cout<<1<<endl;
// 		return;
// 	}

// 	// (i --> no. of liars till point x,where x is j th person)
// 	// dp(i,j) --> represesn the configuration for value (i,j)
// 	// base case
// 	if(arr[0] == 0){
// 		odp[{0,0}] = 1;
// 		odp[{1,1}] = 1;
// 	}else{
// 		odp[{1,1}] = 1;
// 	}

// 	for(int i=1;i<n;i++){
// 		map<pair<int,int>,int> dp;
// 		// if i th guy is honest
// 		dp[{arr[i],0}] = (odp[{arr[i],0}] + odp[{arr[i],1}])%mod;
// 		// if i th guy is Liar
// 		dp[{arr[i-1]+1,1}] = odp[{arr[i-1],0}];
// 		odp = dp;
// 	}
// 	int ans = (odp[{arr[n-1],0}] + odp[{arr[n-2]+1,1}])%mod;
// 	cout<<ans<<endl;
// }

// i --> ind, j-->the nature of the person
// dp(i,j) total no. of configurations till i th person of j th type
// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	for(int i=0;i<n;i++) cin>>arr[i];
// 	if(n==1){
// 		if(arr[0] == 0) cout<<2<<endl;
// 		else cout<<1<<endl;
// 		return;
// 	}

// 	vector<vector<int>> dp(n,vector<int>(2,0));
// 	// base case
// 	if(arr[0] == 0){
// 		dp[0][0] = 1;
// 		dp[0][1] = 1;
// 	}else dp[0][1] = 1;

// 	if(arr[0]==0 && arr[1] == 0){
// 		dp[1][0] = dp[0][0];
// 		dp[1][1] = dp[0][0];
// 	}else if(arr[0] == 0 && arr[1] == 1){
// 		dp[1][0] = dp[0][1];
// 		dp[1][1] = dp[0][0];
// 	}else if(arr[0] == 1 && arr[1] == 0){
// 		dp[1][0] = 0;
// 		dp[1][1] = 0;
// 	}else if(arr[0] == 1 && arr[1] == 1) {
// 		dp[1][0] = dp[0][1];
// 		dp[1][1] = 0;
// 	}

// 	if(arr[0]>1 && arr[1]==0){
// 		dp[1][0] = 0;
// 		dp[1][1] = 0;
// 	}
// 	if(arr[0]==0 && arr[1]>1){
// 		dp[1][0] = 0;
// 		dp[1][1] = 1;
// 	}
// 	if(arr[0]>1 && arr[1]==1){
// 		dp[1][0] = 1;
// 		dp[1][1] = 0;
// 	}
// 	if(arr[0]==1 && arr[1]>1){
// 		dp[1][0] = 0;
// 		dp[1][1] = 0;
// 	}
// 	if(arr[0] > 1 && arr[1] > 1){
// 		dp[1][0] = 0;
// 		dp[1][1] = 0;
// 	}

// 	for(int i=2;i<n;i++){
// 		// i the person honest
// 		if(arr[i] == arr[i-1]){
// 			dp[i][0] = dp[i-1][0];
// 		}

// 		if(arr[i-2]+1==arr[i]) dp[i][0] = (dp[i][0] + dp[i-1][1])%mod;

// 		// i th person liar
// 		dp[i][1] = dp[i-1][0];
// 	}

// 	cout<<(dp[n-1][1] + dp[n-1][0])%mod<<endl;
// }

// Kevin and Numbers
// void solve(){
// 	int n,m;
// 	cin>>n>>m;
// 	int a[n],b[m];

// 	multiset<int> s1,s2;
// 	for(int i=0;i<n;i++) cin>>a[i],s1.insert(a[i]);
// 	for(int j=0;j<m;j++) cin>>b[j],s2.insert(b[j]);

// 	if(m>n){
// 		cout<<"No"<<endl;
// 		return;
// 	}

// 	for(int i=0;i<n;i++){
// 		if(s2.find(a[i])!=s2.end()){
// 			s1.erase(s1.find(a[i]));
// 			s2.erase(s2.find(a[i]));
// 		}
// 	}

// 	// for(int ele : s1) cout<<ele<<" ";
// 	// cout<<endl;
// 	// for(int ele : s2) cout<<ele<<" ";
// 	// cout<<endl;

// 	for(int num2 : s2){
// 		int _min = *s1.begin();
// 		if(num2<_min){
// 			cout<<"No"<<endl;
// 			return;
// 		}

// 		vector<int> temp;
// 		temp.push_back(num2);
// 		while(temp.size()!=0){
// 			vector<int> temp2;
// 			for(int ele : temp){
// 				if(ele == 1){
// 					if(s1.find(ele)==s1.end()){
// 						cout<<"No"<<endl;
// 						return;
// 					}else s1.erase(s1.find(1));
// 					_min = *s1.begin();
// 					continue;
// 				}

// 				if(ele < _min || temp.size() > 1e6){
// 					cout<<"No"<<endl;
// 					return;
// 				}
// 				// cout<<ele<<" "<<_min<<endl;

// 				if(s1.find(ele)!=s1.end()){
// 					s1.erase(s1.find(ele));
// 					_min = *s1.begin();
// 				}else{
// 					int x,y;
// 					if(ele&1) x = ele/2,y = x+1;
// 					else x = ele/2,y = x;
// 					temp2.push_back(x);
// 					temp2.push_back(y);
// 				}
// 				// for(int ele : temp2) cout<<ele<<" ";
// 				// cout<<endl;
// 			}
// 			temp = temp2;
// 		}
// 	}
// 	if(s1.size()==0) cout<<"Yes"<<endl;
// 	else cout<<"No"<<endl;
// }

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[n],b[m];
	int ans = 0;
	for(int i=0;i<n;i++) cin>>a[i] , ans+= a[i];
	for(int i=0;i<m;i++) cin>>b[i];

	vector<vector<int>> prefix(n,vector<int>(m+1,INT_MAX));

	vector<pair<int,int>> precompute((1<<m));

	for(int j=0;j<(1<<m);j++){
		int set_bits = 0;
		int num = (1<<30)-1;
		for(int k=0;k<m;k++){
			if(j&(1<<k)){
				set_bits++;
				num &= b[k];
			}
		}
		precompute[j] = {set_bits,num};
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<m);j++){
			int num = a[i] & precompute[j].second;
			int set_bits = precompute[j].first;
			prefix[i][set_bits] = min(prefix[i][set_bits],num);
		}
	}

	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){	
			int diff = prefix[i][j-1] - prefix[i][j];
			pq.push(diff);
		}
	}

	int req = k,sum = 0;
	while(req--){
		sum += pq.top();
		pq.pop();
	}
	ans -= sum;
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

    return 0;
}