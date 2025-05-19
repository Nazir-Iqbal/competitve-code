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
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);
    tree[node] = 0;
}

int query(int node,int st,int end,int pos){
    if(st==end){
        return tree[node];
    }

    int mid = (st+end)/2;
    int left = 2*node;
    int right = 2*node+1;
    // propagation
    tree[left] += tree[node];
    tree[right] += tree[node];
    tree[node] = 0;
    if(pos>=st && pos<=mid) return query(left,st,mid,pos);
    else return query(right,mid+1,end,pos);
}

void update(int node,int st,int end,int l,int r,int val){
    if(st>=l && end<=r){
        tree[node] += val;
        return;
    }

    if(st>r || end<l) return;

    int mid = (st+end)/2;
    update(2*node,st,mid,l,r,val);
    update(2*node+1,mid+1,end,l,r,val);
}

void solve(){
    int n,q;
    cin>>n>>q;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    while(q--){
        int type;
        cin>>type;
        if(type==2){
            int pos;cin>>pos;
            pos--;
            cout<<query(1,0,n-1,pos)<<endl;
        }else{
            int l,r,val;
            cin>>l>>r>>val;
            l--,r--;
            update(1,0,n-1,l,r,val);
        }
    }
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    solve();

    return 0;
}