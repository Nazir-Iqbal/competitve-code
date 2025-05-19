#include <bits/stdc++.h>
using namespace std;

// creating the segment tree
vector<int> tree(4e5+1);

void build(vector<int> &arr,int node,int st,int end){
    if(st==end){
        tree[node] = arr[st];
        return;
    }
    int left = 2*node;
    int right = 2*node+1;
    int mid = (st+end)/2;
    build(arr,left,st,mid);
    build(arr,right,mid+1,end);
    tree[node] = max(tree[left],tree[right]);
}

int query(vector<int> &arr,int node,int st,int end,int l,int r){
    // completly inside
    if(l<=st && r>=end){
        return tree[node];
    }
    // not in the range
    if(st>r || end<l) return INT_MIN;

    int mid = (st+end)/2;
    int left = query(arr,2*node,st,mid,l,r);
    int right = query(arr,2*node+1,mid+1,end,l,r);
    return max(left,right);
}

void update(vector<int> &arr,int node,int st,int end,int pos,int val){
    // base condidtion
    if(st==end){
        arr[pos]=val;
        tree[node]=val;
        return;
    }

    int mid = (st+end)/2;
    if(st<=pos && pos<=mid){
        update(arr,2*node,st,mid,pos,val);
    }else{
        update(arr,2*node+1,mid+1,end,pos,val);
    }
    tree[node] = max(tree[2*node],tree[2*node+1]);
}

void solve(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    build(arr,1,0,n-1);
    int q;cin>>q;
    while(q--){
        int type,l,r;
        cin>>type;
        if(type==0){
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<query(arr,1,0,n-1,l,r)<<endl;
        }else{
            int pos,val;
            cin>>pos>>val;
            pos--;
            update(arr,1,0,n-1,pos,val);
        }
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    solve();

    return 0;
}