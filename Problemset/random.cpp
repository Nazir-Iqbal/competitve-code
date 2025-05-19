#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// using namespace __gnu_pbds;

#define int long long
#define nline "\n" 

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++) cin>>a[i];
//     map<pair<int,pair<int,int>>,int> m;
//     for(int i=0;i<n-2;i++){
//         int f = a[i],s=a[i+1],t=a[i+2];
//         m[{f,{s,t}}]++;
//         m[{f,{s,0}}]++;
//         m[{f,{0,t}}]++;
//         m[{0,{s,t}}]++;
//     }
//     int ans = 0;
//     for(int i=0;i<n-2;i++){
//         int f = a[i],s=a[i+1],t=a[i+2];
//         int num1 = m[{f,{s,0}}] - m[{f,{s,t}}];
//         int num2 = m[{f,{0,t}}] - m[{f,{s,t}}];
//         int num3 = m[{0,{s,t}}] - m[{f,{s,t}}];
//         ans += num1;
//         ans += num2;
//         ans += num3;
//         // cout<<num3<<" "<<m[{f,{s,t}}]<<endl;
//     }
//     cout<<ans/2<<endl;
// }

// Ingenuity-2
void solve(){
    map<char,int> m;
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++) m[s[i]]++;
    int netx = (m['E']-m['W']);
    int nety = (m['N']-m['S']);
    if(abs(netx)&1 || abs(nety)&1){
        cout<<"NO"<<endl;
        return;
    }
    netx/=2,nety/=2;
    // cout<<netx<<" "<<nety<<endl;
    string ans;
    if(netx!=0 || nety!=0){
        for(int i=0;i<n;i++){
            bool flag = false;
            if(nety>0) if(s[i] == 'N') ans.push_back('R'),nety--,flag = true;
            if(nety<0)  if(s[i] == 'S') ans.push_back('R'),nety++,flag = true;
            if(netx>0) if(s[i] == 'E') ans.push_back('R'),netx--,flag = true;
            if(netx<0)  if(s[i] == 'W') ans.push_back('R'),netx++,flag = true;
            if(!flag) ans.push_back('H');
        }
        cout<<ans<<endl;
    }else{
        int net1=0,net2=0;
        if(m['N']>0) net1 = 1,net2 = 1;
        if(m['E']>0) net1 = -1,net2 = -1;

        if((net1 == 0 && net2==0) || ( abs(net1) + abs(net2) == n)){
            cout<<"NO"<<endl;
            return;
        }
        for(int i=0;i<n;i++){
            bool flag = true;
            if(net1>0) if(s[i] == 'N') ans.push_back('R'),net1--,flag = false;
            if(net1<0) if(s[i] == 'E') ans.push_back('R'),net1++,flag = false;
            if(net2>0) if(s[i] == 'S') ans.push_back('R'),net2--,flag = false;
            if(net2<0) if(s[i] == 'W') ans.push_back('R'),net2++,flag = false;
            if(flag) ans.push_back('H');
        }
        cout<<ans<<endl;
    }
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