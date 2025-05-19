#include <bits/stdc++.h>
using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// #define lld double
const int MOD = 998244353;
#define int long long
struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

// lld get(vector<lld> &c,vector<vector<lld>> &cost,lld val,vector<lld> &dp){
// 	if(val<=0) return 0.0;
// 	if(dp[val]!=-1) return dp[val];
// 	lld ans = 1e18;
// 	for(int i=0;i<cost.size();i++){
// 		lld res = 0,zero = 0;
// 		for(int j=0;j<cost[i].size();j++){
// 			if(cost[i][j] == 0){
// 				zero++;
// 				continue;
// 			}
// 			res += get(c,cost,val-cost[i][j],dp);
// 		}
// 		lld len = cost[i].size();
// 		res = res/len + c[i];
// 		lld spin = len/(len-zero);
// 		res *= spin;
// 		ans = min(ans,res);
// 	}
// 	// cout<<val<<" "<<cost.size()<<" "<<ans<<endl;
// 	return dp[val] = ans; 
// }

// void solve(){
//     int n;
// 	lld m;
// 	cin>>n>>m;
// 	vector<lld> c;
// 	vector<vector<lld>> cp;
// 	for(int i=0;i<n;i++){
// 		int ci;cin>>ci;
// 		c.push_back(ci);
// 		int len;cin>>len;
// 		vector<lld> temp(len);
// 		for(int j=0;j<len;j++) cin>>temp[j];
// 		cp.push_back(temp);
// 	}
// 	vector<lld> dp(m+1,-1);
// 	cout<<fixed<<setprecision(9)<<get(c,cp,m,dp)<<endl;
// }

// void solve(){
// 	string s;cin>>s;
// 	int n = s.size();
// 	set<char> st = {'a','e','i','o','u'};
// 	string ans;
// 	for(int i=0;i<n;i++){
// 		if(st.find(s[i])==st.end()) ans.push_back(s[i]);
// 	}
// 	cout<<ans<<endl;
// }

// void solve(){
// 	int n;cin>>n;
// 	int arr[n];
// 	int sum = 0;
// 	for(int i=0;i<n;i++) cin>>arr[i],sum+=arr[i];
// 	int mid = (sum+1)/2;
// 	int cur = 0;
// 	for(int i=0;i<n;i++){
// 		if(cur+arr[i]>=mid){
// 			cout<<i+1<<" "<<mid-cur<<endl;
// 			return;
// 		}
// 		cur+=arr[i];
// 	}
// }

// C - Flavors
// void solve(){
// 	int n;cin>>n;
// 	map<int,vector<int>> mp;
// 	for(int i=0;i<n;i++){
// 		int f,d;cin>>f>>d;
// 		mp[f].push_back(d);
// 	}
// 	vector<int> temp;
// 	for(auto &ele : mp){
// 		sort(ele.second.begin(),ele.second.end(),greater<int>());
// 		temp.push_back(ele.second[0]);
// 	}
// 	sort(temp.begin(),temp.end(),greater<int>());
// 	int ans = 0;
// 	if(temp.size()>1) ans += temp[0]+temp[1];
// 	for(auto &ele : mp){
// 		if(ele.second.size()>1){
// 			int calc = ele.second[0]+ele.second[1]/2;
// 			ans = max(ans,calc);
// 		}
// 	}
// 	cout<<ans<<endl;
// }

// int terminate(int n,int m,vector<vector<int>> &vis,vector<vector<char>> &vc){
// 	int ter = 0;
// 	for(int i=0;i<n;i++){
// 		set<char> st;
// 		int cnt = 0;
// 		for(int j=0;j<m;j++){
// 			if(vis[i][j]!=2) st.insert(vc[i][j]),cnt++;
// 		}
// 		if(st.size()==1 && cnt>1){
// 			ter++;
// 			for(int j=0;j<m;j++) vis[i][j] = 1;
// 		}
// 	};
// 	for(int j=0;j<m;j++){
// 		set<char> st;
// 		int cnt = 0;
// 		for(int i=0;i<n;i++){
// 			if(vis[i][j]!=2) st.insert(vc[i][j]),cnt++;
// 		}
// 		if(st.size()==1 && cnt>1){
// 			ter++;
// 			for(int i=0;i<n;i++) vis[i][j] = 1; 
// 		}
// 	}
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++) if(vis[i][j]==1) vis[i][j] = 2;
// 	}
// 	return ter;
// }

// void solve(){
// 	int n,m;cin>>n>>m;
// 	vector<vector<char>> vc(n,vector<char>(m,0));
// 	for(int i=0;i<n;i++){
// 		string s;cin>>s;
// 		for(int j=0;j<m;j++) vc[i][j] = s[j];
// 	}
// 	vector<vector<int>> vis(n,vector<int>(m,0));
// 	int ter = 1;
// 	int cnt = 0;
// 	while(ter>0){
// 		if(cnt==1000) break;
// 		ter = terminate(n,m,vis,vc);
// 		// cout<<ter<<"*"<<endl;
// 		cnt++;
// 	}
// 	int ans = 0;
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			if(vis[i][j]!=2) ans++;
// 		}
// 	}
// 	cout<<ans<<endl;
// }

// int candy(vector<int> &a){
// 	int n = a.size();
// 	vector<pair<int,int>> vp;
// 	for(int i=0;i<n;i++){
// 		vp.push_back({a[i],i});
// 	}
// 	sort(vp.begin(),vp.end());
// 	vector<int> can(n,1);
// 	for(int i=0;i<n;i++){
// 		int left = 0,right = 0;
// 		int num = vp[i].first,ind=vp[i].second;
// 		if(ind-1>=0){
// 			if(a[ind-1]<num) left = can[ind-1]+1;
// 		}
// 		if(ind+1<n){
// 			if(a[ind+1]<num) right = can[ind+1]+1;
// 		}
// 		can[ind] = max(can[ind],max(left,right));
// 	}
// 	// for(int i=0;i<n;i++) cout<<can[i]<<" ";
// 	// cout<<endl;
// 	int ans = 0;
// 	for(int i=0;i<n;i++) ans += can[i];
// 	return ans;
// }

// using binary search
// int lis(vector<int> &a){
// 	int n = a.size();
// 	vector<int> temp;
// 	for(int i=0;i<n;i++){
// 		if(temp.size()==0) temp.push_back(a[i]);
// 		else if(temp[temp.size()-1]<a[i]) temp.push_back(a[i]);
// 		else{
// 			int ind = lower_bound(temp.begin(),temp.end(),a[i]) - temp.begin();
// 			temp[ind] = a[i];
// 		}
// 	}
// 	return temp.size();
// }

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode * cur = head;
	ListNode * prev = NULL;
    head = head->next;
    while(cur!=NULL && cur->next!=NULL){
        ListNode * nxt = cur->next;
        cur->next = nxt->next;
        nxt->next = cur;
		if(prev!=NULL) prev->next = nxt;
		prev = cur;
        cur = cur->next;
    }
    return head;
}

void solve(){
	int a;
	vector<int> arr;
	while(cin>>a){
		arr.push_back(a);
	}
	ListNode * head = new ListNode(arr[0]);
	ListNode * cur = head;
	for(int i=1;i<arr.size();i++){
		ListNode * temp = new ListNode(arr[i]);
		cur->next = temp;
		cur = temp;
	}
	head = swapPairs(head);
	while(head){cout<<head->val<<" ";head = head->next;}
	cout<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
	solve();
    return 0;
}