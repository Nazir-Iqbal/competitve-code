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
//     int n,a,b;
//     cin>>n>>a>>b;
//     int diff = abs(a-b);

//     if(diff&1) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     int a[n],b[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     vector<int> diff(n);
//     for(int i=0;i<n;i++){
//         diff[i] = a[i]-b[i];
//     }
//     int cnt = 0,moves = INT_MAX,neg = 0;
//     for(int i=0;i<n;i++){
//         if(diff[i] < 0) cnt++,neg = abs(diff[i]);
//         else moves = min(moves,diff[i]);
//     }
//     if(cnt>1) cout<<"No"<<endl;
//     else{
//         if(moves>=neg) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     string s;cin>>s;
//     vector<vector<int>> v(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cin>>v[i][j];
//     }

//     int row = 0,col = 0;
//     for(int i=0;i<s.size();i++){
//         int sum = 0;
//         if(s[i] == 'D'){
//             for(int j=0;j<m;j++){
//                 if(j==col) continue;
//                 sum += v[row][j];
//             }
//             v[row][col] = -sum;
//             row++;
//         }else{
//             for(int j=0;j<n;j++){
//                 if(j==row) continue;
//                 sum += v[j][col];
//             }
//             v[row][col] = -sum;
//             col++;
//         }
//     }
//     int sum = 0;
//     for(int i=0;i<n;i++){
//         sum += v[i][m-1];
//     }
//     v[n-1][m-1] = -sum;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++) cout<<v[i][j]<<" ";
//         cout<<endl;
//     }

// }

void solve(){
    int n,k,l;
    cin>>n>>k>>l;
    k<<=1;
    l<<=1;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++) arr[i]<<=1;

    int time = arr[0];
    int ptr = 1;
    int pos = k;

    while(ptr<n && pos<l){

        if(abs(pos-arr[ptr])<=time){
            arr[ptr] = pos;

        }else if(arr[ptr]<=pos){
            arr[ptr] += time;
            pos = arr[ptr] + k;
            ptr++;
            continue;
        }else{
            arr[ptr] -= time;
        }

        int diff = arr[ptr]-pos;
        time += (diff/2);
        arr[ptr] -= diff/2;
        pos = arr[ptr] + k;
        ptr++;
    }
    if(pos<l) time += (l-pos);
    cout<<time<<endl;
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