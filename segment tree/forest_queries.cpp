#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    int arr[n][n];
    for(int i=0;i<n;i++){
        string temp;cin>>temp;
        for(int j=0;j<n;j++){
            if(temp[j]=='*') arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
    int prefix[n+1][n+1] = {0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j] = arr[i-1][j-1] + (prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]);
        }
    }

    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int ans = prefix[x2][y2] - (prefix[x1-1][y2] + prefix[x2][y1-1] - prefix[x1-1][y1-1]);
        cout<<ans<<endl;
    }
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    solve();

    return 0;
}