#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// 2023
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int b[n];
//     for(int i=0;i<n;i++) cin>>b[i];
//     int left = 2023;
//     for(int i=0;i<n;i++){
//         if(left%b[i]!=0){
//             cout<<"NO"<<endl;
//             return;
//         }
//         // cout<<left<<" ";
//         left/=b[i];
//     }
//     // cout<<endl;
//     cout<<"YES"<<endl;
//     cout<<left<<" ";
//     for(int i=0;i<k-1;i++) cout<<1<<" ";
//     cout<<endl;
// }

// Two Divisors
// void solve(){
//     int a,b;
//     cin>>a>>b;
//     if(b%a==0){
//         int num = b/a;
//         cout<<num*b<<endl;
//     }else{
//         cout<<(a*b)/__gcd(a,b)<<endl;
//     }
// }

// Training Before the Olympiad
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int sum = arr[0],odd=0;
//     if(arr[0]&1) odd++;
//     cout<<arr[0]<<" ";
//     for(int i=1;i<n;i++){
//         if(arr[i]&1) odd++;
//         sum+=arr[i];
//         int neg = 0;
//         int f = (odd-1)/3;
//         int rem = odd%3;
//         if(odd!=0){
//             if(rem==1 || rem==0) neg = f+1;
//             else neg = f;
//         }
//         cout<<sum-neg<<" ";
//     }
//     cout<<endl;
// }

// Mathematical Problem
void solve(){
    int n;cin>>n;
    if(n==1){
        cout<<1<<endl;
    }else{
        vector<vector<int>> v = {{1,6,9},{9,6,1}};
        cout<<169;
        for(int i=0;i<n-3;i++)cout<<0;
        cout<<endl;
        cout<<196;
        for(int i=0;i<n-3;i++)cout<<0;
        cout<<endl;
        cout<<961;
        for(int i=0;i<n-3;i++)cout<<0;
        cout<<endl;
        int cnt = 0;
        for(int i=1;i<=(n-3)/2;i++){
            if(cnt==n) break;
            // cout<<cnt<<"&"<<endl;
            for(int j=0;j<2;j++){
                int len = 3;
                if(cnt==n) break;
                cout<<v[j][0];
                for(int k=1;k<=i;k++)cout<<0,len++;
                cout<<v[j][1];
                for(int k=1;k<=i;k++)cout<<0,len++;
                cout<<v[j][2];
                len = n-len;
                while(len--) cout<<0;
                cout<<endl;
                cnt++;
                // cout<<n<<" "<<cnt<<" "<<i<<endl;
                // cout<<len<<"*"<<endl;
            }
        }
    }
    
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}