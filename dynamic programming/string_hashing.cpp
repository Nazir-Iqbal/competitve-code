#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Fixing a Binary String
// solving using the hashing
const int N = 1e5+7;
int mod = 1e9+7;
vector<int> expo(N,1);

long long power(long long a, long long b){
    long long result = 1;
    while (b) {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

// precomputed the exponeent powers
void pre(){
	for(int i=1;i<N;i++){
		expo[i] = power(2,i);
	}
}

void solve(){
    int n,k;
	cin>>n>>k;
	string s;cin>>s;
	cout<<"*"<<endl;
	int hsn1=0,hsn2=0;
	string temp1,temp2;
	int one = '1',zero = '0';
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(cnt == k) swap(one,zero),cnt = 0;
		temp1.push_back(one),temp2.push_back(zero);
	}

	// trivial case
	if(s==temp1 || s==temp2){
		cout<<n<<endl;
		return;
	}

	for(int i=0;i<n;i++){
		int ch1 = (temp1[i]-'0')+1;
		int ch2 = (temp2[i]-'0')+1;
		hsn1 = (hsn1 + expo[i]*ch1)%mod;
		hsn2 = (hsn2 + expo[i]*ch2)%mod;
	}

	// rabin karp hashing
	vector<int> prefix(n,0),suffix(n+1,0);
	prefix[n-1] = (s[n-1]-'0') + 1;
	suffix[0] = (expo[n-1]*((s[0]-'0')+ 1))%mod;
	for(int i=1;i<n;i++){
		prefix[i] = (prefix[i-1] + (expo[i]*((s[i]-'0')+ 1))%mod)%mod;
		suffix[i] = (suffix[i-1] + (expo[n-1-i]*((s[i]-'0')+ 1))%mod)%mod;
	}
	int temp = 0;
	for(int i=0;i<n;i++){
		temp = (prefix[i] + (mod + (suffix[n-1]-suffix[i])%mod)%mod)%mod;
		if(temp == hsn1 || temp == hsn2){
			cout<<i+1<<endl;
			return;
		}
	}

	cout<<-1<<endl;
	return;
	
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