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

// Redundant Array
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     vector<int> hsn(n+1,0);
//     int ans = INT_MAX;
//     for(int i=0;i<n;i++) hsn[arr[i]]++;
//     for(int i=1;i<=n;i++){
//         ans = min(ans,(n-hsn[i])*i);
//     }
//     cout<<ans<<endl;
// }

// Amphibian Escape
// void solve(){
//     int n,k,h;
//     cin>>n>>k>>h;
// 	int ans = 0;
// 	for(int i=1;i<=n;i++){
// 		if(i>=h) ans += n;
// 		else{
// 			int calc = (i*k - h)/(k-1);
// 			ans += max(0ll,calc);
// 		}
// 	}
// 	cout<<ans<<endl;
// }

// Perfect Prefixes
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int ans = 0,sum = 0;
// 	// intitally calculated the no. of good permutations
// 	for(int i=1;i<=n;i++){
// 		int calc = (i*(i+1))/2;
// 		sum += arr[i-1];
// 		if(sum == calc) ans++;
// 	}
// 	vector<int> permu1,permu2,prefix(n,0);
// 	// calculating the prefix sum 
// 	prefix[0] = arr[0];
// 	for(int i=1;i<n;i++) prefix[i] = prefix[i-1] + arr[i];
// 	// cout<<ans<<"*"<<endl;
// 	for(int i=0;i<n;i+=2){
// 		if(n&1 && i==n-1) break;
// 		int earlier = 0;
// 		int sum1 = ((i+1)*(i+2))/2;
// 		if(prefix[i] == sum1) earlier++;
// 		int req1 = prefix[i] + arr[i+1] - arr[i];
// 		int later= 0;
// 		if(req1 == sum1) later++;
// 		permu1.push_back(later-earlier);
// 	}
// 	for(int i=1;i<n;i+=2){
// 		if(n%2==0 && i==n-1) break;
// 		int earlier = 0;
// 		int sum1 = ((i+1)*(i+2))/2;
// 		if(prefix[i] == sum1) earlier++;
// 		int req1 = prefix[i] + arr[i+1] - arr[i];
// 		int later= 0;
// 		if(req1 == sum1) later++;
// 		permu2.push_back(later-earlier);
// 	}

// 	// maximum sum array sum (kadane algorithm)
// 	int local1 = 0,local2 = 0,temp = 0;
// 	for(int i=0;i<permu1.size();i++){
// 		temp+=permu1[i];
// 		if(temp<0) temp = 0;
// 		local1 =max(temp,local1);
// 	}
// 	temp = 0;
// 	for(int i=0;i<permu2.size();i++){
// 		temp += permu2[i];
// 		if(temp<0) temp = 0;
// 		local2 = max(temp,local2);
// 	}
// 	ans += max(local1,local2);
// 	cout<<ans<<endl;
// }

// Possible Contender
bool check(int mid,int n,vector<int> &v){
	int c1 = 0,c2 = 0;
	for(int i=0;i<n;i++){
		if(v[i]<mid){
			c1++;
			// doing the compression of the all element in segment
			while(i<n && v[i]<mid) i++;
		}
		if(i>=n) break;
		if(v[i]>=mid) c2++;
	}
	// cout<<c1<<" "<<c2<<endl;
	if(c2>c1) return true;
	return false;
}

void solve(){
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	int range = *max_element(v.begin(),v.end());
	int lo = 1,hi = range;
	// applying the binary search on the answer
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(check(mid,n,v)) lo = mid+1;
		else hi = mid-1;
	}
	// cout<<check(3,n,v)<<endl;
	// cout<<hi<<endl;
	string ans;
	for(int i=0;i<n;i++){
		if(v[i]<=hi) ans.push_back('1');
		else ans.push_back('0');
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