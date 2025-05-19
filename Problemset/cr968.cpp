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

// Turtle and Good Strings
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     if(s[0] == s[n-1]) cout<<"No"<<endl;
//     else cout<<"Yes"<<endl;
// }

// Turtle and Piggy Are Playing a Game 2
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,int> mp;
//     for(int i=0;i<n;i++) mp[arr[i]]++;
//     vector<pair<int,int>> vp;
//     for(auto ele : mp) vp.push_back({ele.first,ele.second});
//     int l = 0,r = mp.size()-1;
//     bool flag = true;
//     while(l<r){
//         if(flag){
//             flag = false;
//             int cnt = vp[l].second;
//             cnt--;
//             vp[l].second = cnt;
//             if(cnt == 0) l++;
//         }else{
//             flag = true;
//             int cnt = vp[r].second;
//             cnt--;
//             vp[r].second = cnt;
//             if(cnt == 0) r--;
//         }
//     }
//     cout<<vp[l].first<<endl;
// }

// Turtle and Good Pairs
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     vector<int> hsn(26,0);
//     for(int i=0;i<n;i++) hsn[s[i]-'a']++;
//     priority_queue<pair<int,int>> pq;
//     for(int i=0;i<26;i++) if(hsn[i]!=0) pq.push({hsn[i],i});
//     string ans;
//     // cout<<"*"<<endl;
//     while(!pq.empty()){
//         auto ele = pq.top();
//         pq.pop();
//         int cnt = ele.first;
//         int chr = char('a'+ele.second);
//         ans.push_back(chr);
//         if(!pq.empty()){
//             auto ele2 = pq.top();
//             pq.pop();
//             ans.push_back(char('a'+ele2.second));
//             if((ele2.first-1)!=0) pq.push({(ele2.first-1),ele2.second});
//         }
//         if((cnt-1) != 0) pq.push({(cnt-1),ele.second});
//     }
//     cout<<ans<<endl;
// }

// Turtle and a MEX Problem (Easy Version)
void solve(){
    int n,m;
    cin>>n>>m;
    int mex = 0;
    for(int i=0;i<n;i++){
        set<int> s;
        int sz;cin>>sz;
        for(int j=0;j<sz;j++){
            int temp;cin>>temp;
            s.insert(temp);
        }
        int cnt = 0,miss = 0;
        for(int ele : s){
            if(ele!=cnt){
                if(miss>0){
                    mex = max(cnt,mex);
                    miss++;
                    break;
                }
                mex = max(cnt,mex);
                miss++;
                cnt++;
                if(cnt!=ele){
                    mex = max(cnt,mex);
                    miss++;
                    break;
                }
            }
            cnt++;
        }
        if(miss==0) mex = max(mex,cnt+1);
        if(miss==1) mex = max(mex,cnt);
    }
    int lm = min(mex,m);
    int left = max(0ll,m-mex);
    int ans = (lm+1)*mex;
    ans += (left*(mex+1+mex+left))/2;
    cout<<ans<<endl;
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