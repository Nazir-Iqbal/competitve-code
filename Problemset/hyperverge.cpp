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

// int timer(string a){
//     int num=0,temp=0;
//     temp = (a[0]-'0')*10 + (a[1]-'0');
//     num += temp*60;
//     temp = (a[3]-'0')*10 + (a[4]-'0');
//     num += temp;
//     return num;
// }

void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    string s;cin>>s;
    int a = 0,b= 0;
    for(int i=0;i<n;i++) (s[i] == 'a')?a++:b++;
    int total = a*b;
    if(total-x != y){
        cout<<"Impossible"<<endl;
        return;
    }
    int fwd = x/b;
    int bt = x%b;
    if(bt == 0) bt = b;
    string ans;
    for(int i=0;i<fwd;i++) ans.push_back('a');
    for(int i=0;i<bt;i++) ans.push_back('b');
    if(b-fwd>0) ans.push_back('a');
    for(int i=0;i<a-bt;i++) ans.push_back('b');
    for(int i=0;i<(b-fwd-1);i++) ans.push_back('a');
    cout<<"Possible"<<endl;
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
    //   if(solve()) cout<<1<<endl;
    //   else cout<<0<<endl;
        solve();
    }

    return 0;
}