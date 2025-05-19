#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Anti Adjacent Swaps
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==1) cout<<"Yes"<<endl;
//     else if(n==2){
//       if(arr[0]>arr[1]) cout<<"No"<<endl;
//       else cout<<"Yes"<<endl;
//     }else if(n==3){
//       if(arr[1] < min(arr[0],arr[2]) || arr[1]>max(arr[0],arr[2])) cout<<"No"<<endl;
//       else cout<<"Yes"<<endl;
//     }else cout<<"Yes"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     string a,b;
//     cin>>a>>b;
//     vector<int> ans;
//     for(int i=0;i<n;i++){
//         int cnt = 0;
//         char c = a[i];
//         while(c!=b[i]){
//             int ind = c-'A';
//             ind = (ind+3)%26;
//             // cout<<ind<<endl;
//             c = (char)('A'+ind);
//             // cout<<c<<endl;
//             cnt++;
//         }
//         ans.push_back(cnt);
//     }
//     for(auto ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Frequal
// const int N = 1e6+5;
// int se[N];
// map<int,int> mp;
// void solve(){
//     int n;cin>>n;
//     vector<int> ans;
//     // cout<<n<<endl;
//     if(n&1) ans.push_back(1),n--;
//     for(auto ele : mp){
//         if(n==0) break;
//         ans.push_back(ele.first);
//         ans.push_back(ele.first);
//         n-=2;
//         // cout<<n<<endl;
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Split And Maximize
void solve(){
  
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    // for(int i=2;i<N;i++){
    //     // cout<<i<<endl;
    //     if(se[i]==1) continue;
    //     mp[i] = 1;
    //     for(int j=2*i;j<N;j+=i){
    //         se[j] = 1;
    //     }
    // }

    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}