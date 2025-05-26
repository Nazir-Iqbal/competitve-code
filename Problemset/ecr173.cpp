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
//     int n;cin>>n;
//     if(n<4){
//         cout<<1<<endl;
//     }else{
//         int cur = 1;
//         while(n>3){
//             n /= 4;
//             cur<<=1;
//         }
//         cout<<cur<<endl;
//     }
// }

// Digits
bool check(int n,int d){
    int num = 1;
    for(int i=1;i<=n;i++) num*=i;
    // cout<<num<<" "<<n<<" "<<d<<endl;
    num*=d;
    return (num%9==0);
}

void solve(){
    int n,d;cin>>n>>d;
    vector<int> ans;
    ans.push_back(1);
    if(d%3==0 || (n>2)) ans.push_back(3);
    if(d%5 == 0) ans.push_back(5);
    if(d%7 == 0 || (n>2)) ans.push_back(7);
    if(d%9==0 || (n>5) || (check(n,d))) ans.push_back(9);
    for(int &ele : ans) cout<<ele<<" ";
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