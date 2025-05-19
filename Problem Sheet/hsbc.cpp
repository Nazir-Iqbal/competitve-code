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

string conv(int num){
    string ans;
    while(num){
        int temp = num%10;
        num/=10;
        ans.push_back(char('0'+temp));
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void solve(){
    string s;
    getline(cin,s);
    string ans;
    map<string,int> mp;
    set<char> st = {'a','e','i','o','u'};
    string temp;
    for(int i=0;i<s.size();i++){
        if(st.find(s[i])!=st.end()) continue;
        if(s[i]==' '){
            if(temp.size()==0) continue;
            int num = mp[temp];
            ans += temp;
            if(num>0) ans += conv(num);
            mp[temp]++;
            temp.clear();
            ans.push_back(' ');
        }else temp.push_back(s[i]);
    }

    if(temp.size()>0){
        int num = mp[temp];
        ans += temp;
        if(num>0) ans += conv(num);
        temp.clear();
    }
    cout<<ans<<endl;
}

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();
    return 0;
}