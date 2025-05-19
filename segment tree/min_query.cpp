#include <bits/stdc++.h>
using namespace std;

// creating the segment tree
vector<int> tree(1e6,0);
vector<int> arr;

// building the segment tree;
void build(int node,int st,int end){
    if(st == end){
        tree[node] = arr[st];
        return;
    }

    int mid = (st+end)/2;
    int left = 2*node;
    int right = 2*node+1;
    build(left,st,mid);
    build(right,mid+1,end);
    tree[node] = min(tree[left],tree[right]);
}

// for processing the query
int query(int node,int st,int end,int l,int r){
    if(l<=st && end<=r) return tree[node];

    if(st>r || end<l) return INT_MAX;

    int mid = (st+end)/2;
    int left = query(2*node,st,mid,l,r);
    int right = query(2*node+1,mid+1,end,l,r);

    return min(left,right);
}

void update(int node,int st,int end,int pos,int val){
    if(st==end){
        arr[pos] = val;
        tree[node] = val;
        return;
    }

    int mid = (st+end)/2;
    if(st<=pos && pos<=mid){
        update(2*node,st,mid,pos,val);
    }else update(2*node+1,mid+1,end,pos,val);

    tree[node] = min(tree[2*node],tree[2*node+1]);
}

void solve(){
    int n,q;
    cin>>n>>q;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    // building the segment tree
    build(1,0,n-1);
    while(q--){
        int type;cin>>type;
        if(type==1){
            int pos,val;
            cin>>pos>>val;
            pos--;
            update(1,0,n-1,pos,val);
        }else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<query(1,0,n-1,l,r)<<endl;
        }
    }
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    solve();

    return 0;
}