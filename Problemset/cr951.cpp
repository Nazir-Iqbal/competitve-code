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

// Guess the Maximum
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int req = *max_element(arr,arr+n);
//     for(int i=1;i<n-1;i++){
//         int left = max(arr[i],arr[i-1]);
//         int right = max(arr[i],arr[i+1]);
//         // cout<<left<<" "<<right<<endl;
//         req = min(req,min(left,right));
//     }
//     cout<<req-1<<endl;
// }

// XOR Sequences
// void solve(){
//     int x,y;
//     cin>>x>>y;
//     int same = 0;
//     for(int i=0;i<=30;i++){
//         if(((x>>i)&1)==((y>>i)&1)){
//             // cout<<i<<"*"<<endl;
//             same++;
//         }else break;
//     }
//     cout<<(1<<same)<<endl;
// }

// Earning on Bets
// int _lcm(int x,int y){
//     int gcd = __gcd(x,y);
//     int ans = (x*y)/gcd;
//     return ans;
// }

// bool check(vector<int> &ans,vector<int> &k){
//     int total = 0;
//     for(int i=0;i<ans.size();i++) total += ans[i];
//     for(int i=0;i<k.size();i++){
//         int num = k[i]*ans[i];
//         // cout<<num<<" "<<total<<endl;
//         if(total>=num) return true;
//     }
//     return false;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> k(n);
//     for(int i=0;i<n;i++) cin>>k[i];
//     int lcm = 1;
//     for(int i=0;i<n;i++){
//         lcm = _lcm(lcm,k[i]);
//     }
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         int num = lcm/k[i];
//         ans.push_back(num);
//     }
//     // cout<<lcm<<endl;
//     if(check(ans,k)) cout<<-1<<endl;
//     else{
//         for(int ele : ans) cout<<ele<<" ";
//         cout<<endl;
//     }
// }

// Fixing a Binary String
// bool check(string &s,int ind,int k){
//     string temp;
//     int n = s.size();
//     for(int i=ind+1;i<n;i++) temp.push_back(s[i]);
//     for(int i=ind;i>=0;i--) temp.push_back(s[i]);
//     for(int i=0;i<n-1;i++){
//         int first = i%k;
//         int second = (i+1)%k;
//         if(temp[i] == temp[i+1]){
//             if(first>=second) return false;
//         }
//         if(temp[i] != temp[i+1]){
//             if(first<second) return false;
//         }
//     }
//     return true;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     string s;cin>>s;
//     int ind = -1;
//     for(int i=0;i<n-1;i++){
//         int first = i%k;
//         int second = (i+1)%k;
//         if(s[i] == s[i+1]){
//             if(first>=second){
//                 ind = i;
//                 break;
//             }
//         }
//         if(s[i] != s[i+1]){
//             if(first<second){
//                 ind = i;
//                 break;
//             }
//         }
//     }

//     if(ind == -1){
//         cout<<n<<endl;
//     }else{
//         int ind1 = max(ind-1,0ll);
//         int ind2 = min(ind+1,n-1);

//         if(check(s,ind,k)) cout<<ind+1<<endl;
//         else if(check(s,ind1,k)) cout<<ind1+1<<endl;
//         else if(check(s,ind2,k)) cout<<ind2+1<<endl;
//         else cout<<-1<<endl;
//     }
    
// }

// method 2
// bool check(string &s,int ind,int k){
//     ind--;
//     string temp;
//     int n= s.size();
//     for(int i=ind+1;i<n;i++) temp.push_back(s[i]);
//     for(int i=ind;i>=0;i--) temp.push_back(s[i]);
//     // cout<<temp<<endl;
//     string str1,str2;
//     int cnt = 0;
//     char zero = '0',one = '1';
//     for(int i=0;i<n;i++){
//         if(cnt==k) swap(zero,one),cnt=0;
//         str1.push_back(one);
//         str2.push_back(zero);
//         cnt++;
//     }
//     if(str1 == temp || str2 == temp) return true;
//     else return false;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     string s;cin>>s;
//     vector<int> cnt;
//     int count = 1;
//     for(int i=1;i<n;i++){
//         if(s[i] == s[i-1]) count++;
//         else cnt.push_back(count),count = 1;
//     }
//     if(count>1) cnt.push_back(count);
//     int ind = 0;
//     for(int i=0;i<cnt.size();i++){
//         // case 1
//         if(cnt[i]>k){
//             // cout<<ind+cnt[i]-k<<"*"<<endl;
//             if(check(s,ind+cnt[i]-k,k)){
//                 cout<<ind+cnt[i]-k<<endl;
//                 return;
//             }else{
//                 cout<<-1<<endl;
//                 return;
//             }
//         }else if(cnt[i]<k){
//             if(check(s,ind+cnt[i],k)){
//                 cout<<ind+cnt[i]<<endl;
//                 return;
//             }else{
//                 cout<<-1<<endl;
//                 return;
//             }
//         }
//         ind+=cnt[i];
//     }
//     cout<<n<<endl;
// }

// method 3
// using the string hashing (rabin karp)
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
	for(int i=1;i<N;i++) expo[i] =  power(2,i);
}

void solve(){
    int n,k;
	cin>>n>>k;
	string s;cin>>s;
	// cout<<"*"<<endl;
	int hsn1=0,hsn2=0;
	string temp1,temp2;
	int one = '1',zero = '0';
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(cnt == k) swap(one,zero),cnt = 0;
		temp1.push_back(one),temp2.push_back(zero);
        cnt++;
	}

	// trivial case
	if(s==temp1 || s==temp2){
		cout<<n<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		int ch1 = (temp1[n-1-i]-'0')+1;
		int ch2 = (temp2[n-1-i]-'0')+1;
		hsn1 = (hsn1 + expo[i]*ch1)%mod;
		hsn2 = (hsn2 + expo[i]*ch2)%mod;
	}
    cout<<hsn1<<" "<<hsn2<<endl;

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
		temp = (suffix[i] + (mod + (prefix[n-1]-prefix[i]))%mod)%mod;
		cout<<temp<<endl;
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
    pre();
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}