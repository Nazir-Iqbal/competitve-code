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
//     int n,k,x;
//     cin>>n>>k>>x;
//     if(k>33){
//         cout<<"No"<<endl;
//         return;
//     }
//     int num = (1ll<<(k-1));
//     if(num<=x) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Anti-Triangle
// void solve(){
//     int n,x;
//     cin>>n>>x;
//     if(x>=2000){
//         for(int i=1;i<=n;i++) cout<<i<<" ";
//         cout<<endl;
//     }else{
//         int last = 10000+(n-1)*2000;
//         for(int i=10000;i<=last;i+=2000) cout<<i<<" ";
//         cout<<endl;
//     }
// }

// ABC Conjecture
void solve(){
    int n;cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    bool flag = false;
    for(int i=0;i<n;i++){
        if((s1[i]=='b' && s2[i] != 'b')||(s1[i]!='b'&&s2[i]=='b')){
            cout<<"No"<<endl;
            return;
        }
    }
    set<int> a,b,c;
    for(int i=0;i<n;i++){
        if(s1[i] == 'a' && s2[i] == 'c') a.insert(i);
        else if(s1[i] == 'c' && s2[i] == 'a') c.insert(i);
        else if(s1[i] == 'b') b.insert(i);
    }
    for(int i=0;i<n;i++){
        if(s1[i] == 'a' && s2[i] == 'c'){
            auto ind = b.lower_bound(i);
            if(ind == b.end()){
                cout<<"No"<<endl;
                return;
            }
            auto ind2 = c.lower_bound((*ind));
            if(ind2 == c.end()){
                cout<<"No"<<endl;
                return;
            }
            swap(s1[i],s1[(*ind2)]);
            c.erase(ind2);
        }
    }
    for(int i=0;i<n;i++){
        if(s1[i] != s2[i]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}