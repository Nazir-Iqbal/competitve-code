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

// Submission Bait
// void solve(){
//     int n;cin>>n;
//     int hsn[n+1] = {0};
//     for(int i=0;i<n;i++){
//         int temp;cin>>temp;
//         hsn[temp]++;
//     }
//     for(int i=1;i<=n;i++){
//         if(hsn[i]&1){
//             cout<<"Yes"<<endl;
//             return;
//         }
//     }
//     cout<<"No"<<endl;
// }

// Array Craft
// void solve(){
//     int n,x,y;
//     cin>>n>>x>>y;
//     vector<int> ans(n+1,0);
//     bool flag = false;
//     for(int i=y-1;i>=1;i--){
//         if(flag) ans[i] = 1,flag=false;
//         else ans[i] = -1,flag=true;
//     }
//     for(int i=y;i<=x;i++) ans[i] = 1;
//     flag = false;
//     for(int i=x+1;i<=n;i++){
//         if(flag) ans[i] = 1,flag = false;
//         else ans[i] = -1,flag = true;
//     }
//     for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
//     cout<<endl;
// }

// Mad MAD Sum
// int tt = 1;

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     // if(tt==289){
//     //     for(int i=0;i<n;i++) cout<<arr[i]<<"*";
//     //     cout<<endl;
//     // }
//     vector<int> madmax(n,0),hsn(n+1,0);
//     int _max = 0,sum = 0,temp = 0;
//     for(int i=0;i<n;i++){
//         hsn[arr[i]]++;
//         if(hsn[arr[i]]>1) _max = max(_max,arr[i]);
//         madmax[i] = _max;
//         sum += arr[i];
//     }
//     for(int i=0;i<=n;i++) hsn[i] = 0;
//     _max = 0;
//     for(int i=0;i<n;i++){
//         sum += madmax[i];
//         hsn[madmax[i]]++;
//         if(hsn[madmax[i]]>1) _max = max(_max,madmax[i]);
//         madmax[i] = _max;
//     }
//     // for(int ele : madmax) cout<<ele<<" ";
//     // cout<<endl;
//     // cout<<sum<<"*"<<endl;
//     for(int i=0;i<n;i++){
//         temp += (n-i)*madmax[i];
//         // cout<<temp<<"$"<<endl;
//     }
//     sum += temp;
//     cout<<sum<<endl;
//     // tt++;
// }

// Grid Puzzle
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans = 0;
    
    cout<<ans<<endl;
}

// struct TreeNode
// {
//     // member vars
//     int data;
//     TreeNode* left;
//     TreeNode* right;
    
//     // constructor
//     TreeNode(int data){
//         this->data = data;
//         left = nullptr;
//         right = nullptr;
//     }
// };

// TreeNode * find(int l,int r,int pos,vector<int> &v){
//     if(l==r){
//         int data = v[l];
//         TreeNode * fun = new TreeNode(data);
//         fun->data = data;
//         return fun;
//     }
//     if(l>r){
//         return  nullptr;
//     }
//     int data = v[pos];
//     TreeNode * x = new TreeNode(data);
//     x->data = data;
//     int nx = (pos-l)/2;
//     int ny = (r-pos)/2;
//     TreeNode * left1 = find(l,pos-1,nx,v);
//     TreeNode * right1 = find(pos+1,r,ny,v);
//     x->left = left1;
//     x->right = right1;
//     return x;
// }

// void srch(int x,TreeNode*node,vector<int> &ans){
//     if(x==node->data){
//         return;
//     }

//     if(x>node->data){
//         srch(x,node->left,ans);
//         ans.push_back(node->data);
//     }else{
//         ans.push_back(node->data);
//         srch(x,node->right,ans);
//     }
// }

// void solve(){
//     vector<int> v;
//     string s;cin>>s;
//     int n = s.length();
//     bool flag = false;
//     for(int i=0;i<n;i++){
//         if(flag){
//             int num = (s[i]-'0')*10;
//             num += (s[i+1]-'0');
//             i++;
//             v.push_back(num);
//             flag = false;
//         }else v.push_back((s[i]-'0')),flag = true;
//     }

//     int sz = v.size();
//     sort(v.begin(),v.end(),greater<int>());

//     for(int ele : v) cout<<ele<<" ";
//     cout<<endl;

//     int root = v[sz/2];
//     TreeNode * x = find(0,sz-1,sz/2,v);
//     vector<int> ans;
//     srch(75,x,ans);
//     for(int ele : ans){
//         cout<<ele<<" ";
//     }
//     cout<<endl;

// }

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    int t;cin>>t;
    while(t--){
      solve();
    }
    // solve();

    return 0;
}