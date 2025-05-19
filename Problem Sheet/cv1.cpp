#include <bits/stdc++.h>
using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve(){
    int n;cin>>n;
    map<string,int> mp = {{"down",1},{"right",2},{"left",3},{"up",4}};
    vector<int> v;
    for(int i=0;i<n;i++){
        string temp;cin>>temp;
        v.push_back(mp[temp]);
    }
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    int ans = 0;
    int left = -1,right = -1,ind = 1;
    left = v[0];
    for(int i=1;i<n;i++){
        if(v[i] == left) continue;
        right = v[i];
        ind = i+1;
        break;
    }
    if(right == -1 || ind == n){
        cout<<0<<endl;
        return;
    }
    for(int i=ind;i<n;i++){
        if(v[i] == left || v[i] == right) continue;
        int oc1 = n,oc2 = n;
        for(int j=i+1;j<n;j++){
            if(v[j] == left){
                oc1 = j;
                break;
            }
        }
        for(int j=i+1;j<n;j++){
            if(v[j] == right){
                oc2 = j;
                break;
            }
        }
        if(oc1>oc2) left = v[i];
        else right =  v[i];
        ans++;
    }
    cout<<ans;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    solve();

    return 0;
}