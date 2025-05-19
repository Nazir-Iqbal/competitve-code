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
//     int n,x,y;
//     cin>>n>>x>>y;
//     string s;cin>>s;
//     int posx = 0,posy=0;
//     for(int i=0;i<n;i++){
//         if(s[i] == 'R') posx++;
//         else if(s[i] == 'L') posx--;
//         else if(s[i] == 'U') posy++;
//         else posy--;
//         int diff = abs(x-posx) + abs(y-posy);
//         if(diff==i+1){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     cout<<"No"<<endl;
// }

// Double Trouble
// const int M = 1e9+7;

// long long power(long long x, long long y, long long p) { 
//     long long res = 1; 
//     x = x % p; 
 
//     while (y > 0) { 
//         if (y & 1) 
//             res = (res * x) % p; 
 
//         y = y >> 1; 
//         x = (x * x) % p; 
//     } 
 
//     return res; 
// } 

// bool check(vector<int> two,int mid,int k){
//     int left = k;
//     int n = two.size();
//     for(int i=0;i<n;i++){
//         // cout<<mid<<" "<<two[i]<<endl;
//         if(mid>two[i]){
//             left -= (mid-two[i]);
//             if(left<0) return false;
//         }
//     }
//     return true;
// }

// void solve(){
//     int n,k;cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     vector<int> two;
//     for(int i=0;i<n;i++){
//         int temp = arr[i];
//         int cnt = 0;
//         while(temp){
//             temp/=2;
//             cnt++;
//         }
//         two.push_back(cnt-1);
//     }
//     // for(int i=0;i<n;i++) cout<<two[i]<<" ";
//     // cout<<endl;
//     int lo = 1,hi = 1e9+7;
//     while(lo<=hi){
//         int mid = (lo+hi)/2;
//         if(check(two,mid,k)) lo = mid+1;
//         else hi = mid-1;
//     }
//     // cout<<check(two,3,2)<<endl;
//     int st = hi;
//     int left = k;
//     for(int i=0;i<n;i++){
//         if(st>two[i]) left -= (st-two[i]);
//     }
//     // cout<<hi<<" "<<left<<endl;
//     vector<int> req;
//     int _max = 0;
//     vector<pair<int,int>> vp;
//     for(int i=0;i<n;i++){
//         if(two[i]<=st){
//             _max = max(_max,two[i]);
//             req.push_back(st-two[i]);
//         }else req.push_back(0);
//     }
//     for(int i=0;i<n;i++){
//         if(two[i]<=_max){
//             int net = arr[i]*power(2,_max-two[i],M);
//             // cout<<net<<" "<<arr[i]<<endl;
//             vp.push_back({net,i});
//         }
//     }
//     sort(vp.begin(),vp.end());
//     // for(int i=0;i<vp.size();i++) cout<<vp[i].first<<"*"<<vp[i].second<<endl;
//     for(int i=0;i<left;i++) req[vp[i].second]++;
//     int ans = 0;
//     for(int i=0;i<n;i++){
//         int mul = power(2,req[i],M);
//         int fin = (mul*arr[i])%M;
//         // cout<<mul<<" "<<arr[i]<<endl;
//         ans = (ans + fin)%M;
//     }
//     cout<<ans<<endl;
// }

// The Undisappearance
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int l=-1,r=-1;
	int cnt1=0,cnt2=0,cnt3=0,total = (n*(n+1))/2,invalid = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == 1) cnt1++;
		else if(arr[i] ==2) cnt2++;
		else cnt3++;
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(arr[i] == 1){
			if(l==-1)l=i;
			r=i;
			cnt++;
		}
		if(arr[i] == 3){
			if(cnt==0) continue;
			if(cnt==cnt1) continue;
			l = -1;
			break;
		}
	}
	if(l!=-1){
		int inl=l,inr=r;
		while(l-1>=0){
			if(arr[l-1]!=3)l--;
			else break;
		}
		while(r+1<n){
			if(arr[r+1]!=3) r++;
			else break;
		}
		invalid += (inl-l+1)*(r-inr+1);
	}cnt=0,l=-1,r=-1;

	for(int i=0;i<n;i++){
		if(arr[i] == 2){
			if(l==-1)l=i;
			r=i;
			cnt++;
		}
		if(arr[i] == 1){
			if(cnt==0) continue;
			if(cnt==cnt2) continue;
			l = -1;
			break;
		}
	}
	if(l!=-1){
		int inl=l,inr=r;
		while(l-1>=0){
			if(arr[l-1]!=1)l--;
			else break;
		}
		while(r+1<n){
			if(arr[r+1]!=1) r++;
			else break;
		}
		invalid += (inl-l+1)*(r-inr+1);
	}cnt=0,l=-1,r=-1;

	for(int i=0;i<n;i++){
		if(arr[i] == 3){
			if(l==-1)l=i;
			r=i;
			cnt++;
		}
		if(arr[i] == 2){
			if(cnt==0) continue;
			if(cnt==cnt3) continue;
			l = -1;
			break;
		}
	}
	if(l!=-1){
		int inl=l,inr=r;
		while(l-1>=0){
			if(arr[l-1]!=2)l--;
			else break;
		}
		while(r+1<n){
			if(arr[r+1]!=2) r++;
			else break;
		}
		invalid += (inl-l+1)*(r-inr+1);
	}cnt=0,l=-1,r=-1;
	total -= (invalid);
	cout<<total<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}