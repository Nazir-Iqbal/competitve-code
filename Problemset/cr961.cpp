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
//     int n,k;
// 	cin>>n>>k;
// 	int ans = 0;
// 	if(k==0){
// 		cout<<0<<endl;
// 		return;
// 	}
// 	if(k<=n){
// 		cout<<1<<endl;
// 		return;
// 	}
// 	k-=n,ans++;
// 	for(int i=n-1;i>=1;i--){
// 		k-=i;
// 		ans++;
// 		if(k<=0) break;
// 		k-=i;
// 		ans++;
// 		if(k<=0) break;
// 	}
// 	cout<<ans<<endl;
// }

// Bouquet (Hard Version)
void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp[arr[i]]++;
	}
		
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		mp[arr[i]]= temp;
	}
	sort(arr,arr+n);
	int prev = -1,ans = 0;
	for(auto ele : mp){
		int cur = ele.first;
		int freq = min(ele.second,m/cur);
		int total = freq*cur;
		// choosing all the same flowers
		ans = max(ans,total);
		if(prev==-1){
			prev = cur;
			continue;
		}
		// choosing the prev flower
		// cout<<prev<<" "<<cur<<endl;
		if(cur-prev==1){
			int freq2 = min(mp[prev],m/prev);
			total = freq2*prev;
			int left = m-total;
			int taken = min(mp[cur],left/cur);
			left -= (taken*cur);
			int getting = min(min(left,mp[cur]-taken),freq2);
			total += (taken*cur + getting);
			ans = max(ans,total);
		}
		prev = cur;
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

    return 0;
}