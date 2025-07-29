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

// binary lifting
vector<vector<int>> up;
void pre(int n,vector<int> &parent){
    up = vector<vector<int>> (18,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++) up[0][i] = parent[i];

    for(int i=1;i<18;i++){
        for(int j=1;j<=n;j++){
            if(up[i-1][j]!=-1){
                up[i][j] = up[i-1][up[i-1][j]];
            }
        }
    }
}

void solve(){
    int n,q;cin>>n>>q;
    vector<int> parent(n+1,-1);
    for(int i=2;i<=n;i++){
        cin>>parent[i];
    }
    pre(n,parent);

    while(q--){
        int x,k;
        cin>>x>>k;
        int cur = x;
        for(int i=0;i<18;i++){
            if(k&(1<<i)){
                cur = up[i][cur];
                if(cur == -1){
                    break;
                }
            }
        }
        cout<<cur<<endl;
    }
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}