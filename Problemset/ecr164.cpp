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

// Painting the Ribbon
// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     if(m==1){
//         cout<<"No"<<endl;
//         return;
//     }
//     int req = (n+(m-n%m)%m)/m;
//     // cout<<req<<endl;
//     if(k>=(n-req)){
//         cout<<"No"<<endl;
//     }else cout<<"Yes"<<endl;
// }

// Make It Ugly
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     set<int> s;
//     for(int ele : arr) s.insert(ele);
//     if(s.size()==1){
//         cout<<-1<<endl;
//         return;
//     }
//     if(arr[0] != arr[n-1]){
//         cout<<-1<<endl;
//         return;
//     }
//     int moves = INT_MAX;
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]!=arr[0]){
//             moves = cnt;
//             break;
//         }
//         cnt++;
//     }cnt = 0;
//     for(int i=n-1;i>=0;i--){
//         if(arr[i]!=arr[n-1]){
//             moves = min(moves,cnt);
//             break;
//         }
//         cnt++;
//     }
//     int prev = -1;
//     for(int i=0;i<n;i++){
//         if(arr[i] != arr[0]){
//             if(prev==-1) prev = i;
//             else moves = min(i-prev-1,moves);
//             prev = i;
//         }
//     }
//     cout<<moves<<endl;
// }

// Long Multiplication
// void solve(){
//     string x,y;
//     cin>>x>>y;
//     int len = x.size();
//     string ans;
//     int ind = -1,flag = true;
//     for(int i=0;i<len;i++){
//         int num1 = x[i] - '0';
//         int num2 = y[i] - '0';
//         if(num1>num2){
//             ind = i;
//             break;
//         }else if (num1<num2){
//             ind = i;
//             flag = false;
//             break;
//         }
//     }
//     // cout<<flag<<" "<<ind<<endl;
//     if(flag){
//         for(int i=ind+1;i<len;i++){
//             int num1 = x[i] - '0';
//             int num2 = y[i] - '0';
//             if(num1>num2) swap(x[i],y[i]);
//         }
//     }else{
//         for(int i=ind+1;i<len;i++){
//             int num1 = x[i] - '0';
//             int num2 = y[i] - '0';
//             if(num1<num2) swap(x[i],y[i]);
//         }
//     }

//     cout<<x<<endl;
//     cout<<y<<endl;
// }

// Colored Balls
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int dp[5001][5001];
    
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }

    return 0;
}