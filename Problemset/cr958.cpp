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
//     int n,k;
//     cin>>n>>k;
//     int ans = (n-1)/(k-1);
//     if((n-1)%(k-1)!=0) ans++;
//     cout<<ans<<endl;
// }

// Make Majority
// void solve(){
//     int n;cin>>n;
//     string s;cin>>s;
//     string temp;
//     for(int i=0;i<n;i++){
//         if(i==n-1) temp.push_back(s[i]);
//         else{
//             if(s[i] == '1') temp.push_back(s[i]);
//             else if(s[i] == '0' && s[i+1] == '1') temp.push_back('0');
//         }
//     }
//     // cout<<temp<<endl;
//     int c1 = 0,len = temp.size();
//     for(int i=0;i<len;i++) if(temp[i] == '1') c1++;
//     // cout<<c1<<" "<<len<<endl;
//     if(c1>len-c1) cout<<"Yes"<<endl;
//     else cout<<"No"<<endl;
// }

// Increasing Sequence with Fixed OR
void solve(){
    int n;cin>>n;
    vector<int> ans;

    int temp = 0;
    for(int i=60;i>=0;i--){
        if(((1ll<<i)&n)){
            int local = 0;
            for(int j=i-1;j>=0;j--) local += ((1ll<<j)&n);
            // cout<<local<<" "<<temp<<endl;
            local += temp;
            if(local > 0) ans.push_back(local);
            temp += (1ll<<i);
        }
    }
    ans.push_back(n);
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