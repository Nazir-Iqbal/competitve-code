#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int long long

// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// void solve(){
//     int n;cin>>n;
//     string a,b,c;
//     cin>>a>>b>>c;
//     bool flag = false;
//     for(int i=0;i<n;i++){
//         if(a[i]!=c[i] && b[i]!=c[i]){
//             flag = true;
//             break;
//         }
//     }
//     if(flag) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// void solve(){
//     int n;cin>>n;
//     vector<int> hsn(n+1,0);
//     for(int i=0;i<n;i++){
//         int temp;cin>>temp;
//         hsn[temp]++;
//     }
//     // for(int i=0;i<=n;i++){
//     //     cout<<i<<" "<<hsn[i]<<endl;
//     // }
//     int left = n;
//     int ans = 0;
//     for(int i=n;i>=0;i--){
//         left-=hsn[i];
//         if(hsn[i]<2) continue;
//         if(hsn[i]>=3) ans+=(hsn[i]*(hsn[i]-1)*(hsn[i]-2))/6;
//         // cout<<ans<<"*"<<endl;
//         ans+=((hsn[i]*(hsn[i]-1))/2)*left;
//         if(left==0) break;
//     }
//     cout<<ans<<endl;
// }

// Closest Cities
// void solve(){
//     int n;cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     map<int,int> mp;
//     mp[0] = 1;
//     mp[n-1] = n-2;
//     for(int i=1;i<n-1;i++){
//         if(abs(arr[i]-arr[i-1])>abs(arr[i]-arr[i+1])) mp[i] = i+1;
//         else mp[i] = i-1;
//     }
//     // for(auto ele : mp){
//     //     cout<<ele.first+1<<" "<<ele.second+1<<endl;
//     // }
//     vector<int> prefix(n,0),suffix(n,0);
//     prefix[0] = 0,suffix[n-1]==0;
//     for(int i=1;i<n;i++){
//         if(mp[i-1]==i) prefix[i] = prefix[i-1]+1;
//         else prefix[i] = prefix[i-1]+abs(arr[i]-arr[i-1]);
//     }
//     for(int i=n-2;i>=0;i--){
//         if(mp[i+1]==i) suffix[i] = suffix[i+1]+1;
//         else suffix[i] += suffix[i+1]+abs(arr[i]-arr[i+1]);
//     }
//     // for(int i=0;i<n;i++) cout<<suffix[i]<<" ";
//     // cout<<endl;
//     int m;cin>>m;
//     while(m--){
//         int x,y;
//         cin>>x>>y;
//         x--,y--;
//         // cout<<x<<"$"<<y<<endl;
//         if(x>=y) cout<<suffix[y]-suffix[x]<<endl;
//         else cout<<prefix[y]-prefix[x]<<endl;
//     }
// }

// my trial method has many flaws but came up with come intuition i think 
// that counts for something
// void solve(){
//     vector<int> calc(62,0);
//     // fact[0] = 1;
//     // for(int i=1;i<21;i++) fact[i] = fact[i-1]*i;
//     calc[0] = 1;
//     for(int i=1;i<62;i++) calc[i] = calc[i-1]*2;
//     for(int i=1;i<62;i++) calc[i]--;
//     int x;cin>>x;
//     x--;
//     vector<int> ans;
//     vector<vector<int>> sorter;
//     // cout<<"h"<<endl;
//     while(x>=0){
//         int ind=0; 
//         for(int i=1;i<62;i++){
//             if(calc[i]>x){
//                 ind = i-1;
//                 break;
//             }
//         }
//         x-=calc[ind];
//         vector<int> temp;
//         for(int i=1;i<=ind;i++) temp.push_back(i);
//         cout<<ind<<" "<<calc[ind]<<" "<<temp.size()<<endl;
//         if(temp.size()>0) sorter.push_back(temp);
//     }
//     int prev=0,_max=0;
//     for(int i=sorter.size()-1;i>=0;i--){
//         for(int j = 0;j<sorter[i].size();j++){
//             sorter[i][j]+=prev;
//             _max = max(sorter[i][j],_max);
//         }
//         prev = _max;
//     }
//     for(auto v : sorter){
//         for(auto ele : v){
//             ans.push_back(ele);
//             // cout<<ele<<" ";
//         }
//         // cout<<endl;
//     }
//     cout<<ans.size()<<endl;
//     for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
//     cout<<endl;
//     // for(int i=0;i<62;i++) cout<<i<<"*"<<calc[i]<<endl;
// }

// Increasing Subsequences
// solving using the recursion
vector<int> f(int x){
    // base case
    if(x==2){
        return {0};
    }
    vector<int> res;
    if(x&1){
        res = f(x-1);
        res.push_back(*min_element(res.begin(),res.end())-1);
    }else{
        res = f(x/2);
        res.push_back(*max_element(res.begin(),res.end())+1);
    }
    return res;
}

// can also be done using the bit manipulation 
// L->current no. of inceasing subsequences;
// case1: 2L if maximum no. is added at the end of the subsquence
// case2: L+1 if minimum element is added at the end of the subsequence
// thus is forming binary operations can be done using bit manipulation or recurison

void solve(){
    int x;cin>>x;
    vector<int> ans = f(x);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;
    while(t--){
      solve();
    }
    return 0;
}