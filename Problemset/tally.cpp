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

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int k;cin>>k;
//     int left = k,ans = n;
//     for(int i=0;i<n;i++){
//         if(left-arr[i]<0) left = k,ans += 2*i;
//         left-=arr[i];
//     }
//     cout<<ans<<endl;
// }

// int MaxGCD(int a[], int n)
// {
//     vector<int> Prefix(n+2,0),Suffix(n+2,0);
//     Prefix[1] = a[0];
//     for (int i = 2; i <= n; i += 1) Prefix[i] = __gcd(Prefix[i - 1], a[i - 1]);
//     Suffix[n] = a[n - 1];
//     for (int i = n - 1; i >= 1; i -= 1) Suffix[i] = __gcd(Suffix[i + 1], a[i - 1]);
//     int ans = max(Suffix[2], Prefix[n - 1]);
//     for (int i = 2; i < n; i += 1) ans = max(ans, __gcd(Prefix[i - 1], Suffix[i + 1]));
 
//     return ans;
// }

// void solve(){
//     int x;cin>>x;
//     int mul = x+(3-(x%3))%3;
//     string ans;
//     while(mul){
//         if(mul>=9) ans.push_back('9'),mul-=9;
//         else ans.push_back(char(48+mul)),mul=0;
//     }
//     reverse(ans.begin(),ans.end());
//     cout<<ans<<endl;
// }

bool check(int arr[],int n,int k){
    int l=0,r=0,td=0,ntd=0;
    while(r<n){
        if(arr[r]>8) td++;
        else ntd++;
        if(r-l+1==k){
            if(td>ntd) return true;
            if(arr[l]>8) td--;
            else ntd--;
            l++;
        }
        r++;
    }
    return false;
}

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int lo = 1,hi = n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(arr,n,mid)) lo = mid+1;
        else hi = mid-1;
    }
    cout<<hi<<endl;
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