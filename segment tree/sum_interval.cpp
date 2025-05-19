#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> tree(1e6);
vector<int> arr;

void build(int node,int st,int end){
    if(st==end){
        tree[node] = arr[st];
        return;
    }

    int mid = (st+end)/2;
    int left = 2*node;
    int right = 2*node+1;
    build(left,st,mid);
    build(right,mid+1,end);
    tree[node] = tree[left]+tree[right];
}

int query(int node,int st,int end,int l,int r){
    if(l>end || r<st) return 0;

    if(l<=st && end<=r){
        return tree[node];
    }

    int mid = (st+end)/2;
    int left = query(2*node,st,mid,l,r);
    int right = query(2*node+1,mid+1,end,l,r);

    return left+right;
}

void update(int node,int st,int end,int pos,int val){
    if(st==end){
        tree[node] = val;
        arr[pos] = val;
        return;
    }

    int mid = (st+end)/2;
    int left = 2*node;
    int right = 2*node+1;
    // applying BS on the segment tree
    if(pos>=st && pos<=mid){
        update(left,st,mid,pos,val);
    }else update(right,mid+1,end,pos,val);

    tree[node] = tree[left]+tree[right];
}

void solve(){
    int n,q;
    cin>>n>>q;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
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