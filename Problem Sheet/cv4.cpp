#include <bits/stdc++.h>
using namespace std;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int one = 0,total = 0,n;
vector<vector<char>> arr(30,vector<char>(30));
vector<vector<bool>> vis(30,vector<bool>(30,0));

int dirx[] = {0,1,0,-1};
int diry[] = {1,0,-1,0};

bool check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && !vis[x][y] && arr[x][y]!='.') return true;
    return false;
}

bool inter(int x,int y){
    for(int i=0;i<4;i++){
        int nx = x+dirx[i];
        int ny = y+diry[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(arr[nx][ny]=='.') return false;
        }
    }
    return true;
}

void dfs(int x,int y){
    vis[x][y] = 1;
    bool is = inter(x,y);
    if(is){
        if(arr[x][y] == '1') one++;
        total++;
    }

    for(int i=0;i<4;i++){
        int nx = x+dirx[i];
        int ny = y+diry[i];
        if(check(nx,ny)) dfs(nx,ny);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<n;j++) arr[i][j] = s[j];
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
    //     cout<<endl;
    // }

    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j=0;j<n;j++){
            if(arr[i][j] != '.'){
                flag = true;
                dfs(i,j);
                break;
            }
        }
        if(flag) break;
    }
    if(one&1){
        cout<<"Impossible";
    }else cout<<total;
}

int32_t main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    FIO;
    // int t;cin>>t;
    // while(t--){
    //   solve();
    // }
    solve();

    return 0;
}