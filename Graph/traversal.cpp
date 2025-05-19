#include <bits/stdc++.h>
using namespace std;

// Number of Distinct Islands
bool ispossible(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis){
    if(i<grid.size() && i>=0 && j>=0 && j<grid[0].size()){
        if(grid[i][j]==1 && !vis[i][j]) return true;
    }
    return false;
}

void dfs(int i,int j,int bx,int by,vector<vector<int>> &grid,vector<vector<bool>> &vis,vector<pair<int,int>> &temp){
    vis[i][j] = 1;
    temp.push_back({bx-i,by-j});
    int dirx[4] = {0,1,0,-1};
    int diry[4] = {1,0,-1,0};
    for(int k=0;k<4;k++){
        int nx = i+dirx[k];
        int ny = j+diry[k];
        if(ispossible(nx,ny,grid,vis)){
            dfs(nx,ny,bx,by,grid,vis,temp);
        }
    }
}

int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // initialy all the islands are not visted
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    set<vector<pair<int,int>>> svp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !vis[i][j]){
                vector<pair<int,int>> temp;
                dfs(i,j,i,j,grid,vis,temp);
                svp.insert(temp);
            }
        }
    }
    return svp.size();
}

int main(){

    return 0;
}