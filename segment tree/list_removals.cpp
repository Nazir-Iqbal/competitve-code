#include <bits/stdc++.h>
using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> tree(1e6);
vector<int> arr;

void build(int node,int st,int end){
    if(st==end){
        tree[node] = 1;
        return;
    }

    int mid = (st+end)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,end);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int node,int st,int end,int val){
    // cout<<node<<" "<<tree[node]<<" "<<val<<endl;
    if(st==end){
        tree[node] = 0;
        return arr[st];
    }

    int mid = (st+end)/2;
    int ind = 0;
    if(tree[2*node]>=val) ind = query(2*node,st,mid,val);
    else ind = query(2*node+1,mid+1,end,val-tree[2*node]);

    tree[node] = tree[2*node] + tree[2*node+1];

    return ind;

}

void solve(){
    int n;cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    build(1,0,n-1);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        cout<<query(1,0,n-1,x)<<" ";
    }
    cout<<endl;
    // for(int i=0;i<=10;i++) cout<<tree[i]<<" ";
    // cout<<endl;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}