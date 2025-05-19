#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
// #define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     if(n == 1){
//         cout<<"Bob"<<endl;
//         return;
//     }else if(n==2){
//         if(s[0] == s[1]) cout<<"Alice"<<endl;
//         else cout<<"Bob"<<endl;
//     }else{
//         int o=0,z=0;
//         for(int i=0;i<n;i++){
//             if(s[i] == '1') o++;
//             else z++;
//         }
//         int diff = abs(o-z);
//         if(n&1){
//             if(diff==1) cout<<"Alice"<<endl;
//             else cout<<"Bob"<<endl;
//         }else{
//             if(diff==0) cout<<"Bob"<<endl;
//             else cout<<"Alice"<<endl;
//         }
//     }
// }

// ConstructXor
void solve(){
    int n,s;
    cin>>n>>s;
    if(s&1 || n==1){
        cout<<-1<<endl;
        return;
    }
    int num1 = s/2,num2 = s/2;
    int len = n;
    vector<int> ans;
    while(len>2 && num1>1){
        len--;
        ans.push_back(1);
        num1--;
    }
    ans.push_back(num1),len--;
    while(len>1 && num2>1){
        len--;
        ans.push_back(1);
        num2--;
    }
    ans.push_back(num2);
    sort(ans.begin(),ans.end(),greater<int> ());
    if(ans[0]!=ans[1]){
        for(int i=0;i<31;i++){
            if(ans[0] == (1<<i)){
                ans[0]--;
                ans[1]++;
                break;
            }
        }
    }
    int xo = 0;
    for(int i=0;i<ans.size();i++) xo^=ans[i];
    // cout<<xo<<endl;
    int _max = *max_element(ans.begin(),ans.end());
    if(xo&1 || xo > _max){
        cout<<-1<<endl;
        return;
    }
    ans[0]-=xo;
    ans[ans.size()-1]+=(xo/2);
    ans[ans.size()-2]+=(xo/2);
    for(int ele : ans) cout<<ele<<" ";
    cout<<endl;
}

// Cake Cutting
// void solve(){
//     int n,m;
//     cin>>m>>n;
//     int p[n],q[n];
//     for(int i=0;i<n;i++) cin>>p[i];
//     for(int i=0;i<n;i++) cin>>q[i];
//     int hsn[m+2] = {0};
//     for(int i=0;i<n;i++){
//         if()
//         hsn[p[i]]++;
//         hsn[q[i]+1]--;
//     }
//     for(int i=1;i<n;i++) hsn[i] += hsn[i-1];
//     for(int i=1;i<=n;i++) cout<<hsn[i]<<" ";
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

    return 0;
}