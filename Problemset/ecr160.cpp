#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Rating Increase
// void solve(){
//     string s;cin>>s;
//     if(s[0]==0){
//         cout<<-1<<endl;
//     }
//     int n = s.length();
//     int num1=0,num2=0;
//     bool flag = true;
//     for(int i=0;i<n/2;i++){
//         if(s[i+1]!='0'){
//             for(int j=0;j<=i;j++) num1=(num1*10)+(s[j]-'0');
//             for(int j=i+1;j<n;j++) num2=(num2*10)+(s[j]-'0');
//             // cout<<num1<<"&"<<num2<<endl;
//             if(num1<num2){
//                 flag = false;
//                 break;
//             }
//             num1=0,num2=0;
//         } 
//     }
//     // cout<<ind<<"*"<<s<<endl;
//     if(flag){
//         cout<<-1<<endl;
//     }else{
//         cout<<num1<<" "<<num2<<endl;
//     }
// }

// Swap and Delete
// void solve(){
//     string s;cin>>s;
//     int n = s.length();
//     vector<vector<int>> v(n+1,vector<int>(2,0));
//     v[0][0]=0,v[0][1]=0;
//     for(int i=1;i<=n;i++){
//         if(s[i-1]=='1') v[i][1]=v[i-1][1]+1,v[i][0]=v[i-1][0];
//         else v[i][0]=v[i-1][0]+1,v[i][1]=v[i-1][1];
//     }
//     int one = v[n][1] , zero = v[n][0];

//     // for(int i=0;i<=n;i++) cout<<v[i][0]<<" ";
//     // cout<<endl;
//     // for(int i=0;i<=n;i++) cout<<v[i][1]<<" ";
//     // cout<<endl;
    
//     int ans = 0;
//     for(int i=n;i>0;i--){
//         // cout<<zero<<"&"<<one<<endl;
//         if(one==v[i][0] && zero == v[i][1]) break;
//         if(one>v[i][0]) one--;
//         else zero--;

//         ans++;
//     }
//     cout<<ans<<endl;
// }

// Game with Multiset
void solve(){
    int m;cin>>m;
    vector<int> hsn(30,0);
    while(m--){
      int a,b;
      cin>>a>>b;
      if(a==1){
        hsn[b]++;
      }else{
        // every previous no. is factor of no. comming after it
        for(int i=29;i>=0;i--){
          int num = pow(2,i);
          if(num<=b){
            int cnt = b/num;
            cnt = min(cnt,hsn[i]);
            b-=(cnt*num);
            if(b==0) break; 
          }
        }
        if(b==0){
          cout<<"Yes"<<endl;
        }else cout<<"No"<<endl;
      }
    }
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}