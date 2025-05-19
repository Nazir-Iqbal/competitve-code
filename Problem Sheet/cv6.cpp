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

void solve(){
    int n;cin>>n;
    vector<vector<int>> xy(100,vector<int>(100,0)),yz(100,vector<int>(100,0)),xz(100,vector<int>(100,0));
    vector<pair<int,pair<int,int>>> vpp;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        vpp.push_back({x,{y,z}});
        // cout<<x<<" "<<y<<" "<<z<<endl;
        string plane;cin>>plane;
        if(plane == "xy"){
            cout<<x<<" "<<y<<endl;
            for(int i=x;i<=x+1;i++){
                for(int j=y;j<=y+1;j++) xy[i][j]++;
            }
        }else if(plane == "yz"){
            for(int i=y;i<=y+1;i++){
                for(int j=z;j<=z+1;j++) yz[i][j]++;
            }
        }else{
            for(int i=x;i<=x+1;i++){
                for(int j=z;j<=z+1;j++) xz[i][j]++;
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++) cout<<xy[i][j]<<" ";
        cout<<endl;
    }

    int vx=0,vy=0,vz=0;
    for(int i=0;i<100;i++){
        bool flag = false;
        for(int j=0;j<100;j++){
            if(xy[i][j]==2 || xy[i][j]==4) flag = true;
            if(xy[i][j]==1 ){
                int first = -1,last = -1;
                for(int j=0;j<100;j++){
                    bool flg = false;
                    for(int i=0;i<100;i++){
                        if(xz[i][j] == 2 || xz[i][j] == 4) flg = true;
                    }
                    if(flg){
                        if(first == -1) first = j;
                        last = j;
                    }
                }
                last--;
                int req = first;
                for(int i=0;i<n;i++){
                    if(vpp[i].first == i && vpp[i].second.first==j){
                        if(vpp[i].second.second==first) req = last;
                        break;
                    }
                }
                cout<<i<<" "<<j<<" "<<req<<" xy";
                return;
            }
        }
        vx+=flag;
    }
    for(int i=0;i<100;i++){
        bool flag = false;
        for(int j=0;j<100;j++){
            if(yz[i][j]==2 || yz[i][j]==4) flag = true;
            if(yz[i][j]==1){
                int first = -1,last = -1;
                for(int j=0;j<100;j++){
                    bool flg = false;
                    for(int i=0;i<100;i++){
                        if(xz[i][j] == 2 || xz[i][j] == 4) flg = true;
                    }
                    if(flg){
                        if(first == -1) first = j;
                        last = j;
                    }
                }
                last--;
                int req = first;
                for(int i=0;i<n;i++){
                    if(vpp[i].first == i && vpp[i].second.first==j){
                        if(vpp[i].second.second==first) req = last;
                        break;
                    }
                }
                cout<<i<<" "<<j<<" "<<req<<" xy";
                return;
            }
        }
        vy+=flag;
    }
    for(int j=0;j<100;j++){
        bool flag = false;
        for(int i=0;i<100;i++){
            if(xz[i][j]==2 || xz[i][j]==4) flag = true;
            if(xz[i][j]==1){
                int first = -1,last = -1;
                for(int i=0;i<100;i++){
                    bool flg = false;
                    for(int j=0;j<100;j++){
                        if(xz[i][j] == 2 || xz[i][j] == 4) flg = true;
                    }
                    if(flg){
                        if(first == -1) first = j;
                        last = j;
                    }
                }
                last--;
                int req = first;
                for(int i=0;i<n;i++){
                    if(vpp[i].first == i && vpp[i].second.first==j){
                        if(vpp[i].second.second==first) req = last;
                        break;
                    }
                }
                cout<<i<<" "<<j<<" "<<req<<" xy";
                return;
            }
        }
        vz+=flag;
    }
    vx--,vy--,vz--;
    // cout<<vx<<" "<<vy<<" "<<vz<<endl;
    cout<<vx*vy*vz<<endl;
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