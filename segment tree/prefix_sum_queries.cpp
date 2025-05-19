#include <bits/stdc++.h>
using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

class Node{
    public:
        int sum,prefix;
        Node(){
            sum =0,prefix = 0;
        }
        Node(int prefix,int sum){
            this->sum = sum;
            this->prefix = prefix;
        }
};

vector<Node> tree(1e6);
vector<int> arr;

void merge(int node,int st,int end){
    tree[node].prefix = max(tree[2*node].prefix,tree[2*node].sum+tree[2*node+1].prefix);
    tree[node].sum = tree[2*node].sum+tree[2*node+1].sum;

}

void build(int node,int st,int end){
    if(st==end){
        tree[node].prefix = arr[st];
        tree[node].sum = arr[st];
        return;
    }

    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);

    merge(node,st,end);
}

Node query(int node,int st,int end,int l,int r){
    
    Node ans;
    if(st>r || end<l){
        ans.prefix = 0;
        ans.sum = 0;
        return ans;
    }

    if(st>=l && end<=r) return tree[node];

    int mid = (st+end)/2;
    auto left = query(2*node,st,mid,l,r);
    auto right = query(2*node+1,mid+1,end,l,r);
    ans.prefix = max(left.prefix,left.sum+right.prefix);
    ans.sum = left.sum + right.sum;
    return ans;
}

void update(int node,int st,int end,int pos,int val){

    if(st==end){
        tree[node].prefix = val;
        tree[node].sum = val;
        arr[st] = val;
        return;
    }

    int mid = (st+end)/2;
    if(st<=pos && pos<=mid) update(2*node,st,mid,pos,val);
    else update(2*node+1,mid+1,end,pos,val);
    merge(node,st,end);
}

void solve(){
    int n,q;cin>>n>>q;
    arr.resize(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    while(q--){
        int type;cin>>type;
        if(type==1){
            int pos,val;
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }else{
            int l,r;
            cin>>l>>r;
            int ans = query(1,1,n,l,r).prefix;
            if(ans<0) cout<<0<<endl;
            else cout<<query(1,1,n,l,r).prefix<<endl;
        }
    }
    // for(int i=1;i<=2*n;i++) cout<<tree[i].sum<<" "<<tree[i].prefix<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}