#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

class fenwick{
  public:

    int n;
    vector<int> fen_tree;

    fenwick(int n){
        this->n = n;
        fen_tree.resize(n+1);
        for(int i=0;i<=n;i++) fen_tree[i] = 0;
    }

    //upadate query
    void update(int ind , int add){
        while(ind<=n){
            fen_tree[ind]+=add;
            ind += (ind & (-ind ));
        }
    }

    //sum query
    int sum(int ind){
        int s = 0;
        while(ind>0){
            s+=fen_tree[ind];
            ind-= (ind & (-ind));
        }
        return s;
    }

    // applying the binary lifting for find opoeration
    int find(int x){
        int cur = 0,prevsum=0;
        for(int i=log2(n);i>=0;i--){
            if(fen_tree[cur+(i<<i)] + prevsum<x){
                cur += i<<i;
                prevsum+=fen_tree[cur];
            }
        }
        return (cur+1);
    }

};

void solve(){
    int n,u;
    cin>>n>>u;
    fenwick fe(n);
    while(u--){
        int l,r,val;
        cin>>l>>r>>val;
        l++,r+=2;
        // cout<<l<<" "<<r<<endl;
        if(r<=n) fe.update(r,-val);
        fe.update(l,val);
    }

    // for(int i=0;i<n;i++) cout<<fe.fen[i]<<" ";
    // cout<<endl;

    int q;cin>>q;
    while(q--){
        int ind;cin>>ind;
        ind++;
        cout<<fe.sum(ind)<<endl;
    }
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