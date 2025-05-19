#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// #define int long long

// priority_queue <int, vector<int>, greater<int>> pq;
// template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

// Floyd Warshall Algorithm
void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1) matrix[i][j] = 1e9;
        }
    }
    
    // dynamic programming solution
    for(int via = 0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][via]+matrix[via][j]);
            }
        }
    }
    
    // checking for the negative cycle;
    for(int i=0;i<n;i++){
        if(matrix[i][i]<0) cout<<"matrix has negative cycle"<<endl;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9) matrix[i][j] = -1;
        }
    }
    
}

void solve(){
        
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