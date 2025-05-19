#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     string s;
//     for(int i=0;i<6;i++){
//         char temp;
//         cin>>temp;
//         s.push_back(temp);
//     }
//     for(int i=1;i<5;i++){
//         if(s[i]=='W' && s[i-1]=='W' && s[i+1]=='W'){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     cout<<"No"<<endl;
// }

// Access Control
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     string s;cin>>s;
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(s[i]=='0') cnt--;
//         else cnt = x;
//         if(cnt<0){
//             cout<<"No"<<endl;
//             return;
//         }
//     }
//     cout<<"Yes"<<endl;
// }

// ORST
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int a[n],b[m];
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<m;i++) cin>>b[i];
//     vector<int> temp;
//     int ind = *max_element(b,b+m);
//     ind = n-ind;
//     for(int i=ind;i<n;i++){
//         temp.push_back(a[i]);
//     }
//     sort(temp.begin(),temp.end());
//     for(int i=ind;i<n;i++) a[i] = temp[i-ind];
//     for(int i=0;i<n;i++) cout<<a[i]<<" ";
//     cout<<endl;
// }

// Chef Product
int check(int sq,int n){
    int temp = sq;
    if((sq+1)*(sq+1)<=n) return sq+1;
    else if(sq*sq<=n) return sq;
    else return sq-1;
}

void solve(){
    int n;cin>>n;
    int sq = sqrt(n);
    sq = check(sq,n);
    if(n&1 && sq&1) cout<<(sq/2)+1<<endl;
    else cout<<sq/2<<endl;

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