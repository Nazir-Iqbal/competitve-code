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
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     bool flag = true;
//     for(int i=1;i<n;i++){
//         int diff = abs(arr[i-1]-arr[i]);
//         if(diff==5 || diff==7) continue;
//         flag = false;
//         break;
//     }
//     if(flag) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// void solve(){
//     int n,k;cin>>n>>k;
//     map<int,int> mp;
//     for(int i=0;i<k;i++){
//         int b,c;cin>>b>>c;
//         mp[b]+=c;
//     }
//     vector<int> v;
//     for(auto ele : mp) v.push_back(ele.second);
//     sort(v.begin(),v.end(),greater<int>());
//     int ans = 0;
//     int len = v.size();
//     for(int i=0;i<min(len,n);i++) ans += v[i];
//     cout<<ans<<endl;
// }

// void check(string &s,int x,int v,int &cnt){
//     int l = max(0,x-4);
//     int in = 0,fin = 0;
//     int n = s.size();
//     for(int i=l;i<=min(x,n-4);i++){
//         if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') in++;
//     }
//     s[x] = v;
//     for(int i=l;i<=min(x,n-4);i++){
//         if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') fin++;
//     }
//     // cout<<x<<" "<<" "<<v<<" "<<l<<" "<<min(x,n-4)<<" "<<in<<" "<<fin<<endl;
//     cnt += (fin-in);
// }

// void solve(){
//     string s;cin>>s;
//     int n = s.size();
//     int q;cin>>q;
//     int cnt = 0;
//     for(int i=0;i<n-3;i++){
//         if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='0' && s[i+3]=='0') cnt++;
//     }
//     while(q--){
//         int x;
//         char v;cin>>x>>v;
//         x--;
//         check(s,x,v,cnt);
//         if(cnt<=0) cout<<"No"<<endl;
//         else cout<<"Yes"<<endl;
//     }
// }

// I Love 1543
// bool check(int lvl,int n,int m){
//     if(lvl>n-1-lvl || lvl>m-1-lvl) return false;
//     return true;
// }

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<string> vv;
//     vector<string> vs;
//     for(int i=0;i<n;i++){
//         string temp;cin>>temp;
//         vs.push_back(temp);
//     }
//     int lvl = 0;
//     while(check(lvl,n,m)){
//         string temp;
//         for(int i=lvl;i<=m-lvl-1;i++) temp.push_back(vs[lvl][i]);
//         for(int i=lvl+1;i<=n-lvl-1;i++) temp.push_back(vs[i][m-lvl-1]);
//         for(int i=m-lvl-2;i>=lvl;i--) temp.push_back(vs[n-lvl-1][i]);
//         for(int i=n-lvl-2;i>lvl;i--) temp.push_back(vs[i][lvl]);
//         vv.push_back(temp);
//         // cout<<"*"<<endl;
//         lvl++;
//     }
//     // for(string ele : vv) cout<<ele<<" ";
//     // cout<<endl;
//     int ans=0;
//     for(int i=0;i<vv.size();i++){
//         int len = vv[i].size();
//         for(int j=0;j<len;j++){
//             if(vv[i][j] == '1' && vv[i][(j+1)%len]=='5' && vv[i][(j+2)%len]=='4' && vv[i][(j+3)%len]=='3') ans++;
//         }
//     }
//     cout<<ans<<endl;
// }

// Reverse the Rivers
// void solve(){
//     int n,m,q;
//     cin>>n>>m>>q;
//     vector<vector<int>> vv(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>vv[i][j];
//             if(i!=0) vv[i][j] |= vv[i-1][j];
//         }
//     }
//     vector<vector<int>> vp(m,vector<int>(n,0ll));
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++) vp[i][j] = vv[j][i];
//     }

//     while(q--){
//         int k;cin>>k;
//         int left = 0ll,right = n-1;
//         for(int i=0;i<k;i++){
//             int r,val;char o;
//             cin>>r>>o>>val;
//             if(o=='>'){
//                 int ind = upper_bound(vp[r-1].begin(),vp[r-1].end(),val)-vp[r-1].begin();
//                 left = max(left,ind);
//             }else{
//                 int ind = lower_bound(vp[r-1].begin(),vp[r-1].end(),val)-vp[r-1].begin();
//                 right = min(right,ind-1);
//             }
//         }
//         if(left>right) cout<<-1<<endl;
//         else cout<<left+1<<endl;
//     }
// }

// XORificator 3000                               
int xorTill(int n){
    if(n%4 == 1){
        return 1; 
    }else if(n%4 == 2){
        return n+1; 
    }else if(n%4 == 3){
        return 0; 
    }else{
        return n; 
    }
}

int xt(int L, int R){
    if(L==0 && R==0) return 0;
    if(L==0) L++;
    int xorTillL = xorTill(L-1);
    int xorTillR = xorTill(R);
    return xorTillL ^ xorTillR;
}                           
                            
void solve(){
    int l,r,i,k;
    stack<int> st;
    cin>>l>>r>>i>>k;
    int num = (1<<i);
    int ans = xt(l,r);
    if(num>r){
        if(k>=l && k<=r) ans ^= k;
    }else{
        int first = (l/num)*num + k;
        if(first<l){
            first = ((num+l-1)/num)*num + k;
        }
        if(r-first>=0){
            int no = (r-first)/num;
            if((no+1)&1){
                ans ^=k;
            }
            int left = first/num , right= (first)/num + no;
            ans ^= (xt(left,right)<<i);
        }
    }
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
    // solve();
    return 0;
}