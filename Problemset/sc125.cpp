#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

// #define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int ones = 0;
//     for(int i=0;i<n;i++){
//         if(s[i] == '1') ones++;
//     }
//     int sum = 0,temp = 0;
//     for(int i=0;i<n;i++){
//         if(s[i] == '0') temp++;
//         else{
//             sum = max(sum,temp);
//             temp = 0;
//         }
//         if(i==n-1){
//             sum = max(temp,sum);
//         }
//     }
//     // cout<<ones<<" "<<sum<<endl;
//     cout<<ones+sum<<endl;
// }

// Binary Minimal
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     string s;cin>>s;
//     int ones = 0;
//     for(int i=0;i<n;i++) if(s[i] == '1') ones++;
//     if(k>=ones){
//         string temp;
//         for(int i=0;i<n;i++){
//             if(s[i]=='0') temp.push_back(s[i]);
//             else k--;
//         }
//         s = temp;
//         n =  s.length();
//         temp.clear();
//         for(int i=0;i<n-k;i++){
//             temp.push_back('0');
//         }
//         cout<<temp<<endl;
//     }else{
//         for(int i=0;i<n;i++){
//             if(k==0) break;
//             if(s[i] == '1'){
//                 s[i] = '0';
//                 k--;
//             }
//         }
//         cout<<s<<endl;
//     }
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int one = 0,odd=0,even=0;
//     for(int i=0;i<n;i++){
//         if(arr[i] == 1) one++;
//         else if(arr[i]&1) odd++;
//         else even++;
//     }
//     int a = (one+1)/2 , b= one/2;
//     if(one&1){
//         if(odd&1) b+= (n-one);
//         else a+=(n-one);
//     }else{
//         if(odd&1) a+=(n-one);
//         else b+=(n-one);
//     }
//     if(a==b) cout<<"Draw"<<endl;
//     else if(a>b) cout<<"Alice"<<endl;
//     else cout<<"Bob"<<endl;
// }

// Operating on A
void solve(){
    int n;cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<=n-4;i++){
        if(a[i]!=b[i]){
            if(a[i] + a[i+1] + a[i+2] == b[i]){
                a[i] = b[i];
                a[i+3] = a[i+3] + a[i+1] + a[i+2]; 
                swap(a[i+1],a[i+2]);
                a[i+1] = -a[i+1];
                a[i+2] = -a[i+2];
            }else{
                cout<<"No"<<endl;
                return;
            }
        }
    }
    for(int i=n-4;i<n;i++){
        if(a[i]!=b[i]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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