#include <bits/stdc++.h>
using namespace std;
#define int long long

// void solve(){
        
// }

// int32_t main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     int t;cin>>t;
//     while(t--){
//       solve();
//     }

//     return 0;
// }

int32_t main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string g,s;
    cin>>g>>s;
    int leng = g.length(),lens = s.length();
    int ans = 0;
    int prev = 0,cur;
    for(int i=0;i<lens;i++){
        int _min = INT_MAX;
        int dis = INT_MAX;
        for(int j=0;j<leng;j++){
            int temp = abs(g[j]-s[i]);
            _min = min(_min,temp);
        }
        int cnt = 0;
        if(_min==0) continue;
        for(int j=0;j<leng;j++) if(abs(g[j]-s[i])==_min) cnt++;
        if(cnt==1){
            for(int j=0;j<leng;j++){
                if(abs(g[j]-s[i])==_min){
                    cur = j;
                    dis = abs(s[i]-g[j]);
                    break;
                }
            } 
        }else{
            for(int j=0;j<leng;j++){
                if(abs(g[j]-s[i])==_min){
                    if(dis>abs(g[j]-g[prev])){
                        cur = j;
                        dis = abs(g[j]-g[prev]);
                    }
                }
            }
        }
        cout<<s[i]<<" "<<g[prev]<<" "<<g[cur]<<" "<<dis<<endl;
        prev = cur;
        ans+=dis;
    }
    cout<<ans;
    return 0;
}