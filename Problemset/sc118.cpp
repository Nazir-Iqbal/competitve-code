#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int p,l;
//     cin>>p>>l;
//     float temp = (l*100)/p;
//     if(temp>=75.0) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Subset GCD
// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int cnt = 0,ind = 0;
//     for(int i=n;i>=1;i--){
//         for(int j=i;j<=n;j+=i) cnt++;
//         if(cnt>=k){
//             ind = i;
//             break;
//         }
//         cnt=0;
//     }
//     cnt = 1;
//     while(k--){
//         cout<<ind*cnt<<" ";
//         cnt++;
//     }
//     cout<<endl;
// }

// Join States
// void solve(){
//     int n,m;
//     cin>>n>>m;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int r=0;
//     int sum=0,ans=0;
//     while(r<n){
//         sum+=arr[r];
//         if(sum>=m){
//             ans++;
//             sum=0;
//         }
//         r++;
//     }
//     cout<<ans<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> bits;
//     convert(bits,n);
//     // for(int i=0;i<bits.size();i++) cout<<bits[i]<<" ";
//     // cout<<endl;
//     vector<int> a,b;
//     int sz = bits.size();
//     for(int i=0;i<sz;i++){
//         if(bits[i]==0) a.push_back(0),b.push_back(0);
//         else{
//             if(i==sz-1){
//                 b.push_back(1);
//                 a.push_back(0);
//             }else{
//                 a.push_back(1);
//                 b.push_back(0);
//             }
//         }
//     }
//     int pos=0,ans=0;
//     for(int i=0;i<sz;i++){
//         if(bits[i]==0){
//             a[i] = 1,b[i] =1;
//             int num1=decimal(a),num2=decimal(b);
//             // cout<<num1<<"&"<<num2<<endl;
//             if(num1>n || num2>n) break;
//             pos++;
//         }
//     }
//     ans = pow(2,pos);
//     cout<<ans<<endl;
//     // for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
//     // cout<<endl;
//     // for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
//     // cout<<endl;
//     // int num1 = decimal(a), num2 = decimal(b);
//     // cout<<min(num1,num2)<<" "<<max(num1,num2)<<endl;
// }

// int32_t main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     int t;cin>>t;
//     while(t--){
//         int n;cin>>n;
//         int ans = 1;
//         int cnt= 0;
//         for(int i=31;i>=0;i--){
//             if(n&(1<<i)) cnt++;
//             if(cnt>1){
//                 if(!(n&(1<<i))) ans*=2;
//             }
//         }
//         cout<<ans<<endl;
//     }

//     return 0;
// }

// Is it uniquely decodable
// void recursion(string &s,int ind,vector<string> &ans,string &temp){
//     cout<<temp<<"*"<<endl;
//     if(ind<0){
//         if(temp.size()>0){
//             reverse(temp.begin(),temp.end());
//             ans.push_back(temp);
//         }
//         return;
//     }
//     // not take
//     recursion(s,ind-1,ans,temp);
//     // take
//     if(s[ind]=='b'){
//         if(ind==0 && s[ind-1]!='a') return;
//         else{
//             temp+="ba";
//             recursion(s,ind-2,ans,temp);
//             temp.pop_back();
//             temp.pop_back();
//         }
        
//     }else{
//         temp.push_back('a');
//         recursion(s,ind-1,ans,temp);
//         temp.pop_back();
//         if(ind<=1 && s[ind-1]!='b' && s[ind-2]!='a') return;
//         else{
//             temp+="aba";
//             recursion(s,ind-3,ans,temp);
//             temp.pop_back();
//             temp.pop_back();
//             temp.pop_back();
//         }
//     }
// }
// void solve(){
//     string s;cin>>s;
//     vector<string> ans;
//     int n = s.length();
//     string temp="";
//     recursion(s,n-1,ans,temp);
//     for(auto ele : ans) cout<<ele<<" ";
//     cout<<endl;
// }

void solve(){
    string s;cin>>s;
    int n = s.length();
    // 0-->a && 1-->b;
    int ans =0,ca=0,cab=0,cba=0;
    int M=1e9+7;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            ca = (ca + ca + 1)%M;
            cba = (cba + cab)%M;
        }else{
            cab = (cab + ca + cba)%M;
        }
    }
    ans = (ca+cab)%M;
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
        solve();
    }
}