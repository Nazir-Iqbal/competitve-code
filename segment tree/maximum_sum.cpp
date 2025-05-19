#include <bits/stdc++.h>
using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class Node{
    public:
        int ele,sum;
        Node(){
            ele = 0;
            sum = 0;
        }
        Node(int ele,int sum){
            this->ele = ele;
            this->sum = sum;
        }
};

vector<Node> tree(1e6);
vector<int> arr;

void merge(int node){
    tree[node].sum = max(tree[2*node].sum,tree[2*node+1].sum);
    tree[node].sum = max(tree[node].sum,tree[2*node].ele+tree[2*node+1].ele);
    tree[node].ele = max(tree[2*node].ele,tree[2*node+1].ele);
}

Node answer(Node left,Node right){
    int sum = max(left.sum,right.sum);
    sum = max(sum,left.ele+right.ele);
    int ele = max(left.ele,right.ele);

    Node ans(ele,sum);
    return ans;
}

void build(int node,int st,int end){
    if(st==end){
        tree[node].ele = arr[st];
        tree[node].sum = arr[st];
        return;
    }

    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);
    
    merge(node);
}

void update(int node,int st,int end,int pos,int val){
    if(st==end){
        tree[node].sum = val;
        tree[node].ele = val;
        arr[st] = val;
        return;
    }

    int mid = (st+end)/2;
    if(pos>=st && pos<=mid) update(2*node,st,mid,pos,val);
    else update(2*node+1,mid+1,end,pos,val);

    merge(node);
    
}

Node query(int node,int st,int end,int l,int r){
    if(st>r || end<l) return {0,0};

    if(st>=l && end<=r) return tree[node];
    int mid = (st+end)/2;
    auto left = query(2*node,st,mid,l,r);
    auto right = query(2*node+1,mid+1,end,l,r);

    return answer(left,right);
}

void solve(){
    int n;cin>>n;
    arr.resize(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    int q;cin>>q;
    while(q--){
        char c;cin>>c;
        if(c=='Q'){
            int l,r;
            cin>>l>>r;
            cout<<query(1,1,n,l,r).sum<<endl;
        }else{
            int pos,ele;
            cin>>pos>>ele;
            update(1,1,n,pos,ele);
        }
    }
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}