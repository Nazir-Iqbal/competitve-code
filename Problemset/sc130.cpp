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

// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int ans = 0,cnt = 1;
//     for(int i=1;i<n;i++){
//         if(s[i-1]==s[i]) cnt++;
//         else ans+=cnt-1,cnt=1;
//     }
//     ans+=cnt-1;
//     cout<<ans<<endl;
// }

// Make Equal
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(n==1){
//         cout<<"YES"<<endl;
//     }else if(n==2){
//         if(arr[0] == arr[1]) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }else{    
//         int mini = INT_MAX;
//         for(int i=1;i<n-1;i++) mini = min(mini,arr[i]);
//         if(arr[0]!=arr[n-1] || mini<arr[0]) cout<<"NO"<<endl;
//         else cout<<"YES"<<endl;   
//     }
// }

// Good Binary String
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int> seg;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]) cnt++;
        else seg.push_back(cnt),cnt = 1;
    }
    seg.push_back(cnt);
    // for(int ele : seg) cout<<ele<<" ";
    // cout<<endl;
    vector<int> ans;
    int ind = 0,pos=-1;
    bool flag = true;
    cnt = 0;
    for(int i=0;i<seg.size();i++) if(seg[i]&1) cnt++;
    if(cnt&1){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<seg.size()-1;i++){
        ind+=seg[i];
        if(seg[i]&1){
            if(pos==-1) seg[i]--,seg[i+1]++,ans.push_back(ind),ind--,pos=i;
            else{
                if(pos!=(i&1)){
                    if(flag) seg[i]--,seg[i+1]++,ans.push_back(ind),ind--,pos=i;
                    else seg[i]++,seg[i+1]--,ans.push_back(ind+1),ind++,pos=i;
                }else{
                    if(flag) seg[i]++,seg[i+1]--,ans.push_back(ind+1),ind++,pos=i,flag=false;
                    else seg[i]--,seg[i+1]++,ans.push_back(ind),ind--,pos=i,flag = true;
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int ele : ans) cout<<ele<<" ";
    cout<<endl;

}

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