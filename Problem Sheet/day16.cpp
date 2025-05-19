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
//     for(int i=1;i<=n;i++) cout<<2*i-1<<" ";
//     cout<<endl;
// }

// void solve(){
//     string s;cin>>s;
//     int n = s.size();
//     if(n==1){
//         cout<<-1<<endl;
//         return;
//     }
//     for(int i=0;i<n-1;i++){
//         if(s[i] == s[i+1]){
//             cout<<s[i]<<s[i]<<endl;
//             return;
//         }
//     }
//     for(int i=0;i<n-2;i++){
//         if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2]){
//             cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
//             return;
//         }
//     }
//     cout<<-1<<endl;
// }

// void solve(){
//     int x,m;
//     cin>>x>>m;
//     int num = 2*x+1;
//     num = min(num,m);
//     int ans = 0;
//     for(int i=1;i<=num;i++){
//         if(i==x) continue;
//         int xo = (i^x);
//         if(x%xo == 0 || i%xo == 0) ans++;
//     }
//     cout<<ans<<endl;
// }

// Shohag Loves XOR (Hard Version)
// void solve(){
// 	int x,m;
// 	cin>>x>>m;
// 	int ans = 0;
// 	for(int i=1;i<2*x && i<=m;i++){
// 		int z = i^x;
// 		if(z%x == 0 || z%i == 0){
// 			if(z<2*x) ans++;
// 		}
// 	}

// 	int rem = m-x;
// 	if(rem>=2*x){
// 		ans += rem/x;
// 		ans -= (2*x-1)/x;
// 	}
// 	for(int z=m-x+1;z<=m+x;z++){
// 		if(z%x) continue;
// 		int y = z^x;
// 		if(y>=1 && y<=m) ans++;
// 	}
// 	cout<<ans<<endl;
// }

// void solve(){
// 	int n;cin>>n;
// 	int arr[n+1];
// 	for(int i=1;i<=n;i++) cin>>arr[i];
// 	int cnt0 = 0,cnt1 = 0,cnt2 = 0,one = 0;
// 	for(int i=1;i<=n;i++){
// 		if(arr[i] == 0) cnt0++;
// 		else if(arr[i] == 2) cnt2++;
// 		else{
// 			cnt1++;
// 			one = i;
// 		}
// 	}
// 	vector<pair<int,int>> uw;
// 	vector<pair<int,int>> ans;
// 	for(int i=1;i<=cnt0;i++){
// 		if(arr[i] !=0){
// 			uw.push_back({arr[i],i});
// 		}
// 	}
// 	sort(uw.begin(),uw.end());
// 	// for(auto it : uw) cout<<it.first<<" "<<it.second<<endl;
// 	reverse(uw.begin(),uw.end());
// 	for(int i=cnt0+1;i<=n;i++){
// 		if(arr[i] == 0){
// 			int ind = uw[uw.size()-1].second;
// 			// cout<<ind<<endl;
// 			uw.pop_back();
// 			if(arr[ind]==1){
// 			    // cout<<i<<"*"<<endl;
// 				ans.push_back({ind,i});
// 				swap(arr[i],arr[ind]);
// 			}else{
// 			    // cout<<ind<<endl;
// 				ans.push_back({ind,one});
// 				swap(arr[ind],arr[one]);
// 				ans.push_back({ind,i});
// 				swap(arr[ind],arr[i]);
// 			}
// 			one=i;
// 		}
// 	}
// 	for(int i=cnt0+1;i<=cnt0+cnt1;i++){
// 		if(arr[i]==2) uw.push_back({arr[i],i});
// 	}
// 	for(int i=cnt0+cnt1+1;i<=n;i++){
// 		if(arr[i] == 1){
// 			int ind = uw[uw.size()-1].second;
// 			ans.push_back({ind,i});
// 			swap(arr[ind],arr[i]);
// 			uw.pop_back();
// 		}
// 	}
// 	cout<<ans.size()<<endl;
// 	for(auto it : ans) cout<<it.first<<" "<<it.second<<nline;
// }

// Move Back at a Cost
// void solve(){
// 	int n;cin>>n;
// 	priority_queue<pair<int,int>> pq;
// 	for(int i=0;i<n;i++){
// 		int x;cin>>x;
// 		pq.push({-x,i});
// 	}
// 	while(!pq.empty()){
// 		int ele = -pq.top().first;
// 		int ind = pq.top().second;
// 		pq.pop();
// 		cout<<ele<<" ";
// 		while(!pq.empty() && pq.top().second>=ind){
// 			cout<<-pq.top().first<<" ";
// 			pq.pop();
// 		}
// 	}
// }

int numUniqueEmails(const vector<string> &emails){
	set<string> s;
	int n = emails.size();
	for(auto &ele : emails){
		int sz = ele.size();
		string temp;
		bool flag = false,flg2 = true;
		for(int i=0;i<sz;i++){
			if(flag){
				if(ele[i] == '@') flag = false,temp.push_back(ele[i]),flg2 = false;
				continue;
			}
			if(ele[i] == '@') flg2 = false;
			if(ele[i] == '.' && flg2) continue;
			else if(ele[i] == '+') flag = true;
			else temp.push_back(ele[i]);
		}
		cout<<temp<<endl;
		s.insert(temp);
	}
	return s.size();
}

void solve(){
	int n;cin>>n;
	vector<string> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<numUniqueEmails(v)<<endl;
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