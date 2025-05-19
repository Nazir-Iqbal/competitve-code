#include <bits/stdc++.h>
using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

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

    tree[node] = max(tree[2*node],tree[2*node+1]);
}

int query(int node,int st,int end,int val){
    if(st==end){
        if(tree[node]<val) return -1;
        tree[node] -= val;
        return st;
    }

    int mid = (st+end)/2;
    int left = 2*node;
    int right = 2*node+1;
    int ind = -1;
    if(tree[left]>=val){
        ind = query(left,st,mid,val);
    }else if(tree[right]>=val){
        ind = query(right,mid+1,end,val);
    }
    tree[node] = max(tree[left],tree[right]);
    return ind;
}

void solve(){
    int n,q;
    cin>>n>>q;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    while(q--){
        int x;cin>>x;
        cout<<query(1,0,n-1,x)+1<<' ';
    }
    cout<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}