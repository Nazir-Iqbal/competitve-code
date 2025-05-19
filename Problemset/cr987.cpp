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
//     int cnt = 1,temp = 1;
//     for(int i=1;i<n;i++){
//         if(arr[i]==arr[i-1]) temp++;
//         else temp = 1;
//         cnt = max(temp,cnt);
//     }
//     cout<<n-cnt<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];
//     for(int i=1;i<n;i++){
//         if(arr[i] != i){
//             if(abs(arr[i]-arr[i+1])!=1){
//                 // cout<<i<<" "<<arr[i]<<" "<<arr[i+1]<<endl;
//                 cout<<"NO"<<endl;
//                 return;
//             }else swap(arr[i],arr[i+1]);
//         }
//     }
//     for(int i=1;i<=n;i++){
//         if(arr[i]!=i){
//             cout<<"NO"<<endl;
//             return;
//         }
//     }
//     cout<<"YES"<<endl;
// }

void check(int n){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                int d1 = j-i,d2 = k-j,d3 = k-i;
                if(sqrt(d1)*sqrt(d1)==d1 && sqrt(d2)*sqrt(d2)==d2 && sqrt(d3)*sqrt(d3)==d3){
                    cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
    }
}

void solve(){
    int n;cin>>n;
    vector<int> ans(n+1,0);
    // check(120);
    if(n&1){
        if(n<27){
            cout<<-1<<endl;
            return;
        }
        ans[1] = ans[10] = ans[26]=1;
        for(int i=2;i<=9;i++) ans[i] = ans[i+9] = i;
        for(int i=19;i<23;i+=2) ans[i] = ans[i+1] = i;
        ans[23] = ans[27] = 23;
        ans[24]=ans[25] = 24;
        for(int i=28;i<=n;i+=2) ans[i] = ans[i+1] = i;
    }else{
        for(int i=1;i<=n;i+=2) ans[i] = ans[i+1] = i;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
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