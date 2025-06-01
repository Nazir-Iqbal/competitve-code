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

class TreeNode{
    public:
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val){
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

void dfs(TreeNode * root,string sum,long long &total){
    if(root->left == NULL && root->right == NULL){
        sum += to_string(root->data);
        total += stoll(sum);
        return;
    }

    if(root->left != NULL) dfs(root->left,sum+to_string(root->data),total);
    if(root->right != NULL) dfs(root->right,sum+to_string(root->data),total);
}

void insert(TreeNode * root,string &s,int ind,int val){
    if(ind == s.size()-1){
        // cout<<root->data<<" "<<ind<<" "<<s[ind]<<endl;
        if(s[ind] == 'L') root->left = new TreeNode(val);
        else root->right = new TreeNode(val);
        return;
    }

    if(s[ind] == 'L') insert(root->left,s,ind+1,val);
    else insert(root->right,s,ind+1,val);
}

long long calculateSum(int n,int root,string pos[],int val[]){

    vector<pair<string,int>> vp;
    for(int i=0;i<n-1;i++) vp.push_back({pos[i],val[i]});
    sort(vp.begin(),vp.end());
    TreeNode * base = new TreeNode(root);
    for(int i=0;i<n-1;i++){
        // cout<<vp[i].first<<" "<<vp[i].second<<endl;
        insert(base,vp[i].first,0,vp[i].second);
    }
    
    long long sum = 0;
    dfs(base,"",sum);
    return sum;
}

void solve(){
    int n;cin>>n;
    int root;cin>>root;
    string str[n-1];
    int val[n-1];
    for(int i=0;i<n-1;i++){
        cin>>str[i];
        cin>>val[i];
    }
    cout<<calculateSum(n,root,str,val);
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}