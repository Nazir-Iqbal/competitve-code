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
//     vector<bool> taken(n,0);
//     if(n&1){
//         cout<<"Alice"<<endl;
//         return;
//     }
//     for(int i=0;i<n;i++){
//         int num1 = i;
//         if(taken[num1]) continue;
//         else{
//             bool flag = true;
//             for(int j=0;j<n;j++){
//                 if((num1+j)%4==3 && taken[j]==0){
//                     taken[j] = i;
//                     flag = false;
//                     break;
//                 }
//             }
//             if(flag){
//                 cout<<"Alice"<<endl;
//                 return;
//             }
//         }
//     }
//     cout<<"Bob"<<endl;
// }

// void solve(){
//     int n,j,k;
//     cin>>n>>j>>k;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     if(k>1) cout<<"Yes"<<endl;
//     else{
//         j--;
//         int _max = *max_element(arr,arr+n);
//         if(_max == arr[j]) cout<<"Yes"<<endl;
//         else cout<<"No"<<endl;
//     }
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n+1];
//     for(int i=1;i<=n;i++) cin>>arr[i];

//     vector<int> prefix_min(n+1,INT_MAX),suffix_max(n+2,INT_MIN);
    
//     for(int i=1;i<=n;i++) prefix_min[i] = min(prefix_min[i-1],arr[i]);
//     for(int i=n;i>=1;i--) suffix_max[i] = max(suffix_max[i+1],arr[i]);

//     prefix_min[0] = INT_MIN;
//     suffix_max[n+1] = INT_MAX;

//     string ans;
//     for(int i=1;i<=n;i++){
//         if(arr[i]==prefix_min[i] || arr[i] ==suffix_max[i]) ans.push_back('1');
//         else ans.push_back('0');
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     string s;cin>>s;
//     int cnt = 0;
//     for(int i=0;i<n;i++) if(s[i] == '1') cnt++;

//     if(cnt <= k) cout<<"Alice"<<endl;
//     else{
//         if(n<2*k) cout<<"Alice"<<endl;
//         else cout<<"Bob"<<endl;
//     }
// }

// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     sort(arr,arr+n);
//     int mex = 0;
//     for(int ele : arr) if(ele == mex) mex++;
//     vector<int> hsn(mex);
//     for(int i=0;i<n;i++){
//         if(arr[i]<mex) hsn[arr[i]]++;
//     }
//     map<int,int> mp;
//     for(int i=0;i<mex;i++) mp[hsn[i]]++;

//     // cout<<mex<<endl;
//     vector<int> ans(n+1,1);
//     int cnt = 1,ind = n;
//     while(cnt<=mex){
//         ans[ind] = cnt;
//         cnt++,
//         ind--;
//     }
//     for(int i=0;i<=ind;i++){
//         if(i==0) ans[i] = 1;
//         else{
//             ans[i] = ans[i-1] + mp[i];
//         }
//     }
//     for(int ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

// Minimize Fixed Points
// const int N = 1e5+1;
// vector<int> gd(N,1);

// void pre(){
//     for(int i=2;i<=N;i++){
//         for(int j=2*i;j<=N;j+=i){
//             gd[j] = i;
//         }
//     }
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> ans(n+1);
//     vector<bool> vis(n+1,0);
//     vector<int> val[n+1];
//     map<int,int> pos;
//     for(int i=2;i<=n;i++){
//         pos[i] = i;
//         ans[i] = i;
//     }
//     ans[1] = 1;

//     for(int i=2;i<=n;i++){
//         int pos = gd[i];
//         if(pos != 1){
//             swap(ans[i],ans[pos]);
//         }
//     }

//     for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
//     cout<<endl;
// }

// Modular Sorting
const int N = 5e5+1;
vector<int> factor[N];

void pre(){
    for(int i=2;i<N;i++){
        for(int j=2*i;j<N;j+=i) factor[j].push_back(i);
    }
}

void check(int pos,int x,int m,int n,vector<vector<int>> &v,vector<int> &cnt){
    for(int i=0;i<factor[m].size();i++){
        int num = factor[m][i];
        int imp1 = 0,imp2 = 0;
        // if(pos>0 && v[i][pos-1] < v[i][pos] && pos<n-1 && v[i][pos+1] < v[i][pos]) imp1++;
        // if(pos>0 && v[i][pos-1] > v[i][pos] && pos<n-1 && v[i][pos+1] > v[i][pos]) imp1++;
        // if(pos == n-1 && v[i][pos-1] > v[i][pos]) imp1++;
        // if(pos == 0 && v[i][pos+1] < v[i][pos]) imp1++;

        if(pos!=0 && v[i][pos-1] > v[i][pos]) imp1++;
        if(pos!=n-1 && v[i][pos+1] < v[i][pos]) imp1++;

        v[i][pos] = x%num;

        // if(pos>0 && v[i][pos-1] < v[i][pos] && pos<n-1 && v[i][pos+1] < v[i][pos]) imp2++;
        // if(pos>0 && v[i][pos-1] > v[i][pos] && pos<n-1 && v[i][pos+1] > v[i][pos]) imp2++;
        // if(pos == n-1 && v[i][pos-1] > v[i][pos]) imp2++;
        // if(pos == 0 && v[i][pos+1] < v[i][pos]) imp2++;

        if(pos!=0 && v[i][pos-1] > v[i][pos]) imp2++;
        if(pos!=n-1 && v[i][pos+1] < v[i][pos]) imp2++;

        cnt[i] += imp2-imp1;
    }
}

void solve(){
    int n,m,q;
    cin>>n>>m>>q;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int> cnt(factor[m].size());
    vector<vector<int>> v(factor[m].size());
    for(int j=0;j<factor[m].size();j++){
        int num = factor[m][j];
        vector<int> temp(n);
        for(int k=0;k<n;k++) temp[k] = (arr[k])%num;

        int seg = 1;
        for(int k=0;k<n-1;k++){
            if(temp[k]>temp[k+1]) seg++;
        }

        v[j] = temp;
        cnt[j]  = seg;
    }

    // for(int i=0;i<factor[m].size();i++){
    //     cout<<factor[m][i]<<" "<<cnt[i]<<endl;
    //     for(int j=0;j<n;j++) cout<<v[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<"*"<<endl;
    for(int i=0;i<q;i++){
        int type;cin>>type;
        if(type==1){
            int pos,x;
            cin>>pos>>x;
            pos--;
            check(pos,x,m,n,v,cnt);

            // for(int i=0;i<factor[m].size();i++){
            //     cout<<factor[m][i]<<" "<<cnt[i]<<endl;
            //     for(int j=0;j<n;j++) cout<<v[i][j]<<" ";
            //     cout<<endl;
            // }

        }else{
            int k;cin>>k;
            int gcd = __gcd(k,m);
            if(gcd == 1) cout<<"Yes"<<endl;
            else{
                // cout<<gcd<<endl;
                int val_class = m/gcd;
                int ind = 0;
                for(int j=0;j<factor[m].size();j++){
                    if(factor[m][j] == k){
                        ind = j;
                        break;
                    }
                }
                int seg = cnt[ind];
                if(val_class >= seg) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    pre();
    int t;cin>>t;
    while(t--){
      solve();
    }

    return 0;
}