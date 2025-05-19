#include <bits/stdc++.h>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> tree(1e6),lazy(1e6);
vector<int> arr;

void build(int node,int st,int end){
    if(st==end){
        tree[node] = arr[st];
        return;
    }

    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);

    tree[node] = tree[2*node] + tree[2*node+1];
}

void propagate(int node,int st,int end){
    if(st==end){
        tree[node] += lazy[node];
        lazy[node] = 0;
        return;
    }

    int mid = (st+end)/2;
    tree[node] += (end-st+1)*lazy[node];
    // reflect
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    lazy[node] = 0;

}

void update(int node,int st,int end,int l,int r,int val){
    // to make sure always that left and right are upadated
    propagate(node,st,end);
    if(st>r || end<l) return;

    if(l<=st && r>=end){
        lazy[node] = val;
        // to reflect changes into the tree for val
        propagate(node,st,end);
        return;
    }

    int mid = (st+end)/2;
    update(2*node,st,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);

    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node,int st,int end,int l,int r){
    propagate(node,st,end);
    if(end<l || st>r) return 0;
    // we can also propagate here

    if(st>=l && end<=r){
        return tree[node];
    }

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
    // for(int i=0;i<16;i++) cout<<tree[i]<<" ";
    // cout<<endl;
    int q;cin>>q;
    while(q--){
        int type;
        cin>>type;
        // cout<<"*"<<endl;
        if(type==0){
            int l,r;cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<endl;
        }else{
            int l,r,val;
            cin>>l>>r>>val;
            update(1,0,n-1,l,r,val);
            // for(int i=0;i<16;i++) cout<<tree[i]<<" ";
            // cout<<endl;
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