#include <bits/stdc++.h>
using namespace std;
// #define int long long

void solve(){
    string s;cin>>s;
    int len = s.length();
    string ans = "";
    int ind = 0;
    for(int i=len-1;i>=0;i--){
        ind++;
        if(s[i]!='0'){
            break;
        }
    }
    for(int i=0;i<len-ind;i++){
        ans.push_back(s[i]);
    }
    cout<<ans<<endl;
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