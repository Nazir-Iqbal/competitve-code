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

class Node{
    public:
        int square,sum;
        Node(){
            square = 0;
            sum = 0;
        }
        Node(int square,int sum){
            this->square = square;
            this->sum = sum;
        }
};

vector<Node> tree(1e4);
vector<int> lazy(1e4),arr;

void build(int node,int st,int end){
    if(st==end){
        tree[node].square = arr[st]*arr[st];
        tree[node].sum = arr[st];
        return;
    }
    
    int mid =(st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);

    tree[node].square = tree[2*node].square + tree[2*node+1].square;
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

void propagte(int node,int st,int end){
    int x = lazy[node];
    if(st==end){
        tree[node].square += x*x + 2*x*tree[node].sum;
        tree[node].sum += x;
        lazy[node] = 0;
        return;
    }

    int len = (end-st+1);
    tree[node].square += (len*x*x) + (2*x*tree[node].sum);
    tree[node].sum += len*x;
    lazy[2*node] += x;
    lazy[2*node+1] += x;
    lazy[node] = 0;
}

void update(int node,int st,int end,int l,int r,int val){
    propagte(node,st,end);
    if(st>r || end<l) return;

    if(st>=l && end<=r){
        lazy[node] += val;
        propagte(node,st,end);
        return;
    }

    int mid = (st+end)/2;
    update(2*node,st,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
    tree[node].square = tree[2*node].square + tree[2*node+1].square;
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

int query(int node,int st,int end,int l,int r){
    propagte(node,st,end);
    if(st>r || end<l) return 0;

    if(st>=l && end<=r) return tree[node].square;

    int mid = (st+end)/2;
    int left = query(2*node,st,mid,l,r);
    int right = query(2*node+1,mid+1,end,l,r);

    return left+right;
}

void solve(){
    int n;cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    int q;cin>>q;
    while(q--){
        int type;cin>>type;
        if(type==0){
            int l,r;cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<endl;
        }else{
            int l,r,val;
            cin>>l>>r>>val;
            update(1,0,n-1,l,r,val);
        }
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}